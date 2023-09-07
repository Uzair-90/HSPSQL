# Memory Management + Buffer cache

Welcome to the notes of lecture number six. 

## Database Storage

### Spatial Control:
* Where to write pages on disk.
* The goal is to keep pages that are used togather often
		as physically cloase togather as possible on disk.

### Temporal Control:

* When to read pages into memory and when to write them to disk.
* The goal is to minimize the number of stalls having to read 
		data from disk.

### Today's Agenda

* Buffer pool manager
* Replacement policies
* Other memory pools

### Important

Buffer pool manager is the same thing as buffer chache it's actually a kind of 
replacement for OS mmap function here the buffer pool will be in our own control
and will intellegently decide which page to evict and which one to fetch.
It is all about how we move a page back and forth from disk to memory.

### Buffer Pool Organization

Memory region is organized as an array of fixed-length pages.
An array entry is called a frame.

When a dbms request a page, an exact copy is placed into one of these frames.

Dirty pages are buffered and not written to disk immediately.
* Write-Back cache.

So basically buffer pool is an array of fixed sized pages in memory.
It contain an offset to the pages on the disk when dbms requests for a specific 
page it go and fetch the desired page into a free frame.

So, what are dirty pages if there is a page in the buffer pool and something tries
to modify it the buffer pool is not going to write it immediately to the disk. It
will wait so it is also called write-back.

### Buffer pool meta-deta

The page table keeps track of the pages that are currently in the memory.
Also keeps additional meta-deta like:
* Dirty Flag
* Pin/Refrence counter

The page table will make sure that which page is in which frame of the buffer pool
there is no guarantee that the pages will be in sorted order in the buffer pool as
they are on the disk.

Pin/refrence is something like suppose if dbms want to write something to a page
then it will be pinned to make sure that the buffer pool don not evict that page.
A simple boolean flag is enough to do this pinning stuff.

You can also put a kind of latch on a special frame so that no other thread can steal
the page in that frame this will avoid any kind of race condition.

### Note

"All this pinnig and latching stull will occur in page table not directly in the 
buffer pool".

## Locks Vs Latches

### Locks

* Protects the database logical contents from other transactions.
* Held for transaction duration.
* Need to be able to rollback changes.

### Latches

* Protects the critical sections of the dbms internal data structure from other
threads.

* Held for operation duration.
* Do not need to be able to rollback changes.

## Page table VS Page directory

The page directory is the mapping from page ids to page locations in database files.
* All changes must be recoreded on disk to allow the dbms to find on restart.

The page table of the mapping from page ids to a copy of the page in the buffer pool
 frames.
* This is an in memory data structure that does not need to be stored on disk.

## Allocation Policies

### Global policy

* Make decision for all active policies.

### Local Policies

* Allocate frames for a specific queries without considering the behaviour of 
concurrent queries.

* Still need to support sharing pages.

## Buffer Pool Optimizations

* Multiple buffer pools.
* Pre-fetching.
* Scan Sharing.
* Buffer Pool Bypass.

### Multiple Buffer Pools

The dbms always donot have a single buffer pool for the entire system.

* Multiple buffer pool instances
* Per-database buffer pool
* Per-page type buffer pool

Partitioning memory across multiple pool helps reduce latch contention and improve 
locality. 

#### Multiple Buffer Pools

create bufferpool custom_pool size 250 pagesize 8k;

create tablespace custom_tablespace pagesize 8k bufferpool custom_pool;

create table new_table tablespace custom_tablespace (...);

## Multiple Buffer pools

#### Approach#1 object id

* Embed and object identifier in record ids and then maintain a mapping from 
objects to specific buffer pools.

#### Approach#2 Hashing

* Hash the page id to select which buffer pool to select.

## Pre Fetching

The dbms can also pre-fetch pages based on a query plan.

* Sequential Scans
* Index Scans

Let's suppose a query want a certain data and the dbms start looking for it when it
go to the buffer pool and ask for a page whether you have it or not if the page 0
is not available then it will fetch a page from the disk and look the data in that
page but it fails to find data in page 0 then it will start looking for page 1 and 
if it fails again then instead of going again and again to read pages from the disk 
it will pre-fetch multiple pages from the disk into the buffer fools to reduce the
number of reads from the disk this proccess of fetching is known as pre-fetching.

## Scan Sharing

Queries can reuse data retrieved from storage operator or operator computations. 
* Also called synchronized scans.
* This is different from result caching.

Allo multiple queries to attach to a single cursor that scans a table.

* Queries do not have to be the same.
* Can also share intermediate results.

This whole concept means that if one query retrieve some data other queries can 
also use that data it's not typical result caching take it this way like if a 
query fetched some pages from the table then we can use those pages for other queries
as well.

If a query wants to scan a table and another query is also doing this, then the 
dbms will attach the second query's cursor to the existing cursor.

Examples are fully supported in IBM db2, MSSQL and postgresql. Oracle can only
share cursor for identical queries.

## Buffer Pool Bypass

The sequential scan operator will not store fetched pages in the buffer pool to
avoid overhead.

* Memory is local to running query.
* Works well if the operator needs to read a large sequence of pages that are not
contigues on disk.
* Can also be used for temporary data (sorting,joins).

Called light scans in informix.

Like if you need a large data set from the disk you cannot store it in a private 
buffer pool because you will have to do some extra effort on it like putting latches
and other things etc. So, to avoid it bypass the buffer pool and throw the pages 
immediately.

## OS page chache

Most disk operations go through the OS API. Unless the dbms tells it not to, the OS
maintains its own filesystem cache (aka page chache, buffer chache).

Most dbms use direct I/O (O_DIRECT) to bypass the OS's cache.
* Redundant copies of pages.
* Different Eviction Policies.
* Loss of control over I/O.

So what it means the dbms is a simple software for an OS like it comes in the category
of user space below that we have OS space which includes file system and page chache
after that so if the dbms request for a specific page from the file system it will go
and start looking in the page cache maintained by the OS so most of the dbms don't
want this because it may cause the above pointed problems. Postgres use OS page chache.

## Quick demo on postgres

```sql
sync; echo 3 > /proc/sys/vm/drop_caches
\timing
set max_parallel_workers_per_page = 0; set jit = off;

EXPLAIN (ANALYZE, BUFFERS) SELECT SUM(A+B) FROM DUMMY;

```
## Output

```txt
postgres=# EXPLAIN (ANALYZE, BUFFERS) SELECT SUM(A+B) FROM DUMMY;
                                                   QUERY PLAN                                                   
----------------------------------------------------------------------------------------------------------------
 Aggregate  (cost=409.08..409.09 rows=1 width=8) (actual time=12.582..12.583 rows=1 loops=1)
   Buffers: shared hit=109
   ->  Seq Scan on dummy  (cost=0.00..309.05 rows=20005 width=16) (actual time=0.057..4.058 rows=20005 loops=1)
         Buffers: shared hit=109
 Planning:
   Buffers: shared hit=23
 Planning Time: 6.245 ms
 Execution Time: 14.053 ms
(8 rows)

```
In the above output you can see the hit is 109.

Let us run this query one more time.

```sql
EXPLAIN (ANALYZE, BUFFERS) SELECT SUM(A+B) FROM DUMMY;
```
## Output

```txt
postgres=# EXPLAIN (ANALYZE, BUFFERS) SELECT SUM(A+B) FROM DUMMY;
                                                   QUERY PLAN                                                   
----------------------------------------------------------------------------------------------------------------
 Aggregate  (cost=409.08..409.09 rows=1 width=8) (actual time=9.270..9.271 rows=1 loops=1)
   Buffers: shared hit=109
   ->  Seq Scan on dummy  (cost=0.00..309.05 rows=20005 width=16) (actual time=0.013..4.194 rows=20005 loops=1)
         Buffers: shared hit=109
 Planning Time: 0.067 ms
 Execution Time: 9.325 ms
(6 rows)


```

Here in the output you can see the that share hit rate in first one is 23 and in the 
second one it's 109 this means that those pages were loaded in OS page cache by
postgres.


















