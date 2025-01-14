# Summary

# Learning Objectives

# Related
Prev - [[COSC Chapter 25 AVL Trees]]

Next - [[COSC Chapter 25.2 Rebalancing Trees]]
# Content
## Key Point

AVL Tree is a balanced [[binary search tree]].

**Chapter 21** introduced binary search trees. The search, insertion, and deletion time for a [[binary search tree]] depends on the height of the tree. In the worst case, the height is **_O(n)_**. If a tree is [[perfectly balanced]], i.e., it is a [[complete binary tree]], its height is **log** **_n_.** Can we maintain a [[perfectly balanced]] tree? Yes. But it will be costly to do so. The compromise is to maintain a [[well-balanced tree]]—i.e., the heights of two subtrees for every node are about the same.

[[AVL trees]] are well balanced. [[AVL trees]] were invented by two Russian computer scientists, G. M. Adelson-Velsky and E. M. Landis, in 1962. In an AVL tree, the difference between the heights of two subtrees for every node is `0` or `1`. It can be shown that the maximum height of an AVL tree is **_O_(log _n_)**.

The process for inserting or deleting an element in an AVL tree is the same as for a regular [[binary search tree]]. The difference is that you may have to rebalance the tree after an insertion or deletion operation. The [[balance factor]] of a node is the height of its right subtree minus the height of its left subtree. For example, the [[balance factor]] for the node 87 in **Figure 25.1a** is `0`, for the node 67 is `1`, and for the node 55 is `–1`. A node is said to be _balanced_ if its [[balance factor]] is `-1`, `0`, or `1`. A node is said to be [[left-heavy]] if its [[balance factor]] is `-1`. A node is said to be [[right-heavy]] if its [[balance factor]] is `+1`.

## Figure 25.1
![[Pasted image 20241205103713.png]]
![[Pasted image 20241205103727.png]]
# References
