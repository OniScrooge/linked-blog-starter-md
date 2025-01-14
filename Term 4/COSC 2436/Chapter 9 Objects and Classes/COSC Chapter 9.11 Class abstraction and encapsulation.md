# Summary

# Learning Objectives

# Related
Prev - [[COSC Chapter 9.10 The scope of variables]]

Next - [[COSC Chapter Summary Chapter 9]]
# Content
## Key Point
_Class abstraction_ is the separation of class implementation from the use of a class. The details of implementation are encapsulated and hidden from the user. This is known as _class encapsulation_.

In **Chapter 6** you learned about function abstraction and used it in stepwise program development. C++ provides many levels of abstraction. [[class abstraction]] is the separation of class implementation from the use of a class. The creator of a class provides a description of the class and lets the user know how it can be used. The collection of constructors and functions that are accessible from outside the class, together with the description of how these members are expected to behave, serves as the _class’s contract_. As shown in **Figure 9.7**, the user of the class does not need to know how the class is implemented. The details of implementation are encapsulated and hidden from the user. This is known as [[class encapsulation]]. For example, you can create a `Circle` object and find the area of the circle without knowing how the area is computed.

## Figure 9.7
![[Pasted image 20241207123603.png]]

Class abstraction and encapsulation are two sides of the same coin. Many real-life examples illustrate the concept of class abstraction. Consider, for instance, building a computer system. Your personal computer is made up of many components, such as CPU, memory, hard disk, motherboard, fan, and so on. Each component can be viewed as an object that has properties and functions. To get the components to work together, all you need to know is how each component is used and how it interacts with the others. You don’t need to know how it works internally. The internal implementation is encapsulated and hidden from you. You can build a computer without knowing how a component is implemented.

​​​The computer-system analogy precisely mirrors the object-oriented approach. Each component can be viewed as an object of the class for the component. For example, you might have a class that models all kinds of fans for use in a computer, with properties like fan size and speed, functions like start, stop, and so on. A specific fan is an instance of this class with specific property values.​

As another example, consider getting a loan. A specific loan can be viewed as an object of a `Loan` class. Interest rate, loan amount, and loan period are its data properties, and computing monthly payment and total payment are its functions. When you buy a car, a loan object is created by instantiating the class with your loan interest rate, loan amount, and loan period. You can then use the functions to find the monthly payment and total payment of your loan. As a user of the `Loan` class, you don't need to know how these functions are implemented.

Let us use the `Loan` class as an example to demonstrate the creation and use of classes. `Loan` has the data fields `annualInterestRate`, `numberOfYears`, and `loanAmount`, and the functions `getAnnualInterestRate`, `getNumberOfYears`, `getLoanAmount`, `setAnnualInterestRate`, `setNumberOfYears`, `setLoanAmount`, `getMonthlyPayment`, and `getTotalPayment`, as shown in ​**Figure​ ​9.8**​.

## Figure 9.8
![[Pasted image 20241207123634.png]]

The UML diagram in **Figure 9.8** serves as the contract for the `Loan` class. Throughout the book, you will play the role of both class user and class developer. The user can use the class without knowing how the class is implemented. Assume that the `Loan` class is available, with the header file, as shown in **LiveExample 9.13**. Let us begin by writing a test program that uses the `Loan` class, in **LiveExample 9.14**.

## **LiveExample 9.13 Loan.h**
```cpp
#ifndef LOAN_H
#define LOAN_H

class Loan
{
public:
  Loan();
  Loan(double rate, int years, double amount);
  double getAnnualInterestRate();
  int getNumberOfYears();
  double getLoanAmount();
  void setAnnualInterestRate(double rate);
  void setNumberOfYears(int years);
  void setLoanAmount(double amount);
  double getMonthlyPayment();
  double getTotalPayment();

private:
  double annualInterestRate;
  int numberOfYears;
  double loanAmount;
};

#endif
```

## **LiveExample 9.14 TestLoanClass**
```cpp
#include <iostream>
#include <iomanip>
#include "Loan.h"
using namespace std;

int main()
{
  // Enter annual interest rate
  cout << "Enter yearly interest rate, for example 8.25: ";
  double annualInterestRate;
  cin >> annualInterestRate;

  // Enter number of years
  cout << "Enter number of years as an integer, for example 5: ";
  int numberOfYears;
  cin >> numberOfYears;

  // Enter loan amount
  cout << "Enter loan amount, for example 120000.95: ";
  double loanAmount;
  cin >> loanAmount;

  // Create Loan object
  Loan loan(annualInterestRate, numberOfYears, loanAmount);

  // Display results
  cout << fixed << setprecision(2); 
  cout << "The monthly payment is " 
    << loan.getMonthlyPayment() << endl;
  cout << "The total payment is " << loan.getTotalPayment() << endl;

  return 0;
}
```
```
command>cl TestLoanClass.cpp
Microsoft C++ Compiler 2019 
Compiled successful (cl is the VC++ compile/link command)

command>TestLoanClass 
Enter yearly interest rate, for example 8.25: 5.75
Enter number of years as an integer, for example 5: 15
Enter loan amount, for example 120000.95: 25000
The monthly payment is 207.60
The total payment is 37368.45

command>
```

The `main` function reads interest rate, payment period (in years), and loan amount (lines 8–21), creates a `Loan` object (line 24), and then obtains the monthly payment (line 29) and total payment (line 30) using the instance functions in the `Loan` class.

The `Loan` class can be implemented as in **​LiveExample ​​9.15​**.

## **LiveExample 9.15 Loan.cpp**
```cpp
#include "Loan.h"
#include <cmath>
using namespace std;

Loan::Loan()
{
  annualInterestRate = 9.5;
  numberOfYears = 30;
  loanAmount = 100000;
}

Loan::Loan(double rate, int years, double amount)
{
  annualInterestRate = rate;
  numberOfYears = years;
  loanAmount = amount;
}

double Loan::getAnnualInterestRate()
{
  return annualInterestRate;
}

int Loan::getNumberOfYears()
{
  return numberOfYears;
}

double Loan::getLoanAmount()
{
  return loanAmount;
}

void Loan::setAnnualInterestRate(double rate)
{
  annualInterestRate = rate;
}

void Loan::setNumberOfYears(int years)
{
  numberOfYears = years;
}

void Loan::setLoanAmount(double amount)
{
  loanAmount = amount;
}

double Loan::getMonthlyPayment()
{
  double monthlyInterestRate = annualInterestRate / 1200;
  return loanAmount * monthlyInterestRate / (1 -
    (pow(1 / (1 + monthlyInterestRate), numberOfYears * 12)));
}

double Loan::getTotalPayment()
{
  return getMonthlyPayment() * numberOfYears * 12;
}
```

From a class developer’s perspective, a class is designed for use by many different customers. In order to be useful in a wide range of applications, a class should provide a variety of ways for customization through constructors, properties, and functions.

The `Loan` class contains two constructors, three getter functions, three _setter functions_, and the functions for finding monthly payment and total payment. You can construct a `Loan` object by using the no-arg constructor or the one with three parameters: annual interest rate, number of years, and loan amount. The three getter functions, `getAnnualInterest`, `getNumberOfYears`, and `getLoanAmount`, return annual interest rate, payment years, and loan amount, respectively.

>[!Important Pedagogical Tip]
>The UML diagram for the `Loan` class is shown in **Figure 9.8**. Students should begin by writing a test program that uses the `Loan` class even though they don’t know how the `Loan` class is implemented. This has three benefits:
>- It demonstrates that developing a class and using a class are two separate tasks.
>- It enables you to skip the complex implementation of certain classes without interrupting the sequence of the book.
>- It is easier to learn how to implement a class if you are familiar with the class through using it.

For all the examples from now on, you may first create an object from the class and try to use its functions before turning your attention to its implementation.

## Self-Check
### What is the output of the following code? (Use the Loan class defined in LiveExample 9.13, Loan.h.)
```cpp
#include <iostream>
#include "Loan.h"
using namespace std;

class A
{
public:
  Loan loan;
  int i;  
};

int main()
{
  A a;
  cout << a.loan.getLoanAmount() << endl;
  cout << a.i << endl;

  return 0;
}
```

100000
? (? means an arbitrary value)

Explanation: Loan's no-arg constructor is used to initialize loan, but i is not initialized.
# References
