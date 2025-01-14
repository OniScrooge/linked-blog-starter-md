# Summary

# Learning Objectives

# Related
Prev - [[COSC Chapter 10.2 The string class]]

Next - [[COSC Chapter 10.2.2 Appending to a String]]
# Content
You created a string using a syntax like this:
```cpp
string s = "Welcome to C++"; 
```

Alternatively, you can use this:
```cpp
string s("Welcome to C++"); 
```

The two are equivalent. You can create an _empty string_ using `string`’s no-arg constructor. For example, the following statement creates an empty string:
```cpp
string s; 
```

You can also create a string from a C-string using `string`’s constructor as shown in the following code:
```cpp
char s1[] = "Good morning"; 
string s(s1); 
```

Here `s1` is a C-string and `s` is a string object.
## Self-Check
### Which one is better?
To create a string "Welcome to C++", you may use a statement like this:
`string s1("Welcome to C++");`
`string s1 = "Welcome to C++";`

In modern compilers, the two are equivalent.
# References
