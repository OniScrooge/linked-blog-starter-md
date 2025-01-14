# Summary

# Learning Objectives

# Related
Prev - [[COSC Chapter 15.3 Generic Programming]]

Next - [[COSC Chapter 15.5 Redefining Functions]]
# Content

## Key Point

The constructor of a [[derived class]] first calls its [[base class]]’s constructor before it executes its own code. The destructor of a [[derived class]] executes its own code then automatically calls its [[base class]]’s destructor.

A [[derived class]] inherits accessible data fields and functions from its [[base class]]. Does it inherit constructors or destructors? Can [[base class]] constructors and destructors be invoked from derived classes? We now consider these questions and their ramification.

## 15.4.1 Calling [[Base Class]] Constructors

A constructor is used to construct an instance of a class. Unlike data fields and functions, the constructors of a [[base class]] are not inherited in the [[derived class]]. They can only be invoked from the constructors of the derived classes to initialize the data fields in the [[base class]]. You can invoke the [[base class]]’s constructor from the constructor initializer list of the [[derived class]]. The syntax is as follows:

```cpp
DerivedClass(parameterList): BaseClass() 
{ 
  // Perform initialization 
} 
```

or

```cpp
DerivedClass(parameterList): BaseClass(argumentList) 
{ 
  // Perform initialization 
} 
```

The former invokes the no-arg constructor of its [[base class]], and the latter invokes the [[base class]] constructor with the specified arguments.

A constructor in a [[derived class]] always invokes a constructor in its [[base class]] explicitly or implicitly. If a base constructor is not invoked explicitly, the [[base class]]’s no-arg constructor is invoked by default. For example, in the following code, (a) and (b) are equivalent, and (c) and (d) are equivalent.

![[Pasted image 20241014211943.png]]
![[Pasted image 20241014211954.png]]
![[Pasted image 20241014212005.png]]
![[Pasted image 20241014212016.png]]

The `Circle(double radius, const string& color, bool filled)` constructor (lines 7–22) in **LiveExample 15.4**, DerivedCircle.cpp, can also be implemented by invoking the [[base class]]’s constructor `GeometricObject(const string& color, bool filled)` as follows:

```cpp
// Construct a circle object with specified radius, color and filled 
Circle::Circle(double radius, const string& color, bool filled) 
    : GeometricObject(color, filled) 
{ 
  setRadius(radius); 
} 
```

or

```cpp
// Construct a circle object with specified radius, color and filled 
Circle::Circle(double radius, const string& color, bool filled) 
    : GeometricObject(color, filled), radius(radius) 
{ 
} 
```

The latter also initializes the data field `radius` in the constructor initializer. `radius` is a data field defined in the `Circle` class.

## 15.4.2 Constructor and [[Destructor Chaining]]

Constructing an instance of a class invokes the constructors of all the base classes along the [[inheritance]] chain. When constructing an object of a [[derived class]], the [[derived class]] constructor first invokes its [[base class]] constructor before performing its own tasks. If a [[base class]] is derived from another class, the [[base class]] constructor invokes its [[parent class]] constructor before performing its own tasks. This process continues until the last constructor along the [[inheritance]] hierarchy is called. This is called [[constructor chaining]]. Conversely, the destructors are automatically invoked in reverse order. When an object of a [[derived class]] is destroyed, the [[derived class]] destructor is called. After it finishes its tasks, it invokes its [[base class]] destructor. This process continues until the last destructor along the [[inheritance]] hierarchy is called. This is called [[destructor chaining]].

Consider the following code in **LiveExample 15.8**:

## **LiveExample 15.8 ConstructorDestructorChainDemo.cpp**
```CPP
#include <iostream>
using namespace std;

class Person
{
public:
  Person()
  {
    cout << "Performs tasks for Person's constructor" << endl;
  }

  ~Person()
  {
    cout << "Performs tasks for Person's destructor" << endl;
  }
};

class Employee: public Person // extends Person
{
public:
  Employee()
  {
    cout << "Performs tasks for Employee's constructor" << endl;
  }

  ~Employee()
  {
    cout << "Performs tasks for Employee's destructor" << endl;
  }
};

class Faculty: public Employee // extends Employee
{
public:
  Faculty()
  {
    cout << "Performs tasks for Faculty's constructor" << endl;
  }

  ~Faculty()
  {
    cout << "Performs tasks for Faculty's destructor" << endl;
  }
};

int main()
{
  Faculty faculty;

  return 0;
}
```

```
command>cl ConstructorDestructorChainDemo.cpp
Microsoft C++ Compiler 2019 
Compiled successful (cl is the VC++ compile/link command)

command>ConstructorDestructorChainDemo 
Performs tasks for Person's constructor
Performs tasks for Employee's constructor
Performs tasks for Faculty's constructor
Performs tasks for Faculty's destructor
Performs tasks for Employee's destructor
Performs tasks for Person's destructor

command>
```

The program creates an instance of `Faculty` in line 48. Since `Faculty` is derived from `Employee` and `Employee` is derived from `Person`, `Faculty`’s constructor invokes `Employee`’s constructor before it performs its own task. `Employee`’s constructor invokes `Person`’s constructor before it performs its own task, as shown in the following figure:
![[Pasted image 20241014212534.png]]
![[Pasted image 20241014212546.png]]

When the program exits, the `Faculty` object is destroyed. So the `Faculty`’s destructor is called, then `Employee`’s, and finally `Person`’s, as shown in the following figure:

>[!warning] Caution
>If a class is designed to be extended, it is better to provide a _no-arg constructor_ to avoid programming [[errors]]. Consider the following code:
>
>```cpp
>class Fruit 
>{ 
>public: 
>  Fruit(int id) 
>  { 
>  } 
>}; 
> 
>class Apple: public Fruit 
>{ 
>public: 
>  Apple() 
>  { 
>  } 
>}; 
>```
>
>Since no constructor is explicitly defined in `Apple`, `Apple`’s default no-arg constructor is defined implicitly. Since `Apple` is a [[derived class]] of `Fruit`, `Apple`’s default constructor automatically invokes `Fruit`’s no-arg constructor. However, `Fruit` does not have a no-arg constructor, because `Fruit` has an explicit constructor defined. Therefore, the program cannot be compiled.


>[!Note]
>If the [[base class]] has a customized copy constructor and assignment operator, you should customize these in the derived classes to ensure that the data fields in the [[base class]] are properly copied. Suppose class `Child` is derived from `Parent`. The code for the copy constructor in `Child` would typically look like this:
>```cpp
>Child::Child(const Child& object): Parent(object) 
>{ 
 > // Write the code for custom copying data fields in Child 
>} 
>```
>
>The code for the assignment operator in `Child` would typically look like this:
>
>```cpp
>Child& Child::operator=(const Child& object) 
>{ 
 > // Use Parent::operator=(object) to apply the custom assignment  
>  // from the base class. 
>  // Write the code for custom copying data fields in Child. 
>} 
>```

>[!Note]
>When a destructor for a [[derived class]] is invoked, it automatically invokes the destructor in the [[base class]]. The destructor in the [[derived class]] only needs to destroy the dynamically created data in the [[derived class]].

## Self-Check

### True or false? When invoking a constructor from a [[derived class]], its [[base class]]'s no-arg constructor is always invoked.

False. If a [[derived class]]'s constructor explicitly invoke a [[base class]]'s constructor, the [[base class]]'s no-arg constructor is not invoked.

### What is the output of running the program in (a)? What problem arises in compiling the program in (b)?

(a)
```CPP
#include <iostream>
using namespace std;

class Parent
{
public:
  Parent()
  {
    cout <<
      "Parent's no-arg constructor is invoked";
  }
};

class Child: public Parent
{
};

int main()
{
  Child c;

  return 0; 
}
```
            
(b)
```CPP
#include <iostream>
using namespace std;

class Parent
{
public:
  Parent(int x)
  {
  }
};

class Child: public Parent
{
};

int main()
{
  Child c;

  return 0; 
}
```

#### Answer
(a) The output is  
Parent's no-arg constructor is invoked  
(b) The default constructor of Child attempts to invoke the default of constructor of Parent, but class Parent's default constructor is not defined.

### Show the output of the following code:

```CPP
#include <iostream>
using namespace std;

class Parent
{
public:
  Parent()
  {
    cout << "Parent's no-arg constructor is invoked" << endl;
  }

  ~Parent()
  {
    cout << "Parent's destructor is invoked" << endl;
  }
};

class Child: public Parent
{
public:
  Child()
  {
    cout << "Child's no-arg constructor is invoked" << endl;
  }

  ~Child()
  {
    cout << "Child's destructor is invoked" << endl;
  }
};

int main()
{
  Child c1;
  Child c2;

  return 0;
}
```

#### Answer
1. Parent's no-arg constructor is invoked
2. Child's no-arg constructor is invoked 
3. Parent's no-arg constructor is invoked 
4. Child's no-arg constructor is invoked 
5. Child's destructor is invoked 
6. Parent's destructor is invoked 
7. Child's destructor is invoked 
8. Parent's destructor is invoked 

### If a [[base class]] has a customized copy constructor and assignment operator, how should you define the copy constructor and the assignment operator in the [[derived class]]?

You should implement the copy constructor and assignment operator by invoking the copy constructor or the assignment operator [[function]] in the [[base class]] to copy the appropriate data fields in the [[base class]].

### If a [[base class]] has a customized destructor, are you required to implement the destructor in the [[derived class]]?

No. When a destructor for a [[derived class]] is invoked, it automatically invokes the destructor in the [[base class]]. So, there is no need to explicitly invoke the destructor in the [[base class]]. The destructor in the [[derived class]] only needs to destroy the dynamically created memory in the [[derived class]].

# References
