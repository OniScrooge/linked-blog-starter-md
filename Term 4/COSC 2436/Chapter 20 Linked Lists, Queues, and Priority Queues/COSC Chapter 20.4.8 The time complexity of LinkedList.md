
# Summary

# Related
Prev - [[COSC Chapter 20.4.7 The source code for LinkedList]]

Next - [[COSC Chapter 20.5 Iterators]]
# Content
**Table 20.1** summarizes the complexities of the functions in `LinkedList`.

#### Table 20.1 **Time Complexities for functions in `LinkedList`**

|   |   |
|---|---|
|**Functions**|**Time**|
|`add(e: T)`|_O_(1)|
|`add(index: int, e: T)`|_O_(_n_)|
|`clear()`|_O_(_n_)|
|`contains(e: T)`|_O_(_n_)|
|`get(index: int)`|_O_(_n_)|
|`indexOf(e: T)`|_O_(_n_)|
|`isEmpty()`|_O_(1)|
|`lastIndexOf(e: T)`|_O_(_n_)|
|`remove(e: T)`|_O_(_n_)|
|`getSize()`|_O_(1)|
|`remove(index: int)`|_O_(_n_)|
|`set(index: int, e: T)`|_O_(_n_)|
|`addFirst(e: T)`|_O_(1)|
|`removeFirst()`|_O_(1)|
|`addLast(e: T)`|_O(_1_)_|
|`removeLast()`|_O(n)_|

Note that you can implement `LinkedList` without using the size data field. But then the `size()` function would take O(n) time. You can use an array, a vector, or a linked list to store elements. If you don’t know the number of elements in advance, it is more efficient to use a vector or a linked list, because these can grow and shrink dynamically. If your application requires frequent insertion and deletion anywhere, it is more efficient to store elements using a linked list, because inserting an element into an array or a vector would require all the elements in the array after the insertion point to be moved. If the number of elements in an application is fixed and the application does not require random insertion and deletion, it is simple and efficient to use an array to store the elements.

## Self-Check
### Discuss the pros and cons of using arrays and linked lists.
See the Note in this section.

### If the number of elements in the program is fixed, what data structure should you use? If the number of elements in the program changes, what data structure should you use?
If the number of elements in the program is fixed, it is efficient and simple to use an array. If the number of elements in the program changes, it is better to use a linked list.

### If you have to add or delete the elements anywhere in a list, should you use a vector or a linked list?
If you have to add or delete the elements anywhere in a list, you should you use a linked list?

### If you change the function signature for printList in line 6 in LiveExample 20.1 to
`void printList(const LinkedList<string> list)`

### Will the program work? So, what is the difference between the two signatures?  
The program will work in the same way as before the change. The difference is that the new signature passes the value of the list to the function, whereas the original signature passes the reference of the list to the function.

### What will happen when you run the following code?
```cpp
#include <iostream>
#include <string>
#include "LinkedList.h"
using namespace std;

int main()
{
  LinkedList<string> list;
  list.add("abc");
  cout << list.removeLast() << endl;
  cout << list.removeLast() << endl;

  return 0;
}
```

A runtime error will be thrown in line 11, but not caught. So the program will terminate abnormally.

### Show the output of the following code:
```cpp
#include <iostream>
#include <string>
#include "LinkedList.h"
using namespace std;

int main()
{
  LinkedList<string> list;
  list.add("abc");
  
  try
  {
    cout << list.removeLast() << endl;
    cout << list.removeLast() << endl;
  }
  catch (runtime_error& ex)
  {
    cout << "The list size is " <<  list.getSize() << endl;
  }

  return 0;
}
```

#### Answer
The program displays:
```
abc 
The list size is 0 
```            

### What would be the time complexity for the `getSize()` function if the size data field is not used in `LinkedList`?

O(n)

### Note that the `get(int)` function is declared as `T& get(int index) const`. What is the output of the following code?
```cpp
  LinkedList<string> list;
  list.add("abc");
  list.get(0)[0] = 'T';
  cout << list.get(0) << endl; 
```

### If the `get(int)` function is redeclared as `T get(int index) const`, what would be the output of the preceding code?

For `T& get(int index) const` defined in the book, the output is Tbc. In this case, the `get(int)` function returns a reference of the string in the list. `list.get(0)[0] = 'T'` changes the string in the list.  
For `T get(int index) const`, the output would be "abc". In this case, the `get(int)` function returns a copy of the string in the list. `list.get(0)[0] = 'T'` does not change the string in the list.
# References