# Summary

# Learning Objectives

# Related

# Content

This section revises the `Rational` class with overloaded function operators. 

​​​​​​​​​​​The preceding sections introduced how to overload function operators. The following points are worth noting:​​​
- Conversion functions from a class type to a primitive type or from a primitive type to a class type cannot both be defined in the same class. Doing so would cause ambiguity errors, because the compiler cannot decide which conversion to perform. Often converting from a primitive type to a class type is more useful. So, we will define our `Rational` class to support automatic conversion from a primitive type to the `Rational` type.
- Most operators can be overloaded either as member or non-member functions. The `++`, `--`, `+=`, `-=`, `*=`, `/=`, `%=`, `=`, and `[]` operators must be overloaded as member functions and `<<` and `>>` operators must be overloaded as nonmember functions.
- The binary `+`, `-`, `*`, `%`, `/`, `<`, `<=`, `==`, `!=`, `>`, and `>=` operators should be overloaded as nonmember functions to enable automatic type conversion with symmetric operands.
- If you want the returned object to be used as an [[lvalue]] (i.e., used on the left-hand side of the assignment statement), you need to define the function to return a reference. The augmented assignment operators `+=`, `-=`, `*=`, `/=`, and `%=`, the prefix `++` and `−−` operators, the subscript operator `[]`, and the assignment operators `=` are [[lvalue]] operators.

**LiveExample 14.7** gives a new header file named RationalWithOperators.h for the `Rational` class with function operators. Lines 10−22 in the new file are the same as in **LiveExample 14.1** Rational.h. The functions for augmented assignment operators (`+=`, `-=`, `*=`, `/=`), subscript operator `[]`, prefix `++`, and prefix `--` are defined to return a reference (lines 27−37). The stream extraction `>>` and stream insertion `<<` operators are defined in lines 48−49. The nonmember functions for comparison operators (`<`, `<=`, `>`, `>=`, `==`, `!=`) and arithmetic operators (`+`, `-`, `*`, `/`) are defined in lines 57−69.
```CPP
#ifndef RATIONALWITHOPERATORS_H
#define RATIONALWITHOPERATORS_H
#include <string>
#include <iostream>
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

  Rational(int numerator); // Suitable for type conversion 

  // Define function operators for augmented operators
  Rational& operator+=(const Rational& secondRational);
  Rational& operator-=(const Rational& secondRational);
  Rational& operator*=(const Rational& secondRational);
  Rational& operator/=(const Rational& secondRational);

  // Define function operator []
  int& operator[](int index);

  // Define function operators for prefix ++ and --
  Rational& operator++();
  Rational& operator--();

  // Define function operators for postfix ++ and --
  Rational operator++(int dummy);
  Rational operator--(int dummy);

  // Define function operators for unary + and -
  Rational operator+();
  Rational operator-();

  // Define the << and >> operators
  friend ostream& operator<<(ostream&, const Rational&);
  friend istream& operator>>(istream&, Rational&);

private:
  int numerator;
  int denominator;
  static int gcd(int n, int d);
};

// Define nonmember function operators for relational operators
bool operator<(const Rational& r1, const Rational& r2);
bool operator<=(const Rational& r1, const Rational& r2);
bool operator>(const Rational& r1, const Rational& r2);
bool operator>=(const Rational& r1, const Rational& r2);
bool operator==(const Rational& r1, const Rational& r2);
bool operator!=(const Rational& r1, const Rational& r2);

// Define nonmember function operators for arithmetic operators
Rational operator+(const Rational& r1, const Rational& r2);
Rational operator-(const Rational& r1, const Rational& r2);
Rational operator*(const Rational& r1, const Rational& r2);
Rational operator/(const Rational& r1, const Rational& r2);

#endif
```

**LiveExample 14.8** implements the header file. The member functions for augmented assignment operators `+=`, `-=`, `*=`, and `/=` change the contents of the calling object (lines 117−139). You have to assign the result of the operation to `this`. The comparison operators are implemented by invoking `r1.compareTo(r2)` (lines 210−238). The arithmetic operators `+`, `-`, `*`, and `/` are implemented by invoking the functions `add`, `subtract`, `multiply`, and `divide` (lines 241−259).
```CPP
#include "RationalWithOperators.h"
#include <cstdlib> // For the abs function

Rational::Rational()
{
  numerator = 0;
  denominator = 1;
}

Rational::Rational(int numerator, int denominator)
{
  int factor = gcd(numerator, denominator);
  this->numerator = (denominator > 0 ? 1 : -1) * numerator / factor;
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

Rational::Rational(int numerator) // Suitable for type conversion
{
  this->numerator = numerator;
  this->denominator = 1;
}

// Define function operators for augmented operators
Rational& Rational::operator+=(const Rational& secondRational)
{
  *this = add(secondRational);
  return *this;
}

Rational& Rational::operator-=(const Rational& secondRational)
{
  *this = subtract(secondRational);
  return *this;
}

Rational& Rational::operator*=(const Rational& secondRational)
{
  *this = multiply(secondRational);
  return *this;
}

Rational& Rational::operator/=(const Rational& secondRational)
{
  *this = divide(secondRational);
  return *this;
}

// Define function operator []
int& Rational::operator[](int index)
{
  if (index == 0)
    return numerator;
  else 
    return denominator;
}

// Define function operators for prefix ++ and --
Rational& Rational::operator++()
{
  numerator += denominator;
  return *this;
}

Rational& Rational::operator--()
{
  numerator -= denominator;
  return *this;
}

// Define function operators for postfix ++ and --
Rational Rational::operator++(int dummy)
{
  Rational temp(numerator, denominator);
  numerator += denominator;
  return temp;
}

Rational Rational::operator--(int dummy)
{
  Rational temp(numerator, denominator);
  numerator -= denominator;
  return temp;
}

// Define function operators for unary + and -
Rational Rational::operator+()
{
  return *this;
}

Rational Rational::operator-()
{
  return Rational(-numerator, denominator);
}

// Define the output and input operator
ostream& operator<<(ostream& out, const Rational& rational)
{
  if (rational.denominator == 1)
    out << rational.numerator;
  else
    out << rational.numerator << "/" << rational.denominator;
  return out;
}

istream& operator>>(istream& in, Rational& rational)
{
  cout << "Enter numerator: ";
  in >> rational.numerator;

  cout << "Enter denominator: ";
  in >> rational.denominator;
  return in;
}

// Define function operators for relational operators
bool operator<(const Rational& r1, const Rational& r2)
{
  return (r1.compareTo(r2) < 0);
}

bool operator<=(const Rational& r1, const Rational& r2)
{
  return (r1.compareTo(r2) <= 0);
}

bool operator>(const Rational& r1, const Rational& r2)
{
  return (r1.compareTo(r2) > 0);
}

bool operator>=(const Rational& r1, const Rational& r2)
{
  return (r1.compareTo(r2) >= 0);
}

bool operator==(const Rational& r1, const Rational& r2)
{
  return (r1.compareTo(r2) == 0);
}

bool operator!=(const Rational& r1, const Rational& r2)
{
  return (r1.compareTo(r2) != 0);
}

// Define non-member function operators for arithmetic operators
Rational operator+(const Rational& r1, const Rational& r2)
{
  return r1.add(r2);
}

Rational operator-(const Rational& r1, const Rational& r2)
{
  return r1.subtract(r2);
}

Rational operator*(const Rational& r1, const Rational& r2)
{
  return r1.multiply(r2);
}
```

**LiveExample 14.9** gives a program for testing the new `Rational` class.
```CPP
#include <iostream>
#include <string>
#include "RationalWithOperators.h"
using namespace std;

int main()
{
  // Create and initialize two rational numbers r1 and r2.
  Rational r1(4, 2);
  Rational r2(2, 3);

  // Test relational operators
  cout << r1 << " > " << r2 << " is " << 
    ((r1 > r2) ? "true" : "false") << endl;
  cout << r1 << " < " << r2 << " is " << 
    ((r1 < r2) ? "true" : "false") << endl;
  cout << r1 << " == " << r2 << " is " << 
    ((r1 == r2) ? "true" : "false") << endl;
  cout << r1 << " != " << r2 << " is " << 
    ((r1 != r2) ? "true" : "false") << endl;

  // Test toString, add, subtract, multiply, and divide operators
  cout << r1 << " + " << r2 << " = " << r1 + r2 << endl;
  cout << r1 << " - " << r2 << " = " << r1 - r2 << endl;
  cout << r1 << " * " << r2 << " = " << r1 * r2 << endl;
  cout << r1 << " / " << r2 << " = " << r1 / r2 << endl;

  // Test augmented operators
  Rational r3(1, 2);
  r3 += r1;
  cout << "r3 is " << r3 << endl;

  // Test function operator []
  Rational r4(1, 2);
  r4[0] = 3; r4[1] = 4;
  cout << "r4 is " << r4 << endl;

  // Test function operators for prefix ++ and --
  r3 = r4++;
  cout << "r3 is " << r3 << endl;
  cout << "r4 is " << r4 << endl;

  // Test function operator for conversion
  cout << "1 + " << r4 << " is " << (1 + r4) << endl;

  return 0;
}
```

```
command>cl TestRationalWithOperators.cpp
Microsoft C++ Compiler 2019 
Compiled successful (cl is the VC++ compile/link command)

command>TestRationalWithOperators 
2 > 2/3 is true
2 < 2/3 is false
2 == 2/3 is false
2 != 2/3 is true
2 + 2/3 = 8/3
2 - 2/3 = 4/3
2 * 2/3 = 4/3
2 / 2/3 = 3
r3 is 5/2
r4 is 3/4
r3 is 3/4
r4 is 7/4
1 + 7/4 is 11/4

command>
```

## Self-Check

### Can the [] operator be defined as a nonmember function?

No.

### What is wrong if the function + is defined as follows:
```CPP
Rational operator+(const Rational& r1, const Rational& r2) const
```

#### Answer

`const` cannot be used with non-member functions.

### If you remove the constructor Rational(`int` numerator) from both `RationalWithOperators.h` and `RationalWithOperators.cpp`, will there be a compile error in line 44 in `TestRationalWithOperators.cpp`? What will be the error?

The error: cannot convert an `int` to a Rational.

### Can the gcd function in the Rational class be defined as a constant function?

No. A static function cannot be defined as a `const` function. Only the instance member function can be defined as a `const` function.

### Suppose r is a Rational object, in order to perform 4 + r to obtain a Rational object, the Rational class header file must contain what?

`conversion constructor Rational(int numerator)` and non-member function `Rational operator+(const Rational& r1, const Rational& r2)`

# References
