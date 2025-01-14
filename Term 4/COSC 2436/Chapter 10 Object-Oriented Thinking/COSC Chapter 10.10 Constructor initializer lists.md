# Summary

# Learning Objectives

# Related
Prev - [[COSC Chapter 10.9 Case Study - The StackOfIntegers Class]]

Next - [[COSC Chapter 10.11 Class design guidelines]]
# Content
## Key Point
Constructor initializer lists can be used to set initial values for [[object]] [[data fields]].

[[Data fields]] may be initialized in the constructor using an [[initializer list]] in the following syntax:
```cpp
ClassName(parameterList) 
  : datafield1(value1), datafield2(value2) // Initializer list 
{ 
  // Additional statements if needed 
} 
```

The [[initializer list]] initializes `datafield1` with `value1` and `datafield2` with `value2`.

For example, see the following constructors.
![[Pasted image 20241207160529.png]]
![[Pasted image 20241207160536.png]]

Constructor in (b), which does not use an [[initializer list]], is actually more intuitive than the one in (a). However, using an [[initializer list]] is necessary to initialize [[object]] [[data fields]] that don’t have a [[no-arg constructor]].

In C++, you can declare an object data field. For example, `name` is declared as a `string` object in the following code:

```cpp
class Student 
{ 
public: 
  Student(); 
 
private: 
  string name; 
}; 
```

However, declaring an object data field in a class is different from declaring a local object in a function like this:

```cpp
int main() 
{ 
  string name; 
}; 
```

As an object data field, the object is not created when it is declared. As an object declared in a function, the object is created when it is declared.

In C++11, primitive data fields can be declared with an initial value. However, a data field of the object type must be declared with a no-arg constructor. For example, the following code is wrong:

```cpp
class Student 
{ 
public: 
  Student(); 
 
private: 
  int age = 5; // OK 
  string name("Peter"); // Wrong, must use a no-arg constructor 
}; 
```

The correct declaration is

```cpp
class Student 
{ 
public: 
  Student(); 
 
private: 
  int age = 5; 
  string name; // Declare a data field of the string type 
}; 
```

If a data field is of an object type, the no-arg constructor for the object type is automatically invoked to construct an object for the data field. If the no-arg constructor does not exist, a compile error will occur. For example, the code in **LiveExample 10.17** has an error, because the `time` data field (line 42) in the `Action` class is of the `Time` class that does not have a no-arg constructor.

## **LiveExample 10.17 NoArgConstructorNeeded.cpp**
```cpp
#include <iostream>
#include <string>
using namespace std;

class Time
{
public:
  Time(int newHour, int newMinute, int newSecond)
  {
     hour = newHour;
     minute = newMinute;
     second = newSecond;
  }
  
  int getHour()
  {
    return hour;
  }

private:
  int hour;
  int minute;
  int second;
};

class Action
{
public:
  Action(const string& newActionName, int hour, int minute, int second)
  {
    actionName = newActionName;
    time = Time(hour, minute, second);
  }

  Time getTime() 
  {
    return time;
  }

private:
  string actionName;
  Time time;
};

int main()
{
  Action action("Go to class", 11, 30, 0);
  cout << action.getTime().getHour() << endl;

  return 0;
}
```
```
[c:\example>cl NoArgConstructorNeeded.cpp
Microsoft C++ Compiler 2017 
NoArgConstructorNeeded.cpp(29): error C2512: 'Time': no no-arg constructor available
NoArgConstructorNeeded.cpp(6): note: see declaration of 'Time'

c:\example>](file:///C:/example%3Ecl%20NoArgConstructorNeeded.cppMicrosoft%20C++%20Compiler%202017%20NoArgConstructorNeeded.cpp(29):%20error%20C2512:%20'Time':%20no%20no-arg%20constructor%20availableNoArgConstructorNeeded.cpp(6):%20note:%20see%20declaration%20of%20'Time'c:/example%3E)
```
To fix this error, you have to use the constructor initializer list as shown in **LiveExample 10.18**. The data field `time` is initialized using an initializer list (line 30).

## **LiveExample 10.18 UseConstructorInitializer.cpp**
```cpp
#include <iostream>
#include <string>
using namespace std;

class Time
{
public:
  Time(int newHour, int newMinute, int newSecond)
  {
     hour = newHour;
     minute = newMinute;
     second = newSecond;
  }
  
  int getHour()
  {
    return hour;
  }

private:
  int hour;
  int minute;
  int second;
};

class Action
{
public:
  Action(const string& newActionName, int hour, int minute, int second)
    :time(hour, minute, second)
  {
    actionName = newActionName;
  }

  Time getTime() 
  {
    return time;
  }

private:
  string actionName;
  Time time;
};

int main()
{
  Action action("Go to class", 11, 30, 0);
  cout << action.getTime().getHour() << endl;

  return 0;
}
```
```
command>cl UseConstructorInitializer.cpp
Microsoft C++ Compiler 2019 
Compiled successful (cl is the VC++ compile/link command)

command>UseConstructorInitializer 
11

command>
```

## Self-Check
### How do you use the constructor initializer list to simplify the implementation of Time constructor and Action constructor in LiveExample 10.18?

Action(const string& newActionName, int hour, int minute, int second)
  :time(hour, minute, second)

### What is wrong in the following code?
```cpp
#include <iostream>
#include <string>
using namespace std;

class A
{
public:
  A() { };
  string s("abc");
};

int main()
{
  A a;
  cout << a.s << endl;

  return 0;
}
```

You have to initialize an object in the constructor if a constructor with arguments is used. So, the following code will work
```cpp
public:
  A() : s("abs")
  {            
  };
            
  string s;
};
```
# References
