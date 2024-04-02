# Query execution - PART II

### Why is parallel execution necessary or important?
So, there is a very short answer for it we need:
* Higher Throughput
* Lower Latency

This increased the responsiveness of a system.
Potentially lower cost of ownership (TCO). This will reduce the need of more machines because in parrallel execution you increase efficiency of the system without changing the available hardware. This will also reduce enerygy consumptions and other things related to it.

## Parallel VS Distributed Systems

### Distributed Systems
In distributed systems you have load balancers and different nodes which are totally different machines on which a database is distributed they work in collection to achieve results.

### Parallel Systems
In parallel systems you create different workers within a single server. You don't have any extra machines.

## Process Model 
A DBMS process model defines how the system is architectured to support concurrent requests from a multi-user application.

A worker is a DBMS component which is responsible for handling client request and returning results.

### Approaches for DBMS Process Model

* Process per DBMS Worker
* Threads per DBMS Worker
* Embedded DBMS

## Process per worker

Each worker is a seperate OS process like the one that is created by fork() call.
There is a dispatcher which is responsible for creating all the workers or processes and it knows which one are alive and which are dead.
When a query comes in the dispatcher picks up a process and assign the query to it which then works alone on it.

It relied on OS scheduler. It use shared-memory for global data structures. A process crash does not take the whole system down. The databases using this appraoch are Postgrsql and Oracle.

## Threads per worker

Single process with multiple worker threads. In this appraoch we have a single process which have internal working threads. The DBMS manages its scheduling. It's not necessary to use a dispatcher means it may or may not use it. Thread crash may kill the entire system. Example MYSQL, Oracle (2014), MSSQL, DB2.

### Scheduling

For each incoming query the DBMS knows the perfect plan it decides where, when and how to execute it.
It decides how many tasks should it use? How many CPU cores should it use? Which core on should it execute and where to store the results? It knows all of the things. 
The DBMS always know more than the OS.

## SQL Server SQLOS

SQLOS is a user-level OS layer that runs inside of the DBMS and manages provisioned hardware resources. So, it was designed to create an abstraction layer for making sys calls like instead of doing system calls directly from the OS there should be a layer which will do this for user. This means that the user will contact the SQLOS and it will then do the system calls. It determines which tasks are scheduled on to which threads. Also manages I/O scheduling and higher level concepts like logical database locks.

Non-preemptive thread scheduling through instrumented DBMS code.

```txt
There are two types of scheduling: preemptive scheduling and non-preemptive scheduling. Preemptive scheduling allows a running process to be interrupted by a high priority process, whereas in non-preemptive scheduling, any new process has to wait until the running process finishes its CPU cycle.
```

SQLOS quantum is 4 ms but the schedular cannot enforce that. This means we cannot interrupt any task in the middle like OS. You have to add explicit yield calls in the source code. Like if there is a query which may take more than 4 ms to execute and you don't the system to spend too much time on it like if it's unnecessary to complete execution then you can add explicit yield calls to terminate.

### Yield Calls
```txt
The term "yield to call" refers to the return a bondholder receives if the security is held until the call date, prior to its date of maturity. Yield to call is applied to callable bonds, which are securities that let bond investors redeem the bonds (or the bond issuer to repurchase them) early, at the call price.
```

## Embedded DBMS

DBMS runs inside the same address space as the application. The application itself is responsible for threads and scheduling. It is usually a light weighted DBMS like SQLite, level DB etc.

## Advantages of multi threaded architecture

* Less overhead per context switch.
* Do not have to manage shared memory.

The thread per worker does not mean that the system supports intra-query parallalisum.

## Inter VS Intra-Query Parallelism

### Inter-Query Parallalisum

In this approach each worker in the system runs different query at a time.

### Intra-Query Parallelism

It executes the operations of a single query like one query is divided into sub queries and then the result is merged. Decreases latency for long-running queries like OLAP.

## Typer of intra-query parallelism

* Intra-Operator (Horizental)
* Inter-Operator (Vertical)
* Bushy

### Intra-Operator (Horizental)

Decompose operators into independant fragments that perform the same function on different subsets of data.
The DBMS inserts a new operator called exchange into the query plan to coalesce/split results from multiple children/parent operators.
Postgres call this "gather".

### Typer of exhange operator

There are three different types of exhange operators which are following.
![Image of exchange operator not visible](https://github.com/Uzair-90/HSPSQL/blob/master/uzair/DBMS%20Internals/exhange_op_types.png)

### Inter-Operator (Vertical)

Operations are overlapped in order to pipeline data from one stage to another without materialization. In this approach different parts or segments of a query plan are assigned to different workers which work continuesly in a pipeline.
We use this approach for continues data like streaming data where one operator gets continues input and provide continues output to the next oeprator.

This approach is also called pipeline parallelism.

## Bushy Appraoch 

It's a combination of both intra and inter operators and it also needs exchange operators to coalsce results from different workers.


## Observation

Using additional processes/threads to execute queries in parallel will not help in reducing execution time if disk is the main bottleneck.
It may reduce the performance of DBMS worst sometime if worker is accessing different parts of the disk at once. 

## I/O parallelism

In this approach we divide the storage into multiple storage devices instead of one to improve disk bandwidth latency. Some of the approaches are:

* Multiple disks per database.
* One database per disk.
* One relation per disk.
* Split relation across multiple disks.

## Multi-Disk parallelism

You have to configure OS/Hardware to store the DBMS files across multiple storage devices.
* Storage appliances
* RAID configuration

This is transparent to the DBMS.

RAID
```txt
RAID (Redundant Array of Independent Disks) configuration is a way to combine multiple hard disk drives (HDDs) or solid-state drives (SSDs) into a single logical unit.
```

## Database Partitioning

Some DBMS allow you to specify the disk location of each indivisual database. The buffer pool manager will map the page to its location.

# Partitioning

Split single logical table into disjoint physical segments that are stored and managed seperately.
The partitions should logically be transparent to the application. The application should only access logical tables and should not worry how they are stored at physical level.













