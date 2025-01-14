# Summary

# Learning Objectives

# Related

# Content

## Key Point

The subscript operator `[]` is commonly defined to access and modify a data field or an element in an object. 

In C++, the pair of square brackets `[]` is called the _subscript operator_. You have used this operator to access array elements and the elements in a `string` object and a `vector` object. You can overload this operator to access the contents of the object if desirable. For example, you may wish to access the numerator and denominator of a `Rational` object `r` using `r[0]` and `r[1]`.

We first give an incorrect solution to overload the `[]` operator. We will then identify the problem and give a correct solution. To enable a `Rational` object to access its numerator and denominator using the `[]` operator, define the following function header in the Rational.h header file:

```cpp
int operator[](int index); 
```

​​​Implement the function in Rational.cpp as follows:​

```cpp
int Rational::operator[](int index) 
```
```cpp
{ 
```
```cpp
  if (index == 0) 
```
```cpp
    return numerator; 
```
```cpp
  else 
```
```cpp
    return denominator; 
```
```cpp
} 
```

In the above code, line 1 is partially correct.

​​​The following code​
```cpp
Rational r(2, 3); 
cout << "r[0] is " << r[0] << endl; 
cout << "r[1] is " << r[1] << endl; 
```

​​​displays​
```
r[0] is 2r[1] is 3
```

​​​Can you set a new numerator or denominator like an array assignment such as the following?​
```cpp
r[0] = 5; 
r[1] = 6; 
```

​​​If you compile it, you will get the following error:
```
lvaluerequired in r[0] and r[1]
```

In C++, [[lvalue]] refers to a named item persists beyond a single expression. [[rvalue]] refers to an unnamed value that disappears after it is used in the expression. All variables and named objects are lvalues. Literal values and temporary objects are rvalues. For example, in the following code, `x` and `y` are lvalues while numbers `4` and `5` are rvalues.

```cpp
int x = 4 * 5; // x is [[lvalue]], 4 and 5 are rvalue 
int y = x + 6 * 7; // x and y are lvalue and 6 and 7 are rvalue 
```

In the following code, `s` is an [[lvalue]] and `string("abc")` is an [[rvalue]]. `string("abc")` is an unnamed object `string` object.
```cpp
string s("Welcome"); // s is lvalue 
s = string("abc"); // string("abc") is an rvalue 
```

How can you make `r[0]` and `r[1]` an [[lvalue]] so that you can assign a value to `r[0]` and `r[1]`? The answer is that you can define the `[]` operator to return a reference of the variable. This is called [[return-by-reference]].

​​​Add the following correct function header in `Rational.h`:​
```cpp
int& operator[](int index); 
```

​​​Implement the function in Rational.cpp:​
```cpp
int& Rational::operator[](int index) 
{ 
  if (index == 0) 
    return numerator; 
  else 
    return denominator; 
} 
```
In the above code the first line is correct.

You are familiar with pass-by-reference. [[Return-by-reference]] and pass-by-reference are the same concept. In pass-by-reference, the formal parameter and the actual parameter are aliases. In [[return-by-reference]], the function returns an alias to a variable. This way, a function can be used on the left side of an assignment statement.

In this function, if `index` is `0`, the function returns an alias of variable `numerator`. If index is `1`, the function returns an alias of variable `denominator`. The function now can be used an [[lvalue]].

Note that this function does not check the bounds of the index. In **Chapter 16**, you will learn how to revise this function to make your program more robust by throwing an exception if the index is not `0` or `1`.

The following code
```cpp
Rational r(2, 3); 
r[0] = 5; // Set numerator to 5 
r[1] = 6; // Set denominator to 6 
cout << "r[0] is " << r[0] << endl; 
cout << "r[1] is " << r[1] << endl; 
cout << "r.doubleValue() is " << r.doubleValue() << endl; 
```
displays
```
r[0] is 5r[1] is 6r.doubleValue() is 0.833333
```

In `r[0]`, `r` is an object and `0` is the argument to the member function `[]`. When `r[0]` is used as an expression, it returns a value for the numerator. When `r[0]` is used on the left side of the assignment operator, it is an alias for variable `numerator`. So, `r[0] = 5` assigns `5` to `numerator`.

The `[]` operator functions as both accessor and mutator. For example, you use `r[0]` as an accessor to retrieve the numerator in an expression, and you use `r[0] = value` as a mutator.

For convenience, we call a function operator that returns a reference an _**[[lvalue]] operator**_. Several other operators such as `+=`, `-=`, `*=`, `/=`, and `%=` are also [[lvalue]] operators.

## Self-Check

### What is an [[lvalue]]? What is an [[rvalue]]?

In C++, [[lvalue]] refers to a named item persists beyond a single expression. [[rvalue]] refers to an unnamed value that disappears after it is used in the expression.

### Explain pass-by-reference and [[return-by-reference]].

Pass-by-reference is to pass the reference of the argument when invoking a function. [[Return-by-reference]] is to return the reference of the variable returned from the function.

### What should be the function signature for the [] operator?

The function signature should be

```C++
Somereturntype& operator[](const int& index);
```


### Note that the `getCourseName()` function is declared as string `getCourseName() const` in __LiveExample 11.14 Course.h__. What is the output of the following code?
```C++
  Course course1("C++");
  course1.getCourseName()[0] = 'T';
  cout << course1.getCourseName() << endl; 
```
If the `getCourseName()` function is redeclared as string& `getCourseName() const`, what would be the output of the preceding code?

#### Answer

For string `getCourseName() const` defined in __LiveExample 11.14 Course.h__, the output is C++. In this case, the `getCourseNmae()` function returns a copy of the course name string in the course. `course1.getCourseName()[0] = 'T'` does not change the string in the course name.  
For `string& getCourseName() const`, the output would be T++. In this case, the `getCourseNmae()` function returns a reference of the course name string in the course. `course1.getCourseName()[0] = 'T'` changes the course name string in the course.

# References
