# Summary

# Learning Objectives

# Related
Prev - [[COSC Chapter 10.6 Constant member functions]]

Next - [[COSC Chapter 10.8 Class relationships]]
# Content
## Key Point
The procedural paradigm focuses on designing functions. The object-oriented paradigm couples data and functions together into objects. Software design using the object-oriented paradigm focuses on objects and operations on objects.

In software development, a paradigm describes a pattern or model. The procedural paradigm solves problems using assignments, selections, loops, functions, and arrays. The study of the procedural paradigm lays a solid foundation for object-oriented programming. The object-oriented paradigm provides more flexibility and modularity for building reusable software. This section uses the object-oriented approach to improve the solution for a problem introduced in **Chapter 3**. Observing the improvements, you will gain insight on the differences between the procedural and object-oriented paradigm and see the benefits of developing reusable code using objects and classes.​

**​LicwExample 3.2**, ComputeAndInterpretBMI.cpp, presented a program for computing body mass index. The program cannot be reused in other programs. To make the code reusable, define a function to compute body mass index as follows:​
```cpp
double getBMI(double weight, double height) 
```

This function is useful for computing body mass index for a specified weight and height. However, it has limitations. Suppose you need to associate the weight and height with a person’s name and birth date. You may declare separate variables to store these values. But these values are not tightly coupled. The ideal way to couple them is to create an object that contains them. Since these values are tied to individual objects, they should be stored in instance data fields. You can define a class named `BMI`, as shown in **Figure 10.11**.

## Figure 10.11
![[Pasted image 20241207154859.png]]

The `BMI` class can be defined as in **LiveExample 10.11**.

## **LiveExample 10.11 BMI.h**
```cpp
#ifndef BMI_H
#define BMI_H

#include <string>
using namespace std;

class BMI
{
public:
  BMI(const string& newName, int newAge, 
    double newWeight, double newHeight);
  BMI(const string& newName, double newWeight, double newHeight);
  double getBMI() const;
  string getStatus() const;
  string getName() const;
  int getAge() const;
  double getWeight() const;
  double getHeight() const;

private:
  string name;
  int age;
  double weight;
  double height;
};

#endif
```

>[!Tip]
The `string`​ ​parameter `newName`​ ​is defined as pass-by-reference using the syntax `string&`​ ​`newName`. This improves performance by preventing the compiler from making a copy of the object being passed into the function. Further, the reference is defined `const`​ ​to prevent `newName`​ ​from being modified accidentally. _You should always pass an object parameter by reference. If the object does not change in the function, define it as a `const`_​ ​_reference parameter_.

>[!Tip]
​​​​If a member function does not change data fields, define it as a `const`_​function_. All member functions in the `BMI`​ ​class are `const`​ ​functions.

Assume that the `BMI` class has been implemented. **LiveExample 10.12** is a test program that uses this class.

## **LiveExample 10.12 UseBMIClass.cpp**
```cpp#include <iostream>
#include "BMI.h"
using namespace std;

int main()
{
  BMI bmi1("John Doe", 18, 145, 70);
  cout << "The BMI for " << bmi1.getName() << " is "
    << bmi1.getBMI() << " " << bmi1.getStatus() << endl;

  BMI bmi2("Susan King", 215, 70);
  cout << "The BMI for " << bmi2.getName() << " is "
    << bmi2.getBMI() << " " + bmi2.getStatus() << endl;

  return 0;
}

```
```
command>cl UseBMIClass.cpp
Microsoft C++ Compiler 2019 
Compiled successful (cl is the VC++ compile/link command)

command>UseBMIClass 
The BMI for John Doe is 20.8051 Normal
The BMI for Susan King is 30.849 Obese

command>
```

Line 7 creates an object `bmi1` for `John Doe` and line 11 creates an object `bmi2` for `Susan` `King.` You can use the instance functions `getName()`, `getBMI()`, and `getStatus()` to return the BMI information in a `BMI` object.

The `BMI`​ ​class can be implemente​d as in **LiveExample 10.13**.​

## **LiveExample 10.13 BMI.cpp**
```cpp
#include <iostream>
#include "BMI.h"
using namespace std;

BMI::BMI(const string& newName, int newAge, 
  double newWeight, double newHeight)
{
  name = newName;
  age = newAge;
  weight = newWeight;
  height = newHeight;
}

BMI::BMI(const string& newName, double newWeight,
  double newHeight)
{
  name = newName;
  age = 20;
  weight = newWeight;
  height = newHeight;
}

double BMI::getBMI() const
{
  const double KILOGRAMS_PER_POUND = 0.45359237;
  const double METERS_PER_INCH = 0.0254;
  double bmi = weight * KILOGRAMS_PER_POUND /
    ((height * METERS_PER_INCH) * (height * METERS_PER_INCH));
  return bmi;
}

string BMI::getStatus() const
{
  double bmi = getBMI();
  if (bmi < 18.5)
    return "Underweight";
  else if (bmi < 25)
    return "Normal";
  else if (bmi < 30)
    return "Overweight";
  else
    return "Obese";
}

string BMI::getName() const
{
  return name;
}

int BMI::getAge() const
{
  return age;
}

double BMI::getWeight() const
{
  return weight;
}

double BMI::getHeight() const
{
  return height;
}
```

The mathematic formula for computing the BMI using weight and height is given in **Section 3.7**, “Case Study: Computing Body Mass Index.” The instance function `getBMI()` returns the BMI. Since the weight and height are instance data fields in the object, the `getBMI()` function can use these properties to compute the BMI for the object.

The instance function `getStatus()` returns a string that interprets the BMI. The interpretation is also given in **Section 3.7**.

This example demonstrates the advantages of using the object-oriented over the procedural paradigm. The procedural paradigm focuses on designing functions. The object-oriented paradigm couples data and functions together into objects. Software design using the object-oriented paradigm focuses on objects and operations on objects. The object-oriented approach combines the power of the procedural paradigm with an added dimension that integrates data with operations into objects.

In procedural programming, data and operations on the data are separate, and this methodology requires sending data to functions. Object-oriented programming places data and the operations that pertain to them within a single entity called an _object_; this approach solves many of the problems inherent in procedural programming. The object-oriented programming approach organizes programs in a way that mirrors the real world, in which all objects are associated with both attributes and activities. Using objects improves software reusability and makes programs easier to develop and easier to maintain.

## Self-Check
### What is the output of the following code?
```cpp
#include <iostream>
#include <string>
#include "BMI.h"
using namespace std;

int main()
{
  string name("John Doe");
  BMI bmi1(name, 18, 145, 70);
  name[0] = 'P';

  cout << "name from bm1.getName() is " << bmi1.getName() << endl;
  cout << "name is " << name << endl;

  return 0;
}
```

```
name from bm1.getName is John Doe  
name is Pohn Doe
```
### In the following code, what will be the output from a.s and b.k in the main function?
```cpp
#include <iostream>
#include <string>
using namespace std;

class A
{
public:
  A() 
  {
    s = "John"; 
  }

  string s;
};

class B
{
public:
  B() 
  {
    k = 4;
  }

  int k;
};

int main()
{
  A a;
  cout << a.s << endl;

  B b;
  cout << b.k << endl;

  return 0;
}
```

```
John  
4
```
### What is wrong in the following code?
```cpp
#include <iostream>
#include <string>
using namespace std;

class A
{
public:
  A() { };

private:
  string s;
};

int main()
{
  A a;
  cout << a.s << endl;

  return 0;
}
```

s is a private member in A. it cannot be accessed from the outside of the class.
# References
