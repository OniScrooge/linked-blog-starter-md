# Summary

# Learning Objectives

# Related
Prev - [[COSC Chapter 15.5 Redefining Functions]]

Next - [[COSC Chapter 15.7 Virtual Functions and Dynamic Binding]]
# Content

## Key Point

_[[Polymorphism]]_ means that a variable of a [[supertype]] can refer to a [[subtype]] object.

The three pillars of object-oriented programming are encapsulation, [[inheritance]], and [[polymorphism]]. You have already learned the first two. This section introduces [[polymorphism]].

First, let us define two useful terms: [[subtype]] and [[supertype]]. A class defines a type. A type defined by a [[derived class]] is called a [[subtype]], and a type defined by its [[base class]] is called a [[supertype]]. Therefore, you can say that `Circle` is a [[subtype]] of `GeometricObject` and `GeometricObject` is a [[supertype]] for `Circle`.

The [[inheritance]] relationship enables a [[derived class]] to inherit features from its [[base class]] with additional new features. A [[derived class]] is a specialization of its [[base class]]; every instance of a [[derived class]] is also an instance of its [[base class]], but not vice versa. For example, every circle is a geometric object, but not every geometric object is a circle. Therefore, you can always pass an instance of a [[derived class]] to a parameter of its [[base class]] type. Consider the code in **LiveExample 15.9**.

## **LiveExample 15.9 PolymorphismDemo.cpp**
```CPP
#include <iostream>
#include "GeometricObject.h"
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
command>cl PolymorphismDemo.cpp
Microsoft C++ Compiler 2019 
Compiled successful (cl is the VC++ compile/link command)

command>PolymorphismDemo 
Geometric Object
Geometric Object
Geometric Object

command>
```

The [[function]] `displayGeometricObject` (line 8) takes a parameter of the `GeometricObject` type. You can invoke `displayGeometricObject` by passing any instance of `GeometricObject`, `Circle`, and `Rectangle` (lines 16, 19, 22). An object of a [[derived class]] can be used wherever its [[base class]] object is used. This is commonly known as [[polymorphism]] (from a Greek word meaning “many forms”). In simple terms, [[polymorphism]] means that a variable of a [[supertype]] can refer to a [[subtype]] object.

## Self-Check

### What is a [[subtype]] and a [[supertype]]? What is [[polymorphism]]?

A class defines a type. A type defined by a [[subclass]] is called a [[subtype]], and a type defined by its [[superclass]] is called a [[supertype]]. [[Polymorphism]] means that a variable of a [[supertype]] can refer to a [[subtype]] object.

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

__CCC__

# References
