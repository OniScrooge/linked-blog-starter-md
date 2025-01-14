# Summary

# Learning Objectives

# Related
Prev - [[COSC 13.2.4 Testing End of File]]

Next - [[COSC 13.3 Formatting Output]]
# Content

In the preceding examples, the file names are string literals hard-coded in the program. In many cases, it is desirable to let the user enter the name of a file at runtime. **LiveExample 13.4** gives an example that prompts the user to enter a file name and checks whether the file exists.

**LiveExample 13.4 CheckFile.cpp**
```C++
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main()
{
  string filename;
  cout << "Enter a file name: ";
  cin >> filename;

  ifstream input(filename.c_str());
  
  if (input.fail())
    cout << filename << " does not exist" << endl;
  else
    cout << filename << " exists" << endl;

  return 0;
}
```

```
command>cl CheckFile.cpp
Microsoft C++ Compiler 2019 
Compiled successful (cl is the VC++ compile/link command)

command>CheckFile 
Enter a filename: c:\example\Welcome.cpp
c:\example\Welcome.cpp exists

command>
```

In the preceding examples, the file names are string literals hard-coded in the program. In many cases, it is desirable to let the user enter the name of a file at runtime. **LiveExample 13.4** gives an example that prompts the user to enter a file name and checks whether the file exists.

#### **LiveExample 13.4 CheckFile.cpp**

The program prompts the user to enter a file name as a string (line 10). However, the file name passed to the input and output stream constructor or to the `open` function must be a C-string prior to C++11. So, the `c_str()` function in the `string` class is invoked to return a C-string from a `string` object (line 12).

>[!Note]
In C++11, you can also pass a `string` as the file name in the `open` function.

## Self-Check

### Should you pass a filename as a string or a C-string to create an input and output stream object or to the open function?

Before C++11, you must pass a C-String as a filename to create an ifstream or ofstream object or to the open function. In C++, the filename can be a string.


# References
