# Summary

# Learning Objectives

# Related
Prev - [[COSC Chapter 15.9 The protected keyword]]

Next - [[COSC Chapter 15.11 Casting static_cast versus dynamic_cast]]
# Content

## Key Point

An abstract class cannot be used to create objects. An abstract class can contain abstract functions, which are implemented in concrete derived classes.

In the [[inheritance]] hierarchy, classes become more specific and concrete _with each new [[derived class]]_. If you move from a [[derived class]] back up to its parent and ancestor classes, the classes become more general and less specific. Class design should ensure that a [[base class]] contains common features of its derived classes. Sometimes a [[base class]] is so abstract that it cannot have any specific instances. Such a class is referred to as an [abstract class](https://revel-ise.pearson.com/courses/66e7050d84448f59a62c6945/assignments/711c7caf-6fd2-4d48-b657-33274573990d/pages/urn:pearson:entity:39d01509-56c8-48b2-9cc5-3f5ead74c6a7?source=dashboard#).

In **Section 15.2**, `GeometricObject` was defined as the [[base class]] for `Circle` and `Rectangle`. `GeometricObject` models common features of geometric objects. Both `Circle` and `Rectangle` contain the `getArea()` and `getPerimeter()` functions for computing the area and perimeter of a circle and a rectangle. Since you can compute areas and perimeters for all geometric objects, it is better to define the `getArea()` and `getPerimeter()` functions in the `GeometricObject` class. However, these functions cannot be implemented in the `GeometricObject` class, because their implementation is dependent on the specific type of geometric object. Such functions are referred to as [abstract functions](https://revel-ise.pearson.com/courses/66e7050d84448f59a62c6945/assignments/711c7caf-6fd2-4d48-b657-33274573990d/pages/urn:pearson:entity:39d01509-56c8-48b2-9cc5-3f5ead74c6a7?source=dashboard#). After you define the abstract functions in `GeometricObject`, `GeometricObject` becomes an abstract class. The new `GeometricObject` class is shown in **Figure 15.3**. In UML graphic notation, the names of abstract classes and their abstract functions are italicized, as shown in **Figure 15.3**.

>[!info] Figure 15.3
>![[Pasted image 20241014224240.png]]
>


In C++, abstract functions are called pure virtual functions. A class that contains pure virtual functions becomes an abstract class. A [[pure virtual function]] is defined this way:
![[Pasted image 20241014224358.png]]

The `=` `0` notation indicates that `getArea` is a [[pure virtual function]]. A [[pure virtual function]] does not have a body or implementation in the [[base class]].

**LiveExample 15.16** defines the new abstract `GeometricObject` class with two pure virtual functions in lines 18–19.

## **LiveExample 15.16 AbstractGeometricObject.h**
```CPP
#ifndef GEOMETRICOBJECT_H
#define GEOMETRICOBJECT_H
#include <string>
using namespace std;

class GeometricObject
{
protected:
  GeometricObject();
  GeometricObject(const string& color, bool filled);

public:
  string getColor() const;
  void setColor(const string& color);
  bool isFilled() const;
  void setFilled(bool filled);
  string toString() const;
  virtual double getArea() const = 0;
  virtual double getPerimeter() const = 0;

private:
  string color;
  bool filled;
}; // Must place semicolon here

#endif
```

`GeometricObject` is just like a regular class, except that you cannot create objects from it because it is an abstract class. If you attempt to create an object from `GeometricObject,` the compiler will report an error.

**LiveExample 15.17** gives an implementation of the `GeometricObject` class.

## **LiveExample 15.17 AbstractGeometricObject.cpp**
```CPP
#include "AbstractGeometricObject.h"

GeometricObject::GeometricObject()
{
  color = "white";
  filled = false;
}

GeometricObject::GeometricObject(const string& color, bool filled)
{
  setColor(color);
  setFilled(filled);
}

string GeometricObject::getColor() const
{
  return color;
}

void GeometricObject::setColor(const string& color)
{
  this->color = color;
}

bool GeometricObject::isFilled() const
{
  return filled;
}

void GeometricObject::setFilled(bool filled)
{
  this->filled = filled;
}

string GeometricObject::toString() const
{
  return "Geometric Object";
}
```

**LiveExamples 15.15**, **15.16**, **15.17**, and **15.18** show the files for the new `Circle` and `Rectangle` classes derived from the abstract `GeometricObject`.

## **LiveExample 15.18 DerivedCircleFromAbstractGeometricObject.h**
```CPP
#ifndef CIRCLE_H
#define CIRCLE_H
#include "AbstractGeometricObject.h"

class Circle: public GeometricObject
{
public:
  Circle();
  Circle(double);
  Circle(double radius, const string& color, bool filled);
  double getRadius() const;
  void setRadius(double);
  double getArea() const;
  double getPerimeter() const;
  double getDiameter() const;

private:
  double radius;
};  // Must place semicolon here

#endif
```

## **LiveExample 15.19 DerivedCircleFromAbstractGeometricObject.cpp**
```CPP
#include "DerivedCircleFromAbstractGeometricObject.h"

// Construct a default circle object
Circle::Circle()
{
  radius = 1;
}

// Construct a circle object with specified radius
Circle::Circle(double radius)
{
  setRadius(radius);
}

// Construct a circle object with specified radius, color, filled 
Circle::Circle(double radius, const string& color, bool filled)
{
  setRadius(radius);
  setColor(color);
  setFilled(filled);
}

// Return the radius of this circle
double Circle::getRadius() const
{
  return radius;
}

// Set a new radius
void Circle::setRadius(double radius)
{
  this->radius = (radius >= 0) ? radius : 0;
}

// Return the area of this circle
double Circle::getArea() const
{
  return radius * radius * 3.14159;
}

// Return the perimeter of this circle
double Circle::getPerimeter() const
{
  return 2 * radius * 3.14159;
}

// Return the diameter of this circle
double Circle::getDiameter() const
{
  return 2 * radius;
}
```

## **LiveExample 15.20 DerivedRectangleFromAbstractGeometricObject.h**
```CPP
#ifndef RECTANGLE_H
#define RECTANGLE_H
#include "AbstractGeometricObject.h"

class Rectangle: public GeometricObject
{
public:
  Rectangle();
  Rectangle(double width, double height);
  Rectangle(double width, double height, 
    const string& color, bool filled);
  double getWidth() const;
  void setWidth(double);
  double getHeight() const;
  void setHeight(double);
  double getArea() const;
  double getPerimeter() const;

private:
  double width;
  double height;
};  // Must place semicolon here

#endif
```

## **LiveExample 15.21 DerivedRectangleFromAbstractGeometricObject.cpp**
```CPP
#include "DerivedRectangleFromAbstractGeometricObject.h"

// Construct a default retangle object
Rectangle::Rectangle()
{
  width = 1;
  height = 1;
}

// Construct a rectangle object with specified width and height
Rectangle::Rectangle(double width, double height)
{
  setWidth(width);
  setHeight(height);
}

// Construct a rectangle object with width, height, color, filled
Rectangle::Rectangle(double width, double height, 
  const string& color, bool filled)
{
  setWidth(width);
  setHeight(height);
  setColor(color);
  setFilled(filled);
}

// Return the width of this rectangle
double Rectangle::getWidth() const
{
  return width;
}

// Set a new radius
void Rectangle::setWidth(double width)
{
  this->width = (width >= 0) ? width : 0;
}

// Return the height of this rectangle
double Rectangle::getHeight() const
{
  return height;
}

// Set a new height
void Rectangle::setHeight(double height)
{
  this->height = (height >= 0) ? height : 0;
}

// Return the area of this rectangle
double Rectangle::getArea() const
{
  return width * height;
}

// Return the perimeter of this rectangle
double Rectangle::getPerimeter() const
{
  return 2 * (width + height);
}
```

You may be wondering whether the abstract functions `getArea` and `getPerimeter` should be removed from the `GeometricObject` class. The following example in **LiveExample 15.22** shows the benefits of defining them in the `GeometricObject` class.

This example presents a program that creates two geometric objects (a circle and a rectangle), invokes the `equalArea` [[function]] to check whether the two objects have equal areas, and invokes the `displayGeometricObject` [[function]] to display the objects.

## **LiveExample 15.22 TestAbstractGeometricObject.cpp**
```CPP
#include "AbstractGeometricObject.h"
#include "DerivedCircleFromAbstractGeometricObject.h"
#include "DerivedRectangleFromAbstractGeometricObject.h"
#include <iostream>
using namespace std;

// A function for comparing the areas of two geometric objects
bool equalArea(const GeometricObject& g1,
  const GeometricObject& g2)
{
  return g1.getArea() == g2.getArea();
}

// A function for displaying a geometric object
void displayGeometricObject(const GeometricObject& g)
{
  cout << "The area is " << g.getArea() << endl;
  cout << "The perimeter is " << g.getPerimeter() << endl;
}

int main()
{
  Circle circle(5);
  Rectangle rectangle(5, 3);

  cout << "Circle info: " << endl;
  displayGeometricObject(circle);

  cout << "\nRectangle info: " << endl;
  displayGeometricObject(rectangle);

  cout << "\nThe two objects have the same area? " <<
    (equalArea(circle, rectangle) ? "Yes" : "No") << endl;

  return 0;
}
```
```
command>cl TestAbstractGeometricObject.cpp
Microsoft C++ Compiler 2019 
Compiled successful (cl is the VC++ compile/link command)

command>TestAbstractGeometricObject 
Circle info: 
The area is 78.5397
The perimeter is 31.4159

Rectangle info: 
The area is 15
The perimeter is 16

The two objects have the same area? No

command>
```

The program creates a `Circle` object and a `Rectangle` object in lines 23–24.

The pure virtual functions `getArea``(``)` and `getPerimeter``(``)` defined in the `Geometric``Object` class are overridden in the `Circle` class and the `Rectangle` class.

When invoking `displayGeometricObject(circle)` (line 27), the functions `getArea` and `getPerimeter` defined in the `Circle` class are used, and when invoking `displayGeometricObject(rectangle)` (line 30), the functions `getArea` and `getPerimeter` defined in the `Rectangle` class are used. C++ dynamically determines which of these functions to invoke at runtime, depending on the type of object.

Similarly, when invoking `equalArea(circle, rectangle)` (line 33), the `getArea` [[function]] defined in the `Circle` class is used for `g1.getArea()`, since `g1` is a circle. Also, the `getArea` [[function]] defined in the `Rectangle` class is used for `g2.getArea()`, since `g2` is a rectangle.

Note that if the `getArea` and `getPerimeter` functions were not defined in `GeometricObject`, you cannot define the `equalArea` and `displayGeometricObject` functions in this program. So, you now see the benefits of defining the abstract functions in `GeometricObject`.

## Self-Check

### How do you define a [[pure virtual function]]?

Just like a [[virtual function]] except that you have to add

= 0;

at the end of the [[function]] prototype.

### What is wrong in the following code?

```CPP
class A
{
public:
  virtual void f() = 0;
};

int main()
{
  A a;

  return 0;
}
```

A is an abstract class. You cannot create an instance from an abstract class.

### Can you compile and run the following code? What will be the output?

```CPP
#include <iostream>
using namespace std;

class A
{
public:
  virtual void f() = 0;
};

class B: public A
{
public:
  void f()
  {
    cout << "invoke f from B" << endl;
  }
};

class C: public B
{
public:
  virtual void m() = 0;
};

class D: public C
{
public:
  virtual void m()
  {
    cout << "invoke m from D" << endl;
  }
};

void p(A& a)
{
  a.f();
}

int main()
{
  D d;
  p(d);
  d.m();

  return 0;
}
```

- invoke f from B
- invoke m from D 

### The getArea and getPerimeter functions may be removed from the GeometricObject class. What are the benefits of defining getArea and getPerimeter as abstract functions in the GeometricObject class?

The benefits are for [[generic programming]]. A variable of GeometricObject type can use the getArea and getPerimeter functions at compilation time.

# References
