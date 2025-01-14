# Summary

# Related
Prev - [[COSC Chapter 21.6 Inserting an Element into a BST]]

Next - [[COSC Chapter 21.8 The BST Class]]
# Content
## Key Point

[[Inorder]], [[preorder]], [[postorder]], depth-first, and breadth-first are the common ways to traverse the elements in a [[binary tree]].

[[Tree traversal]] is the process of visiting each node in the tree exactly once. There are several ways to traverse a tree. This section presents [[inorder]], [[preorder]], [[postorder]], _depth-first_, and _breadth-first_ traversals.

With [[inorder]] traversal, the left subtree of the current node is recursively visited first, then the current node, and finally the right subtree of the current node. The [[inorder]] traversal displays all the nodes in a BST in increasing order, as shown in **Figure 21.5a**.

With [[postorder]] traversal, the left subtree of the current node is visited recursively first, then the right subtree of the current node, and finally the current node itself, as shown in **Figure 21.5b**.

With [[preorder]] traversal, the current node is visited recursively first, then the left subtree of the current node, and finally the right subtree of the current node. Depth-first traversal is the same as [[preorder]] traversal, as shown in **Figure 21.5c**.

>[!Note]
You can reconstruct a [[binary search tree]] by inserting the elements in their [[preorder]]. The reconstructed tree preserves the parent and child relationship for the nodes in the original [[binary search tree]].

Depth-first traversal is to visit the root, then recursively visit its left subtree and right subtree in an arbitrary order. The [[preorder]] traversal can be viewed as a special case of depth-first traversal, which recursively visit its left subtree and then its right subtree, as shown in **Figure 21.5d**. With breadth-first traversal, the nodes are visited level by level. First the root is visited, then all the children of the root from left to right, then the grandchildren of the root from left to right, and so on, as shown in **Figure 21.5e**.

## Figure 21.5
![[Pasted image 20241202193424.png]]
![[Pasted image 20241202193431.png]]
![[Pasted image 20241202193438.png]]
![[Pasted image 20241202193448.png]]
![[Pasted image 20241202193456.png]]

You can use the following simple tree in **Figure 21.6** to help remember [[inorder]], [[postorder]], and [[preorder]].

## Figure 21.6
![[Pasted image 20241202193526.png]]

The [[inorder]] is `1 + 2`, the [[postorder]] is `1 2 +`, and the [[preorder]] is `+ 1 2`.

## Self-Check
### Show the [[inorder]], [[preorder]], and [[postorder]] of traversing the elements in the [[binary tree]] shown in Figure 21.1c.
[[Inorder]]: A F G M R T  
[[Preorder]]: G F A R M T  
[[Postorder]]: A F M T R G
### If a set of elements is inserted into a BST in two different orders, will the two corresponding BSTs look the same? Will the [[inorder]] traversal be the same? Will the [[postorder]] traversal be the same? Will the [[preorder]] traversal be the same?
- If a set of the same elements is inserted into a [[binary tree]] in two different orders, will the two corresponding binary trees look the same? No.
- Will the [[inorder]] traversal be the same? Yes.
- Will the [[postorder]] traversal be the same? No.
- Will the [[preorder]] traversal be the same? No.
# References
