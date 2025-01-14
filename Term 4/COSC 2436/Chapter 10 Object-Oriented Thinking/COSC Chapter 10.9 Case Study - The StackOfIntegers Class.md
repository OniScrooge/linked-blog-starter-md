# Summary

# Learning Objectives

# Related
Prev - [[COSC Chapter 10.8 Class relationships]]

Next - [[COSC Chapter 10.10 Constructor initializer lists]]
# Content
## Key Point
This section designs a class for modeling stacks.

Recall that a stack is a data structure that holds data in a last-in, first-out fashion, as shown in **Figure 10.18**.

Stacks have many applications. For example, the compiler uses a stack to process function invocations. When a function is invoked, its parameters and local variables are placed in an activation record that is pushed into a stack. When a function calls another function, the new function’s parameters and local variables are placed in a new activation record that is pushed into the stack. When a function finishes its work and returns to its caller, its activation record is released from the stack.

You can define a class to model stacks. For simplicity, assume the stack holds the `int`​ ​values. So, name the stack class `StackOfIntegers`. The UML diagram for the class is shown in **Figure 10.19**.

## Figure 10.19
![[Pasted image 20241207160325.png]]
The `StackOfIntegers` class encapsulates the stack storage and provides the operations for manipulating the stack.

Suppose that the class is available, as defined in **LiveExample 10.14**. Let us write a test program in **LiveExample 10.15** that uses the class to create a stack (line 7), stores ten integers `0`, `1`, `2`, . . . , and `9` (lines 9–10), and displays them in reverse order (lines 12–13).

## **LiveExample 10.14 StackOfIntegers.h**
```cpp
#ifndef STACK_H
#define STACK_H

class StackOfIntegers
{
public:
  StackOfIntegers();
  bool empty() const;
  int peek() const;
  void push(int value);
  int pop();
  int getSize() const;

private:
  int elements[100];
  int size;
};

#endif
```

## **LiveExample 10.15 TestStackOfIntegers.cpp**
```cpp
#include <iostream>
#include "StackOfIntegers.h"
using namespace std;

int main()
{
  StackOfIntegers stack;

  for (int i = 0; i < 10; i++)
    stack.push(i);

  while (!stack.empty())
    cout << stack.pop() << " ";

  return 0;
}
```
```
command>cl TestStackOfIntegers.cpp
Microsoft C++ Compiler 2019 
Compiled successful (cl is the VC++ compile/link command)

command>TestStackOfIntegers 
9 8 7 6 5 4 3 2 1 0 

command>
```

How do you implement the `StackOfIntegers` class? The elements in the stack are stored in an array named `elements`. When you create a stack, the array is also created. The no-arg constructor initializes `size` to `0`. The variable `size` counts the number of elements in the stack, and `size` `–` `1` is the index of the element at the top of the stack, as shown in **Figure 10.20**. For an empty stack, `size` is `0`.

## Figure 10.20
![[Pasted image 20241207160412.png]]

The `StackOfIntegers` class uses an array to store the elements in a stack.

The `StackOfIntegers`​ ​class is implemented in **LiveExample 10.16**.

## **LiveExample 10.16 StackOfIntegers.cpp**
```cpp
#include "StackOfIntegers.h"

StackOfIntegers::StackOfIntegers()
{
  size = 0;
}

bool StackOfIntegers::empty() const
{
  return size == 0;
}

int StackOfIntegers::peek() const
{
  return elements[size - 1];
}

void StackOfIntegers::push(int value)
{
  elements[size++] = value;
}

int StackOfIntegers::pop()
{
  return elements[--size];
}

int StackOfIntegers::getSize() const
{
  return size;
}
```
## Self-Check
### When a stack is created, what are the initial values in the elements array?
The values in elements are undefined. There are 100 values in elements.
### When a stack is created, what is the value of variable size?
The variable size is initialized to 0 in the constructor.
# References
