
# Summary

# Related
Prev - [[COSC Chapter 20.5 Iterators]]

Next - [[COSC Chapter 20.7 Variations of Linked Lists]]
# Content
## Key Point

You can use a foreach loop to traverse the elements in a collection. 

The foreach loop is a common computer language feature for traversing the elements in a collection sequentially. This feature is supported in C++11. You have already used a foreach loop to traverse the elements in an array or a vector. For example, the following code displays all the elements in the array `myList`:

```cpp
double myList[] = {3.3, 4.5, 1}; 
for (double& e: myList) 
{ 
  cout << e << endl; 
} 
```

You can read the code as “for each element `e` in `myList`, do the following.” Note that the variable, `e`, must be declared as the same type as the elements in `myList`.

In fact, you can use a foreach on any collection with the `begin()` and `end()` functions that return the start and end iterators of the `std::iterator` type. The syntax for a foreach loop is

```cpp
for (elementType& element: collection) 
{ 
  // Process the element 
} 
```

In C++, a vector is a collection with an iterator. So, you can traverse all the elements in a vector using a foreach loop. For example, the following code traverses all the elements in a vector of strings.

```cpp
vector<string> names; 
names.push_back("Atlanta"); 
names.push_back("New York"); 
names.push_back("Kansas"); 
for (string& s: names) 
{ 
  cout << s << endl; 
} 
```

Since list is a collection with an iterator, you can rewrite **LiveExample 20.3** TestIterator.cpp using a foreach loop as shown in **LiveExample 20.5**.

## **LiveExample 20.5 TestForeachLoop.cpp**
```cpp
#include <iostream>
#include <string>
#include "LinkedList.h"
using namespace std;

string toUpperCase(string& s)
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
  for (string& s: list)
  {
    cout << toUpperCase(s) << " ";
  }

  return 0;
}
```
```
command>cl TestForeachLoop.cpp
Microsoft C++ Compiler 2019 
Compiled successful (cl is the VC++ compile/link command)

command>TestForeachLoop 
AMERICA CANADA RUSSIA FRANCE 

command>
```

The program creates a list (line 17) and adds four strings into the list (lines 20–23). A foreach loop is used to traverse the strings in the list (lines 26–29).

## Self-Check
### Show the output of the following code:
```cpp
#include <iostream>
using namespace std;

int main()
{ 
  int list[] = {5, 9};

  for (int i : list)
    i++; 

  for (int i : list)
    cout << i << endl;

  return 0;
}
```

5  
9

### Show the output of the following code:
```cpp
#include <iostream>
using namespace std;

int main()
{ 
  int list[] = {5, 9};

  for (int& i : list)
    i++; 

  for (int i : list)
    cout << i << endl;

  return 0;
}
```

6  
10
# References