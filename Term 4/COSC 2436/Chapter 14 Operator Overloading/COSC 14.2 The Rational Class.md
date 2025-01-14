# Summary

# Learning Objectives

# Related

# Content

## Key Point
This section defines the `Rational` class for modeling rational numbers.

A rational number has a numerator and a denominator in the form `a/b`, where `a` is the numerator and `b` is the denominator. For example, `1/3`, `3/4`, and `10/4` are rational numbers.

A rational number cannot have a denominator of `0`, but a numerator of `0` is fine. Every integer `i` is equivalent to a rational number `i/1`. Rational numbers are used in exact computations involving fractions—for example, `1/3` = `0.33333....` This number cannot be precisely represented in floating-point format using data type `double` or `float`. To obtain the exact result, we must use rational numbers.

​​​C++ provides data types for integers and floating-point numbers but not for rational numbers. This section shows how to design a class to represent rational numbers.​

A `Rational` number can be represented using two data fields: `numerator` and `denominator`. You can create a `Rational` number with specified numerator and denominator or create a default `Rational` number with numerator `0` and denominator `1`. You can add, subtract, multiply, divide, and compare rational numbers. You can also convert a rational number into an integer, floating-point value, or string. The UML class diagram for the `Rational` class is given in ​**Figure​ ​14.1**.​
![[Pasted image 20241007145154.png]]

A rational number consists of a numerator and a denominator. There are many equivalent rational numbers; for example, `1/3` = `2/6` = `3/9` = `4/12`. For convenience, we use `1/3` to represent all rational numbers that are equivalent to `1/3`. The numerator and the denominator of `1/3` have no common divisor except `1`, so `1/3` is said to be in _lowest terms_.

To reduce a rational number to its lowest terms, you need to find the greatest common divisor (GCD) of the absolute values of its numerator and denominator and then divide both numerator and denominator by this value. You can use the function for computing the GCD of two integers `n` and `d`, as suggested in **Listing 5.8**, GreatestCommonDivisor.cpp. The numerator and denominator in a `Rational` object are reduced to their lowest terms.

As usual, we first write a test program to create `Rational` objects and test the functions in the `Rational` class. **LiveExample 14.1** shows the header file for the `Rational` class, and **LiveExample 14.2** is a test program.
```C++
#ifndef RATIONAL_H
#define RATIONAL_H
#include <string>
using namespace std;

class Rational
{
public:
  Rational();
  Rational(int numerator, int denominator);
  int getNumerator() const;
  int getDenominator() const;
  Rational add(const Rational& secondRational) const;
  Rational subtract(const Rational& secondRational) const;
  Rational multiply(const Rational& secondRational) const;
  Rational divide(const Rational& secondRational) const;
  int compareTo(const Rational& secondRational) const;
  bool equals(const Rational& secondRational) const;
  int intValue() const;
  double doubleValue() const;
  string toString() const;

private:
  int numerator;
  int denominator;
  static int gcd(int n, int d);
};

#endif
```

**LiveExample 14.2 TestRationalClass.cpp**
```C++
#include <iostream>
#include "Rational.h"
using namespace std;

int main()
{
  // Create and initialize two rational numbers r1 and r2.
  Rational r1(4, 2);
  Rational r2(2, 3);

  // Test toString, add, subtract, multiply, and divide
  cout << r1.toString() << " + " << r2.toString() << " = "
    << r1.add(r2).toString() << endl;
  cout << r1.toString() << " - " << r2.toString() << " = "
    << r1.subtract(r2).toString() << endl;
  cout << r1.toString() << " * " << r2.toString() << " = "
    << r1.multiply(r2).toString() << endl;
  cout << r1.toString() << " / " << r2.toString() << " = "
    << r1.divide(r2).toString() << endl;

  // Test intValue and double
  cout << "r2.intValue()" << " is " << r2.intValue() << endl;
  cout << "r2.doubleValue()" << " is " << r2.doubleValue() << endl;

  // Test compareTo and equal
  cout << "r1.compareTo(r2) is " << r1.compareTo(r2) << endl;
  cout << "r2.compareTo(r1) is " << r2.compareTo(r1) << endl;
  cout << "r1.compareTo(r1) is " << r1.compareTo(r1) << endl;
  cout << "r1.equals(r1) is " 
       << (r1.equals(r1) ? "true" : "false") << endl;
  cout << "r1.equals(r2) is " 
       << (r1.equals(r2) ? "true" : "false") << endl;

  return 0;
}
```

```
command>cl TestRationalClass.cpp
Microsoft C++ Compiler 2019 
Compiled successful (cl is the VC++ compile/link command)

command>TestRationalClass 
2 + 2/3 = 8/3
2 - 2/3 = 4/3
2 * 2/3 = 4/3
2 / 2/3 = 3
r2.intValue() is 0
r2.doubleValue() is 0.666667
r1.compareTo(r2) is 1
r2.compareTo(r1) is -1
r1.compareTo(r1) is 0
r1.equals(r1) is true
r1.equals(r2) is false

command>
```

The `main` function creates two rational numbers, `r1` and `r2` (lines 8−9), and displays the results of `r1 + r2`, `r1 - r2`, `r1 x r2`, and `r1 / r2` (lines 12−19). To perform `r1 + r2`, invoke `r1.add(r2)` to return a new `Rational` object. Similarly, `r1.subtract(r2)` returns a new `Rational` object for `r1 - r2`, `r1.multiply(r2)` for `r1 x r2` , and `r1.divide(r2)` for `r1 / r2`.

The `intValue()` function displays the `int` value of `r2` (line 22). The `doubleValue()` function displays the `double` value of `r2` (line 23).

Invoking `r1.compareTo(r2)` (line 26) returns `1`, since `r1` is greater than `r2`. Invoking `r2.compareTo(r1)` (line 27) returns `-1`, since `r2` is less than `r1`. Invoking `r1.compareTo(r1)` (line 28) returns `0`, since `r1` is equal to `r1`. Invoking `r1.equals(r1)` (line 29) returns `true`, since `r1` is equal to `r1`. Invoking `r1.equals(r2)` (line 30) returns `false`, since `r1` are `r2` are not equal.

The `Rational` class is implemented in ​**LiveExample ​14.3​**.
```C++
#include "Rational.h"
#include <cstdlib> // For the abs function

Rational::Rational()
{
  numerator = 0;
  denominator = 1;
}

Rational::Rational(int numerator, int denominator)
{
  int factor = gcd(numerator, denominator);
  this->numerator = ((denominator > 0) ? 1 : -1) * numerator / factor;
  this->denominator = abs(denominator) / factor;
}

int Rational::getNumerator() const
{
  return numerator;
}

int Rational::getDenominator() const
{
  return denominator;
}

// Find GCD of two numbers 
int Rational::gcd(int n, int d) 
{
  int n1 = abs(n);
  int n2 = abs(d);
  int gcd = 1;

  for (int k = 1; k <= n1 && k <= n2; k++)
  {
    if (n1 % k == 0 && n2 % k == 0)
      gcd = k;
  }

  return gcd;
}

Rational Rational::add(const Rational& secondRational) const
{
  int n = numerator * secondRational.getDenominator() +
    denominator * secondRational.getNumerator();
  int d = denominator * secondRational.getDenominator();
  return Rational(n, d);
}

Rational Rational::subtract(const Rational& secondRational) const
{
  int n = numerator * secondRational.getDenominator()
    - denominator * secondRational.getNumerator();
  int d = denominator * secondRational.getDenominator();
  return Rational(n, d);
}

Rational Rational::multiply(const Rational& secondRational) const
{
  int n = numerator * secondRational.getNumerator();
  int d = denominator * secondRational.getDenominator();
  return Rational(n, d);
}

Rational Rational::divide(const Rational& secondRational) const
{
  int n = numerator * secondRational.getDenominator();
  int d = denominator * secondRational.numerator;
  return Rational(n, d);
}

int Rational::compareTo(const Rational& secondRational) const
{
  Rational temp = subtract(secondRational);
  if (temp.getNumerator() < 0)
    return -1;
  else if (temp.getNumerator() == 0)
    return 0;
  else
    return 1;
}

bool Rational::equals(const Rational& secondRational) const
{
  if (compareTo(secondRational) == 0)
    return true;
  else
    return false;
}

int Rational::intValue() const
{
  return getNumerator() / getDenominator();
}

double Rational::doubleValue() const
{
  return 1.0 * getNumerator() / getDenominator();
}

string Rational::toString() const
{
  if (denominator == 1)
    return to_string(numerator); // See Ch7 for to_string
  else
    return  to_string(numerator) + "/" + to_string(denominator);
}
```

The rational number is encapsulated in a `Rational` object. Internally, a rational number is represented in its lowest terms (lines 13−14), and the numerator determines its sign (line 13). The denominator is always positive (line 14).

The `gcd()` function (lines 28−41) is private; it is not intended for use by clients. The `gcd()` function is only for internal use by the `Rational` class. The `gcd()` function is also static, since it is not dependent on any particular `Rational` object.

Two `Rational` objects can interact with each other to perform addition, subtraction, multiplication, and division operations. These methods return a new `Rational` object (lines 43–71). The math formula for performing these operations are as follows:

1. $​a/b + c/d = (ad + bc)/(bd) (e.g., 2/3 + 3/4 = (2*4 + 3*3)/(3*4) = 17/12)​$
2. $​a/b - c/d = (ad - bc)/(bd) (e.g., 2/3 - 3/4 = (2*4 - 3*3)/(3*4) = -1/12)​$
3. $a/b * c/d = (ac)/(bd) (e.g., 2/3 * 3/4 = (2*3)/(3*4) = 6/12 = 1/2)$
4. $a/b / c/d = (ad)/(bc) (e.g., (2/3) / (3/4) = (2*4)/(3*3) = 8/9)$

The `abs(x)` function (lines 30−31) is defined in the standard C++ library that returns the absolute value of `x`.

Two `Rational` objects can perform add, subtract, multiply, and divide operations. These functions return a new `Rational` object (lines 43−71).

The `compareTo(&secondRational)` function (lines 73−82) compares this rational number to the other rational number. It first subtracts the second rational from this rational and saves the result in `temp` (line 75). Return `-1`, `0`, or `1`, if `temp`’s numerator is less than, equal to, or greater than `0`.

The `equals(&secondRational)` function (lines 84−90) utilizes the `compareTo` function to compare this rational number to the other one. If this function returns `0`, the `equals` function returns `true`; otherwise, it returns `false`.

The functions `intValue` and `doubleValue` return an `int` and a `double` value, respectively, for this rational number (lines 92−100).

The `toString()` function (lines 102−108) returns a string representation of a `Rational` object in the form `numerator/denominator` or simply `numerator` if `denominator` is `1`. The `to_string` is new in C++11, which is introduced in ​**Section​ ​7.12**​.

>[!Tip]
The numerator and denominator are represented using two variables. We can represent them also using an array of two integers. See **Programming Exercise 14.2**. The signatures of the public functions in the `Rational` class are not changed, although the internal representation of a rational number is changed. This is a good illustration of the idea that the data fields of a class should be kept private so as to _encapsulate_ the implementation of the class from the use of the class.

## Self-Check

### Trace the program carefully and show the output of the following code.
```C++
Rational r1(1, 2);
Rational r2(1, -2);
cout << r1.add(r2).toString() << endl;
```
#### Answer
0 / 4

### The preceding question shows a bug in the `toString` function. Revise the `toString()` function to fix the error.
```
string Rational::toString() const
{
  if (numerator == 0)
    return "0";
  else if (denominator == 1)
    return to_string(numerator); // See Ch7 for to_string
  else
    return to_string(numerator) + "/" + to_string(denominator);
}
```

### What happens if you create a Rational using Rational(1, 0)? Discuss the appropriate ways for handling this case.

Rational(1, 0) would create a Rational with denominator 0. The best way to handle this case is to throw an exception when denominator is 0.

### What statement creates a default Rational object?

`Rational r1;`

### What will be displayed by the following code?

```C++
  #include <iostream> 
  #include "Rational.h"
  using namespace std;
  int main()
{
    cout << Rational().toString();
	return 0;
}
```

#### Answer
0

### What will be displayed by the following code?

```C++
#include <iostream>
#include "Rational.h"
using namespace std;
int main()
{
	Rational r1(1, 2);
    Rational r2(2, 4);
	cout << r1.equals(r2);
	return 0;
}
```

#### Answer
1

# References
