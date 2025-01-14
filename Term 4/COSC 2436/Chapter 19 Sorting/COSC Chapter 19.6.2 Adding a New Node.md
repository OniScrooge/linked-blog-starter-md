# Summary

# Learning Objectives

# Related
Prev - [[COSC Chapter 19.6.1 Storing a Heap]]

Next - [[COSC Chapter 19.6.3 Removing the Root]]
# Content
To add a new node to the heap, first add it to the end of the heap and then rebuild the tree as follows:

```cpp
    Let the last node be the current node; 
    while (the current node is greater than its parent) 
    { 
      Swap the current node with its parent; 
      Now the current node is one level up; 
    } 
```

Suppose a heap is initially empty. The heap is shown in **Figure 19.11**, after adding numbers 3, 5, 1, 19, 11, and 22 in this order.

>[!note] Figure 19.11
>![[Pasted image 20241107111819.png]]

Now consider adding 88 into the heap. Place the new node 88 at the end of the tree, as shown in **Figure 19.12a**. Swap 88 with 19, as shown in **Figure 19.12b**. Swap 88 with 22, as shown in **Figure 19.12c**.

>[!note] Figure 19.12
>![[Pasted image 20241107111924.png]]

## Self-Check
### Describe how to add a new object to a heap.

First add the new object to the end of the list and compare/swap it with its parent repeatedly until it is in the right place.

### Add the elements 4, 5, 1, 2, 9, and 3 into a heap in this order. Draw the diagrams to show the heap after each element is added.

![[Pasted image 20241107112010.png]]

# References
