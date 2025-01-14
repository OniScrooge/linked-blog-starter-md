# Summary

# Learning Objectives

# Related
Prev - [[COSC Chapter 9.9 Data Field Encapsulation]]

Next - [[COSC Chapter 9.11 Class abstraction and encapsulation]]
# Content
## Key Point
The scope of data fields is the entire class, regardless of where the data fields are declared.

**Chapter 6** discussed the scope of global variables, local variables, and static local variables. Global variables are declared outside all functions and are accessible to all functions in its scope. The scope of a global variable starts from its declaration and continues to the end of the program. Local variables are defined inside functions. The scope of a local variable starts from its declaration and continues to the end of the block that contains the variable. Static local variables are permanently stored in the program so they can be used in the next call of the function.

The data fields are declared as variables and are accessible to all constructors and functions in the class. Data fields and functions can be in any order in a class. For example, all the following declarations are the same:
![The figure illustrates 3 sets of code.](https://cite-media.pearson.com/legacy_paths/053648c0-9a45-491d-8109-7704372a554d/09fig09_New.png "click to zoom")


>[!Tip]
Though the class members can be in any order, the common style in C++ is to place public members first and then private members.

This section discusses the scope rules of all the variables in the context of a class.

You can declare a variable for data field only once, but you can declare the same variable name in a function many times in different functions.

Local variables are declared and used inside a function locally. If a local variable has the same name as a data field, the local variable takes precedence, and the data field with the same name is shaddowed. For example, in the program in ​**LiveExample ​9.12**​, `x` is defined as a data field and as a local variable in the function.

## **LiveExample 9.12 ShadowDataField.cpp**
```cpp
#include <iostream>
using namespace std;

class Foo
{
public:
  int x; // Data field
  int y; // Data field

  Foo()
  {
    x = 10;
    y = 10;
  }

  void p()
  {
    int x = 20; // Local variable
    cout << "x is " << x << endl;
    cout << "y is " << y << endl;
  }
};

int main()
{
  Foo foo;
  foo.p();
  
  return 0;
}
```
```
command>cl ShadowDataField.cpp
Microsoft C++ Compiler 2019 
Compiled successful (cl is the VC++ compile/link command)

command>ShadowDataField 
x is 20
y is 10

command>
```

Why is the printout `20` for `x` and `10` for `y`? Here is why:
- `x` is declared as a data field in the `Foo` class, but is also defined as a local variable in the function `p()` with an initial value of `20`. The latter `x` is displayed to the console in line 19.
- `y` is declared as a data field, so it is accessible inside function `p()`.

>[!Tip]
As demonstrated in the example, it is easy to make mistakes. To avoid confusion, do not declare the same variable name twice in a class, except for function parameters.

## Self-Check
### Can data fields and functions be placed in any order in a class?
Yes.
# References
