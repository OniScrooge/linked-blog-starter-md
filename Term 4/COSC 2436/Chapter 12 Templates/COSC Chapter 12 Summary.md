# Summary

# Learning Objectives

# Related
Prev - [[COSC 12.10 Using Smart Pointers for automatic object destruction]]

Next - [[COSC 13.1 Introduction]]
# Content
## Key Terms
1. **smart pointer**
2. **template**
3. **template class**
4. **template function**
5. **template prefix**
6. **type parameter**
## Chapter Summary
1. Templates provide the capability to parameterize types in functions and classes.
2. You can define functions or classes with generic types that can be substituted for concrete types by the compiler.
3. The definition for the function template begins with the keyword `template` followed by a list of parameters. Each parameter must be preceded by the interchangeable keywords `class` or `typename` in the form
```cpp
<typename typeParameter> or 
<class typeParameter> 
```

4. When you define a generic function, it is better to start with a nongeneric function, debug and test it, and then convert it to a generic function.
5. The syntax for class templates is basically the same as that for function templates. You place the template prefix before the class definition, just as you place the template prefix before the function template.
6. If the elements need to be processed in a last-in first-out fashion, use a stack to store the elements.
7. The array size is fixed after it is created. C++ provides the `vector` class, which is more flexible than arrays.
8. The `vector` class is a generic class. You can use it to create objects for concrete types.
9. You can use a `vector` object just like an array, but a vector’s size can grow automatically if needed.
10. You can use the C++11 smart pointers `unique_ptr` for automatic object destruction.
# References
