# Summary

# Related
Prev - [[COSC Chapter 20.2 Nodes]]

Next - [[COSC Chapter 20.4 Implementing LinkedList]]
# Content
## Key Point

The `LinkedList` class provides the operations for storing, searching, retrieving, and removing elements in a list.

Linked list is a popular data structure for storing data in sequential order. For example, a list of students, a list of available rooms, a list of cities, and a list of books all can be stored using lists. The operations listed here are typical of most lists:
- Retrieve an element from a list.
- Insert a new element to a list.
- Delete an element from a list.
- Find how many elements are in a list.
- Find whether an element is in a list.
- Find whether a list is empty.

**Figure 20.6** gives the class diagram for `LinkedList`. `LinkedList` is a class template with type parameter `T` that represents the type of the elements stored in the list.

## Figure 20.6
![[Pasted image 20241130133114.png]]

You can get an element from the list using `get(int index)`. The index is 0-based; i.e., the node at the head of the list has index `0`. Assume that the `LinkedList` class is available in the header file LinkedList.h. Let us begin by writing a test program that uses the `LinkedList` class, as shown in **LiveExample 20.1**. The program creates a list using `LinkedList` (line 18). It uses the `add` function to add strings to the list and the `remove` function to remove strings.

## **LiveExample 20.1 TestLinkedList.cpp**
```cpp
#include <iostream>
#include <string>
#include "LinkedList.h"
using namespace std;
 
void printList(const LinkedList<string>& list)
{
  for (int i = 0; i < list.getSize(); i++)
  {
    cout << list.get(i) << " ";
  }
  cout << endl;
}
  
int main()
{
  // Create a list for strings
  LinkedList<string> list;
   
  // Add elements to the list
  list.add("America"); // Add America to the list
  cout << "(1) ";
  printList(list);
   
  list.add(0, "Canada"); // Add Cananda to the beginning of the list
  cout << "(2) ";
  printList(list);
   
  list.add("Russia"); // Add Russia to the end of the list
  cout << "(3) ";
  printList(list);
   
  list.add("France"); // Add France to the end of the list
  cout << "(4) ";
  printList(list);
  
  list.add(2, "Germany"); // Add Germany to the list at index 2
  cout << "(5) ";
  printList(list);
  
  list.add(5, "Norway"); // Add Norway to the list at index 5
  cout << "(6) ";
  printList(list);
  
  list.add(0, "Netherlands"); // Same as list.addFirst("Netherlands")
  cout << "(7) ";
  printList(list);
   
  // Remove elements from the list
  list.removeAt(0); // Same as list.remove("Netherlands") in this case
  cout << "(8) ";
  printList(list);
   
  list.removeAt(2); // Remove the element at index 2
  cout << "(9) ";
  printList(list);
   
  list.removeAt(list.getSize() - 1); // Remove the last element
  cout << "(10) ";
  printList(list);
   
  return 0;
}
```
```
command>cl TestLinkedList.cpp
Microsoft C++ Compiler 2019 
Compiled successful (cl is the VC++ compile/link command)

command>TestLinkedList 
(1) America 
(2) Canada America 
(3) Canada America Russia 
(4) Canada America Russia France 
(5) Canada America Germany Russia France 
(6) Canada America Germany Russia France Norway 
(7) Netherlands Canada America Germany Russia France Norway 
(8) Canada America Germany Russia France Norway 
(9) Canada America Russia France Norway 
(10) Canada America Russia France 

command>
```

## Self-Check
### Which of the following statements are used to insert a string s to the head of the list? Which ones are used to append a string s to the end of the list?
```cpp
list.addFirst(s);
list.add(s);
list.add(0, s);
list.add(1, s);
```

#### Answer
The following statements are to insert s to the head of the list.

`list.addFirst(s);`
`list.add(0, s);`

The following statements are to append s to the end of the list.

`list.add(s);`

### Which of the following statements are used to remove the first element from the list? Which ones are used to remove the last element from the list?
```cpp
list.removeFirst(s);
list.removeLast(s);
list.removeFirst();
list.removeLast();
list.remove(0);
list.removeAt(0);
list.removeAt(list.getSize() - 1);
list.removeAt(list.getSize());
```

#### Answer
The following statements are to remove the first element from the list.

`list.removeFirst();`
`list.removeAt(0);`

The following statements are to remove the last element from the list.

`list.removeLast();`
`list.removeAt(list.getSize() - 1);`

### Suppose the `removeAt` function is renamed as remove so that there are two overloaded functions, `remove(T element)` and `remove(int index)`. This is incorrect. Explain the reason.
If you substitute the generic type T with int, these two functions will have the same signature, this will be compile error.

# References