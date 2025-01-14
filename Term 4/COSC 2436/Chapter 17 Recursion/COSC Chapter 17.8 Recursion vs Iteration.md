# Summary

# Learning Objectives

# Related
Prev - [[COSC Chapter 17.7 Eight Queens]]

Next - [[COSC Chapter 17.9 Tail Recursion]]
# Content
## Key Point

Recursion is an alternative form of program control. It is essentially repetition without a loop.

Recursion is an alternative form of program control. It is essentially repetition without a loop control. When you use loops, you specify a loop body. The repetition of the loop body is controlled by the loop-control structure. In recursion, the [[function]] itself is called repeatedly. A selection statement must be used to control whether to call the [[function]] recursively or not.

Recursion bears substantial overhead. Each time the program calls a [[function]], the system must assign space for all of the [[function]]’s local variables and parameters. This can consume considerable memory and requires extra time to manage the additional space.

Any problem that can be solved recursively can be solved nonrecursively with iterations. Recursion has some negative aspects: It uses too much time and too much memory. Why, then, should you use it? In some cases, using recursion enables you to specify a clear, simple solution for an inherent recursive problem that would otherwise be difficult to obtain. The Tower of Hanoi problem is such an example, which is rather difficult to solve without using recursion.

The decision whether to use recursion or iteration should be based on the nature of the problem you are trying to solve and your understanding of it. The rule of thumb is to use whichever of the two approaches can best develop an intuitive solution that naturally mirrors the problem. If an iterative solution is obvious, use it. It generally will be more efficient than the recursive option.

>[!Note]
>Your recursive program could run out of memory, causing a _stack overflow_ runtime error.

>[!Tip]
>If you are concerned about your program’s performance, avoid using recursion, because it takes more time and consumes more memory than iteration.

## Self-Check
### Which of the following statements are true?  
1. Any [[recursive function]] can be converted into a nonrecursive [[function]].
2. A [[recursive function]] takes more time and memory to execute than a nonrecursive [[function]]. 
3. Recursive functions are always simpler than nonrecursive functions.
4. There is always a selection statement in a [[recursive function]] to check whether a [[base case]] is reached.
5. Recursive functions run faster than non-recursive functions.
#### Answer
1. TRUE
2. TRUE
3. FALSE
4. TRUE
5. FALSE
### What is the cause for the stack overflow [[exception]]?

When a [[function]] is invoked, its contents are placed into a stack. If a [[function]] is recursively invoked, it is possible that the stack space is exhausted. This causes stack overflow.
# References
