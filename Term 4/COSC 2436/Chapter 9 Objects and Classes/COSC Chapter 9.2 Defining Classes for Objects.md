# Summary

# Learning Objectives

# Related
Prev - [[COSC Chapter 9.1 Introduction]]

Next - [[COSC Chapter 9.3 Example - Defining Classes and Creating Objects]]
# Content
## Key Point
A [[class]] defines the [[properties]] and behaviors for objects.

[[object-oriented programming]] involves programming using objects. An [[object]] represents an entity in the real world that can be distinctly identified. For example, a student, a desk, a circle, a button, and even a loan can all be viewed as objects. An [[object]] has a unique identity, [[state]], and behavior.

- The [[state]] of an [[object]] (also known as [[properties]] or _attributes_) is ​represented by [[data fields]] with their current values. A circle [[object]], for example, has a data field, `radius`, which is the property that characterizes a circle. A rectangle [[object]], for example, has [[data fields]], `width` and `height`, which are the [[properties]] that characterize a rectangle.
- The _behavior_ of an [[object]] (also known as its _actions_) is defined by functions. To invoke a [[function]] on an [[object]] is to ask the [[object]] to perform an action. For example, you may define functions named `getArea()` and `getPerimeter()` for circle objects. A circle [[object]] may invoke `getArea()` to return its area and `getPerimeter()` to return its perimeter. You may also define the `setRadius(radius)` [[function]]. A circle [[object]] can invoke this [[function]] to change its radius.

Objects of the same type are defined using a common [[class]]. A [[class]] is a template, blueprint, or [[contract]] that defines what an [[object]]’s [[data fields]] and functions will be. An [[object]] is an [[instance]] of a [[class]]. You can create many instances of a [[class]]. Creating an [[instance]] is referred to as [[instantiation]]. The terms _[[object]]_ and [[instance]] are often interchangeable. The relationship between classes and objects is analogous to the relationship between apple pie recipes and apple pies. You can make as many apple pies as you want from a single recipe. **Figure 9.1** shows a [[class]] named `Circle` and its three objects.

## Figure 9.1
![[Pasted image 20241207113634.png]]

A C++ _[[class]]_ uses variables to define _[[data fields]]_ and _functions_ to define behaviors. Additionally, a [[class]] provides functions of a special type, known as [constructors](https://revel-ise.pearson.com/courses/66e7050d84448f59a62c6945/pages/urn:pearson:entity:89cd4ac4-09f5-48b0-91cc-25f6f7b2c6df?source=dashboard#), which are invoked when a new [[object]] is created. A constructor is a special kind of [[function]]. Constructors can perform any action, but they are designed to perform initializing actions, such as initializing the [[data fields]] of objects. **Figure 9.2** shows an example of the [[class]] for `Circle` objects.

## Figure 9.2
![[Pasted image 20241207113703.png]]

A [[class]] is a blueprint that defines objects of the same type.

## Figure 9.3
![[Pasted image 20241207113744.png]]

The illustration of [[class]] and objects in **Figure 9.1** can be standardized using UML (Unified Modeling Language) notation, as shown in **Figure 9.3**. This is called a [[UML class diagram]], or simply _[[class]] diagram_. The data field is denoted as
```cpp
dataFieldName: dataFieldType 
```

The constructor is denoted as
```cpp
ClassName(parameterName: parameterType) 
 
```

​​​The [[function]] is denoted as​
```cpp
functionName(parameterName: parameterType): returnType 
 
```

# References
