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

























