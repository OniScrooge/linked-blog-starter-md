# Summary

# Learning Objectives

# Related
Prev - [[COSC 12.9 Case study - Evaluating Expressions]]

Next - [[COSC Chapter 12 Summary]]
# Content
## Key Point

C++11 provides the `unique_ptr` class for wrapping a pointer to perform automatic object destruction. 

A serious problem with dynamic memory allocation is potential memory leak. Memory leak may be caused by a programmer error if a programmer forgets to destroy the memory after an object is no longer used. It may also be caused by a runtime exception if the program throws an exception before it can destroy the memory for the object. The C++11 smart pointers come to the rescue.

C++11 introduced a new template class named `unique_ptr`, which functions as a pointer with additional features for automatic memory deallocation. This is called a [smart pointer](https://revel-ise.pearson.com/courses/66e7050d84448f59a62c6945/pages/urn:pearson:entity:8b095379-6e5a-42a7-9193-0ca0ec68460b?source=dashboard#), since it can automatically destroy the memory for the object when the object is no longer used. Here is an example of creating a smart pointer:

![[Pasted image 20241005150644.png]]

This statement creates a smart pointer named `p1` that points to a memory for an `int` array of `10` elements. Here are some detailed descriptions for the statement:
- The `unique_ptr` class is defined in the `memory` header file, which must be included in order to use `unique_ptr` in the program.
- `int``[]` indicates that the smart pointer points to an array of `int` values.
- `p1` is the name of the smart pointer.
- `new` `int``[10]` is an expression that creates a dynamic memory for an array of `10 int` values, which is passed to the constructor of the `unique_ptr` class to create smart pointer.

Here are several more examples of creating smart pointers:

```cpp
unique_ptr<double> p2(new double); 
```

This statement creates a smart pointer for a `double` value.

```cpp
unique_ptr<Circle> p3(new Circle); 
```

This statement creates a smart pointer for a `Circle` objet.

Smart pointers can be used just like a regular pointer. The following statement assigns `5.5` to memory pointed by `p2`.

```cpp
*p2 = 5.5; 
```

The following statement displays the area for a circle pointed by `p3`.

```cpp
cout << p3->getArea(); // or cout << (*p3).getArea() 
```

**LiveExample 12.13** gives an example that creates a new array which is the reversal of an original array. 
```C++
#include <iostream>
#include <memory>
using namespace std;

unique_ptr<int[]> reverse(const int* list, int size)
{
  // Smart pointer for int[size]
  unique_ptr<int[]> result(new int[size]); 

  for (int i = 0, j = size - 1; i < size; i++, j--)
  {
    result[j] = list[i];
  }

  return result;
}

void printArray(const unique_ptr<int[]>& list, int size)
{
  for (int i = 0; i < size; i++)
    cout << list[i] << " ";
}

int main()
{
  int list[] = {1, 2, 3, 4, 5, 6};
  unique_ptr<int[]> p = reverse(list, 6);

  printArray(p, 6);

  return 0;
}
```

```
command>cl ReverseArrayUsingSmartPointer.cpp
Microsoft C++ Compiler 2019 
Compiled successful (cl is the VC++ compile/link command)

command>ReverseArrayUsingSmartPointer 
6 5 4 3 2 1 

command>
```

The program creates an array (line 26) and invokes the `reverse` function to return a new array which is the reversal of the original array (line 27). The new array is created using `new` `int[size]` (line 8) and it is referenced by a smart pointer named `result`.

The elements in the original array `list` are copied to `result` in​ reverse ord​er in the for loop (lines 10–13). The smart pointer `result` is returned in line 15. The return value is assigned to a smart pointer `p` in line 27 in the main function.

The smart pointer `p` is passed by reference to `list` in the `printArray` function (line 29). The `printArray` function displays the array elements accessed through a smart pointer `list` (line 21). Note that the parameter `list` in the `printArray` is pass-by-reference for two reasons. First, it is more efficient to pass a `unique_ptr` object by reference. Second, a smart pointer is unique and it cannot be copied.

## Self-Check
### Create a smart pointer named p for an array of 12 string objects, assign "abc" to the first string in the array, and display the first string.

```C++
unique_ptr<string[]> p(new string[12]);
p[0] = "abc";
cout << p[0] << endl;            
```
### Create a smart pointer named p for a string "abc".
```C++
unique_ptr<string[]> p(new string("abc");
```

# References
