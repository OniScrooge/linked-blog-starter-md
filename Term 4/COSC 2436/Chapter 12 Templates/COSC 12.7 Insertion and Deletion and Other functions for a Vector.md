# Summary

# Learning Objectives

# Related
Prev - [[COSC 12.6 The C++ vector class]]

Next - [[COSC 12.8 Replacing Arrays using the Vector Class]]
# Content

## Key Point

You can use the `insert` and `erase` functions to insert and delete elements in a vector. 

You can insert an element at the end of a vector using the `push_back` function. To insert an element anywhere in the vector, you need to use the `insert` `(p, element)` function, where `p` is a pointer to the element in the vector.

The pointer to the first element in a vector `v` can be obtained by invoking `v.begin()`. So the pointer that points to the `ith` element in the vector is `v.begin() + i`. You can also use the `v.end()` function to return the pointer that past the last element in the vector. So the pointer that points to the last element in the vector is `v.end() - 1`. More precisely, here a pointer is actually an iterator. We will introduce iterators in **Chapter 20**. For now, you can think iterators just as pointers.

You can remove the last element in a vector using the `pop_back` function. To remove an element anywhere in the vector, you need to use the `erase(p)` function, where `p` is the pointer that points an element in the vector.

The useful functions `min_element`, `max_element`, `sort`, `random_shuffle`, and `find` for arrays introduced in **Section 11.8** can also be used for vectors.

**LiveExample 12.9** gives an example that demonstrates these functions.
```C++
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

template<typename T>
void print(const string& title, const vector<T>& v)
{
  cout << title << " ";
  for (int i = 0; i < v.size(); i++)
    cout << v[i] << " ";
  cout << endl;
}

int main()
{
  vector<int> v;
  for (int i = 0; i < 5; i++)
    v.push_back(i);

  v.insert(v.begin() + 1, 20); // Insert 20 at index 1
  v.erase(v.end() - 2); // Remove the second last element
  print("The elements in vector:", v);

  sort(v.begin(), v.end()); // Sort the elements in v
  print("Sorted elements:", v);

  random_shuffle(v.begin(), v.end()); // Shuffle the elements in v
  print("After random shuffle:", v);

  cout << "The max element is " << 
    *max_element(v.begin(), v.end()) << endl;

  cout << "The min element is " << 
    *min_element(v.begin(), v.end()) << endl;
  
  int key = 45;
  if (find(v.begin(), v.end(), key) == v.end()) 
    cout << key << " is not in the vector" << endl;
  else
    cout << key << " is in the vector" << endl;

  return 0;
}
```

```
command>cl VectorInsertDelete.cpp
Microsoft C++ Compiler 2019 
Compiled successful (cl is the VC++ compile/link command)

command>VectorInsertDelete 
The elements in vector: 0 20 1 2 4 
Sorted elements: 0 1 2 4 20 
After random shuffle: 20 1 4 2 0 
The max element is 20
The min element is 0
45 is not in the vector

command>
```

This program creates a vector (line 18) and appends five integers to it (lines 19–20). The program inserts 20 at index 1 in the vector (line 22) and deletes the second last element from the vector (line 23).

The program uses the `sort` function to sort the vector (line 26) and the `random_shuffle` function to random shuffle the elements (line 29). The program obtains the max and min element using the `max_element` and `min_element` functions (lines 32–36). Finally, the program invokes the `find` function to test if an element is in the vector (lines 39). The `find` function returns the pointer to the element if the element is found in the vector. Otherwise, it returns the pointer that points to the element past the last element in the search range.

## Self-Check

### Suppose a vector v contains integers 1, 2, 3, 4. What is in the vector after the following statements?
```C++
v.insert(v.begin(), 5);
v.erase(v.begin() + 1);

1 5 1 2 3 4
```

### Suppose a vector v contains integers 1, 2, 3, 4. What is the output of the following code?
```C++
cout << *max_elemet(v.begin() + 1, v.end() - 1);
cout << *min_elemet(v.begin() + 1, v.end() - 1);

3
2
```
# References
