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

## Linear Probe Hashing delete

Approach: Tombstone

* Set a marker to indicate that the entry is deleted.
* You can reuse the slot for new keys.

## Non Unique Keys

### Choice 1: Seperate Linked List

* Store values in seperate storage area for each key.

### Redundant Keys

* Store duplicate keys entries togather in the hash table.
* This is easier to implement so this is waht most systems do.

## Robin Hood Hashing

Variant of linear probe hashing that steals slots from rich keys and give them to poor 
keys.

* Each key tracks the number of positions they are from where its optimal position in 
the table.
* On insert, a key takes the slot of another key if the first key is farther away from 
its optimal position than the second key.

## Cuckoo hashing

Use multiple hash tables with different hash seeds.

* On insert, check every table and pick anyone that has a free slot.
* If no table has a free slot, evict the element from one of them and rehash it find a
new locations.

Look-up and deletions are always O(1) because only one location per hash table is 
checked. 
In this hashing algorithm we must keep track of the position from where we started or
else we are going to stuck in an infinite loop.

Best open source implementation is from CMU.

# Observation 

The previous hash tables require the dbms to know the exact number of elements it wants
to store.
* Otherwise, it must rebuild the table if it needs to grow/shrink in size.

Dynamic hash tables resize themselves on demand.
* Chained Hashing.
* Extendible Hashing.
* Linear Hashing.

## Chained Hashing

Maintain a linked list of buckets for each slot in the hash table.
Resolve collisions by placing all the elements with the same hash in key in the same
bucket.

* To detemine whether an element is present hash to its bucket and search for it.
* Insertions and deletions are generalizations of lookups.

## Extendable Hashing

Chained-hashing approach where we split buckets instead of letting the linked-list 
grow forever.

Multiple slot locations can point to the same bucket chain.

Reshuffle bucket entries on split and increase the number of bits to examine.
* Data movement is localized to just the split chain. 

## Linear Hashing

The hash table maintains a pointer that tracks the next bucket to split.

* When any bucket overflows split the bucket at the pointer location.

Use multiple hash tables to find the right bucket for a given key.

Can use different overflow criterian:
* Space utilization.
* Average length of overflow chains.

# Conclusion

Fast data structures that supports O(1) lookups that are all used throughout the dbms
internals.

Hash tables are usually not what you want to use for a table index...





















