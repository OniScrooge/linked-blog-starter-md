# Summary

# Learning Objectives

# Related

# Content

You can use the `reinterpret_cast` operator to cast data of any type to bytes and vice versa. This section gives an example in **LiveExample 13.15** to write an array of `double` values to a binary file and read it back from the file.

**LiveExample 13.15 BinaryArrayIO.cpp**
```C++
#include <iostream>
#include <fstream>
using namespace std;

int main()
{
  const int SIZE = 5;  // Array size

  fstream binaryio; // Create stream object

  // Write array to the file
  binaryio.open("array.dat", ios::out | ios::binary);
  double array[SIZE] = {3.4, 1.3, 2.5, 5.66, 6.9};
  binaryio.write(reinterpret_cast<char*>(&array), sizeof(array));
  binaryio.close();

  // Read array from the file
  binaryio.open("array.dat", ios::in | ios::binary);
  double result[SIZE];
  binaryio.read(reinterpret_cast<char*>(&result), sizeof(result));
  binaryio.close();

  // Display array
  for (int i = 0; i < SIZE; i++)
    cout << result[i] << " ";

  return 0;
}
```

```
command>cl BinaryArrayIO.cpp
Microsoft C++ Compiler 2019 
Compiled successful (cl is the VC++ compile/link command)

command>BinaryArrayIO 
3.4 1.3 2.5 5.66 6.9 

command>
```

The program creates a stream object in line 9, opens the file array.dat for binary output in line 12, writes an array of `double` values to the file in line 14, and closes the file in line 15.

The program then opens the file array.dat for binary input in line 18, reads an array of `double` values from the file in line 20, and closes the file in line 21.

Finally, the program displays the contents in the array `result` (lines 24–25).

## Self-Check

### How do you write an array list to a binary file?

Create a binary output stream named output. Use  
```C++
output.write(reinterprete_cast<char*>(&list), sizeof(list));
```


# References
