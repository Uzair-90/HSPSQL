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

The page table of the mappring from page ids to a copy of the page in the buffer pool
 frames.
* This is an in memory data structure that does not need to be stored on disk.




















