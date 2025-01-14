1. Pointers are variables that store the memory address of other variables.
2. The declaration `int* pCount;` declares _pCount_ to be a pointer that can point to an _int_ variable.
3. The ampersand(_&_) symbol is called the __address operator__ when placed in front of a variable. It is a unary operator that returns the address of the variable.
4. A pointer variable is declared with a type such as _int_ or _double_. You have to assign it with the address of the variable of the same type.
5. Like a local variable, a local pointer is assigned an arbitrary value if you don't initialize it.
6. If a pointer does not reference to a value, it should be initialized to _nullptr_ to prevent potential memory errors.
7. The asterisk(_*_) placed before a pointer is known as the indirection operator or dereference operator (dereference means indirect reference).
8. When a pointer is dereferenced, the value at the address stored in the pointer is retrieved.
9. The _const_ keyword can be used to declare constant pointer and constant data.
10. An array name is actually a constant pointer that points to the starting address of the array.
11. You can access array elements using pointers or via index.
12. An integer may be added or subtracted from a pointer. The pointer is incremented, or decremented, by that integer times the size of the element to which the pointer points.
13. A pointer argument can be passed by value or by reference.
14. A pointer may be returned from a function, but you should not return the address of a local variable from a function, because a local variable is destroyed after the function is returned.
15. The _new_ operator can be used to allocate persistent memory on the heap.
16. You should used the _delete_ operator to release the memory created using the _new_ operator, when the memory is no longer needed.
17. You can use pointers to reference an object and access object data fields and invoke functions.
18. You can create objects dynamically in a heap using the _new_ operator.
19. The keyword _this_ can be used as a pointer to the calling object.
20. Destructors are the opposite of constructors.
21. Constructors are invoked to create objects, and destructors are invoked automatically when objects are destroyed.
22. Every class has a default destructor, if the destructor is not explicitly defined.
23. The default destructor does not perform any operations.
24. Every class has a default copy constructor, if the copy constructor is not explicitly defined.
25. The default copy constructor simply copies each data filed in one object to its counterpart in the other object.