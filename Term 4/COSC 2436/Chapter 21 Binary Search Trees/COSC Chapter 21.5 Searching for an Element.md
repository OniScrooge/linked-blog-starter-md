# Summary

# Related
Prev - [[COSC Chapter 21.4 Accessing Nodes in Binary Trees]]

Next - [[COSC Chapter 21.6 Inserting an Element into a BST]]
# Content
## Key Point
BST enables an efficient search that resembles a binary search.

To search for an element in a BST, you start from the root and scan down from the root until a match is found or you arrive at an empty subtree. The algorithm is described in **Listing 21.1**. Let `current` point to the root (line 4). Repeat the following steps until current is `nullptr` (line 6) or the element matches `current->element` (line 16).
- If `element` is less than `current->element`, assign `current->left` to `current` (line 9).
- If `element` is greater than `current->element`, assign `current->right` to `current` (line 13).
- If `element` is equal to `current->element`, return `true` (line 16).

If the `current` is `nullptr`, the subtree is empty and the element is not in the tree (line 18).

## **Listing 21.1 Searching for an Element in a BST**
![[Pasted image 20241202192652.png]]
## Self-Check
### Implement the search(element) function using recursion.
```cpp
/** Returns true if the element is in the tree */
bool search(E e) 
{
  return search(root, e);
}

bool search(TreeNode<T>* root, E e) 
{
  if (root == nullptr) 
    return false;
  else if (e < root.element) 
    return search(root.left, e);
  else if (e > root.element) 
    return search(root.right, e);
  else
    return true;
}
```
The time complexity is $O(n)$.

# References