# Summary

# Learning Objectives

# Related
Prev - [[COSC Chapter 15.6 Polymorphism]]

Next - [[COSC Chapter 15.8  The C++11 `override` and `final` Keywords]]
# Content

## Key Point

A [[function]] can be implemented in several classes along the [[inheritance]] chain. **[[virtual function]] functions** enable the system to decide which [[function]] is invoked at runtime based on the actual type of the object.

The program in **LiveExample 15.9** defines the `displayGeometricObject` [[function]] that invokes the `toString` [[function]] on a `GeometricObject` (line 10).

The `displayGeometricObject` [[function]] is invoked in lines 16, 19, 22 by passing an object of `GeometricObject`, `Circle`, and `Rectangle`, respectively. As shown in the output, the `toString``(``)` [[function]] defined in class `GeometricObject` is invoked. Can you invoke the `toString``(``)` [[function]] defined in `Circle` when executing `displayGeometricObject``(``circle``)`, the `toString``(``)` [[function]] defined in `Rectangle` when executing `displayGeometicObject``(``rectangle``)`, and the `toString``(``)` [[function]] defined in `GeometricObject` when executing `displayGeometricObject``(``geometricObject``)`​?​ You can do so simply by declaring `toString` as a [[virtual function]] [[function]] in the [[base class]] `GeometricObject`.

Suppose you replace line 15 in **LiveExample 15.1** with the following [[function]] declaration and create a new file named ​`**GeometricObjectWithVirtualtoString.h**​:`

```cpp
virtual string toString() const; 
```

## LiveExample: GeometricObjectWithVirtualtoString.h
```CPP
#ifndef GEOMETRICOBJECT_H
#define GEOMETRICOBJECT_H
#include <string>
using namespace std;

class GeometricObject
{
public:
  GeometricObject();
  GeometricObject(const string& color, bool filled);
  string getColor() const;
  void setColor(const string& color);
  bool isFilled() const;
  void setFilled(bool filled);
  virtual string toString() const; // Virtual toString()

private:
  string color;
  bool filled;
}; // Must place semicolon here

#endif 
```

Now if you rerun **LiveExample 15.9** with [[virtual function]] `toString()` in **LiveExample PolymorphismDemoWithVirtualtoString.cpp**, you will see the following output:

```
Geometric objectCircle objectRectangle object
```

## LiveExample: PolymorphismDemoWithVirtualtoString.cpp
```CPP
#include <iostream>
#include "GeometricObjectWithVirtualtoString.h" // Virtual toString() header file
#include "DerivedCircle.h"
#include "DerivedRectangle.h"

using namespace std;

void displayGeometricObject(const GeometricObject& g)
{
  cout << g.toString() << endl;
}

int main()
{
  GeometricObject geometricObject;
  displayGeometricObject(geometricObject);

  Circle circle(5);
  displayGeometricObject(circle);

  Rectangle rectangle(4, 6);
  displayGeometricObject(rectangle);

  return 0;
}
```

```
command>cl PolymorphismDemoWithVirtualtoString.cpp
Microsoft C++ Compiler 2019 
Compiled successful (cl is the VC++ compile/link command)

command>PolymorphismDemoWithVirtualtoString 
Geometric Object
Circle object
Rectangle object

command>
```

With the `toString``(``)` [[function]] defined as `virtual` in the [[base class]], C++ dynamically determines which `toString``(``)` [[function]] to invoke at runtime. When invoking `displayGeometricObject``(``circle``)`, a `Circle` object is passed to `g` by reference. Since `g` refers to an object of the `Circle` type, the `toString` [[function]] defined in class `Circle` is invoked. The capability of determining which [[function]] to invoke at runtime is known as [[dynamic binding]].

>[!Note]
>In C++, _redefining_ a [[virtual function]] [[function]] in a [[derived class]] is called _[[overriding a function]]_.
>
>To enable [[dynamic binding]] for a [[function]], you need to do two things:
>- The [[function]] must be defined [[virtual function]] in the [[base class]].
>- The variable that references the object must be passed by reference or passed as a pointer in the [[virtual function]] [[function]].

**LiveExample 15.9** passes the object to a parameter by reference (line 8); alternatively, you can rewrite lines 8–11 by passing a pointer, as in **LiveExample 15.10**:

## **LiveExample 15.10 VirtualFunctionDemoUsingPointer.cpp**
```CPP
#include <iostream>
#include "GeometricObjectWithVirtualtoString.h" // Virtual toString() 
#include "DerivedCircle.h"
#include "DerivedRectangle.h"

using namespace std;

void displayGeometricObject(const GeometricObject* g) // Pass a pointer
{
  cout << (*g).toString() << endl;
}

int main()
{
  displayGeometricObject(&GeometricObject());
  displayGeometricObject(&Circle(5));
  displayGeometricObject(&Rectangle(4, 6));

  return 0;
}
```

```
command>cl VirtualFunctionDemoUsingPointer.cpp
Microsoft C++ Compiler 2019 
Compiled successful (cl is the VC++ compile/link command)

command>VirtualFunctionDemoUsingPointer 
Geometric Object
Circle Object
Rectangle Object

command>
```

However, if the object argument is passed by value, the [[virtual function]] functions are not bound dynamically. As shown in **LiveExample 15.11**, even though the [[function]] is defined to be [[virtual function]], the output is the same as it would be without using the [[virtual function]] [[function]].

## **LiveExample 15.11 VirtualFunctionDemoPassByValue.cpp**
```CPP
#include <iostream>
#include "GeometricObjectWithVirtualtoString.h" // Virtual toString()
#include "DerivedCircle.h"
#include "DerivedRectangle.h"

using namespace std;

void displayGeometricObject(GeometricObject g) // Pass-by-value
{
  cout << g.toString() << endl;
}

int main()
{
  displayGeometricObject(GeometricObject());
  displayGeometricObject(Circle(5));
  displayGeometricObject(Rectangle(4, 6));

  return 0;
}
```

```
command>cl VirtualFunctionDemoPassByValue.cpp
Microsoft C++ Compiler 2019 
Compiled successful (cl is the VC++ compile/link command)

command>VirtualFunctionDemoPassByValue 
Geometric Object
Geometric Object
Geometric Object

command>
```

Note the following points regarding [[virtual function]] functions:
- If a [[function]] is defined `virtual` in a [[base class]], it is automatically `virtual` in all its derived classes. The keyword `virtual` need not be added in the [[function]] declaration in the [[derived class]].
- Matching a [[function]] signature and binding a [[function]] implementation are two separate issues. The _declared type_ of the variable decides which [[function]] to match at compile time. This is _static binding_. The compiler finds a matching [[function]] according to parameter type, number of parameters, and order of the parameters at compile time. A [[virtual function]] [[function]] may be implemented in several derived classes. C++ dynamically binds the implementation of the [[function]] at runtime, decided by the _actual class_ of the object referenced by the variable. This is _[[dynamic binding]]_.
- [[Dynamic binding]] works as follows: Suppose an object o is an instance of classes C1, C2, …, Cn−1, and Cn, where C1 is a [[subclass]] of C2, C2 is a [[subclass]] of C3, …, and Cn−1 is a [[subclass]] of Cn, as shown in **Figure 15.2**. That is, Cn is the most general class, and C1 is the most specific class. If o invokes a [[function]] p, C++ searches the implementation for the [[function]] p in C1, C2, …, Cn−1, and Cn, in this order, until it is found. Once an implementation is found, the search stops and the first-found implementation is invoked.
- If a [[function]] defined in a [[base class]] needs to be redefined in its derived classes, you should define it [[virtual function]] to avoid confusions and mistakes. On the other hand, if a [[function]] will not be redefined, it is more efficient not to declare it [[virtual function]], because more time and system resource are required to bind [[virtual function]] functions dynamically at runtime. We call a class with a [[virtual function]] [[function]] a _polymorphic type_.

>[!info] Figure 15.2
>![[Pasted image 20241014220404.png]]

>[!Note]
>In C++, [[dynamic binding]] does not apply during constructing objects. For example, in the following code, when `new B()` is invoked in line 37, the constructor `B()` is invoked. Since `A` is a [[supertype]] of `B`, `A`'s constructor is invoked, which invokes `t()` in line 9. `t()` is a [[virtual function]] [[function]] and it is overridden in class `B`. However, [[dynamic binding]] does not apply during constructing objects in C++, the [[function]] `t()` defined in class `A` is invoked from `A`'s constructor, which assigns `20` to `i` in line 15. So the output from line 10 is "`i from A is 20`" and the output from line 26 is "`i from B is 20`". In Java and Python, [[dynamic binding]] applies during constructing objects.
```CPP
#include <iostream>
using namespace std;

class A
{
public:
  A()
  {
    t();
    cout << "i from A is " << i << endl;
  }

  virtual void t()
  {
    i = 20;
  }

  int i = 0;
};

class B : public A
{
public:
  B()
  {
    cout << "i from B is " << i << endl;
  }

  void t() override
  {
    i = 30;
  }
};

int main()
{
  A* p = new B();
  p->t();
  cout << "i is now " << p->i << endl;

  return 0;
}
```
```
command>cl NoDynamicBindingForObjectCreation.cpp
Microsoft C++ Compiler 2019 
Compiled successful (cl is the VC++ compile/link command)

command>NoDynamicBindingForObjectCreation 
i from A is 20
i from B is 20
i is now 30

command>
```
>After the object is created in line 37, `p->t()` (line 38) invokes `t()` from an object of the `B` type. Note `p` is declared as `A*`, but it actually points to a `B` type object. Therefore, by [[dynamic binding]], the `t()` [[function]] defined in the `B` class is invoked, which assigns `30` to `i` (line 31). Line 39 displays "`i is now 30`".

## Self-Check

### Answer the following questions for the program below:
```CPP
 1  #include <iostream>
 2  using namespace std;
 3
 4  class Parent
 5  {
 6  public:
 7    void f()
 8    {
 9      cout << "invoke f from Parent" << endl;
10    }
11  };
12
13  class Child: public Parent
14  {
15  public:
16    void f()
17    {
18      cout << "invoke f from Child" << endl;
19    }
20  };
21
22  void p(Parent a)
23  {
24    a.f();
25  }
26
27  int main()
28  {
29    Parent a;
30    a.f();
31    p(a);
32
33    Child b;
34    b.f();
35    p(b);
36
37    return 0;
38  }
```

a. What is the output of this program?  
b. What will be the output if line 7 is replaced by [[virtual function]] void f()?  
c. What will be the output if line 7 is replaced by [[virtual function]] void f() and line 22 is replaced by void p(Parent& a)?  

#### Answer
a.
invoke f from Parent 
invoke f from Parent  
invoke f from Child 
invoke f from Parent  

b.
invoke f from Parent 
invoke f from Parent  
invoke f from Child 
invoke f from Parent  
            
c.
invoke f from Parent 
invoke f from Parent  
invoke f from Child 
invoke f from Child  

### What is static binding and what is [[dynamic binding]]?

Matching a [[function]] signature and binding a [[function]] implementation are two separate issues. The declared type of the variable decides which [[function]] to match at compile time. This is static binding. The compiler finds a matching [[function]] according to parameter type, number of parameters, and order of the parameters at compile time. A [[virtual function]] [[function]] may be implemented in several derived classes. C++ dynamically binds the implementation of the [[function]] at runtime, decided by the actual class of the object referenced by the variable. This is [[dynamic binding]].

### Is declaring [[virtual function]] functions enough to enable [[dynamic binding]]?

No. You also need to use reference for the object that invokes the [[function]].

### Show the output of the following code:

(a)
```CPP
#include <iostream>
#include <string>
using namespace std;

class Person
{
public:
  void printInfo()
  {
    cout << getInfo() << endl;
  }
	
  virtual string getInfo() const
  {
    return "Person";
  }
}; 

class Student: public Person
{
public:
  string getInfo() const 
  {
    return "Student";
  }
}; 

int main()
{
  Person().printInfo();
  Student().printInfo();
}
```

(b) 
```CPP
#include <iostream>
#include <string>
using namespace std;

class Person
{
public:
  void printInfo()
  {
    cout << getInfo() << endl;
  }
	
  string getInfo() const
  {
    return "Person";
  }
}; 

class Student: public Person
{
public:
  string getInfo() const
  {
    return "Student";
  }
}; 

int main()
{
  Person().printInfo();
  Student().printInfo();
}
```

#### Answer
(a)
Person
Student

(b)
Person
Person

### Is it a good practice to define all functions [[virtual function]]?

No. it is more efficient without declaring it [[virtual function]], because it takes more time and system resource to bind [[virtual function]] functions dynamically at runtime.  
You should only declare a [[function]] [[virtual function]] if it is intended to be redefined by derived classes.

### Show the output of the following code.
```CPP
#include <iostream>
using namespace std;

class A
{
public:
  A()
  {
    t();
    cout << "i from A is " << i << endl;
  }

  void t() 
  {
    setI(20);
  }

  virtual void setI(int i)
  {
    this->i = 2 * i;
  }
  
  int i;
};

class B: public A
{
public:
  B()
  {
    cout << "i from B is " << i << endl;
  }

  void setI(int i) 
  {
    this->i = 3 * i;
  }
};

int main()
{
  A* p = new B();

  p->t();
  cout << p->i << endl;

  return 0;
}
```

- i from A is 40
- i from A is 40
- 60


### What will be displayed by the following code?

```CPP
#include <iostream>
#include <string>

using namespace std;

class C
{
public:
	virtual string toString()    {      return "C";    }
};

class B: public C
{
public:
	string toString()    {      return "B";    }
};

class A: public B
{
public:
	string toString()    {      return "A";    }
};

void displayObject(C* p)  {    cout << p->toString();  }

int main()
{
	displayObject(&A());
	displayObject(&B());
	displayObject(&C());
	
	return 0;
}
```

__ABC__

### What will be displayed by the following code?

```CPP
#include <iostream>
#include <string>

using namespace std;

class C
{
public:
	string toString()    {      return "C";    }
};

class B: public C
{
public:
	string toString()    {      return "B";    }
};

class A: public B
{
	virtual string toString()    {      return "A";    }
};

void displayObject(C* p)  {    cout << p->toString();  }

int main()
{
	displayObject(&A());
    displayObject(&B());
    displayObject(&C());
    
	return 0;
}
```

__CCC__

### What will be displayed by the following code?

```CPP
#include <iostream>
#include <string>

using namespace std;

class C
{
public:
virtual string toString()    {      return "C";    }
};

class B: public C
{
public:
	string toString()    {      return "B";    }
};

class A: public B
{
public:
	string toString()    {      return "A";    }
};

void displayObject(C p)  {    cout << p.toString();  }
int main()
{
	displayObject(A());
    displayObject(B());
    displayObject(C());
    
	return 0;
}
```

__CCC__

# References
