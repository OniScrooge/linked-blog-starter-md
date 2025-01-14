# Summary

# Learning Objectives

# Related
Prev - [[COSC Chapter 9.4 Constructors]]

Next - [[COSC Chapter 9.6 Separating Class Definition from Implementation]]
# Content
## Key Point
An [[object]]’s data and functions can be accessed through the dot (`.`) operator via the [[object]]’s name. 

​​​A constructor is invoked when an [[object]] is created. The syntax to create an object using the [[no-arg constructor]] is​
```java
ClassName objectName; 
```

For example, the following declaration creates an object named `circle1` by invoking the `Circle` class’s [[no-arg constructor]].
```java
Circle circle1; 
```

​​​The syntax to create an object using a constructor with arguments is​
```cpp
ClassName objectName(arguments); 
```

For example, the following declaration creates an object named `circle2` by invoking the `Circle` class’s constructor with a specified radius `5.5`.
```cpp
Circle circle2(5.5); 
```

In OOP term, an object’s member refers to its data fields and functions. Newly created objects are allocated in the memory. After an object is created, its data can be accessed and its functions invoked using the [[dot operator]], also known as the _object_ [[member access operator]]:
- `objectName.dataField` references a data field in the object.
- `objectName.function(arguments)` invokes a function on the object.

For example, `circle1.radius` references the radius in `circle1`, and `circle1.getArea()` invokes the `getArea` function on `circle1`. Functions are invoked as operations on objects.

The data field `radius` is referred to as an _instance member variable_ or simply [[remote-vault/Term 4/COSC 2436/Terms & Concepts/instance variable]], because it is dependent on a specific instance. For the same reason, the function `getArea` is referred to as an _instance_ [[member function]] or [[remote-vault/Term 4/COSC 2436/Terms & Concepts/instance function]], because you can invoke it only on a specific instance. The object on which an instance function is invoked is called a [[calling object]].

>[!Note]
When you define a custom class, capitalize the first letter of each word in a class name—for example, the class names `Circle`, `GeometricObject`, and `Desk`. The class names in the C++ library are named in lowercase. The objects are named like variables.

​​​The following points on classes and objects are worth noting:​
1. • You can use primitive data types to define variables. You can also use class names to declare object names. In this sense, a class is also a data type.
2. • In C++, you can use the assignment operator `=` to copy the contents from one object to the other. By default, each data field of one object is copied to its counterpart in the other object. For example,

```cpp
circle2 = circle1;  
```

1. copies the `radius` in `circle1` to `circle2`. After the copy, `circle1` and `circle2` are still two different objects but have the same radius.
2. • Object names are like array names. Once an object name is declared, it represents an object. It cannot be reassigned to represent another object. In this sense, an object name is a constant, though the contents of the object may change. Memberwise copy can change an object’s contents but not its name.
3. • An object contains data and may invoke functions. This may lead you to think that an object is quite large. It isn’t, though. Data are physically stored in an object, but functions are not. Since functions are shared by all objects of the same class, the compiler creates just one copy for sharing. You can find out the actual size of an object using the `sizeof` function. For example, the following code displays the size of objects `circle1` and `circle2`. Their size is `8`, since the data field radius is `double`, which takes `8` bytes.

```cpp
Circle circle1; 
Circle circle2(5.0); 
 
cout << sizeof(circle1) << endl; 
cout << sizeof(circle2) << endl; 
```

Usually you create a named object and later access its members through its name. Occasionally you may create an object and use it only once. In this case, you don’t have to name it. Such objects are called an [[anonymous object]].

The syntax to create an anonymous object using the no-arg constructor is
```cpp
ClassName()  
```

​​​The syntax to create an anonymous object using the constructor with arguments is​
```cpp
ClassName(arguments)  
```

​​​For example,​
```cpp
circle1 = Circle();  
```

creates a `Circle` object using the no-arg constructor and copies its contents to `circle1`.
```cpp
circle1 = Circle(5);  
```

creates a `Circle` object with radius `5` and copies its contents to `circle1`.

For example, the following code creates `Circle` objects and invokes their `getArea()` function.

```cpp
cout << "Area is " << Circle().getArea() << endl; 
cout << "Area is " << Circle(5).getArea() << endl; 
```

​​​As you see from these examples, you may create an anonymous object if it will not be referenced later.​

>[!warning]
Please note that in C++, to create an anonymous object using the _no-arg constructor_, you have to add parentheses after the constructor name (e.g., `Circle()`). To create a named object using the no-arg constructor, you cannot use the parentheses after the constructor name (e.g., you use `Circle circle1` rather than `Circle circle1()`). This is the required syntax, which you just have to accept.

## Self-Check
### How do you create an object using a no-arg constructor? How do you create an object using a constructor with arguments?
To declare an object using the no-arg constructor, use
`ClassName objectName;`

To declare an object using the constructor with arguments, use
`ClassName objectName(arguments);`

### Once an object name is declared, can it be reassigned to reference another object?
Once an object name is declared, it cannot be reassigned to reference another object. Object names are like constants.

### Assuming that the Circle class is defined as in LiveExample 9.1, show the output of the following code:
```cpp
Circle c1(5);
Circle c2(6);
c1 = c2;
cout << c1.radius << " " << c2.radius << endl;
```
6 6

### What is wrong in the following code? (Use the Circle class defined in LiveExample 9.1, TestCircle.cpp.)

#### (a)
```cpp
int main() 
{
  Circle c1();
  cout << c1.getRadius() << endl;

  return 0;
}
```
 
#### (b)
```cpp
int main() 
{
  Circle c1(5);
  Circle c1(6);

  return 0;
}
```

__(a)__ Line 3 is wrong. It should be  
`Circle c1;`
__(b)__ Line 4 is wrong. The object cannot be declared again.

### Which of the following statements is correct?
`Circle c;`

`Circle c();`

The first statement declares an object of Circle. The object is created using the Circle's no-arg constructor.  
The second statement is incorrect.

### Suppose the following two are independent statements. Are they correct?
`Circle c;`

`Circle c = Circle();`

The first statement declares an object of Circle. The object is created using the Circle's no-arg constructor.
For the second statement, the left-hand side of the = sign does the same as the first statement and the right-hand side creates an anonymous object using the Circle's no-arg constructor and copies the object to c.
# References
