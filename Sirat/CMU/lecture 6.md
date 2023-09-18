
##  lecture 6

### Database storage
problem#2: how the dbms manages its memory and move data back-and-forth from disk

* Spatial control:
where to write pages on disk

the goal is to keep pages that are used together often as physically close together as possible on disk

* Temporal control
when to read pages into memory, and when to write them to disk

the goal is to minimize the number of stalls from having to read data from disk

### agenda
* buffer pool manager
* replacement policies
* other memory pools

### buffer pool organization
memory region organized as an array of fixed-size pages.an array entry is called a frame.

when the dbms requests a page, an exact copy is places into one of these frames.

Dirty pages are buffered and not written to disk immediately.

what are dirty pages if there is a page in the buffer pool and something tries to modify it the buffer pool is not going to write it immediately to the disk. It will wait so it is also called write-back.

* Write-Back cache.

### buffer pool meta-data
the page table keeps track of pages that are currently in memory. Also keeps additional meta-deta like:

* Dirty Flag
The "Dirty Flag" is a boolean indicator associated with each page in the buffer pool. It signifies whether the page has been modified since it was brought into memory. If a page is marked as "dirty," it means that changes have been made to it and it needs to be written back to the disk at some point to ensure data durability.

* Pin/Refrence counter
The "Pin/Reference Counter" is a numerical value associated with each page in the buffer pool. It keeps track of how many active references or "pins" exist to a particular page. When a page is first brought into memory, its counter is incremented. When it is no longer needed or evicted from memory, the counter is decremented. This helps in managing the page's lifecycle in the buffer pool.

### locks vs latches
* locks
Purpose: Locks are used to protect the logical contents of the database from interference by other transactions. They prevent concurrent access to the same data by multiple transactions to maintain data integrity.

Duration: Locks are held for the entire duration of a transaction. This ensures that the transaction can perform its operations without interference from other transactions.

Rollback: Transactions holding locks must have the ability to rollback changes. If a transaction encounters an error or needs to be aborted, it must be able to release the locks and undo any changes it has made.
* latches 
Purpose: Latches protect critical sections of the database management system's internal data structures (like buffers, caches, and in-memory structures) from concurrent access by multiple threads or processes. They are used to enforce synchronization within the DBMS itself.

Duration: Latches are held for the duration of a specific operation or critical section. Once the operation is complete, the latch is released.

Rollback: Latches do not need to be able to rollback changes, as they are used for internal synchronization and don't directly impact the logical contents of the database.

### page table vs page directory
* The page directory is the mapping from page ids to page locations in database files.

All changes must be recoreded on disk to allow the dbms to find on restart.
* The page table of the mapping from page ids to a copy of the page in the buffer pool frames.

This is an in memory data structure that does not need to be stored on disk.

 ### allocation policies
 * global policies
 make decisions for all active queries
 * local policies
 allocate frames to a specific queries without considering the behavior of concurrent queries
 still need to support sharing pages.

 ### buffer pool optimization
* Multiple buffer pools.
* Pre-fetching.
* Scan Sharing.
* Buffer Pool Bypass.

### multiple buffer pools.
This optimization strategy involves segregating the buffer pool into multiple pools, each with its own configuration settings. Each pool is responsible for caching specific types of data, such as hot data (frequently accessed), cold data (infrequently accessed), or data from specific tables or indexes. This allows for more fine-grained control over caching behavior and can improve performance by prioritizing access to critical data.

* SQL atatements typically used to create a custom buffer pool:
create bufferpool custom_pool size 250 pagesize 8k;

create tablespace custom_tablespace pagesize 8k bufferpool custom_pool;

create table new_table tablespace custom_tablespace (...);

* approach#1: object id
embed an object identifier in record ids and then maintain a mapping from objects to speccific buffer pool

* approach#2:hashing
hash the page id to select which buffer pool to access.

### pre-fetching
Pre-fetching is a proactive strategy where the database system anticipates future data needs and fetches additional pages into the buffer pool ahead of time. By bringing in data that is likely to be accessed soon, pre-fetching reduces the likelihood of disk I/O delays when the data is actually requested.

the dbms can also prefetch pages based on a query plan
* sequential scans 
* index scans

### scan sharing
Scan sharing optimizes the buffer pool's usage when multiple queries are performing full table scans on the same table concurrently. Instead of duplicating pages in the buffer pool for each scan, the system can share pages among concurrent scans. This reduces the overall memory footprint and improves efficiency.

queries can reuse data retrieved from storage or operator computations.
* also called synchronized scans
* this is different from result caching

allow multiple queries to attach to a single cursor that scans a table
* queries do not have to be the same
* can also share intermediate results

if a query wants to scans a table and another query is already doing this. then the dbms will attach the second querys cursor to the existing cursor.

### buffer pool Bypass
Buffer pool bypass is a technique that allows specific queries or operations to bypass the buffer pool entirely and access data directly from disk. This can be beneficial for certain types of queries that perform better with direct disk access or for queries that involve large sequential scans.

The sequential scan operator will not store fetched pages in the buffer pool to avoid overhead.

* Memory is local to running query.
* Works well if the operator needs to read a large sequence of pages that are not contigues on disk.
* Can also be used for temporary data (sorting,joins).

### os page cache
Most disk operations go through the OS API. Unless the dbms tells it not to, the OS maintains its own filesystem cache (aka page chache, buffer chache).

Most dbms use direct I/O (O_DIRECT) to bypass the OS's cache.

* Redundant copies of pages.
* Different Eviction Policies.
* Loss of control over I/O.

### buffer replacement policies
When the dbms needs to decide to free up a frame to make space for a new page, it must decide which page to evict from the buffer pool.

Goals
Correctnes
Accuracy
Speed
Meta-data overhead

### least-recently used
Maintain a single timestamp of each page when was last accessed. When the dbms needs to evict a page, select one with the oldest timestamp.

Keep the pages sorted to reduce the searching time for eviction.

### clock
Approximation of LRU that doesn't need a seperate timestamp per page.

* Each page has refrence bit.
* When a page is accessed set it to 1.
Organize the pages in a circular buffer with a clock hand:

* Upon sweeping, check if a page bit is set to 1?
* If yes, set to 0 otherwise evict it.

### problems
LRU and clock replacement policies are susceptible to sequential flooding.

* A query performs a sequential scan that reads every page.
* This pollutes the buffer with pages that are red once and then never used.
In some workloads the most recent used page is the most unneeded page.


### better policies: LRU-K
LRU-K is an extension of the Least Recently Used (LRU) cache replacement policy. In standard LRU, the cache keeps track of the most recently accessed items and evicts the least recently used item when the cache is full. LRU-K extends this concept by considering the "K" most recent accesses instead of just the most recent one.

The cache maintains a history of the K most recent accesses to items. This means that it considers not only the most recent access but also the K-1 previous accesses.

When the cache is full and a new item needs to be added, LRU-K considers the entire set of K most recent accesses to determine which item to evict. This can result in more intelligent eviction decisions compared to standard LRU.

### priority hints
the dbms known about the context of each page during query execution.

it can provide hints to the buffer pool on whether a page is important or not.

### dirty pages
* fast path
If a page in the buffer is not dirty then the dbms can simply drop it.

* Slow Path
If a page is dirty then the dbms must write it back to the disk to make sure that its changes are persisted.

Trade off between fast evictions versus dirty writing pages that will not be read again in the future

### backgroud writing 
The dbms can walk through the page table periodically to write the dirty pages to the disk. When a dirty page is safely written, the dbms can evict the page or just unset the dirty flag. Need to be careful the system does not write the dirty pages before their log records are written.

### the dbms can almost always manage memory better thann os.
