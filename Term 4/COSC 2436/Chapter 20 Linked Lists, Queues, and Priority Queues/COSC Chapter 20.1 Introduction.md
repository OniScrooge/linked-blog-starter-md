# Summary

# Learning Objectives

# Related
Prev - [[COSC Chapter 20 Linked Lists, Queues, and Priority Queues]]

Next - [[COSC Chapter 20.2 Nodes]]
# Content
# Key Point

This chapter focuses on designing and implementing custom data structures. 

**Section 12.4**, Class Templates, introduced a generic `Stack` class. The elements in the stack are stored in an array. The array size is fixed. If the array is too small, the elements cannot be stored in the stack; if it is too large, a lot of space will be wasted. A possible solution was proposed in **Section 12.5**, Improving the `Stack` Class. Initially, the stack uses a small array. When there is no room to add a new element, the stack creates a new array that doubles the size of the old array, copies the contents from the old array to this new one, and discards the old array. It is time-consuming to copy the array.

The vector class, introduced in **Section 12.6**, remedies the shortcomings of arrays. A vector is essentially a flexible array. Its size grows automatically if needed. But a vector is not efficient for the insertion and deletion at the beginning of a vector.

This chapter introduces a new data structure, called [[linked list]]. A linked list is efficient for storing and managing a varying number of elements. It is especially efficient for inserting and deleting elements at the beginning of a list. This chapter also discusses how to implement queues using linked lists.
# References
