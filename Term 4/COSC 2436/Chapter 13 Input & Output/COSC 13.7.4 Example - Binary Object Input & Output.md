# Summary

# Learning Objectives

# Related

# Content

This section gives an example of writing objects to a binary file and reading the objects back from the file.

**LiveExample 13.1** writes student records into a text file. A student record consists of first name, middle initial, last name, and score. These fields are written to the file separately. A better way of processing is to define a class to model records. Each record is an object of the `Student` class.

Let the class be named `Student` with the data fields `firstName`, `mi`, `lastName`, and `score`, their supporting accessors and mutators, and two constructors. The class UML diagram is shown in **Figure 13.5**.
![[Pasted image 20241006214318.png]]

**LiveExample 13.16** defines the `Student` class in the header file, and **LiveExample 13.17** implements the class. Note that the first name and last name are stored in two arrays of characters with a fixed-length `25` internally (lines 22, 24), so that every student record will have the same size. This is necessary to ensure that students can be read from the file correctly. Since it is easier to use the `string` type than C-string, the `string` type is used in the `get` and `set` functions for `firstName` and `lastName` (lines 12, 14, 16, 18).

**LiveExample 13.16 Student.h**
```C++
#ifndef STUDENT_H
#define STUDENT_H
#include <string>
using namespace std;

class Student
{
public:
  Student();
  Student(const string& firstName, char mi, 
    const string& lastName, int score);
  void setFirstName(const string& s);
  void setMi(char mi);
  void setLastName(const string& s);
  void setScore(int score);
  string getFirstName() const;
  char getMi() const;
  string getLastName() const;
  int getScore() const;

private:
  char firstName[25];
  char mi;
  char lastName[25];
  int score;
};

#endif
```

**LiveExample 13.17 Student.cpp**
```C++
#include "Student.h"
#include <cstring>

// Construct a default student
Student::Student()
{
}

// Construct a Student object with specified data
Student::Student(const string& firstName, char mi, 
  const string& lastName, int score)
{
  setFirstName(firstName);
  setMi(mi);
  setLastName(lastName);
  setScore(score);
}

void Student::setFirstName(const string& s)
{
  strcpy(firstName, s.c_str());
}

void Student::setMi(char mi)
{
  this->mi = mi;
}

void Student::setLastName(const string& s)
{
   strcpy(lastName, s.c_str());
}

void Student::setScore(int score)
{
  this->score = score;
}

string Student::getFirstName() const
{
  return string(firstName);
}

char Student::getMi() const
{
  return mi;
}

string Student::getLastName() const
{
  return string(lastName);
}

int Student::getScore() const
{
  return score;
}
```

**LiveExample 13.18** gives a program that creates four `Student` objects, writes them to a file named student.dat, and reads them back from the file.
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

  Student student1("John", 'T', "Smith", 90);
  Student student2("Eric", 'K', "Jones", 85);
  Student student3("Susan", 'T', "King", 67);
  Student student4("Kim", 'K', "Peterson", 95);

  binaryio.write(reinterpret_cast<char*>
    (&student1), sizeof(Student));
  binaryio.write(reinterpret_cast<char*>
    (&student2), sizeof(Student));
  binaryio.write(reinterpret_cast<char*>
    (&student3), sizeof(Student));
  binaryio.write(reinterpret_cast<char*>
    (&student4), sizeof(Student));

  binaryio.close();
 
  // Read student back from the file
  binaryio.open("student.dat", ios::in | ios::binary);

  Student studentNew;

  binaryio.read(reinterpret_cast<char*>
    (&studentNew), sizeof(Student));

  displayStudent(studentNew);
   
  binaryio.read(reinterpret_cast<char*>
    (&studentNew), sizeof(Student));

  displayStudent(studentNew);

  binaryio.close();

  return 0;
}
```

```
command>cl BinaryObjectIO.cpp
Microsoft C++ Compiler 2019 
Compiled successful (cl is the VC++ compile/link command)

command>BinaryObjectIO 
John T Smith 90
Eric K Jones 85

command>
```

#### **LiveExample 13.17 Student.cpp**

**LiveExample 13.18** gives a program that creates four `Student` objects, writes them to a file named student.dat, and reads them back from the file.

#### **LiveExample 13.18 BinaryObjectIO.cpp**

The program creates a stream object in line 16, opens the file student.dat for binary output in line 17, creates four `Student` objects in lines 19–22, writes them to the file in lines 24–31, and closes the file in line 33.

The statement to write an object to the file is

```cpp
binaryio.write(reinterpret_cast<char*> 
  (&student1), sizeof(Student)); 
```

The address of object `student1` is cast into the type `char*`. The size of an object is determined by the data fields in the object. Every student has the same size, which is `sizeof(Student)`.

The program opens the file student.dat for binary input in line 36, creates a `Student` object using its no-arg constructor in line 38, reads a `Student` object from the file in lines 40–41, and displays the object’s data in line 43. The program continues to read another object (lines 45–46) and displays its data in line 48.

Finally, the program closes the file in line 50.

## Self-Check

### Will LiveExample 13.8 work if the firstName and lastName are strings in LiveExample 13.6 rather than a fixed-size C-string?

No. In order to use binary IO for objects, the objects must have the same size.

# References
