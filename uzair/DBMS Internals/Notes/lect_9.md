# Concurrent Indexes

## B+ Tree Design Choices

* Node Size
* Merge Threshold
* Variable-Length Keys
* Intra-Node Search Keys

## Node Size

The slower the storage device, the larger the optimal node size for a B+ Tree.
* HDD: 1MB
* SSD: 10KB
* In-Memory: 512B

Optimal sizes can vary depending on the workload.
* Leaf node scans VS Root to Leaf traversals.

## Merge Threshold

Some DBMS do not always merge nodes when they are half full.
Delaying a merge operation may reduce the amount of reorganization.
It may also be better to just let smaller nodes exists and then periodically rebuild
entire tree.

## Variable Length keys

### Approach 1: Pointers
* Store the keys as pointers to the tuple's attributes.
### Approach 2: Varaible-Length Nodes
* The size of each node in the index can vary.
* Requires carefull Memory management.
### Approach 3: Padding
* Always pad the key to be max length of the key type.
### Approach 4: Key Map/ Inderection
* Embe an array of pointers that map the key + Value list with in the node.

## Intra-Node Search

### Approach 1: Linear Search 
* Scan node keys from begining to end.
* Use SIMD to vectorize comparisons.

### Approach 2: Binary
* Jump to the middle key, pivot left/right depending on comparison.

### Approach 3: Interpolation
* Approximate location of desired key based on known distribution of keys.

## Optimizations 
* Suffix Truncation
* Pointer swizzling
* Bulk Insert

### Suffix Truncation
The keys in the inner node are only used to "direct traffic".
* We don't need the entrie key.

Store a minimum prefix that is needed to correctly route probes into the index.

### Pointer Swizzling
Nodes use page ids to refrence other nodes in the index. The DBMS must get the momory
location from the page table during traversal.
If a page is pinned in the buffer pool, then we can store raw pointers instead of page ids. This avoids address lookups from the page table.

### Bulk Insert

The fastest way to build a new B+ Tree for an existing table is to first sort the keys 
and then build the index from the bottom up.

## Observation
We (mostly) assumed all the data structures that we have discussed so far are single-threaded.
But a DBMS needs to allow multiple threads to safely access data structures to take 
advantage of additional CPU cores and hide disk I/O stalls. 

## Concurrency Control
A concurrency control protocol is the method that the DBMS uses to ensure “correct” 
results for concurrent operations on a shared object.
A protocol's correctness criteria can vary:
* Logical Correctness: Can a thread see the data that it is supposed to see?
* Physical Correctness: Is the internal representation of the object sound?

## Today's Agenda

* Latches Overview
* Hash Table Latching
* B+Tree Latching
* Leaf Node Scans

## Locks VS Latches

### Locks
* Protect the database's logical contents from other txns.
* Held for txn duration.
* Need to be able to rollback changes.
Latches
* Protect the critical sections of the DBMS's internal data structure from other 
threads.
* Held for operation duration.
* Do not need to be able to rollback changes.

|                 | Locks                 | Latches               |
| --------------- | --------------------- | --------------------- |
|                 | Separate              | User Transactions     |
| Protect         | Database Contents     | In-Memory Data Structures |
| During Modes    | Entire Transactions   | Critical Sections     |
| Modes           | Shared, Exclusive, Update, Intention | Read, Write |
| DeadLock by     | Waits-for, Timeout, Aborts | Coding Discipline  |
| Kept in         | Lock Manager          | Protected Data Structure |













