# Summary

# Learning Objectives

# Related
Prev - [[COSC Chapter 15.10 Abstract Classes and Pure Virtual Functions]]

Next - [[COSC Chapter Summary 15]]
# Content

## Key Point

The `dynamic_cast` operator can be used to cast an object to its actual type at runtime.

Suppose you wish to rewrite the `displayGeometricObject` [[function]] in **LiveExample 15.22**, TestAbstractGeometricObject.cpp, to display the radius and diameter for a circle object and the width and height for a rectangle object. You may attempt to implement the [[function]] as follows:

```cpp
void displayGeometricObject(GeometricObject& g) 
{ 
  cout << "The radius is " << g.getRadius() << endl; 
  cout << "The diameter is " << g.getDiameter() << endl; 
  cout << "The width is " << g.getWidth() << endl; 
  cout << "The height is " << g.getHeight() << endl; 
  cout << "The area is " << g.getArea() << endl; 
  cout << "The perimeter is " << g.getPerimeter() << endl; 
} 
```

There are two problems with this code. First, the code cannot be compiled because `g`’s type is `GeometricObject`, but the `GeometricObject` class does not contain the `getRadius()`, `getDiameter()`, `getWidth()`, and `getHeight()` functions. Second, your code should detect whether the geometric object is a circle or a rectangle and then display radius and diameter for a circle and width and height for a rectangle.

The problems may be fixed by casting `g` into `Circle` or `Rectangle`, as shown in the following code:

Static casting is performed on `p` that points to a `GeometricObject` `g` (line 3). This new [[function]] can compile but is still incorrect. A `Circle` object may be cast to `Rectangle` to invoke `getWidth``(``)` in line 10. Likewise, a `Rectangle` object may be cast to `Circle` to invoke `getRadius``(``)` in line 5. We need to ensure that the object is indeed a `Circle` object before invoking `getRadius``(``)`. This can be done using `dynamic``_``cast`.

The `dynamic``_``cast` works like the `static``_``cast`. Additionally, it performs runtime checking to ensure that casting is successful. If casting fails, it returns `nullptr`. So, if you run the following code,

```cpp
1  Rectangle rectangle(5, 3); 
2  GeometricObject* p = &rectangle; 
3  Circle* p1 = dynamic_cast<Circle*>(p); 
4  cout << (*p1).getRadius() << endl; 
```

`p1` will be `nullptr`. A runtime error will occur when running the code in line 4.

>[!Note]
>Assigning a pointer of a [[derived class]] type to a pointer of its [[base class]] type is called [upcasting](https://revel-ise.pearson.com/courses/66e7050d84448f59a62c6945/assignments/711c7caf-6fd2-4d48-b657-33274573990d/pages/urn:pearson:entity:75b68b18-b2ef-4d02-84fb-7457283e17b0?source=dashboard#), and assigning a pointer of a [[base class]] type to a pointer of its [[derived class]] type is called [downcasting](https://revel-ise.pearson.com/courses/66e7050d84448f59a62c6945/assignments/711c7caf-6fd2-4d48-b657-33274573990d/pages/urn:pearson:entity:75b68b18-b2ef-4d02-84fb-7457283e17b0?source=dashboard#). Upcasting can be performed implicitly without using the `static_cast` or `dynamic_cast` operator. For example, the following code is correct:

```cpp
GeometricObject* p = new Circle(1); 
Circle* p1 = new Circle(2); 
p = p1; 
```

However, downcasting must be performed explicitly. For example, to assign `p` to `p1`, you have to use

```cpp
p1 = static_cast<Circle*>(p); 
or p1 = dynamic_cast<Circle*>(p); 
```

>[!Note]
>`dynamic``_``cast` can be performed only on the pointer or a reference of a polymorphic type; i.e., the type contains a [[virtual function]]. `dynamic``_``cast` can be used to check whether casting is performed successfully at runtime. `static_cast` is performed at compile time. `static_cast` is performed at compile time.

Now you can rewrite the `displayGeometricObject` [[function]] using dynamic casting, as in **LiveExample 15.23**, to check whether casting is successful at runtime.

## **LiveExample 15.23 DynamicCastingDemo.cpp**
```CPP
#include "AbstractGeometricObject.h"
#include "DerivedCircleFromAbstractGeometricObject.h"
#include "DerivedRectangleFromAbstractGeometricObject.h"
#include <iostream>
using namespace std;

// A function for displaying a geometric object
void displayGeometricObject(GeometricObject& g)
{
  cout << "The area is " << g.getArea() << endl;
  cout << "The perimeter is " << g.getPerimeter() << endl;

  GeometricObject* p = &g;
  Circle* p1 = dynamic_cast<Circle*>(p);
  Rectangle* p2 = dynamic_cast<Rectangle*>(p);

  if (p1 != nullptr)
  {
    cout << "The radius is " << p1->getRadius() << endl;
    cout << "The diameter is " << p1->getDiameter() << endl;
  }

  if (p2 != nullptr)
  {
    cout << "The width is " << p2->getWidth() << endl;
    cout << "The height is " << p2->getHeight() << endl;
  }
}

int main()
{
  Circle circle(5);
  Rectangle rectangle(5, 3);

  cout << "Circle info: " << endl;
  displayGeometricObject(circle);

  cout << "\nRectangle info: " << endl;
  displayGeometricObject(rectangle);

  return 0;
}
```
```
command>cl DynamicCastingDemo.cpp
Microsoft C++ Compiler 2019 
Compiled successful (cl is the VC++ compile/link command)

command>DynamicCastingDemo 
Circle info: 
The area is 78.5397
The perimeter is 31.4159
The radius is 5
The diameter is 10

Rectangle info: 
The area is 15
The perimeter is 16
The width is 5
The height is 3

command>
```

Line 13 creates a pointer for a `GeometricObject` `g`. The `dynamic_cast` operator (line 14) checks whether pointer `p` points to a `Circle` object. If so, the object’s address is assigned to `p1`; otherwise `p1` is `nullptr`. If `p1` is not `nullptr`, the `getRadius()` and `getDiameter()` functions of the `Circle` object (pointed by `p1`) are invoked in lines 19–20. Similarly, if the object is a rectangle, its width and height are displayed in lines 25–26.

The program invokes the `displayGeometricObject` [[function]] to display a `Circle` object in line 36 and a `Rectangle` object in line 39. The [[function]] casts the parameter `g` into a `Circle` pointer `p1` in line 14 and a `Rectangle` pointer `p2` in line 15. If it is a `Circle` object, the object’s `getRadius()` and `getDiameter()` functions are invoked in lines 19–20. If it is a `Rectangle` object, the object’s `getWidth()` and `getHeight()` functions are invoked in lines 25–26.

The [[function]] also invokes `GeometricObject`’s `getArea()` and `getPerimeter()` functions in lines 10–11. Since these two functions are defined in the `GeometricObject` class, there is no need to downcast the object parameter to `Circle` or `Rectangle` in order to invoke them.

>[!Tip]
>Occasionally, it is useful to obtain information about the class of the object. You can use the `typeid` operator to return a reference to an object of class `type_info`. For example, you can use the following statement to display the class name for object `x`:
>
>```cpp
>string x; 
>cout << typeid(x).name() << endl; 
>```
>
>It displays string, because `x` is an object of the `string` class. To use the `typeid` operator, the program must include the `<typeinfo` header file.

>[!Tip]
>If a class is used polymorphic with dynamic memory allocations, its destructor should be defined virtual. Suppose class `Child` is derived from class `Parent` and destructors are not virtual. Consider the following code:
>
>```cpp
>Parent* p = new Child(); 
>... 
>delete p; 
>```
>
>When `delete` is invoked with `p`, `Parent`’s destructor is called, since `p` is declared a pointer for `Parent`. `p` actually points to an object of `Child`, but `Child`’s destructor is never called. To fix the problem, define the destructor virtual in class `Parent`. Now, when `delete` is invoked with `p`, `Child`’s destructor is called and then `Parent`’s destructor is called, since destructors are virtual.

## Self-Check

### What is upcasting? What is downcasting?

Upcasting is to cast a pointer from a [[derived class]] type to a [[base class]] type. Downcasting is to cast a pointer from a [[base class]] type to a [[derived class]] type.

### When do you need to downcast an object from a [[base class]] type to a [[derived class]] type?

If a pointer points to an object of a [[derived class]], but it is declared as a [[base class]] type, you need to cast the pointer to the [[derived class]] type in order to access the members defined in the [[derived class]].

### What will be the value in p1 after the following statements?
```CPP
GeometricObject* p = new Rectangle(2, 3);
Circle* p1 = new Circle(2);
p1 = dynamic_cast<Circle*>(p);
```

0

### Analyze the following code:
```CPP
#include <iostream>
using namespace std;

class Parent
{
};

class Child: public Parent
{
public:
  void m()
  {
    cout << "invoke m" << endl;
  }
};

int main()
{
  Parent* p = new Child();
 
  // To be replaced

  return 0;
}
```

1. What compile [[errors]] will you get if the "To be replaced" line is replaced by the following code? `(*p).m();`
2. What compile [[errors]] will you get if the "To be replaced" line is replaced by the following code? `Child* p1 = dynamic_cast<Child*>(p); (*p1).m();`
3. Will the program compile and run if the highlighted line is replaced by the following code? `Child* p1 = static_cast<Child*>(p); (*p1).m();`
4. Will the program compile and run if `virtual void m() { }` is added in the [[Parent class]] and the highlighted line is replaced by `dynamic_cast<Child*>(p)->m();`?

#### Answer
1. m() is not a member of the [[Parent class]].  
2. To cast p dynamically, p's defining class must have virtual functions. Here, Parent is not defined as a class with virtual functions.  
3. Static casting to the Child type is OK.  
4. Yes.

### Why should you define a destructor virtual?

It is a good practice to always declare destructors virtual to ensure that a [[derived class]]' constructor is called when an object of the [[derived class]] is deleted.

### Can destructors be overloaded? Can you redefine a destructor?

No. You cannot overload a destructor.  
No. You cannot redefine a destructor in a [[derived class]].

# References
