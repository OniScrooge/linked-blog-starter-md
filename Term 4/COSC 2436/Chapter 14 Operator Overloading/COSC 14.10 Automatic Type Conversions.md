# Summary

# Learning Objectives

# Related

# Content

## Key Point

You can define functions to perform automatic conversion from an object to a primitive type value and vice versa.

C++ can perform certain type conversions automatically. You can define functions to enable conversions from a `Rational` object to a primitive type value or vice versa.

## 14.10.1 Converting to a Primitive Data Type

You can add an `int` value with a `double` value such as

```cpp
4 + 5.5 
```

In this case, C++ performs automatic type conversion to convert an `int` value `4` to a double value `4.0`.

Can you add a rational number with an `int` or a `double` value? Yes. You have to define a function operator to convert an object into `int` or `double`. Here is the implementation of the function to convert a `Rational` object to a `double` value.

```cpp
Rational::operator double() 
{ 
  return doubleValue(); // doubleValue() already in Rational.h 
} 
```

​​​Don’t forget that you have to add the member function header in the `Rational.h` header file.​

```cpp
operator double(); 
```

​​​This is a special syntax for defining conversion functions to a primitive type in C++. There is no return type like a constructor. The function name is the type that you want the object to be converted to.​

So, the following code

```cpp
  Rational r1(1, 4); 
```
```cpp
  double d = r1 + 5.1; 
```
```cpp
  cout << "r1 + 5.1 is " << d << endl; 
```

displays

```cpp
r1 + 5.1 is 5.35 
```

The statement in line 2 adds a rational number `r1` with a `double` value `5.1`. Since the conversion function is defined to convert a rational number to a `double`, `r1` is converted to a `double` value `0.25`, which is then added with `5.1`.

## 14.10.2 Converting to an Object Type

A `Rational` object can be automatically converted to a numeric value. Can a numeric value be automatically converted to a `Rational` object? Yes, it can.

To achieve this, define the following constructor in the header file:

```cpp
Rational(int numerator); 
```

​​​and implement it in the implementation file as follows:​

```cpp
Rational::Rational(int numerator) 
{ 
  this->numerator = numerator; 
  this->denominator = 1; 
} 
```

Provided that the `+` operator is also overloaded (see ​**Section​ ​14.3**​), the following code

```cpp
Rational r1(2, 3); 
Rational r = r1 + 4; // Automatically converting 4 to Rational 
cout << r << endl; 
```

displays

```cpp
14 / 3 
```

When C++ sees `r1 + 4`, it first checks to see if the `+` operator has been overloaded to add a `Rational` with an integer. Since no such function is defined, the system next searches for the `+` operator to add a `Rational` with another `Rational`. Since `4` is an integer, C++ uses the constructor that constructs a `Rational` object from an integer argument. In other words, C++ performs an automatic conversion to convert an integer to a `Rational` object. This automatic conversion is possible because the suitable constructor is available. Now two `Rational` objects are added using the overloaded `+` operator to return a new `Rational` object (`14 / 3`).

​​​A class can define the conversion function to convert an object to a primitive type value or define a conversion constructor to convert a primitive type value to an object, but not both simultaneously in the class. If both are defined, the compiler will report an ambiguity error.​

## Self-Check

### What should be the function signature for converting an object to the `int` type?

`operator int()`

### How do you convert a primitive type value to an object?

You can convert a primitive type value to an object by defining a constructor with the primitive type as the sole parameter.

### Can a class define the conversion function to convert an object to a primitive type value and define a conversion constructor to convert a primitive type value to an object simultaneously in the class?

No. It may cause ambiguity compile error because the compiler cannot decide which function to use. For example, for a Rational object r, r + 4 would cause an ambiguity error.

# References
