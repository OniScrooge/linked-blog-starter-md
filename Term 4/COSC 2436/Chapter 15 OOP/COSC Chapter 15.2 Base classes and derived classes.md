# Summary

# Learning Objectives

# Related
Prev - [[COSC Chapter 15.1 Introduction]]

Next - [[COSC Chapter 15.3 Generic Programming]]
# Content

## Key Point

[[Inheritance]] enables you to define a general class (i.e., a [[base class]]) and later extend it to more specialized classes (i.e., derived classes).

You use a class to model objects of the same type. Different classes may have some common properties and behaviors, which can be generalized in a class that can be shared by other classes. [[Inheritance]] enables you to define a general class and later extend it to more specialized ones. The specialized classes inherit properties and functions from the general class.

Consider geometric objects. Suppose you want to design the classes to model geometric objects like circles and rectangles. Geometric objects have many common properties and behaviors. They can be drawn in a certain color, filled or unfilled. Thus, a general class `GeometricObject` can be used to model all geometric objects. This class contains the properties `color` and `filled` and their appropriate `getter` and `setter` functions. Assume that this class also contains the `toString()` [[function]], which returns a string representation for the object. Since a circle is a special type of geometric object, it shares common properties and functions with other geometric objects. Thus, it makes sense to define the `Circle` class that extends the `GeometricObject` class. Likewise, `Rectangle` can also be defined as a [[derived class]] of `GeometricObject`. **Figure 15.1** shows the relationships among these classes. A triangle pointing to the [[base class]] is used to denote the [[inheritance]] relationship between the two classes involved.

![[Pasted image 20241014194305.png]]

The `GeometricObject` class is the [[base class]] for `Circle` and `Rectangle`.

In C++ terminology, a class `C1` extended from another class `C2` is called a [[derived class]], and `C2` is called a [[base class]]. We also refer to a [[base class]] as a [[parent class]] or a [[superclass]] and to a [[derived class]] as a [[child class]] or a [[subclass]]. A [[derived class]] inherits accessible data fields and functions from its [[base class]] and may also add new data fields and functions.

The `Circle` class inherits all accessible data fields and functions from the `GeometricObject` class. In addition, it has a new data field, `radius`, and its associated `getter` and `setter` functions. It also contains the `getArea``(``)`, `getPerimeter``(``)`, and `getDiameter()` functions for returning the area, perimeter, and diameter of the circle.

The `Rectangle` class inherits all accessible data fields and functions from the `GeometricObject` class. In addition, it has data fields `width` and `height` and its associated `getter` and `setter` functions. It also contains the `getArea``(``)` and `getPerimeter``(``)` functions for returning the area and perimeter of the rectangle.

The class declaration for `GeometricObject` is shown in **LiveExample 15.1**. The preprocessor directives in lines 1 and 2 guard against multiple declarations. The C++ `string` class header is included in line 3 to support the use of the `string` class in `GeometricObject`. The `isFilled``(``)` [[function]] is the accessor for the `filled` data field. Since this data field is the `bool` type, the accessor [[function]] is named `isFilled``(``)` by convention.

### **LiveExample 15.1 GeometricObject.h**
```CPP
#ifndef GEOMETRICOBJECT_H
#define GEOMETRICOBJECT_H
#include <string>
using namespace std;

class GeometricObject
{
public:
  GeometricObject();
  GeometricObject(const string& color, bool filled);
  string getColor() const;
  void setColor(const string& color);
  bool isFilled() const;
  void setFilled(bool filled);
  string toString() const; 

private:
  string color;
  bool filled;
}; // Must place semicolon here

#endif 
```

The `GeometricObject` class is implemented in **LiveExample 15.2**. The `toString` [[function]] (lines 35–38) returns a string that describes the object. The `string` operator `+` is used to concatenate two strings and returns a new `string` object.

### **LiveExample 15.2 GeometricObject.cpp**
```CPP
#include "GeometricObject.h"

GeometricObject::GeometricObject()
{
  color = "white";
  filled = false;
}

GeometricObject::GeometricObject(const string& color, bool filled)
{
  this->color = color;
  this->filled = filled;
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

The class definition for `Circle` is shown in **LiveExample 15.3**. Line 5 defines that the `Circle` class is derived from the [[base class]] `GeometricObject`. The syntax tells the compiler that the class is derived from the [[base class]]. So, all public members in `GeometricObject` are inherited in `Circle`.
![[Pasted image 20241014195012.png]]

### **LiveExample 15.3 DerivedCircle.h**
```CPP
#ifndef CIRCLE_H
#define CIRCLE_H
#include "GeometricObject.h"

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
  string toString() const;

private:
  double radius;
}; // Must place semicolon here

#endif
```

The `Circle` class is implemented in **LiveExample 15.4**.

### **LiveExample 15.4 DerivedCircle.cpp**
```CPP
#include "DerivedCircle.h"

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

// Construct a circle object with specified radius,
//  color and filled values
Circle::Circle(double radius, const string& color, bool filled)
{
  this->radius = radius;
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

// Redefine the toString function
string Circle::toString() const
{
  return "Circle object";
}
```

The constructor `Circle``(``double` `radius``,` `const` `string``&` `color``,` `bool` `filled``)` is implemented by invoking the `setColor` and `setFilled` functions to set the `color` and `filled` properties (lines 17–22). These two public functions are defined the [[base class]] `GeometricObject` and are inherited in `Circle`. So, they can be used in the [[derived class]].

You might attempt to use the data fields `color` and `filled` directly in the constructor as follows:

```cpp
Circle::Circle(double radius, const string& c, bool f) 
{ 
  this->radius = radius; // This is fine 
  color = c; // Illegal since color is private in the base class 
  filled = f; // Illegal since filled is private in the base class 
} 
```

This is wrong, because the private data fields `color` and `filled` in the `GeometricObject` class cannot be accessed in any class other than in the `GeometricObject` class itself. The only way to read and modify `color` and `filled` is through their `getter` and `setter` functions.

The class `Rectangle` is defined in **LiveExample 15.5**. Line 5 defines that the `Rectangle` class is derived from the [[base class]] `GeometricObject`. The syntax tells the compiler that the class is derived from the [[base class]]. So, all public members in `GeometricObject` are inherited in `Rectangle`

### **LiveExample 15.5 DerivedRectangle.h**
```CPP
#ifndef RECTANGLE_H
#define RECTANGLE_H
#include "GeometricObject.h"

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
  string toString() const;

private:
  double width;
  double height;
};  // Must place semicolon here

#endif
```

The `Rectangle` class is implemented in **LiveExample 15.6**.

### **LiveExample 15.6 DerivedRectangle.cpp**
```CPP
#include "DerivedRectangle.h"

// Construct a default rectangle object
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

Rectangle::Rectangle(
  double width, double height, const string& color, bool filled)
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

// Redefine the toString function, to be covered in Section 15.5
string Rectangle::toString() const
{
  return "Rectangle object";
}
```

**LiveExample 15.7** gives a test program that uses these three classes—`GeometricObject`, `Circle`, and `Rectangles`.

### **LiveExample 15.7 TestGeometricObject.cpp**
```CPP
#include "GeometricObject.h"
#include "DerivedCircle.h"
#include "DerivedRectangle.h"
#include <iostream>
using namespace std;

int main()
{
  GeometricObject shape;
  shape.setColor("red");
  shape.setFilled(true);
  cout << shape.toString() << endl
    << " color: " << shape.getColor()
    << " filled: " << (shape.isFilled() ? "true" : "false") << endl; 

  Circle circle(5);
  circle.setColor("black");
  circle.setFilled(false);
  cout << circle.toString()<< endl
    << " color: " << circle.getColor()
    << " filled: " << (circle.isFilled() ? "true" : "false") 
    << " radius: " << circle.getRadius()
    << " area: " << circle.getArea()
    << " perimeter: " << circle.getPerimeter() << endl;

  Rectangle rectangle(2, 3);
  rectangle.setColor("orange");
  rectangle.setFilled(true);
  cout << rectangle.toString()<< endl
	<< " color: " << rectangle.getColor()
    << " filled: " << (rectangle.isFilled() ? "true" : "false")
    << " width: " << rectangle.getWidth()
    << " height: " << rectangle.getHeight()
    << " area: " << rectangle.getArea()
    << " perimeter: " << rectangle.getPerimeter() << endl;

  return 0;
}
```

```
command>cl TestGeometricObject.cpp
Microsoft C++ Compiler 2019 
Compiled successful (cl is the VC++ compile/link command)

command>TestGeometricObject 
Geometric Object
 color: red filled: true
Circle object
 color: black filled: false radius: 5 area: 78.5397 perimeter: 31.4159
Rectangle object
 color: orange filled: true width: 2 height: 3 area: 6 perimeter: 10

command>
```

The program creates a `GeometricObject` and invokes its functions `setColor`, `setFilled`, `toString`, `getColor`, and `isFilled` in lines 9–14.

The program creates a `Circle`​ ​object and invokes its functions `setColor`, `setFilled`, `toString`, `getColor`, `isFilled`, `getRadius`, `getArea`, and `getPerimeter` in lines 16–24. Note that the `setColor` and `setFilled` functions are defined in the `GeometricObject` class and inherited in the `Circle` class.

The program creates a `Rectangle` object and invokes its functions `setColor`, `setFilled`, `toString`, `getColor`, `isFilled`, `getWidth`, `getHeight`, `getArea`, and `getPerimeter` in lines 26–35. Note that the `setColor` and `setFilled` functions are defined in the `GeometricObject` class and inherited in the `Rectangle` class.

Note the following points about [[inheritance]]:
- Private data fields in a [[base class]] are not accessible outside the class. Therefore, they cannot be used directly in a [[derived class]]. They can, however, be accessed/mutated through public accessor/mutator if defined in the [[base class]].
- Not all **is-a** relationships should be modeled using [[inheritance]]. For example, a square is a rectangle, but you should not define a `Square` class to extend a `Rectangle` class, because there is nothing to extend (or supplement) from a rectangle to a square. Rather you should define a `Square` class to extend the `GeometricObject` class. For class `A` to extend class `B`, `A` should contain more detailed information than `B`.
- [[Inheritance]] is used to model the _is-a_ relationship. Do not blindly extend a class just for the sake of reusing functions. For example, it makes no sense for a `Tree` class to extend a `Person` class, even though they share common properties such as height and weight. A [[derived class]] and its [[base class]] must have the _is-a_ relationship.
- C++ allows you to derive a [[derived class]] from several classes. This capability is known as multiple [[inheritance]], which is discussed in **Supplement IV.A**.

## Self-Check

### True or false? A [[derived class]] is a subset of a [[base class]].

False. A [[derived class]] is an extension of a [[base class]] and normally contains more details information than its [[base class]].

### Can a class be derived from multiple base classes in C++?

Yes.

### Identify the problems in the following classes.
```CPP
class Circle
{
public:
  Circle(double radius)
  {
    radius = radius;
  }

  double getRadius()
  {
    return radius;
  }

  double getArea()
  {
    return radius * radius * 3.14159;
  }

private:
  double radius;
};

class B : Circle
{
public:
  B(double radius, double length) 
  {
    radius = radius;
    length = length;
  }

  // Returns Circle's getArea * length 
  double getArea()
  {
    return getArea() * length;
  }

private:
  double length;
};
```

#### Answer
The following lines are erroneous:
```CPP
{  
  radius = radius; // Must use this->radius = radius
}

class B: Circle // Missing public

{  
  length = length; // Must use this->length = length
}

{
  Circle(radius);  // Must use super(radius)
  length = length; // Must use this.length = length
}

double getArea()
{
  return getArea() * length; // Must be Circle::getArea() * length
}
```


### What relationship is appropriate for the following classes? Draw the relationships using UML diagrams.

1. Company and Employee
2. Course and Faculty
3. Student and Person
4. House and Window
5. Account and Savings Account

#### Answer
1. Composition  
2. Composition  
3. [[Inheritance]]  
4. Composition  
5. [[Inheritance]]

# References
