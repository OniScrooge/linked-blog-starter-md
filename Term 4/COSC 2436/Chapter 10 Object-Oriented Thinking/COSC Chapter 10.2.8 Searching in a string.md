# Summary

# Learning Objectives

# Related
Prev - [[COSC Chapter 10.2.7 Obtaining substrings]]

Next - [[COSC Chapter 10.2.9 Inserting and replacing strings]]
# Content
You can use the `find` function to search for a substring or a character in a string, as shown in **Figure 10.7**. The function returns `string::npos` (not a position) if no match is found. `npos` is a constant defined in the `string` class.

## Figure 10.7
![[Pasted image 20241207151709.png]]

For example:
```cpp
string s1("Welcome to HTML"); 
cout << s1.find("co") << endl; // Returns 3 
cout << s1.find("co", 6) << endl; // Returns string::npos 
cout << s1.find('o') << endl; // Returns 4 
cout << s1.find('o', 6) << endl; // Returns 9 
```

## Self-Check
### What are the results of the following expressions?
Suppose that s1 is a string, given as follows:
`string s1("I have a dream");`

Assume that each expression is independent.
(1) s1.find('A')
(2) s1.find('a', 9)

#### Answer
(1) string::npos               
(2) 12              
### What is wrong in the following code? How do you fix it?
```cpp
string s("New York");
if (s.find('P') >= 0)
{
  cout << "Character P is in " << s << endl;
}
else 
{
  cout << "Character P is not in " << s << endl;
}
```

The test condition should be changed to:
`if (s.find('P') != string::npos )`
# References
