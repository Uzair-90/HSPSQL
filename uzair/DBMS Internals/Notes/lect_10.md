# Sorting and Aggregations

## Query Plan
The operators are arranged in a tree.
Data flows from the leaves of the tree up towards the root.
* We will discuss the granularity of the data movement in coming lectures.
The output of the root node is the result of the query.

## Disk Oriented System

Just like it cannot assume that a table fits entirely in memory, a disk-oriented DBMS 
cannot assume that query results fit in memory.
We will use the buffer pool to implement algorithms that need to spill to disk.
We are also going to prefer algorithms that maximize the amount of sequential I/O.

## Why do we need to sort?
Relational model/SQL is unsorted.
Queries may request that tuples are sorted in a specific way (ORDER BY).
But even if a query does not specify an order, we may still want to sort to do other 
things:
* Trivial to support duplicate elimination (DISTINCT)
* Bulk loading sorted tuples into a B+Tree index is faster
* Aggregations (GROUP BY)

## In memory sort

If data fits in memory, then we can use a standard sorting algorithm like quicksort.
If data does not fit in memory, then we need to use a technique that is aware of the 
cost of reading and writing disk pages…

## Today's Agenda

* Top-N Heap Sort
* External Merge Sort
* Aggregations

### TOP-N HEAP SORT
If a query contains an ORDER BY with a LIMIT, then the DBMS only needs to scan the data
once to find the top-N elements.
Ideal scenario for heapsort if the topN elements fit in memory.
* Scan data once, maintain an in-memory sorted priority queue.

In postgres database if you try to analyze TOP-N heap sort it will follow the following
behaviour: 

It consumes the input values in sequence. After it fills the heap up to the target 
number of tuples it starts examining each new value to see if it's larger than all 
current values, smaller than all current values, or fits within the heap.

If it's larger than all current values (assuming ASC sort) it gets discarded, since we 
have enough lower values already.

If it's smaller than all current values or than some current values, it's inserted at 
the appropriate point in the heap, everything gets shifted down by one, and it bumps 
the last entry off the heap.

### Eternal Merge Sort

Divide-and-conquer algorithm that splits data into separate runs, sorts them 
individually, and then combines them into longer sorted runs.
### Phase #1 – Sorting

* Sort chunks of data that fit in memory and then write back the sorted chunks to a 
file on disk.
### Phase #2 – Merging
* Combine sorted runs into larger chunks. 

### Stored RUN

A run is a list of key/value pairs.
Key: The attribute(s) to compare to compute the sort order.
Value: Two choices
* Tuple (early materialization).
* Record ID (late materialization).

### Early materialization:

Early materialization in DBMS is a query optimization approach where data is retrieved 
and processed from the database as soon as possible during query execution, reducing
I/O operations and enabling early error detection.

### Late Materialization

Late materialization in DBMS delays data retrieval and processing until it's necessary 
for the final query result, potentially increasing I/O operations but offering more
flexibility in optimizing queries.

### 2-Way External Merge Sort

We will start with a simple example of a 2-way external merge sort.
* “2” is the number of runs that we are going to merge into a new run for each pass.
Data is broken up into N pages.
The DBMS has a finite number of B buffer pool pages to hold input and output data.

Pass #0
* Read all B pages of the table into memory
* Sort pages into runs and write them back to disk
Pass #1,2,3,…
* Recursively merge pairs of runs into runs twice as long
* Uses three buffer pages (2 for input pages, 1 for output)

In each pass, we read and write every page in the file.
Number of passes = 1 + ⌈ log2 N ⌉
Total I/O cost = 2N ∙ (# of passes)

This algorithm only requires three buffer pool pages to perform the sorting (B=3).
* Two input pages, one output page.
But even if we have more buffer space available (B>3), it does not effectively utilize 
them if the worker must block on disk I/O…

## Double Buffering Optimization

Prefetch the next run in the background and store it in a second buffer while the 
system is processing the current run.
* Reduces the wait time for I/O requests at each step by continuously utilizing the 
disk.

### Pass #0
* Use B buffer pages
* Produce ⌈N / B⌉ sorted runs of size B
### Pass #1,2,3,…
* Merge B-1 runs (i.e., K-way merge)

Number of passes = 1 + ⌈ logB-1 ⌈N / B⌉ ⌉
Total I/O Cost = 2N ∙ (# of passes)

## Comparison Optimizations

### Approach #1: Code Specialization
* Instead of providing a comparison function as a pointer to sorting algorithm, create 
a hardcoded version of sort that is specific to a key type.
### Approach #2: Suffix Truncation
* First compare a binary prefix of long VARCHAR keys instead of slower string 
comparison. Fallback to slower version if prefixes are equal.

## Using B+ Tree for sorting

If the table that must be sorted already has a B+Tree index on the sort attribute(s), 
then we can use that to accelerate sorting.
Retrieve tuples in desired sort order by simply traversing the leaf pages of the tree.
Cases to consider:
* Clustered B+Tree
* Unclustered B+Tree

### Case #1: Clustered B+ Tree

Traverse to the left-most leaf page, and then retrieve tuples from all leaf pages.
This is always better than external sorting because there is no computational cost, 
and all disk access is sequential.

### Case #2: Unclustered B+ Tree

Chase each pointer to the page that contains the data.
This is almost always a bad idea.
In general, one I/O per data record.

## Aggregations

Collapse values for a single attribute from multiple tuples into a single scalar value.
The DBMS needs a way to quickly find tuples with the same distinguishing attributes 
for grouping.
Two implementation choices:
* Sorting
* Hashing

## Alternatives to sorting

What if we do not need the data to be ordered?
* Forming groups in GROUP BY (no ordering)
* Removing duplicates in DISTINCT (no ordering)
Hashing is a better alternative in this scenario.
* Only need to remove duplicates, no need for ordering.
* Can be computationally cheaper than sorting

## Hashing Aggregate

Populate an ephemeral hash table as the DBMS scans the table. For each record, check 
whether there is already an entry in the hash table:
* DISTINCT: Discard duplicate
* GROUP BY: Perform aggregate computation
If everything fits in memory, then this is easy.
If the DBMS must spill data to disk, then we need to be smarter…

## External Hashing Aggregate

### Phase #1 – Partition
* Divide tuples into buckets based on hash key.
* Write them out to disk when they get full.
### Phase #2 – ReHash
* Build in-memory hash table for each partition and compute the aggregation.

### Phase #1 Partitioning

Use a hash function h1 to split tuples into partitions on disk.
* A partition is one or more pages that contain the set of keys with the same hash value.
* Partitions are “spilled” to disk via output buffers.
Assume that we have B buffers.
We will use B-1 buffers for the partitions and 1 buffer for the input data.

### Phase #2 Rehashing

For each partition on disk:
* Read it into memory and build an in-memory hash table based on a second hash
function h2.
* Then go through each bucket of this hash table to bring together matching tuples.
This assumes that each partition fits in memory

## Hashing summarization

During the ReHash phase, store pairs of the form (GroupKey→RunningVal).
When we want to insert a new tuple into the hash table:
* If we find a matching GroupKey, just update the RunningVal appropriately.
* Else insert a new GroupKey→RunningVal.


## Conclusion

Choice of sorting vs. hashing is subtle and depends on optimizations done in each case.
We already discussed the optimizations for sorting:
* Chunk I/O into large blocks to amortize costs.
* Double-buffering to overlap CPU and I/O.














