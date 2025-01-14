# Summary

# Learning Objectives

# Related
Prev - [[COSC Chapter 16.6 Exception Handling]]

Next - [[COSC Chapter 16.8 When to use Exceptions]]
# Content

## Key Point

After an [[exception]] is caught, it can be rethrown to the caller of the [[function]].

C++ allows an [[exception]] handler to rethrow the [[exception]] if it cannot process it or simply wants to let its caller be notified. The syntax may look like this:

```cpp
try  
{ 
  statements; 
} 
catch (TheException& ex) 
{ 
  perform operations before exits; 
  throw; 
} 
```

The statement `throw` rethrows the [[exception]] so that other handlers get a chance to process it.

**LiveExample 16.15** gives an example that demonstrates how to rethrow exceptions.

## **LiveExample 16.15 RethrowExceptionDemo.cpp**
```CPP
#include <iostream>
#include <stdexcept>
using namespace std;

int f1()
{
  try
  {
    throw runtime_error("Exception in f1");
  }
  catch (exception& ex)
  {
    cout << "Exception caught in function f1" << endl;
    cout << ex.what() << endl;
    throw; // Rethrow the exception
  }
}

int main()
{
  try
  {
    f1();
  }
  catch (exception& ex)
  {
    cout << "Exception caught in function main" << endl;
    cout << ex.what() << endl;
  }

  return 0;
}
```
```
command>cl RethrowExceptionDemo.cpp
Microsoft C++ Compiler 2019 
Compiled successful (cl is the VC++ compile/link command)

command>RethrowExceptionDemo 
Exception caught in function f1
Exception in f1
Exception caught in function main
Exception in f1

command>
```

The program invokes [[function]] `f1` in line 23, which throws an [[exception]] in line 9. This [[exception]] is caught in the `catch` block in line 11, and it is rethrown to the main [[function]] in line 15. The `catch` block in the main [[function]] catches the rethrown [[exception]] and processes it in lines 27–28.

## Self-Check

### Suppose that statement2 causes an [[exception]] in the following statement:

```CPP
try 
{
  statement1;
  statement2;
  statement3;
}
catch (Exception1& ex1) 
{
}
catch (Exception2& ex2) 
{
}
catch (Exception3& ex3) 
{
  statement4;
  throw;
}
statement5;
```

Answer the following questions:  
1. Will statement5 be executed if the [[exception]] is not caught?  
2. If the [[exception]] is of type Exception3, will statement4 be executed, and will statement5 be executed?  

#### Answer
1. No.  
2. This [[exception]] is caught by the catch (Exception3 e3) clause and statement4 will be executed, but statement5 will not be executed because it is rethrown to its caller.



# References
