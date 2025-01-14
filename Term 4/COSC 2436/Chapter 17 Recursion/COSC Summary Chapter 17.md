# Summary

# Learning Objectives

# Related
Prev - [[COSC Chapter 17.9 Tail Recursion]]

Next - [[COSC Chapter 18 Developing Efficient Algorithms]]
# Content
## Key Terms
1. **[[base case]]**
2. **[[infinite recursion]]**
3. **[[recursive function]]**
4. **[[recursive helper function]]**
5. **[[stopping condition]]**
6. **[[tail recursive]]**
## Chapter Summary
1. A [[recursive function]] is one that invokes itself directly or indirectly. For a [[recursive function]] to terminate, there must be one or more base cases.
2. Recursion is an alternative form of program control. It is essentially repetition without a loop control. It can be used to write simple, clear solutions for inherently recursive problems that would otherwise be difficult to solve.
3. Sometimes the original [[function]] needs to be modified to receive additional parameters in order to be invoked recursively. A [[recursive helper function]] can be defined for this purpose.
4. Recursion bears substantial overhead. Each time the program calls a [[function]], the system must assign space for all of the [[function]]’s local variables and parameters. This can consume considerable memory and requires extra time to manage the additional space.
5. A [[recursive function]] is said to be _[[tail recursive]]_ if there are no pending operations to be performed on return from a recursive call. Some compilers can optimize tail recursion to reduce stack space.
# References
