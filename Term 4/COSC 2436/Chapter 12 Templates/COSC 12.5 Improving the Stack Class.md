# Summary

# Learning Objectives

# Related
Prev - [[COSC 12.4 Class Templates]]

Next - [[COSC 12.6 The C++ vector class]]
# Content

## Key Point

This section implements a dynamic stack class.

There is a problem in the `Stack` class. The elements of the stack are stored in an array with a fixed size `100` (see line 16 in **LiveExample 12.4**). So, you cannot store more than `100` elements in a stack. You could change `100` to a larger number, but if the actual stack is small, this would waste space. One way to resolve this dilemma is to allocate more memory dynamically when needed.

The `size` property in the `Stack``<``T``>` class represents the number of elements in the stack. Let us add a new property named `capacity` that represents the current size of the array for storing the elements. The no-arg constructor of `Stack``<``T``>` creates an array with capacity `16`. When you add a new element to the stack, you may need to increase the array size in order to store the new element if the current capacity is full.

How do you increase the array capacity? You cannot do so, once the array is declared. To circumvent this restriction, you may create a new, larger array, copy the contents of the old array to this new one, and delete the old array.

The improved `Stack``<``T``>`​ class is ​shown in **LiveExample 12.7**.​​

## **LiveExample 12.7 ImprovedStack.h**
```Cpp
#ifndef IMPROVEDSTACK_H
#define IMPROVEDSTACK_H

template<typename T>
class Stack
{
public:
  Stack(); // No-arg constructor
  Stack(const Stack&); // Copy constructor
  ~Stack(); // Destructor
  bool empty() const;
  T peek() const;
  void push(T value);
  T pop();
  int getSize() const;

private:
  T* elements;
  int size;
  int capacity;
  void ensureCapacity();
};

template<typename T>
Stack<T>::Stack(): size(0), capacity(16)
{
  elements = new T[capacity];
}

template<typename T>
Stack<T>::Stack(const Stack& stack)
{
  elements = new T[stack.capacity];
  size = stack.size;
  capacity = stack.capacity;
  for (int i = 0; i < size; i++)
  {
    elements[i] = stack.elements[i];
  }
}

template<typename T>
Stack<T>::~Stack()
{
  delete [] elements;
}

template<typename T>
bool Stack<T>::empty() const
{
  return size == 0;
}

template<typename T>
T Stack<T>::peek() const
{
  return elements[size - 1];
}

template<typename T>
void Stack<T>::push(T value)
{
  ensureCapacity();
  elements[size++] = value;
}

template<typename T>
void Stack<T>::ensureCapacity()
{
  if (size >= capacity)
  {
    T* old = elements;
    capacity = 2 * size;
    elements = new T[size * 2];

    for (int i = 0; i < size; i++)
      elements[i] = old[i];

    delete [] old;
  }
}

template<typename T>
T Stack<T>::pop() 
{
  return elements[--size];
}

template<typename T>
int Stack<T>::getSize() const
{
  return size;
}

#endif
```

Since the internal array `elements` is dynamically created, a destructor must be provided to properly destroy the array to avoid memory leak (lines 42–46). Note that the array elements in **LiveExample 12.4**, GenericStack.h, are not allocated dynamically, so there is no need to provide a destructor in that case.

The `push` `(T value)` function (lines 60–65) adds a new element to the stack. This function first invokes `ensureCapacity()` (line 63), which ensures that there is a space in the array for the new element.

The `ensureCapacity()` function (lines 67–81) checks whether the array is full. If it is, create a new array that doubles the current array size, set the new array as the current array, copy the old array to the new array, and delete the old array (line 79).

Please note that the syntax to destroy a dynamically created array is

```cpp
delete [] elements; // Line 45 
delete [] old; // Line 79 
```

What happens if you mistakenly write the following?

```cpp
delete elements; // Line 45 
delete old; // Line 79 
```

The program will compile and run fine for a stack of primitive-type values, but it is not correct for a stack of objects. The statement `delete` `[]` `elements` first calls the destructor on each object in the `elements` array and then destroys the array, whereas the statement `delete` `elements` calls the destructor only on the first object in the array.

The `Stack` class can be further improved by storing the elements in a vector (see **Programming Exercise 12.9**). The `vector` class is introduced in the next section.

## Self-Check

>[!faq]- What is wrong if line 79 in LiveExample 12.7 ImprovedStack.h is replaced by `delete old;`
The statement delete [] elements first calls the destructor on each object in the elements array and then destroys the array, whereas the statement delete elements only calls the destructor on the first object in the array. So, the objects in the array may not be destroyed properly.

# References
