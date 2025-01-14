# Summary

# Learning Objectives

# Related
Prev - [[COSC Chapter 10.2.4 Functions at, clear, erase, empty, back, and front]]

Next - [[COSC Chapter 10.2.6 Comparing strings]]
# Content
You can use the functions `length()`, `size()`, and `capacity()` to obtain a string’s length, size, and capacity and `c_str()` to return a C-string, as shown in **Figure 10.4**. The functions `length()` and `size()` are aliases. The functions `c_str()` and `data()` are the same in the new C++11. The `capacity()` function returns the internal buffer size which is always greater than or equal to the actual string size.

## Figure 10.4
![[Pasted image 20241207151138.png]]

For example, see the following code:
```cpp
1  string s1("Welcome"); 
2  cout << s1.length() << endl; // Length is 7 
3  cout << s1.size() << endl; // Size is 7 
4  cout << s1.capacity() << endl; // Capacity is 15 
5 
6  s1.erase(1, 2); 
7  cout << s1.length() << endl; // Length is now 5 
8  cout << s1.size() << endl; // Size is now 5 
9  cout << s1.capacity() << endl; // Capacity is still 15 
```

>[!Note]
The _capacity_ is set to `15` when string `s1` is created in line 1. After two characters are erased in line 6, the capacity is still `15`, but the length and size become `5`.

## Self-Check
### What are the results of the following expressions?
Suppose that s1 is a string, given as follows:
`string s1("I have a dream");`

Assume that each expression is independent.
(1) s1.length()
(2) s1.size()
(3) s1.capacity() 
(4) s1.c_str()

#### Answer
(1)  14              
(2)  14              
(3)  14                       
(4)  I have a dream
# References
