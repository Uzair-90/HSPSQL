
##  Iecture 5
### Data workloads
Database workloads refer to the types and patterns of operations that a database system must handle. These workloads can vary widely depending on the nature of the application and the requirements of the organization using the database.
* On-Line transactions processing (OLTP)
Fast operations that only read/update small amount of data each time.
* On-Line Analytical processing (OLAP)
Complex queries that read alot of data to compute aggregates.
* Hybrid Transactions + Analytical Processing
OLTP + OLAP on the same database instance

### observation
the relational model does not specify that the DBMS must store all a tuple's attributes together in a single page. 
* OLTP 
simple queries that read/update a small amount of the data that is related to a single entity in the database. this is kind of application that people build first
* OLAP
complex queries that read large portions of the database spanninh multiple entites.

### N-ARY storage model (NSM)
The N-ARY Storage Model (NSM) is a database storage model designed to efficiently handle analytical workloads, particularly those involving complex queries and extensive data retrieval. NSM is optimized for read-heavy operations, making it suitable for data warehousing and business intelligence applications.

The database stores all attributes for a single tuple contiguously in a page

ideal for oltp workload where queries tend to operate only an individal entity and insert heavy workload.

* Advantages:
Fast Inserts, Updates, and deletes.
Good for queries that need the entire tuple.
* Disadvantages:
Not good for scanning large portion of the table or a subset of an attribute. as it will will fetch all the data in the database even useless data into memory.

### Decomposition Storage Model (DSM)
The dbms stores the values of a single attribute for all tuples contiguously in a page. Also known as a column store.

Ideal for olap workloads where raed-only queries perform large scans over the subsets of the table's attributes.

* tuple identification
Tuple identification in a columnar storage model involves mapping the columnar data back to its original row-based representation. This process is crucial when you need to retrieve complete rows of data, perform updates, or support general transactional operations.

tuple identification in a columnar storage model is typically managed using some of the following methods:

* Tuple Indexing:
Indexes are created on one or more columns to facilitate efficient retrieval of specific tuples. These indexes store pointers or references to the tuples, allowing for fast access.

* Tuple Identifiers (TID):
Some columnar databases maintain a Tuple Identifier (TID) for each tuple. A TID is essentially a unique identifier for a tuple within a columnar table. It's not based on physical storage, but rather a logical identifier maintained by the database system.

* Metadata and Catalog Information:
The database system maintains metadata and catalog information about the columns and their respective values. This information is used to identify tuples when executing queries.

* advantages:
reduces the amount wasted I/O because the dbms only reads the data that is need.
better query processing and data compression (more on this later)

* Disadvantages
slow for point queries,inserts,updates,and deletes because of tuple splitting/stitching.

### observation 
I/O is the main bottleneck if the dbms fetches data from disk during query execution. Disk access is typically much slower compared to operations in memory.

the dbms can compress pages to increase the utility of the data moved per I/O operation.

key trade-off is speed vs compression relational
* compressing the database reduces DRAM requirements
* it may decrease CPU costs during query execution.

### database compression
* goal#1: must produce fixed- length values.
This goal emphasizes the importance of producing fixed-length representations of data after compression. Fixed-length values are crucial for maintaining consistent storage patterns, which can simplify various operations within a database system. This approach ensures that each compressed value takes up a predictable amount of space.

* goal#2: Postpone Decompression (Late Materialization)
This principle emphasizes delaying the process of decompression for as long as possible during query execution. By postponing decompression until necessary, the database system can potentially reduce the computational overhead associated with decompression. This is particularly important for optimizing query performance.

* goal#3: must be a lossless scheme.
Ensuring that the compression scheme is lossless is a critical requirement. A lossless compression scheme means that after compression and subsequent decompression, the original data is faithfully recovered without any loss of information. This is crucial for maintaining data integrity and ensuring that the compressed data remains accurate and reliable. 

### lossless vs lossy compression
When a dbms uses compression it will always be lossless because no one wants to loss their data.

Any kind lossy compression must be performed at the application level.

### Compression Granularity:
* BLOCK LEVEL:
Compress a block of tuple for the same table.

* TUPEL LEVEL:
Compress the contents of the entire tuple (NSM only).

* ATTRIBUTE LEVEL.
compress a single attributes within one tuple
can target multiple attributes for the same tuple.

* COLUMN LEVEL.
compress multiple values for one or  ore attributes stored for muliple tuples (DSM only).

### naive compression
compress data using a general-ppurpose algorithm scape of compression is only based on the data provided as input.

  Considerations:
* computatiomal overhead
General-purpose compression algorithms often involve computation-intensive processes such as searching for repeating patterns, encoding, and decoding. This can introduce significant computational overhead, especially for large datasets. The impact on system performance and response times should be carefully evaluated.
* compress vs decompress speed
The speed at which data can be compressed and decompressed is essential, particularly for real-time or interactive systems. Some compression algorithms are faster at compression but slower at decompression, while others may have the opposite characteristics. The choice of algorithm should align with the system's requirements.

the dbms must decompress data first before it can be read and modified.

### observation
ideally,we want the dbms to operate on compressed data without decompressing it first.

### columnar compression
* Run-Length Encoding (RLE):
Run-Length Encoding is a simple compression technique that replaces consecutive repeating values with a count of repetitions. It's particularly effective for columns with long sequences of the same value.
* Bit-Packing Encoding:
Bit-packing involves storing multiple values in a fixed number of bits. For example, if the data has a small range of possible values, bit-packing can be used to represent each value using fewer bits than its original representation.
* Bitmap Encoding:
Bitmap encoding is used for columns with low cardinality (a small number of distinct values). It creates a bitmap for each distinct value, where each bit in the bitmap corresponds to a tuple. If the tuple has the value, the bit is set; otherwise, it's clear.
* Delta Encoding:
Delta encoding involves storing the difference between consecutive values rather than the values themselves. This can be effective for columns with sorted or partially sorted data.
* Incremental Encoding:
Incremental encoding is similar to delta encoding, but it involves storing the difference between a value and its predecessor, allowing for the reconstruction of the original value.
* Dictionary Encoding:
Dictionary encoding creates a mapping between unique values in a column and a corresponding dictionary of codes. The actual data is replaced with the codes. This is useful when a column has a limited set of distinct values.


