# Summary

# Learning Objectives

# Related
Prev - [[COSC Chapter 16.3 Exception Classes]]

Next - [[COSC Chapter 16.5 Multiple Catches]]
# Content

## Key Point

You can define custom [[exception]] classes to model exceptions that cannot be adequately represented using C++ [[standard exception]] classes.

C++ provides the [[exception]] classes listed in **Figure 16.1**. Use them whenever possible instead of creating your own [[exception]] classes. However, if you run into a problem that cannot be adequately described by the [[standard exception]] classes, you can create your own [[exception]] class. This class is just like any C++ class, but often it is desirable to derive it from `<exception>` or a [[derived class]] of `exception` so you can utilize the common features (e.g., the `what()` [[function]]) in the `exception` class.

Let us consider the `Triangle` class for modeling triangles. The class UML diagram is shown in **Figure 16.2**. The class is derived from the `GeometricObject` class, which is an abstract class introduced in **Section 15.9**, “Abstract Classes and Pure Virtual Functions.”

![[Pasted image 20241014235118.png]]

A triangle is valid if the sum of any two sides is greater than the third side. When you attempt to create a triangle, or change a side of a triangle, you need to ensure that this property is not violated. Otherwise, an [[exception]] should be thrown. You can define the `TriangleException` class as in **LiveExample 16.9** to model this [[exception]].

## **LiveExample 16.9 TriangleException.h**
```CPP
#ifndef TRIANGLEEXCEPTION_H
#define TRIANGLEEXCEPTION_H
#include <stdexcept>
using namespace std;

class TriangleException: public logic_error
{
public:
  TriangleException(double side1, double side2, double side3)
    : logic_error("Invalid triangle")
  {
    this->side1 = side1;
    this->side2 = side2;
    this->side3 = side3;
  }

  double getSide1() const
  {
    return side1;
  }

  double getSide2() const
  {
    return side2;
  }

  double getSide3() const
  {
    return side3;
  }

private:
  double side1, side2, side3;
}; // Semicolon required

#endif 
```

The `TriangleException` class describes a logic error, so it is appropriate to define this class to extend the standard `logic_error` class in line 6. Since `logic_error` is in the `<``stdexcept``>` header file, this header is included in line 3.

Recall that if a base constructor is not invoked explicitly, the [[base class]]’s no-arg constructor is invoked by default. However, since the [[base class]] `logic_error` does not have a no-arg constructor, you must invoke a [[base class]]’s constructor to avoid compile [[errors]] in line 10. Invoking `logic_error("Invalid triangle")` sets an error message, which can be returned from invoking `what()` on an `exception` object.

>[!Note]
>A custom [[exception]] class is just like a regular class. Extending from a [[base class]] is not necessary, but it is a good practice to extend from the standard `exception` or a [[derived class]] of `exception` so your custom [[exception]] class can use the functions from the standard classes.

>[!Note]
>The header file TriangleException.h contains the implementation for the class. Recall that this is the inline implementation. For short functions, using inline implementation is efficient.

The `Triangle` class can be implemented as follows in **LiveExample 16.10**.

#### **LiveExample 16.10 Triangle.h**
```CPP
#ifndef TRIANGLE_H
#define TRIANGLE_H
#include "AbstractGeometricObject.h" // Defined in Listing 15.13
#include "TriangleException.h"
#include <cmath>

class Triangle: public GeometricObject
{
public:
  Triangle()
  {
    side1 = side2 = side3 = 1;
  }

  Triangle(double side1, double side2, double side3)
  {
    if (!isValid(side1, side2, side3))
      throw TriangleException(side1, side2, side3);

    this->side1 = side1;
    this->side2 = side2;
    this->side3 = side3;
  }

  double getSide1() const
  {
    return side1;
  }

  double getSide2() const
  {
    return side2;
  }

  double getSide3() const
  {
    return side3;
  }

  void setSide1(double side1)
  {
    if (!isValid(side1, side2, side3))
      throw TriangleException(side1, side2, side3);

    this->side1 = side1;
  }

  void setSide2(double side2)
  {
    if (!isValid(side1, side2, side3))
      throw TriangleException(side1, side2, side3);

    this->side2 = side2;
  }

  void setSide3(double side3)
  {
    if (!isValid(side1, side2, side3))
      throw TriangleException(side1, side2, side3);

    this->side3 = side3;
  }

  double getPerimeter() const
  {
    return side1 + side2 + side3;
  }

  double getArea() const
  {
    double s = getPerimeter() / 2;
    return sqrt(s * (s - side1) * (s - side2) * (s - side3));
  }

private:
  double side1, side2, side3;

  bool isValid(double side1, double side2, double side3) const
  {
    return (side1 < side2 + side3) && (side2 < side1 + side3) &&
      (side3 < side1 + side2);
  }
};

#endif 
```

The `Triangle` class extends `GeometricObject` (line 7) and overrides the pure virtual functions `getPerimeter` and `getArea` defined in the `GeometricObject` class (lines 64–73).

The `isValid` [[function]] (lines 78–82) checks whether a triangle is valid. This [[function]] is defined private for use inside the `Triangle` class.

When constructing a `Triangle` object with three specified sides, the constructor invokes the `isValid` [[function]] (line 17) to check validity. If not valid, a `TriangleException` object is created and thrown in line 18. Validity also is checked when the functions `setSide1`, `setSide2`, and `setSide3` are invoked. When invoking `setSide1(side1)`, `isValid(side1, side2, side3)` is invoked. Here `side1` is the new `side1` to be set, not the current `side1` in the object.

**LiveExample 16.11** gives a test program that creates a `Triangle` object using its no-arg constructor (line 10), displays its perimeter and area (lines 11–12), and changes its `side3` to `4` (line 14), which causes a `TriangleException` to be thrown. The [[exception]] is caught in the `catch` block (lines 18–23).

## **LiveExample 16.11 TestTriangle.cpp**
```CPP
#include <iostream>
#include "AbstractGeometricObject.h"
#include "Triangle.h"
using namespace std;

int main()
{
  try
  {
    Triangle triangle;
    cout << "Perimeter is " << triangle.getPerimeter() << endl;
    cout << "Area is " << triangle.getArea() << endl;

    triangle.setSide3(4);
    cout << "Perimeter is " << triangle.getPerimeter() << endl;
    cout << "Area is " << triangle.getArea() << endl;
  }
  catch (TriangleException& ex)
  {
    cout << ex.what();
    cout << " three sides are " << ex.getSide1() << " "
      << ex.getSide2() << " " << ex.getSide3() << endl;
  }

  return 0;
}
```
```
command>cl TestTriangle.cpp
Microsoft C++ Compiler 2019 
Compiled successful (cl is the VC++ compile/link command)

command>TestTriangle 
Perimeter is 3
Area is 0.433013
Invalid triangle three sides are 1 1 4

command>
```

The `what()` [[function]] is defined in the `exception` class. Since `TriangleException` is derived from `logic_error`, which is derived from `exception`, you can invoke `what()` (line 20) to display an error message on a `TriangleException` object. The `TriangleException` object contains the information pertinent to a triangle. This information is useful for handling the [[exception]].

## Self-Check

### What is the benefit of defining a custom [[exception]] class to be derived from the [[exception]] class?

The benefit is to use the functions defined in the [[exception]] class and to handle the custom exceptions as a special case of the general [[exception]].

# References
