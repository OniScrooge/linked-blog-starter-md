# Related
Prev - [[COSC Chapter 25.9 AVL Tree time complexity analysis]]

Next - 
# Key Terms
1. **​AVL tree**
2. **balance factor**
3. **left-heavy**
4. **LL rotation**
5. **LR rotation**
6. **perfectly balanced**
7. **right-heavy**
8. **RL rotation**
9. **rotation**
10. **RR rotation**
11. **well balanced​**
# Chapter Summary
1. ​An AVL tree is a well-balanced binary tree.
2. In an AVL tree, the difference between the heights of two subtrees for every node is `0` or `1`.
3. The process for inserting or deleting an element in an AVL tree is the same as for a regular binary search tree. The difference is that you may have to rebalance the tree after an insertion or deletion operation.
4. Imbalances in the tree caused by insertions and deletions are rebalanced through subtree rotations at the node of the imbalance.
5. The process of rebalancing a node is called a _rotation_. There are four possible rotations: LL rotation, LR rotation, RR rotation, and RL rotation.
6. The height of an AVL tree is _O_(log _n_). So, the time complexities for the search, insert, and delete functions are _O_(log _n_).​