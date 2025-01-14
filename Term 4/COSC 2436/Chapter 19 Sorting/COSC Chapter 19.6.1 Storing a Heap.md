# Summary

# Learning Objectives

# Related
Prev - [[COSC Chapter 19.6 Heap Sort]]

Next - [[COSC Chapter 19.6.2 Adding a New Node]]
# Content
A heap can be stored in a vector or an array if the heap size is known in advance. The heap in **Figure 19.10a** can be stored using the array in **Figure 19.10b**. The root is at position 0, and its two children are at positions 1 and 2. For a node at position $i−1$, its left child is at position $2i+1$, its right child is at position $2i+2$, and its parent is $(i−1)/2$. For example, the node for element 39 is at position 4, so its left child (element 14) is at $9(2*4+1)$, its right child (element 33) is at $10(2*4+2$), and its parent (element 42) is at $1((4−1)/2)$

>[!note] Figure 19.10
>![[Pasted image 20241107111526.png]]
## Self-Check
### When a heap in Figure 19.10a is stored in a list, what is index for element 44? What is the index of parent for 44 and what is the index of left and right children of 44?
The index for 44 is 5. The parent index for 44 is 2. The left child index for 44 is 11 and the right child index for 44 is 12.
# References
