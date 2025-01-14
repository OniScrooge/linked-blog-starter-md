# Summary

# Learning Objectives

# Related
Prev - [[COSC Chapter 25.2 Rebalancing Trees]]

Next - [[COSC Chapter 25.4 Overriding the insert function]]
# Content
## Key Point
Since an AVL tree is a [[binary search tree]], `AVLTree` is designed as a [[subclass]] of `BST`.

An AVL tree is a [[binary tree]]. So you can define the `AVLTree` class to extend the `BST` class, as shown in **Figure 25.7**. The `BST` and `TreeNode` classes are defined in **Section 21.2.6.**

## Figure 25.7
![[Pasted image 20241205104921.png]]

In order to balance the tree, you need to know each node’s height. For convenience, store the height of each node in `AVLTreeNode` and define `AVLTreeNode` to be a [[subclass]] of `TreeNode`, defined in lines 8–22 in **Listing 21.3**. Note that `TreeNode` contains the data fields `element`, `left`, and `right`, which are inherited in `AVLTreeNode`. So, `AVLTreeNode` contains four data fields, as pictured in **Figure 25.8**.

## Figure 25.8
![[Pasted image 20241205104947.png]]

In the `BST` class, the `createNewNode()` function creates a `TreeNode` object. This function is overridden in the `AVLTree` class to create an `AVLTreeNode`. Note that the return type of the `createNewNode()` function in the `BST` class is `TreeNode`, but the return type of the `createNewNode()` function in `AVLTree` class is `AVLTreeNode`. This is fine, since `AVLTreeNode` is a [[subtype]] of `TreeNode`.

Searching an element in an AVL tree is the same as searching in a regular [[binary tree]]. So, the `search` function defined in the `BST` class also works for `AVLTree`.

The `insert` and `remove` functions are overridden to insert and delete an element and perform rebalancing operations if necessary to ensure that the tree is balanced.

## Self-Check
### What are the data fields in the AVLTreeNode class?
AVLTreeNode inherits from TreeNode. The height is a new data field defined in AVLTreeNode. The data fields in TreeNode are left and right, pointing to the left and right subtree.
### True or false: AVLTreeNode is a [[subclass]] of TreeNode?
True
### True or false: AVLTree is a [[subclass]] of BST.
True
# References
