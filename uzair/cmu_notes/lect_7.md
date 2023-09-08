# Hash Tables

### Data structures for use

* Internal Meta-data
* Core Data Storage
* Temporary data structures
* Table indexes

## Design Decisions

### Data Organization
How we layout data structure in memory/pages and what information to store to support efficient access.

### Concurrency
How to enable multiple threads to access the data structure at the same time without
caching the problem.

# Hash tables

A hash table implements an unordered associative array that maps keys to values.

It uses a hash function to compute an offset into this array for a given key, from which the desired value can be found.

Space complexity O(n).
Time complexity:
* Average O(1).
* Worst O(n).

# Static Hash table

Allocate a giant array that allocates a signle slot for each element you need to store.

To find an entry mod the key by the number of elelemnts to find the offset in the array.

## Assumptions

* Number of elements is known ahead of time and it is fixed.
* Each key is unique.
* Perfect hash function.

If: key 1 != key 2 then: hash(key1)!= hash(key2)

The above assumptions are just theoratical there is no such thing such as perfect hash table. A realistic approach is different from it because we may not know the number of 
keys ahead of time and they may change any time.

## Design decision #1: Hash function
* How to map a large key space into a small domain?
* Trade-off between being fast vs collisions rate.

## Design decision #2: Hashing Scheme
* How to handle key collisions after hashing.
* Trade-off between allocating a large hash table vs additional instructions to get/put 
keys.

# Lecture agenda

* Hash functions 
* Static Hash functions 
* Dynamic Hash functions

## Hash functions

For any input key, return an integer representation of the key.

We do not want to use a cryptographic hash functions for dbms hash table (sha-2).

We want something that is fast and has a low collision rate.

-------------------------------
Some important hash functions.
-------------------------------

* CRC-64 (1957).
Used in networking for error detection.
* Murmur Hash (2008).
Designed as fast, general-purpose hash function.
* Google city hash (2011).
Designed to be fast for short keys like < 64 bytes.
* Facebook XX hash (2012).
From the creater of zstd compression.
* Google city hash (2014).
Designed with better collision rates.

XX hash is the best among all for databases.

## Static Hashing Schemes

* Approach one: Linear Probe Hashing
* Approach two: Robin Hood Hashing
* Approach three: Cuckoo Hashing

### Linear Probe Hashing

Single giant table of slots.

Resolve collision by linearly searching for the next free slot in the table.
* To determine whether an element is present, hask to the location in the index and scan for it.
* Must store the key in the index to know when to stop scanning.
* Insertions and deletions are generalizations of lookups.


















