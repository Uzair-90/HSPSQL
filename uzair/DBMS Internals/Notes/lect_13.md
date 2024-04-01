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

SQLOS is a user-level OS layer that runs inside of the DBMS and manages provisioned hardware resources. So, it was designed to create an abstraction layer for making sys calls like insted of doing system calls directly from the OS there should be a layer which will do this for user. This means that the user will contact the SQLOS and it will then do the system calls. It determines which tasks are scheduled on to which threads. Also manages I/O scheduling and higher level concepts like logical database locks.

Non-preemptive thread scheduling through instrumented DBMS code.

```txt
There are two types of scheduling: preemptive scheduling and non-preemptive scheduling. Preemptive scheduling allows a running process to be interrupted by a high priority process, whereas in non-preemptive scheduling, any new process has to wait until the running process finishes its CPU cycle.
```



