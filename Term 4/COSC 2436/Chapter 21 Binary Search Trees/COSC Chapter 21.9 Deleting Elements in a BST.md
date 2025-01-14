# Summary

# Related
Prev - [[COSC Chapter 21.8 The BST Class]]

Next - [[COSC Chapter 21.10 Iterators for BST]]
# Content
## Key Point
To delete an element from a BST, first locate it in the tree and then consider two cases—whether or not the node has a left child—before deleting the element and reconnecting the tree.

The `insert(element)` function was presented in **Section 21.2.4** to add an element to a binary tree. Often you need to delete an element from a binary tree. Deleting an element from a binary tree is far more complex than adding an element into a binary tree.

To delete an element from a binary tree, you need to first locate the node that contains the element and also its parent node. Let `current` point to the node that contains the element in the binary tree and `parent` point to the parent of the `current` node. The `current` node may be a left child or a right child of the `parent` node. Consider two cases:

Case 1: The current node does not have a left child, as shown in **Figure 21.9a**. Simply connect the parent with the right child of the current node, as shown in **Figure 21.9b**.

## Figure 21.9
![[z2m5pkif.bmp]]
For example, to delete node `10` in **Figure 21.10a**. Connect the parent of node `10` with the right child of node `10`, as shown in **Figure 21.10b**.

## Figure 21.10
![[gzsxu3ft.bmp]]

>[!Note]
If the current node is a leaf, it falls into Case 1. For example, to delete element `16` in **Figure 21.10a**, connect its right child to the parent of node `16`. In this case, the right child of node `16` is `nullptr`.

Case 2: The `current` node has a left child. Let `rightMost` point to the node that contains the largest element in the left subtree of the `current` node and `parentOfRightMost` point to the parent node of the `rightMost` node, as shown in **Figure 21.11a**. Note that the `rightMost` node cannot have a right child, but may have a left child. Replace the element value in the `current` node with the one in the `rightMost` node, connect the `parentOfRightMost` node with the left child of the `rightMost` node, and delete the `rightMost` node, as shown in **Figure 21.11b**.

## Figure 21.11
![[a4wbhxdk.bmp]]

For example, consider deleting node `20` in **Figure 21.12a**. The `rightMost` node has the element value `16`. Replace the element value `20` with `16` in the `current` node and make node `10` the parent for node `14`, as shown in **Figure 21.12b**.

## Figure 21.12
![[vwptd8xh.bmp]]

>[!Note]
If the left child of `current` does not have a right child, `current->left` points to the large element in the left subtree of `current`. In this case, `rightMost` is `current->left` and `parentOfRightMost` is `current`. You have to take care of this special case to reconnect the right child of `rightMost` with `parentOfRightMost`.

The algorithm for deleting an element from a binary tree is described in **Listing 21.3**.

## **Listing 21.3 Deleting an Element from a Binary Tree**
```cpp
bool remove(T e) 
{ 
  Locate element e in the tree; 
  if element e is not found 
    return false; 
 
  Let current be the node that contains e and parent be 
    the parent of current; 
 
  if (current has no left child) // Case 1 
    Connect the right child of 
    current with parent; now current is not referenced, so 
    it is eliminated; 
  else // Case 2 
    Locate the rightmost node in the left subtree of current. 
    Copy the element value in the rightmost node to current. 
    Connect the parent of the rightmost to the left child 
    of rightmost; Delete rightMost. 
 
  return true; // Element deleted successfully 
}  
```

You cannot name the function `delete` because `delete` is a C++ keyword.

The complete implementation of the `remove` function is given in lines 319–391 in **Listing 21.3**. The function locates the node (named `current`) to be deleted and also locates its parent (named `parent`) in lines 323–339. If `current` is `nullptr` (line 341), the element is not in the tree. So, the function returns `false` (line 342). Please note that if `current` is `root`, `parent` is `nullptr`. If the tree is empty, both `current` and `parent` are `nullptr`.

Case 1 of the algorithm is covered in lines 345–361. In this case, the `current` node has no left child (i.e., `current->left` is `nullptr`). If `parent` is `nullptr`, assign `current->right` to `root` (lines 348–351). Otherwise, assign `current->right` to `parent->left` or `parent->right`, depending on whether `current` is a left or right child of `parent` (353–358).

Case 2 of the algorithm is covered in lines 362–387. In this case, `current` has a left child. The algorithm locates the rightmost node (named `rightMost`) in the left subtree of the current node and also its parent (named `parentOfRightMost`) (lines 370–374). Replace the element in `current` by the element in `rightMost` (line 377); assign `rightMost->left` to `parentOfRightMost->right` or `parentOfRightMost->right` (lines 380–384), depending on whether `rightMost` is a right or left child of `parentOfRightMost`.

**LiveExample 21.3** is a test program that deletes the elements from the binary tree.

## **LiveExample 21.3 TestBSTDelete.cpp**
```cpp
#include <iostream>
#include <vector>
#include <string>
#include "BST.h"
using namespace std;

template <typename T>
void printTree(const BST<T>& tree)
{
  // Traverse tree
  cout << "Inorder (sorted): ";
  tree.inorder();
  cout << "\nPostorder: ";
  tree.postorder();
  cout << "\nPreorder: ";
  tree.preorder();
  cout << "\nThe number of nodes is " << tree.getSize() << endl;
}

int main()
{
  BST<string> tree;
  tree.insert("George");
  tree.insert("Michael");
  tree.insert("Tom");
  tree.insert("Adam");
  tree.insert("Jones");
  tree.insert("Peter");
  tree.insert("Daniel");
  printTree(tree);

  cout << "\nAfter delete George:";
  tree.remove("George"); // Delete George
  printTree(tree);

  cout << "\nAfter delete Adam:";
  tree.remove("Adam");
  printTree(tree);

  cout << "\nAfter delete Michael:";
  tree.remove("Michael");
  printTree(tree);

  return 0;
}
```
```
command>cl TestBSTDelete.cpp
Microsoft C++ Compiler 2019 
Compiled successful (cl is the VC++ compile/link command)

command>TestBSTDelete 
Inorder (sorted): Adam Daniel George Jones Michael Peter Tom 
Postorder: Daniel Adam Jones Peter Tom Michael George 
Preorder: George Adam Daniel Michael Jones Tom Peter 
The number of nodes is 7

After delete George:Inorder (sorted): Adam Daniel Jones Michael Peter Tom 
Postorder: Adam Jones Peter Tom Michael Daniel 
Preorder: Daniel Adam Michael Jones Tom Peter 
The number of nodes is 6

After delete Adam:Inorder (sorted): Daniel Jones Michael Peter Tom 
Postorder: Jones Peter Tom Michael Daniel 
Preorder: Daniel Michael Jones Tom Peter 
The number of nodes is 5

After delete Michael:Inorder (sorted): Daniel Jones Peter Tom 
Postorder: Peter Tom Jones Daniel 
Preorder: Daniel Jones Tom Peter 
The number of nodes is 4

command>
```

**Figures 21.13–21.15** show how the tree evolves as the elements are deleted from it.

## Figure 21.13
![[ginymomm.bmp]]

## Figure 21.14
![[ooiaidil.bmp]]

## Figure 21.15
![[j2q5r1xf.bmp]]

>[!Note]
It is obvious that the time complexity for the inorder, preorder, and postorder is _O(n)_, since each node is traversed only once. The time complexity for search, insertion and deletion is the height of the tree. In the worst case, the height of the tree is _O(n)_.

Consider the following scenarios:
1. What will happen if you forget to delete the discarded node? Your program will continue to run, but it will suffer memory leak.
2. Does the program work if the `rightMost` node is a leaf? Yes. In this case, `rightMost->left` is `nullptr`, which is assigned to `parentOfRightMost->right`.
## Self-Check
### Show the result of deleting 55 from the tree in Figure 21.4b.
![[Pasted image 20241202195011.png]]
### Show the result of deleting 60 from the tree in Figure 21.4b.
![[Pasted image 20241202195020.png]]
### What is the time complexity of deleting an element from a BST?
The time complexity of deleting an element from a binary tree is O(n).
### Is the algorithm correct if lines 254-257 in LiveExample 21.3 in Case 2 of the delete() function are replaced by the following code?
`parentOfRightMost->right = rightMost->left;`
No. Consider the case when current is parentOfRightMost and current.left is rightMost. You have to assign rightMost.left to parentOfRightMost.left.
# References
