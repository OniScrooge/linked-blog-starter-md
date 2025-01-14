# Summary

# Learning Objectives

# Related
Prev - [[COSC Chapter 9.5 Constructing and Using Objects]]

Next - [[COSC Chapter 9.7 Preventing Multiple Inclusions]]
# Content
## Key Point
Separating class definition from class implementation makes the class easy to maintain.

C++ allows you to separate class definition from implementation. The class definition describes the _contract_ of the class and the class implementation carries out the contract. The class definition simply lists all the data fields, constructor prototypes, and function prototypes. The class implementation implements the constructors and functions. The class definition and implementation may be in two separate files. Both files should have the same name but different extension names. The class definition file has an extension name `.h` (h means header) or `.hpp` and the class implementation file an extension name `.cpp`.

**LiveExample 9.3** and **LiveExample** **9.4** present the `Circle` class definition and implementation.

## **LiveExample 9.3 Circle.h**
```cpp
class Circle
{
public:
  // The radius of this circle
  double radius;

  // Construct a default circle object
  Circle();

  // Construct a circle object
  Circle(double);

  // Return the area of this circle
  double getArea();
};
```

>[!warning]
It is a common mistake to omit the semicolon (`;`) at the end of the class definition.

## **LiveExample 9.4 Circle.cpp**
```cpp
#include "Circle.h"

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
```

The `::` symbol, known as the [[binary scope resolution operator]], specifies the scope of a class member in a class.

Here, `Circle::` preceding each constructor and function in the `Circle` class tells the compiler that these constructors and functions are defined in the `Circle` class.

**LiveExample 9.5** is a program that uses the `Circle` class. Such a program that uses the class is often referred to as a [[client]] of the class.

## **LiveExample 9.5 TestCircleWithHeader.cpp**
```cpp
#include <iostream>
#include "Circle.h"
using namespace std;

int main()
{
  Circle circle1;
  Circle circle2(5.0);

  cout << "The area of the circle of radius "
    << circle1.radius << " is " << circle1.getArea() << endl;
  cout << "The area of the circle of radius "
    << circle2.radius << " is " << circle2.getArea() << endl;

  // Modify circle radius
  circle2.radius = 100;
  cout << "The area of the circle of radius "
    << circle2.radius << " is " << circle2.getArea() << endl;

  return 0;
}
```
```
command>cl TestCircleWithHeader.cpp
Microsoft C++ Compiler 2019 
Compiled successful (cl is the VC++ compile/link command)

command>TestCircleWithHeader 
The area of the circle of radius 1 is 3.14159
The area of the circle of radius 5 is 78.5397
The area of the circle of radius 100 is 31415.9

command>
```

There are at least two benefits for separating a class definition from implementation.
1. It hides implementation from definition. You can feel free to change the implementation. The client program that uses the class does not need to change as long as the definition is not changed.
2. As a software vendor, you can just provide the customer with the header file and class object code without revealing the source code for implementing the class. This protects the software vendor’s intellectual property.

>[!Note]
To compile a main program from the command line, you need to add all its supporting files in the command. For example, to compile TestCircleWithHeader.cpp using a GNU C++ compiler, the command is

```cpp
g++ Circle.h Circle.cpp TestCircleWithHeader.cpp -o Main 
 
```

>[!Note]
If the main program uses other programs, all of these program source files must be present in the project pane in the IDE. Otherwise, you may get linking errors. For example, to run `TestCircleWithHeader.cpp`, you need to place `TestCircleWithHeader.cpp`, `Circle.cpp`, and `Circle.h` in the project pane in Visual C++, as shown in **Figure 9.5**.

## **Figure 9.5**
![[l497n0wi.bmp]]

## Self-Check
### How do you separate class definition from implementation?

Declare all data fields, constructors, and function prototypes in the interface and implement functions in a separate file.

### What is the output of the following code? (Use the Circle class defined in LiveExample 9.3, Circle.h.)

#### (a)
```cpp
int main() 
{
  Circle c1;
  Circle c2(6);
  c1 = c2;
  cout << c1.getArea() << endl;

  return 0;
}
```

#### (b)
```cpp
int main() 
{
  cout << Circle(8).getArea() 
    << endl;

  return 0;
}
```

(a) output is 5  
(b) Output is 8k
# References
