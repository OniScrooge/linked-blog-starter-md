# Summary

# Learning Objectives

# Related
Prev - [[COSC Chapter 10.5 Instance and static members]]

Next - [[COSC Chapter 10.7 Thinking in objects]]
# Content
## Key Point
C++ also enables you to specify a constant member function to tell the compiler that the function should not change the value of any data fields in the object.

You used the `const` keyword to specify a constant parameter to tell the compiler that the parameter should not be changed in the function. You can also use the `const` keyword to specify a constant member function (or simply [[constant function]] to tell the compiler that the function does not change the data fields in the object. To do so, place the `const` keyword at the end of the function header. For example, you may redefine the `Circle` class in **LiveExample 10.6** as shown in **LiveExample 10.9**, and the header file is implemented in **LiveExample 10.10**.

## **LiveExample 10.9 CircleWithConstantMemberFunctions.h**
```cpp
#ifndef CIRCLE_H
#define CIRCLE_H

class Circle
{
public:
  Circle();
  Circle(double);
  double getArea() const; 
  // const instance member function
  double getRadius() const; 
  void setRadius(double);
  // No const for static member functions
  static int getNumberOfObjects(); 

private:
  double radius;
  static int numberOfObjects;
};

#endif
```

## **LiveExample 10.10 CircleWithConstantMemberFunctions.cpp**
```cpp
#include "CircleWithConstantMemberFunctions.h"

int Circle::numberOfObjects = 0;

// Construct a circle object
Circle::Circle()
{
  radius = 1;
  numberOfObjects++;
}

// Construct a circle object
Circle::Circle(double newRadius)
{
  radius = newRadius;
  numberOfObjects++;
}

// Return the area of this circle
double Circle::getArea() const
{
  return radius * radius * 3.14159;
}

// Return the radius of this circle
double Circle::getRadius() const
{
  return radius;
}

// Set a new radius
void Circle::setRadius(double newRadius)
{
  radius = (newRadius >= 0) ? newRadius : 0;
}

// Return the number of circle objects
int Circle::getNumberOfObjects()
{
  return numberOfObjects;
}
```

Only instance member functions can be defined as constant functions. Like constant parameters, constant functions are for _defensive programming_. If your function mistakenly changes the value of data fields in a function, a compile error will be reported. Note that you can define only instant functions constant, not static functions. An instance getter function should always be defined as a constant member function, because it does not change the contents of the object.

If a function does not change the object being passed, you should define the parameter constant using the `const`​ ​keyword like this:
```cpp
void printCircle(const Circle& c) 
{ 
  cout << "The area of the circle of " 
    << c.getRadius() << " is " << c.getArea() << endl; 
} 
```

Note that this code will not compile if the `getRadius()` or `getArea()` function is not defined const. If you use the `Circle` class defined in **LiveExample** **9.9**, the preceding function will not compile, because the `getRadius()` and `getArea()` are not defined const. However, if you use the `Circle`​ ​class defined in **LiveExample 10.9**, the preceding function will compile, because the `getRadius()` and `getArea()` are defined const.

>[!Tip]
You can use the `const`​ ​modifier to specify a constant reference parameter or a constant member function. You should use the `const`​ ​modifier _consistently_ whenever appropriate.

## Self-Check
### True or false? Only instance member functions can be defined as constant functions.
true
### What is wrong in the following class definition?
```cpp
class Count
{
public:
  int count;

  Count(int c)
  {
    count = c;
  }

  Count()
  {
    count = 0;
  }

  int getCount() const
  {
    return count;
  }

  void incrementCount() const
  {
    count++;
  }
};
```

The function increment changes the data field count in the class. Therefore, it cannot be declared as a constant function.

### What is wrong in the following code?
```cpp
#include <iostream>
using namespace std;

class A
{
public:
  A();
  double getNumber();

private:
  double number;
};

A::A() 
{
  number = 1;
}

double A::getNumber() 
{
  return number;
}

void printA(const A& a)
{
  cout << "The number is " << a.getNumber() << endl;
}

int main()
{
  A myObject;
  printA(myObject);

  return 0;
}
```

Inconsistent use of const. Either change getNumber to a const member function or remove const in the printA header.
# References
