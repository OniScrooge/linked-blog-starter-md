# Summary

# Learning Objectives

# Related
Prev - [[COSC Chapter 10.2.3 Assigning a string]]

Next - [[COSC Chapter 10.2.5 Functions length, size, capacity, and c_str]]
# Content
You can use the `at(index)` function to retrieve a character at a specified index, `clear()` to clear the string, `erase(index, n)` to delete part of the string, `empty()` to test whether a string is empty, and `front()` and `back()` to return the first and last character from the string, as shown in **Figure 10.3**.

## Figure 10.3
![[Pasted image 20241207150929.png]]

For example:
```cpp
string s1("Welcome"); 
cout << s1.at(3) << endl; // s1.at(3) returns c 
cout << s1.erase(2, 3) << endl; // s1 is now Weme 
 
s1.clear(); // s1 is now empty 
cout << s1.empty() << endl; // s1.empty returns 1 (means true) 
```

## Self-Check
### What are the results of the following expressions?
Suppose that s1 is a string, given as follows:
`string s1("I have a dream");`

Assume that each expression is independent.
(1) s1.at(0)
(2) s1.erase(1, 2)
(3) s1.empty()

#### Answer
(1) I                           
(2) Iave a dream                        
(3) s1 is now empty
# References
