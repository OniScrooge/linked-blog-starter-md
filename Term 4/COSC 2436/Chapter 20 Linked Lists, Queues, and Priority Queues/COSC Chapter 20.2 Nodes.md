# Summary

# Learning Objectives

# Related
Prev - [[COSC Chapter 20.1 Introduction]]

Next - [[COSC Chapter 20.3 The LinkedList Class]]
# Content
## Key Point
In a linked list, each element is contained in a structure called the node. 

When a new element is added, a node is created to contain it. All the nodes are chained through pointers, as shown in **Figure 20.1**.

## Figure 20.1
![[Pasted image 20241130131907.png]]

Nodes can be defined using a class. The class definition for a node can be as follows:
![[Pasted image 20241130131957.png]]

`Node` is defined as a template class with a type parameter `T` for specifying the element type.

By convention, pointer variables named `head` and `tail` are used to point to the first and the last node in the list. If the list is empty, both `head` and `tail` should be `nullptr`. Recall that `nullptr` is a C++11 keyword that replaces `NULL`, which indicates that a pointer does not point to any node. Here is an example that creates a linked list to hold three nodes. Each node stores a string element.

Step 1: Declare `head` and `tail`:

|   |   |
|---|---|
|`Node<string>* head = **nullptr**;`|The list is empty now.|
|`Node<string>* tail = **nullptr**;`|head is nullptr and tail is nullptr|

`head` and `tail` are both `nullptr`. The list is empty.

Step 2: Create the first node and insert it to the list:

## Figure 20.2
![[Pasted image 20241130132053.png]]
![[Pasted image 20241130132106.png]]
![[Pasted image 20241130132115.png]]

After the first node is inserted in the list, `head` and `tail` point to this node, as shown in **Figure 20.2**.

Step 3: Create the second node and append it to the list:
## Figure 20.3
![[Pasted image 20241130132238.png]]
![[Pasted image 20241130132249.png]]
![[Pasted image 20241130132258.png]]

To append the second node to the list, link it with the first node, as shown in **Figure 20.3b**. The new node is now the tail node. So you should move tail to point to this new node, as shown in **Figure 20.3c**.

Step 4: Create the third node and append it to the list:
## Frigure 20.4
![[Pasted image 20241130132344.png]]
![[Pasted image 20241130132351.png]]
![[Pasted image 20241130132401.png]]

To append the new node to the list, link it with the last node, as shown in **Figure 20.4b**. The new node is now the tail node. So you should move tail to point to this new node, as shown in **Figure 20.4c**.

Each node contains the element and a pointer that points to the next element. If the node is the last in the list, its pointer data field `next` contains the value `nullptr`. You can use this property to detect the last node. For example, you may write the following loop to traverse all the nodes in the list.
![[Pasted image 20241130132456.png]]

The `current` pointer points to the first node in the list initially (line 1). In the loop, the element of the current node is retrieved (line 4), and then `current` points to the next node (line 5). The loop continues until the current node is `nullptr`.

## Self-Check
### Are the following class declarations correct?
#### (a)
```cpp
class A
{
public:
  A()
  {
  }

private:
  A* a;
  int i;
};
```
#### (b)
```cpp
class A
{
public:
  A()
  {
  }

private:
  A a;
  int i;
};
```

#### Answer
(a) is correct, but (b) is wrong. Why? Because class A is being defined and used to create an object at the same time. Write a test program to see what happens.

### What is nullptr for?

is a C++11 keyword that replaces NULL, which indicates that a pointer does not point to any node.

### When a node is created using the Node class, is the next pointer of this new node nullptr?

Yes. It is initialized in the constructor.

# References
