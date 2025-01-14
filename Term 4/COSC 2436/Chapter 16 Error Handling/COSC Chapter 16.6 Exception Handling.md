# Summary

# Learning Objectives

# Related
Prev - [[COSC Chapter 16.5 Multiple Catches]]

Next - [[COSC Chapter 16.7 Rethrowing Exceptions]]
# Content

## Key Point

An [[exception]] is thrown through a chain of calling functions until it is caught or it reaches to the main [[function]].

You now know how to declare an [[exception]] and how to throw an [[exception]]. When an [[exception]] is thrown, it can be caught and handled in a `try`-`catch` block, as follows:

```cpp
try 
{ 
  statements;  // Statements that may throw exceptions 
} 
catch (Exception1& ex1) 
{ 
  handler for exception1; 
} 
catch (Exception2& ex2) 
{ 
  handler for exception2; 
} 
... 
catch (ExceptionN& exN) 
{ 
  handler for exceptionN; 
} 
```

If no exceptions arise during the execution of the `try` block, the `catch` blocks are skipped.

If one of the statements inside the `try` block throws an [[exception]], C++ skips the remaining statements in the `try` block and starts the process of finding the code to handle the [[exception]]. This code, called the _[[exception]] handler_, is found by propagating the [[exception]] backward through a chain of [[function]] calls, starting from the current [[function]]. Each `catch` block is examined in turn, from first to last, to see whether the type of the [[exception]] object is an instance of the [[exception]] class in the `catch` block. If so, the [[exception]] object is assigned to the variable declared, and the code in the `catch` block is executed. If no handler is found, C++ exits this [[function]], passes the [[exception]] to the [[function]] that invoked the [[function]], and continues the same process to find a handler. If no handler is found in the chain of functions being invoked, the program prints an error message on the console and terminates. The process of finding a handler is called _catching an [[exception]]_.

Suppose the `main` [[function]] invokes `function1`, `function1` invokes `function2`, `function2` invokes `function3`, and `function3` throws an [[exception]], as shown in **Figure 16.3**. Consider the following scenario:
- If the [[exception]] type is `Exception3`, it is caught by the `catch` block for handling [[exception]] `ex3` in `function2`. `statement5` is skipped, and `statement6` is executed.
- If the [[exception]] type is `Exception2`, `function2` is aborted, the control is returned to `function1`, and the [[exception]] is caught by the `catch` block for handling [[exception]] `ex2` in `function1`. `statement3` is skipped, and `statement4` is executed.
- If the [[exception]] type is `Exception1`, `function1` is aborted, the control is returned to the `main` [[function]], and the [[exception]] is caught by the `catch` block for handling [[exception]] `ex1` in the `main` [[function]]. `statement1` is skipped, and `statement2` is executed.
- If the [[exception]] is not caught in `function2`, `function1`, and `main`, the program terminates. `statement1` and `statement2` are not executed.
![[Pasted image 20241015125109.png]]

#### Answer
 The statements called in that program is:
 `statement4`, `statement1`, `statement2`

# References
