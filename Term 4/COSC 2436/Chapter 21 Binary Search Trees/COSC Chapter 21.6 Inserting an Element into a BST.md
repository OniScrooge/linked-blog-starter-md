# Summary

# Related
Prev - [[COSC Chapter 21.5 Searching for an Element]]

Next - [[COSC Chapter 21.7 Tree Traversal]]
# Content
## Key Point

The new element is inserted as a leaf node.

To insert an element into a BST, you need to locate where to insert it. The key idea is to locate the parent for the new node. **Listing 21.2** gives the algorithm.

## **Listing 21.2 Inserting an Element into a BST**
![[Pasted image 20241202193007.png]]

If the tree is empty, create a root node with the new element (lines 4–5). Otherwise, locate the parent node for the new element node (lines 9–22). Create a new node for the element and link this node to its parent node (lines 25–28). If the new element is less than the parent element, the node for the new element will be the left child of the parent (line 26). If the new element is greater than the parent element, the node for the new element will be the right child of the parent (line 28).

For example, to insert `101` into the tree in **Figure 21.3**, after the `while` loop finishes in the algorithm, `parent` points to the node for `107`, as shown in **Figure 21.4a**. The new node for `101` becomes the left child of the parent. To insert `59` into the tree, after the `while` finishes in the algorithm, the parent points to the node for `57`, as shown in **Figure 21.4b**. The new node for `59` becomes the right child of the parent.

## Figure 21.4
![[Pasted image 20241202193049.png]]
![[Pasted image 20241202193056.png]]
![[Pasted image 20241202193103.png]]
## Self-Check
### Show the result of inserting 44 into Figure 21.4b.
![[Pasted image 20241202193211.png]]
### What is the time complexity of inserting an element into a BST?
The time complexity of inserting an element to a binary tree is O(n).
# References
