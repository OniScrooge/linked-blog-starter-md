# Summary

# Learning Objectives

# Related
Prev - [[COSC Chapter 9.7 Preventing Multiple Inclusions]]

Next - [[COSC Chapter 9.9 Data Field Encapsulation]]
# Content
## Key Point
You can define short functions as inline functions to improve performance.

**Section 6.10**, “Inline Functions,” introduced how to improve function efficiency using inline functions. When a function is implemented inside a class definition, it automatically becomes an inline function. This is also known as [[inline definition]]. For example, in the following definition for class `A`, the constructor and function `f1` are automatically inline functions, but function `f2` is not.
```cpp
class A 
{ 
public: 
  A() 
  { 
    // Do something; 
  } 
 
  double f1() 
  { 
    // Return a number 
  } 
 
  double f2(); 
}; 
```

There is another way to define inline functions for classes. You may define inline functions in the class’s implementation file. For example, to define function `f2` as an inline function, precede the inline keyword in the function header as follows:
```cpp
// Implement function as inline 
inline double A::f2() 
{ 
  // Return a number 
} 
```

As noted in **Section 6.10**, short functions are good candidates for inline functions, but long functions are not.
## Self-Check
### How do you implement all functions inline in LiveExample 9.4, Circle.cpp?

Implement all the functions in the header file.
```cpp
class Circle
{
public:
  Circle() 
  {
    radius = 1; 
  };
  Circle(double newRadius) 
  { 
     radius = newRadius;
  }
  double getArea()
  {
    return radius * radius * 3.14159;
  };
  double getRadius()
  {
    return radius;
  };
  void setRadius(double newRadius)
  {
     radius = newRadius;
  }; 

private:
  double radius;
};
```
# References
