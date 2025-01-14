# Summary

# Learning Objectives

# Related
Prev - [[COSC Chapter 25.3 Designing Classes for AVL Trees]]

Next - [[COSC Chapter 25.5 Implementing rotations]]
# Content
## Key Point
Inserting an element into an AVL tree is the same as inserting it to a BST, except that the tree may need to be rebalanced.

​​​​​A new element is always inserted as a leaf node. As a result of adding a new node, the heights of the ancestors of the new node may increase. After insertion, check the nodes along the path from the new leaf node up to the root. If a node is found unbalanced, perform an appropriate rotation using **Listing ​25.1**​:​

## **Listing 25.1 Balancing Nodes on a Path**
```cpp
void balancePath(T& e) 
{ 
  Get the path from the node that contains element e to the root, 
    as illustrated in Figure 25.9; 
  for each node A in the path leading to the root 
  { 
    Update the height of A; 
    Let parentOfA denote the parent of A, 
      which is the next node in the path, or NULL if A is the root; 
 
    switch (balanceFactor(A)) 
    { 
      case -2: if balanceFactor(A.left) = -1 or 0 
                 Perform LL rotation; // See Figure 25.2 
               else 
                 Perform LR rotation; // See Figure 25.4 
               break; 
      case +2: if balanceFactor(A.right) = +1 or 0 
                 Perform RR rotation; // See Figure 25.3 
               else 
                 Perform RL rotation; // See Figure 25.5 
    } // End of switch 
  } // End of for 
} // End of function 
```

## Figure 25.9
![[r1y3g58x.bmp]]

The algorithm considers each node in the path from the new leaf node to the root. Update the height of the node on the path. If a node is balanced, no action is needed. If a node is not balanced, perform an appropriate [[rotation]].

## Self-Check
### For the AVL tree in Figure 25.1a, show the new AVL tree after adding element 40. What [[rotation]] do you perform in order to rebalance the tree? Which node was unbalanced?
After inserting 40, node 55 is unbalanced, perform [[LL rotation]]. The resulting tree is  
![](https://liangcpp.pearsoncmg.com/checkpoint5e/IMAGE26_7.png)
### For the AVL tree in Figure 25.1a, show the new AVL tree after adding element 50. What [[rotation]] do you perform in order to rebalance the tree? Which node was unbalanced?
After inserting 50, node 55 is unbalanced, perform [[LR rotation]]. The resulting tree is  
![](https://liangcpp.pearsoncmg.com/checkpoint5e/IMAGE26_8.png)
### For the AVL tree in Figure 25.1a, show the new AVL tree after adding element 80. What [[rotation]] do you perform in order to rebalance the tree? Which node was unbalanced?
After inserting 80, node 67 is unbalanced, perform [[RL rotation]]. The resulting tree is  
![](https://liangcpp.pearsoncmg.com/checkpoint5e/IMAGE26_9.png)
### For the AVL tree in Figure 25.1a, show the new AVL tree after adding element 89. What [[rotation]] do you perform in order to rebalance the tree? Which node was unbalanced?
After inserting 89, node 67 is unbalanced, perform [[RR rotation]]. The resulting tree is  
![](https://liangcpp.pearsoncmg.com/checkpoint5e/IMAGE26_10.png)
# References
