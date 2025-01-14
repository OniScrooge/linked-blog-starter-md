# Summary

# Learning Objectives

# Related

# Content

# Key Point

The functions `seekg()` and `seekp()` can be used to move file pointer to any position in a random-access file for input and output.

A file consists of a sequence of bytes. A special marker called [file pointer](https://revel-ise.pearson.com/courses/66e7050d84448f59a62c6945/pages/urn:pearson:entity:1686882c-38d4-46d9-81e0-4480ea585048?source=dashboard#) is positioned at one of these bytes. A read or write operation takes place at the location of the file pointer. When a file is opened, the file pointer is set at the beginning of the file. When you read or write data to the file, the file pointer moves forward to the next data item. For example, if you read a character using the `get()` function, C++ reads one byte from the file pointer, and now the file pointer is `1` byte ahead of the previous location, as shown in **Figure 13.6**.
![[Pasted image 20241006214735.png]]

All the programs you have developed so far read/write data sequentially. This is called [sequential access file](https://revel-ise.pearson.com/courses/66e7050d84448f59a62c6945/pages/urn:pearson:entity:1686882c-38d4-46d9-81e0-4480ea585048?source=dashboard#). That is, the file pointer always moves forward. If a file is open for input, it starts to read data from the beginning to the end. If a file is open for output, it writes data one item after the other from the beginning or from the end (with the append mode `ios::app`).

The problem with sequential access is that in order to read a byte in a specific location, all the bytes that precede it must be read. This is not efficient. C++ enables the file pointer to jump backward or forward freely using the `seekp` and `seekg` member functions on a stream object. This capability is known as [random access file](https://revel-ise.pearson.com/courses/66e7050d84448f59a62c6945/pages/urn:pearson:entity:1686882c-38d4-46d9-81e0-4480ea585048?source=dashboard#).

The `seekp` (“seek put”) function is for the output stream, and the `seekg` (“seek get”) function is for the input stream. Each function has two versions with one argument or two arguments. With one argument, the argument is the absolute location. For example,

```cpp
input.seekg(0); 
output.seekp(0); 
```

moves the file pointer to the beginning of the file.

With two arguments, the first argument is an integer that indicates an offset, and the second argument, known as the _seek base_, specifies where to calculate the offset from. **Table 13.3** lists the three possible seek base arguments.

| Table 13.3    |                                                       |
| ------------- | ----------------------------------------------------- |
| **Seek Base** | **Description**                                       |
| `ios::beg`    | Calculates the offset from the beginning of the file. |
| `ios::end`    | Calculates the offset from the end of the file.       |
| `ios::cur`    | Calculates the offset from the current file pointer.  |

**Table 13.4** gives some examples of using the `seekp` and `seekg` functions.

| Table 13.4               |                                                                                   |
| ------------------------ | --------------------------------------------------------------------------------- |
| **Statement**            | **Description**                                                                   |
| `seekg(100, ios::beg);`  | Moves the file pointer to the `100th` byte from the beginning of the file.        |
| `seekg(-100, ios::end);` | Moves the file pointer to the `100th` byte backward from the end of the file.     |
| `seekp(42, ios::cur);`   | Moves the file pointer to the `42nd` byte forward from the current file pointer.  |
| `seekp(-42, ios::cur);`  | Moves the file pointer to the `42nd` byte backward from the current file pointer. |
| `seekp(100);`            | Moves the file pointer to the ﻿`100th` byte in the file.                          |

You can also use the `tellp` and `tellg` functions to return the position of the file pointer in the file.

**LiveExample 13.19** demonstrates how to access a file randomly. The program first stores `10` student objects into the file and then retrieves the third student from the file.
```C++
#include <iostream>
#include <fstream>
#include "Student.h"
using namespace std;

void displayStudent(const Student& student)
{
  cout << student.getFirstName() << " ";
  cout << student.getMi() << " ";
  cout << student.getLastName() << " ";
  cout << student.getScore() << endl;
}

int main()
{ 
  fstream binaryio; // Create stream object
  binaryio.open("student.dat", ios::out | ios::binary);
	
  Student student1("FirstName1", 'A', "LastName1", 10);
  Student student2("FirstName2", 'B', "LastName2", 20);
  Student student3("FirstName3", 'C', "LastName3", 30);
  Student student4("FirstName4", 'D', "LastName4", 40);
  Student student5("FirstName5", 'E', "LastName5", 50);
  Student student6("FirstName6", 'F', "LastName6", 60);
  Student student7("FirstName7", 'G', "LastName7", 70);
  Student student8("FirstName8", 'H', "LastName8", 80);
  Student student9("FirstName9", 'I', "LastName9", 90);
  Student student10("FirstName10", 'J', "LastName10", 100);

  binaryio.write(reinterpret_cast<char*>
    (&student1), sizeof(Student));
  binaryio.write(reinterpret_cast<char*>
    (&student2), sizeof(Student));
  binaryio.write(reinterpret_cast<char*>
    (&student3), sizeof(Student));
  binaryio.write(reinterpret_cast<char*>
    (&student4), sizeof(Student));
  binaryio.write(reinterpret_cast<char*>
    (&student5), sizeof(Student));
  binaryio.write(reinterpret_cast<char*>
    (&student6), sizeof(Student));
  binaryio.write(reinterpret_cast<char*>
    (&student7), sizeof(Student));
  binaryio.write(reinterpret_cast<char*>
    (&student8), sizeof(Student));
  binaryio.write(reinterpret_cast<char*>
    (&student9), sizeof(Student));
  binaryio.write(reinterpret_cast<char*>
    (&student10), sizeof(Student));

  binaryio.close();

  // Read student back from the file
  binaryio.open("student.dat", ios::in | ios::binary);

  Student studentNew;
  // Move to the 3rd student
  binaryio.seekg(2 * sizeof(Student)); 
  cout << "Current position is " << binaryio.tellg() 
    << endl;

  binaryio.read(reinterpret_cast<char*>
    (&studentNew), sizeof(Student));

  displayStudent(studentNew);

  cout << "Current position is " << binaryio.tellg() << endl;

  binaryio.close();

  return 0;
}
```

```
command>cl RandomAccessFile.cpp
Microsoft C++ Compiler 2019 
Compiled successful (cl is the VC++ compile/link command)

command>RandomAccessFile 
Current position is 112
FirstName3 C LastName3 30
Current position is 168

command>
```

The program creates a stream object in line 16, opens the file **student.dat** for binary output in line 17, creates ten `Student` objects in lines 19–28, writes them to the file in lines 30–49, and closes the file in line 51.

The program opens the file **student.dat** for binary input in line 54, creates a `Student` object using its no-arg construction in line 56, and moves the file pointer to the address of the third student in the file in line 58. The current position is now at `112`. (Note that `sizeof(Student)` is `56`.) After the third object is read, the file pointer is moved to the fourth object. So, the current position becomes `168`.

## Self-Check

### What is the file pointer?

A file consists of a sequence of bytes. There is a special marker called file pointer that is positioned at one of these bytes.

### What are the differences between `seekp` and `seekg`?

The function `seekp` is to move the file pointer for writing and `seekg` is for moving the file pointer for reading.


# References
