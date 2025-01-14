# Summary

# Learning Objectives

# Related
Prev - [[COSC 12.5 Improving the Stack Class]]

Next - [[COSC 12.7 Insertion and Deletion and Other functions for a Vector]]
# Content

## Key Point

C++ contains a generic `vector` class for storing a list of objects. 

You can use an array to store a collection of data such as strings and `int` values. There is a serious limitation: The array size is fixed when the array is created. C++ provides the `vector` class, which is more flexible than arrays. You can use a `vector` object just like an array, but a vector’s size can grow automatically if needed.

To create a vector, use the syntax:

```cpp
vector<elementType> vectorName; 
```

For example,

```cpp
vector<int> intVector; 
```

creates a vector to store `int` values.

```cpp
vector<string> stringVector; 
```

creates a vector to store `string` objects.

**Figure 12.2** lists several frequently used functions in the vector class in a UML class diagram.

![[Pasted image 20241005143938.png]]

You can also create a vector with the initial size, filled with default values. For example, the following code creates a vector of initial size `10` with default values `0`.

```cpp
vector<int> intVector(10); 
```

A vector can be accessed using the subscript operator `[]`. For example,

```cpp
cout << intVector[0]; 
```

displays the first element in the vector.

>[!warning] Caution
>To use the array subscript operator `[]`, the element must already exist in the vector. Like array, the index is `0`-based in a vector–i.e., the index of the first element in the vector is `0` and the last one is `v.size() – 1`﻿. To use an index beyond this range would cause errors.

**LiveExample 12.8** gives an example of using vectors.
```Cpp
#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main()
{
  vector<int> intVector; // Create a vector named intVector

  // Store numbers 1, 2, 3, 4, 5, ..., 10 to the vector
  for (int i = 0; i < 10; i++)
    intVector.push_back(i + 1);

  // Display the numbers in the vector
  cout << "Numbers in the vector: ";
  for (int i = 0; i < intVector.size(); i++)
    cout << intVector[i] << " ";

  vector<string> stringVector;

  // Store strings into the vector
  stringVector.push_back("Dallas");
  stringVector.push_back("Houston");
  stringVector.push_back("Austin");
  stringVector.push_back("Norman"); // Add Norman to the vector

  // Display the string in the vector
  cout << "\nStrings in the string vector: ";
  for (int i = 0; i < stringVector.size(); i++)
    cout << stringVector[i] << " ";

  stringVector.pop_back(); // Remove the last element

  vector<string> v2;
  v2.swap(stringVector);
  v2[0] = "Atlanta"; // Assign Atlanta to replace the first element in v2

  // Redisplay the string in the vector
  cout << "\nStrings in the vector v2: ";
  for (int i = 0; i < v2.size(); i++)
    cout << v2.at(i) << " ";

  return 0;
}
```

```
command>cl TestVector.cpp
Microsoft C++ Compiler 2019 
Compiled successful (cl is the VC++ compile/link command)

command>TestVector 
Numbers in the vector: 1 2 3 4 5 6 7 8 9 10 
Strings in the string vector: Dallas Houston Austin Norman 
Strings in the vector v2: Atlanta Houston Austin 

command>
```

Since the `vector` class is used in the program, line 2 includes its header file. Since the `string` class is also used, line 3 includes the `string` class header file.

A vector for storing `int` values is created in line 8. The `int` values are appended to the vector in line 12. There is no limit on the size of the vector. The size grows automatically as more elements are added into the vector. The program displays all the `int` values in the vector in lines 15–17. Note the array subscript operator `[]` is used to retrieve an element in line 17.

A vector for storing strings is created in line 19. Four strings are added to the vector (lines 22–25). The program displays all the strings in the vector in lines 29–30. Note the array subscript operator `[]` is used to retrieve an element in line 30.

Line 32 removes the last string from the vector. Line 34 creates another vector `v2`. Line 35 swaps `v2` with `stringVector`. Line 36 assigns a new string to `v2[0]`﻿. The program displays the strings in `v2` (lines 40–41). Note that the `at` function is used to retrieve the elements. You can also use the subscript operator `[]` to retrieve the elements.

The `size()` function returns the size of the vector as an `unsigned` (i.e., unsigned integer), not `int`. Some compilers may warn you because an unsigned value is used with a signed `int` value in variable `i` (lines 16, 29, 40). This is just a warning and should not cause any problems, because the unsigned value is automatically promoted to a signed value in this case. To get rid of the warning, declare `i` to be `unsigned` `int` in line 16 as follows:

```cpp
for (unsigned i = 0; i < intVector.size(); i++) 
```

In C++11, you can assign values to a vector using a vector initializer, which is similar to an array initializer. For example, the following statement creates a vector with initial values `1` and `9`.

```cpp
vector<int> intVector{1, 9}; 
```

You can also assign values to a vector after the vector is created using the following syntax:

```cpp
intVector = {13, 92, 1}; 
```

After executing this statement, `intVector` now has values `13`, `92`, and `1`. The old values in `intVector` are destroyed.

Note that you cannot assign values to an array after the array is created using an array initializer. For example, the second statement in the following code will cause a syntax error:

```cpp
int temp[] = {1, 9}; 
temp = {13, 92, 1}; 
```

Like arrays, you can also use a foreach loop to traverse all the elements in a vector in C++11. For example,

```cpp
for (int e: intVector) 
{ 
  cout << e << endl; 
} 
```

displays all the values in `intVector`.

## Self-Check

Use the check point questions, word match, and freestyle exercises to check your understanding of the concepts.

>[!faq]- How do you declare a vector to store double values? How do you append a double to a vector? How do you find the size of a vector? How do you remove an element from a vector?
```C++
vector<double> v;
v.push_back(5.4);
v.size();
v.pop_back();
```

>[!faq] Why is the code in (a) wrong, but the code in (b) correct?

(a)
```
vector<int> v;
v[0] = 4;
```
 
(b)
```
vector<int> v(5);
v[0] = 4;    
```

>[!faq]- (a)
Before you can access v[0], v[0] must exist. You have to use push_back to append a number to the vector first.

>[!faq]- (b)
vector v is defined initialized with 5 elements, each has a default value 0.

>[!faq]- Write a statement that creates a vector with initial values 9.4, 9.1, and 1.3.
```
vector<double> v = {9.4, 9.1, 1.3};
# References
```