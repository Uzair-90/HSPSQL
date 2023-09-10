# B plus trees

### Table indexes

A table index is a replica of a subset of a table's attributes that are organized and/or
sorted for efficient access using those attributes.
The dbms ensures that the contents of the table and the index are logically 
synchronized.

It is the dbms job to figure out the best index(es) to use to execute each query.

There is a trade off regarding the number of indexes to create per database.
* Storage overhead.
* Maintainance Overhead.

## Todays agenda

* B+ Tree Overview
* Use in a dbms
* Design Choices 
* Optimizations

# B-tree Family

There is a specific data structure called B tree.
People also use the term to generally refer to a class of balanced tree data structures:
* B-Tree (1971)
* B+ Tree (1973)
* B* Tree (1977)
* B_{link} Tree (1981)

## B+ Tree

A B+ tree is a self-balancing tree data structure that keeps data sorted and allows 
searching, sequential access, insertions, and deletion always in O(log n).

* Generalization of a binary search tree, since a node can have more than two children.
* Optimized for systems that read and write large blocks of data.

### B+ tree properties

A B+ Tree is a M-way search tree with the following properties:
* It is perfectly balanced (i.e every leaf node is at the same depth).
* Every node other than root node must be half full that is:
M/2 <= # keys <= M-1.
* Every inner node with k keys has k+1 non-null children.

### Nodes

Every in B+ Tree node is compromised of an array of key/value pairs.
* The keys are derived from the attribute that the index is based on.
* The value will differ based on whether the node is classified as an inner node or a
leaf node.

The arrays are usually kept in sorted order.

![b plus tree structure](https://github.com/Uzair-90/practice/blob/master/uzair/DBMS%20Internals/b%2B_leaf_node.png)

### Leaf node values

#### Approach #1: Record IDS
A pointer to the location of the tuple to which the index entry corresponds.

#### Approach #2: Tuple data
* The leaf node stores the actual contents of the tuple.
* Secondary indexes must store the record ids as their values.

## B-Tree vs B+ Tree

The original B-Tree from 1972 stored keys and values in all nodes in the tree.
* More space efficient since each key appears once in the tree.

A B+Tree only stores values in the leaf nodes. Inner nodes only guide the search 
process.

## B+ Tree insert

* Find the correct laef node L.
* Insert data entry into L in sorted order.
* If L has enough space done!

Otherwise, split L keys into L and a new node L2.

* Redistribute entries everly, copy up middle key.
* Insert index entry pointing to L2 into parent of L.

To split inner noded redistribute entries evenly, but push up middle key.

### B+ Tree visualization

[Visualize B+ Tree](https://www.cs.usfca.edu/~galles/visualization/BPlusTree.html)

## B+ Tree DELETE

Start at root, find leaf L where entry belongs.
Remove the entry.
If L is atleast half full done!

If L has M/2-1 entries:
* Try to redistribute, borrowing from sibling (adjacent node with same parent L).
* If redistribution fails, try to merge L and sibling.

If merge occured, must delete entry (pointing to L or sibling) from parent of L.

## Selection Conditions

The dbms can use a B+ tree index if query provides any of the attributes of the search
key.

Example index on <a,b,c>

* Supported (a = 1 AND b = 2 AND c =3)
* Supported (a = 1 AND b = 2)
* Supported (b =2),(c = 3)

Not all DBMS support this.
For a hash index we must have all attributes in the search key.

## B+ Tree Duplicate Keys

Approach 1: Append Record IDS

* Add the tuples unique record record id as a part of the key to ensure that all keys 
are unique.
* The DBMS can still use partial keys to find tuples.

Approach 2: Overflow Leaf Nodes

* Allow leaf node to split into overflow node that contain duplicate keys.
* This is more complex to maintain and modify.

## Clustered Indexes

The table is sorted in the sort order specified by the primary key.
* Can be either heap or index-organized storage.

Some DBMS always use a clustered index.
* If a table does not contain a primary key, the DBMS will automatically make a hidden 
primary key.

Other DBMS cannot use them at all.

## Clustered B+ Tree

Traverse to the most left leaf page and then retrieve tuples from all leaf pages.
This will always be better than sorting data for each query.

![clustered b+ tree structure](https://github.com/Uzair-90/practice/blob/master/uzair/DBMS%20Internals/Cluestered_btree.png)


























