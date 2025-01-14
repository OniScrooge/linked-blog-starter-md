# Related
Prev - [[COSC Chapter 21.11 Case Study - Data Compression]]

Next - 
# Key Terms
1. **binary search tree**
2. **binary tree**
3. **inorder traversal**
4. **postorder traversal**
5. **preorder traversal**
6. **tree traversal**
# Chapter Summary
1. A binary tree can be implemented using linked nodes. Each node contains the element value and two pointers that point to the left and right children.
2. Tree traversal is the process of visiting each node in the tree exactly once in a certain order. There are several ways to traverse a tree.
3. With inorder traversal, the left subtree of the current node is visited recursively first, then the current node, and finally the right subtree of the current node. The inorder traversal displays all the nodes in a binary search tree in increasing order.
4. With postorder traversal, the left subtree of the current node is visited recursively first, then the right subtree of the current node, and finally the current node itself.
5. With preorder traversal, the current node is visited recursively first, then the left subtree of the current node, and finally the right subtree of the current node. Depth-first traversal is the same as preorder traversal.
6. With breadth-first traversal, the nodes are visited level by level. First the root is visited, then all the children of the root from left to right, then the grandchildren of the root from left to right, and so on.
7. To search for an element in a BST, you start from the root and compare the element with the root. If the element is less than the root, search the left subtree. If the element is greater than the root, search the right subtree. If the element is equal to the root, a match is found. Continue the process until a match is found or search is exhausted.
8. To insert an element into a BST, perform a search. If the element is already in the tree, insertion cannot be done. Otherwise search until you reach to a leaf node and create a new node for the element. The new node is a left or a right child of the leaf node.
9. To delete an element from a BST, perform a search to locate the element and consider two cases to remove and reorganize the tree.
10. You can define an iterator for traversing the elements in a binary tree.