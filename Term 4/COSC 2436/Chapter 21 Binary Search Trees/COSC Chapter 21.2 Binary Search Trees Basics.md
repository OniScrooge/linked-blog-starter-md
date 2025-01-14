# Summary

# Learning Objectives

# Related
Prev - [[COSC Chapter 21.1 Introduction]]

Next - [[COSC Chapter 21.3 Representing Binary Search Trees]]
# Content
## Key Point
A binary search tree can be implemented using a linked structure.

Recall that lists, stacks, and queues are linear structures that consist of a sequence of elements. A [[binary tree]] is a hierarchical structure. It either is empty or consists of an element, called the _root_, and two distinct binary trees, called the _left subtree_ and _right subtree_, either or both of which may be empty, as shown in **Figure 21.1a**. Examples of binary trees are shown in **Figure 21.1b-c**.

## Figure 21.1
![[Pasted image 20241202191433.png]]
![[Pasted image 20241202191446.png]]
![[Pasted image 20241202191455.png]]

The _length_ of a path is the number of the edges in the path. The _depth_ of a node is the length of the path from the root to the node. The set of all nodes at a given depth is sometimes called a _level_ of the tree. _Siblings_ are nodes that share the same parent node. The root of a left (right) subtree of a node is called a _left (right) child_ of the node. A node without children is called a _leaf_. The _height_ of an empty tree is -1. The height of a non-empty tree is the length of the path from the root node to its furthest leaf. Consider the tree in **Figure 21.1b**. The length for the path from node 60 to 45 is 2. The depth of node 60 is 0, the depth of node 55 is 1, and the depth of node 45 is 2. The height of the tree is 2. Nodes 45 and 57 are siblings. Nodes 45, 57, 67, and 107 are in the same level.

A special type of binary tree called a [[binary search tree]] (BST) is often useful. A BST (with no duplicate elements) has the property that for every node in the tree, the value of any node in its left subtree is less than the value of the node, and the value of any node in its right subtree is greater than the value of the node. The binary trees in **Figure 21.1** are all BSTs. This section is concerned with BSTs.

# References
