# Summary

# Learning Objectives

# Related
Prev - [[COSC Chapter 24.4 Handling Collisions using open addressing]]

Next - [[COSC Chapter 24.6 Load Factor and Rehashing]]
# Content
## Key Point
The separate chaining scheme places all entries with the same hash index in the same location, rather than finding new locations. Each location in the separate chaining scheme uses a bucket to hold multiple entries.

The preceding section introduced handling collisions using _open addressing_. The _open addressing scheme_ finds a new location when a collision occurs. This section introduces handling collisions using [[separate chaining]]. The separate chaining scheme places all entries with the same hash index into the same location, rather than finding new locations. Each location in the separate chaining scheme is called a bucket. A bucket is a container that holds multiple entries.

You can implement a bucket using an array, vector, or `LinkedList`. We will use `LinkedList` for demonstration. You can view each cell in the hash table as the reference to the head of a linked list, and elements in the linked list are chained starting from the head, as shown in **Figure 24.8**.

## Figure 24.8
![[1apbk9cr.bmp]]

## Self-Check
### Show the hash table of size 11 after inserting entries with the keys 34, 29, 53, 44, 120, 39, 45, and 40, using separate chaining.
Use the animation https://liveexample.pearsoncmg.com/dsanimation/SeparateChainingeBook.html to verify your answer. To start, click the Remove All button to empty the hash table and set the load factor threshold to 0.99.
# References
