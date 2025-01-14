# Summary

# Learning Objectives

# Related
Prev - [[COSC Chapter 10.2.13 Case Study - Replacing Strings]]

Next - [[COSC Chapter 10.4 Array of objects]]
# Content
## Key Point

Objects can be passed to a function by value or by reference, but it is more efficient to pass objects by reference.

So far, you have learned how to pass arguments of primitive types, array types, and string types to functions. You can pass any types of objects to functions. You can pass objects by value or by reference. **LiveExample 10.3** gives an example that passes an object by value.

## **LiveExample 10.3 PassObjectByValue.cpp**
```cpp
#include <iostream>
// CircleWithPrivateDataFields.h is defined in Section 9.9
#include "CircleWithPrivateDataFields.h" 
using namespace std;

void printCircle(Circle c) // Pass a Circle object by value
{
  cout << "The area of the circle of "
    << c.getRadius() << " is " << c.getArea() << endl;
}

int main()
{
  Circle myCircle(5.0);
  printCircle(myCircle); 

  return 0;
}
```
```
command>cl PassObjectByValue.cpp
Microsoft C++ Compiler 2019 
Compiled successful (cl is the VC++ compile/link command)

command>PassObjectByValue 
The area of the circle of 5 is 78.5397

command>
```

The `Circle` class defined CircleWithPrivateDataFields.h from **Listing 9.9** is included in line 3. The parameter for the `printCircle` function is defined as `Circle` (line 6). The `main` function creates a `Circle` object `myCircle` (line 14) and passes it to the `printCircle` function by value (line 15). To pass an object argument by value is to copy the object to the function parameter. So the object `c` in the `printCircle` function is independent of the object `myCircle` in the main function, as shown in **Figure 10.9a**.

## Figure 10.9
![[Pasted image 20241207153116.png]]

**LiveExample 10.4** gives an example that passes an object by reference.

## **LiveExample 10.4 PassObjectByReference.cpp**
```cpp
#include <iostream>
#include "CircleWithPrivateDataFields.h"
using namespace std;

void printCircle(Circle& c) // Pass a Circle object by reference
{
  cout << "The area of the circle of "
    << c.getRadius() << " is " << c.getArea() << endl;
}

int main()
{
  Circle myCircle(5.0);
  printCircle(myCircle); 

  return 0;
}
```
```command>cl PassObjectByReference.cpp
Microsoft C++ Compiler 2019 
Compiled successful (cl is the VC++ compile/link command)

command>PassObjectByReference 
The area of the circle of 5 is 78.5397

command>

```

A reference parameter of the `Circle` type is declared in the `printCircle` function (line 5). The `main` function creates a `Circle` object `myCircle` (line 13) and passes the reference of the object to the `printCircle` function (line 14). So the object `c` in the printCircle function is essentially an alias of the object `myCircle` in the main function, as shown in **Figure 10.9b**.

Though you can pass an object to a function by value or by reference, passing by reference is preferred, because it takes time and additional memory space to pass by value.

## Self-Check
### Why is passing by reference preferred for passing an object to a function?
Because it saves memory and is more efficient.
### Answer the questions:
(a) What is the output of the following code?  
(b) What will be the output if the increment function header is changed to "void increment(Count& c, int times)"?  
(c) What will be the output if the increment function header is changed to "void increment(Count& c, int& times)"?

#### Answer
```cpp
#include <iostream>
using namespace std;

class Count
{
public:
  int count;

  Count(int c)
  {
    count = c;
  }

  Count()
  {
    count = 0;
  }
};

void increment(Count c, int times)
{
  c.count++;
  times++;
}

int main()
{
  Count myCount;
  int times = 0;

  for (int i = 0; i < 100; i++)
    increment(myCount, times);

  cout << "myCount.count is " << myCount.count;
  cout << " times is " << times;

  return 0;
}
```

(a) myCount.count is 0 times is 0  
(b) myCount.count is 100 times is 0  
(c) myCount.count is 100 times is 100

### Answer the questions:
(a) What is the output of the following code?  
(b) What is the output if the function header is changed to "void toUpperCase(string& s1, string& s2)"?
```cpp
#include <iostream>
#include <string>
using namespace std;

void toUpperCase(string& s1, string s2) 
{
  s2 = s1;
  for (unsigned i = 0; i < s1.length(); i++)
    s2[i] = toupper(s1[i]);
}

int main()
{
  string s1 = "Welcome";
  string s2;
  toUpperCase(s1, s2);
  cout << s2 << endl;

  return 0;
}
```
#### Answer
(a) Nothing is printed, because s2 is empty. Note that it is pass-be-value for s2 when invoking upperCase(s1, s2) in this case.  
(b) WELCOME
# References
