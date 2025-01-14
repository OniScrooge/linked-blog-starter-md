# Summary

# Learning Objectives

# Related
Prev - [[COSC Chapter 19.5 Quick Sort]]

Next - [[COSC Chapter 19.6.1 Storing a Heap]]
# Content
# Key Point

A [[heap sort]] uses a binary heap. It first adds all the elements to a heap and then removes the largest elements successively to obtain a sorted list.

[[Heap sort]] uses a binary heap, which is a [[complete binary tree]]. A binary tree is a hierarchical structure. It either is empty or it consists of an element, called the root, and two distinct binary trees, called the left subtree and right subtree. The length of a path is the number of the edges in the path. The depth of a node is the length of the path from the root to the node.

A _binary heap_ is a binary tree with the following properties:

- Shape property: It is a [[complete binary tree]].
- Heap property: Each node is greater than or equal to any of its children.

A [[complete binary tree]] is if each of its levels is full, except that the last level may not be full and all the leaves on the last level are placed leftmost. For example, in **Figure 19.8**, the binary trees in (a) and (b) are complete, but the binary trees in (c) and (d) are not complete. Further, the binary tree in (a) is a heap, but the binary tree in (b) is not a heap, because the root (39) is less than its right child (42).

>[!note] Figure 19.8
>![[19fig10.png]]

>[!Note]
**​​Heap** is ​a term with many meanings in computer science. In this chapter, heap means a binary heap.

>[!Note]
A [[complete binary tree]] is not a full binary tree. A _full binary tree_ is also known as a perfect binary tree. A _perfect binary tree_ is a binary tree in which all interior nodes have two children and all leaves have the same depth or same level.

>[!note] Pedagogical Note
A heap can be implemented efficiently for inserting keys and for deleting the root. **Figure 19.9** shows an animation of a binary heap.
## Self-Check
### What is a [[complete binary tree]]? What is a heap?
A binary tree is complete if every level of the tree is full except that the last level may not be full and all the leaves on the last level are placed left-most. A heap is a binary tree with the following properties:  
1. It is a [[complete binary tree]].  
2. Each node is greater than or equal to any of its children.
# References
