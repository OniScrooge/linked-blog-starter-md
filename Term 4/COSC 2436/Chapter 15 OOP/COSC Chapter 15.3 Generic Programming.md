# Summary

# Learning Objectives

# Related
Prev - [[COSC Chapter 15.2 Base classes and derived classes]]

Next - [[COSC Chapter 15.4 Constructors and Destructors]]
# Content

## Key Point

An object of a [[derived class]] can be passed wherever an object of a base type parameter is required. Thus a [[function]] can be used generically for a wide range of object arguments. This is known as **[[generic programming]]**.

If a [[function]]’s parameter type is a [[base class]] (e.g., `GeometricObject`), you may pass an object to this [[function]] of any of the parameter’s derived classes (e.g., `Circle` or `Rectangle`). This is called [[generic programming]].

For example, suppose you define a [[function]] as follows:

```cpp
    void displayGeometricObject(const GeometricObject& shape) 
    { 
      cout << shape.getColor() << endl; 
    } 
```

The parameter type is `GeometricObject`. You can invoke this [[function]] in the following code:

```cpp
displayGeometricObject(GeometricObject("black", true)); 
displayGeometricObject(Circle(5)); 
displayGeometricObject(Rectangle(2, 3)); 
```

Each statement creates an anonymous object and passes it to invoke `displayGeometricObject`. Since `Circle` and `Rectangle` are derived from `GeometricObject`, you can pass a `Circle` object or a `Rectangle` object to the `GeometricObject` parameter type in the `displayGeometricObject` [[function]].

## Self-Check

### Assume `class A` is derived from `class B` and _B_ is derived from _C_, all the classes have no-arg constructors. Given [[function]] `f(B b)`, can you invoke `f(A())`, `f(B())`, and `f(C())`?

You can invoke f(A()) because A() is an instance B since A is derived from B. You can invoke f(B()) because B() is an instance B. You cannot invoke f(C()) because C() is not an instance B.

# References
