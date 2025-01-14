# Summary

# Learning Objectives

# Related
Prev - [[COSC Chapter 10.1 Introduction]]

Next - [[COSC Chapter 10.2.1 Constructing a String]]
# Content
## Key Point
The `string` class defines the `string` type in C++. It contains many useful functions for manipulating strings.

In C++ there are two ways to process strings. One way is to treat them as arrays of characters ending with the null terminator (`'\0'`), as discussed in **Section 7.11**, “C-Strings.” These are known as _C-strings_. The null terminator indicates the end of the string, which is important for the C-string functions to work. The other way is to process strings using the `string` class. You can use the C-string functions to manipulate and process strings, but the `string` class is easier. Processing C-strings requires the programmer to know how characters are stored in the array. The `string` class hides the low-level storage from the programmer. The programmer is freed from implementation details.

**Section 4.8**, “The `string` Type,” briefly introduced the string type. You learned how to retrieve a string character using the `at(index)` function and the subscript operator `[]`, and use the `size()` and `length()` functions to return the number of characters in a string. This section gives a more detailed discussion on using string objects.
# References
