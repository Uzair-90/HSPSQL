```sql
select * from s union all select * from r;
```

This above query will return the union of the two tabels s and r by removing all the duplicated.

```sql
select * from s intersection select * from r;
```

The above query will return the intersection of tables s and r.

```sql
select * from s except select * from r;
```

The above query will return s-r.

```sql
select * from r cross join s; or select * from r,s;
```

The above query means (r x s).

## Natural Join:

To perform natural join in sql the syntax is as following:

```sql
select * from s natural join r;
```

### Data model:
 
 	A datamodel is a collection of concepts for describing the data in database.

### Schema: 

	A schema is a description of a practical collection of data using a given model.