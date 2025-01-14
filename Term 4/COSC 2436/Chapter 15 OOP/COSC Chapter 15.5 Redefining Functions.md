# Summary

# Learning Objectives

# Related
Prev - [[COSC Chapter 15.4 Constructors and Destructors]]

Next - [[COSC Chapter 15.6 Polymorphism]]
# Content

## Key Point

A [[function]] defined in the [[base class]] can be redefined in the derived classes.

The `toString``(``)` [[function]] is defined in the `GeometricObject` class to return a string `"``Geometric` `object``"` (lines 35–38 in **LiveExample 15.2**) as follows:

```cpp
string GeometricObject::toString() const 
{ 
  return "Geometric object"; 
} 
```

To redefine a [[base class]]’s [[function]] in the [[derived class]], you need to add the [[function]]’s prototype in the [[derived class]]’s header file, and provide a new implementation for the [[function]] in the [[derived class]]’s implementation file.

The `toString``(``)` [[function]] is redefined in the `Circle` class (lines 55–58 in **LiveExample 15.4**) as follows:

```cpp
string Circle::toString() const 
{ 
  return "Circle object"; 
} 
```

The `toString``(``)` [[function]] is redefined in the `Rectangle` class (lines 63–66 in **LiveExample 15.6**) as follows:

```cpp
string Rectangle::toString() const 
{ 
  return "Rectangle object"; 
} 
```

So, the following code:
![[Pasted image 20241014214016.png]]

displays:
```cpp
shape.toString() returns Geometric object 
circle.toString() returns Circle object 
rectangle.toString() returns Rectangle object 
```

The code creates a `GeometricObject` in line 1. The `toString` [[function]] defined in `GeometricObject` is invoked in line 2, since `shape`’s type is `GeometricObject`.

The code creates a `Circle` object in line 4. The `toString` [[function]] defined in `Circle` is invoked in line 5, since `circle`’s type is `Circle`.

The code creates a `Rectangle` object in line 7. The `toString` [[function]] defined in `Rectangle` is invoked in line 9, since `rectangle`’s type is `Rectangle`.

If you wish to invoke the `toString` [[function]] defined in the `GeometricObject` class on the calling object `circle`, use the scope resolution operator (`:``:`) with the [[base class]] name. For example, the following code

```cpp
Circle circle(5); 
cout << "circle.toString() returns " << circle.toString() << endl; 
cout << "invoke the base class’s toString() to return "  
  << circle.GeometricObject::toString(); 
```

displays

```
circle.toString() returns Circle objectinvoke the base class’s toString() to return Geometric object
```

>[!Note]
>In **Section 6.7**, “Overloading Functions,” you learned about overloading functions. Overloading a [[function]] is a way to provide more than one [[function]] with the same name but with different signatures to distinguish them. To redefine a [[function]], the [[function]] must be defined in the [[derived class]] using the same signature and same return type as in its [[base class]].

## Self-Check

### What is the difference between overloading a [[function]] and redefining a [[function]]?

Overloading a [[function]] is a way to provide more than one [[function]] with the same name but with different signatures to distinguish them. To redefine a [[function]], the [[function]] must be defined in the [[derived class]] using the same signature and same return type as in its [[base class]].

### True or false? (1) You can redefine a private [[function]] defined in a [[base class]]. (2) You can redefine a static [[function]] defined in a [[base class]]. (3) You can redefine a constructor.

All false.  
1. No. You can only override accessible functions.
2. No.
3. No.

# References
