# Summary

# Learning Objectives

# Related

# Content

You can update a binary file by opening a file using the mode `ios::in | ios:out | ios::binary`. 

Often you need to update the contents of the file. You can open a file for both input and output. For example,

```cpp
binaryio.open("student.dat", ios::in | ios::out | ios::binary); 
```

This statement opens the binary file student.dat for both input and output.

**LiveExample 13.20** demonstrates how to update a file. Suppose file student.dat already has been created with ten `Student` objects from **LiveExample 13.19**. The program first reads the second student from the file, changes the last name, writes the revised object back to the file, and reads the new object back from the file.

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

  // Open file for input and output
  binaryio.open("student.dat", ios::in | ios::out | ios::binary);

  Student student1;
  binaryio.seekg(sizeof(Student)); // Move to the 2nd student
  binaryio.read(reinterpret_cast<char*>
    (&student1), sizeof(Student)); // Read the 2nd student
  displayStudent(student1);

  student1.setLastName("Yao"); // Modify 2nd student
  binaryio.seekp(sizeof(Student)); // Move to the 2nd student
  binaryio.write(reinterpret_cast<char*>
    (&student1), sizeof(Student)); // Update 2nd student in the file

  Student student2;
  binaryio.seekg(sizeof(Student)); // Move to the 2nd student
  binaryio.read(reinterpret_cast<char*>
    (&student2), sizeof(Student)); // Read the 2nd student
  displayStudent(student2);

  binaryio.close();

  return 0;
}
```

```
command>cl UpdateFile.cpp
Microsoft C++ Compiler 2019 
Compiled successful (cl is the VC++ compile/link command)

command>UpdateFile 
FirstName2 B LastName2 20
FirstName2 B Yao 20

command>
```

The program creates a stream object in line 16 and opens the file student.dat for binary input and output in line 19.

The program moves to the second student in the file (line 22) and reads the student (lines 23–24), displays it (line 25), changes its last name (line 27), and writes the revised object back to the file (lines 29–30).

The program then moves to the second student in the file again (line 33) and reads the student (lines 34–35) and displays it (line 36). You will see that the last name of this object has been changed in the sample output.

# References
