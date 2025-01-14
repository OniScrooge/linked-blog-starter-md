# Summary

# Learning Objectives

# Related

# Content

## Key Point

The _preincrement_, _predecrement_, _postincrement_, and _postdecrement_ operators can be overloaded.

The `++` and `--` operators may be prefix or postfix. The prefix `++var` or `--var` first adds or subtracts `1` from the variable and then uses the new value in `var` in the expression. The postfix `var++` or `var--` adds or subtracts `1` from the variable, but uses the old value in `var` in the expression.

If the `++` and `−−` are implemented correctly, the following code

```cpp
Rational r2(2, 3); 
Rational r3 = ++r2; // Prefix increment 
cout << "r3 is " << r3.toString() << endl; 
cout << "r2 is " << r2.toString() << endl; 
 
Rational r1(2, 3); 
Rational r4 = r1++; // Postfix increment 
cout << "r1 is " << r1.toString() << endl; 
cout << "r4 is " << r4.toString() << endl; 
```

should display

```
r3 is 5/3r2 is 5/3r1 is 5/3r4 is 2/3
```

In the last line of the code above r4 stores the original value of r1.

How does C++ distinguish the prefix `++` or `--` function operators from the postfix `++` or `--` function operators? C++ defines postfix `++`/`--` function operators with a special dummy parameter of the `int` type and defines the prefix `++` function operator with no parameters as follows:

```cpp
Rational& operator++(); // Preincrement 
```

```cpp
Rational operator++(int dummy); // Postincrement 
```

Note that the prefix `++` and `−−` operators are [[lvalue]] operators, but the postfix `++` and `−−` operators are not. So, the following code is legal in C++:

```cpp
int x = 1; 
++x = 4; 
```

But the following code is not allowed:

```cpp
int x = 1; 
x++ = 4; 
```

The prefix and postfix `++` operator functions for the `Rational` numbers can be implemented as follows:

```cpp
// Prefix increment 
```
```cpp
Rational& Rational::operator++() 
```
```cpp
{ 
```
```cpp
  numerator += denominator; 
```
```cpp
  return *this; 
```
```cpp
} 
```
```cpp
// Postfix increment 
```
```cpp
Rational Rational::operator++(int dummy) 
```
```cpp
{ 
```
```cpp
  Rational temp(numerator, denominator); 
```
```cpp
  numerator += denominator; 
```
```cpp
  return temp; 
```
```cpp
} 
```

In the prefix `++` function, line 4 adds the denominator to the numerator. This is the new numerator for the calling object after adding `1` to the `Rational` object. Line 5 returns the calling object.

In the postfix `++` function, line 11 creates a temporary `Rational` object to store the original calling object. Line 12 increments the calling object. Line 13 returns the original calling object.

## Self-Check

### What should be the function signature for the prefix ++ operator and for the postfix ++ operator?

Prefix:
`returnValueType& operator++();`

Postfix:
`returnValueType operator++(int dummy)`

### Suppose you implement the postfix ++ as follows
```C++
Rational Rational::operator++(int dummy)
{
  Rational temp(*this);
  add(Rational(1, 0));
  return temp;
}
```
Is this implementation correct? If so, compare it with the implementation in the text; which one is better?  

#### Answer

Correct. Both are OK. The implementation in the book is better because it adds denominator directly to numerator rather than invoking the add function.

# References
