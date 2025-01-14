# Summary

# Learning Objectives

# Related
Prev - [[COSC Chapter 15.7 Virtual Functions and Dynamic Binding]]

Next - [[COSC Chapter 15.9 The protected keyword]]
# Content

## Key Point

The `override` keyword ensures that a [[function]] is overridden and the `final` keyword prevents a [[function]] from being overridden. 

C++11 introduced the `override` keyword to avoid programming [[errors]] and make sure that a [[function]] in a [[derived class]] overrides a [[virtual function]] in the [[base class]]. Consider the following example in **LiveExample 15.12**.

## **LiveExample 15.12 NeedForOverrideKeyword.cpp**
```CPP
#include <iostream>
using namespace std;

class A 
{
public:
  virtual void print(int i)
  {
    cout << "A" << i << endl;
  }
};

class B : public A
{
public:
  // Suppose to override the print function in A
  void print(long i)
  {
    cout << "B" << i << endl;
  }
};

int main()
{
  A* p1 = new B();
  B* p2 = new B();

  p1->print(1);
  p2->print(2);

  return 0;
}
```
```
command>cl NeedForOverrideKeyword.cpp
Microsoft C++ Compiler 2019 
Compiled successful (cl is the VC++ compile/link command)

command>NeedForOverrideKeyword 
A1
B2

command>
```

A virtual `print` [[function]] defined in the [[base class]] `A` is supposed to be overridden in the [[derived class]] `B`. However, it is done incorrectly because these two `print` functions have different signatures. The parameter `i` in the `print` [[function]] in `B` is of the `long` type, but it is of the `int` type in `A`. To avoid this kind of [[errors]], use the C++11 `override` keyword as shown in **LiveExample 15.13**.

## **LiveExample 15.13 UseOverrideKeyword.cpp**
```CPP
#include <iostream>
using namespace std;

class A 
{
public:
  virtual void print(int i)
  {
    cout << "A" << i << endl;
  }
};

class B : public A
{
public:
  // Use override keyword to avoid errors
  void print(int i) override
  {
    cout << "B" << i << endl;
  }
};

int main()
{
  A* p1 = new B();
  B* p2 = new B();

  p1->print(1);
  p2->print(2);

  return 0;
}
```
```
command>cl UseOverrideKeyword.cpp
Microsoft C++ Compiler 2019 
Compiled successful (cl is the VC++ compile/link command)

command>UseOverrideKeyword 
B1
B2

command>
```

The override keyword tells the compiler to check that the [[function]] in the [[derived class]] is overriding a [[virtual function]] in the [[base class]]. If the overridden [[function]] in the [[derived class]] does not match the [[virtual function]] defined in the [[base class]], the complier would report the error.

C++11 also introduced the final keyword that can be used to prevent a [[virtual function]] from being overridden. Consider the code in **LiveExample 15.14**.

## **LiveExample 15.14 UseFinalKeyword.cpp**
```CPP
#include <iostream>
using namespace std;

class A 
{
public:
  virtual void print(int i) 
  {
    cout << "A" << i << endl;
  }
};

class B : public A
{
public:
  void print(int i) override final
  {
    cout << "B" << i << endl;
  }
};

class C : public B
{
public:
  void print(int i) // Error, because print is final
  {
    cout << "B" << i << endl;
  }
};

int main()
{
  A* p1 = new B();
  B* p2 = new B();

  p1->print(1);
  p2->print(2);

  return 0;
}
```
```
c:\example>cl UseFinalKeyword.cpp
Microsoft C++ Compiler 2017
UseFinalKeyword.cpp
UseFinalKeyword.cpp(25): error C3248: 'B::print': function 
declared as 'final' cannot be overridden by 'C::print'

c:\example>
```

The program has a syntax error is line 25, because the `print` [[function]] is declared `final` in line 16. Note that the `final` keyword is only used with `virtual` functions. `print` is a `virtual` [[function]] originally defined in class `A`.

## Self-Check

### What will be the output if `int` is changed to long in line 7 in __LiveExample 15.12__?

B1
B2

### What would happen if `int` is changed to long in line 17 in __LiveExample 15.13__?

A1
B2

### What is the purpose of using the `final` keyword?

The final keyword can be used in two ways: (1) To prevent a [[function]] to be overridden; (2) To declare a constant.

### The fuck is gonna happen?

```CPP
#include <iostream>

using namespace std;

class A
{
public:
	A()    
	{
	      t();      // cout << "i from A is " << i << endl;
	}
	
	void t()     {      setI(20);    }
    virtual void setI(int i)    {      this->i = 2 * i;    }
           int i;  };    class B: public A  {  public:    B()    {      cout << "i from B is " << i << endl;    }      void setI(int i) override    {      this->i = 3 * i;    }  };    int main()  {    A* p = new B();      return 0;  }
```
# References
