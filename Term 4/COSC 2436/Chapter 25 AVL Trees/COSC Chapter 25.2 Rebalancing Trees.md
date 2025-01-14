# Summary

# Learning Objectives

# Related
Prev - [[COSC Chapter 25.1 Introduction]]

Next - [[COSC Chapter 25.3 Designing Classes for AVL Trees]]
# Content
## Key Point
After inserting or deleting an element from an AVL tree, if the tree becomes unbalanced, perform a [[rotation]] operation to rebalance the tree.

If a node is not balanced after an insertion or deletion operation, you need to rebalance it. The process of rebalancing a node is called a [[rotation]]. There are four possible rotations.

[[LL Rotation]]: An _LL imbalance_ occurs at a node `A` such that `A` has a [[balance factor]] `-2` and a left child `B` with a [[balance factor]] `-1` or `0`, as shown in **Figure 25.3a**. This type of imbalance can be fixed by performing a single right [[rotation]] at `A`, as shown in **Figure 25.3b**.

## Figure 25.3
![[92up1dy3.bmp]]

[[RR rotation]] : An _RR imbalance_ occurs at a node `A` such that `A` has a [[balance factor]] `+2` and a right child `B` with a [[balance factor]] `+1` or `0`, as shown in **Figure 25.4a**. This type of imbalance can be fixed by performing a single left [[rotation]] at `A`, as shown in **Figure 25.4b**.

## Figure 25.4
![[7m8jtekp.bmp]]5.4

[[LR rotation]]: An _LR imbalance_ occurs at a node `A` such that `A` has a [[balance factor]] `-2` and a left child `B` with a [[balance factor]] `+1`, as shown in **Figure 25.5a**. Assume B’s right child is `C`. This type of imbalance can be fixed by performing a double [[rotation]] at `A` (first a single left [[rotation]] at `B` and then a single right [[rotation]] at `A`), as shown in **Figure 25.5b**.

## Figure 25.5
![[jm8ldp80.bmp]]
[[RL rotation]]: An _RL imbalance_ occurs at a node `A` such that `A` has a [[balance factor]] `+2` and a right child `B` with a [[balance factor]] `-1`, as shown in **Figure 25.6a**. Assume `B`’s left child is `C`. This type of imbalance can be fixed by performing a double [[rotation]] at `A` (first a single right [[rotation]] at `B` and then a single left [[rotation]] at `A`), as shown in **Figure 25.6b**.

## Figure 25.6
![[cr9zuko6.bmp]]

## Self-Check
### What is an AVL tree? Describe the following terms: [[balance factor]], [[left-heavy]], and [[right-heavy]].
[[AVL trees]] are well-balanced. In an AVL tree, the difference between the heights of two subtrees for every node is 0 or 1.  
The [[balance factor]] of a node is the height of its right subtree minus the height of its left subtree. A node is said to be balanced if its [[balance factor]] is -1, 0, or 1. A node is said to be [[left-heavy]] if its [[balance factor]] is -1. A node is said to be [[right-heavy]] if its [[balance factor]] is +1.
### Show the [[balance factor]] of each node in the following trees.
![](https://liangcpp.pearsoncmg.com/checkpoint5e/IMAGE26_2.png)
### Describe [[LL rotation]], [[RR rotation]], [[LR rotation]], and [[RL rotation]] for an AVL tree.
If a node is not balanced after an insertion or deletion operation, you need to rebalance it. The process of rebalancing a node is called a [[rotation]]. There are four possible rotations: LL, LR, RR, and RL.  
An LL imbalance occurs at a node A such that A has a [[balance factor]] -2 and a left child B with a [[balance factor]] -1 or 0. This type of imbalance can be fixed by performing a single right [[rotation]] at A.
# References
