# Summary

# Learning Objectives
Prev - [[COSC Chapter 10.11 Class design guidelines]]

Next - [[COSC Chapter 11 - Pointers and Dynamic Memory Management]]
# Related

# Content
## Key Terms
1. **[[aggregation]]**
2. **[[composition]]**
3. **[[constant function]]**
4. **[[initializer list]]**
5. **[[has-a relationships]]**
6. **[[instance variable 1]]**
7. **[[instance function 1]]**
9. **[[multiplicity]]**
10. **[[static function]]**
11. **[[static variable]]**
## Chapter Summary
1. The C++ `string` [[class]] encapsulates an array of characters and provides many functions for processing strings such as `append`, `assign`, `at`, `clear`, `erase`, `empty`, `length`, `c_str`, `compare`, `substr`, `find`, `insert`, and `replace`.
2. C++ supports operators (`[]`, `=`, `+`, `+=`, `<<`, `>>`, `==`, `!=`, `<`, `<=`, `>`, `>=`) to simplify string operations.
3. You can use `cin` to read a string ending with a whitespace character and use `getline(cin, s, delimiterCharacter)` to read a string ending with the specified delimiter character.
4. You can pass an [[object]] to a [[function]] by value or by reference. For performance, passing by reference is preferred.
5. If the [[function]] does not change the [[object]] being passed, define the [[object]] parameter as a constant reference parameter to prevent the [[object]]’s data being modified accidentally.
6. An [[instance]] variable or [[function]] belongs to an [[instance]] of a [[class]]. Its use is associated with individual instances.
7. A [[static variable]] is a variable shared by all instances of the same [[class]].
8. A [[static function]] is a [[function]] that can be invoked without using instances.
9. Every [[instance]] of a [[class]] can access the [[class]]’s static variables and functions. For clarity, however, it is better to invoke static variables and functions using `ClassName::staticVariable` and `ClassName::functionName(arguments)`.
10. If a [[function]] does not change the [[data fields]] of an [[object]], define the [[function]] constant to prevent [[errors]].
11. A [[constant function]] does not change the values of any [[data fields]].
12. You can specify a [[member function]] to be constant by placing the `const` modifier at the end of the [[function]] declaration.
13. The [[object]]-oriented approach combines the power of the procedural paradigm with an added dimension that integrates data with operations into objects.
14. The procedural paradigm focuses on designing functions. The [[object]]-oriented paradigm couples data and functions together into objects.
15. Software design using the [[object]]-oriented paradigm focuses on objects and operations on objects.
16. An [[object]] can contain another [[object]]. The relationship between the two is called _[[composition]]_.
17. Some guidelines for [[class]] design are _cohesion_, _consistency_, _encapsulation_, _clarity_, and _completeness_.

# References
