# What are we trying to do?

Implementing data sharding using Citus on PostgreSQL involves horizontally partitioning large datasets across multiple nodes, enhancing scalability and performance in a distributed system. Citus, as a PostgreSQL extension, seamlessly integrates with the database engine to enable distributed database management through sharding.

To begin, you choose a sharding key based on an attribute that dictates the distribution of data across nodes. This key is pivotal for ensuring an even distribution of data and optimizing query performance. Subsequently, you create tables as distributed tables, and Citus takes charge of distributing the data across shards on different nodes.

Citus operates transparently to applications, allowing queries to be written in the same manner as with a traditional PostgreSQL database. Behind the scenes, Citus optimizes queries for parallel processing across distributed nodes, significantly improving performance and scalability.

One notable advantage of using Citus is its streamlined integration with PostgreSQL, minimizing the need for application modifications. As queries are executed, Citus efficiently manages the distribution of data and optimizes the workload across nodes.

Additionally, Citus provides robust monitoring and management tools, offering insights into the performance of distributed queries and the status of each shard. Through the implementation of data sharding with Citus on PostgreSQL, organizations can effectively manage large datasets, distribute workloads, and achieve enhanced performance in distributed environments.

# Our Setup

Our setup is a well-architected and balanced distributed system designed for optimal performance and scalability. At its core, we have a single-point server, featuring a robust 6th generation Core i7 processor and 4GB of RAM, ensuring high computing power for handling diverse workloads. Complementing this, our distributed server is a network of five computers, including one coordinator node responsible for load balancing and four worker nodes. Each worker node is equipped with 2nd generation Core i3 processors and 4GB of RAM, contributing to a distributed computing environment that efficiently processes tasks in parallel. This configuration leverages the strengths of the single-point server's formidable processing capabilities while harnessing the collective power of the distributed nodes for enhanced load balancing and workload distribution. The synergy between these components establishes a well-rounded setup capable of meeting the demands of modern computing, whether for complex calculations, data processing, or other resource-intensive tasks.

### Below is our distributed system architecture

![Failed to load image](https://github.com/Uzair-90/HSPSQL/blob/master/uzair/PostgresHS/distributed_architecture.png)

### Single server architecture

![Failed to load image](https://github.com/Uzair-90/HSPSQL/blob/master/uzair/PostgresHS/single_server.png)

# Citus installation and distributed system setup.

Here I will talk a little abstractly because the overall process is a little lengthy but you can always check this using citus and postgresql official documentation. In establishing a distributed system using Citus for PostgreSQL, begin by installing the Citus extension on your PostgreSQL database, following the official documentation for guidance. Once installed, configure the PostgreSQL settings by specifying the coordinator node's IP address and defining the shard range. Create worker nodes on separate computers by installing PostgreSQL and enabling the Citus worker settings in the configuration file. Establish connections between the coordinator and worker nodes using the master_add_node SQL command. Designate one of the worker nodes as the coordinator with the master_set_node_as_coordinator command. Distribute data across shards for parallel processing using the create_distributed_table command. After distribution, remove data from the coordinator node (Check documentation for this). Verify connected nodes using the master_get_active_worker_nodes query. Additional queries like citus_is_enabled and master_get_table_shard_count can be used to check Citus status and table distribution. Finally, monitor system performance with Citus management tools and PostgreSQL monitoring utilities. Adapt IP addresses, ports, and table names according to your specific configuration for a seamless Citus installation and distributed system setup.


# Our dataset for testing single server and distributed server performance

Our dataset is extensive, comprising a total of 60 million rows of information. We've carefully integrated a subset of 10 million rows sourced from Kaggle, a platform known for high-quality data shared by the data science community. The predominant portion, exceeding 50 million rows, originates from the IMDB non-commercial dataset, a comprehensive resource for movie-related information. This blend of curated excellence from Kaggle and the expansive details from IMDB forms the foundation for thorough analyses, providing a nuanced and comprehensive perspective within our dataset.

# Set max_parallel_workers

To optimize high-speed and parallel computation, we've configured our PostgreSQL setup with distinct settings for single-server and distributed environments. On the single server, we've empowered the system with eight parallel worker threads to efficiently process tasks concurrently. In the distributed setup, where we have both master and worker nodes, we've fine-tuned the configuration to enable four parallel threads on each individual node. This tailored approach ensures that our PostgreSQL deployment adapts seamlessly to the computing demands of both centralized and distributed computing scenarios, providing an optimal balance between performance and resource utilization.

### For Single Server (Enable 8 parallel workers)
```sql
-- Set the maximum number of parallel workers
ALTER SYSTEM SET max_parallel_workers = 8;

-- Set the maximum number of parallel workers per gather operation
ALTER SYSTEM SET max_parallel_workers_per_gather = 8;
```

### For Distributed Setup (Enable 4 parallel workers on each node)

```sql
-- Set the maximum number of parallel workers on each node
ALTER SYSTEM SET max_parallel_workers = 4;

-- Set the maximum number of parallel workers per gather operation on each node
ALTER SYSTEM SET max_parallel_workers_per_gather = 4;

```

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


