# Summary

# Learning Objectives

# Related
Prev - [[COSC Chapter 10.2.8 Searching in a string]]

Next - [[COSC Chapter 10.2.10 String Operators]]
# Content
You can use the `insert`​ ​and `replace`​ ​functions to insert a substring and replace a substring in a string, as shown in **Figure 10.8**.

## Figure 10.8
![[Pasted image 20241207151932.png]]

Here are examples of using the `insert`​ ​and `replace`​ ​functions:
```cpp
string s1("Welcome to HTML"); 
s1.insert(11, "C++ and "); 
cout << s1 << endl; // s1 becomes Welcome to C++ and HTML 
string s2("AA"); 
s2.insert(1, 4, 'B'); 
cout << s2 << endl; // s2 becomes to ABBBBA 
string s3("Welcome to HTML"); 
s3.replace(11, 4, "C++"); 
cout << s3 << endl; // s3 becomes Welcome to C++ 
```

>[!Note]
A `string` object invokes the `append`, `assign`, `erase`, `replace`, and `insert` functions to change the contents of the `string` object. These functions also return the new string. For example, in the following code, `s1` invokes the `insert` function to insert `"C++ and "` into `s1`, and the new string is returned and assigned to `s2`.

```cpp
string s1("Welcome to HTML"); 
string s2 = s1.insert(11, "C++ and "); 
cout << s1 << endl; // s1 becomes Welcome to C++ and HTML 
cout << s2 << endl; // s2 becomes Welcome to C++ and HTML 
```

>[!Note]
On most compilers, the capacity is automatically increased to accommodate more characters for the functions `append`, `assign`, `insert`, and `replace`. If the capacity is fixed and is too small, the function will copy as many characters as possible.

## Self-Check
### What are the results of the following expressions?
Suppose that s1 is a string, given as follows:
`string s1("I have a dream");`

Assume that each expression is independent.
(1) s1.replace(2, 4, "NEW")
(2) s1.insert(4, "NEW")
(3) s1.insert(6, 8, 'N')

#### Answer
(1) I NEW a dream              
(2) I haNEWve a dream             
(3) I haveNNNNNNNN a dream             

### Show the output of the following code (the replaceString function is defined in LiveExample 10.2).
```cpp
string s("abcdabab"), oldSubStr("ab"), newSubStr("AAA");
replaceString(s, oldSubStr, newSubStr);
cout << s << endl;
```
AAAcdAAAAAA
# References
