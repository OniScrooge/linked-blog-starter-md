# Summary

# Learning Objectives

# Related

# Content

## Key Terms

1. **abstract class**
2. **abstract function**
3. **[[base class]]**
4. **[[constructor chaining]]**
5. **[[derived class]]**
6. **[[destructor chaining]]**
7. **downcasting**
8. **[[dynamic binding]]**
9. **[[child class]]**
10. **[[generic programming]]**
11. **[[inheritance]]**
12. **override function**
13. **[[parent class]]**
14. **[[polymorphism]]**
15. **protected**
16. **[[pure virtual function]]**
17. **[[subclass]]**
18. **[[subtype]]**
19. **[[superclass]]**
20. **[[supertype]]**
21. **upcasting**
22. **[[virtual function]]**

## Chapter Summary
1. You can derive a new class from an existing class. This is known as _class [[inheritance]]_. The new class is called a _[[derived class]]_, _[[child class]]_, or _[[subclass]]_. The existing class is called a _[[base class]]_ or _[[parent class]]_.
2. An object of a [[derived class]] can be passed wherever an object of a base type parameter is required. Then a [[function]] can be used generically for a wide range of object arguments. This is known as _[[generic programming]]_.
3. A constructor is used to construct an instance of a class. Unlike data fields and functions, the constructors of a [[base class]] are not inherited in the [[derived class]]. They can only be invoked from the constructors of the derived classes to initialize the data fields in the [[base class]].
4. A [[derived class]] constructor always invokes its [[base class]] constructor. If a base constructor is not invoked explicitly, the [[base class]] no-arg constructor is invoked by default.
5. Constructing an instance of a class invokes the constructors of all the base classes along the [[inheritance]] chain.
6. A [[base class]] constructor is called from a [[derived class]] constructor. Conversely, the destructors are automatically invoked in reverse order, with the [[derived class]]’s destructor invoked first. This is called _constructor and [[destructor chaining]]_.
7. A [[function]] defined in the [[base class]] may be redefined in the [[derived class]]. A redefined [[function]] must match the signature and return type of the [[function]] in the [[base class]].
8. A [[virtual function]] enables [[dynamic binding]]. A [[virtual function]] is often redefined in the derived classes. The compiler decides which [[function]] implementation to use dynamically at runtime.
9. If a [[function]] defined in a [[base class]] needs to be redefined in its derived classes, you should define it virtual to avoid confusions and mistakes. On the other hand, if a [[function]] will not be redefined, it is more efficient not to declare it virtual, because more time and system resource are required to bind virtual functions dynamically at runtime.
10. A protected data field or a protected [[function]] in a [[base class]] can be accessed in its derived classes.
11. A [[pure virtual function]] is also called an abstract [[function]].
12. If a class contains a [[pure virtual function]], the class is called an abstract class.
13. You cannot create instances from an abstract class, but abstract classes can be used as data types for parameters in a [[function]] to enable [[generic programming]].
14. You can use the `static_cast` and `dynamic_cast` operators to cast an object of a [[base class]] type to a [[derived class]] type. `static_cast` is performed at compile time and `dynamic_cast` is performed at runtime for runtime type checking. The `dynamic_cast` operator can only be performed on a polymorphic type (i.e., the type with virtual functions).
# References
