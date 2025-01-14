# Summary

# Learning Objectives

# Related
Prev - [[COSC Chapter 9.6 Separating Class Definition from Implementation]]

Next - [[COSC Chapter 9.8 Inline Functions in Classes]]
# Content
## Key Point
Inclusion guard prevents header files to be included multiple times.

It is a common mistake to include, inadvertently, the same header file in a program multiple times. Suppose `Head.h` includes `Circle.h` and TestHead.cpp includes both `Head.h` and `Circle.h`, as shown in ​**LiveExample ​9.6​** and **LiveExample 9.7**.

## **LiveExample 9.6 Head.h**
```cpp
#include "Circle.h" // Include Circle.h
// Other code in Head.h omitted
```

## **LiveExample 9.7 TestHead.cpp**
```cpp
#include "Circle.h" // Include Circle.h
#include "Head.h" // Include Head.h

int main()
{
  // Other code in TestHead.cpp omitted
}
```

If you compile TestHead.cpp, you will get a compile error indicating that there are multiple definitions for `Circle`. What is wrong here? Recall that the C++ preprocessor inserts the contents of the header file at the position where the header is included. `Circle.h` is included in line 1. Since the header file for `Circle` is also included in `Head.h` (see line 1 in **LiveExample 9.6**), the preprocessor will add the definition for the `Circle` class another time as result of including `Head.h` in TestHead.cpp, which causes the multiple-inclusion errors.

The C++ `#ifndef` directive along with the `#define` directive can be used to prevent a header file from being included multiple times. This is known as [inclusion guard](https://revel-ise.pearson.com/courses/66e7050d84448f59a62c6945/pages/urn:pearson:entity:6927b7bd-6d5c-4012-87e9-9094af490a4a?source=dashboard#). To make this work, you have to add three lines (lines 1-2, 20) in ​**LiveExample ​​9.8**.​

## **LiveExample 9.8 CircleWithInclusionGuard.h**
```cpp
#ifndef CIRCLE_H
#define CIRCLE_H

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

#endif
```

Recall that the statements preceded by the pound sign (`#`) are preprocessor directives. They are interpreted by the C++ preprocessor. The preprocessor directive `#ifndef` stands for “_if n_ot _def_ined.” Line 1 tests whether the symbol `CIRCLE_H` is already defined. If not, define the symbol in line 2 using the `#define` directive and the rest of the header file is included; otherwise, the rest of the header file is skipped. The `#endif` directive is needed to indicate the end of header file.

To avoid multiple-inclusion errors, define a class using the following template and convention for naming the symbol:

```
  #ifndef ClassName_H  #define ClassName_H    A class header for the class named ClassName is declared here     #endif
```

​​​​​If you replace Circle.h by CircleWithInclusionGuard.h in **LiveExamples ​9.6** ​and​ **9.7**​, the program will not have the multiple-inclusion error.​

## Self-Check
### What might cause multiple-inclusion errors? How do you prevent multiple inclusions of header files?
If your program include two header files and one of which actually include the other, then your program will receive the multiple declaration error. To prevent it, use the #ifndef directive.

### What is the #define directive for?
The #define directive defines a constant.
# References
