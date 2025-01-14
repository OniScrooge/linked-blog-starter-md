# Summary

# Learning Objectives

# Related

# Content

## Key Point

The functions `eof()`, `fail()`, `good()`, and `bad()` can be used to test the states of stream operations.

You have used the `eof()` function and `fail()` function to test the states of a stream. C++ provides several more functions in a stream for testing [stream states](https://revel-ise.pearson.com/courses/66e7050d84448f59a62c6945/pages/urn:pearson:entity:80e37186-a07e-4bb5-9e53-860ba515907d?source=dashboard#). These functions are listed in **Table 13.2**.

**Table 13.2**  **Stream State Functions**

|   |   |
|---|---|
|**Function**|**Description**|
|`eof()`|Returns `true` if the end of input stream is reached.|
|`fail()`|Returns `true`﻿ if an operation has failed.|
|`bad()`|Returns `true`﻿ if an unrecoverable error has occurred.|
|`good()`|Returns `true`﻿ if an operation is successful.|

**LiveExample 13.9** gives an example to detect the stream states.
```C++
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

void showState(const fstream&);

int main()
{
  fstream inout;

  // Create an output file
  inout.open("temp.txt", ios::out);
  inout << "Dallas";
  cout << "Normal operation (no errors)" << endl;
  showState(inout);
  inout.close();

  // Create an input file
  inout.open("temp.txt", ios::in);

  // Read a string
  string city;
  inout >> city;
  cout << "End of file (no errors)" << endl;
  showState(inout);

  inout.close();

  // Attempt to read after file closed
  inout >> city;
  cout << "Bad operation (errors)" << endl;
  showState(inout);

  return 0;
}

void showState(const fstream& stream)
{
  cout << "Stream status: " << endl;
  cout << "  eof(): " << stream.eof() << endl;
  cout << "  fail(): " << stream.fail() << endl;
  cout << "  bad(): " << stream.bad() << endl;
  cout << "  good(): " << stream.good() << endl;
}
```

```
command>cl ShowStreamState.cpp
Microsoft C++ Compiler 2019 
Compiled successful (cl is the VC++ compile/link command)

command>ShowStreamState 
Normal operation (no errors)
Stream status:
  eof(): 0
  fail(): 0
  bad(): 0
  good(): 1
End of file (no errors)

Stream status:
  eof(): 1
  fail(): 0
  bad(): 0
  good(): 0
Bad operation (errors)

Stream status:
  eof(): 1
  fail(): 1
  bad(): 0
  good(): 0

command>
```

You have used the `eof()` function and `fail()` function to test the states of a stream. C++ provides several more functions in a stream for testing [stream states](https://revel-ise.pearson.com/courses/66e7050d84448f59a62c6945/pages/urn:pearson:entity:80e37186-a07e-4bb5-9e53-860ba515907d?source=dashboard#). These functions are listed in **Table 13.2**.

#### **Table 13.2**

#### **Stream State Functions**

|   |   |
|---|---|
|**Function**|**Description**|
|`eof()`|Returns `true` if the end of input stream is reached.|
|`fail()`|Returns `true`﻿ if an operation has failed.|
|`bad()`|Returns `true`﻿ if an unrecoverable error has occurred.|
|`good()`|Returns `true`﻿ if an operation is successful.|

**LiveExample 13.9** gives an example to detect the stream states.

#### **LiveExample 13.9 ShowStreamState.cpp**

The program creates a `fstream` object using its no-arg constructor in line 10, opens **temp.txt** for output in line 13, and writes a string Dallas in line 14. The state of the stream is displayed in line 15. There are no errors so far.

The program then closes the stream in line 17, reopens **temp.txt** for input in line 20, and reads a string Dallas in line 24. The state of the stream is displayed in line 26. There are no errors so far, but the end of file is reached.

Finally, the program closes the stream in line 28 and attempts to read data after the file is closed in line 31, which causes an error. The state of the stream is displayed in line 33.

When invoking the `showState` function in lines 16, 26, and 33, the stream object is passed to the function by reference.

## Self-Check

### How do you determine the state of I/O operations?

You can use the functions fail(), bad(), good() to find the states of the file operations.

# References
