/*
Name: Patrick Ignaut w211197397

Date: 11/14/2024

Explanation: The program creates two similar classes. One is an templated class for a statically created stack. The other is a templated class for a dynamically created stack.
Both have constructors, and member functions to check if empty, peek, push values, pop values, and getters for size. The dynamic class has a destructor, copy constructor to 
handle the dynamically allocated memory and a member function to check for the stacks capacity. The main function tests these two classes' implementation with varying values
and their member functions.
*/


#include <iostream>
#include <string>


// Class to statically allocate for that stack class
template<typename T>
class StaticStack
{
private:
    T elements[100];
    int size;

public:
    // Constructor
    StaticStack()
    {
        size = 0;
    }
    // Checks if empty
    bool empty() const
    {
        return (size == 0);
    }
    // Peeks at the next element in the stack array
    T peek() const
    {
        return elements[size - 1];
    }
    // Pushes a value to the stack array
    void push(T value)
    {
        elements[size++] = value;
    }
    // Pops a value off the stack array
    T pop()
    {
        return elements[--size];
    }
    // Getter for the size of the stack array
    int getSize() const
    {
        return size;
    }
};

// Class to dynamically allocate memory for that stack class
template<typename T>
class DynamicStack
{
private:
    T* elements;
    int size;
    int capacity;

public:
    // No-arg constructor
    DynamicStack(): size(0), capacity(16)
    {
        elements = new T[capacity];
    }
    // Copy constructor
    DynamicStack(const DynamicStack& stack)
    {
        elements = new T[stack.capacity];
        size = stack.size;
        capacity = stack.size;
        for(int i {0}; i < size; ++i)
        {
            elements[i] = stack.elements[i];
        }
    }
    // Destructor
    ~DynamicStack()
    {
        delete [] elements;
    }
    // Check if stack array is empty
    bool empty() const
    {
        return (size == 0);
    }
    // Checks if capacity can is large enough for the size
    void ensureCapacity()
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
    // Peek at element in the stack array
    T peek() const
    {
        return elements[size - 1];
    }
    // Push value onto the stack array
    void push(T value)
    {
        ensureCapacity();
        elements[size++] = value;
    }
    // Pop a value off the stack array
    T pop()
    {
        return elements[--size];
    }
    // Getter for the stack array size
    int getSize() const
    {
        return size;
    }
};


int main()
{
    // Create a stack of int values
    StaticStack<int> intStack;
    DynamicStack<int> dintStack;

    // Push i into the stack
    for (int i = 0; i < 10; i++)
    {
        intStack.push(i);
    }

    for (int i = 0; i < 10; i++)
    {
        dintStack.push(i);
    }

    // Pops values off the stack until empty
    while (!intStack.empty())
    {
        std::cout << intStack.pop() << " " << '\n';
    }

    while (!dintStack.empty())
    {
        std::cout << dintStack.pop() << " " << '\n';
    }

    // Create a stack of strings
    StaticStack<std::string> stringStack;
    StaticStack<std::string> dStringStack;

    // Push each string of a city name to the stack
    stringStack.push("Chicago");
    stringStack.push("Denver");
    stringStack.push("London");

    dStringStack.push("Houston");
    dStringStack.push("Dallas");
    dStringStack.push("Lubbock");

    // Pop each value from the stack while the stack remains un-empty
    while (!stringStack.empty())
    {
        std::cout << stringStack.pop() << " " << '\n';
    }

    while (!dStringStack.empty())
    {
        std::cout << dStringStack.pop() << " " << '\n';
    }

    return 0;
}