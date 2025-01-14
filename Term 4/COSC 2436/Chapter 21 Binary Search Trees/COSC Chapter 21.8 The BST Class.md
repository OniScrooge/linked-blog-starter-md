# Summary

# Related
Prev - [[COSC Chapter 21.7 Tree Traversal]]

Next - [[COSC Chapter 21.9 Deleting Elements in a BST]]
# Content
## Key Point
The BST class defines a data structure for storing and manipulating data in a binary search tree.

Let us define a binary search tree class named `BST`, as shown in **Figure 21.7**. Its implementation is given in **LiveExample 21.1**. The implementation of search, insert, inorder traversal, postorder traversal, and preorder traversal are discussed in the preceding sections. The `remove` function will be discussed in **Section 21.3**. The iterators for traversing the elements in a binary tree will be discussed in **Section 21.4**.

## Figure 21.7
![[Pasted image 20241202193822.png]]

## **LiveExample 21.1 BST.h**
```cpp
#ifndef BST_H
#define BST_H

#include <vector>
#include <stdexcept>
using namespace std;

template<typename T>
class TreeNode
{
public:
  T element; // Element contained in the node
  TreeNode<T>* left; // Pointer to the left child
  TreeNode<T>* right; // Pointer to the right child

  TreeNode(const T& e) // Constructor
  {
    this->element = e;
    left = nullptr;
    right = nullptr;
  }
};

template <typename T>
class Iterator: public std::iterator<std::forward_iterator_tag, T>
{
public:
  Iterator(TreeNode<T>* p)
  {
    if (p == nullptr)
      current = -1; // The end
    else
    {
      // Get all the elements in inorder
      treeToVector(p);
      current = 0;
    }
  }

  Iterator operator++()
  {
    current++;
    if (current == v.size())
      current = -1; // The end
    return *this;
  }

  T &operator*()
  {
    return v[current];
  }

  bool operator==(const Iterator<T>& iterator) const
  {
    return current == iterator.current;
  }

  bool operator!=(const Iterator<T>& iterator) const
  {
    return current != iterator.current;
  }

private:
  int current;
  vector<T> v;
  void treeToVector(const TreeNode<T>* p)
  {
    if (p != nullptr)
    {
      treeToVector(p->left);
      v.push_back(p->element);
      treeToVector(p->right);
    }
  }
};

template <typename T>
class BST
{
public:
  BST(); // No-arg constructor
  BST(const T elements[], int arraySize);
  BST(const BST<T>& tree); // Copy constructor
  ~BST(); // Destructor
  bool search(const T& e) const;
  virtual bool insert(const T& e);
  virtual bool remove(const T& e);
  void inorder() const;
  void preorder() const;
  void postorder() const;
  int getSize() const;
  void clear();
  vector<TreeNode<T>*>* path(const T& e) const;

  Iterator<T> begin() const
  {
    return Iterator<T>(root);
  };

  Iterator<T> end() const
  {
    return Iterator<T>(nullptr);
  };

protected:
  TreeNode<T>* root;
  int size;
  virtual TreeNode<T>* createNewNode(const T& e);

private:
  void inorder(const TreeNode<T>* root) const;
  void postorder(const TreeNode<T>* root) const;
  void preorder(const TreeNode<T>* root) const;
  void copy(const TreeNode<T>* root);
  void clear(const TreeNode<T>* root);
};

template <typename T>
BST<T>::BST()
{
  root = nullptr;
  size = 0;
}

template <typename T>
BST<T>::BST(const T elements[], int arraySize)
{
  root = nullptr;
  size = 0;

  for (int i = 0; i < arraySize; i++)
  {
    insert(elements[i]);
  }
}

/* Copy constructor */
template <typename T>
BST<T>::BST(const BST<T>& tree)
{
  root = nullptr;
  size = 0;
  copy(tree.root); // Recursively copy nodes to this tree
}

/* Copies the element from the specified tree to this tree */
template <typename T>
void BST<T>::copy(const TreeNode<T>* root)
{
  if (root != nullptr)
  {
    insert(root->element);
    copy(root->left);
    copy(root->right);
  }
}

/* Destructor */
template <typename T>
BST<T>::~BST()
{
  clear();
}

/* Return true if the element is in the tree */
template <typename T>
bool BST<T>::search(const T& e) const
{
  TreeNode<T>* current = root; // Start from the root

  while (current != nullptr)
    if (e < current->element)
    {
      current = current->left; // Go left
    }
    else if (e > current->element)
    {
      current = current->right; // Go right
    }
    else // Element e matches current.element
      return true; // Element e is found

  return false; // Element e is not in the tree
}

template <typename T>
TreeNode<T>* BST<T>::createNewNode(const T& e)
{
  return new TreeNode<T>(e);
}

// Insert element e into the binary tree
// Return true if the element is inserted successfully
// Return false if the element is already in the list
template <typename T>
bool BST<T>::insert(const T& e)
{
  if (root == nullptr)
    root = createNewNode(e); // Create a new root
  else
  {
    // Locate the parent node
    TreeNode<T>* parent = nullptr;
    TreeNode<T>* current = root;
    while (current != nullptr)
      if (e < current->element)
      {
        parent = current;
        current = current->left;
      }
      else if (e > current->element)
      {
        parent = current;
        current = current->right;
      }
      else
        return false; // Duplicate node not inserted

    // Create the new node and attach it to the parent node
    if (e < parent->element)
      parent->left = createNewNode(e);
    else
      parent->right = createNewNode(e);
  }

  size++;
  return true; // Element inserted
}

/* Inorder traversal */
template <typename T>
void BST<T>::inorder() const
{
  inorder(root);
}

/* Inorder traversal from a subtree */
template <typename T>
void BST<T>::inorder(const TreeNode<T>* root) const
{
  if (root == nullptr) return;
  inorder(root->left);
  cout << root->element << " ";
  inorder(root->right);
}

/* Postorder traversal */
template <typename T>
void BST<T>::postorder() const
{
  postorder(root);
}

/** Inorder traversal from a subtree */
template <typename T>
void BST<T>::postorder(const TreeNode<T>* root) const
{
  if (root == nullptr) return;
  postorder(root->left);
  postorder(root->right);
  cout << root->element << " ";
}

/* Preorder traversal */
template <typename T>
void BST<T>::preorder() const
{
  preorder(root);
}

/* Preorder traversal from a subtree */
template <typename T>
void BST<T>::preorder(const TreeNode<T>* root) const
{
  if (root == nullptr) return;
  cout << root->element << " ";
  preorder(root->left);
  preorder(root->right);
}

/* Get the number of nodes in the tree */
template <typename T>
int BST<T>::getSize() const
{
  return size;
}

/* Remove all nodes from the tree */
template <typename T>
void BST<T>::clear()
{
  // Left as exercise
}

/* Return a path from the root leading to the specified element */
template <typename T>
vector<TreeNode<T>*>* BST<T>::path(const T& e) const
{
  vector<TreeNode<T>*>* v = new vector<TreeNode<T>*>();
  TreeNode<T>* current = root;

  while (current != nullptr)
  {
    v->push_back(current);
    if (e < current->element)
      current = current->left;
    else if (e > current->element)
      current = current->right;
    else
      break;
  }

  return v;
}

/* Delete an element e from the binary tree.
 * Return true if the element is deleted successfully
 * Return false if the element is not in the tree */
template <typename T>
bool BST<T>::remove(const T& e)
{
  // Locate the node to be deleted and also locate its parent node
  TreeNode<T>* parent = nullptr;
  TreeNode<T>* current = root;
  while (current != nullptr)
  {
    if (e < current->element)
    {
      parent = current;
      current = current->left;
    }
    else if (e > current->element)
    {
      parent = current;
      current = current->right;
    }
    else
      break; // Element e is in the tree pointed by current
  }

  if (current == nullptr)
    return false; // Element e is not in the tree

  // Case 1: current has no left children
  if (current->left == nullptr)
  {
    // Connect the parent with the right child of the current node
    if (parent == nullptr)
    {
      root = current->right;
    }
    else
    {
      if (e < parent->element)
        parent->left = current->right;
      else
        parent->right = current->right;
    }

    delete current; // Delete current
  }
  else
  {
    // Case 2: The current node has a left child
    // Locate the rightmost node in the left subtree of
    // the current node and also its parent
    TreeNode<T>* parentOfRightMost = current;
    TreeNode<T>* rightMost = current->left;

    while (rightMost->right != nullptr)
    {
      parentOfRightMost = rightMost;
      rightMost = rightMost->right; // Keep going to the right
    }

    // Replace the element in current by the element in rightMost
    current->element = rightMost->element;

    // Eliminate rightmost node
    if (parentOfRightMost->right == rightMost)
      parentOfRightMost->right = rightMost->left;
    else
      // Special case: parentOfRightMost->right == current
      parentOfRightMost->left = rightMost->left;

    delete rightMost; // Delete rightMost
  }

  size--;
  return true; // Element inserted
}

#endif
```

A binary tree contains nodes defined in the `TreeNode` class (lines 8–22). You can obtain iterators for traversing the elements in a binary tree. The `Iterator` class (lines 24–75) will be discussed in §21.4.

The header of the `BST` class is defined in lines 77–116. Five private functions are defined in lines 110–115. These are supporting functions, which are used only for implementing the public functions. The data fields `root` and `size` (lines 106–107) are declared protected so they can be directly accessed from the child classes. Later, in **Chapter 25**, we will define the `AVLTree` class, which is derived from `BST`. The `createNewNode` function creates a new node (line 108). The function is defined virtual, because it will be redefined in the `AVLTree` class to create a new type of node. The `insert` and `remove` functions (lines 86–87) are also defined `virtual`, because they will be redefined the `AVLTree` class, so that they can be invoked dynamically for different types of trees.

## Design Pattern Note: factory function pattern

The design for the `createNewNode()` function applies the factory function pattern, which creates an object returned from the function rather than directly using the constructor in the code to create the object. Suppose the factory function returns an object of the type `A`. This design enables you to override the function to create an object of the subtype of `A`. The `createNewNode()` function in the `BST` class returns a `TreeNode` object. Later in later chapters, we will override this function to return an object of the subtype of `TreeNode`.

The no-arg constructor (lines 118–123) constructs an empty binary tree with `root` `nullptr` and `size` `0`. The constructor (lines 125–135) constructs a binary tree initialized with the elements in the array.

The copy constructor (lines 138–144) creates a new binary tree by copying the contents from an existing tree. This is done by recursively inserting the elements from the existing tree to the new tree using the copy function (lines 147–156).

The destructor (lines 159–1631) removes all nodes from the tree.

The `search(T element)` function (lines 166–184) searches an element in the BST. It returns `true` (line 181) if an element is found, otherwise, it returns `false` (line 183).

The `insert(T element)` function (lines 195–228) creates a node for element and inserts it into the tree. If the tree is empty, the node becomes the root (line 199). Otherwise, the function finds an appropriate parent for the node to maintain the order of the tree. If the element is already in the tree, the function returns `false` (line 217); otherwise it returns `true` (line 227).

The `inorder()` function (lines 231–235) invokes `inorder(root)` to traverse the entire tree. The function `inorder(TreeNode root)` traverses the tree with the specified root. This is a recursive function. It recursively traverses the left subtree, then the root, and finally the right subtree. The traversal ends when the tree is empty.

The `postorder()` function (lines 248–252) and the `preorder()` function (lines 265–269) are implemented similarly using recursion.

The `path(T element)` function (lines 296–314) finds a path of nodes from the root leading to the node that contains the element, or the parent node under which the element will be inserted.

**LiveExample 21.2** gives an example that uses some of the functions in BST.

## **LiveExample 21.2 TestBST.cpp**
```cpp
#include <iostream>
#include <vector>
#include <string>
#include "BST.h"
using namespace std;

int main()
{
  BST<string> tree;
  tree.insert("George");
  tree.insert("Michael");
  tree.insert("Tom");
  tree.insert("Adam");
  tree.insert("Jones");
  tree.insert("Peter"); // Insert Peter
  tree.insert("Daniel");

  cout << "Inorder (sorted): ";
  tree.inorder();

  cout << "\nPostorder: ";
  tree.postorder();

  cout << "\nPreorder: ";
  tree.preorder();

  cout << "\nThe number of nodes is " << tree.getSize() << endl;
  cout << "search(\"Jones\") " << tree.search("Jones") << endl;
  cout << "search(\"John\") " << tree.search("John") << endl;

  cout << "A path from the root to Peter is: ";
  vector<TreeNode<string>*>* v = tree.path("Peter");
  for (unsigned i = 0; i < (*v).size(); i++)
    cout << (*v)[i]->element << " ";

  int numbers[] = {2, 4, 3, 1, 8, 5, 6, 7};
  BST<int> intTree(numbers, 8);
  cout << "\nInorder (sorted): ";
  intTree.inorder();

  return 0;
}
```
```
command>cl TestBST.cpp
Microsoft C++ Compiler 2019 
Compiled successful (cl is the VC++ compile/link command)

command>TestBST 
Inorder (sorted): Adam Daniel George Jones Michael Peter Tom 
Postorder: Daniel Adam Jones Peter Tom Michael George 
Preorder: George Adam Daniel Michael Jones Tom Peter 
The number of nodes is 7
search("Jones") 1
search("John") 0
A path from the root to Peter is: George Michael Tom Peter 
Inorder (sorted): 1 2 3 4 5 6 7 8 

command>
```

The program creates a binary tree for strings using `BST``<``string``>` (line 9). The program adds strings into the binary tree (lines 10–16) and displays the elements in inorder (line 19), postorder (line 22), and preorder (line 25). The `getSize` and `search` functions are invoked in lines 27–29. Lines 31–34 display a path from the root to `Peter`.

The program creates a binary tree for integers from an array of integers (line 36) and displays the numbers in increasing order (line 39).

After all the string elements are inserted, `tree` should appear as shown in **Figure 21.8a**. Tree `intTree` is created as shown in **Figure 21.8b**.

## Figure 21.8
![[l48gimzi.bmp]]
![[txc166g6.bmp]]

If the elements are inserted in a different order, the tree will look different. However, the inorder traversal prints elements in the same order as long as the set of elements is the same. The inorder traversal displays a sorted list.

## Self-Check
### What is wrong if the root and size are not initialized in the following constructor for BST?
```cpp
template<typename T>
BST<T>::BST(T elements[], int arraySize)
{
  root = nullptr;
  size = 0;
  for (int i = 0; i < arraySize; i++)
  {
    insert(elements[i]);
  }
}
```

The data fields must be initialized explicitly. Otherwise, their values are unpredictable.
### The assignment operator should be implemented in the BST class along with the copy constructor and destructor. Implement the assignment operator.
```cpp
template<typename T>
BST& BST<T>::operator=(const BST<T>& tree)
{
  clear();
  root = nullptr;
  size = 0;
  copy(tree.root); // Recursively copy nodes to this tree
}
```
# References
