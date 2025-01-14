# Summary

# Learning Objectives

# Related

# Content

## Key Point

The unary `+` and `−` operators can be overloaded. 

The `+` and `-` are unary operators. They can be overloaded, too. Since the unary operator operates on one operand that is the calling object itself, the unary function operator has no parameters.

Here is an example that overloads the `-` operator. Add the function header in **LiveExample 14.1**, Rational.h.

```cpp
Rational operator-() 
```

Implement the function in **LiveExample 14.3**, Rational.cpp.

```cpp
Rational Rational::operator-() 
{ 
  return Rational(-numerator, denominator); 
} 
```

Negating a `Rational` object is the same as negating its numerator (line 3). Note that the negating operator returns a new `Rational`. The calling object itself is not changed.

The following code

```cpp
Rational r2(2, 3); 
```
```cpp
Rational r3 = -r2;  // Negate r2 
```
```cpp
cout << "r2 is " << r2.toString() << endl; 
```
```cpp
cout << "r3 is " << r3.toString() << endl; 
```

displays

```
r2 is 2/3r3 is -2/3
```

## Self-Check

### What should be the function signature for the unary + operator?

`returnValueType operator+()`

### Why is the following implementation for the unary - operator wrong?  

```C++
Rational Rational::operator-() 
{
  numerator *= -1;
  return *this;
}
```

#### Answer

The implementation changes the calling object value, but the calling object should not be changed.


# References
