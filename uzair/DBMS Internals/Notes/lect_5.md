# Columnar Databases and Compression

### Database Workloads:

#### On-Line transactions processing (OLTP):
Fast operations that only read/update small amount of data each time.

#### On-Line Analytical processing (OLAP):
Complex queries that read alot of data to compute aggregates.

#### Hybrid Transactions + Analytical Processing:
OLTP + OLAP on the same database instance.

### OBSERVATION

The relational model doesnot specify that the dbms must store all the
tuple's attributes in a single page.

This may not be actually the best layout for some workloads.

In the start it is ok to build an oltp database because you don't have much
data at the start you will have to move on to olap when you start 
injecting large amount of data.


### Database storage models:
The dbms can store tuples in different ways that are better
for either olap or oltp.

## N-ARY storage model (NSM):
The database stores all attributes for a single tuple
contiguously in a page.

Ideal for oltp workloads where queries tend to operate only on an indivisual
entity and insert-heavy workloads.

![n-ary architecture](https://github.com/Uzair-90/practice/blob/master/uzair/DBMS%20Internals/n_ary_storage.avif)

In NSM you may have to check all pages if you need data more than a single tuple.
Even if you need a single attribute from a table the harware will fetch all the
data in the database because it don't know anything about the database and you
will end-up getting useless data into memory.

### NSM Advantages:
* Fast Inserts, Updates, and deletes.
* Good for queries that need the entire tuple.
### Disadvantages:
* Not good for scanning large portion of the table or a subset of an attribute.

## Decomposition Storage Model (DSM):

The dbms stores the values of a single attribute for all tuples contiguously in
a page. Also known as a column sotre.

Ideal for olap workloads where raed-only queries perform large scans over the subsets
of the table's attributes.

Tuple identification in a columnar storage model involves mapping the columnar data 
back to its original row-based representation. This process is crucial when you need 
to retrieve complete rows of data, perform updates, or support general transactional 
operations. Here are a few ways tuple identification can be approached in a decomposed 
storage model:

### Tuple IDs (Row IDs):
One common approach is to assign unique identifiers (IDs) to each 
row of data before it's decomposed into columns. These IDs are maintained alongside 
the columnar data. When you need to retrieve a specific tuple, you can look up its 
corresponding columnar values using the associated tuple ID.

### Vectorized Processing:
In columnar databases, operations are often performed on entire 
columns at once (vectorized processing). To retrieve a tuple, the database system can 
use the tuple ID to identify the position of the data within each column and then 
reconstruct the tuple by combining the relevant values from each column.

### Metadata and Indexing:
Metadata and indexing structures can help map between columnar 
data and tuples. For instance, you can maintain metadata that stores the range of 
tuple IDs present in each column, or you can build indexes that facilitate efficient 
lookup based on tuple IDs.

### Hybrid Storage:
Some systems use a hybrid approach where they combine columnar storage 
with row-based storage. Smaller tables or frequently accessed rows might be stored 
using row-based storage, while larger tables or analytical data could be stored in a 
columnar format. This way, you can leverage the benefits of both storage models while 
managing tuple identification.

### Physical Design Considerations: 
The design of the decomposed storage model can impact tuple identification. For example, the order of columns and their arrangement might 
influence how efficiently tuples can be reconstructed.

It's important to note that while columnar storage offers benefits for certain 
workloads, it might not be ideal for all types of database operations. Transactional 
workloads with frequent updates or insertions might not perform as well with pure 
columnar storage due to the need for tuple reconstruction during those operations.

In summary, tuple identification in a decomposed storage model involves techniques 
such as assigning tuple IDs, using metadata and indexing structures, and leveraging 
vectorized processing to efficiently map between columnar data and original tuples. 
The specific approach taken will depend on the database system's design and the 
trade-offs between storage efficiency and data retrieval performance.  

### Advantages and Disadvatages of DSM:

#### Advantages: 
* Reduces the amount wasted I/O because the dbms only reads the data that it needs.
* Better query processing and data compression.
#### Disadvantages:
	
* Slow for point queries insert, updates and deletes because of tuple splitting
	/stiching.

### Observation:
	
I/O is the main bottleneck if dbms fetches data from disk during query execution.
The dbms can compress the pages to increase the utility of the data moved per I/O operation.
Key trade-off is speed vs compression ratio.
* Compressing the database reduces the DRAM requirements.
* It may decrease cpu cost during query execution.

### Database compression goals:

* Must produce fixed length values. (only exception is var-length values stored in seperate pool).

* Postpone decompression for as long as possible during query execution.
Also known as late-materialization.

* Must be a lossless scheme.

### Lossy vs lossless compression: 
When a dbms uses compression it will always be lossless because no one wants to
loss their data.

Any kind lossy compression must be performed at the application level.

### Compression Granularity:

#### BLOCK LEVEL:
Compress a block of tuple for the same table.
#### TUPEL LEVEL:
Compress the contents of the entire tuple (NSM only).
#### ATTRIBUTE LEVEL.
#### COLUMN LEVEL.

### Naive Compression

Compress data using a general purpose algorithm.
Scope of compression is only based on the input data provided.

LZO(1996), LZ4(2011), Snappy (2011), Oracle OZIP (2014), Zstd (2015).

### Considerations 
* Computational Overhead.
* Compress vs decompress speed.

The dbms must decompress the data first before it can read or potentially modified.
This limits the "scope" of the compression scheme.
The schemes also do not consider the high level meaning or semantics of the data.
The comperssion is performed on page levels because if compress a whole table and
then we need to read it we must first decompress the whole page which is quite 
expensive operation.

 
### OBSERVATION
Ideally, we want our dbms to operate on compressed data without decompressing it
first.

### Columnar Compression Algorithms.

* Run-length Encoding
* Bit-Packing Encoding
* Bitmap Encoding
* Delta Encoding
* Incremental Encoding
* Dictionary Encoding

The most common columnar compression algorithm is Dictionary encoding due to its 
efficiency and wide use.

To explain all of the above algorithms visit the following website:

https://chistadata.com/compression-techniques-for-column-oriented-databases/

## Conclusion
It is important to choose the right sotrage model for the target workload
* OLTP is row store.
* OLAP is column store.

DBMS can combine different approaches for better compression.
Dictionary encoding is probably the most useful because it do not require any
pre sorting.

That is the end of storage representation now we will do home work 2 check the home work 2 directory for its solution and that is all for today.

Thank you.

