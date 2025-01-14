# Summary

# Learning Objectives

# Related
Prev - [[COSC Chapter 9.8 Inline Functions in Classes]]

Next - [[COSC Chapter 9.10 The scope of variables]]
# Content
## Key Point
Making data fields private protects data and makes the class easy to maintain.

The data field `radius` in the `Circle` class in **Listing 9.1** can be modified directly (e.g., `circle1.radius = 5`). This is not a good practice—for two reasons:
- First, data may be tampered with.
- Second, it makes the class difficult to maintain and vulnerable to bugs. Suppose you want to modify the `Circle` class to ensure that the radius is nonnegative after other programs have already used the class. You have to change not only the `Circle` class, but also the programs that use the `Circle` class. This is because the clients may have modified the radius directly (e.g., `myCircle.radius = -5`).

To prevent direct modifications of properties, you should declare the data field private, using the [[private]] keyword. This is known as [[data field encapsulation]]. Making the radius data field private in the `Circle` class, you can define the class as follows:

```cpp
class Circle 
{ 
public: 
  Circle(); 
  Circle(double); 
  double getArea(); 
 
private: 
  double radius; 
}; 
```

A private data field cannot be accessed by an object through a direct reference outside the class that defines the private field. But often a client needs to retrieve and/or modify a data field. To make a private data field accessible, provide a _getter function_ to return the field’s value. To enable a private data field to be updated, provide a _setter function_ to set a new value. A getter function is also referred to as an [[accessor]] and a setter to a [[mutator]].

A getter function has the following signature:
```cpp
returnType getPropertyName() 
 
```

If the `returnType` is `bool`, by convention the getter function should be defined as follows:
```cpp
bool isPropertyName() 
```

​​​A setter function has the following signature:​
```cpp
void setPropertyName(dataType propertyValue) 
```

Let us create a new circle class with a private data field radius and its associated accessor and [[mutator]] functions. The class diagram is shown in **Figure 9.6**. The new circle class is defined in **LiveExample 9.9**.

## Figure 9.6
![[Pasted image 20241207122744.png]]

## **LiveExample 9.9 CircleWithPrivateDataFields.h**
```cpp
#ifndef CIRCLE_H
#define CIRCLE_H

class Circle
{
public:
  Circle();
  Circle(double);
  double getArea();
  double getRadius();
  void setRadius(double); 

private:
  double radius;
};

#endif
```

**LiveExample 9.10** implements the class contract specified in the header file in **LiveExample 9.9**.

## **LiveExample 9.10 CircleWithPrivateDataFields.cpp**
```cpp
#include "CircleWithPrivateDataFields.h"

// Construct a default circle object
Circle::Circle()
{
  radius = 1;
}

// Construct a circle object
Circle::Circle(double newRadius)
{
  radius = newRadius;
}

// Return the area of this circle
double Circle::getArea()
{
  return radius * radius * 3.14159;
}

// Return the radius of this circle
double Circle::getRadius()
{
  return radius;
}

// Set a new radius
void Circle::setRadius(double newRadius)
{
  radius = (newRadius >= 0) ? newRadius : 0;
}
```

The `getRadius()` function (lines 22–25) returns the radius, and the `setRadius(newRadius)` function (line 28–31) sets a new radius into the object. If the new radius is negative, `0` is set to the radius in the object. Since these functions are the only ways to read and modify radius, you have total control over how the `radius` property is accessed. If you have to change the functions’ implementation, you need not change the client programs. This makes the class easy to maintain.

**LiveExample 9.11** is a client program that uses the `Circle` class to create a `Circle` object and modifies the radius using the `setRadius` function.

## **LiveExample 9.11 TestCircleWithPrivateDataFields.cpp**
```cpp
#include <iostream>
#include "CircleWithPrivateDataFields.h"
using namespace std;

int main()
{
  Circle circle1;
  Circle circle2(5.0);

  cout << "The area of the circle of radius "
    << circle1.getRadius() << " is " << circle1.getArea() << endl;
  cout << "The area of the circle of radius "
    << circle2.getRadius() << " is " << circle2.getArea() << endl;

  // Modify circle radius
  circle2.setRadius(100);
  cout << "The area of the circle of radius "
    << circle2.getRadius() << " is " << circle2.getArea() << endl;

  return 0;
}
```
```
command>cl TestCircleWithPrivateDataFields.cpp
Microsoft C++ Compiler 2019 
Compiled successful (cl is the VC++ compile/link command)

command>TestCircleWithPrivateDataFields 
The area of the circle of radius 1 is 3.14159
The area of the circle of radius 5 is 78.5397
The area of the circle of radius 100 is 31415.9

command>
```

The data field `radius` is declared private. Private data can be accessed only within their defining class. You cannot use `circle1.radius` in the client program. A compile error would occur if you attempted to access private data from a client.

>[!Tip]
To prevent data from being tampered with and to make the class easy to maintain, the data fields in this book will be private.

## Self-Check
### What is wrong in the following code? (Use the Circle class defined in __LiveExample 9.9__, `CircleWithPrivateDataFields.h`.)
```cpp
Circle c;
cout << c.radius << endl;
```
You cannot use `c.radius`, since radius is a private data field.

### What is an accessor function? What is a mutator function? What are the naming conventions for such functions?
Accessor function is for retrieving private data value and mutator function is for changing private data value. The naming convention for accessor function is `getDataFieldName()` for non-boolean values and `isDataFieldName()` for bool values. The naming convention for mutator function is `setDataFieldName(value)`.
### What are the benefits of data field encapsulation?
Two benefits: (1) for protecting data and (2) for easy to maintain the class.
# References
