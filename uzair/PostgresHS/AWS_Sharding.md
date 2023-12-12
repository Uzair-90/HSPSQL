# Sharding on AWS 

In this section we will talk how can you do sharding on AWS by creating different aws instances and then treating one of them as coordinator and the other as worker nodes.

## Creating EC2 instances

I am assuming that the reader knows how to create EC2 instances. So, first of all create two EC2 instances in same security group then open the port range which you will be using to run postgresql databases. After doing this on each instance install postgresql and citus any version you are confortable with then in the configuration files made the necessary changes which are required to establish connections you will find details about this at:

[citus distributed systems documentation](https://docs.citusdata.com/en/v11.1/installation/multi_node_rhel.html)

After you are done with all the instructions given in the documentation ( link provided above) create your tables and start working. Your queries will run in parallel for a demo consider the following:

```sql
CREATE TABLE distributed_table (
    user_id SERIAL PRIMARY KEY,
    name VARCHAR(100),
    email VARCHAR(100)
);

```
In the above table postgres will use user_id as sharding key by default and if you want to know how to select your own key for sharding read the following documentation:

[choosing sharding key](https://docs.citusdata.com/en/v11.3/sharding/data_modeling.html)

Now let us insert some data into the table:

```sql
INSERT INTO distributed_table (name, email) VALUES
    ('John Doe', 'john.doe@example.com'),
    ('Jane Smith', 'jane.smith@example.com'),
    ('Abdullah Khan', 'abd.khan@example.com'),
    ('Harris', 'harris@example.com'),
    ('Uzair Rehman', 'Uzair.Rehman@example.com'),
    ('Sirat', 'Sirat@example.com')
    ;

```

Now after inserting the data query your database and your query will run in parrallel and will get the reults at coordinator node.

```txt
postgres=# select * from distributed_table;
 user_id |     name      |          email           
---------+---------------+--------------------------
       1 | John Doe      | john.doe@example.com
       2 | Jane Smith    | jane.smith@example.com
       3 | Abdullah Khan | abd.khan@example.com
       4 | Harris        | harris@example.com
       5 | Uzair Rehman  | Uzair.Rehman@example.com
       6 | Sirat         | Sirat@example.com
(6 rows)

```
You will experience a good execution speed.


I would like to mention if you want to check that your worker nodes are working successfully or not run the following query and check for the resuts.

```sql
postgres=# SELECT * FROM citus_get_active_worker_nodes();
 node_name  | node_port 
------------+-----------
 3.92.47.79 |      5432
(1 row)

```

Right now I am using just 2 EC2 instances one as coordinator and one as worker my worker node is 3.92.47.79 and my dabtase port is 5432 which is clearly visible in the query result.

## Creating a sharded table 
To shard a table use the following command in postgres:
```sql
SELECT create_distributed_table('distributed_table','user_id');

```
This will distribute your table into shards.

Before the sharding the table query planning time was 0.5 ms and execution time was .890 ms but after sharding planning time was 00.12 ms but execution time was 0.025 ms so here you can see a clear different in the execution time.

Running the same commands on my local machine results in execution time of 0.07 ms and planning time was 8.911 ms which is quite slow as compare to sharded tables.

To check distributed table run the following command:

```sql
SELECT * FROM citus_shards;
```
