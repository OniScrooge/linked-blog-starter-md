# Summary

# Learning Objectives

# Related

# Content
## Key Point

 __Templates__ ​provide the capability to parameterize types in functions and classes. You can define functions or classes with generic types that can be substituted for concrete types by the compiler.

Let us begi​n with a simple example to demonstrate the need for templates. Suppose you want to find the maximum of two integers, two doubles, two characters, and two strings. ​You might write four overloaded functions as follows:

```cpp
int maxValue(int value1, int value2) 
{ 
  if (value1 > value2) 
    return value1; 
  else 
    return value2; 
} 
 
double maxValue(double value1, double value2) 
{ 
  if (value1 > value2) 
    return value1; 
  else 
    return value2; 
} 
 
char maxValue(char value1, char value2) 
{ 
  if (value1 > value2) 
    return value1; 
  else 
    return value2; 
} 
 
string maxValue(string value1, string value2) 
{ 
  if (value1 > value2) 
    return value1; 
  else 
    return value2; 
} 
```

These four functions are almost identical, except that each uses a different type. The first function uses the `int` type, the second the `double` type, the third the `char` type, and the fourth the `string` type. It would save typing, save space, and make the program easy to maintain if you could simply define one function with a generic type as follows:

```cpp
GenericType maxValue(GenericType value1, GenericType value2) 
{ 
  if (value1 > value2) 
    return value1; 
  else 
    return value2; 
} 
```

This `GenericType` applies to all types such as `int`, `double`, `char`, and `string`.

C++ enables you to define a function [template](https://revel-ise.pearson.com/courses/66e7050d84448f59a62c6945/pages/urn:pearson:entity:4e570056-17af-4d52-bb03-220187d8c814?source=dashboard#) with generic types. ​**LiveExample 12.1**​ defines a template function for finding a maximum value between two values of a generic type.

**LiveExample 12.1 GenericMaxValue.cpp**
```Cpp
#include <iostream>
#include <string>
using namespace std;

FILL_CODE_OR_CLICK_ANSWER
T maxValue(const T value1, const T value2)
{
  if (value1 > value2)
    return value1;
  else
    return value2;
}

int main()
{
  cout << "Maximum between 1 and 3 is " << maxValue(1, 3) << endl;
  cout << "Maximum between 1.5 and 0.3 is "
    << maxValue(1.5, 0.3) << endl;
  cout << "Maximum between 'A' and 'N' is "
    << maxValue('A', 'N') << endl;
  cout << "Maximum between \"NBC\" and \"ABC\" is "
    << maxValue(string("NBC"), string("ABC")) << endl;

  return 0;
}
```

```
command>cl GenericMaxValue.cpp
Microsoft C++ Compiler 2019 
Compiled successful (cl is the VC++ compile/link command)

command>GenericMaxValue 
Maximum between 1 and 3 is 3
Maximum between 1.5 and 0.3 is 1.5
Maximum between 'A' and 'N' is N
Maximum between "NBC" and "ABC" is NBC

command>
```

The definition for the function template begins with the keyword `template` followed by a list of parameters. Each parameter must be preceded by the interchangeable keyword `typename` ​or​ `class` in the form `<``typename typeParameter``>` ​or​ `<``class typeParameter``>`. For example, line 5

```cpp
template<typename T> 
```

begins the definition of the function template for `maxValue`. This line is also known as the [template prefix](https://revel-ise.pearson.com/courses/66e7050d84448f59a62c6945/pages/urn:pearson:entity:4e570056-17af-4d52-bb03-220187d8c814?source=dashboard#). Here `T` is a [type parameter](https://revel-ise.pearson.com/courses/66e7050d84448f59a62c6945/pages/urn:pearson:entity:4e570056-17af-4d52-bb03-220187d8c814?source=dashboard#). By convention, a single capital letter such as `T` is used to denote a type parameter.

The `maxValue` function is defined in lines 6–12. A type parameter can be used in the function just like a regular type. You can use it to specify the return type of a function, declare function parameters, or declare variables in the function.

The `maxValue` function is invoked to return the maximum `int`, `double`, `char`, and `string` in lines 16–22. For the function call `maxValue(1, 3)`, the compiler recognizes that the parameter type is `int` and replaces the type parameter `T` with `int` to invoke the `maxValue` function with a concrete `int` type. For the function call `maxValue(string("NBC"), string("ABC"))`, the compiler recognizes that the parameter type is `string` and replaces the type parameter `T` with `string` to invoke the `maxValue` function with a concrete `string` type.

What happens if you replace `maxValue(string("NBC"), string("ABC"))` in line 22 with `maxValue("NBC", "ABC")`? You will be surprised to see that it returns `ABC`. Why? `"NBC"` and `"ABC"` are C-strings. Invoking `maxValue("NBC", "ABC")` passes the addresses of `"NBC"` and `"ABC"` to the function parameter. When comparing `value1 > value2`, the addresses of two arrays are compared, not the contents of the array!

>[!warning] Caution
>The generic `maxValue` function can be used to return a maximum of two values of _any type_, provided that:
>- The two values have the same type;
>- The two values can be compared using the `>` operator.
>
>For example, if one value is `int` and the other is `double` (e.g., `maxValue(1, 3.5)`), the compiler will report a syntax error because it cannot find a match for the call. If you invoke `maxValue(Circle(1), Circle(2))`, the compiler will report a syntax error because the `>` operator is not defined in the `Circle` class.

>[!tip]
>You can use either `<``typename T``>` or `<``class T``>` to specify a type parameter. Using `<``typename T``>` is better because `<``typename T``>` is descriptive. `<``class T``>` could be confused with class definition.

>[!note]
>Occasionally, a template function may have more than one parameter. In this case, place the parameters together inside the brackets, separated by commas, such as `<``typename T1, typename T2, typename T3``>`.

The parameters in the generic function in **LiveExample 12.1** are defined as pass-by-value. You can modify it using pass-by-reference as shown in **LiveExample 12.2**.

**LiveExample 12.2 GenericMaxValuePassByReference.cpp**
```C++
#include <iostream>
#include <string>
using namespace std;

template<typename T>
T maxValue(FILL_CODE_OR_CLICK_ANSWER value1, const T& value2)
{
  if (value1 > value2)
    return value1;
  else
    return value2;
}

int main()
{
  cout << "Maximum between 1 and 3 is " << maxValue(1, 3) << endl;
  cout << "Maximum between 1.5 and 0.3 is "
    << maxValue(1.5, 0.3) << endl;
  cout << "Maximum between 'A' and 'N' is "
    << maxValue('A', 'N') << endl;
  cout << "Maximum between \"NBC\" and \"ABC\" is "
    << maxValue(string("NBC"), string("ABC")) << endl;

  return 0;
}
```

```
command>cl GenericMaxValuePassByReference.cpp
Microsoft C++ Compiler 2019 
Compiled successful (cl is the VC++ compile/link command)

command>GenericMaxValuePassByReference 
Maximum between 1 and 3 is 3
Maximum between 1.5 and 0.3 is 1.5
Maximum between 'A' and 'N' is N
Maximum between "NBC" and "ABC" is NBC

command>
```

## Self-Check

>[!faq]- For the maxValue function in LiveExample 12.1, can you invoke it with two arguments of different types, such as maxValue(1, 1.5)?
No. See the Note box in this section.

>[!faq]- For the maxValue function in LiveExample 12.1, can you invoke it with two arguments of strings, such as maxValue("ABC", "ABD")? Can you invoke it with two arguments of circles, such as maxValue(Circle(2), Circle(3))?
You can invoke it with maxValue("ABC", "ABD"), but with maxValue(Circle(2), Circle(3)) because Circle objects cannot be compared using the < operator.

>[!faq]- Can `template<typename T>` be replaced by `template<class T>`?
Yes.

>[!faq]-  Can a type parameter be named using any identifier other than a keyword?
Yes.

>[!faq]- Can a type parameter be of a primitive type or an object type?
>Yes.

>[!faq]- What is wrong in the following code?
```C++
#include <iostream>
#include <string>
using namespace std;

template<typename T>
T maxValue(T value1, T value2)
{
  int result;
  if (value1 > value2)
    result = value1;
  else
    result = value2;
  return result;
}

int main()
{
  cout << "Maximum between 1 and 3 is " 
    << maxValue(1, 3) << endl;
  cout << "Maximum between 1.5 and 0.3 is "
    << maxValue(1.5, 0.3) << endl;
  cout << "Maximum between 'A' and 'N' is "
   << maxValue('A', 'N') << endl;
  cout << "Maximum between \"ABC\" and \"ABD\" is "
   << maxValue("ABC", "ABD") << endl;

  return 0;
}
```
>Line 8, int should be changed to T.

>[!faq]- Suppose you define the maxValue function as follows:
```C++
template<typename T1, typename T2>
T1 maxValue(T1 value1, T2 value2)
{
  if (value1 > value2)
    return value1;
  else
    return value2;
}
```

>[!faq]- What would be the return value from invoking maxValue(1, 2.5), maxValue(1.4, 2.5), and maxValue(1.5, 2)?
maxValue(1, 2.5) returns 2.  
maxValue(1.4, 2.5) returns 2.5.  
maxValue(1.5, 2) is returns 2.
