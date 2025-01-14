# Summary

# Learning Objectives

# Related

# Content

## Key Point

C++ allows you to define functions for operators. This is called operator overloading.

In **Section 10.2.10**, “String Operators,” you learned how to use operators to simplify string operations. You can use the `+` operator to concatenate two strings, the relational operators (`==`, `!=`, `<`, `<=`, `>`, `>=`) to compare two strings, and the subscript operator `[]` to access a character. In **Section 12.6**, “The C++ `vector` Class,” you learned how to use the `[]` operator to access an element in a vector. For example, the following code uses the `[]` operator to return a character from a string (line 3), the `+` operator to combine two strings (line 4), the `<` operator to compare two strings (line 5), the `[]` operator to return an element from a vector (line 10).

```cpp
string s1("Washington"); 
```
```cpp
string s2("California"); 
```
```cpp
cout << "The first character in s1 is " << s1[0] << endl; 
```
```cpp
cout << "s1 + s2 is " << (s1 + s2) << endl; 
```
```cpp
cout << "s1 < s2? " << (s1 < s2) << endl; 
```
```cpp
vector<int> v; 
```
```cpp
v.push_back(3); 
```
```cpp
v.push_back(5); 
```
```cpp
cout << "The first element in v is " << v[0] << endl; 
```

The operators are actually functions defined in a class. These functions are named with keyword `operator` followed by the actual operator. For example, you can rewrite the preceding code using the function syntax as follows:

```cpp
string s1("Washington"); 
```
```cpp
string s2("California"); 
```
```cpp
cout << "The first character in s1 is " << s1.operator[](0) << endl; 
```
```cpp
cout << "s1 + s2 is " << operator+(s1, s2) << endl; 
```
```cpp
cout << "s1 < s2? " << operator<(s1, s2) << endl; 
```
```cpp
vector<int> v; 
```
```cpp
v.push_back(3); 
```
```cpp
v.push_back(5); 
```
```cpp
cout << "The first element in v is " << v.operator[](0) << endl; 
```

The `operator[]` function is a member function in the `string` class, and the `vector` class and `operator+` and `operator<` are nonmember functions in the `string` class. Note that a member function must be invoked by an object using the syntax `objectName.functionName(...)`, such as `s1.operator[](0)`. Obviously, it is more intuitive and convenient to use the operator syntax `s1[0]` than the function syntax `s1.operator[](0)`.

Defining functions for operators is called _operator overloading_. Operators such as `+`, `==`, `!=`, `<`, `<=`, `>`, `>=`, and `[]` are overloaded in the `string` class. How do you overload operators in your custom classes? This chapter uses the `Rational` class as an example to demonstrate how to overload a variety of operators. First, you will learn how to design a `Rational` class for supporting rational-number operations and then overload the operators to simplify these operations.

## Self-Check

Use the freestyle exercises to check your understanding of the concepts.
# References
