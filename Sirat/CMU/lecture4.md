
### Lecture 4
# Agenda
* Log-Structured Storage
* Data Representation
* System Catalogs

# Log-Structured Storage
* it is a method of managing data in computer systems. It is particularly well-suited for systems that need to handle a high rate of random writes, such as file systems or databases. The core idea behind LSS is to organize data in a sequential and appends log record to the end of the file without checking previous log records.
* DBMS stores log record that contain changes to tuples (PUT,DELETE).Each log record must contain the tuples unique identifier.put records contains the tuple contents.deletes marks the tuple as deleted.
* when the page gets full, the DBMS writes it out disk and start filling up the next page with records. maintain an index that maps a tuple id to the newest log record.
* log will grow forever so pages are compacted to rreduce wasted space. larger log files into smaller files by removing unnecessary records.(universal compaction, level compaction).
* downside of compaction (write-amplification, compaction is expensive).

# Tuple Storage
* A tuple is essentially a sequence of bytes. It's the job of the dbms to interpret those bytes into attribute types and values. The dbms catalog contains the schema information about the system uses to figure out the tuple's layout. The tuple storage is independant of the storage architecture whether it is page-oriented design or log-structure

# Data Representation
* integer/bigint/smallint/tinyint
* float/real is numeric/decimal
* varchar/varbinary/text/blob 
* time/date/timestamp

 In languages like C and C++, floating-point numbers are approximate representations of real numbers. Due to their nature, they may not always yield exact results, especially in situations involving precise arithmetic operations.


 Databases provide numeric data types, such as numeric or decimal, which offer arbitrary precision and scale. These types allow you to define the exact number of digits for the integral part (precision) and the number of digits to the right of the decimal point (scale).

 different implementation can be less expensive if you give up arbitrary precision

 Most databases don't allow a tuple to exceed the size of a single page.

 To store values that are larger than a page, the dbms uses seperate overflow storage pages.
* Postgres: Toast (>2kb).
* Mysql: Overflow (>1/2 size of the page).
* Sql server: overflow (> size of the page).

# external value storage
some systems allow you to store a really large value in an external file.

 the dbms cannot manipulate the contants of an external file.
* no durability protection
* no transaction protection

# system Catalogs

 A dbms stores meta-data about databases in its internal catalogs.
* Tables, columns, indexes, views
* Users, Permissions
* Internal Statistics

 Almost every dbms stores the database catalog inside itself
* Wrap object abstraction around itself.
* Specialized code for bootstraping catalog tables.


