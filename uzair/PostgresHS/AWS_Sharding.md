# Sharding on AWS 

In this section we will talk how can you do sharding on AWS by creating different aws instances and then treating one of them as coordinator and the other as worker nodes.

## Creating EC2 instances

I am assuming that the reader knows how to create EC2 instances. So, first of all create two EC2 instances in same security group then open the port range which you will be using to run postgresql databases. After doing this on each instance install postgresql and citus any version you are confortable with then in the configuration files change made the necessary changes which are required to establish connections you will find a detail about this at:

[citus distributed systems documentation](https://docs.citusdata.com/en/v11.1/installation/multi_node_rhel.html)

After you are done with all the instructions given in the documentation provided above create your tables and start working your queries will run in parallel like for demo consider the following:

```sql
CREATE TABLE distributed_table (
    user_id SERIAL PRIMARY KEY,
    name VARCHAR(100),
    email VARCHAR(100)
);

```
In the above table postgres will use user_id as sharding key by default and if you want to check how to select your own key for sharding read the following documentation:

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

Now after inserting the data query you database and your query will run in parrallel and will return you the results.

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
You will experience a good speed.


One last things that I would like to mention if you want to check the that your worker nodes are working successfully or not run the following query and check for the resuts.

```sql
postgres=# SELECT * FROM citus_get_active_worker_nodes();
 node_name  | node_port 
------------+-----------
 3.92.47.79 |      5432
(1 row)

```

Right now I am using just 2 EC2 instances one as coordinator and one as worker my worker node is 3.92.47.79 and my dabtase port is 5432 which is clearly visible in the query result thank you that is all for this tutorial.