# Summary

# Learning Objectives

# Related
Prev - [[COSC Chapter 10.7 Thinking in objects]]

Next - [[COSC Chapter 10.9 Case Study - The StackOfIntegers Class]]
# Content
# Key Point

To design classes, you need to explore the relationships among classes. The common relationships among classes are _association_, _aggregation_, _composition_, and _inheritance_. 

This section explores association, aggregation, and composition. The inheritance relationship will be intr​oduced in **Chapter 15**, Inheritance and Polymorphism.​

## 10.8.1 Association

**Association** is a general binary relationship that describes an activity between two classes. For example, a student taking a course is an association between the `Student`​ ​class and the `Course`​ ​class, and a faculty member teaching a course is an association between the `Faculty`​ ​class and the `Course`​ ​class. These associations can be represented in UML graphical notation, as shown in **Figure 10.12**.

## Figure 10.12
![[Pasted image 20241207155334.png]]

This UML diagram shows that a student may take any number of courses, a faculty member may teach at most three courses, a course may have from five to sixty students, and a course is taught by only one faculty member.

An association is illustrated by a solid line between two classes with an optional label that describes the relationship. In **Figure 10.12**, the labels are _Take_ and _Teach_. Each relationship may have an optional small black triangle that indicates the direction of the relationship. In this figure, the direction indicates that a student takes a course (as opposed to a course taking a student).

Each class involved in the relationship may have a role name that describes the role it plays in the relationship. In **Figure 10.12**, _teacher_ is the role name for `Faculty.`

Each class involved in an association may specify a [[multiplicity]], which is placed at the side of the class to specify how many of the class’s objects are involved in the relationship in UML. A multiplicity could be a number or an interval that specifies how many of the class’s objects are involved in the relationship. The character `*` means an unlimited number of objects, and the interval `m..n` indicates that the number of objects is between `m` and `n`, inclusively. In **Figure 10.12**, each student may take any number of courses, and each course must have at least five and at most sixty students. Each course is taught by only one faculty member, and a faculty member may teach from zero to three courses per semester.

In C++ code, you can implement associations by using data fields and functions. For example, the relationships in **Figure 10.12** may be implemented using the classes in **Figure 10.13**. The relation “a student takes a course” is implemented using the `addCourse` function in the `Student` class and the `addStuent` function in the `Course` class. The relation “a faculty teaches a course” is implemented using the `addCourse` function in the `Faculty` class and the `setFaculty` function in the `Course` class. The `Student`​ ​class may use a list to store the courses that the student is taking, the `Faculty`​ ​class may use a list to store the courses that the faculty is teaching, and the `Course`​ ​class may use a list to store students enrolled in the course and a data field to store the instructor who teaches the course.

## Figure 10.13
![[Pasted image 20241207155410.png]]
![[Pasted image 20241207155417.png]]
![[Pasted image 20241207155425.png]]

The association relations are implemented using data fields and functions in classes.

>[!Note]
There are many possible ways to implement relationships. For example, the student and faculty information in the `Course` class can be omitted, since they are already in the `Student` and `Faculty` class. Likewise, if you don’t need to know the courses a student takes or a faculty member teaches, the data field `courseList` and the `addCourse` function in `Student` or `Faculty` can be omitted.

## 10.8.2 Aggregation and Composition

[[aggregation]] is a special form of association that represents an ownership relationship between two objects. Aggregation models [[has-a relationships]]. The owner object is called an aggregating object, and its class is called an aggregating class. The subject object is called an _aggregated object_, and its class is called an _aggregated class_.

We refer aggregation between two objects as [[composition]] if the existence of the aggregated object is dependent on the aggregating object. In other words, if a relationship is composition, the aggregated object cannot exist on its own. For example, “a student has a name” is a composition relationship between the `Student` class and the `Name` class because `Name` is dependent on `Student`, whereas “a student has an address” is an aggregation relationship between the `Student` class and the `Address` class because an address can exist by itself. Composition implies exclusive ownership. One object owns another object. When the owner object is destroyed, the dependent object is destroyed as well. In UML, a filled diamond is attached to an aggregating class (in this case, `Student`) to denote the composition relationship with an aggregated class (`Name`), and an empty diamond is attached to an aggregating class (`Student`) to denote the aggregation relationship with an aggregated class (`Address`), as shown in **Figure 10.14**.

## Figure 10.14
![[Pasted image 20241207155526.png]]
In **Figure 10.14**, each student has only one address and each address can be shared by up to 3 students. Each student has one name, and a name is unique for each student.

An aggregation relationship is usually represented as a data field in the aggregating class. For example, the relationships in **Figure 10.14** may be implemented using the classes in **Figure 10.15**. The relation “a student has a name” and “a student has an address” are implemented in the data field `name` and `address` in the `Student` class.

## Figure 10.15
![[Pasted image 20241207155538.png]]
![[Pasted image 20241207155545.png]]
![[Pasted image 20241207155552.png]]

The composition relations are implemented using data fields in classes.

Aggregation may exist between objects of the same class. For example, a person may have a supervisor. This is illustrated in **Figure 10.16**.

## Figure 10.16
![[Pasted image 20241207155846.png]]

A person may have a supervisor.

In the relationship “a person has a supervisor,” as shown in **Figure 10.16**, a supervisor can be represented as a data field in the `Person`​ ​class, as follows:

```cpp
class Person 
{ 
private: 
  Person supervisor;  // The type for the data is the class itself 
  ... 
} 
```

If a person may have several supervisors, as shown in **Figure 10.17**, you may use an array to store supervisors (for example, `10` supervisors).

## Figure 10.17
![[Pasted image 20241207155908.png]]

A person may have several supervisors.

>[!Note]
Since aggregation and composition relationships are represented using classes in similar ways, we will not differentiate them and call both compositions for simplicity.

## Self-Check
### What are common relationships among classes? Describe the UML graphical notation for modeling the relationships among classes.
The common relationships among classes are association, aggregation, composition, and inheritance. See the text for the UML notations for class modeling.
### What is association? What is aggregation? What is composition?
Association is a general binary relationship that describes an activity between two classes. Aggregation is a special form of association that represents an ownership relationship between two objects. Aggregation models has-a relationships. An object can be owned by several other aggregating objects. If an object is exclusively owned by an aggregating object, the relationship between the object and its aggregating object is referred to as a composition.
### What is UML notation of aggregation and composition?
Aggregation: empty diamond on the aggregating class. Composition: Solid diamond on the aggregating class.
### Why both aggregation and composition are together referred to as composition?
Since aggregation and composition relationships are represented using classes in the same way, we will not differentiate them and call both compositions for simplicity.
# References
