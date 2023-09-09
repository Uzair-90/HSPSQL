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

A B+ tree is a self-balancing tree data structure that keeps data sorted and allows searching, sequential access, insertions, and deletion always in O(log n).

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

 
























