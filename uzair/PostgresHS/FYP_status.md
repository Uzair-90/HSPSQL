# Query Execution Plan Summary

This section provides a summary of the execution plans for various queries on both the single server and distributed server environments. Each table presents key metrics, such as execution time, planning time, and specific details from the query plans.

## Query 1

```sql
SELECT location, COUNT(*) AS batch_count
FROM beerbatches
GROUP BY location
ORDER BY batch_count DESC;
```

After running the above query on distributed as well as single server on same dataset taken from
kaggle which contains 10 million of rows with 13 columns following are the results which contains several things like execution time etc.

| Metric          | Distributed System | Single Server  |
|-----------------|--------------------|----------------|
| Execution Time  | 16473.031 ms       | 28968.943 ms   |
| Sort Method     | Quicksort          | Quicksort      |
| Memory Usage    | 40kB               | 25kB           |
| Task Count      | 32                 | 3 (Parallel)   |
| Rows Processed  | 104002             | 3333333        |
| Planning Time   | 1.359 ms           | 54.143 ms      |


## Query 2

```sql
SELECT beer_style, AVG(alcohol_content) AS avg_alcohol, AVG(bitterness) AS avg_bitterness
FROM beerbatches
GROUP BY beer_style
ORDER BY avg_alcohol DESC;
```
Above is second query tested on both of the servers and following are the results:

| Metric          | Distributed System | Single Server  |
|-----------------|--------------------|----------------|
| Execution Time  | 365.190 ms         | 41000.048 ms   |
| Sort Method     | Quicksort          | Quicksort      |
| Memory Usage    | 40kB               | 25kB           |
| Task Count      | 32                 | Not applicable |
| Rows Processed  | 312735             | 3333333        |
| Planning Time   | 1.508 ms           | 81.417 ms      |

## Query 3

```sql
explain analyze UPDATE beerbatches
SET alcohol_content = 0.06
WHERE batch_id = 123;
```
For the above query following are the results:

| Metric          | Distributed System | Single Server  |
|-----------------|--------------------|----------------|
| Execution Time  | 207.038 ms         | 27910.691 ms   |
| Task Count      | 1                  | 1              |
| Planning Time   | 0.129 ms           | 4.337 ms       |

## Query 4

```sql
explain analyze INSERT INTO beerbatches (brew_date, beer_style, sku, location, fermentation_time, temperature, ph_level, gravity, alcohol_content, bitterness, color, ingredient_ratio, volume_produced)
VALUES ('2023-01-01', 'IPA', 'IPA123', 'New Brewery', 14, 68.5, 4.2, 1.056, 0.065, 40, 12, 'Hops: 50%, Malt: 40%, Yeast: 10%', 1000);
```

For the above query following are the results:

| Metric          | Distributed System | Single Server  |
|-----------------|--------------------|----------------|
| Execution Time  | 40.669 ms          | 8.102 ms       |
| Task Count      | 1                  | Not applicable |
| Planning Time   | 0.129 ms           | 0.347 ms       |


# Tests performed on IMDB datasets

The following queries are performed on IMDB non commercial dataset which is a very large dataset and contains more than 50 millions records.

## Query 1

```sql
-- Calculate the average rating for each profession in parallel
explain analyze SELECT primaryprofession, AVG(averagerating) AS avg_rating
FROM name_basics nb
JOIN title_principals tp ON nb.nconst = tp.nconst
JOIN title_basics tb ON tp.tconst = tb.tconst
JOIN title_ratings tr ON tb.tconst = tr.tconst
WHERE nb.birthyear BETWEEN 1980 AND 1990
GROUP BY primaryprofession
ORDER BY avg_rating DESC;

```

Following are the results after running the query on both of the servers:

| Metric          | Distributed System   | Single Server      |
|-----------------|----------------------|--------------------|
| Execution Time  | 7.67 seconds         | 242.63 seconds     |
| Sort Method     | Quicksort            | Quicksort          |
| Memory Usage    | 1.649 MB             | 2.177 MB           |
| Task Count      | 20 (Parallel Tasks)  | Not applicable     |
| Rows Processed  | 3,423                | 7,836              |
| Planning Time   | 6.881 ms             | 12.628 ms          |


## Query 2

```sql
EXPLAIN ANALYZE
SELECT nb.primaryname, tb.primarytitle, tr.averagerating
FROM name_basics nb
JOIN title_principals tp ON nb.nconst = tp.nconst
JOIN title_basics tb ON tp.tconst = tb.tconst
JOIN title_ratings tr ON tb.tconst = tr.tconst
WHERE 'Actor' = ANY (nb.primaryprofession)
ORDER BY tr.averagerating DESC
LIMIT 10;

```

Following are the results of the above query on both servers:

| Metric               | Single Server      | Distributed Server |
|----------------------|--------------------|---------------------|
| Execution Time       | 4.35 hours         | 0.001 hours        |
| Sort Method          | External merge     | Quicksort           |
| Disk Usage           | 26.27 MB           | Memory: 25 kB       |
| Parallel Workers     | 2                  | 20                  |
| Rows Processed       | 460,554            | - (not explicitly provided in the EXPLAIN ANALYZE output) |
| Planning Time        | 716.87 ms          | 12.08 ms            |


## Query 3 

After this query 2 the single server was taking alot of time so query 3 and 4 are only tested on distributed systems.

```sql
explain analyze UPDATE name_basics
SET birthyear = 1990
WHERE nconst IN (SELECT nconst FROM title_principals WHERE category = 'Actor');
```

Following are the distributed server results for the aobvoe query:

| Metric                | Distributed Server                                     |
|-----------------------|--------------------------------------------------------|
| Execution Time        | 44.57 seconds                                          |
| Planning Time         | 2.96 ms                                                |
| Rows Updated          | 38                                                     |
| Parallel Workers      | 20                                                     |
| Tasks Shown           | One of 32                                              |
| Nodes                 | 3                                                      |
| Sub-Task Execution    | One of 32 (Workers: 0)                                 |
| Update Operation      | On name_basics_102072 (Table name modified for distributed) |
| Nested Loop Cost      | 1640.54                                                |
| HashAggregate Cost    | 4.50                                                   |
| HashAggregate Memory  | 40kB                                                   |
| Function Scan Time    | 0.181 ms                                               |
| Index Scan Cost       | 8.18                                                   |
| Total Planning Time   | 2.958 ms                                               |
| Total Execution Time  | 44,571.960 ms                                          |

## Query 4:

```sql
explain analyze SELECT tb.genres, AVG(tr.averagerating) AS avg_rating
FROM title_basics tb
JOIN title_ratings tr ON tb.tconst = tr.tconst
GROUP BY tb.genres
ORDER BY avg_rating DESC
LIMIT 5;
```

Following are the distributed server results:

| Metric                         | Distributed Server                                        |
|--------------------------------|------------------------------------------------------------|
| Execution Time                 | 472.432 ms                                                 |
| Planning Time                  | 1.809 ms                                                  |
| Rows Returned                  | 35                                                        |
| Tasks Shown                    | One of 32                                                 |
| Nodes                          | 3                                                         |
| Sub-Task Execution             | One of 32 (Workers: 0)                                    |
| Finalize GroupAggregate        | Cost: 10129.71, Actual Time: 340.733 ms, Rows: 1071         |
| Gather Merge                   | Cost: 10129.71, Actual Time: 340.723 ms, Rows: 1071         |
| Sort                           | Cost: 9129.69, Actual Time: 340.011 ms, Rows: 1071          |
| Partial HashAggregate          | Cost: 9077.09, Actual Time: 337.031 ms, Rows: 1071          |
| Hash Join                      | Cost: 1240.38, Actual Time: 52.080 ms, Rows: 42950         |
| Parallel Seq Scan (tb)         | Cost: 0.00, Actual Time: 0.025 ms, Rows: 324593            |
| Hash                           | Cost: 703.50, Actual Time: 51.812 ms, Rows: 42950          |
| Seq Scan (tr)                  | Cost: 0.00, Actual Time: 0.017 ms, Rows: 42950            |

## Conclusion 
Above table just show a basic comparison between single server and distributed systems on same dataset and same queries the results can clearly clearify it.


