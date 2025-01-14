# Summary

# Learning Objectives

# Related
Prev - [[COSC Chapter 15.8  The C++11 `override` and `final` Keywords]]

Next - [[COSC Chapter 15.10 Abstract Classes and Pure Virtual Functions]]
# Content

## Key Point

A protected member of a class can be accessed from a [[derived class]].

So far, you have used the `private` and `public` keywords to specify whether data fields and functions can be accessed from outside the class. Private members can be accessed only from inside the class or from `friend` functions and `friend` classes, and public members can be accessed from any other classes.

Often it is desirable to allow derived classes to access data fields or functions defined in the [[base class]] but not allow nonderived classes to do so. For this purpose, you can use the [protected](https://revel-ise.pearson.com/courses/66e7050d84448f59a62c6945/assignments/711c7caf-6fd2-4d48-b657-33274573990d/pages/urn:pearson:entity:36b96031-f1a3-445b-9b29-cbb817b5b364?source=dashboard#) keyword. A protected data field or a protected [[function]] in a [[base class]] can be accessed in its derived classes.

The keywords `private`, `protected`, and `public` are known as _visibility_ or _accessibility keywords_ because they specify how class and class members are accessed. Their visibility increases in this order:

**LiveExample 15.15** demonstrates the use of `protected` keywords.

## **LiveExample 15.15 VisibilityDemo.cpp**
```CPP
#include <iostream>
using namespace std;

class B
{
public:
  int i;

protected:
  int j;

private:
  int k;
};

class A: public B
{
public:
  void display() const
  {
    cout << i << endl; // Fine, can access it
    cout << j << endl; // Fine, can access it
    cout << k << endl; // Wrong, cannot access it
  }
};

int main()
{
  A a;
  cout << a.i << endl; // Fine, can access it
  cout << a.j << endl; // Wrong, cannot access it
  cout << a.k << endl; // Wrong, cannot access it

  return 0;
}
```
```
c:\example>cl VisibilityDemo.cpp
Microsoft C++ Compiler 2017
VisibilityDemo.cpp
VisibilityDemo.cpp(23) : error C2248: 'B::k' : cannot 
access private member declared in class 'B'
VisibilityDemo.cpp(13) : see declaration of 'B::k'
VisibilityDemo.cpp(5) : see declaration of 'B'
VisibilityDemo.cpp(31) : error C2248: 'B::j' : cannot access 
protected member declared in class 'B'
VisibilityDemo.cpp(10) : see declaration of 'B::j'
VisibilityDemo.cpp(5) : see declaration of 'B'
VisibilityDemo.cpp(32) : error C2248: 'B::k' : cannot access 
private member declared in class 'B'
VisibilityDemo.cpp(13) : see declaration of 'B::k'
VisibilityDemo.cpp(5) : see declaration of 'B'

c:\example>
```

Since `A` is derived from `B` and `j` is protected, `j` can be accessed from class `A` in line 22. Since `k` is private, `k` cannot be accessed from class `A` in line 23.

Since `i` is public, `i` can be accessed from `a``.``i` in line 30. Since `j` and `k` are not public, they cannot be accessed from the object `a` in lines 31–32.

## Self-Check

### If a member is declared private in a class, can it be accessed from other classes? If a member is declared protected in a class, can it be accessed from other classes? If a member is declared public in a class, can it be accessed from other classes?

No.  
Only accessible from derived classes.  
Yes.

### Show the output of following program:

```CPP
#include <iostream>
#include <string>
using namespace std;

class Apple
{
public:
  Apple();
  Apple(double weight);
  virtual string toString();

protected:
  double weight;
};

Apple::Apple()
{
  weight = 1;
  cout << "Apple no-arg constructor" << endl;
}

Apple::Apple(double weight)
{
  this->weight = weight;
  cout << "Apple constructor with weight" << endl;
}

string Apple::toString() 
{
  return "Apple: " + to_string(weight);
}

class GoldenDelicious : public Apple
{
public:
  GoldenDelicious();
  GoldenDelicious(double weight);
  string toString() override;
};

GoldenDelicious::GoldenDelicious() : Apple(5)
{
  cout << "GoldenDelicious non-arg constructor" << endl;
}

GoldenDelicious::GoldenDelicious(double weight) : Apple(weight)
{
  cout << "GoldenDelicious constructor with weight" << endl;
}

string GoldenDelicious::toString() 
{
    return "GoldenDelicious: " + to_string(weight);
}

int main()
{
  Apple* a = new Apple();
  cout << a->toString() << endl;
  cout << "---------------" << endl;

  GoldenDelicious* g = new GoldenDelicious(7);
  cout << g->toString() << endl;
  cout << "---------------" << endl;

  Apple* c = new GoldenDelicious(8);
  cout << c->toString() << endl;

  return 0;
}
```

Apple constructor with weight
Apple no-arg constructor
Apple: 1.0

Apple constructor with weight
GoldenDelicious constructor with weight
GoldenDelicious: 7.0

Apple constructor with weight
GoldenDelicious constructor with weight
GoldenDelicious: 8.0

# References