# Summary

# Learning Objectives

# Related
Prev - [[COSC 12.8 Replacing Arrays using the Vector Class]]

Next - [[COSC 12.10 Using Smart Pointers for automatic object destruction]]
# Content

## Key Point

Stacks can be used to evaluate expressions.

Stacks have many applications. This section gives an application of using stacks. You can enter an arithmetic expression from Google to evaluate the expression as shown in **Figure 12.3**.

__Figure 12.3__
![The figure illustrates Google calculator.](https://cite-media.pearson.com/legacy_paths/8cbc184a-32d6-4945-b039-d55c3db4d4c0/12fig03_New.png "Figure 12.3 click to zoom")
You can evaluate an arithmetic expression from Google.

A Google search window with search text as 51 plus (54 multiplied by (3 plus 2)) is opened in a web browser. The calculator shows the output: 51 plus (54 multiplied by (3 plus 2)) equals 321.

How does Google evaluate an expression? This section presents a program that evaluates a _compound expression_ with multiple operators and parentheses (e.g., `(15 + 2) * 34 – 2)`. For simplicity, assume that the operands are integers and operators are of four types: `+`, `-`, `*`, and `/`.

The problem can be solved using two stacks, named `operandStack` and `operatorStack`, for storing operands and operators, respectively. Operands and operators are pushed into the stacks before they are processed. When an _operator is processed_, it is popped from `operatorStack` and applied on the first two operands from `operandStack` (the two operands are popped from `operandStack`). The resultant value is pushed back to `operandStack`.

The algorithm takes two phases:

### **Phase 1: Scanning expression**

The program scans the expression from left to right to extract operands, operators, and the parentheses.

1.1 If the extracted item is an operand, push it to `operandStack`.

1.2 If the extracted item is a `+` or `-` operator, process all the operators at the top of `operatorStack` with higher or equal precedence (i.e., `+`, `-`, `*`, `/`), push the extracted operator to `operatorStack`.

1.3 If the extracted item is a `*` or `/` operator, process all the operators at the top of `operatorStack` with higher or equal precedence (i.e., `*`, `/`), push the extracted operator to `operatorStack`.

1.4 If the extracted item is a `(` symbol, push it to `operatorStack`.

1.5 If the extracted item is a `)` symbol, repeatedly process the operators from the top of `operatorStack` until seeing the `(` symbol on the stack.

### **Phase 2: Clearing stack**

Repeatedly process the operators from the top of `operatorStack` until `operatorStack` is empty.

**The following animation** shows how the algorithm is applied to evaluate the expression `(1 + 2) * 4 - 3`.

**LiveExample 12.12 EvaluateExpression.cpp**
```C++
#include <iostream>
#include <vector>
#include <string>
#include <cctype>
#include "ImprovedStack.h"

using namespace std;

// Split an expression into numbers, operators, and parenthese
vector<string> split(const string& expression);

// Evaluate an expression and return the result
int evaluateExpression(const string& expression);

// Perform an operation
void processAnOperator(
  Stack<int>& operandStack, Stack<char>& operatorStack);

int main()
{
  string expression;
  cout << "Enter an expression: ";
  getline(cin, expression);

  cout << expression << " = " 
    << evaluateExpression(expression) << endl;

  return 0;
}

vector<string> split(const string& expression)
{
  vector<string> v; // A vector to store split items as strings
  string numberString; // A numeric string

  for (unsigned int i = 0; i < expression.length(); i++)
  {
    if (isdigit(expression[i]))
      numberString.append(1, expression[i]); // Append a digit
    else
    {
      if (numberString.size() > 0)
      {
        v.push_back(numberString); // Store the numeric string
        numberString.erase(); // Empty the numeric string
      }

      if (!isspace(expression[i]))
      {
        string s;
        s.append(1, expression[i]);
        v.push_back(s); // Store an operator and parenthesis
      }
    }
  }

  // Store the last numeric string
  if (numberString.size() > 0)
    v.push_back(numberString);

  return v;
}

// Evaluate an expression 
int evaluateExpression(const string& expression)
{
  // Create operandStack to store operands
  Stack<int> operandStack;

  // Create operatorStack to store operators
  Stack<char> operatorStack;

  // Extract operands and operators
  vector<string> tokens = split(expression);

  // Phase 1: Scan tokens
  for (unsigned int i = 0; i < tokens.size(); i++)
  {
    if (tokens[i][0] == '+' || tokens[i][0] == '-')
    {
      // Process all +, -, *, / in the top of the operator stack
      while (!operatorStack.empty() && (operatorStack.peek() == '+'
       || operatorStack.peek() == '-' || operatorStack.peek() == '*'
       || operatorStack.peek() == '/'))
      {
        processAnOperator(operandStack, operatorStack);
      }

      // Push the + or - operator into the operator stack
      operatorStack.push(tokens[i][0]);
    }
    else if (tokens[i][0] == '*' || tokens[i][0] == '/')
    {
      // Process all *, / in the top of the operator stack
      while (!operatorStack.empty() && (operatorStack.peek() == '*'
        || operatorStack.peek() == '/'))
      {
        processAnOperator(operandStack, operatorStack);
      }

      // Push the * or / operator into the operator stack
      operatorStack.push(tokens[i][0]);
    }
    else if (tokens[i][0] == '(')
    {
      operatorStack.push('('); // Push '(' to stack
    }
    else if (tokens[i][0] == ')')
    {
      // Process all the operators in the stack until seeing '('
      while (operatorStack.peek() != '(')
      {
        processAnOperator(operandStack, operatorStack);
      }

      operatorStack.pop(); // Pop the '(' symbol from the stack
    }
    else
    { // An operand scanned. Push an operand to the stack as integer
      operandStack.push(atoi(tokens[i].c_str()));
    }
  }

  // Phase 2: process all the remaining operators in the stack
  while (!operatorStack.empty())
  {
    processAnOperator(operandStack, operatorStack);
  }

  // Return the result
  return operandStack.pop();
}

// Process one opeator: Take an operator from operatorStack and 
// apply it on the operands in the operandStack 
void processAnOperator(
    Stack<int>& operandStack, Stack<char>& operatorStack)
{
  char op = operatorStack.pop();
  int op1 = operandStack.pop();
  int op2 = operandStack.pop();
  if (op == '+')
    operandStack.push(op2 + op1);
  else if (op == '-')
    operandStack.push(op2 - op1);
  else if (op == '*')
    operandStack.push(op2 * op1);
  else if (op == '/')
    operandStack.push(op2 / op1);
}
```

```
command>cl EvaluateExpression.cpp
Microsoft C++ Compiler 2019 
Compiled successful (cl is the VC++ compile/link command)

command>EvaluateExpression 
Enter an expression: (13 + 2) * 4 - 3
(13 + 2) * 4 - 3 = 57

command>
```

The program reads an expression as a string (line 23) and invokes the `evaluateExpression` function (line 26) to evaluate the expression.

The `evaluateExpression` function creates two stacks `operandStack` and `operatorStack` (lines 68, 71) and invokes the `split` function to extract numbers, operators, and parentheses from the expression (line 74) into tokens. The tokens are stored in a vector of strings. For example, if the expression is `(13 + 2) * 4 – 3`, the tokens are `(`, `13`, `+`, `2`, `)`, `*`, `4`, `-`, and `3`.

The `evaluateExpression` function scans each token in the `for` loop (lines 77–122). If a token is an operand, push it to `operandStack` (line 120). If a token is a `+` or `–` operator (line 79), process all the operators from the top of `operatorStack` if any (lines 81–87) and push the newly scanned operator to the stack (line 90). If a token is a `*` or `/` operator (line 92), process all the `*` and `/` operators from the top of `operatorStack` if any (lines 95–99) and push the newly scanned operator to the stack (line 102). If a token is a `(` symbol (line 104), push it to `operatorStack`. If a token is a `)` symbol (line 108), process all the operators from the top of `operatorStack` until seeing the `)` symbol (lines 111–114) and pop the `)` symbol from the stack (line 116).

After all tokens are considered, the program processes the remaining operators in `operatorStack` (lines 125–128).

The `processAnOperator` function (lines 136–150) processes an operator. The function pops the operator from `operatorStack` (line 139) and pops two operands from `operandStack` (lines 140–141). Depending on the operator, the function performs an operation and pushes the result of the operation back to `operandStack` (lines 143, 145, 147, 149).

## Self-Check

### Trace how the expression (3 + 4) * (1 - 3) - ((1 + 3) * 5 - 4) is evaluated using the EvaluateExpression program.

Omitted
### Can the EvaluateExpression program evaluate the following expressions "1+2", "1 + 2", "(1) + 2", "((1)) + 2", and "(1 + 2)"?

Yes.

### Show the change of the contents in the stacks when evaluating "3 + (4 + 5) * (3 + 5) + 4 * 5" using the EvaluateExpression program.

Omitted.

### If you enter an expression "4 + 5 5 5", the program will display 10. How do you fix this problem?

You can fix this problem by throwing an exception if operandStack is not empty after poping the result out of the operandStack stack.

# References
