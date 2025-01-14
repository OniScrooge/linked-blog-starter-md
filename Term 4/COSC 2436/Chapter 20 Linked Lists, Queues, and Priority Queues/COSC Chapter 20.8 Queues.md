# Summary

# Related
Prev - [[COSC Chapter 20.7 Variations of Linked Lists]]

Next - [[COSC Chapter 20.9 Priority Queues]]
# Content
## Key Point

A queue is a first-in and first-out data structure. 

A [queue](https://revel-ise.pearson.com/courses/66e7050d84448f59a62c6945/assignments/483c3e14-d1b1-47f5-be50-abb738020075/pages/urn:pearson:entity:9d874a2c-a980-4799-a25e-62f69ef04f63?source=dashboard#) represents a waiting list. It can be viewed as a special type of list whose elements are inserted into the end (tail) and are accessed and deleted from the beginning (head), as shown in **Figure 20.15**.

A queue holds objects in a first-in, first-out fashion.

There are two ways to design the queue class:

Using composition: You can declare a linked list as a data field in the queue class, as shown in **Figure 20.16a**.

Using inheritance: You can define a queue class by extending the linked list class, as shown in **Figure 20.16b**.

## Figure 20.16

![[Pasted image 20241130142538.png]]

**Queue** may be implemented using composition or inheritance.

Both designs are fine, but using composition is better, because it enables you to define a completely new queue class without inheriting the unnecessary and inappropriate functions from the linked list. **Figure 20.17** shows the UML class diagram for the queue. Its implementation is given in **LiveExample 20.6**.

## Figure 20.17
![[Pasted image 20241130142553.png]]
`Queue` uses a linked list to provide a first-in, first-out data structure.

#### **LiveExample 20.6 Queue.h**
```cpp
#ifndef QUEUE_H
#define QUEUE_H
#include "LinkedList.h"
#include <stdexcept>
using namespace std;
  
template<typename T>
class Queue
{
public:
  Queue();
  void enqueue(const T& element);
  T dequeue();
  int getSize() const;
  
private:
  LinkedList<T> list;
};
  
template<typename T>
Queue<T>::Queue()
{
}
  
template<typename T>
void Queue<T>::enqueue(const T& element)
{
  list.addLast(element);
}
  
template<typename T>
T Queue<T>::dequeue()
{
  return list.removeFirst();
}
  
template<typename T>
int Queue<T>::getSize() const
{
  return list.getSize();
}
  
#endif
```

A linked list is created to store the elements in a queue (line 17). The `enqueue(T element)` function (lines 25–29) adds elements into the tail of the queue. The `dequeue()` function (lines 31–35) removes an element from the head of the queue and returns the removed element. The `getSize()` function (lines 37–41) returns the number of elements in the queue.

**LiveExample 20.7** gives an example that creates a queue for `int` values (line 17) and a queue for strings (line 24) using the `Queue` class. It uses the [enqueue](https://revel-ise.pearson.com/courses/66e7050d84448f59a62c6945/assignments/483c3e14-d1b1-47f5-be50-abb738020075/pages/urn:pearson:entity:9d874a2c-a980-4799-a25e-62f69ef04f63?source=dashboard#) function to add elements to the queues (lines 19, 25–27) and the [dequeue](https://revel-ise.pearson.com/courses/66e7050d84448f59a62c6945/assignments/483c3e14-d1b1-47f5-be50-abb738020075/pages/urn:pearson:entity:9d874a2c-a980-4799-a25e-62f69ef04f63?source=dashboard#) function to remove int values and strings from the queue.

## **LiveExample 20.7 TestQueue.cpp**
```cpp
#include <iostream>
#include "Queue.h"
#include <string>
using namespace std;

template<typename T>
void printQueue(Queue<T>& queue)
{
  while (queue.getSize() > 0)
    cout << queue.dequeue() << " ";
  cout << endl;
}

int main()
{
  // Queue of int values
  Queue<int> intQueue;
  for (int i = 0; i < 10; i++)
    intQueue.enqueue(i); // Add i to the queue

  printQueue(intQueue);

  // Queue of strings
  Queue<string> stringQueue;
  stringQueue.enqueue("New York");
  stringQueue.enqueue("Boston");
  stringQueue.enqueue("Denver");

  printQueue(stringQueue);

  return 0;
}
```
```
command>cl TestQueue.cpp
Microsoft C++ Compiler 2019 
Compiled successful (cl is the VC++ compile/link command)

command>TestQueue 
0 1 2 3 4 5 6 7 8 9 
New York Boston Denver 

command>
```

## Self-Check
### You can use inheritance or composition to design the data structures for queues. Discuss the pros and cons of these two approaches.

See the text.

### Show the output of the following code:
```cpp
#include <iostream>
#include <string>
#include "ImprovedStack.h" // Defined in LiveExample 12.7
#include "Queue.h"
using namespace std;

int main()
{
  Stack<string> stack;
  Queue<int> queue;

  stack.push("Georgia");
  stack.push("Indiana");
  stack.push("Oklahoma");

  cout << stack.pop() << endl;
  cout << "Stack's size is " << stack.getSize() << endl;

  queue.enqueue(1);
  queue.enqueue(2);
  queue.enqueue(3);

  cout << queue.dequeue() << endl;
  cout << "Queue's size is " << queue.getSize() << endl;

  return 0;
} 
```

The output is:

Oklahoma 
Stack's size is 2 
1
Queue's size is 2
# References