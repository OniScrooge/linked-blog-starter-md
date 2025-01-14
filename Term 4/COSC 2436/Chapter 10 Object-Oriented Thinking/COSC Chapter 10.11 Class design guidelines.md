# Summary

# Learning Objectives

# Related
Prev - [[COSC Chapter 10.10 Constructor initializer lists]]

Next - [[COSC Chapter Summary 10]]
# Content
# Key Point

Class design guidelines are helpful for designing sound classes.

This chapter is concerned mainly with object-oriented design. While there are many object-oriented methodologies, UML has become the industry-standard notation for object-oriented modeling, and itself leads to a methodology. The process of designing classes calls for identifying the classes and discovering the relationships among them.

You have learned how to design classes from the examples in this chapter and from many other examples in the preceding chapters. Here are some guidelines.

## 10.11.1 Cohesion

A class should describe a single entity, and all the class operations should logically fit together to support a coherent purpose. You can use a class for students, for example, but you should not combine students and staff in the same class, because students and staff are different entities.

A single entity with too many responsibilities can be broken into several classes to separate responsibilities.

## 10.11.2 Consistency

Follow standard programming style and naming conventions. Choose informative names for classes, data fields, and functions. A popular style in C++ is to place the data declaration after the functions, and place constructors before functions.

Choose names consistently. It is a good practice to choose the same names for similar operations using function overloading.

In general, you should consistently provide a public no-arg constructor for constructing a default instance. If a class does not support a no-arg constructor, document the reason. If no constructors are defined explicitly, a public default no-arg constructor with an empty body is assumed.

## 10.11.3 Encapsulation

A class should use the `private` modifier to hide its data from direct access by clients. This makes the class easy to maintain.

Provide a `getter` function only if you want the field to be readable, and provide a `setter` function only if you want the field to be updateable. A class should also hide functions not intended for client use. Such functions should be defined as private.

## 10.11.4 Clarity

Cohesion, consistency, and encapsulation are good guidelines for achieving design clarity. Additionally, a class should have a clear contract that is easy to explain and easy to understand.

Users can incorporate classes in many different combinations, orders, and environments. Therefore, you should design a class that imposes no restrictions on what the user can do with it or when, design the properties in a way that lets the user set them in any order and with any combination of values, and design functions independently of their order of occurrence. For example, the `Loan` class in **LiveExample 9.13** contains the functions `setLoanAmount`, `setNumberOfYears`, and `setAnnualInterestRate`. The values of these properties can be set in any order.

You should not declare a data field that can be derived from other data fields. For example, the following `Person` class has two data fields: `birthDate` and `age`. Since `age` can be derived from `birthDate`, `age` should not be declared as a data field.

```cpp
class Person 
{ 
public: 
  ... 
 
private: 
  Date birthDate; 
  int age; 
} 
```

## 10.11.5 Completeness

Classes are designed for use by many different customers. In order to be useful in a wide range of applications, a class should provide a variety of ways for customization through properties and functions. For example, the `string` class contains more than 20 functions that are useful for a variety of applications.

## 10.10.6 Instance vs. Static

A variable or function that is dependent on a specific instance of the class should be an instance variable or function. A variable that is shared by all the instances of a class should be declared static. For example, the variable `numberOfObjects` in `Circle` in **LiveExample 10.9** is shared by all the objects of the `Circle` class and therefore is declared static. A function that is not dependent on a specific instance should be defined as a static function. For instance, the `getNumberOfObjects` function in `Circle` is not tied to any specific instance, and therefore is defined as a static function.

Always reference static variables and functions from a class name (rather than an object) to improve readability and avoid errors.

A constructor is always instance, because it is used to create a specific instance. A static variable or function can be invoked from an instance function, but an instance variable or function cannot be invoked from a static function.

# References
