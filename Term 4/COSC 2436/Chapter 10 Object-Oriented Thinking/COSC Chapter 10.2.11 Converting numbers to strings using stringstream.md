# Summary

# Learning Objectives

# Related
Prev - [[COSC Chapter 10.2.10 String Operators]]

Next - [[COSC Chapter 10.2.12 Splitting strings]]
# Content
**Section 7.11.7**, “Converting Numbers to Strings,” introduced the `to_string` function for converting a number to a string. When converting a floating-point number to a string, the converted string contains six digits after the decimal point. Trailing zeros are appended to the string if there are not enough digits after the decimal point. To avoid trailing zeros in the string, you can write a function to perform the conversion. However, a simple approach is to use the `stringstream` class in the `<``sstream``>` header. `stringstream` provides an interface to manipulate strings as if they were input/output streams. One application of `stringstream` is for converting numbers to strings. Here is an example:​ 

```cpp
stringstream ss; 
ss << 3.1415; 
string s = ss.str(); 
```

## Self-Check
### What is the header file for `stringstream`? How to return a `string` from a `stringstream`?
The header file for `stringstream` is `sstream`. To return a string from a `stringstream`, invoke the `str()` function from the `stringstream`.
# References
