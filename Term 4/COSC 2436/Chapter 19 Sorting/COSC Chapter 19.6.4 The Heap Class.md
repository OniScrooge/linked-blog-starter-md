# Summary

# Learning Objectives

# Related
Prev - [[COSC Chapter 19.6.3 Removing the Root]]

Next - [[COSC Chapter 19.6.5 Sorting Using the Heap Class]]
# Content
Now you are ready to design and implement the `Heap` class. The class diagram is shown in **Figure 19.15**. Its implementation is given in **LiveExample 19.5**.

>[!note] Figure 19.15
>![[Pasted image 20241107112657.png]]

## **LiveExample 19.5 Heap.h**
```cpp
#ifndef HEAP_H
#define HEAP_H
#include <vector>
#include <stdexcept>
using namespace std;

template<typename T>
class Heap
{
public:
  Heap();
  Heap(const T elements[], int arraySize);
  void add(const T& element);
  T remove();
  int getSize() const;

private:
  vector<T> v;
};

template<typename T>
Heap<T>::Heap()
{
}

template<typename T>
Heap<T>::Heap(const T elements[], int arraySize)
{
  for (int i = 0; i < arraySize; i++)
  {
    add(elements[i]);
  }
}

// Insert element into the heap and maintain the heap property 
template<typename T>
void Heap<T>::add(const T& element)
{
  v.push_back(element); // Append element to the heap
  int currentIndex = v.size() - 1; // The index of the last node

  // Maintain the heap property
  while (currentIndex > 0)
  {
    int parentIndex = (currentIndex - 1) / 2;
    // Swap if the current element is greater than its parent
    if (v[currentIndex] > v[parentIndex])
    {
      T temp = v[currentIndex];
      v[currentIndex] = v[parentIndex];
      v[parentIndex] = temp;
    }
    else
      break; // the tree is a heap now

    currentIndex = parentIndex;
  }
}

// Remove the root from the heap 
template<typename T>
T Heap<T>::remove()
{
  if (v.size() == 0)
    throw runtime_error("Heap is empty");

  T removedElement = v[0];
  v[0] = v[v.size() - 1]; // Copy the last to root
  v.pop_back(); // Remove the last element

  // Maintain the heap property
  int currentIndex = 0;
  while (currentIndex < v.size())
  {
    int leftChildIndex = 2 * currentIndex + 1;
    int rightChildIndex = 2 * currentIndex + 2;

    // Find the maximum between two children
    if (leftChildIndex >= v.size()) break; // The tree is a heap
    int maxIndex = leftChildIndex;
    if (rightChildIndex < v.size())
    {
      if (v[maxIndex] < v[rightChildIndex])
      {
        maxIndex = rightChildIndex;
      }
    }

    // Swap if the current node is less than the maximum
    if (v[currentIndex] < v[maxIndex])
    {
      T temp = v[maxIndex];
      v[maxIndex] = v[currentIndex];
      v[currentIndex] = temp;
      currentIndex = maxIndex;
    }
    else
      break; // The tree is a heap
  }

  return removedElement;
}

// Get the number of element in the heap 
template<typename T>
int Heap<T>::getSize() const
{
  return v.size();
}

#endif
```

A heap is represented using a vector internally (line 18). You may change it to other data structures, but the `Heap` class contract will remain unchanged

The `add(T element)` [[function]] (lines 36–58) appends the element to the tree and then swaps it with its parent if it is greater than its parent. This process continues until the new element becomes the root or is not greater than its parent.

The `remove``(``)` [[function]] (lines 61–102) removes and returns the root. To maintain the heap property, the [[function]] moves the last element to the root position and swaps it with its larger child if it is less than the larger child. This process continues until the last element becomes a leaf or is not less than its children.

## Self-Check
### Which of the following statements are wrong?
1.  `Heap<int> heap1;`
2. `Heap<int> heap2 = new Heap<>();`
3. `Heap<int> heap3 = new Heap<int>();`
4. `Heap<int>* heap4 = new Heap<int>();`
5. `Heap<int>* heap4 = new Heap<>();`
#### Answer
Lines 2, 3, and 5 are wrong. Line 1 creates a Heap object named heap1. Line 4 creates a Heap object pointed by heap4.
### What is the return value from invoking the remove method if the heap is empty?

The return value will be null.
# References