# Summary

# Learning Objectives

# Related
Prev - [[COSC Chapter 19.6.2 Adding a New Node]]

Next - [[COSC Chapter 19.6.4 The Heap Class]]
# Content
Often you need to remove the maximum element, which is the root in a heap. After the root is removed, the tree must be rebuilt to maintain the heap property. The algorithm for rebuilding the tree can be described as follows:

```cpp
Move the last node to replace the root; 
Let the root be the current node; 
while (the current node has children and the current node is 
       smaller than one of its children)                      
{  
  Swap the current node with the larger of its children; 
  Now the current node is one level down; 
} 
```

**Figure 19.13** shows the process of rebuilding a heap after the root 62 is removed from **Figure 19.10a**. Move the last node, 9, to the root, as shown in **Figure 19.13a**. Swap 9 with 59, as shown in **Figure 19.13b**; swap 9 with 44, as shown in **Figure 19.13c**; and swap 9 with 30, as shown in **Figure 19.13d**.

>[!note] Figure 19.13
>![[Pasted image 20241107112152.png]]

**Figure 19.14** shows the process of rebuilding a heap after the root, 59, is removed from **Figure 19.13d**. Move the last node, 17, to the root, as shown in **Figure 19.14a**. Swap 17 with 44, as shown in **Figure 19.14b**, and then swap 17 with 30, as shown in **Figure 19.14c**.

>[!note] Figure 19.14
>![[Pasted image 20241107112349.png]]

## Self-Check
### Describe how to remove an object to a heap.
First replace the root with the last element and swap the root with its largest child if necessary. This process continues until it is in the right place.
### Show the heap after the root in the heap in Figure 23.15c is removed.
![[Pasted image 20241107112528.png]]
# References
