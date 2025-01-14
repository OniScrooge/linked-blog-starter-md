# Summary

# Learning Objectives
- To know the motivation and benefits of templates (§12.2).
- To define a template function with type parameters (§12.2).
- To develop a generic sort function using templates (§12.3).
- To develop generic classes using class templates (§§12.4–12.5).
- To use the C++ `vector` class as a resizable array (§12.6).
- To insert and delete elements in a vector and apply the `min_element`, `max_element`, `sort`, `random_shuffle`, and `find` functions for vectors (§12.7).
- To replace arrays using vectors (§12.8).
- To parse and evaluate expressions using stacks (§12.9).
- To use smart pointers `unique_ptr` for automatic object destruction (§12.10).
# Related


Next - [[COSC 12.4 Class Templates]]
# Content

## Key Point
You can define template functions and classes in C++ using generic types. Template functions and classes enable programs to work on many different data types without being rewritten for each one.

---

C++ provides functions and classes for developing reusable software. Templates provide the capability to parameterize types in functions and classes. With this capability, you can define one function or one class with a generic type that the compiler can substitute for a concrete type. For example, you may define one function for finding the maximum number between two numbers of a generic type. If you invoke this function with two `int` arguments, the generic type is replaced by the `int` type. If you invoke this function with two `double` arguments, the generic type is replaced by the `double` type.

This chapter introduces the concept of templates, and you will learn how to define function templates and class templates and use them with concrete types. You will also learn a very useful generic template `vector`, which you can use to replace arrays.

# References
