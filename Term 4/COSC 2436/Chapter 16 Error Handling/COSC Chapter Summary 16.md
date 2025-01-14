# Summary

# Learning Objectives

# Related
Prev - [[COSC Chapter 16.8 When to use Exceptions]]

Next - [[COSC Chapter 18 Developing Efficient Algorithms]]
# Content

## Key Terms
1. **[[exception]]**
2. **[[exception]] specification**
3. **[[rethrow exception]]**
4. **[[standard exception]]**
5. **[[throw exception]]**
6. **throw list**

## Chapter Summary
1. [[Exception]] handling makes programs robust. [[Exception]] handling separates error-handling code from normal programming tasks, thus making programs easier to read and modify. Another important advantage of [[exception]] handling is that it enables a [[function]] to throw an [[exception]] to its caller.
2. C++ allows you to use the `throw` statement to throw a value of any type (primitive or class type) when an [[exception]] occurs. This value is passed to a `catch` block as an argument so that the `catch` block can utilize this value to process the [[exception]].
3. When an [[exception]] is thrown, the normal execution flow is interrupted. If the [[exception]] value matches a `catch` block parameter type, the control is transferred to a `catch` block. Otherwise, the [[function]] is exited and the [[exception]] is thrown to the [[function]]’s caller. If the [[exception]] is not handled in the `main` [[function]], the program is aborted.
4. C++ provides a number of [[standard exception]] classes that can be used for creating [[exception]] objects. You can use the `exception` class or its derived classes `runtime_error` and `logic_error` to create [[exception]] objects.
5. You also can create a custom [[exception]] class if the [[standard exception]] classes cannot adequately describe exceptions. This class is just like any C++ class, but often it is desirable to derive it from `exception` or a [[derived class]] of `exception` so you can utilize the common features (e.g., the `what()` [[function]]) in the `exception` class.
6. A `try` block may be followed by multiple `catch` blocks. The order in which exceptions are specified in `catch` blocks is important. A `catch` block for a [[base class]] type should appear after a `catch` block for a [[derived class]] type.
7. If a [[function]] throws an [[exception]], you should declare the [[exception]]’s type in the [[function]] header to warn programmers to deal with potential exceptions.
8. [[Exception]] handling should not be used to replace simple tests. You should test simple exceptions whenever possible and reserve [[exception]] handling for dealing with situations that cannot be handled with `if` statements.

# References
