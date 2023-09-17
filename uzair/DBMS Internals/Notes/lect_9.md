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
| Separate        | User Transaction      | Threads			      |
| Protect         | Database Contents     | In-Memory Data Structures |
| During Modes    | Entire Transactions   | Critical Sections     |
| Modes           | Shared, Exclusive, Update, Intention | Read, Write |
| DeadLock by     | Waits-for, Timeout, Aborts | Coding Discipline  |
| Kept in         | Lock Manager          | Protected Data Structure |

## Latch Modes

### Read Mode
* Multiple threads can read the same object at the same time.
* A thread can acquire the read latch if another thread has it in read mode.

### Write Mode
* Only one thread can access the object.
* A thread cannot acquire a write latch if another thread has it in any mode.

## Latch Implementation

### Approach 1: Blocking the OS mutex

* Simple to use
* Non-Scalable (about 25 ns per loack/unlock invocation)
* Example: std::mutex

```c++
std::mutex m;
.
.
.
m.lock();
//Do something...
m.unlock();
```
### Approach 2: Reader-Writer Latches

* Allow for concurrent readers. Must manage read/write queues to avoid starvation.
* Can be implemented on top of spinlocks.
* Example: std::shared_mutex

In this latching mode if two threads come to read they will not have to wait they will
get it directly to read it but if then a write thread comes and want to write something
it will wait until the the two threads are done with reading but if one more thread
comes to read it will also have to wait because there is a thread in waiting which is 
waiting to write it.

## Hash table latching

Easy to support concurrent access due to the limited ways threads access the data 
structure.
* All threads move in the same direction and only access a single page/slot at a time.
* Deadlocks are not possible.
To resize the table, take a global write latch on the entire table (e.g., in the 
header page).

### Approach 1: Page Latches
* Each page has its own reader-writer latch that protects its entire contents.
* Threads acquire either a read or write latch before they access a page.

### Approach 2: Slot Latches
* Each slot has its own latch.
* Can use a single-mode latch to reduce meta-data and computational overhead.

Let us consider we are dealing with linear probe hasing where table pages are in sorted
order as p0,p1 and p2 if a thread comes and try to find a key in p1 it will put a read
latch on this page and right after taht another latch comes and tries to write 
something to p1 but it will wait because thread 1 is there to read p1 as soon thread 1 
is finished with reading the page p1 it will release the write latch on p1 and then 
thread 2 will acquire it and will write it.


## B+ Tree concurrency control

We want to allow multiple threads to read and update a B+Tree at the same time.
We need to protect against two types of problems:
* Threads trying to modify the contents of a node at the same time.
* One thread traversing the tree while another thread splits/merges nodes.

## Solution

## LATCH  CRABBING/COUPLING

Protocol to allow multiple threads to access/modify B+Tree at the same time.
* Get latch for parent
* Get latch for child
* Release latch for parent if “safe”
A safe node is one that will not split or merge when updated.
* Not full (on insertion)
* More than half-full (on deletion)


## B E T T E R  LATCHING  A LG O R I T H M

Most modifications to a B+Tree will not require a split or merge.
Instead of assuming that there will be a split/merge, optimistically traverse
the tree using read latches.
If you guess wrong, repeat traversal with the pessimistic algorithm.

### Procedure
Search: Same as before.
Insert/Delete:
* Set latches as if for search, get to leaf, and set W latch on leaf.
* If leaf is not safe, release all latches, and restart thread using previous insert/
delete protocol with write latches.
This approach optimistically assumes that only leaf node will be modified; if not, R 
latches set on the first pass to leaf are wasteful.


## OBSERVATION

The threads in all the examples so far have acquired latches in a "top-down" manner.
* A thread can only acquire a latch from a node that is below its current node.
* If the desired latch is unavailable, the thread must wait until it becomes available.
But what if threads want to move from one leaf node to another leaf node?

Lets suppose that two different threads T1 and T2 wants to search a tree for numbers 
greater than 1. So both of the nodes start at root one goes to the left and goes to 
the right of the tree while scanning the tree both reaches their corresponding sides 
leaf nodes while scanning the leaf nodes of each side both threads must put a read 
latch on their respective sides and when they are done with checking their sides of 
they want to scan the sibilings means now they have to cross sides a latch can't be 
released untill it a thread reaches the sibling leaf node now both of the threads will 
try to access sibling nodes but they have a read latch which will end up in a deadlock 
situation.

## Leaf node scans

Latches do not support deadlock detection or avoidance. The only way we can deal with
this problem is through coding discipline.
The leaf node sibling latch acquisition protocol must support a “no-wait” mode.
The DBMS's data structures must cope with failed latch acquisitions.

## Conclusion

Making a data structure thread-safe is notoriously difficult in practice.
We focused on B+Trees, but the same high-level techniques are applicable to other data
structures.




















