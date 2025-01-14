# Summary

# Learning Objectives

# Related
Prev - [[COSC 12.1 Introductions]]

Next - [[COSC 12.5 Improving the Stack Class]]
# Content

## Key Point

__You can define generic types for a class.__

In the preceding sections, you defined template functions with type parameters for the function. You also can define [template classes](https://revel-ise.pearson.com/courses/66e7050d84448f59a62c6945/pages/urn:pearson:entity:46527460-46f6-4650-bc41-069a14ef94c5?source=dashboard#) with type parameters for the class. The type parameters can be used everywhere in the class where a regular type appears.

Recall that the `StackOfIntegers` class, defined in **Section 10.9**, “Case Study: The `StackOfInteger` Class,” can be used to create a stack for `int` values. Here is a copy of the class with its UML class diagram, as shown in **Figure 12.1a**.

```Cpp
#ifndef STACK_H
#define STACK_H
class StackOfIntegers
{
	public: StackOfIntegers();
	bool empty() const;
	int peek() const;
	void push(int value);
	int pop();
	int getSize() const;
private:
	int elements[100];
	int size;
};
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
#endif
```

__Figure 12.1__
![[Pasted image 20241005140824.png]]

`Stack``<``T`> is a generic version of the `Stack` class.

By replacing the highlighted `int` in the preceding code with `double`, `char`, or `string`, you easily can modify this class to define classes such as `StackOfDouble`, `StackOfChar`, and `StackOfString` for representing a stack of `double`, `char`, and `string` values. But, instead of writing almost identical code for these classes, you can define just one template class that works for the element of any type. **Figure 12.1b** shows the UML class diagram for the new generic `Stack` class. **LiveExample 12.4** defines a generic `stack` class for storing elements of a generic type.

**LiveExample 12.4 GenericStack.h**
```Cpp
#ifndef STACK_H
#define STACK_H

template<typename T>
class Stack
{
public:
  Stack();
  bool empty() const;
  T peek() const;
  void push(T value);
  T pop();
  int getSize() const;

private:
  T elements[100];
  int size;
};

template<typename T>
Stack<T>::Stack()
{
  size = 0;
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

template<typename T> // implement push function
void Stack<T>::push(T value)
{
  elements[size++] = value;
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

The syntax for class templates is basically the same as that for function templates. You place the _template prefix_ before the class definition (line 4), just as you place the template prefix before the function template.

```cpp
template<typename T> 
```

The type parameter can be used in the class just like any regular data type. Here, the type `T` is used to define functions `peek``()` (line 10), `push``(T value)` (line 11), and `pop``()` (line 12). `T` also is used in line 16 to declare array `elements`.

The constructors and functions are defined the same way for regular classes, except that the constructors and functions themselves are templates. So, you have to place the template prefix before the constructor and function header in the implementation. For example,

```cpp
template<typename T> 
Stack<T>::Stack() 
{ 
  size = 0; 
} 
 
template<typename T> 
bool Stack<T>::empty() 
{ 
  return size == 0; 
} 
 
template<typename T> 
T Stack<T>::peek() 
{ 
  return elements[size - 1]; 
} 
```

Note also that the class name before the scope resolution operator `::` is `Stack``<``T``>`, not `Stack`.

>[!Tip]
GenericStack.h combines class definition and class implementation into one file. Normally, you put class definition and class implementation into two separate files. For class templates, however, it is safer to put them together, because some compliers cannot compile them separately.

**LiveExample 12.5** gives a test program that creates a stack for `int` values in line 9 and a stack for strings in line 18.

**LiveExample 12.5 TestGenericStack.cpp**
```Cpp
#include <iostream>
#include <string>
#include "GenericStack.h"
using namespace std;

int main()
{
  // Create a stack of int values
  Stack<int> intStack;
  for (int i = 0; i < 10; i++)
    intStack.push(i); // Push i into the stack

  while (!intStack.empty())
    cout << intStack.pop() << " ";
  cout << endl;

  // Create a stack of strings
  Stack<string> stringStack;
  stringStack.push("Chicago");
  stringStack.push("Denver");
  stringStack.push("London"); // Push London to the stack

  while (!stringStack.empty())
    cout << stringStack.pop() << " ";
  cout << endl;

  return 0;
}
```
```
command>cl TestGenericStack.cpp
Microsoft C++ Compiler 2019 
Compiled successful (cl is the VC++ compile/link command)

command>TestGenericStack 
9 8 7 6 5 4 3 2 1 0 
London Denver Chicago 

command>
```

To declare an object from a template class, you have to specify a concrete type for the type parameter `T`. For example,

```cpp
Stack<int> intStack; 
```

This declaration replaces the type parameter `T` with `int`. So, `intStack` is a stack for `int` values. The object `intStack` is just like any other object. The program invokes the `push` function on `intStack` to add ten `int` values to the stack (line 11), and displays the elements from the stack (lines 13–14).

The program declares a stack object for storing strings in line 18, adds three strings in the stack (lines 19–21), and displays the strings from the stack (line 24).

Note the code in lines 9–11:
```cpp
while (!intStack.empty()) 
  cout << intStack.pop() << " "; 
cout << endl; 
```

and in lines 23–25:
```cpp
while (!stringStack.empty()) 
  cout << stringStack.pop() << " "; 
cout << endl; 
```

These two fragments are almost identical. The difference is that the former operates on `intStack` and the latter on `stringStack`. You can define a function with a stack parameter to display the elements in the stack. The new program is shown in **LiveExample 12.6**.

**LiveExample 12.6 TestGenericStackWithTemplateFunction.cpp**
```Cpp
#include <iostream>
#include <string>
#include "GenericStack.h"
using namespace std;

template<typename T>
void printStack(Stack<T>& stack)
{
  while (!stack.empty())
    cout << stack.pop() << " ";
  cout << endl;
}

int main()
{
  // Create a stack of int values
  Stack<int> intStack;
  for (int i = 0; i < 10; i++)
    intStack.push(i);
  printStack(intStack);

  // Create a stack of strings
  Stack<string> stringStack;
  stringStack.push("Chicago");
  stringStack.push("Denver");
  stringStack.push("London");
  printStack(stringStack);

  return 0;
}
```
```
command>cl TestGenericStackWithTemplateFunction.cpp
Microsoft C++ Compiler 2019 
Compiled successful (cl is the VC++ compile/link command)

command>TestGenericStackWithTemplateFunction 
9 8 7 6 5 4 3 2 1 0 
London Denver Chicago 

command>
```

The generic class name `Stack``<``T``>` is used as a parameter type in a [template function](https://revel-ise.pearson.com/courses/66e7050d84448f59a62c6945/pages/urn:pearson:entity:46527460-46f6-4650-bc41-069a14ef94c5?source=dashboard#) (line 7).

>[!Note]
>C++ allows you to assign a _default type_ for a type parameter in a class template. For example, you may assign `int` as a default type in the generic `Stack` class as follows:
```cpp
template<typename T = int> 
class Stack 
{ 
  ... 
}; 
```
>You now can declare an object using the default type like this:
```cpp
Stack<> stack;  // stack is a stack for int values 
```
>
>You can use default type only in class templates, not in function templates.

>[!Note]
>You also can use _nontype parameters_ along with type parameters in a template prefix. For example, you may declare the array capacity as a parameter for the `Stack` class as follows:
```cpp
template<typename T, int capacity> 
class Stack 
{ 
  ... 
private: 
  T elements[capacity]; 
  int size; 
}; 
```
So, when you create a stack, you can specify the capacity for the array. For example,
```cpp
Stack<string, 500> stack; 
```
declares a stack that can hold up to `500` strings.

>[!Note]
You can define static members in a template class. Each template specialization has its own copy of a static data field.

## Self-Check

>[!faq]- Do you have to use the template prefix for each function in the class definition? Do you have to use the template prefix for each function in the class implementation?
Yes. Yes.

>[!faq]- What is wrong in the following code?
>Function templates cannot have default values.
```C++
template<typename T = int>
void printArray(const T list[], int arraySize)
{
  for (int i = 0; i < arraySize; i++)
  {
    cout << list[i] << " ";
  }
  cout << endl;
}
```

>[!faq]- What is wrong in the following code?
>Improper formatting
```C++
template<typename T>
class Foo
{
public:
  Foo();
  T f1(T value);
  T f2();
};

Foo::Foo()
{
  ...
}

T Stack::f1(T value)
{
  ...
}

T Stack::f2()
{
  ...
};
```

```C++
template<typename T>
Foo<T>::Foo()
{
  ...
}

template<typename T>
T Stack<T>::f1(T value)
{
  ...
}

template<typename T>
T Stack<T>::f2()
{
  ...
};
```

>[!faq]- Suppose the template prefix for the Stack class is `template<typename T = string>`. Can you create a stack of strings using the following? `Stack stack;`
>No. You have to use `Stack<>` stack.

# References
