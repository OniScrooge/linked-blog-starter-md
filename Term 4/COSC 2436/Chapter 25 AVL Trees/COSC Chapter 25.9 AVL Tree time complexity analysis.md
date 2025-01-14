# Summary

# Learning Objectives

# Related
Prev - [[COSC Chapter 25.8 Testing the AVL Tree class]]

Next - [[COSC Chapter Summary 25]]
# Content
## Key Point
Since the height of an AVL tree is O(log n), the time complexity of the `search`, `insert`, and `remove` functions in `AVLTree` is O(log n).

The time complexity of the `search`, `insert`, and `remove` functions in `AVLTree` depends on the height of the tree. We can prove that the height of the tree is _O_(log _n_).

Let _G(h)_ denote the minimum number of the nodes in an AVL tree with height _h_. Obviously, _G_(0) is 1 and _G_(1) is 2. An AVL tree with height h≥2 must have at least two subtrees: one with height h−1 and the other with height h−2. So, G(h)=G(h−1)+G(h−2)+1.Recall that a Fibonacci number at index i can be described using the recurrence relation F(i)=F(i−1)+F(i−2). So, the [[function]] _G_(_h_) is essentially the same as _F_(_i_). It can be proven that h<1.4405 log(n+2)−1.3277, where _n_ in the number of nodes in the tree. Therefore, the height of an AVL tree is _O_(log _n_).

The `search`, `insert`, and `remove` functions involve only the nodes along a path in the tree. The `updateHeight` and `balanceFactor` functions are executed in a [[constant time]] for each node in the path. The `balancePath` [[function]] is executed in a [[constant time]] for a node in the path. So, the time complexity for the `search`, `insert`, and `remove` functions is _O_(log _n_).

## Self-Check
### What is the maximum/minimum height for an AVL tree of 3 nodes, 5 nodes, and 7 nodes?
What is the maximum/minimum height for an AVL tree of 3 nodes is 2/2, for 5 nodes is 3/3, for 7 nodes is 4/3?
### If an AVL tree has a height of 3, what maximum number of nodes can the tree have? What minimum number of nodes can the tree have?
If an AVL tree has a height of 3, what maximum number of nodes can the tree have? 7. What minimum number of nodes can the tree have? 4
### If an AVL tree has a height of 4, what maximum number of nodes can the tree have? What minimum number of nodes can the tree have?
If an AVL tree has a height of 4, what maximum number of nodes can the tree have? 15. What minimum number of nodes can the tree have? 7
# References
