# Summary

# Learning Objectives

# Related
Prev - [[COSC Chapter 25.7 The AVL Tree class]]

Next - [[COSC Chapter 25.9 AVL Tree time complexity analysis]]
# Content
## Key Point
This section gives an example of using the `AVLTree` class.

**LiveExample 25.2** gives a test program. The program creates an `AVLTree` initialized with an array of integers `25`, `20`, and `5` (lines 22–23), inserts elements in lines 28–39, and deletes elements in lines 41–49.

## **LiveExample 25.2 TestAVLTree.cpp**
```cpp
#include <iostream>
#include "AVLTree.h"
using namespace std;

template <typename T>
void printTree(const AVLTree<T>& tree)
{
  // Traverse tree
  cout << "\nInorder (sorted): " << endl;
  tree.inorder();
  cout << "\nPostorder: " << endl;
  tree.postorder();
  cout << "\nPreorder: " << endl;
  tree.preorder();
  cout << "\nThe number of nodes is " << tree.getSize();
  cout << endl;
}

int main()
{
  // Create an AVL tree
  int numbers[] = {25, 20, 5};
  AVLTree<int> tree(numbers, 3);

  cout << "After inserting 25, 20, 5:" << endl;
  printTree<int>(tree);

  tree.insert(34);
  tree.insert(50); // Insert 50 to tree
  cout << "\nAfter inserting 34, 50:" << endl;
  printTree<int>(tree);

  tree.insert(30);
  cout << "\nAfter inserting 30" << endl;
  printTree<int>(tree);

  tree.insert(10);
  cout << "\nAfter inserting 10" << endl;
  printTree(tree);

  tree.remove(34);
  tree.remove(30);
  tree.remove(50);
  cout << "\nAfter removing 34, 30, 50:" << endl;
  printTree<int>(tree);

  tree.remove(5); // Delete 5 from tree
  cout << "\nAfter removing 5:" << endl;
  printTree<int>(tree);

  return 0;
}
```
```
command>cl TestAVLTree.cpp
Microsoft C++ Compiler 2019 
Compiled successful (cl is the VC++ compile/link command)

command>TestAVLTree 
After inserting 25, 20, 5:

Inorder (sorted): 
5 20 25 
Postorder: 
5 25 20 
Preorder: 
20 5 25 
The number of nodes is 3

After inserting 34, 50:

Inorder (sorted): 
5 20 25 34 50 
Postorder: 
5 25 50 34 20 
Preorder: 
20 5 34 25 50 
The number of nodes is 5

After inserting 30

Inorder (sorted): 
5 20 25 30 34 50 
Postorder: 
5 20 30 50 34 25 
Preorder: 
25 20 5 34 30 50 
The number of nodes is 6

After inserting 10

Inorder (sorted): 
5 10 20 25 30 34 50 
Postorder: 
5 20 10 30 50 34 25 
Preorder: 
25 10 5 20 34 30 50 
The number of nodes is 7

After removing 34, 30, 50:

Inorder (sorted): 
5 10 20 25 
Postorder: 
5 20 25 10 
Preorder: 
10 5 25 20 
The number of nodes is 4

After removing 5:

Inorder (sorted): 
10 20 25 
Postorder: 
10 25 20 
Preorder: 
20 10 25 
The number of nodes is 3

command>
```

**Figure 25.10** shows how the tree evolves as elements are added to it. After `25` and `20` are added, the tree is as shown in **Figure 25.10a**. `5` is inserted as a left child of `20`, as shown in **Figure 25.10b**. The tree is not balanced. It is [[left-heavy]] at node `25`. Perform an [[LL rotation]] to produce an AVL tree, as shown in **Figure 25.10c**.

After inserting `34`, the tree is as shown in **Figure 25.10d**. After inserting `50`, the tree is as shown in **Figure 25.10e**. The tree is not balanced. It is [[right-heavy]] at node `25`. Perform an [[RR rotation]] to produce an AVL tree, as shown in **Figure 25.10f**.

After inserting `30`, the tree is as shown in **Figure 25.10g**. The tree is not balanced. Perform an [[RL rotation]] to produce an AVL tree, as shown in **Figure 25.10h**.

After inserting `10`, the tree is as shown in **​Figure​ ​25.10i​**. The tree is not balanced. Perform an [[LR rotation]] to produce an AVL tree, as shown in **​Figure​ ​25.10j**​.

## Figure 25.10
![[ac273wxc.bmp]]

**Figure 25.11** shows how the tree evolves as elements are deleted. After deletion of `34`, `30`, and `50`, the tree is as shown in **Figure 25.11b**. The tree is not balanced. Perform an [[LL rotation]] to produce an AVL tree, as shown in **Figure 25.11c**.

After deleting `5`, the tree is as shown in ​**Figure​ ​25.11d**​. The tree is not balanced. Perform an [[RL rotation]] to produce an AVL tree, as shown in ​**Figure​ ​25.11e**​.

## Figure 25.11
![[thlbib37.bmp]]

## Self-Check
### Show the change of an AVL tree when inserting 1, 2, 3, 4, 10, 9, 7, 5, 8, 6 into the tree, in this order.
![](https://liangcpp.pearsoncmg.com/checkpoint5e/IMAGE26_19.png)
### For the tree built in the preceding question, show its change after 1, 2, 3, 4, 10, 9, 7, 5, 8, 6 are deleted from the tree in this order.
![](https://liangcpp.pearsoncmg.com/checkpoint5e/IMAGE26_2.png)0
### Can you traverse the elements in an AVL tree using a foreach loop?
Yes.
# References
