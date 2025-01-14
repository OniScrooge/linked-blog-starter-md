# Summary

# Learning Objectives

# Related
Prev - [[COSC Chapter 16.7 Rethrowing Exceptions]]

Next - [[COSC Chapter Summary 16]]
# Content

## Key Point

Use exceptions for exceptional circumstances, not for simple logic [[errors]] that can be caught easily using an `if` statement. 

The `try` block contains the code that is executed in normal circumstances. The `catch` block contains the code that is executed in exceptional circumstances. [[Exception]] handling separates error-handling code from normal programming tasks, thus making programs easier to read and to modify. Be aware, however, that [[exception]] handling usually requires more time and resources, because it requires instantiating a new [[exception]] object, rolling back the call stack, and propagating the [[exception]] through the chain of functions invoked to search for the handler.

An [[exception]] occurs in a [[function]]. If you want the [[exception]] to be processed by its caller, you should throw it. If you can handle the [[exception]] in the [[function]] where it occurs, there is no need to throw or use exceptions.

In general, common exceptions that may occur in multiple classes in a project are candidates for [[exception]] classes. Simple [[errors]] that may occur in individual functions are best handled locally without throwing exceptions.

[[Exception]] handling is for dealing with unexpected error conditions. Do not use a `try`-`catch` block to deal with simple, expected situations. Which situations are exceptional and which are expected is sometimes difficult to decide. The point is not to abuse [[exception]] handling as a way to deal with a simple logic test.

## Self-Check

### When should exceptions be used in a program?

Use exceptions for exceptional circumstances, not for simple logic [[errors]] that can be caught easily using an if statement.

# References
