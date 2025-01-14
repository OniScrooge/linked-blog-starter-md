# Summary

# Learning Objectives

# Related

# Content

The syntax for the `write` function is

```cpp
streamObject.write(const char* bytes, int size) 
```

which writes an array of bytes in the type `char*`. Each character is a byte. Here `char*` should be interpreted as an array of bytes, not an array of characters, as shown in **Figure 13.4**.
![[Pasted image 20241006213146.png]]

Note that C++ does not have a data type byte. If C++ had the `byte` type for representing a byte, it would make more sense to use `byte*` rather than `char*`.

**LiveExample 13.10** shows an example of using the `write` function.
```C++
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main()
{
  fstream binaryio("city.dat", ios::out | ios::binary);
  string s = "Atlanta";
  binaryio.write(s.c_str(), s.size()); // Write s to file
  binaryio.close();

  cout << "Done" << endl;

  return 0;
}
```

```
command>cl BinaryCharOutput.cpp
Microsoft C++ Compiler 2019 
Compiled successful (cl is the VC++ compile/link command)

command>BinaryCharOutput 
Done

command>
```

Note that C++ does not have a data type byte. If C++ had the `byte` type for representing a byte, it would make more sense to use `byte*` rather than `char*`.

**LiveExample 13.10** shows an example of using the `write` function.

#### **LiveExample 13.10 BinaryCharOutput.cpp**

Line 8 opens the binary file city.dat for output. Invoking `binaryio.write(s.c_str(),s.size())` (line 10) writes string `s` to the file.

Often you need to write data other than characters. How can you accomplish this? You can use the `reinterpret_cast` operator. The `reinterpret_cast` operator can cast a pointer type to any other pointer type. It simply performs a reinterpretation of the value from one type to the other without altering the data. The syntax of using the `reinterpret_cast` operator is as follows:

```cpp
reinterpret_cast<dataType*>(address) 
```

Here, `address` is the starting address of the data (primitive, array, or object) and `dataType` is the data type you are casting to. In this case for binary I/O, it is `char*`.

For example, see the code in **LiveExample 13.11**.
```C++
#include <iostream>
#include <fstream>
using namespace std;

int main()
{
  fstream binaryio("temp.dat", ios::out | ios::binary);
  int value = 199;
  binaryio.write(reinterpret_cast<char*>(&value), sizeof(value));
  binaryio.close();

  cout << "Done" << endl;

  return 0;
}
```

```
command>cl BinaryIntOutput.cpp
Microsoft C++ Compiler 2019 
Compiled successful (cl is the VC++ compile/link command)

command>BinaryIntOutput 
Done

command>
```

Note that C++ does not have a data type byte. If C++ had the `byte` type for representing a byte, it would make more sense to use `byte*` rather than `char*`.

**LiveExample 13.10** shows an example of using the `write` function.

#### **LiveExample 13.10 BinaryCharOutput.cpp**

Line 8 opens the binary file city.dat for output. Invoking `binaryio.write(s.c_str(),s.size())` (line 10) writes string `s` to the file.

Often you need to write data other than characters. How can you accomplish this? You can use the `reinterpret_cast` operator. The `reinterpret_cast` operator can cast a pointer type to any other pointer type. It simply performs a reinterpretation of the value from one type to the other without altering the data. The syntax of using the `reinterpret_cast` operator is as follows:

```cpp
reinterpret_cast<dataType*>(address) 
```

Here, `address` is the starting address of the data (primitive, array, or object) and `dataType` is the data type you are casting to. In this case for binary I/O, it is `char*`.

For example, see the code in **LiveExample 13.11**.

#### **LiveExample 13.11 BinaryIntOutput.cpp**

Line 9 writes the content in variable `value` to the file. `reinterpret_cast`<`char*`>`(&value)` cast the address of the `int` value to the type `char*`. `sizeof(value)` returns the storage size for the value variable, which is `4`, since it is an `int` type variable.

>[!Note]
For consistency, this book uses the extension `.txt` to name text files and `.dat` to name binary files.

To understand the **reinterpret_cast** operator, consider the following code in **LiveExample 13.12**:
```C++
#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
  float floatValue = 19.5;
  int* p = reinterpret_cast<int*>(&floatValue);
  cout << "int value " << *p << " and float value "  
    << floatValue << "\nhave the same binary representation "
    << hex << *p << endl;

  return 0;
}
```

```
command>cl ReinterpretCastingDemo.cpp
Microsoft C++ Compiler 2019 
Compiled successful (cl is the VC++ compile/link command)

command>ReinterpretCastingDemo 
int value 1100742656 and float value 19.5
have the same binary representation 419c0000

command>
```

The program casts a pointer to a `float` number `19.5` to a pointer of the `int` type (line 8). The same raw data in the memory is reinterpreted as an `int`. The raw data is `419c0000` in hex, which is `1100742656` when interpreted as `int` and `19.5` when interpreted as a `float`. Note that `hex` is a manipulator defined in the `<``iomanip``>` header to display a number in hex

## Self-Check

### How do you open a file for binary I/O?

To open a file for binary I/O, use the ios::binary mode.

### The write function can write only an array of bytes. How do you write a primitive-type value or an object into a binary file?

Use the
```C++
reinterpret_cast<char*>(value) 
```
to cast a value to a character array.

### If you write string "ABC" to an ASCII text file, what values are stored in a file?

The values stored in the text file are 0x41 0x42 0x43.

### If you write string "100" to an ASCII text file, what values are stored in a file? If you write a numeric int value 100 using binary I/O, what values are stored in a file?

If you write string "100" to an ASCII text file, the values stored are 0x31 0x30 0x30. If you write a numeric int value 100 using binary I/O, the value stored in the file is 0x64.

### Use Programming Exercise 5.46 to find out the binary representation for and int value -1. What is the output of the following code?

```C++
int x = -1;
unsigned y = *reinterpret_cast<unsigned*>(&x);
cout << x << endl << y << endl;
```

#### Answer
-1  
4294967295


# References
