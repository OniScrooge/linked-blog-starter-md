# Summary

# Learning Objectives

# Related
Prev - [[COSC Chapter 16.4 Custom Exception Classes]]

Next - [[COSC Chapter 16.6 Exception Handling]]
# Content
## Key Point

A `try`-`catch` block may contain multiple catch clauses to deal with different exceptions thrown in the `try` clause. 

Usually a `try` block should run without exceptions. Occasionally, though, it may throw an [[exception]] of one type or another. For example, a nonpositive value for a side in a triangle in **LiveExample 16.11** may be considered a type of [[exception]] different from a `TriangleException`. So, the `try` block may throw a nonpositive-side [[exception]] or a `TriangleException`, depending on the occasion. One `catch` block can catch only one type of [[exception]]. C++ allows you to add multiple `catch` blocks after a `try` block in order to catch multiple types of exceptions.

Let us revise the example in the preceding section by creating a new [[exception]] class named `NonPositiveSideException` and incorporating it in the `Triangle` class. The `NonPositiveSideException` class is shown in **LiveExample 16.12** and the new `Triangle` class in **LiveExample 16.13**.

## **LiveExample 16.12 NonPositiveSideException.h**
```CPP
#ifndef NonPositiveSideException_H
#define NonPositiveSideException_H
#include <stdexcept>
using namespace std;

class NonPositiveSideException: public logic_error
{
public:
  NonPositiveSideException(double side)
    : logic_error("Non-positive side")
  {
    this->side = side;
  }

  double getSide()
  {
    return side;
  }

private:
  double side;
};

#endif 
```

The `NonPositiveSideException` class describes a logic error, so it is appropriate to define this class to extend the standard `logic_error` class in line 6.

## **LiveExample 16.13 NewTriangle.h**
```CPP
#ifndef TRIANGLE_H
#define TRIANGLE_H
#include "GeometricObject.h"
#include "TriangleException.h"
#include "NonPositiveSideException.h"
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
    check(side1);
    check(side2);
    check(side3);

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
    check(side1);
    if (!isValid(side1, side2, side3))
      throw TriangleException(side1, side2, side3);

    this->side1 = side1;
  }

  void setSide2(double side2)
  {
    check(side2);
    if (!isValid(side1, side2, side3))
      throw TriangleException(side1, side2, side3);

    this->side2 = side2;
  }

  void setSide3(double side3)
  {
    check(side3);
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

  void check(double side) const
  {
    if (side <= 0)
      throw NonPositiveSideException(side);
  }
};

#endif 
```

The new `Triangle` class is identical to the one in **LiveExample 16.10**, except that it also checks nonpositive sides. When a `Triangle` object is created, all of its sides are checked by invoking the `check` [[function]] (lines 18–20). The `check` [[function]] checks whether a side is nonpositive (line 94); it throws a `NonPositiveSideException` (line 95).

**LiveExample 16.14** gives a test program that prompts the user to enter three sides (lines 12–14) and creates a `Triangle` object (line 15).

## **LiveExample 16.14 MultipleCatchDemo.cpp**
```CPP
#include <iostream>
#include "AbstractGeometricObject.h"
#include "NonPositiveSideException.h"
#include "NewTriangle.h"

using namespace std;

int main()
{
  try
  {
    cout << "Enter three sides: ";
    double side1, side2, side3;
    cin >> side1 >> side2 >> side3;
    Triangle triangle(side1, side2, side3);
    cout << "Perimeter is " << triangle.getPerimeter() << endl;
    cout << "Area is " << triangle.getArea() << endl;
  }
  catch (NonPositiveSideException& ex)
  {
    cout << ex.what();
    cout << " the side is " << ex.getSide() << endl;
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
command>cl MultipleCatchDemo.cpp
Microsoft C++ Compiler 2019 
Compiled successful (cl is the VC++ compile/link command)

command>MultipleCatchDemo 
Enter three sides: 1.5 1.5 7.6
Invalid triangle three sides are 1.5 1.5 7.6

command>
```

If you enter three sides `2`, `2.5`, and `2.5`, it is a legal triangle. The program displays the perimeter and area of the triangle (lines 16–17). If you enter `-1`, `1`, and `1`, the constructor (line 15) throws a `NonPositiveSideException`. This [[exception]] is caught by the `catch` block in line 19 and processed in lines 21–22. If you enter `1`, `2`, and `1`, the constructor (line 15) throws a `TriangleException`. This [[exception]] is caught by the `catch` block in line 24 and processed in lines 26–28.

>[!Note]
>Various [[exception]] classes can be derived from a common [[base class]]. If a `catch` block catches [[exception]] objects of a [[base class]], it can catch all the [[exception]] objects of the derived classes of that [[base class]].

>[!Note]
>The order in which exceptions are specified in `catch` blocks is important. A `catch` block for a [[base class]] type should appear after a `catch` block for a [[derived class]] type. Otherwise, the [[exception]] of a [[derived class]] is always caught by the catch block for the [[base class]]. For example, the ordering in (a) below is erroneous, because `TriangleException` is a [[derived class]] of `logic_error`. The correct ordering should be as shown in (b). In (a), a `TriangleException` occurred in the `try` block is caught by the `catch` block for `logic_error`.
>![[Pasted image 20241015000124.png]]
>![[Pasted image 20241015000139.png]]

You may use an ellipsis `(...)` as the parameter of `catch`, which will catch any [[exception]] no matter what the type of the [[exception]] that was thrown. This can be used as a default handler that catches all exceptions not caught by other handlers if it is specified at last as shown in the following example:
![[Pasted image 20241015000236.png]]

## Self-Check

### Can you throw multiple exceptions in one throw statement? Can you have multiple catch blocks in a try-catch block?

Can you throw multiple exceptions in one throw statement? No.  
Can you have multiple catch blocks in a try-catch block? Yes.

### Suppose that statement2 causes an [[exception]] in the following try-catch block:

```CPP
try 
{
  statement1;
  statement2;
  statement3;
}
catch (Exception1& ex1)
{
}
catch (Exception2& ex2) 
{
}

statement4;
```

Answer the following questions:  
1. Will statement3 be executed?  
2. If the [[exception]] is not caught, will statement4 be executed?  
3. If the [[exception]] is caught in the catch block, will statement4 be executed?  
4. If the [[exception]] is passed to the caller, will statement4 be executed?  

#### Answer

1. No.  
2. No.  
3. Yes.  
4. No.

# References
