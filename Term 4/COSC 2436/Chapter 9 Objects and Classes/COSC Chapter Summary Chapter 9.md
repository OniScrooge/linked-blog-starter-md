# Summary

# Learning Objectives
Prev - [[COSC Chapter 9.11 Class abstraction and encapsulation]]

Next - 
# Related

# Content
## Key Terms
1. **[[accessor]]**
2. **[[anonymous object]]**
3. **[[binary scope resolution operator]] (`::`)**
4. **[[calling object]]**
5. **[[class]]**
6. **[[class abstraction]]**
7. **[[class encapsulation]]**
8. **[[client]]**
9. **constructor**
10. **[[contract]]**
11. **[[data fields]]**
12. **[[data field encapsulation]]**
13. **[[default constructor]]**
14. **[[dot operator]] (`.`)**
15. **inclusion guard**
16. **[[inline definition]]**
17. **[[instance]]**
18. **[[remote-vault/Term 4/COSC 2436/Terms & Concepts/instance function]]**
19. **[[remote-vault/Term 4/COSC 2436/Terms & Concepts/instance variable]]**
20. **[[instantiation]]**
21. **[[member function]]**
22. **[[member access operator]]**
23. **[[mutator]]**
24. **[[no-arg constructor]]**
25. **[[object]]**
26. **[[object-oriented programming]] (OOP)**
27. **property**
28. **[[private]]**
29. **[[public]]**
30. **[[state]]**
31. **[[UML class diagram]]**
## Chapter Summary
1. A [[class]] is a blueprint for objects.
2. A [[class]] defines the [[data fields]] for storing the [[properties]] of objects and provides constructors for creating objects and functions for manipulating them.
3. Constructors must have the same name as the [[class]] itself.
4. A non-arg constructor is a constructor that does not have arguments.
5. A [[class]] is also a data type. You can use it to declare and create objects.
6. An [[object]] is an [[instance]] of a [[class]]. You use the dot (`.`) operator to access members of that [[object]] through its name.
7. The _[[state]]_ of an [[object]] is represented by _[[data fields]]_ (also known as _[[properties]]_) with their current values.
8. The _behavior_ of an [[object]] is defined by a set of functions.
9. The [[data fields]] do not have initial values. They must be initialized in constructors.
10. You can separate [[class]] definition from [[class]] implementation by defining [[class]] in a header file and [[class]] implementation in a separate file.
11. The C++ `#ifndef` directive, called _inclusion guard_, can be used to prevent a header file from being included multiple times.
12. When a [[function]] is implemented inside a [[class]] definition, it automatically becomes an inline [[function]].
13. Visibility keywords specify how the [[class]], [[function]], and data are accessed.
14. A `public` [[function]] or data is accessible to all clients.
15. A `private` [[function]] or data is accessible only inside the [[class]].
16. You can provide a getter [[function]] or a _setter [[function]]_ to enable clients to see or modify the data.
17. Colloquially, a getter [[function]] is referred to as a _getter_ (or _[[accessor]]_), and a _setter [[function]]_ is referred to as a _setter_ (or _[[mutator]]_).
18. A getter [[function]] has the signature
```cpp
returnType getPropertyName() 
```

19. If the `returnType` is `bool`, the getter [[function]] should be defined as
```cpp
bool isPropertyName(). 
```

20. A _setter [[function]]_ has the signature
```cpp
void setPropertyName(dataType propertyValue) 
```
# References
