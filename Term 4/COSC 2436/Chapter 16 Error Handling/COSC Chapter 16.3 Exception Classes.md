# Summary

# Learning Objectives

# Related
Prev - [[COSC Chapter 16.2 Exception Handling Overview]]

Next - [[COSC Chapter 16.4 Custom Exception Classes]]
# Content

## Key Point

You can use C++ [[standard exception]] classes to create [[exception]] objects and throw exceptions.

The `catch` block parameter in the preceding examples is the `int` type. A class type is often more useful, because an object can contain more information that you want to throw to a `catch` block. C++ provides a number of [[standard exception]] classes that can be used for creating [[exception]] objects. These classes are shown in **Figure 16.1**
![[Pasted image 20241014234129.png]]

The root class in this hierarchy is `exception` (defined in header `<``exception``>`). It contains the [[virtual function]] `what()` that returns an [[exception]] object’s error message.

The `runtime_error` class (defined in header `<``stdexcept``>`) is a [[base class]] for several [[standard exception]] classes that describes runtime [[errors]]. Class `overflow_error` describes an arithmetic overflow—i.e., a value is too large to be stored. Class `underflow_error` describes an arithmetic underflow—i.e., a value is too small to be stored.

The `logic_error` class (defined in header `<``stdexcept``>`) is a [[base class]] for several [[standard exception]] classes that describes logic [[errors]]. Class `invalid_argument` indicates that an invalid argument has been passed to a [[function]]. Class `length_error` indicates that an object’s length has exceeded the maximum allowed length. Class `out_of_range` indicates that a value has exceeded its allowed range.

Classes `bad_alloc`, `bad_cast`, `bad_typeid`, and `bad_exception` describe the exceptions thrown by C++ operators. For example, a `bad_alloc` [[exception]] is thrown by the `new` operator if the memory cannot be allocated. A `bad_cast` [[exception]] is thrown by the `dynamic_cast` operator as the result of a failed cast to a reference type. A `bad_typeid` [[exception]] is thrown by the `typeid` operator when the operand for `typeid` is a `NULL` pointer. The `bad_exception` class is used in the [[exception]]-specification of a [[function]], which will be discussed in **Section 16.9**.

These classes are used by some functions in the C++ standard library to [throw exceptions](https://revel-ise.pearson.com/courses/66e7050d84448f59a62c6945/assignments/fdba75d7-efef-40d7-b9a6-31de4c3a2774/pages/urn:pearson:entity:f651b10a-352e-4137-8650-216b916d5dfd?source=dashboard#). You also can use these classes to throw exceptions in your programs. **LiveExample 16.5** rewrite **Listing 16.4**, QuotientWithFunction.cpp, by throwing a `runtime_error`.

## **LiveExample 16.5 QuotientThrowRuntimeError.cpp**
```CPP
#include <iostream>
#include <stdexcept>
using namespace std;

int quotient(int number1, int number2)
{
  if (number2 == 0)
    throw runtime_error("Divisor cannot be zero");

  return number1 / number2;
}

int main()
{
  // Read two integers
  cout << "Enter two integers: ";
  int number1, number2;
  cin >> number1 >> number2;

  try
  {
    int result = quotient(number1, number2);
    cout << number1 << " / " << number2 << " is "
      << result << endl;
  }
  catch (runtime_error& ex)
  {
    cout << ex.what() << endl;
  }

  cout << "Execution continues ..." << endl;

  return 0;
}
```
```
command>cl QuotientThrowRuntimeError.cpp
Microsoft C++ Compiler 2019 
Compiled successful (cl is the VC++ compile/link command)

command>QuotientThrowRuntimeError 
Enter two integers: 3 0
Divisor cannot be zero
Execution continues ...

command>
```

The `quotient` [[function]] in **Listing 16.4** throws an `int` value, but the [[function]] in this program throws a `runtime_error` object (line 8). You can create a `runtime_error` object by passing a string that describes the [[exception]].

The catch block catches a `runtime_error` [[exception]] and invokes the `what` [[function]] to return a string description of the [[exception]] (line 28).

**LiveExample 16.6** shows an example of handling the `bad_alloc` [[exception]].

## **LiveExample 16.6 BadAllocExceptionDemo.cpp**
```CPP
#include <iostream>
using namespace std;

int main()
{
  try
  {
    for (int i = 1; i <= 100; i++)
    {
      new int[70000000];
      cout << i << " arrays have been created" << endl;
    }
  }
  catch (bad_alloc& ex)
  {
    cout << "Exception: " << ex.what() << endl;
  }

  return 0;
}
```
```
command>cl BadAllocExceptionDemo.cpp
Microsoft C++ Compiler 2019 
Compiled successful (cl is the VC++ compile/link command)

command>BadAllocExceptionDemo 
1 arrays have been created
2 arrays have been created
3 arrays have been created
4 arrays have been created
5 arrays have been created
6 arrays have been created
Exception: bad allocation

command>
```

The output shows that the program creates six arrays before it fails on the seventh `new` operator. When it fails, a `bad_alloc` [[exception]] is thrown and caught in the `catch` block, which displays the message returned from `ex.what()`.

**LiveExample 16.7** shows an example of handling the `bad_cast` [[exception]].

## **LiveExample 16.7 BadCastExceptionDemo.cpp**
```CPP
#include "AbstractGeometricObject.h" 
#include "DerivedCircleFromAbstractGeometricObject.h" 
#include "DerivedRectangleFromAbstractGeometricObject.h"
#include <iostream>
using namespace std;

int main()
{
  try
  {
    Rectangle r(3, 4);
    Circle& c = dynamic_cast<Circle&>(r);
  }
  catch (bad_cast& ex)
  {
    cout << "Exception: " << ex.what() << endl;
  }

  return 0;
}
```
```
command>cl BadCastExceptionDemo.cpp
Microsoft C++ Compiler 2019 
Compiled successful (cl is the VC++ compile/link command)

command>BadCastExceptionDemo 
Exception: Bad dynamic_cast!

command>
```

Dynamic casting was introduced in **Section 15.11**, “Casting: `static_cast` versus `dynamic_cast`.”

In line 12, a reference of a `Rectangle` object is cast to a `Circle` reference type, which is illegal, and a `bad_cast` [[exception]] is thrown. The [[exception]] is caught in the `catch` block in line 14. If line 12 is replaced by `Circle* c = dynamic_cast<Circle*>(&r)`, no [[exception]] will be thrown. `c` will be a `nullptr`.

**LiveExample 16.8** shows an example of throwing and handling an `invalid_argument` [[exception]].

## **LiveExample 16.8 InvalidArgumentExceptionDemo.cpp**
```CPP
#include <iostream>
#include <stdexcept>
using namespace std;

double getArea(double radius)
{
  if (radius < 0)
    throw invalid_argument("Radius cannot be negative");

  return radius * radius * 3.14159;
}

int main()
{
  // Pormpt the user to enter radius
  cout << "Enter radius: ";
  double radius;
  cin >> radius;

  try
  {
    double result = getArea(radius);
    cout << "The area is " << result << endl;
  }
  catch (exception& ex)
  {
    cout << ex.what() << endl;
  }

  cout << "Execution continues ..." << endl;

  return 0;
}
```
```
command>cl InvalidArgumentExceptionDemo.cpp
Microsoft C++ Compiler 2019 
Compiled successful (cl is the VC++ compile/link command)

command>InvalidArgumentExceptionDemo 
Enter radius: -5.5
Radius cannot be negative
Execution continues ...

command>
```

In the sample output, the program prompts the user to enter radius, `5` and `-5`. Invoking `getArea(-5)` (line 22) causes a `invalid_argument` [[exception]] to be thrown (line 8). This [[exception]] is caught in the `catch` block in line 25. Note that the catch-block parameter type `exception` is a [[base class]] for `invalid_argument`. So, it can catch an `invalid_argument`.

## Self-Check

### Describe the C++ [[exception]] class and its derived classes. Give examples of using bad_alloc and bad_cast.

The [[exception]] class is the root class for C++ [[standard exception]] classes. Its commonly used derived classes are `runtime_error` and `logic_error`. It is a good practice to declare custom [[exception]] classes derived from a [[standard exception]] class, so you can utilize the common features (e.g., the `what()` [[function]]) in the [[exception]] class. For example of using `bad_alloc` and `bad_cast`, see __LiveExamples 14.5 and 14.6__.

### Show the output of the following code with input 10, 60, and 120, respectively.

```CPP
#include <iostream>
using namespace std;

int main()
{
  cout << "Enter a temperature: ";
  double temperature;
  cin >> temperature;

  try
  {
    cout << "Start of try block ..." << endl;

    if (temperature > 95)
      throw runtime_error("Exceptional temperature");

    cout << "End of try block ..." << endl;
  }
  catch (runtime_error& ex)
  {
    cout << ex.what() << endl;
    cout << "It is too hot" << endl;
  }

  cout << "Continue ..." << endl;

  return 0;
}
```
#### Answer
```
Enter a temperature: 120
Start of try block ... 
Exceptional temperature 
It is too hot Continue ...
```

# References
