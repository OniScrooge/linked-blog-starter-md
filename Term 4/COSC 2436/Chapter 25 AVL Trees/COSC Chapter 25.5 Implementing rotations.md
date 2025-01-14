# Summary

# Learning Objectives

# Related
Prev - [[COSC Chapter 25.4 Overriding the insert function]]

Next - [[COSC Chapter 25.6 Implementing the remove function]]
# Content
## Key Point

An unbalanced tree becomes balanced by performing an appropriate [[rotation]] operation.

**Section 25.2**, “Rebalancing Tree,” illustrated how to perform rotations at a node. **Listing 25.2** gives the algorithm for the [[LL rotation]], as pictured in **Figure 25.3**.

## **Listing 25.2 [[LL Rotation]] Algorithm**
```cpp
void balanceLL(TreeNode* A, TreeNode* parentOfA) 
{ 
  Let B be the left child of A; 
  
  if (A is the root) 
    Let B be the new root; 
  else 
  { 
    if (A is a left child of parentOfA) 
      Let B be a left child of parentOfA; 
    else 
      Let B be a right child of parentOfA; 
  } 
  
  Make T2 the left subtree of A by assigning B.right to A.left; 
  Make A the right child of B by assigning A to B.right; 
  Update the height of node A and node B; 
} // End of function 
```

Note that the height of nodes `A` and `B` may be changed, but the heights of other nodes in the tree are not changed. Similarly, you can implement the [[RR rotation]], [[LR rotation]], and [[RL rotation]].

## Self-Check
### Use Listing 25.2 as a template to describe the algorithm for implementing the [[RR rotation]].
Here is the algorithm for the [[RR rotation]].

[[RR Rotation]] Algorithm
```cpp
   void balanceRR(TreeNode* A, TreeNode* parentOfA)
   {
     Let B be the right child of A;
           
     if (A is the root) 
       Let B be the new root;
     else 
     {
       if (A is a left child of parentOfA)
         Let B be a left child of parentOfA;
       else
         Let B be a right child of parentOfA;
     }
  
     Make T2 the right subtree of A by assigning B.left to A.right; 
     Make A the left child of B by assigning A to B.left;
          
     Update the height of node A and node B; 
   } // End of method
```
### Use Listing 25.2 as a template to describe the algorithm for implementing the [[LR rotation]].
Here is the algorithm for the [[LR rotation]].

[[LR Rotation]] Algorithm
```cpp
   void balanceLR(TreeNode* A, TreeNode* parentOfA)
   {
     Let B be the left child of A;
     Let C be the right child of B;
           
     if (A is the root) 
       Let C be the new root;
     else {
       if (A is a left child of parentOfA)
         Let C be a left child of parentOfA;
       else
         Let C be a right child of parentOfA;
     }
  
     Make T3 the left subtree of A by assigning C.right to A.left; 
     Make T2 the right subtree of B by assigning C.left to B.right; 
     Make B the left child of C by assigning B to C.left;
     Make A the right child of C by assigning A to C.right;
          
     Update the height of node A, node B, and node C; 
   } // End of method
```
### Use Listing 25.2 as a template to describe the algorithm for implementing the [[RL rotation]].
Here is the algorithm for the [[RL rotation]].

[[RL Rotation]] Algorithm
```cpp
void balanceRL(TreeNode* A, TreeNode* parentOfA)
   {
     Let B be the right child of A;
     Let C be the left child of B;
           
     if (A is the root) 
       Let C be the new root;
     else 
     {
       if (A is a left child of parentOfA)
         Let C be a left child of parentOfA;
       else
         Let C be a right child of parentOfA;
     }
  
     Make T3 the left subtree of B by assigning C.right to B.left; 
     Make T2 the right subtree of A by assigning C.left to A.right; 
     Make B the right child of C by assigning B to C.right;
     Make A the left child of C by assigning A to C.left;
          
     Update the height of node A, node B, and node C; 
   } // End of method
```
# References
