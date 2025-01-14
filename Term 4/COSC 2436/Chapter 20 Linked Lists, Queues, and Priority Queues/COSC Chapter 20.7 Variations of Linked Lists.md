
# Summary

# Related
Prev - [[COSC Chapter 20.6 Foreach Loop]]

Next - [[COSC Chapter 20.8 Queues]]
# Content

## Key Point

Various types of linked lists can be used to organize data for certain applications. 

The linked list introduced in the preceding sections is known as a [singly linked list](https://revel-ise.pearson.com/courses/66e7050d84448f59a62c6945/assignments/483c3e14-d1b1-47f5-be50-abb738020075/pages/urn:pearson:entity:88a760db-4eba-4ceb-aa0b-e137516919af?source=dashboard#). It contains a pointer to the list’s first node, and each node contains a pointer to the next node sequentially. Several variations of the linked list are useful in certain applications.

A [circular, singly linked list](https://revel-ise.pearson.com/courses/66e7050d84448f59a62c6945/assignments/483c3e14-d1b1-47f5-be50-abb738020075/pages/urn:pearson:entity:88a760db-4eba-4ceb-aa0b-e137516919af?source=dashboard#) differs in that the pointer of the last node points back to the first node, as shown in **Figure 20.14a**. Note that `tail` is not needed for circular linked lists. A good application of a circular linked list is in the operating system that serves multiple users in a timesharing fashion. The system picks a user from a circular list and grants a small amount of CPU time to the user and then moves on to the next user in the list.

A [doubly linked list](https://revel-ise.pearson.com/courses/66e7050d84448f59a62c6945/assignments/483c3e14-d1b1-47f5-be50-abb738020075/pages/urn:pearson:entity:88a760db-4eba-4ceb-aa0b-e137516919af?source=dashboard#) contains the nodes with two pointers. One points to the next node and the other to the previous node, as shown in **Figure 20.14b**. These two pointers are conveniently called _a forward pointer_ and _a backward pointer_. So, a doubly linked list can be traversed forward and backward.

A [circular, doubly linked list](https://revel-ise.pearson.com/courses/66e7050d84448f59a62c6945/assignments/483c3e14-d1b1-47f5-be50-abb738020075/pages/urn:pearson:entity:88a760db-4eba-4ceb-aa0b-e137516919af?source=dashboard#) has the property that the forward pointer of the last node points to the first node and the backward pointer of the first pointer points to the last node, as shown in **Figure 20.14c**.

## Figure 20.14
![[Pasted image 20241130142345.png]]

**LinkedList** may appear in various forms.

The implementation of these linked lists is left to the exercises.

### Note

In a singly linked list, `removeLast()` takes O(n) time. In a doubly linked list, `removeLast()` can be implemented to take O(1) time. See **CheckPoint 20.7.2**.

## Self-Check
### What is a circular, singly linked list? What is a doubly linked list? What is a circular, doubly linked list?

See the text.

### Implement the removeLast() function in a doubly linked list in O(1) time.

Note that in a singly linked list, to find the second-to-last node, you have loop all the way from head to the second-to-last node, which takes O(n) time. Here is the copy of the code from the text:
#### Answer
```cpp
 1  template<typename T>
 2  T LinkedList<T>::removeLast() throw (runtime_error)
 3  {
 4    if (size == 0 || size == 1) 
 5      return removeFirst();
 6    else
 7    {
 8      Node<T>* current = head;
 9  
10      for (int i = 0; i < size - 2; i++)
11        current = current->next;
12  
13      Node<T>* temp = tail;
14      tail = current;
15      tail->next = NULLnullptr;
16      size--;
17      T element = temp->element;
18      delete temp;
19      return element;
20    }
21  }
```

In a doubly linked list, the second-to-last node can be found in O(1) time using tail->previous. Here is the complete code:

 ```cpp
1  template<typename T>
 2  T LinkedList<T>::removeLast() throw (runtime_error)
 3  {
 4    if (size == 0 || size == 1) 
 5      return removeFirst();
 6    else
 7    {
 8      Node<E> temp = tail; 
 9      tail = tail->previous;
10      tail->next = null;
11      size--;
12      return temp->element; 
13    }
14  }
```

# References
