# Summary

# Learning Objectives

# Related

# Content

If an operator can be overloaded as a nonmember function, define it as a nonmember function to enable implicit type conversions.

C++ can perform certain type conversions automatically. You can define functions to enable conversions You can add a `Rational` object `r1` with an integer like this:

```cpp
r1 + 4 
```

Can you add an integer with a `Rational` object `r1` like this?

```cpp
4 + r1 
```

Naturally you would think the `+` operator is symmetric. However, it does not work, because the left operand is the calling object for the `+` operator and the left operand must be a `Rational` object. Here, `4` is an integer, not a `Rational` object. C++ does not perform automatic conversion in this case. To circumvent this problem, take the following two steps:

1. **1.** Define and implement the following constructor, as discussed in the preceding section.

```cpp
Rational(int numerator); 
```

1. This constructor enables the integer to be converted to a `Rational` object.
2. **2.** Define the `+` operator as a nonmember function in the Rational.h header file as follows:

```cpp
Rational operator+(const Rational& r1, const Rational& r2) 
```

1. Implement the function in Rational.cpp as follows:

```cpp
Rational operator+(const Rational& r1, const Rational& r2) 
{ 
  return r1.add(r2); 
} 
```

Automatic type conversion to the user-defined object also works for comparison operators (`<`, `<=`, `==`, `!=`, `>`, `>=`).

Note that the examples for the `operator<` and `operator+` are defined as member functio​​​​ns in **Section 14.3**. From now​​​​ on, we will define them as nonmember functions

## Self-Check

### Why defining a nonmember function for an operator is preferred?

If an operator can be overloaded as a non-member function, define it as a non-member function to enable implicit type conversions.

# References
