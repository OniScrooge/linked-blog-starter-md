# Summary

# Learning Objectives
1. To know operator overloading and its benefits (§14.1).
2. To define the `Rational` class for creating rational numbers (§14.2).
3. To discover how an operator can be overloaded in C++ using a function (§14.3).
4. To overload the relational operators (`<`, `<=`, `==`, `!=`, `>=`, `>`) and arithmetic operators (`+`, `−`, `*`, `/`) (§14.3).
5. To overload the subscript operator `[]` (§14.4).
6. To overload the augmented assignment operators `+=`, `−=`, `*=`, and `/=` (§14.5).
7. To overload the unary operators `+` and `−` (§14.6).
8. To overload the prefix and postfix `++` and `−−` operators (§14.7).
9. To enable friend functions and friend classes to access a class’s private members (§14.8).
10. To overload the stream insertion and extraction operators `<<` and `>>` as friend nonmember functions (§14.9).
11. To define operator functions to perform object conversions to a primitive type (§14.10.1).
12. To define appropriate constructors to perform conversions from a numeric value to an object type (§14.10.2).
13. To define nonmember functions to enable implicit type conversions (§14.11).
14. To define a new `Rationa`l class with overloaded operators (§14.12).
15. To overload the `=` operator to perform a deep copy (§14.13).
# Related

# Content
## Key Terms
1. **[[friend class]]**
2. **friend function**
3. **[[return-by-reference]]**
4. **[[rule of three]]**
5. **[[lvalue]]**
6. **[[rvalue]]**
## Summary
1. ​C++ allows you to overload operators to simplify operations for objects.
2. You can overload nearly all operators except `?:`, `.`, `.*`, and `::.`
3. You cannot change the operator precedence and associativity by overloading.
4. You can overload the subscript operator `[]` to access the contents of the object using the if desirable.
5. A C++ function may return a reference, which is an alias for the returned variable.
6. The augmented assignment operators (`+=`, `-=`, `*=`, `/=`), subscript operator `[]`, prefix `++`, and prefix `--` operators are lvalue operators. The functions for overloading these operators should return a reference.
7. The `friend` keyword can be used to give the trusted functions and classes access to a class’s private members.
8. The operators `+=`, `-=`, `*=`, `/=`, `%=`,`[]`, `++`, `--`, and `[]` must be overloaded as member functions.
9. The `<<` and `>>` operators must be overloaded as nonmember functions.
10. The arithmetic operators (`+`, `-`, `*`, `/`) and comparison operators (`>`, `>=`, `==`, `!=`, `<`, `<=`) should be implemented as nonmember functions.
11. C++ can perform certain type conversions automatically if appropriate functions and constructors are defined.
12. By default, the memberwise shallow copy is used for the `=` operator. To perform a deep copy for the `=` operator, you need to overload the `=` operator.
# References
