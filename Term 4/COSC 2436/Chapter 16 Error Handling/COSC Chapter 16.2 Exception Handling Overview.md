# Summary

# Learning Objectives

# Related
Prev - [[COSC Chapter 16.1 Introduction]]

Next - [[COSC Chapter 16.3 Exception Classes]]
# Content

## Key Point

An [[exception]] is thrown using a `throw` statement and caught in a `try`-`catch` block. [[Exception]] handling enables the caller of the [[function]] to process the [[exception]] thrown from a [[function]].

To demonstrate [[exception]] handling including how an [[exception]] is created and thrown, let us begin with an example that reads in two integers and displays their quotient, as shown in 
## **LiveExample 16.1 Quotient.cpp**
```CPP
#include <iostream>
using namespace std;

int main()
{
  // Read two intergers
  cout << "Enter two integers: ";
  int number1, number2;
  cin >> number1 >> number2;

  cout << number1 << " / " << number2 << " is "
    << (number1 / number2) << endl;

  return 0;
}
```
```
command>cl Quotient.cpp
Microsoft C++ Compiler 2019 
Compiled successful (cl is the VC++ compile/link command)

command>Quotient 
Enter two integers: 1 0
A runtime error occurred

command>
```

If you enter `0` for the second number, a runtime error occurs, because you cannot divide an integer by `0`. (_Recall that a floating-point number divided by `0` does not raise an [[exception]]._) A simple way to fix the error is to add an `if` statement to test the second number, as shown in 
## **LiveExample 16.2 QuotientWithIf.cpp**
```CPP
#include <iostream>
using namespace std;

int main()
{
  // Read two integers
  cout << "Enter two integers: ";
  int number1, number2;
  cin >> number1 >> number2;

  if (number2 != 0)
  {
    cout << number1 << " / " << number2 << " is "
      << (number1 / number2) << endl;
  }
  else
  {
    cout << "Divisor cannot be zero" << endl;
  }

  return 0;
}
```
```
command>cl QuotientWithIf.cpp
Microsoft C++ Compiler 2019 
Compiled successful (cl is the VC++ compile/link command)

command>QuotientWithIf 
Enter two integers: 1 0
Divisor cannot be zero

command>
```

## **LiveExample 16.3**

Before introducing [[exception]] handling, let us rewrite **LiveExample 16.2** to compute a quotient using a [[function]], as shown in **CodeAnimation 16.3**.

```CPP
#include <iostream>
using namespace std;

int quotient(int number1, int number2)
{
  if (number2 == 0)
  {
    cout << "Divisor cannot be zero" << endl;
    exit(0); // Terminate the program
  }

  return number1 / number2;
}

int main()
{
  // Read two integers
  cout << "Enter two integers: ";
  int number1, number2;
  cin >> number1 >> number2;

  int result = quotient(number1, number2);
  cout << number1 << " / " << number2 << " is "
    << result << endl;

  return 0;
}
```
```
command>cl QuotientWithFunction.cpp
Microsoft C++ Compiler 2019 
Compiled successful (cl is the VC++ compile/link command)

command>QuotientWithFunction 
Enter two integers: 1 0
Divisor cannot be zero

command>
```

The [[function]] `quotient` (lines 4–13) returns the quotient of two integers. If `number2` is `0`, it cannot return a value, so the program is terminated in line 9. The `exit(0)` [[function]] terminates the program. This is clearly a problem. You should not let the [[function]] terminate the program—the _caller_ should decide whether to terminate the program.

How can a [[function]] notify its caller an [[exception]] has occurred? C++ enables a [[function]] to throw an [[exception]] that can be caught and handled by the caller. **LiveExample 16.3** can be rewritten, as shown in
## **LiveExample 16.4 QuotientWithException.cpp**
```CPP
#include <iostream>
using namespace std;

int quotient(int number1, int number2)
{
  if (number2 == 0)
    throw number1;

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
  catch (int ex)
  {
    cout << "Exception: an integer " << ex <<
      " cannot be divided by zero" << endl;
  }

  cout << "Execution continues ..." << endl;

  return 0;
}
```
```
command>cl QuotientWithException.cpp
Microsoft C++ Compiler 2019 
Compiled successful (cl is the VC++ compile/link command)

command>QuotientWithException 
Enter two integers: 1 0
Exception: an integer 1 cannot be divided by zero
Execution continues ...

command>
```


If `number2` is `0`, the [[function]] `quotient` throws an [[exception]] (line 7) by executing

```cpp
throw number1; 
```

The value thrown, in this case `number1`, is called an [[exception]]. The execution of a throw statement is c​alled _throwing an [[exception]]_. You can throw a​ value of any type. In this case, the value is of the `int` type.

When an [[exception]] is thrown, the normal execution flow is interrupted. As the name suggests, to “throw an [[exception]]” is to pass the [[exception]] from one place to another. The statement for invoking the [[function]] is contained in a `try` block. The `try` block (lines 19–24) contains the code that is executed in normal circumstances. The [[exception]] is caught by the `catch` block. The code in the `catch` block is executed to _handle the [[exception]]_. Afterward, the statement (line 31) after the `catch` block is executed.

The `throw` statement is analogous to a [[function]] call, but instead of calling a [[function]], it calls a `catch` block. In this sense, a `catch` block is like a [[function]] definition with a parameter that matches the type of the value being thrown. However, after the `catch` block has been executed, the program control does not return to the `throw` statement; instead, it executes the next statement after the `catch` block.

The identifier `e` in the `catch` block header

```cpp
catch (int ex) 
```

acts very much like a parameter in a [[function]]. So, it is referred to as a `catch` block parameter. The type (e.g., `int`) preceding `ex` specifies the kind of [[exception]] the `catch` block can catch. Once the [[exception]] is caught, you can access the thrown value from this parameter in the body of a catch block.

In summary, a template for a `try`-`throw`-`catch` block may look like this:

```cpp
try 
{ 
  Code to try; 
  Throw an exception with a throw statement or 
    from function if necessary; 
  More code to try; 
} 
catch (type ex) 
{ 
  Code to process the exception; 
} 
```

An [[exception]] may be thrown directly using a `throw` statement in a `try` block, or a [[function]] may be invoked that throws an [[exception]].

[[Function]] `quotient` (lines 4–10) returns the quotient of two integers. If `number2` is `0`, it cannot return a value. So, an [[exception]] is thrown in line 7.

The main [[function]] invokes the `quotient` [[function]] (line 21). If the quotient [[function]] executes normally, it returns a value to the caller. If the `quotient` [[function]] encounters an [[exception]], it throws the [[exception]] back to its caller. The caller’s `catch` block handles the [[exception]].

Now you see the _advantages_ of using [[exception]] handling. It enables a [[function]] to throw an [[exception]] to its caller. Without this capability, a [[function]] must handle the [[exception]] or terminate the program. Often, the called [[function]] does not know what to do in case of error. This is typically the case for the library [[function]]. The library [[function]] can detect the error, but only the caller knows what needs to be done when an error occurs. The fundamental idea of [[exception]] handling is to separate error detection (done in a called [[function]]) from error handling (done in the calling [[function]]).

>[!Note]
>If you are not interested in the contents of an [[exception]] object, the `catch` block parameter may be omitted. For example, the following `catch` block is legal.
>
>```cpp
>try 
>{ 
>  // ... 
>} 
>catch (int) 
>{ 
>  cout << "Error occurred " << endl; 
>} 
>```

## Self-Check

### Show the output of the following code with input 120.

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
      throw temperature;

    cout << "End of try block ..." << endl;
  }
  catch (double temperature)
  {
    cout << "The temperature is " << temperature << endl;
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
The temperature is 120
It is too hot
Continue ... 
```

### What would be the output for the preceding code if the input were 80?

```
Enter a temperature: 80
Start of try block ...
End of try block ...
Continue ... 
```
   
### Would it be an error if you changed

```CPP
catch (double temperature)
{
  cout << "The temperature is " << temperature << endl;
  cout << "It is too hot" << endl;
}
```

in the preceding code to the following?

```CPP
catch (double)
{
  cout << "It is too hot" << endl;
}
```
#### Answer

No [[errors]]. It is legal in C++ to omit the catch block parameter.

### What is advantage of using [[exception]] handling?

[[Exception]] handling enables the caller of the [[function]] to process the [[exception]] thrown from a [[function]]

# References
