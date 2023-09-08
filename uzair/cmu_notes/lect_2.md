Relational data model is the superior data model for databases.

## Relational languages:

*	Data manipulation languages (DML)
*	Data definition languages (DDL)
*	Data control languages (DCL)

Sql is based on bag algebra that contain duplicates not on set algebra that don't 
contain duplicates.

There are three sorts of data collection:
 
#### Lists:
 		It can have duplications with a defined order where you can append data and 
        also pop data.
#### Sets:
 		It doesn't have a defined order but it also don't have any duplications.

#### Bages:
 	 	It also don't have an order but it can allow duplicates.

If we allow duplicated it can make query execution efficient.
 
				

###	Lecture 2 Agneda

* Aggregations + Group By
* String/Date/Time Operations
* Output Control + Redirection
* Nested Queries
* Common Table Expressions
* Window Functions

## Aggregates: 

	Functions that return a single value from a bag of tuples.
	Those functions are:

*	Avg(col)
*	Min(col)
*	Max(col)
*	Sum(col)
*	count(col)

For example using count to return the number of students form login col where they are
 @cs:

```sql
select count(login) as cnt from students where login like '@cs';
                            or
select count(*) as cnt from students where login like '@cs';
                            or
select count(1) as cnt from students where login like '@cs';
```

Get the number of students and their avg gpa where login is @cs:

```sql
select avg(gpa), count(sid) from students where login like '@cs';
```

Get the number of unique students means no duplications where login is @cs:

```sql
select count(DISTINCT login) as cnt from students where login like '@cs';
```


Select the average gpa from students table enrolled in each course from enrolled table:

```sql
select avg(s.gpa), e.cid from enrolled as e, students as s where e.sid = s.sid 
group by e.cid;
```

This will select the average of students enrolled in each course and will group 
them or arrange them them by cid in enrolled table.

Non-aggregated values in select output clause must appear in group by clause like:

```sql
select avg(s.gpa), e.cid, s.name from enrolled as e, students as s where e.sid
         = s.sid group by e.cid,s.name;
```


### Having clause:

If you want to filter your data after aggregation then you must use having clause with
 gourpby like:

```sql
select avg(s.gpa) as avg_gpa, e.cid from endrolled as e, students as s 
            where e.sid = s.sid and avg_gpa > 3.9 group by e.cid;
```

This query is not correct and will produce undefined behaviour because 
here you are trying to filter data with something that is not calculated 
yet which is avg_gpa. So the correct way to do this will be:

```sql
select avg(s.gpa) as avg_gpa, e.cid from endrolled as e, students as s 
            where e.sid = s.sid group by e.cid having avg_gpa > 3.9;
```
Now the above query will first calculate avg_gpa and then it will filter 
your data which is the correct way to do it.

### String operations:

Postgres is case-sensitve for strings and there will be single string quotes.

check for othere databases by yourself.

like is string matching operator used to match strings. e.g:- '15-%', '@c_'

String concatination:

String concatination in postgresql work as following:

```sql
select name from students where login = lower(name) || '@cs';
```
 	or

```sql
select name from students where login = concat(lower(name),'@cs');
```

### Output

```txt
postgres=# select 'uzair' || ' ' || 'rehman';
   ?column?   
--------------
 uzair rehman
(1 row)

postgres=#   select concat('uzair',' ','rehman');
    concat    
--------------
 uzair rehman
(1 row)
```


### Date/Time operations:

```sql
select now();
```

A basic function that will show you the current time and date.

### Output
```txt
postgres=# select now();
              now              
-------------------------------
 2023-08-27 15:15:33.098794+05
(1 row)

select current_timestemp;

the above line have the same functionallity.

select current_timestamp;
       current_timestamp       
-------------------------------
 2023-08-27 15:17:31.567865+05
(1 row)
```

```sql
select date('yyyy/mm/dd');
```

The above function will take the time as a string and will cast it into date type.

### Output
```txt
postgres=# select date('2023-08-27');
    date    
------------
 2023-08-27
(1 row)
```


There is a function that will calculate the number of days between two dates as following:

```sql
select date('date1') -  date('date2') as days;
```
To show a working example of this let us run a query:

```sql
select date('2023-08-27') - date('2001-02-09') as days;
```

### Output

```txt
postgres=# select date('2023-08-27') - date('2001-02-09') as days;
 days 
------
 8234
(1 row)
```
So, I am 8234 days old according to today date that's funny I am feeling too old now.

### Output redirection:

This stores the query results into another tables.

there are rules for it that are:

* Table must not already be defined.
* Table will have the same number of columns with the same types as the input.


Let us suppose you have a table enrolled with many records and you want to store its 
distinct types into a new table here is a query.

```sql
select distinct cid into courseids from enrolled;
```

Let us give a try to this on imdb non-commercial dataset tables.

```sql
select primary_name into dummy_names from name_basics;
```

### Output

```sql
postgres=# select primary_name into dummy_names from name_basics;
SELECT 12660630
postgres=# select * from dummy_names limit 10;
  primary_name   
-----------------
 Fred Astaire
 Lauren Bacall
 Brigitte Bardot
 John Belushi
 Ingmar Bergman
 Ingrid Bergman
 Humphrey Bogart
 Marlon Brando
 Richard Burton
 James Cagney
(10 rows)

```

### Output control:

order by <coloumn> [asc|desc]

The order by clause is used to sort data into ascending or descinding order.

Let us see an example where we will show the data of a table naming name_basics 
ordered by birth year of the person.

```sql
select * from name_basics order by birth_year limit 10;
```

### Output


```txt
postgres=# SELECT * FROM name_basics ORDER BY birth_year LIMIT 10;
  nconst   |    primary_name    | birth_year | death_year |           primary_profession           |              known_for_titles               
-----------+--------------------+------------+------------+----------------------------------------+---------------------------------------------
 nm0144482 | Xavier Castano     |          1 |            | {assistant_director,producer,director} | {tt2909116,tt0338512,tt1701210,tt0870921}
 kk65      | Tim                |          1 |          2 | Actor                                  | cc
 nm0784172 | Lucio Anneo Seneca |          4 |         65 | {writer}                               | {tt0237666,tt0972562,tt0218822,tt0049203}
 nm4511421 | Megan Liz Smith    |         12 |            | {miscellaneous,actress}                | {tt3416744,tt14300912,tt10183848,tt1966378}
 nm1620433 | Karen Abercrombie  |         13 |            | {actress,producer,writer}              | {tt8180386,tt3832914,tt6791350,tt7383268}
 nm8810146 | Paul Walsh         |         21 |            | {actor}                                | {tt0314567,tt0083839,tt0098878,tt0093223}
 nm0430769 | Flavius Josephus   |         37 |         95 | {writer,miscellaneous}                 | {tt0237666,tt0273236,tt0049833,tt0009573}
 nm1306202 | Plutarch           |         46 |        122 | {writer}                               | {tt0056937,tt0237666,tt0272979,tt0472473}
 nm0515385 | Titus Livius       |         59 |         17 | {writer}                               | {tt0003740}
 nm9049180 | Pliny the Younger  |         61 |        113 | {}                                     | {}
(10 rows)
```

### Offset:

This will pick the number of records mentioned in the offset like:


```sql
select * from name_basics offset 10;
```


This will show data after the first 10 as it will skip the first 10 rows;

Example:

```sql
select * from name_basics limit 10;
```

## Output

```txt
  nconst   |  primary_name   | birth_year | death_year |          primary_profession           |             known_for_titles              
-----------+-----------------+------------+------------+---------------------------------------+-------------------------------------------
 nm0000001 | Fred Astaire    |       1899 |       1987 | {soundtrack,actor,miscellaneous}      | {tt0031983,tt0072308,tt0050419,tt0053137}
 nm0000002 | Lauren Bacall   |       1924 |       2014 | {actress,soundtrack}                  | {tt0075213,tt0038355,tt0037382,tt0117057}
 nm0000003 | Brigitte Bardot |       1934 |            | {actress,soundtrack,music_department} | {tt0054452,tt0056404,tt0057345,tt0049189}
 nm0000004 | John Belushi    |       1949 |       1982 | {actor,soundtrack,writer}             | {tt0078723,tt0072562,tt0080455,tt0077975}
 nm0000005 | Ingmar Bergman  |       1918 |       2007 | {writer,director,actor}               | {tt0083922,tt0050976,tt0050986,tt0069467}
 nm0000006 | Ingrid Bergman  |       1915 |       1982 | {actress,soundtrack,producer}         | {tt0036855,tt0038109,tt0038787,tt0034583}
 nm0000007 | Humphrey Bogart |       1899 |       1957 | {actor,soundtrack,producer}           | {tt0034583,tt0043265,tt0042593,tt0037382}
 nm0000008 | Marlon Brando   |       1924 |       2004 | {actor,soundtrack,director}           | {tt0070849,tt0068646,tt0047296,tt0078788}
 nm0000009 | Richard Burton  |       1925 |       1984 | {actor,soundtrack,producer}           | {tt0087803,tt0059749,tt0057877,tt0061184}
 nm0000010 | James Cagney    |       1899 |       1986 | {actor,soundtrack,director}           | {tt0031867,tt0029870,tt0042041,tt0035575}
(10 rows)
```

```sql
select * from name_basics offset 10 limit 10;
```
## Output

```txt
  nconst   |    primary_name     | birth_year | death_year |           primary_profession            |             known_for_titles              
-----------+---------------------+------------+------------+-----------------------------------------+-------------------------------------------
 nm0000011 | Gary Cooper         |       1901 |       1961 | {actor,soundtrack,stunts}               | {tt0034167,tt0035896,tt0027996,tt0044706}
 nm0000012 | Bette Davis         |       1908 |       1989 | {actress,soundtrack,make_up_department} | {tt0031210,tt0056687,tt0035140,tt0042192}
 nm0000013 | Doris Day           |       1922 |       2019 | {soundtrack,actress,producer}           | {tt0045591,tt0053172,tt0049470,tt0048317}
 nm0000014 | Olivia de Havilland |       1916 |       2020 | {actress,soundtrack}                    | {tt0029843,tt0040806,tt0041452,tt0031381}
 nm0000015 | James Dean          |       1931 |       1955 | {actor,miscellaneous}                   | {tt0048028,tt0120956,tt0048545,tt0049261}
 nm0000016 | Georges Delerue     |       1925 |       1992 | {composer,soundtrack,music_department}  | {tt0069946,tt0091763,tt0096320,tt8847712}
 nm0000017 | Marlene Dietrich    |       1901 |       1992 | {soundtrack,actress,music_department}   | {tt0021156,tt0051201,tt0052311,tt0055031}
 nm0000018 | Kirk Douglas        |       1916 |       2020 | {actor,producer,soundtrack}             | {tt0043338,tt0050825,tt0054331,tt0049456}
 nm0000019 | Federico Fellini    |       1920 |       1993 | {writer,director,actor}                 | {tt0047528,tt0050783,tt0056801,tt0071129}
 nm0000020 | Henry Fonda         |       1905 |       1982 | {actor,producer,soundtrack}             | {tt0050083,tt0032551,tt0082846,tt0051207}
(10 rows)
```


In the above example you can see there are first 10 rows displayed but using offset 10 
the next 10 rows are displayed 
and the first 10 rows are skipped.


Nested Queries:


Queries containing other queries. They are often difficult to optimize.
Inner queries can appear always (almost) any where in the parent query.

Example:  Get the names of students who enrolled in 15-445.

```sql
select name from student where sid in (select sid from enrolled where cid = '15-445');
```

Some times in nested query might run every time for each row of outer query like in 
the above the worst case would be if the inner query run each time for outer quey checking new row. So, in that case you need to be carefull.

Here are some keywords and their use in nested queries.

All -> Must satisfy for all rows in the sub-query.

ANY -> must satisfy for atleast one row in the sub-query.

IN -> equivalent to any().

exists -> atleast one row is returned.


Find student record with the highest id that is enrolled in at least one course.

```sql
select sid, name from students where sid in (select max(sid) from enrolled);
```

					or you can also

```sql
select sid, name from students where sid in (select sid from enrolled order by sid desc limit 1);
```


Find all courses that has no students enrolled in it.

```sql
select * from course where not exists (select * from enrolled where course.cid = 
enrolled.cid);
```


Window functions:

performs a sliding calculation across a set of tuples that are related. like an 
aggregation but tuples are not grouped into
single output tuples.


This includes aggregation functions that were previously discussed. It also includes 
some special 
Functions that are row_number() , number of the current row.
rank() , order position of the current row.

Example: 

```sql
select *, row_number over() as row_num from name_basics;
```

Tthis will return the each row number in the table name_basics.

rank() and over():

The RANK() function assigns a unique rank to each distinct row in the result set 
within a specified window partition. If two rows have the same values, they will 
receive the same rank, and the next rank will be skipped. For example, if two rows 
have a rank of 1, the next row will be assigned a rank of 3.


The OVER() clause defines the window partition and the ordering used for the window 
function. It specifies how the data should be partitioned and ordered before applying 
the window function. This allows you to calculate window functions over specific 

subsets of rows within the result set.


Example:

```sql
CREATE TABLE scores (
    student_id INT,
    subject VARCHAR(50),
    score INT
);

INSERT INTO scores (student_id, subject, score)
VALUES
    (1, 'Math', 85),
    (1, 'Science', 92),
    (1, 'History', 78),
    (2, 'Math', 91),
    (2, 'Science', 88),
    (2, 'History', 75),
    (3, 'Math', 79),
    (3, 'Science', 82),
    (3, 'History', 90);
```


Now, suppose we want to rank students based on their scores in each subject.
We'll use the RANK() function along with the OVER() clause:


```sql
SELECT
    student_id,
    subject,
    score,
    RANK() OVER (PARTITION BY subject ORDER BY score DESC) AS rank
FROM scores;
```



### Output

```txt
 student_id | subject | score | rank 
------------+---------+-------+------
          3 | History |    90 |    1
          1 | History |    78 |    2
          2 | History |    75 |    3
          2 | Math    |    91 |    1
          1 | Math    |    85 |    2
          3 | Math    |    79 |    3
          1 | Science |    92 |    1
          2 | Science |    88 |    2
          3 | Science |    82 |    3
(9 rows)
```



### CTE (Common Table Expression):

Its a kind of temporary table or you can also say it's an alternative for nested queries and views.






































