# Join Algorithms 

## Why do we need join?
We normalize tables in a relational database to avoid unnecessary repetition of information.
We then use the join operator to reconstruct the original tuples without any information loss.

## JOIN ALGORITHMS

We will focus on performing binary joins (twotables) using inner equijoin algorithms.
* These algorithms can be tweaked to support other joins.
* Multi-way joins exist primarily in research literature.
In general, we want the smaller table to always be the left table ("outer table") in the query 
plan.
* The optimizer will (try to) figure this out when generating the physical plan.

## How joins works?

In a relational database, the JOIN operation is used to combine rows from two or more tables 
based on a related column between them. This operation allows you to retrieve data from 
multiple tables in a single query and create a result set that includes columns from all the 
joined tables. JOINs are fundamental to SQL (Structured Query Language) and are used to 
establish relationships between tables in a database.

## Inner Join

An INNER JOIN returns only the rows that have matching values in both tables. Rows with 
non-matching values in the specified columns are excluded from the result set.

Example:

```sql
SELECT orders.order_id, customers.customer_name
FROM orders
INNER JOIN customers ON orders.customer_id = customers.customer_id;

```
The operator output may be sorted or unsorted or could be in any order it depends on many things
which inlude:

Output contents can vary:
* Depends on processing model.
* Depends on storage model.
* Depends on data requirements in query.

## Query Optimization By Early or Late Materialization

The concepts of early and late materialization are related to how data is retrieved and processed when performing JOIN operations in a database, especially in the context of query optimization. These concepts are more relevant in the context of query execution and the performance of your database queries.

## Early Materialization:

Early materialization refers to the approach where the database engine retrieves all the data needed for a JOIN operation from the participating tables and forms a temporary result set containing all the required columns.
In early materialization, the JOIN operation is typically performed early in the query execution process. The database engine fetches all the relevant rows and columns from the tables and combines them before filtering or aggregating the data.
This approach can be memory-intensive because it creates a potentially large intermediate result set that includes all the columns from the joined tables.

## Late Materialization:

Late materialization, on the other hand, involves delaying the JOIN operation until after filtering, aggregation, or other operations have been performed on the individual tables.
In late materialization, the database engine optimizes the query execution plan to minimize the amount of data retrieved from the tables initially. It may choose to perform filtering or aggregation operations on each table before joining them, which can reduce the amount of data involved in the JOIN.
Late materialization is often more memory-efficient because it avoids creating large intermediate result sets with unnecessary columns.
The choice between early and late materialization depends on several factors, including the query optimizer's decisions, the database system's capabilities, and the specific query being executed. Query optimizers aim to find the most efficient execution plan for a given query based on factors like the size of the tables, available indexes, and the nature of the data.

In many cases, a query optimizer may opt for late materialization when it can improve query performance by reducing the amount of data involved in the JOIN operation. However, there are situations where early materialization may be more efficient, especially when using certain optimization techniques or when performing complex multi-table joins.

Ultimately, as a database developer or administrator, you may not need to explicitly control whether early or late materialization is used. Instead, you can focus on designing efficient queries, creating appropriate indexes, and maintaining the database schema to ensure that the query optimizer can make the best decisions for query execution.


Late Materialization is Ideal for column stores because the DBMS does not copy data that is not 
needed for the query.

## Cost Analysis Criteria

### Assume:
* M pages in table R, m tuples in R
* N pages in table S, n tuples in S
### Cost Metric: # of IOs to compute join

We will ignore output costs since that depends on the data and we cannot compute that yet.

Consider the following join for the above senario:

```sql
SELECT R.id, S.cdate FROM R JOIN S
ON R.id = S.id WHERE S.value > 100
```

## Join Algorithms

Nested Loop Join
* Simple / Stupid
* Block
* Index
Sort-Merge Join
Hash Join


## Nested Loop Join

This of it as a nested for loop like in the followin way:

```c++
for(auto r: R ){
	for(auto s: S){
		if(r == s){
			join.push(tuple);
		}
	}
}
```
Like in the above senario you can see atable R which is the outer table and table S which is
the inner table for each tuple of R we check the whole S table if the key matches add it to
the join.

This is the dumbest thing you can do for a join. Because its so naive with maximum I/O.

Why is this algorithm stupid?

* For every tuple in R, it scans S once

COST: M + (m.N)

M is the number of pages in table one. n is the number of tuples and N is the number of pages
in table two.

## Example database:
* Table R: M = 1000, m = 100,000
* TableS: N=500,n=40,000 4 KB pages → 6 MB
## Cost Analysis:
* M + (m ∙ N) = 1000 + (100000 ∙ 500) = 50,001,000 IOs
* At 0.1 ms/IO, Total time ≈ 1.3 hours
What if smaller table (S) is used as the outer table? * N + (n ∙ M) = 500 + (40000 ∙ 1000) = 40,000,500 IOs
* At 0.1 ms/IO, Total time ≈ 1.1 hours

## Blocked Nested Join Loops

![nested block image](https://github.com/Uzair-90/practice/blob/master/uzair/DBMS%20Internals/nested_block.png)

In a traditional Nested Loop Join, for each row in the outer table, the entire inner table is 
scanned sequentially to find matching rows. This can be very inefficient, especially when 
dealing with large tables. The Block Nested Loop Join addresses this inefficiency by reading 
and processing data in blocks (chunks) rather than row by row.

This will readuce the number of I/O to the disk which can cause alot of overhead.

The cost is now reduced to:

M+(M.N) because we are not making an I/O for each tuple or row now we are making an I/O for 
chunks only.

The smaller table should be the outer table.
We determine size based on the number of pages, not the number of tuples.

Example database:
* Table R: M = 1000, m = 100,000
* TableS: N=500,n=40,000
Cost Analysis:
* M + (M ∙ N) = 1000 + (1000 ∙ 500) = 501,000 IOs
* At 0.1 ms/IO, Total time ≈ 50 seconds

What if we have B buffers available?
* Use B-2 buffers for scanning the outer table.
* Use one buffer for the inner table, one buffer for storing output.

This algorithm uses B-2 buffers for scanning R.
## Cost:
M + ( [M / (B-2)] ∙ N)

What if the outer relation completely fits in memory (B > M+2)?
* Cost: M + N = 1000 + 500 = 1500 IOs
* At 0.1ms/IO, Total time ≈ 0.15 seconds

As we have discussed that Nested Loop Join algorithm is so bad so what is the solution for it?

## Solution
We can avoid sequential scans by using an index to find inner table matches.
* Use an existing index for the join.

![index_join](https://github.com/Uzair-90/practice/blob/master/uzair/DBMS%20Internals/index_join.png)

The cost will be some constant for searching C now the cost depends on C:

cost = M+(m.C)

## Nested loop join summary:

Key takeaways:
* Pick the smaller table as the outer table.
* Buffer as much of the outer table in memory as possible.
* Loop over the inner table (or use an index).

Algorithms:

* Simple / Stupid
* Block
* Index


## Sort-Merge Join

A Sort-Merge Join is a type of JOIN algorithm used in database query processing to combine rows from two tables during a JOIN operation. It is particularly useful when the tables being joined are not already sorted on the join key and cannot be efficiently indexed for the JOIN operation.

Here's how a Sort-Merge Join works:

Sorting: First, both the left (or outer) table and the right (or inner) table are independently sorted based on the join key. This sorting step can be computationally expensive, especially for large tables. However, it is a crucial step for the efficiency of the Sort-Merge Join.

Merging: Once both tables are sorted, the actual merge operation takes place. The merge operation is similar to merging two sorted lists. It involves comparing values in the join key columns of the sorted tables and combining matching rows.

The Sort-Merge Join process starts by comparing the first row of the left table with the first row of the right table. If they match, these rows are combined into a result row.

If the values do not match, the algorithm moves to the next row in either the left or right table (whichever value is smaller) and continues comparing and merging until all matches are found.

If a row in one table does not have a matching row in the other table, it is not included in the result set. This behavior depends on whether you're performing an INNER JOIN, LEFT JOIN, RIGHT JOIN, or FULL JOIN.

Result Set: The result of the Sort-Merge Join is a combined result set containing rows from both tables that satisfy the join condition.

Advantages of Sort-Merge Join:

Efficient for Non-Sorted Data: Unlike some other JOIN algorithms that require pre-sorted data or indexed columns, the Sort-Merge Join can efficiently handle tables that are not already sorted.

Predictable Performance: The Sort-Merge Join's performance is relatively predictable and doesn't depend on the distribution of data as much as some other JOIN algorithms.

Disadvantages of Sort-Merge Join:

High Initial Cost: The sorting step can be computationally expensive, especially for large tables. This cost can be significant, and it may make Sort-Merge Join less efficient for smaller datasets.

Space Requirements: Sorting both tables can require additional disk space to store the sorted versions of the tables.

May Not Be Optimal for Small Tables: Sort-Merge Join may not be the best choice for very small tables where other JOIN algorithms like Nested Loop Join could be more efficient.

The choice of which JOIN algorithm to use depends on factors such as table sizes, available memory, and the query optimizer's decisions based on these factors. The query optimizer's goal is to select the most efficient algorithm for a given query, considering the specific characteristics of the tables and the join conditions.


## Cost of Sort-Merge Join

Sort Cost (R): 2M ∙ (1 + ⌈ logB-1 ⌈M / B⌉ ⌉)
Sort Cost (S): 2N ∙ (1 + ⌈ logB-1 ⌈N / B⌉ ⌉)
Merge Cost: (M + N)
Total Cost: Sort + Merge

## Example database:

* Table R: M = 1000, m = 100,000
* TableS: N=500,n=40,000
With B=100 buffer pages, both R and S can be sorted in two passes:
* Sort Cost (R) = 2000 ∙ (1 + ⌈log99 1000 /100⌉) = 4000 IOs
* Sort Cost (S) = 1000 ∙ (1 + ⌈ log99 500 / 100⌉) = 2000 IOs
* Merge Cost = (1000 + 500) = 1500 IOs
* Total Cost = 4000 + 2000 + 1500 = 7500 IOs
* At 0.1 ms/IO, Total time ≈ 0.75 seconds

The worst case for the merging phase is when the join attribute of all the tuples in both relations contains the same value.
Cost: (M ∙ N) + (sort cost)

## Question

When is Sort-Merge Join useful?

One or both tables are already sorted on join key. Output must be sorted on join key.
The input relations may be sorted either by an explicit sort operator, or by scanning the
relation using an index on the join key.

## Hash Joins

Think of a Hash Join like organizing a big party where you have two guest lists, and you want to find who's coming to your party. First, you create separate buckets for each list, grouping guests by their names (like all the Johns in one bucket). Then, you take one list, say the smaller one, and put it in your memory. Now, you pick up the other list and start looking for matching guests by their names. You use the buckets you created earlier to quickly find the right group of people (like all the Johns) and see if they're on both lists. If you find a match, you add those guests to your final party list. You keep doing this for all the guests on the second list. In the end, you have a list of all the people who are coming to your party – those are your join results! The key here is that you use these buckets and memory to find matches faster, especially when you have a lot of guests (or rows) to check.


If tuple r ∈ R and a tuple s ∈ S satisfy the join condition, then they have the same value for 
the join attributes.
If that value is hashed to some partition i, the R tuple must be in ri and the S tuple in si.
Therefore, R tuples in ri need only to be compared with S tuples in si.


### Basic Hash Join Algorithm

Phase #1: Build

* Scan the outer relation and populate a hash table using the hash function h1 on the join attributes.

* We can use any hash table that we discussed before but in practice linear probing works the best.
Phase #2: Probe

* Scan the inner relation and use h1 on each tuple to jump to a location in the hash table and find a matching tuple.


![hash join](https://github.com/Uzair-90/practice/blob/master/uzair/DBMS%20Internals/hash_join.png)

### Hash Table Contents

Key: The attribute(s) that the query is joining the tables on.
* We always need the original key to verify that we have a correct match in case of hash 
collisions.
Value: Varies per implementation.
* Depends on what the operators above the join in the query plan expect as its input.
* Early vs. Late Materialization

## Cost Analysis

How big of a table can we hash using this approach?
* B-1 "spill partitions" in Phase #1
* Each should be no more than B blocks big
Answer: B ∙ (B-1)
* A table of N pages needs about sqrt(N) buffers
* Assumes hash distributes records evenly. 
Use a "fudge factor" f>1 for that: we need B∙sqrt(f∙N)

Bloom filters can be used as an optimization technique in Hash Join operations to reduce the amount of data that needs to be loaded into memory, making the join process more efficient, especially when dealing with large datasets. Here's how Bloom filters can be employed for Hash Join optimizations:

Building Bloom Filters:

Before performing the Hash Join, a Bloom filter is constructed for one or both of the tables involved in the join operation.
A Bloom filter is a space-efficient data structure used to test whether an element is a member of a set. It uses a set of hash functions and a bit array. Initially, all bits in the array are set to 0.
For each row in the table(s) for which you're constructing the Bloom filter(s), you apply the hash functions to the join key(s) of the row and set the corresponding bits in the Bloom filter(s) to 1.
Filtering Phase:

During the Hash Join operation, before loading an entire table into memory, you can use the Bloom filter(s) to perform a quick initial filter.
For each row in the other table (probe table), you apply the same hash functions to the join key(s) and check the corresponding bits in the Bloom filter(s). If all bits are set to 1, it indicates a possible match.
Rows that fail the Bloom filter test (i.e., any of the bits are 0) are skipped, reducing the number of rows that need to be loaded into memory for the actual join.
Hash Join:

After the initial filtering using Bloom filters, you proceed with the Hash Join as usual, but now with a reduced dataset in memory. This can significantly improve memory usage and join performance.
Bloom filters are useful in situations where the cost of loading data into memory is high, such as when dealing with large tables or distributed databases. They help eliminate many rows that are guaranteed not to match the join condition, reducing the memory and computational resources required for the actual join.

However, it's essential to keep in mind that Bloom filters may produce false positives (indicating a match when there isn't one). Therefore, they are typically used as a preliminary filtering step to reduce the dataset size before the actual Hash Join. Any potential matches identified by the Bloom filter must be further verified in the subsequent Hash Join phase to ensure correctness.


## Partioned Hash Join

A Partitioned Hash Join is an extension of the traditional Hash Join algorithm that is designed to improve the performance of join operations, especially in distributed database systems. In a Partitioned Hash Join, data is divided into partitions, and each partition is processed independently, reducing data movement and improving parallelism. Let's walk through the key steps of a Partitioned Hash Join and perform a simple cost analysis.

Steps of a Partitioned Hash Join:

### Partitioning Phase:
Both the left (or outer) and right (or inner) tables are divided into partitions based on the join key values. Each partition contains rows with the same hash value on the join key.
The number of partitions in each table is typically determined based on the available resources and the distribution of data. The goal is to evenly distribute the data across partitions.

### Local Hash Join:
Each partition of the left table is joined with the corresponding partition of the right table using a local Hash Join. This means that the Hash Join operation is performed independently within each partition.

### Shuffling Phase (Data Exchange):
After the local Hash Join, the results of each partition are reshuffled or exchanged based on the join key values. Rows with the same join key hash values are sent to the same destination node or partition.
This shuffling phase can involve data movement across the distributed system, and it's a critical step in the Partitioned Hash Join.

### Global Hash Join:
Once the data is properly shuffled, a global Hash Join is performed on the redistributed data. This step is similar to a traditional Hash Join but is now performed on a smaller subset of the data since each partition contains only the rows that match the join key values from the other table's partition.

## Cost of Partioned Hash Join

Cost of hash join?
* Assume that we have enough buffers.
* Cost: 3(M + N)
Partitioning Phase:
* Read+Write both tables
* 2(M+N) IOs
Probing Phase:
* Read both tables → M+N IOs


Example database:
* M = 1000, m = 100,000
* N = 500, n = 40,000
Cost Analysis:
* 3 ∙ (M + N) = 3 ∙(1000 + 500) = 4,500 IOs
* At 0.1 ms/IO, Total time ≈ 0.45 seconds

## Observation

No constraint on the size of inner table.
If the DBMS knows the size of the outer table,
then it can use a static hash table.
* Less computational overhead for build / probe operations.
If we do not know the size, then we must use a dynamic hash table or allow for overflow pages.

## Join Algorithms


## Conclusion

Hashing is almost always better than sorting for operator execution.
Caveats:
* Sorting is better on non-uniform data.
* Sorting is better when result needs to be sorted.
Good DBMSs use either (or both).














