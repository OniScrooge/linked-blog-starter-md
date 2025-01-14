# Summary

# Learning Objectives

# Related
Prev - [[COSC Chapter 19.6.4 The Heap Class]]

Next - [[COSC Chapter 19.6.6 Heap Sort Time Complexity]]
# Content
To sort an array using a heap, first create an object using the `Heap` class, add all the elements to the heap using the `add` [[function]], and remove all the elements from the heap using the `remove` [[function]]. The elements are removed in descending order. **LiveExample 19.6** gives a program for sorting an array using a heap.

## **LiveExample 19.6 HeapSort.cpp**
```cpp
#include <iostream>
#include "Heap.h"
using namespace std;

template <typename T>
void heapSort(T list[], int arraySize)
{
  Heap<T> heap;

  for (int i = 0; i < arraySize; i++)
    heap.add(list[i]);

  for (int i = 0; i < arraySize; i++)
    list[arraySize - i - 1] = heap.remove();
}

int main()
{
  const int SIZE = 9;
  int list[] = {1, 7, 3, 4, 9, 3, 3, 1, 2};
  heapSort(list, SIZE);
  for (int i = 0; i < SIZE; i++)
    cout << list[i] << " ";

  return 0;
}  
```
```
command>cl HeapSort.cpp
Microsoft C++ Compiler 2019 
Compiled successful (cl is the VC++ compile/link command)

command>HeapSort 
1 1 2 3 3 3 4 7 9 

command>
```

Note that the largest element in the heap is removed first. So, the removed elements from the heap are placed in the array in the reversed order (lines 13–14).

## Self-Check
### Modify line 13 in LiveExample 19.6 so that the elements are sorted in a non-increasing order.
Change it to:
    for (int i = 0; i < arraySize; i++)
# References
