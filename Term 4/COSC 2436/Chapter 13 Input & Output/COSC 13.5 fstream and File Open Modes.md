# Summary

# Learning Objectives

# Related

# Content

## Key Point

You can use `fstream` to create a file object for both input and output. 

In the preceding sections, you used the `ofstream` to write data and the `ifstream` to read data. Alternatively, you can use the `fstream` class to create an input or output stream. It is convenient to use `fstream` if your program needs to use the same stream object for both input and output. To open an `fstream` file, you have to specify a [file open mode](https://revel-ise.pearson.com/courses/66e7050d84448f59a62c6945/pages/urn:pearson:entity:71182614-1271-4239-b905-c744053acb0e?source=dashboard#) to tell C++ how the file will be used. The file modes are listed in **Table 13.1**.

**Table 13.1 - File Modes**

|   |   |
|---|---|
|**Mode**|**Description**|
|`ios::in`|Opens a file for input.|
|`ios::out`|Opens a file for output.|
|`ios::app`|Appends all output to the end of the file.|
|`ios::ate`|Opens a file for output. If the file already exists, move to the end of the file. Data can be written anywhere in the file.|
|`ios::trunc`|Discards the file’s contents if the file already exists. (This is the default action for `ios:out`.)|
|`ios::binary`|Opens a file for binary input and output.|

>[!Note]
Some of the file modes also can be used with `ifstream` and `ofstream` objects to open a file. For example, you may use the `ios::app` mode to open a file with an `ofstream` object so that you can append data to the file. However, for consistency and simplicity, it is better to use the file modes with the `fstream` objects.

>[!Note]
Several modes can be combined using the `|` operator. This is a bitwise inclusive-OR operator. See ​**Appendix E** for more detai​ls. For example, to open an output file named **city.txt** for appending data, you can use the following statement:

```cpp
stream.open("city.txt", ios::out | ios::app); 
```

**LiveExample 13.8** gives a program that creates a new file named **city.txt** (line 11) and writes data to the file. The program then closes the file and reopens it to append new data (line 19), rather than overriding it. Finally, the program reads all data from the file.
```C++
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main()
{
  fstream inout;

  // Create a file
  inout.open("city.txt", ios::out);

  // Write cities
  inout << "Dallas" << " " << "Houston" << " " << "Atlanta" << " ";

  inout.close();

  // Open a file named city.txt for appending
  inout.open("city.txt", ios::out | ios::app);

  // Write cities
  inout << "Savannah" << " " << "Austin" << " " << "Chicago";

  inout.close();

  string city;

  // Open the file
  inout.open("city.txt", ios::in);
  while (!inout.eof()) // Continue if not end of file
  {
    inout >> city;
    cout << city << " ";
  }

  inout.close();

  return 0;
} 
```

```
command>cl AppendFile.cpp
Microsoft C++ Compiler 2019 
Compiled successful (cl is the VC++ compile/link command)

command>AppendFile 
Dallas Houston Atlanta Savannah Austin Chicago

command>
```

The program creates an `fstream` object in line 8 and opens the file **city.txt** for output using the file mode `ios::out` in line 11. After writing data in line 14, the program closes the stream in line 16.

The program uses the same stream object to reopen the text file with the combined modes `ios::out | ios::app` in line 19. The program then appends new data to the end of the file in line 22 and closes the stream in line 24.

Finally, the program uses the same stream object to reopen the text file with the input mode `ios::in` in line 29. The program then reads all data from the file (lines 30–34).

## Self-Check

### How do you open a file so that you can append data into the file?

Use `ios::app`

### What is the file open mode `ios::trunc`?

`ios::trunc` discards the file contents. This is the default for `fostream`.
# References
