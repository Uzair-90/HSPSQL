# Memory Management + Buffer cache

Welcome to the notes of lecture number six. 

## Database Storage

### Spatial Control:
* Where to write pages on disk.
* The goal is to keep pages that are used togather often
		as physically cloase togather as possible on disk.

### Temporal Control:

* When to read pages into memory and when to write them to disk.
* The goal is to minimize the number of stalls having to read 
		data from disk.

