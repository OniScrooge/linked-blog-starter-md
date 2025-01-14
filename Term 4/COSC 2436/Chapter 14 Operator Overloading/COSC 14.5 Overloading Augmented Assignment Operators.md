# Summary

# Learning Objectives

# Related

# Content

## Key Point

You can define the augmented assignment operators as functions to return a value by reference.

C++ has augmented assignment operators `+=`, `-=`, `*=`, `/=`, and `%=` for adding, subtracting, multiplying, dividing, and modulus a value in a variable. You can overload these operators in the `Rational` class.

​​​Note that the augmented operators can be used as lvalues. For example, the code​

```cpp
int x = 0; 
(x += 2) += 3; 
```

​​​is legal. So augmented assignment operators are [[lvalue]] operators and you should overload them to return by reference.​

Here is an example that overloads the addition assignment operator `+=`. Add the function header in **LiveExample 14.1**, Rational.h.

```cpp
Rational& operator+=(const Rational& secondRational); 
```

Implement the function in **LiveExample 14.3**, Rational.cpp.

```cpp
Rational& Rational::operator+=(const Rational& secondRational) 
```
```cpp
{ 
```
```cpp
  *this = add(secondRational); 
```
```cpp
  return *this; 
```
```cpp
} 
```

Line 3 invokes the `add` function to add the calling `Rational` object with the second `Rational` object. The result is copied to the calling object `*this` in line 3. The calling object is returned in line 4.

For example, the following code

```cpp
Rational r1(2, 4); 
Rational r2 = r1 += Rational(2, 3); 
cout << "r1 is " << r1.toString() << endl; 
cout << "r2 is " << r2.toString() << endl; 
```

displays

```
r1 is 7/6r2 is 7/6
```

## Self-Check

### When you overload an augmented operator such as +=, should the function be void or nonvoid?

nonvoid, because it must return a new value.

### Why should the functions for augmented assignment operators return a reference?

Because the operator can be used as an [[lvalue]].


# References
