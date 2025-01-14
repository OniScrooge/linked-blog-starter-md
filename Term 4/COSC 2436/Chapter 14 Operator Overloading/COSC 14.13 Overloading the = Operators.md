# Summary

# Learning Objectives

# Related

# Content

You need to overload the `=` operator to perform a customized copy operation for an object. 

By default, the `=` operator performs a memberwise copy from one object to the other. For example, the following code copies `r2` to `r1`.

```cpp
Rational r1(1, 2); 
Rational r2(4, 5); 
r1 = r2; 
cout << "r1 is " << r1 << endl; 
cout << "r2 is " << r2 << endl; 
```

So, the output is

```
r1 is 4/5r2 is 4/5
```

The behavior of the `=` operator is the same as that of the default copy constructor. It performs a **shallow copy**, meaning that if the data field is a pointer to some object, the address of the pointer is copied rather than its contents. In **Section 11.15**, “Customizing Copy Constructors,” you learned how to customize the copy constructor to perform a deep copy. However, customizing the copy constructor does not change the default behavior of the assignment copy operator `=`. For example, the `Course` class defined in **LiveExample 11.19**, CourseWithCustomCopyConstructor.h, has a pointer data field named `students` which points to an array of `string` objects. If you run the following code using the assignment operator to assign `course1` to `course2`, as shown in line 9 in **LiveExample 14.10**, you will see that both `course1` and `course2` have the same `students` array, as shown in **Figure 11.6**.

#### **LiveExample 14.10 DefaultAssignmentDemo.cpp**
```CPP
#include <iostream>
#include "CourseWithCustomCopyConstructor.h" // See Listing 11.19
using namespace std;

int main()
{
  Course course1("C++", 10);
  Course course2("Java", 14);
  course2 = course1; // Assign course1 to course2

  course1.addStudent("Peter Pan"); // Add a student to course1
  course2.addStudent("Lisa Ma"); // Add a student to course2

  cout << "students in course1: " <<
    course1.getStudents()[0] << endl;
  cout << "students in course2: " <<
    course2.getStudents()[0] << endl;

  return 0;
}
```

```
command>cl DefaultAssignmentDemo.cpp
Microsoft C++ Compiler 2019 
Compiled successful (cl is the VC++ compile/link command)

command>DefaultAssignmentDemo 
students in course1: Lisa Ma
students in course2: Lisa Ma

command>
```

>[!Note]
>As shown in **Figure 14.2a**, the `students` array in `course1` and `course2` are the same after assigning `course1` to `course2` in line 9. When you add student `"Peter Pan"` to `course1` (line 11), `"Peter Pan"` is assigned to `students[numberOfStudents]`, where `numberOfStudents` is `0`. After the assignment, `numberOfStudents` is increased by `1`, as shown in ​**Figure​ ​14.2b**​.
>
>When you add student `"Lisa Ma"` to `course2` (line 13), `"Lisa Ma"` is assigned to `students[numberOfStudents]`, where `numberOfStudents` is `0`. After the assignment, `numberOfStudents` is increased by `1`, as shown in ​**Figure​ ​14.2c**​.
>
>Now both `course1.getStudents()[0]` and `course2.getStudents()[0]` will be `"Lisa Ma"`.

![[Pasted image 20241007175054.png]]

To change the way the default assignment operator `=` works, you need to overload the `=` operator, as shown in line 17 in **LiveExample 14.11**.

#### **LiveExample 14.11 CourseWithAssignmentOperatorOverloaded.h**

```CPP
#ifndef COURSE_H
#define COURSE_H
#include <string>
using namespace std;

class Course
{
public:
  Course(const string& courseName, int capacity);
  ~Course(); // Destructor
  Course(Course&); // Copy constructor
  string getCourseName() const;
  void addStudent(const string& name);
  void dropStudent(const string& name);
  string* getStudents() const;
  int getNumberOfStudents() const;
  Course& operator=(const Course& course); // Assignment operator

private:
  string courseName;
  string* students;
  int numberOfStudents;
  int capacity;
};

#endif
```

In **LiveExample ​14.11**​, we define​

```cpp
Course& operator=(const Course& course); 
```

Why is the return type `Course` not `void`? C++ allows expressions with chained assignments, such as:

```cpp
course1 = course2 = course3; 
```

In this statement, `course3` is copied to `course2`, and then returns `course2`, and then `course2` is copied to `course1`. So the `=` operator must have a valid return value type.

​​​​​The implementation of the header file is given in **LiveExample ​14.12**​.​

#### **LiveExample 14.12 CourseWithAssignmentOperatorOverloaded.cpp**
```CPP
#include <iostream>
#include "CourseWithAssignmentOperatorOverloaded.h"
using namespace std;

Course::Course(const string& courseName, int capacity)
{
  numberOfStudents = 0;
  this->courseName = courseName;
  this->capacity = capacity;
  students = new string[capacity];
}

Course::~Course()
{
  delete [] students;
}

string Course::getCourseName() const
{
  return courseName;
}

void Course::addStudent(const string& name)
{
  if (numberOfStudents >= capacity)
  {
    cout << "The maximum size of array exceeded" << endl;
    cout << "Program terminates now" << endl;
    exit(0);
  }

  students[numberOfStudents] = name;
  numberOfStudents++;
}

void Course::dropStudent(const string& name)
{
  // Left as an exercise
}

string* Course::getStudents() const
{
  return students;
}

int Course::getNumberOfStudents() const
{
  return numberOfStudents;
}

Course::Course(Course& course) // Copy constructor
{
  courseName = course.courseName;
  numberOfStudents = course.numberOfStudents;
  capacity = course.capacity;
  students = new string[capacity];
  for (int i = 0; i < numberOfStudents; i++)
    students[i] = course.students[i];
}

Course& Course::operator=(const Course& course) // Assignment operator
{
  if (this != &course) // Do nothing with self-assignment
  {
    courseName = course.courseName;
    numberOfStudents = course.numberOfStudents;
    capacity = course.capacity;

    delete [] this->students; // Delete the old array

    // Create a new array with the same capacity as course copied
    students = new string[capacity]; 
    for (int i = 0; i < numberOfStudents; i++)
      students[i] = course.students[i];
  }

  return *this;
}
```

Line 63 tests the case for self-assignment such as (`course = course`). If so, no copy is needed. Line 69 deletes the old array and line 72 creates a new array that has the same capacity as the course being copied. Line 77 returns the calling object using `*this`. Note that `this` is the pointer to the calling object, so `*this` refers to the calling object.

**LiveExample 14.13** gives you a new test program that uses the overloaded `=` operator to copy a `Course` object. As shown in the sample output, the two courses have different `students` array (also see **Figure 14.3**).

#### **LiveExample 14.13 CustomAssignmentDemo.cpp**
```CPP
#include <iostream>
#include "CourseWithAssignmentOperatorOverloaded.h"
using namespace std;

void printStudent(const string names[], int size)
{
  for (int i = 0; i < size; i++) 
    cout << names[i] << (i < size - 1 ? ", " : " ");
}

int main()
{
  Course course1("C++", 10);
  Course course2("Java", 10);

  // Assign course1 to course2
  course2 = course1; 
  course1.addStudent("Peter Pan"); // Add a student to course1
  course2.addStudent("Lisa Ma"); // Add a student to course2

  cout << "students in course1: ";
  printStudent(course1.getStudents(), course1.getNumberOfStudents());
  cout << endl;

  cout << "students in course2: ";
  printStudent(course2.getStudents(), course2.getNumberOfStudents());
  cout << endl;

  return 0;
} 
```

```
command>cl CustomAssignmentDemo.cpp
Microsoft C++ Compiler 2019 
Compiled successful (cl is the VC++ compile/link command)

command>CustomAssignmentDemo 
students in course1: Peter Pan 
students in course2: Lisa Ma 

command>
```

>[!Note]
>As shown in **Figure 14.3a**, the `students` array in `course1` and `course2` are different after assigning `course1` to `course2` in line 17 as result of performing a deep copy, as shown in **Figure 14.3****b**.
>
>When you add student `“Lisa Ma`” to `course2` (line 18), `“Lisa Ma”` is assigned to `students[numberOfStudents]`, where `numberOfStudents` is `0`. After the assignment, `numberOfStudents` is increased by `1,` as shown in **Figure 14.3c**.
>
>Now `students` in `course1` is `“Peter Pan”` and in `course2` are `“Peter Pan”` and `“Lisa Ma”`.

![[Pasted image 20241007175317.png]]

>[!Note]
>The following statement
>
>```cpp
>Course c = c1; 
>```
>
>is equivalent to
>
>```cpp
>Course c(c1); 
>```
>
>which is different from the following statements
>
>```cpp
>Course c; // Create object c using the Course no-arg constructor 
>c = c1; // Assign c1 to c 
>```

>[!Note]
The copy constructor, the `=` assignment operator, and the destructor are called the [[[rule of three]]](https://revel-ise.pearson.com/courses/66e7050d84448f59a62c6945/pages/urn:pearson:entity:1b0dbc98-d009-4a5f-86a8-475a913b3e62?source=dashboard#), or _the Big Three_. If they are not defined explicitly, all three are created by the compiler automatically. You should customize them if the class contains a pointer data field. If you have to customize one of the three, you should customize the other two as well. In C++11, the Big Three rule is expanded to the Big Five with move constructors and move assignments. See Supplement IV.I, “C++11 Move Constructors and Move Assignment,” at **https://liangcpp.pearsoncmg.com/supplement/MoveSemantics.pdf****.**

## Self-Check

### In what situation should you overload the copy constructor, the = operator, and the destructor?

You need to overload the copy constructor, the = operator, and the destructor if the class contains a pointer data field.

### Show the output of the following code:
```CPP
#include <iostream>
#include "CourseWithCustomCopyConstructor.h" // See LiveExample 11.19
using namespace std;

void printStudent(const Course& course)
{
  for (int i = 0; i < course.getNumberOfStudents(); i++)
  {
    cout << course.getStudents()[i] << " ";
  }
  cout << endl;
}

int main()
{
  Course course1("Java Programming", 10);
  course1.addStudent("John");
  Course course2("C++ Programming", 30);
  Course course3("Python Programming", 40);
  course3 = course2 = course1 = course1;

  course1.addStudent("Peter Pan"); // Add a student to course1
  course3.addStudent("Lisa Ma"); // Add a student to course2

  printStudent(course1);
  printStudent(course2);
  printStudent(course3);

  return 0;
}
```

#### Answer

John Peter Pan
John
John Lisa Ma

### If copying to itself is not checked in line 63 in the `opearator=` [[function]] in __LiveExample 14.12__, what will be the output from the preceding question?

John Peter Pan
(note a blank line here)
John Lisa Ma

### If the old array is not deleted in line 69 in the `opearator=` [[function]] in __LiveExample 14.12__, what will be the output from the preceding question? What will happen to the old array?

John Peter Pan
John
John Lisa Ma

The old array is garbage now. It causes memory leak.

# References
