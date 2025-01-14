# Summary

# Learning Objectives

# Related

# Content

The syntax for the `read` function is

```cpp
streamObject.read(char* address, int size) 
```

The `size` parameter indicates the maximum number of bytes read. The actual number of bytes read can be obtained from a member function `gcount`.

Assume the file city.dat was created in **LiveExample 13.10**. **LiveExample 13.13** reads the bytes using the `read` function.
```C++
#include <iostream>
#include <fstream>
using namespace std;

int main()
{
  fstream binaryio("city.dat", ios::in | ios::binary);
  char s[10];
  binaryio.read(s, 10); // Read into s
  cout << "Number of chars read: " << binaryio.gcount() << endl;
  s[binaryio.gcount()] = '\0'; // Append a C-string terminator
  cout << s << endl;
  binaryio.close();

  return 0;
}
```

```
command>cl BinaryCharInput.cpp
Microsoft C++ Compiler 2019 
Compiled successful (cl is the VC++ compile/link command)

command>BinaryCharInput 
Number of chars read: 7
Atlanta

command>
```

The syntax for the `read` function is

```cpp
streamObject.read(char* address, int size) 
```

The `size` parameter indicates the maximum number of bytes read. The actual number of bytes read can be obtained from a member function `gcount`.

Assume the file city.dat was created in **LiveExample 13.10**. **LiveExample 13.13** reads the bytes using the `read` function.

#### **LiveExample 13.13 BinaryCharInput.cpp**

Line 7 opens the binary file city.dat for input. Invoking `binaryio.read(s, 10)` (line 9) reads up to `10` bytes from the file to the array. The actual number of bytes read can be determined by invoking `binaryio.gcount()` (line 11).

Assume that the file temp.dat was created in **LiveExample 13.11**. **LiveExample 13.14** reads the integer using the `read` function.
```C++
#include <iostream>
#include <fstream>
using namespace std;

int main()
{
  fstream binaryio("temp.dat", ios::in | ios::binary);
  int value;
  binaryio.read(reinterpret_cast<char*>(&value), sizeof(value));
  cout << value << endl;
  binaryio.close(); // Close binaryio
  
  return 0;
}
```

```
command>cl BinaryIntInput.cpp
Microsoft C++ Compiler 2019 
Compiled successful (cl is the VC++ compile/link command)

command>BinaryIntInput 
199

command>
```

The data in the file temp.dat were created in **LiveExample 13.11**. The data consisted of an integer and were cast to characters before stored. This program first read the data as bytes and then used the `reinterpret_cast` operator to cast bytes into an `int` value (line 9).

## Self-Check

### How do you read an int from a binary file and assign it to int variable x?

Create a binary input stream named input. Use:
```C++
input.read(reinterprete_cast<char*>(&x), sizeof(x));
```
# References
