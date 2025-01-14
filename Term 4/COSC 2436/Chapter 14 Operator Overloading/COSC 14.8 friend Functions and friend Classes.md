# Summary

# Learning Objectives

# Related

# Content

## Key Point

You can define a `friend` function or a `friend` class to enable it to access private members in another class.

C++ allows you to overload the stream insertion operator (`<<`) and the stream extraction operator (`>>`). These operators often need to be implemented as `friend` nonmember functions, because they may access private data fields in a class. This section introduces `friend` functions and `friend` _classes_ to prepare you to overload these operators.

Private members of a class cannot be accessed from outside the class. Occasionally, it is convenient to allow some trusted functions and classes to access a class’s private members. C++ enables you to use the `friend` keyword to define `friend` functions and friend classes so that these trusted functions and classes can access another class’s private members.

**​​​​​LiveExample ​14.4**​ gives an example that defines a [[friend class]].​
```CPP
#ifndef DATE_H
#define DATE_H
class Date
{
public:
  Date(int year, int month, int day)
  {
    this->year = year;
    this->month = month;
    this->day = day;
  }

  friend class AccessDate; // AccessDate is a friend of Date

private:
  int year;
  int month;
  int day;
};

#endif
```

The `AccessDate` class (line 13) is defined as a `friend` class for the `Date` class. So, you can directly access private data fields `year`, `month`, and `day` from the `AccessDate` class in **LiveExample 14.5**.
```CPP
#include <iostream>
#include "Date.h"
using namespace std;

class AccessDate
{
public:
  static void p()
  {
    Date birthDate(2010, 3, 4);
    birthDate.year = 2000; // Access private data in Date
    cout << birthDate.year << endl;
  }
};

int main()
{
  AccessDate::p(); // Invoke p() in AccessDate

  return 0;
}
```

```
command>cl TestFriendClass.cpp
Microsoft C++ Compiler 2019 
Compiled successful (cl is the VC++ compile/link command)

command>TestFriendClass 
2000

command>
```

The `AccessDate` class is defined in lines 5−14. A `Date` object is created in the class. Since `AccessDate` is a `friend` class of the `Date` class, the private data in a `Date` object can be accessed in the `AccessDate` class (lines 11−12). The main function invokes the static function `AccessDate::p()` in line 18.

**LiveExample 14.6** gives an example of how to use a `friend` function. The program defines the `Date` class with a `friend` function `p` (line 13). Function `p` is not a member of the `Date` class but can access the private data in `Date`. In function `p`, a `Date` object is created in line 23, and the private field data `year` is modified in line 24 and retrieved in line 25.

```CPP
#include <iostream>
using namespace std;

class Date
{
public:
  Date(int year, int month, int day)
  {
    this->year = year;
    this->month = month;
    this->day = day;
  }
  friend void p(); // p() is a friend function of Date

private:
  int year;
  int month;
  int day;
};

void p()
{
  Date date(2010, 5, 9);
  date.year = 2000;
  cout << date.year << endl;
}

int main()
{
  p();

  return 0;
}
```

```
command>cl TestFriendFunction.cpp
Microsoft C++ Compiler 2019 
Compiled successful (cl is the VC++ compile/link command)

command>TestFriendFunction 
2000

command>
```

## Self-Check

### How do you define a [[friend function]] to access a class's private members?

```CPP
friend void p(); // p() is a friend function of Date
```
See __LiveExample 14.6.__

### How do you define a [[friend class]] to access a class's private members?

```CPP
friend class AccessDate; // AccessDate is a friend of Date
```
See __LiveExample 14.4.__

# References
