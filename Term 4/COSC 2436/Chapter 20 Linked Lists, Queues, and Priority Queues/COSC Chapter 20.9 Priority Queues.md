# Summary

# Related
Prev - [[COSC Chapter 20.8 Queues]]

Next - [[COSC Chapter Summary 20]]
# Content
## Key Point

Elements in a priority queue are assigned with a priority. The element with the highest priority is removed first from a priority queue. 

A regular queue is a first-in, first-out data structure. Elements are appended to the end of the queue and are removed from the beginning. In a priority queue, elements are assigned with priorities. The element with the highest priority is accessed or removed first. For example, the emergency room in a hospital assigns patients with priority numbers; the patient with the highest priority is treated first.

A [priority queue](https://revel-ise.pearson.com/courses/66e7050d84448f59a62c6945/assignments/483c3e14-d1b1-47f5-be50-abb738020075/pages/urn:pearson:entity:efe8f7ef-a400-4230-9a02-30fbbd425092?source=dashboard#) can be implemented using a heap, where the root is the element with the highest priority in the queue. Heap was introduced in **Section 19.6**, “Heap Sort.” The class diagram for the priority queue is shown in **Figure 20.18**. Its implementation is given in **LiveExample 20.8**.

## Figure 20.18
![[Pasted image 20241130142919.png]]

**PriorityQueue** uses a heap to provide a largest-in, first-out data structure.

#### **LiveExample 20.8 PriorityQueue.h**
```cpp
#ifndef PRIORITYQUEUE_H
#define PRIORITYQUEUE_H
#include "Heap.h"

template<typename T>
class PriorityQueue
{
public:
  PriorityQueue();
  void enqueue(const T& element);
  T dequeue();
  int getSize() const;

private:
  Heap<T> heap;
};

template<typename T>
PriorityQueue<T>::PriorityQueue()
{
}

template<typename T>
void PriorityQueue<T>::enqueue(const T& element)
{
  heap.add(element);
}

template<typename T>
T PriorityQueue<T>::dequeue()
{
  return heap.remove();
}

template<typename T>
int PriorityQueue<T>::getSize() const
{
  return heap.getSize();
}

#endif
```

**LiveExample 20.9** gives an example of using a priority queue for patients. The `Patient` class is defined in lines 6–38. Line 43 creates a priority queue. Four patients with associated priority values are created and enqueued in lines 44–47. Line 51 dequeues a patient from the queue.

#### **LiveExample 20.9 TestPriorityQueue.cpp**
```cpp
#include <iostream>
#include "PriorityQueue.h"
#include <string>
using namespace std;

class Patient
{
public:
  Patient(const string& name, int priority)
  {
    this->name = name;
    this->priority = priority;
  }

  bool operator<(const Patient& secondPatient)
  {
    return (this->priority < secondPatient.priority);
  }

  bool operator>(const Patient& secondPatient)
  {
    return (this->priority > secondPatient.priority);
  }

  string getName() const
  {
    return name;
  }

  int getPriority() const
  {
    return priority;
  }

private:
  string name;
  int priority;
};

int main()
{
  // Queue of patients
  PriorityQueue<Patient> patientQueue;
  patientQueue.enqueue(Patient("John", 2));
  patientQueue.enqueue(Patient("Jim", 1));
  patientQueue.enqueue(Patient("Tim", 5));
  patientQueue.enqueue(Patient("Cindy", 7));

  while (patientQueue.getSize() > 0)
  {
    Patient element = patientQueue.dequeue(); // Get a patient from the queue
    cout << element.getName() << " (priority: " <<
      element.getPriority() << ") ";
  }

  return 0;
}
```
```
command>cl TestPriorityQueue.cpp
Microsoft C++ Compiler 2019 
Compiled successful (cl is the VC++ compile/link command)

command>TestPriorityQueue 
Cindy (priority: 7) Tim (priority: 5) John (priority: 2) Jim (priority: 1) 

command>
```
The `<` and `>` operators are defined the `Patient` class, so two patients can be compared. You can use any class type for the elements in the heap, provided that the elements can be compared using the `<` and `>` operators.

## Self-Check
### What is a priority queue? How is a priority queue implemented?
In a priority queue, elements are assigned with priorities. When accessing elements, the element with the highest priority is removed first. A priority queue has a largest-in, first-out behavior.

# References
