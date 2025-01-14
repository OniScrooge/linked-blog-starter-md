# Summary

# Learning Objectives

# Related

# Content

## Key Point
Most of the operators in C++ can be defined as functions to perform desirable operations.

It is convenient to compare two string objects using an intuitive syntax like

```cpp
string1 < string2 
```

Can you compare two `Rational` objects using a similar syntax like the following?

```cpp
r1 < r2 
```

Yes. You can define a special function called the _operator function_ in the class. The operator function is just like a regular function except that it must be named with keyword `operator` followed by the actual operator. For example, the following function header

```cpp
bool operator<(const Rational& secondRational) const 
```

defines the `<` operator function that returns `true` if this `Rational` object is less than `secondRational`. You can invoke the function using

```cpp
r1.operator<(r2) 
```

or simply

```cpp
r1 < r2 
```

To use this operator, you have to add the function header for `operator<` in the public section in **LiveExample 14.1** Rational.h and implement the function in the Rational.cpp in **LiveExample 14.3** as follows:

```cpp
bool Rational::operator<(const Rational& secondRational) const 
{ 
  // compareTo is already defined Rational.h 
  if (compareTo(secondRational) < 0) 
    return true; 
  else 
    return false; 
} 
```

The following code

```cpp
Rational r1(4, 2); 
Rational r2(2, 3); 
cout << "r1 < r2 is " << (r1.operator<(r2) ? "true" : "false"); 
cout << "\nr1 < r2 is " << ((r1 < r2) ? "true" : "false"); 
cout << "\nr2 < r1 is " << (r2.operator<(r1) ? "true" : "false"); 
```

displays

```
r1 < r2 is falser1 < r2 is falser2 < r1 is true
```

Note that `r1.operator<(r2)` is same as `r1 < r2`. The latter is simpler and therefore preferred.

C++ allows you to overload the operators listed in **Table 14.1**. **Table 14.2** shows the four operators that cannot be overloaded. C++ does not allow you to create new operators.
![[Pasted image 20241007151659.png]]

![[Pasted image 20241007151713.png]]

>[!Note]
C++ defines the operator precedence and associativity (see **Section 3.15**, “Operator Precedence and Associativity”). You cannot change the operator _precedence and associativity_ by overloading.

>[!Note]
Most operators are binary operators. Some are unary. You cannot change the number of operands by overloading. For example, the `/` divide operator is binary and `++` is unary.

Here is another example that overloads the binary `+` operator in the `Rational` class. Add the following function header in Rational.h in **LiveExample 14.1**.

```cpp
Rational operator+(const Rational& secondRational) const 
```

Implement the function in Rational.cpp in **LiveExample 14.3** as follows:

```cpp
Rational Rational::operator+(const Rational& secondRational) const 
{ 
  // add is already defined Rational.h 
  return add(secondRational); 
} 
```

The following code

```cpp
Rational r1(4, 2); 
Rational r2(2, 3); 
cout << "r1 + r2 is " << (r1 + r2).toString() << endl; 
```

displays

```
r1 + r2 is 8/3
```

## Self-Check

### How do you define an operator function for overloading an operator?

The function is just like a regular function except that the function must be named with word operator followed by the actual operator. For example, see the following function header

```C++
bool operator<(Rational& secondRational)
```

### List the operators that cannot be overloaded.

`?:, ., .*, and ::.`

### Can you change the operator precedence or associativity by overloading?

No

### What are the right ways to add one rational object to another?

`r2 = r1.operator+=(r2);`

`r2 = r2.operator+=(r1);`

`r2 += r1;`

`r2 = r2.add(r1);`

# References
