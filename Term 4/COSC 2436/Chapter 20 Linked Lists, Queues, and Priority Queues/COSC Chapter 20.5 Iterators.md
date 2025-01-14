
# Summary

# Related
Prev - [[COSC Chapter 20.4.8 The time complexity of LinkedList]]

Next - [[COSC Chapter 20.6 Foreach Loop]]
# Content
## Key Point

Iterators are objects that provide a uniform way for traversing elements in various types of containers. 

Iterator is an important notion in C++. The Standard Template Library (STL) uses iterators to access the elements in the containers. The STL will be introduced in **Chapters 22** and **23**. The present section defines an iterator class and creates an iterator object for traversing the elements in a linked list. The objectives here are twofold: (1) to look at an example of how to define an iterator class; (2) to become familiar with iterators and how to use them to traverse the elements in a container.

Iterators can be viewed as encapsulated pointers. In a linked list, you can use pointers to traverse the list. But iterators have more functions than pointers. Iterators are objects. Iterators contain functions for accessing and manipulating elements. An iterator typically contains the overloaded operators, as shown in **Table 20.2**.

#### **Table 20.2** **Typical Overloaded Operators in an Iterator**

|   |   |
|---|---|
|**Operator**|**Description**|
|`++`|Advances the iterator to the next element.|
|`*`|Accesses the element pointed by the iterator.|
|`==`|Tests whether two iterators point to the same element.|
|`!=`|Tests whether two iterators point to different elements.|

The `Iterator` class for traversing the elements in a linked list is defined in **Figure 20.13**.
## Figure 20.13
![[Pasted image 20241130141153.png]]

This class is implemented in lines 25–64 in **Listing 20.2**. Since constructors and functions are short, they are implemented as inline functions. The `Iterator` class uses the data field `current` to point to the node being traversed (line 63). The constructor (lines 29–32) creates an iterator that points to a specified node. Both the prefix and postfix forms of the increment operators are implemented (lines 34–45) to move `current` to point to the next node in the list (lines 36, 43). Note that the postfix increment operator increments the iterator (line 43), but returns the original iterator (lines 42, 44). The `*` operator returns the element pointed at the iterator (line 49). The `==` operator tests whether the current iterator is the same as another iterator (line 54).

An iterator is used in conjunction with a container object that actually stores the elements. The container class should provide the `begin()` and `end()` functions for returning iterators, as shown in **Table 20.3**.

#### Table 20.3 

#### **Common Functions for Returning Iterators**

|   |   |
|---|---|
|**Operator**|**Description**|
|`begin()`|Returns an iterator that points to the first element in the container.|
|`end()`|Returns an iterator that represents a position past the last element in the container. This iterator can be used to test whether all elements in the container have been traversed.|

To obtain iterators from a `LinkedList`, the following two functions are defined and implemented in lines 93–101 in **LiveExample 20.2**.

```cpp
Iterator<T> begin() const; 
Iterator<T> end() const; 
```

The `begin()` function returns the iterator for the first element in the list, and the `end()` function returns the iterator that represents a position past the last element in the list.

**LiveExample 20.3** gives an example that uses iterators to traverse the elements in a linked list and displays the strings in uppercase. The program creates a `LinkedList` for strings in line 17, adds four strings to the list (lines 20–23), and traverses all the elements in the list using iterators and displays them in uppercase (lines 26–30).

## **LiveExample 20.3 TestIterator.cpp**
```cpp
#include <iostream>
#include <string>
#include "LinkedList.h"
using namespace std;

string toUpperCase(string s)
{
  for (int i = 0; i < s.length(); i++)
    s[i] = toupper(s[i]);

  return s;
}

int main()
{
  // Create a list for strings
  LinkedList<string> list;

  // Add elements to the list
  list.add("America");
  list.add("Canada");
  list.add("Russia");
  list.add("France");

  // Traverse a list using iterators
  for (Iterator<string> iterator = list.begin();
    iterator != list.end(); iterator++)
  {
    cout << toUpperCase(*iterator) << " ";
  }

  return 0;
}
```
```
command>cl TestIterator.cpp
Microsoft C++ Compiler 2019 
Compiled successful (cl is the VC++ compile/link command)

command>TestIterator 
AMERICA CANADA RUSSIA FRANCE 

command>
```


>[!Note]
An iterator functions like a pointer. It may be implemented using pointers, array indexes, or other data structures. The abstraction of iterators spares you the details of implementation. **Chapter 22**, “STL Containers,” will introduce iterators in STL. STL iterators provide a uniform interface for accessing the elements in a container, so you can use iterators to access the elements in a vector or a set just as in a linked list.

Iterator can be used to traverse the elements in a container efficiently. Note that the `printList` function takes _O_(_n_2) time since the `get(index)` function takes _O_(_n_) time to obtain an element in the ith index in the list. So, you should rewrite the printList function using iterators to improve its efficiency.

```cpp
    void printList(const LinkedList<string>& list) 
    { 
      Iterator<string> current = list.begin(); 
      while (current != list.end()) 
      { 
        cout << *current << " "; 
        ++current; 
      } 
      cout << endl; 
    } 
```

Note that the `Iterator` class is derived from `std::iterator``<``std::forward_iterator_tag, T``>`. It is not necessary to make `Iterator` a child class of `std::iterator``<``std::forward_iterator_tag, T``>`, but doing so enables you to invoke the C++ STL library functions for `LinkedList` elements. These functions use iterators to traverse elements in the container. **LiveExample 20.4** gives an example that uses the C++ STL library functions `max_element` and `min_element` to return the maximum and minimum elements in a linked list.

## **LiveExample 20.4 TestSTLAlgorithm.cpp**
```cpp
#include <iostream>
#include <algorithm>
#include <string>
#include "LinkedList.h"
using namespace std;

int main()
{
  // Create a list for strings
  LinkedList<string> list;

  // Add elements to the list
  list.add("America");
  list.add("Canada");
  list.add("Russia");
  list.add("France");

  cout << "The max element in the list is: " <<
    *max_element(list.begin(), list.end()) << endl;

  cout << "The min element in array1: " <<
    *min_element(list.begin(), list.end()) << endl;

  return 0;
}
```
```
command>cl TestSTLAlgorithm.cpp
Microsoft C++ Compiler 2019 
Compiled successful (cl is the VC++ compile/link command)

command>TestSTLAlgorithm 
The max element in the list is: Russia
The min element in array1: America

command>
```

The `max_element` and `min_element` functions were introduced in **Section 11.8**, “Useful Array Functions.” The functions take pointers in the parameters. Iterators are like pointers. You can call an iterator just as a pointer for convenience. The `max_element(iterator1, iterator2)` returns the iterator for the maximum element between `iterator1` and `iterator2 - 1`.

## Self-Check
### What happens if Iterator is not defined as a subtrype of std::iterator?  

The STL algorithms rely on the std::iterator class. If Iterator is not a subtype of std::iterator, the `max_element` and `min_element` will not work.

# References
