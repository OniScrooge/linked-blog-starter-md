# Summary

# Related
Prev - [[COSC Chapter 9.3 Example - Defining Classes and Creating Objects]]

Next - [[COSC Chapter 9.5 Constructing and Using Objects]]
# Content
## Key Point
A constructor is invoked to create an [[object]].

Constructors are a special kind of [[function]], with three peculiarities:
- Constructors must have the same name as the [[class]] itself.
- Constructors do not have a return type—not even `void`.
- Constructors are invoked when an [[object]] is created. Constructors play the role of initializing objects.

​​​The constructor has exactly the same name as the defining [[class]]. Like regular functions, constructors can be overloaded (i.e., multiple constructors with the same name but different signatures), making it easy to construct objects with different sets of data values.​

It is a common mistake to put the `void` keyword in front of a constructor. For example,
```java
void Circle() 
{ 
} 
```

​​​Most C++ compilers will report an error, but some will treat this as a regular [[function]], not as a constructor.​

Constructors are for initializing [[data fields]]. The data field `radius` does not have an initial value, so it must be initialized in the constructor (lines 13 and 19 in **Listing 9.1**). In C++11, you can also initialize a member data field upon its declaration. This is known as _member initializer_ in C++11. For example, it is correct in C++11 to replace line 8 in **Listing 9.1** by
```java
double radius = 5; // Initialize radius 
```

A [[class]] normally provides a constructor without arguments (e.g., `Circle()`). Such constructor is called a _no-arg_ or [[no-arg constructor]].

A [[class]] may be defined without constructors. In this case, a [[no-arg constructor]] with an empty body is implicitly defined in the [[class]]. Called _a_ [[default constructor]], it is provided automatically _only if no constructors are explicitly defined in the [[class]]_.

## Self-Check
### What are the differences between constructors and functions?
Constructors are special kinds of functions that are called when creating an [[object]]. Constructors do not have a return type, not even void.
### Is the following code correct in C++11?
```cpp
class Circle
{
public:
  Circle()
  {
  }
            
  double radius = 1;
};
```

Yes. Data field radius can be initialized in C++11 now.
# References