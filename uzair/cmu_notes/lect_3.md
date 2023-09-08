# Disk base architecture

The dbms assumes that the primary storage location of the database is non-volatile disk.

the dbms's components manage to move data between volatile and non-volatile storage.
			 					 					 					 					 					
 					 					 					 					 					   					 	 
Storage hierarchy
* cpu registest						Volatile		 					   		
* cpu chaches			 			Random Access  				
* Dram								Byte Addressable
------------------------------------------------------------------
* Ssd								Non-volatile
* Hdd								Sequential Access
* Network Storage					Block Addressable



In volatile memory we can randomly access any data by their address and even the exact byte.
In non-volatile memory we cannot access the the memory directly but we can access the block
or the exact page which containts the data inside the block or page of memory we will access
data sequentially.


# System design goals

*  Allow the dbms to manage databases that exceed the amount of memory that is 
available.
* Reading/Writing to disk is really expensive so it must be manages carefully to avoid large stalls and performance degradation.
* Random access on disk is much slower than sequential access so, the dbms will want to maximize sequential access.

In disk oriented dbms there is an execution engine that requests the memory for a particular page or block of data then the memory will return it a pointer to the location of the data in disk.

### What is actually memory mapping in a DBMS?

Memory mapping in a database management system (DBMS) is a technique that allows a file's contents to be directly mapped into the address space of a process, effectively allowing the process to access the file's data as if it were in memory. This can provide a more efficient way to work with large data files compared to traditional file I/O operations.

Here's a simplified breakdown of how memory mapping works in a DBMS context:

#### File Mapping:
 When memory mapping is used in a DBMS, a portion of a database file (or the entire file) is mapped to the process's memory space. This mapping is established through system calls provided by the operating system.

#### Virtual Memory:
 The process's virtual memory address space is divided into pages, which are typically small fixed-size units (e.g., 4KB). Each page in the virtual memory corresponds to a page in the actual physical memory (RAM) or, if necessary, to a page in the file being memory-mapped.

#### Lazy Loading:
 When a process accesses a memory-mapped region that hasn't been loaded into physical memory yet, the operating system uses a technique called "lazy loading." This means that only the pages of the file that are actually accessed by the process are brought into physical memory. This helps conserve memory resources.

#### Direct Access:
 Once a portion of the file is memory-mapped, the process can access it using standard memory access mechanisms like pointers. The process reads from and writes to memory locations just like it would with data that's already in its address space.

#### Caching:
 The operating system can manage caching automatically. Accessed data is cached in physical memory, providing fast subsequent access to the same data.

#### Synchronization:
 Memory-mapped files can be shared between processes, which introduces considerations related to data consistency and synchronization. Proper synchronization mechanisms need to be in place to ensure that data remains coherent when multiple processes are accessing and modifying the mapped file concurrently.

#### I/O Operations:
 While reading data from a memory-mapped file is generally efficient, writing data can be more complex. Changes made to the memory-mapped data might not be immediately flushed to the disk, so explicit synchronization or "flushing" operations might be required to ensure data durability.

In a DBMS, memory mapping can be useful for scenarios where large data files need to be accessed quickly and efficiently. For example, a DBMS might use memory mapping to read data from database files, indexes, or temporary storage areas. It's important to carefully manage the memory-mapped regions to avoid memory-related issues and ensure data integrity.

Overall, memory mapping is a technique that leverages the capabilities of modern operating systems to provide a more streamlined and efficient way to work with files, especially in cases where I/O performance is critical, such as in database systems.


The dbms can use memory (mmap) to store the contents of a file into the address space of a programme then why we don't use it?

Using memory-mapped files (mmap) in database management systems (DBMS) can indeed offer some benefits in certain scenarios, but there are also potential drawbacks and considerations that might make their use less common. Let's explore the pros and cons of using mmap for storing file contents in a DBMS:

### Advantages of using mmap in DBMS:

##### Efficiency: 
Memory-mapped files can provide efficient access to data because the operating system handles page caching and loading. This can lead to faster read and write operations compared to traditional file I/O.

##### Simplified I/O:
 Mapped files allow you to treat the file content as if it were in memory. This can simplify I/O operations, as you can use standard memory access methods instead of explicit read and write operations.

##### Memory Utilization:
 Mapped files can make better use of system memory, as only the required portions of the file are loaded into memory. This can be beneficial for large databases where loading the entire file might be inefficient.

### Drawbacks and considerations:

##### Memory Usage:
 While mmap can be memory-efficient, it's important to note that the entire file is not always loaded into memory. Only the accessed portions are loaded. This can lead to unpredictable memory usage patterns, which might impact performance.

##### Concurrency:
 Mapped files can present challenges when it comes to concurrent access. Careful synchronization mechanisms are needed to ensure data consistency and prevent race conditions, especially in a multi-user DBMS environment.

##### Operating System Limitations:
 The availability and behavior of mmap can vary across different operating systems. This can complicate portability and compatibility of DBMS implementations.

##### Fragmentation:
 Frequent mapping and unmapping of files can lead to memory fragmentation, which might degrade performance over time.

##### File System Considerations:
 Memory-mapped files rely on the underlying file system. Some file systems might not support mmap or might have limitations on file size or concurrent mappings.

##### Complexity:
 Implementing memory-mapped file support in a DBMS can add complexity to the codebase. Proper error handling, resource management, and performance optimization require careful design and testing.

##### Write Operations:
 While mmap can be efficient for read-heavy workloads, write operations might be slower due to the need to sync data back to disk. This could be a concern for write-intensive database workloads.

In conclusion, the decision to use memory-mapped files in a DBMS depends on various factors including the specific use case, workload characteristics, performance requirements, and the design philosophy of the DBMS. While mmap can offer benefits like efficient read operations and memory utilization, it also comes with challenges related to concurrency, memory management, and complexity. DBMS developers need to carefully evaluate these trade-offs before deciding whether to adopt mmap for file storage.


### Potential problems with MMAP:

##### Transaction Safety:
 OS can flush dirty pages at any time. As OS is not your friend and can kill your process or operation any time it feels the need.

##### I/O stalls:
 The DBMS doesn't which pages are in memory. The OS will stall (a delay in execution of an instruction in order to resolve a hazard) a thread on page fault.

##### Error Handling:
 As everything is hidden from the DBMS by OS the database will never know if any error occurs whether the file is corrupter or you can't get something from the file system then you don't get an exception because that is the operating system and you will get a sigbus (It can be faced when the user tries to access the memory, which is invalid.).

##### Performance Issues:
 OS data structure contention ( situation in which multiple threads or processes concurrently attempt to access or modify the same data structures maintained by the operating system ). TLB shootdowns.

```txt
Remember one thing is not your friend and will not tolerate any attempt to look for what is hidden.
```


### Database Storage

* How the dbms represents the database files on the disk?
* How dbms manage its memory and moves data back-and-forth from the disk?


### Today's Agenda

* File Storage
* Page Layout
* Tuple Layout


##### File Storage:
 For high performance databases he dbms stores a database as one or more file on disk typically in a proprietary format. The OS doesn't know anything about the format of these files.

##### Storage Manager:
 It is responsible for maintaining database files. Some do their own scheduling for reads and writes to improve spatial and temporal locality of pages.
 It organizes the files as a collection of pages. Tracks data red/written to pages and also tracks the available space.


##### Database Pages:
 A page is a fixed size block of data. It can contain tuples, meta-data, indexes and log records etc.
 Most system donot mix page types like all pages whatever they contain will be of the same type.
 Some system require a page to be self contained.

### Note:
 "In the context of a database management system (DBMS), the term "self-contained pages" typically refers to a design principle used in database storage structures, where each page of data contains all the necessary information and metadata to operate independently without relying on information from other pages. This design approach aims to improve performance, maintain data integrity, and simplify the process of accessing and modifying data."

Each page is given a unique identifier. The dbms uses an indirection layer to map page IDs to their physical locations.

There are three different page notions that are:

Hardware page (Usually 4kb).
OS page (Usually 4kb).
Database page (512B-16kb).

A hardware page is the only page that guarantees to be written atomically means that it could be written completely or not. Like if the system fails to write data it will return a failure message and when I go back and check the page there will no partial data. Means failsafe write.

The page size in databases varies like in sqlite, IBM DB2 and oracle it's 4kb but in postgresql it's 8kb. Mysql is the only database with 16kb page size.

##### Page storage architecture:
 Different dbms manage pages in files on dist in different ways that are:

* Heap FIle organization
* Tree file organization
* Sequential/sorted file organization
* Hashing file organization

##### Heap file:
 A heap file is an unordered collection of pages. With tuples that are stored in random order. 
 It is easy to find pages if there is only a single file.

Functionalities in heap file are create a page, read a page, get a page and delete a page. Must also support iterating over all pages.

Like for example in sqlite there are pages in p0,p1,p2,p3,... if you want to get a particular page then just its offset will page_number * page_size;


We need a meta data to keep track of which file contain which page and also to know which one have free space.

Page Directory: The dbms maintain special pages that contain the location of other data pages in different files. The are also in sync with the meta data and keeps the track of available space in a data page available space means number of free/empty pages.


### Page Layout

##### Page header:
 Every page contains a header of meta-data about what the page contains means page contents that are:

* Page size
* Checksum
* Dbms version
* Transaction visibility
* Compression information

Some system require pages to be self contain like oracle.

### Page layout:
 For any page storage architecture, we now need to decide how to organize data inside of the page. 

--we are still assuming that we are only storing tuples--

There are two different approaches:

* Tuple oriented
* Log structured

##### Tuple storage:
 How to store tuples in a page?

#####  Strawman Idea:
 Keep track the number of the tuples in a page and then just append a new tuple at the end.

There are alot of problems in the given answer for example:

* What happens if we delete a tuple?
* What happens if we have a variable length attribute?

We handle it in the following way:-

The most common scheme is slotted pages. (for view check the image slotted_page.png in the same directory).

There is a slot array at the header of the page. The slot array maps "slots" to the tuples starting position offset.

The header of the page keeps track of:

* The number of used slots.
* The offset of the starting location of the last slot used.

The slot array will tell you the offset of the tuple you are looking for.

The slot array starts from the begining of the page and tuples storing begins from the end and one time will come where the slots and tuples will meet and that is the storage limit of the page.

Deletion in the page depends on its implementation like if you delete tuple #3 from the page then move tuple #4 to the position of tuple #3 and update the slot in the slot array so that now it will be pointing to the new location of of tuple #4.

									

### RECORD IDS

The dbms needs a way to keep track of each indivisual tuples. Each tuple is assigned a unique record identifier.

* Most common: page_id + offset/slot
* Can also contain file location.

This technique is used to find the physical location of a logical tuple. (The physical tuple is the actual data that is stored on disk. The logical tuple is the way that the data is represented in memory. The user interacts with the logical tuple, but the database engine manages the physical tuple).

In postgresql the ctid is 6 bytes. (In PostgreSQL, CTID stands for Column Table Index Description. It is a hidden system column that is present in every table. It stores the physical location of the row within the table. The ctid is a pair of numbers: the block number and the tuple index within the block).

We cannot rely on record identifiers because the databases are free to change them anytime whenever they want so, it's a sort of abstraction or seperation between logical and physical tuples.

So, lets get to the examples.


```sql
postgres=# create table r (id int primary key, val varchar(6));
CREATE TABLE
postgres=# insert into r values(100,'aaa'),(101,'bbb'),(102,'ccc');
INSERT 0 3
postgres=# select * from r;
 id  | val 
-----+-----
 100 | aaa
 101 | bbb
 102 | ccc
(3 rows)
```

```sql
postgres=#  select r.ctid, r.* from r;
 ctid  | id  | val 
-------+-----+-----
 (0,1) | 100 | aaa
 (0,2) | 101 | bbb
 (0,3) | 102 | ccc
(3 rows)
```

```sql
postgres=# delete from r where id = 101;
DELETE 1
postgres=#  select r.ctid, r.* from r;
 ctid  | id  | val 
-------+-----+-----
 (0,1) | 100 | aaa
 (0,3) | 102 | ccc
(2 rows)
```

```sql
postgres=# insert into r values(103,'xyz');
INSERT 0 1
postgres=#  select r.ctid, r.* from r;
 ctid  | id  | val 
-------+-----+-----
 (0,1) | 100 | aaa
 (0,3) | 102 | ccc
 (0,4) | 103 | xyz
(3 rows)
```

```sql
postgres=# vacuum full r;
VACUUM
postgres=#  select r.ctid, r.* from r;
 ctid  | id  | val 
-------+-----+-----
 (0,1) | 100 | aaa
 (0,2) | 102 | ccc
 (0,3) | 103 | xyz
(3 rows)
```

```sql
postgres=# select * from r where ctid = '(0,1)';
 id  | val 
-----+-----
 100 | aaa
(1 row)
```


##### Tuple Layout:
 A tuple is a sequence of bytes. It's the job of the dbms to interpret those bytes into attributes types and values.

##### Tuple header:
 Each tuple has a header that contains the meta-data about it.

* Visibility info (concurrency control)
* Bit Map of NULL values.

We do not need to store meta data about the schema. 

Tuple
-------------------------
|header| attributes data|
-------------------------

 Tuple data is stored in the same order when you create a table it is donw for software engineering purposees else it was stored differently it could have efficient.

 Denormalized tuple data is a data storage technique in which redundant data is stored in a single table. This can improve the performance of queries that access multiple tables, but it can also make the data less consistent and more difficult to update.

In a normalized database, data is stored in separate tables, with each table containing only one type of data. This helps to prevent data redundancy and inconsistencies. However, it can also make queries that access multiple tables slower.

Denormalization can be used to improve the performance of these queries by storing redundant data in a single table. This means that the database does not have to join multiple tables to retrieve the data, which can significantly reduce the amount of time it takes to run the query.

However, denormalization can also make the data less consistent. This is because the same data may be stored in multiple places, and if one of the copies is updated, the other copies may not be updated as well. This can lead to inconsistencies in the data.

Denormalization can also make the data more difficult to update. This is because any change to the data may require updates to multiple tables.

Overall, denormalized tuple data can be a useful technique for improving the performance of queries. However, it is important to weigh the benefits of denormalization against the risks of data redundancy, inconsistency, and difficulty of updating.

Here is an example of denormalized tuple data:

A table of students might have columns for the student's ID, name, age, and GPA. In a normalized database, the GPA would be stored in a separate table, with one row for each GPA. However, in a denormalized database, the GPA could be stored in the student table, along with the other student data. This would make it faster to query the data, but it would also mean that the GPA would be duplicated for each student.

The decision of whether or not to denormalize tuple data depends on the specific application. If the performance of queries is critical, then denormalization may be a good option. However, if data consistency and ease of updating are more important, then normalization may be a better choice.


This is all for today more in next lecture thank you. 

















