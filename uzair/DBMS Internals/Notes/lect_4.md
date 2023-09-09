# Page oriented architecture:

#### Insert a new tuple:
* check page directory to find a page with free slot.
* retrieve the page from disk (if not in memory).
* check slot array to find empty space in a page that will fit.

#### Update existing tuple using its record id:

* Check page directory to find its location.
* Retrieve the page from disk (if not in the memory).
* Find offset in page using slot aray.
* Overwrite existing data if new data fits.

 
### DISCUSSION

 What are the potential problems with this slot page design?

  * Fragmentation: updating multiple tuples at different locations will leave some free space that will lead to fragmentation.

  * Useless I/O: when ever we need to update a particular tuple will have to pass through unnecessary tuples which is quite an expensive operation because accessing disk again and again leads to performance degredation.

  * Random DISK I/O: let us suppose that we have to update 20 different tuples at 20 different pages this is also an expensive operation.

What is the dbms could not overwrite data in pages and could only create a new page? like cloud storage (s3) and hdfs.

### Todays agenda

* Log-structure storage
* Data representation
* System catalogs

### Log Structure storage:
 This architecture is an alternative to page-oriented design.

Dbms stores log records that contain changes to tuples that are (put, delete).

* Each log record must contain a unique identifier that means a totally unique identifier not like page number and offset.
* Put record contain the tuple contents.
* Delete marks the tuple as deleted.

As the application make changes to the database the dbms appends new data to the end of the record file without checking the previous log records.

When the page gets full the dbms write it to the disk and start filling up the new page with the records.

* All disk writes are sequential.
* On-disk pages are immutable.


### Immutable tables:
 Immutable tables are insert-only tables in which existing data cannot be modified. Deleting rows is either prohibited or restricted based on the insertion time of the rows.

So, the basic concept is when one page in memory is full it will flushed to disk, buffer will get empty and start putting new records again and will repeat the process but once a page is flushed to disk it becomes immutable means you cannot change it anymore.

To read a tuple with a given id, the dbms finds the newest record corresponding to that id.

* Scan log from newest to oldest.

Maintain an index that maps a tuple id to the newest log record.

* If log-record is in memory just read it.
* If log-record is on disk page retrieve it.

Each index will work the same as it works in a textbook you look for the page number and and then you go to that page similarly if you need specific record-log the index will give you a pointer to its location.

### Log-structure compaction:
 The log will go forever the dbms needs to periodically compact pages to save the wasted space.

Like you were constantly adding new and new data at the end of each page now you have multiple versions of some records that contain the old version record and also the new ones and you have two pages now to store them while compacting means just take the latest version of each log record and make a new page.

### Note:
 "Timestamp is a unique identifier created by the DBMS to identify the relative starting time of a transaction."

 After a page is being compacted we don't need the temporal ordering of the records anymore. Because they
 were only used to decide which is the latest version of the record once compaction is done we don't need
 them anymore.

 * Each tuple id is guranteed to appear at most once in the page.

 The dbms can then sort the page based on the order of the id to improve efficiency lookup.
 This is also called sorting string tables (SST).


 Compaction coalesces larger log files into smaller log files by removing unnecessary records.

 Check any level compation image over the internet to see how level compaction works but the key idea is
 That when two sorted log files are completely sorted merge them and shift them to an above level like from level 0 to level 1.
 This means that at each higher level you will have larger log files.
 Consolidation, in the context of databases and storage systems, refers to the process of combining or merging multiple smaller units of data or entities into larger, more organized units. This is often done for the purpose of improving efficiency, optimizing performance, and reducing complexity.    


## DISCUSSION

 What are the some downsides of this log-structured approach?

  * Write Amplification: In a log-structured architecture, data is written sequentially in an append-only manner to a log or journal. Over time, as data is updated or deleted, new versions are written to the log, resulting in fragmentation and the creation of obsolete data. This fragmentation and the need for compaction can lead to write amplification.

  * Compaction is expensive.


###  Tuple Storage:
 A tuple is essentially a sequence of bytes. It's the job of the dbms to interpret those bytes into attribute types and values.
 The dbms catalog contains the schema information about the system uses to figure out the tuple's layout.

The tuple storage is independant of the storage architecture whether it is page-oriented design or 
log-structure.

In programming languages like c and c++ if you call floating point numbers it will be not exactly accurate to handle this issue we need fixed precision numbers in databases.

Numeric data types with (potentially) arbitrary precision and scale. Used when rounding errors are unacceptable e.g: numberic, decimal

Many different implementations e.g store an exact variable-length binary representation with additional
meta data.
Can be less expensive if you give up arbitrary precision.

Adding two numerics high precision and accuracy would be pretty much expensive and the system will take few cycles to perform just one operation. 

To check out how expensive it will be check postgres add_numeric function implementation.

Large values: Most databases don't allow a tuple to exceed the size of a single page.

To store values that are larger than a page, the dbms uses seperate overflow storage pages.
* Postgres: Toast (>2kb).
* Mysql: Overflow (>1/2 size of the page).
* Sql server: overflow (> size of the page).

### External value storage:
Some systems allow you to store a very value in an external file.
The dbms cannot manipulate the contents of an external file.
* No durability protections.
* No transaction protections.


### System CATALOGS:
A dbms stores meta-data about databases in its internal catalogs. 

* Tables, columns, indexes, views.
* Users, Permissions.
* Internal Statistics.

Almost every dbms stores the database catalog inside itself.

* Wrap object abstraction around itself.
* Specialized code for bootstraping catalog tables.

You can query the dbms internal information_schema catalog to get info about the database.
![schema info](https://github.com/Uzair-90/practice/blob/master/uzair/cmu_notes/scheme_info.png)

In postgres just type: 
```sql
select * from pg_tables;
``` 


### CONCLUSION

Log-structured storage is an alternative approach to the page-oriented architecture.
The storage manager is not entirely independant from rest of the dbms.

That is all for today thank you.

