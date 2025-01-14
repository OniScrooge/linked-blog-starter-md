# Summary

# Learning Objectives

# Related
Prev - [[COSC Chapter 10.4 Array of objects]]

Next - [[COSC Chapter 10.6 Constant member functions]]
# Content
## Key Point
A static variable is shared by all objects of the class. A static function cannot access instance members of the class.

The data fields used in the classes so far are known as an [[instance variable 1]]. An instance variable is tied to a specific instance of the class; it is not shared among objects of the same class. For example, suppose that you create the following objects using the `Circle` class in **LiveExample 9.9**, `CircleWithPrivateDataFields.h`:
```cpp
Circle circle1; 
Circle circle2(5); 
```

The `radius` in `circle1` is independent of the `radius` in `circle2` and is stored in a different memory location. Changes made to `circle1`’s `radius` do not affect `circle2`’s `radius`, and vice versa.

If you want all the instances of a class to share data, use a [[static variable]], also known as _class variables_. Static variables store values for the variables in a common memory location. Accordingly, all objects of the same class are affected if one object changes the value of a static variable. C++ supports static functions as well as static variables. A [[static function]] can be called without creating an instance of the class. Recall that an [[instance function 1]] can only be called from a specific instance.

Let us modify the `Circle`​ ​class by adding a static variable `numberOfObjects` to count the number of circle objects created. When the first object of this class is created, `numberOfObjects` is `1`. When the second object is created, `numberOfObjects` becomes `2`. The UML of the new circle class is shown in **Figure 10.10**. The `Circle`​ ​class defines the instance variable `radius` and the static variable​ ​`numberOfObjects`, the instance functions `getRadius`, `setRadius`, and `getArea`, and the static function `getNumberOfObjects`. (Note that static variables and functions are underlined in the UML diagram.)

## Figure 10.10
![[Pasted image 20241207153803.png]]
![[Pasted image 20241207153810.png]]
![[Pasted image 20241207153818.png]]
![[Pasted image 20241207153825.png]]
![[Pasted image 20241207153832.png]]

To declare a static variable or a static function, put the modifier `static`​ ​in the variable or function declaration. So the static variable `numberOfObjects` and the static function `getNumberOfObjects()` can be declared as follows:
```cpp
static int numberOfObjects; 
static int getNumberOfObjects(); 
```

The new circle class is defined in **LiveExample 10.6**

## **LiveExample 10.6 CircleWithStaticDataFields.h**
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
  static int getNumberOfObjects();

private:
  double radius;
  static int numberOfObjects;
};

#endif
```

A static function `getNumberOfObjects` is declared in line 12 and a static variable `numberOfObjects` is declared in line 16 as a private data field in the class.

**LiveExample 10.7** gives the implementation of the `Circle` class:

## **LiveExample 10.7 CircleWithStaticDataFields.cpp**
```cpp
#include "CircleWithStaticDataFields.h"

int Circle::numberOfObjects = 0; // Set numberOfObjects to 0

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

// Return the number of circle objects
int Circle::getNumberOfObjects()
{
  return numberOfObjects;
}
```

The static data field `numberOfObjects` is initialized in line 3. When a `Circle` object is created, `numberOfObjects` is incremented (lines 9, 16).

Instance functions (e.g., `getArea()`) and instance data fields (e.g., `radius`) belong to instances and can be used only after the instances are created. They are accessed from a specific instance. Static functions (e.g., `getNumberOfObjects()`) and static data fields (e.g., `numberOfObjects`) can be accessed from any instance of the class, as well as from their class name.

The program in **LiveExample 10.8** demonstrates how to use instance and static variables and functions and illustrates the effects of using them.

## **LiveExample 10.8 TestCircleWithStaticDataFields.cpp**
```cpp
#include <iostream>
#include "CircleWithStaticDataFields.h"
using namespace std;

int main()
{
  cout << "Number of circle objects created: "
    << Circle::getNumberOfObjects() << endl;

  Circle circle1;
  cout << "The area of the circle of radius "
    << circle1.getRadius() << " is " << circle1.getArea() << endl;
  cout << "Number of circle objects created: "
    << Circle::getNumberOfObjects() << endl;

  Circle circle2(5.0);
  cout << "The area of the circle of radius "
    << circle2.getRadius() << " is " << circle2.getArea() << endl;
  cout << "Number of circle objects created: "
      << Circle::getNumberOfObjects() << endl;

  circle1.setRadius(3.3);
  cout << "The area of the circle of radius "
    << circle1.getRadius() << " is " << circle1.getArea() << endl;

  cout << "circle1.getNumberOfObjects() returns "
    << circle1.getNumberOfObjects() << endl;
  cout << "circle2.getNumberOfObjects() returns "
    << circle2.getNumberOfObjects() << endl;

  return 0;
}
```
```
command>cl TestCircleWithStaticDataFields.cpp
Microsoft C++ Compiler 2019 
Compiled successful (cl is the VC++ compile/link command)

command>TestCircleWithStaticDataFields 
Number of circle objects created: 0
The area of the circle of radius 1 is 3.14159
Number of circle objects created: 1
The area of the circle of radius 5 is 78.5397
Number of circle objects created: 2
The area of the circle of radius 3.3 is 34.2119
circle1.getNumberOfObjects() returns 2
circle2.getNumberOfObjects() returns 2

command>
```

Static variables and functions can be accessed without creating objects. Line 8 displays the number of objects, which is `0`, since no objects have been created.

The `main` function creates two circles, `circle1` and `circle2` (lines 10, 16). The instance variable `radius` in `circle1` is modified to become `3.3` (line 22). This change does not affect the instance variable `radius` in `circle2`, since these two instance variables are independent. The static variable `numberOfObjects` becomes `1` after `circle1` is created (line 10), and it becomes `2` after `circle2` is created (line 16).

You can access static data fields and functions from the instances of the class—e.g., `circle1.getNumberOfObjects()` in line 27 and `circle2.getNumberOfObjects()` in line 29. But it is better to access them from the class name—e.g., `Circle::`. Note that in lines 27 and 29 `circle1.getNumberOfObjects()` and `circle2.getNumberOfObjects()` could be replaced by `Circle::getNumberOfObjects()`. This improves readability, because the reader can easily recognize the static function `getNumberOfObjects()`.

>[!Tip]
Use `ClassName::functionName(arguments)` to invoke a static function and `ClassName::staticVariable` to access static variables. This improves readability, because the user can easily recognize the static function and data in the class.

>[!Tip]
How do you decide whether a variable or function should be instance or static? A variable or function that is dependent on a specific instance of the class should be an instance variable or function. A variable or function that is not dependent on a specific instance of the class should be a static variable or function. For example, every circle has its own radius. Radius is dependent on a specific circle. Therefore, `radius` is an instance variable of the `Circle` class. Since the `getArea` function is dependent on a specific circle, it is an instance function. Since `numberOfObjects` is not dependent on any specific instance, it should be declared static.

## Self-Check
### A data field and function can be declared as instance or static. What are the criteria for deciding?
A variable or function that is dependent on a specific instance of the class should be an instance variable or function. A variable or function that is not dependent on a specific instance of the class should be a static variable or function.
### Where do you initialize a static data field?
You initialize a static data field in the implementation, not inside a class declaration.
### Suppose function `f()` is static defined in class C and c is an object of the C class. Can you invoke `c.f()`, `C::f()`, or `c::f()`?
You can invoke it using c.f() or C::f(). C::f() is better because it clearly indicates that f() is static
# References
