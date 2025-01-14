# Summary

# Related
Prev - [[COSC Chapter 21.2 Binary Search Trees Basics]]

Next - [[COSC Chapter 21.4 Accessing Nodes in Binary Trees]]
# Content
## Key Point
A binary tree can be implemented using a linked structure.

A binary tree can be represented using a set of linked nodes. Each node contains a value and two links named _left_ and _right_ that reference the left child and right child, respectively, as shown in **Figure 21.3**.
## Figure 21.3
![[Pasted image 20241202191717.png]]

A node can be defined as a class, as follows:
```cpp
template<typename T> 
class TreeNode 
{ 
public: 
  T element; // Element contained in the node 
  TreeNode<T>* left; // Pointer to the left child 
  TreeNode<T>* right; // Pointer to the right child 
 
  TreeNode(T element) // Constructor 
  { 
    this->element = element; 
    left = nullptr; 
    right = nullptr; 
  } 
}; 
 
```

We use the variable `root` refers to the root node of the tree. If the tree is empty, `root` is `nullptr`. The following code creates the first three nodes of the tree in **Figure 21.1**:

```cpp
// Create the root node 
TreeNode<int>* root = new TreeNode<int>(60); 
 
// Create the left child node 
root->left = new TreeNode<int>(55); 
 
// Create the right child node 
root->right = new TreeNode<int>(100); 
```

## Self-Check
### When a new TreeNode is created, what is the value for it's left and right?

Both left and right are nullptr.
# References