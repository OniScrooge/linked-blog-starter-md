# Summary

# Related
Prev - [[COSC Chapter 21.9 Deleting Elements in a BST]]

Next - [[COSC Chapter 21.11 Case Study - Data Compression]]
# Content
## Key Point

You can use iterators to traverse a binary tree.

**Section 20.5** introduced iterators and defined an `Iterator` class for `LinkedList`. Iterators are very useful to provide a uniformed way for traversing the elements in a container. Every iterator class has the same pattern, so they are very similar. This section defines an `Iterator` class for traversing the elements in `BST`, as shown in **Figure 21.16**.

## Figure 21.16
![[Pasted image 20241202195213.png]]

This class is implemented in lines 24–75 in **LiveExample 21.3**. For convenience, the constructors and functions are implemented as inline functions.

The `Iterator` class has two data fields, `vector` and `current`. The data field `vector` (line 65) is used as an auxiliary storage for the elements in the binary tree. The data field `current` points to the current element in vector (line 64).

The constructor (lines 28–38) creates an iterator. Invoking the `treeToVector(p)` function (line 35) stores all the elements in the tree rooted at `p` into the `vector` (lines 66–74). The data field current points to the `current` element in the vector. Initially, it is set to `0` (line 36).

The `operator++()` function moves `current` to point to the next element in the vector (line 42). `current` is set to `-1` if the pointer is moved past the last element in the vector (line 44).

To obtain iterators from a `BST`, the following two functions are defined and implemented in lines 95–103 in **LiveExample 21.3**.

```cpp
Iterator<T> begin() const; 
Iterator<T> end() const; 
```

The `begin()` function returns the iterator for the first element to be traversed and the `end()` function returns the iterator that pasts the last element in the list.

**LiveExample 21.4** gives an example that uses iterators to traverse the string elements in a tree and displays the strings in uppercase. The program creates a `BST` for strings in line 18, adds four strings to the list (lines 21–24), and traverses all the elements in the list using iterators and displays them in uppercase (lines 27–31).

## **LiveExample 21.4 TestBSTIterator.cpp**
```cpp
#include <iostream>
#include <string>
#include <algorithm>
#include "BST.h"
using namespace std;

string toUpperCase(string& s)
{
  for (int i = 0; i < s.length(); i++)
    s[i] = toupper(s[i]);

  return s;
}

int main()
{
  // Create a binary search tree for strings
  BST<string> tree;

  // Add elements to the tree
  tree.insert("America");
  tree.insert("Canada");
  tree.insert("Russia");
  tree.insert("France");

  // Traverse a binary tree using iterators
  for (Iterator<string> iterator = tree.begin();
    iterator != tree.end(); ++iterator)
  {
    cout << toUpperCase(*iterator) << " ";
  }

  cout << endl << "Min element is " <<
    *min_element(tree.begin(), tree.end()) << endl;
  cout << "Max element is " 
    << *max_element(tree.begin(), tree.end()) << endl;

  return 0;
}
```
```
command>cl TestBSTIterator.cpp
Microsoft C++ Compiler 2019 
Compiled successful (cl is the VC++ compile/link command)

command>TestBSTIterator 
AMERICA CANADA FRANCE RUSSIA 
Min element is America
Max element is Russia

command>
```
## Self-Check
### Rewrite the loop in LiveExample 21.7 using a foreach loop.
```cpp
for (string s: tree)
{
  cout << toUpperCase(s) << " ";
}
```

### Note that Iterator class in BST.h is defined as a subtype of the standard iterator in the C++ library as follows:
class Iterator: public std::iterator<std::forward_iterator_tag, T>

What happens if Iterator is not defined as a subtrype of std::iterator?  
#### Answer
The STL algorithms rely on the std::iterator class. If Iterator is not a subtype of std::iterator, the max_element and min_element will not work.
# References
