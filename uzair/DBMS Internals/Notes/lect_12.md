# Query Execution Part 1

Today's Agenda

* Processing Models 
* Access Methods
* Modification Queries
* Expresssion Evaluation

## Processing Models

A DBMS's processing model defines how the system executes a query plan.
* Different trade-offs for different workloads.
### Approach #1: Iterator Model
### Approach #2: Materialization
### Model Approach #3: Vectorized / Batch Model

## Iterator Model

Each query plan operator implements a Next() function.
* On each invocation, the operator returns either a single tuple or a null marker if there are 
no more tuples.
* The operator implements a loop that calls Next() on its children to retrieve their tuples and 
then process them. Also called Volcano or Pipeline Model.

Next() Function: Each operator in a query plan implements a Next() function. This function is used to retrieve the next tuple from the operator's input source. The tuple contains the result of the query operation, and it's returned to the parent operator.

Returning Tuples or Null: When Next() is invoked, the operator can return either a single tuple representing a query result or a null marker if there are no more tuples to be returned. This null marker indicates the end of the result set.

Looping Over Child Operators: The operator implementing the Next() function typically has one or more child operators. To retrieve and process tuples, the operator calls Next() on its child operators. This creates a processing pipeline where each operator consumes tuples from its children, processes them, and passes the results up to its parent.

## Materialization Model

This model is primarily concerned with how the query execution operators handle intermediate results and how they produce the final result set. Here are the key characteristics of the Materialization Model:

Batch Processing: In the Materialization Model, each operator processes its entire input all at once. This means that the operator collects and processes all relevant data before emitting any output. This is in contrast to streaming or pipelined processing models where operators emit output as soon as they process a portion of their input.

Materialization of Output: The term "materialization" refers to the process of creating a complete, concrete result set. In this model, each operator generates and stores its entire output, either as a single result or a complete set of rows or columns, before passing it on to the next operator or returning it to the user.

Optimization Opportunities: The DBMS can take advantage of the Materialization Model to optimize query execution. For example, the system can use hints like LIMIT to limit the number of rows processed or returned, which can improve performance by avoiding the need to process the entire dataset.

Output Formats: The Materialization Model allows for flexibility in the format of the output. Operators can emit either whole tuples (NSM - Not-So-Materialized) or subsets of columns (DSM - Materialized) based on the specific requirements of the query.

Here's a simplified example to illustrate how this model works:

Suppose you have a SQL query that involves selecting all columns from a table:

```sql
SELECT * FROM Customers WHERE Country = 'USA'
```
In the Materialization Model:

The operator responsible for the WHERE clause processes all rows of the Customers table, identifying those with 'USA' as the country.

Instead of immediately emitting each matching row, the operator materializes the entire result set of matching rows as a temporary table.

Once the entire result set is materialized, it is either returned to the user or passed to the next operator for further processing.

## Question
What happens if the intermediate result doesn't fit into memory?

## Ans
To handle large result sets that can't fit entirely in memory, database systems often use disk-based storage for temporary results. This involves writing portions of the result set to disk and then reading them back as needed. This process is known as "spilling to disk."

Better for OLTP workloads because queries only
access a small number of tuples at a time.
* Lower execution / coordination overhead.
* Fewer function calls.
Not good for OLAP queries with large intermediate results.


## Vectorized Processing Model

Like the Iterator Model where each operator implements a Next() function, but...
Each operator emits a batch of tuples instead of a single tuple.
* The operator's internal loop processes multiple tuples at a time.
* The size of the batch can vary based on hardware or query properties.

Vectorized query processing, also known as vectorized execution or vectorization, is an optimization technique used in some DBMSs to improve query performance. It involves processing and manipulating data in large batches, typically using SIMD (Single Instruction, Multiple Data) instructions supported by modern CPUs. This approach aims to reduce the overhead associated with processing individual rows or tuples one at a time and takes advantage of parallelism in hardware.

Here are key aspects of the vectorized processing model in DBMS:

Batch Processing: Instead of processing one row or tuple at a time, vectorized query processing works on batches of rows, often referred to as "vectors" or "column batches." These batches can contain multiple values for each column involved in the query.

SIMD Instructions: The DBMS uses SIMD instructions provided by the CPU to perform operations on entire batches of data in a single instruction. SIMD instructions are designed for data-level parallelism and can process multiple data elements simultaneously.

Columnar Storage: Vectorized processing is particularly well-suited for columnar storage databases, where data for each column is stored separately. This allows for efficient batch processing of individual columns, which is a characteristic of vectorized execution.

Predication: Predication is a technique used to filter and select rows within a batch based on specific conditions. It can be performed efficiently in a vectorized processing model, where operations are applied to entire batches.

Aggregation and Join Operations: Common database operations like aggregation and joins can benefit significantly from vectorized processing. These operations involve complex calculations on large datasets, making them ideal candidates for optimization.

Code Generation: Some DBMSs use code generation techniques to generate optimized code for specific queries, taking into account the vectorized processing model. This approach tailors the execution plan to the query and the hardware architecture.

Ideal for OLAP queries because it greatly reduces the number of invocations per operator.
Allows for operators to more easily use vectorized (SIMD) instructions to process batches of tuples.

## Note

```txt
SIMD stands for "Single Instruction, Multiple Data." It is a type of parallel processing architecture and instruction set used in modern microprocessors and CPUs to perform the same operation on multiple data elements simultaneously. SIMD instructions allow for efficient data-level parallelism and are particularly well-suited for tasks that involve large datasets and repetitive calculations. 
```

## Plan Processing Approach

Approach #1: Top-to-Bottom
* Start with the root and "pull" data up from its children.
* Tuples are always passed with function calls.
Approach #2: Bottom-to-Top
* Start with leaf nodes and push data to their parents.
* Allows for tighter control of caches/registers in pipelines.

## Acsess Methods

An access method is the way that the DBMS accesses the data stored in a table.
* Not defined in relational algebra.
Three basic approaches:
* Sequential Scan
* Index Scan (many variants) → Multi-Index Scan

For each page in the table:
* Retrieve it from the buffer pool.
* Iterate over each tuple and check whether to include it.
The DBMS maintains an internal cursor that tracks the last page / slot it examined.

This is almost always the worst thing that the DBMS can do to execute a query, but it may be the only choice available.

Sequential Scan Optimizations:
* Prefetching
* Buffer Pool Bypass
* Parallelization
* Heap Clustering
* Late Materialization
* Data Skipping

## Data Skipping

Approach #1: Approximate Queries (Lossy)
* Execute queries on a sampled subset of the entire table to produce approximate results.
* Examples: BlinkDB, Redshift, ComputeDB, XDB, Oracle, Snowflake, Google BigQuery, DataBricks
Approach #2: Zone Maps (Loseless)
* Pre-compute columnar aggregations per page that allow the DBMS to check whether queries need to access it.
* Trade-off between page size vs. filter efficacy.
* Examples: Oracle, Vertica, SingleStore, Netezza, Snowflake, Google BigQuery

## Zone Maps

Pre-computed aggregates for the attribute values in a page. DBMS checks the zone map first to decide whether it wants to access the page.

The zone maps technique is lossyless because if I want to run a query:

```sql
select * from table where val > 600;
```
The DBMS will perform a sequential scan on the column and will find the aggregates that are:

max, min, avg, sum, count.

Then it will check if the max is less than 600 it will skip the entire column for checking
val > 600.

## Index Scan

The DBMS picks an index to find the tuples that the query needs.
   
Which index to use depends on:
* What attributes the index contains
* What attributes the query references
* The attribute's value domains
* Predicate composition
* Whether the index has unique or non-unique keys

(We will cover the above things in lecture 14).

## Example

Consider the following query:

```sql
SELECT * FROM students WHERE age < 30
AND dept = 'CS' AND country = 'US';
```

Suppose that we have a single table with 100 tuples and two indexes:
* Index #1: age
* Index #2: dept

### Scenario #1

There are 99 people under the age of 30 but only 2 people in the CS department.

In this scenario we want to index on the department because it will result into quick lookup.

### Scenario #2

There are 99 people in the CS department but only 2 people under the age of 30.

In this scenarion we want ot index on the age because it will result into quick lookup.

## Multi-Index Scan

If there are multiple indexes that the DBMS can use for a query:
* Compute sets of Record IDs using each matching index.
* Combine these sets based on the query's predicates (union vs. intersect).
* Retrieve the records and apply any remaining predicates.
Examples:
* DB2 Multi-Index Scan
* PostgreSQL Bitmap Scan
* MySQL Index Merge

With an index on age and an index on dept:
* We can retrieve the Record IDs satisfying age<30 using the first,
* Then retrieve the Record IDs satisfying dept='CS' using the second,
* Take their intersection
* Retrieve records and check country='US'.

## Modification Queries

Operators that modify the database (INSERT, UPDATE, DELETE) are responsible for modifying
the target table and its indexes.
* Constraint checks can either happen immediately inside of operator or deferred until later in query/transaction.
The output of these operators can either be Record Ids or tuple data (i.e., RETURNING).

























