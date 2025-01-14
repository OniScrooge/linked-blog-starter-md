# Summary

# Learning Objectives

# Related
Prev - [[COSC Chapter 25.5 Implementing rotations]]

Next - [[COSC Chapter 25.7 The AVL Tree class]]
# Content
## Key Point
Deleting an element from an AVL tree is the same as deleing it from a BST, except that the tree may need to be rebalanced.

As discussed in **Section 21.3**, “Deleting Elements in a BST,” to delete an element from a [[binary tree]], the algorithm first locates the node that contains the element. Let `current` point to the node that contains the element in the [[binary tree]] and `parent` point to the parent of the `current` node. The `current` node may be a left child or a right child of the `parent` node. Two cases arise when deleting an element:

Case 1: The current node does not have a left child, as shown in **Figure 21.10a**. To delete the current node, simply connect the parent with the right child of the current node, as shown in **Figure 21.10b**.

The heights of the nodes along the path from the parent up to the root may have decreased. To ensure that the tree is balanced, invoke

```cpp
balancePath(parent.element); // Defined in Listing 25.1 
```

Case 2: The `current` node has a left child. Let `rightMost` point to the node that contains the largest element in the left subtree of the `current` node and `parentOfRightMost` point to the parent node of the `rightMost` node, as shown in **Figure 21.11a**. The `rightMost` node cannot have a right child but may have a left child. Replace the element value in the `current` node with the one in the `rightMost` node, connect the `parentOfRightMost` node with the left child of the `rightMost` node, and delete the `rightMost` node, as shown in **Figure 21.11b**.

The height of the nodes along the path from `parentOfRightMost` up to the root may have decreased. To ensure that the tree is balanced, invoke

```cpp
balancePath(parentOfRightMost); // Defined in Listing 25.1 
```

## Self-Check
### For the AVL tree in Figure 25.1a, show the new AVL tree after deleting element 107. What [[rotation]] do you perform in order to rebalance the tree? Which node was unbalanced?
After deleting 107, node 100 is unbalanced, perform [[LR rotation]]. The resulting tree is  
![](https://liangcpp.pearsoncmg.com/checkpoint5e/IMAGE26_11.png)
### For the AVL tree in Figure 25.1a, show the new AVL tree after deleting element 60. What [[rotation]] do you perform in order to rebalance the tree? Which node was unbalanced?
After deleting 60, node 55 is unbalanced, perform [[RL rotation]]. The resulting tree is  
![](https://liangcpp.pearsoncmg.com/checkpoint5e/IMAGE26_12.png)
### For the AVL tree in Figure 25.1a, show the new AVL tree after deleting element 55. What [[rotation]] did you perform in order to rebalance the tree? Which node was unbalanced?
After deleting 55, node 60 is unbalanced, perform [[RL rotation]]. The resulting tree is  
![](https://liangcpp.pearsoncmg.com/checkpoint5e/IMAGE26_13.png)
### For the AVL tree in Figure 25.1b, show the new AVL tree after deleting elements 67 and 87. What [[rotation]] did you perform in order to rebalance the tree? Which node was unbalanced?
After deleting 67 and 87 in Figure 29.6b, node 100 is unbalanced, perform [[RR rotation]]. The resulting tree is  
![](https://liangcpp.pearsoncmg.com/checkpoint5e/IMAGE26_14.png)
# References
