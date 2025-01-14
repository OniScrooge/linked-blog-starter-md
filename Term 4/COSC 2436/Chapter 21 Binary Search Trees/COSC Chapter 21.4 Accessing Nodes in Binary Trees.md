# Summary

# Related
Prev - [[COSC Chapter 21.3 Representing Binary Search Trees]]

Next - [[COSC Chapter 21.5 Searching for an Element]]
# Content
## Key Point

You can access the binary search tree starting from the root.

Suppose a tree with three nodes is created as in the preceding section. You can access the nodes in the tree through the `root` pointer. Here are the statements to display the elements at the root and its left and right nodes.

```cpp
// Display the root element 
cout << root->element << endl; 
 
// Display the element in the left child of the root 
cout << (root->left)->element << endl; 
 
// Display the element in the right child of the root 
cout << (root->right)->element << endl; 
```

## Self-Check
### Write the code that displays the root's left child's left child's element.
```cpp
cout << ((root->left)->left)->element << endl;
```
# References