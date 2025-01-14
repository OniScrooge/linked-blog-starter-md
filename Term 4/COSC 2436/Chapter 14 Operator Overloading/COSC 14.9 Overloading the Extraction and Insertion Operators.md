# Summary

# Learning Objectives

# Related

# Content

## Key Point

The stream extraction (`>>`) and insertion (`<<`) operators can be overloaded for performing input and output operations. 

So far, in order to display a `Rational` object, you invoke the `toString()` function to return a string representation for the `Rational` object and then display the string. For example, to display a `Rational` object `r`, you write
```cpp
cout << r.toString(); 
```

Wouldn’t it be nice to be able to display a `Rational` object directly using a syntax like the following?
```cpp
cout << r; 
```

The stream insertion operator (`<<`) and the stream extraction operator (`>>`) are just like other binary operators in C++. `cout << r` is actually the same as `<<(cout, r)` or `operator<<(cout, r)`.

​​​Consider the following statement:​
```cpp
r1 + r2; 
```

The operator is `+` with two operands `r1` and `r2`. Both are instances of the `Rational` class. So, you can overload the `+` operator as a member function with `r2` as the argument. However, for the statement
```cpp
cout << r; 
```

the operator is `<<` with two operands `cout` and `r`. The first operand is an instance of the `ostream` class, not the `Rational` class. C++ requires that you overload the `<<` operator as a non-member function. Since the function may need to access the private data in the `Rational` class, you can define the function as a [[friend function]] of the `Rational` class in the Rational.h header file:
```cpp
// This is placed in the header file 
friend ostream& operator<<(ostream& out, const Rational& rational); 
```

Note that this function returns a reference of `ostream`, because you may use the `<<` operator in a chain of expressions. Consider the following statement:
```cpp
cout << r1 << " followed by " << r2; 
```

This is equivalent to
```cpp
((cout << r1) << " followed by ") << r2; 
```

For this to work, `cout << r1` must return a reference of `ostream`. So, the function `<<` can be implemented as follows:
```cpp
// This is placed in the implementation file 
ostream& operator<<(ostream& out, const Rational& rational) 
{ 
  out << rational.numerator << "/" << rational.denominator; 
  return out; 
} 
```

Note that you can declare and implement the [[friend function]] all in the Rational.h header file as follows: 
```cpp
// This combined declaration and implementation is placed inside the header file 
friend ostream& operator<<(ostream& out, const Rational& rational) 
{ 
  out << rational.numerator << "/" << rational.denominator; 
  return out; 
} 
```

Similarly, to overload the `>>` operator, define the following function header in the Rational.h header file:
```cpp
friend istream& operator>>(istream& in, Rational& rational); 
```

Implement this function in Rational.cpp as follows:
```cpp
// This is placed in the implementation file 
istream& operator>>(istream& in, Rational& rational) 
{ 
  cout << "Enter numerator: "; 
  in >> rational.numerator; 
  cout << "Enter denominator: "; 
  in >> rational.denominator; 
  return in; 
} 
```

The following code gives a test program that uses the overloaded `<<` and `>>` functions operators.
```cpp
Rational r1, r2; 
```
```cpp
cout << "Enter first rational number" << endl; 
```
```cpp
cin >> r1; 
```
```cpp
cout << "Enter second rational number" << endl; 
```
```cpp
cin >> r2; 
```
```cpp
cout << r1 << " + " << r2 << " = " << r1 + r2 << endl; 
```
```
Enter first rational numberEnter numerator: 1Enter denominator: 2Enter second rational numberEnter numerator: 3Enter denominator: 41/2 + 3/4 is 5/4
```

Line 3 reads values to a rational object from `cin`. In line 8, `r1 + r2` is evaluated to a new rational number, which is then sent to `cout`.

Note that the `operator<<` and `operator>>` are defined friend because their implementation accesses the private members of the `Rational` class. If you modify their implementation to not access the private members, you don’t need to define these functions as friend of `Rational`.

## Self-Check

### What should be the function signature for the `<<` operator? for the `>>` operator?
```CPP
friend ostream& operator<<(ostream& cout, const Rational& rational);
friend istream& operator>>(istream& cin, Rational& rational);
```

### Why should the `<<` and `>>` operators be defined as nonmember functions?

because the first operand in << and >> are not Rational object.

### Suppose you overload the `<<` operator as follows: Do you still need to define in the Rational class? 
```CPP
ostream& operator<<(ostream& stream, const Rational& rational)
{
  stream << rational.toString();
  return stream;
}
```

```CPP
friend ostream& operator<<(ostream& stream, Rational& rational)
```

#### Answer
No, because the function does not need to access the private members in Rational.

### If the << operator does not access the private data fields in Rational, do you still have to declare it friend?

No

### What is the correct signature for the overloaded >> operator?

```CPP
friend istream& operator>>(istream& stream, Rational& rational);
```

# References
