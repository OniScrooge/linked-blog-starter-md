# Summary

# Related
Prev - [[COSC Chapter 20.9 Priority Queues]]

Next - 
# Content
## Key Terms
1. **circular doubly linked list**
2. **circular singly linked list**
3. **dequeue**
4. **doubly linked list**
5. **enqueue**
6. **linked list**
7. **priority queue**
8. **queue**
9. **singly linked list**
## Chapter Summary
1. A linked list grows and shrinks dynamically. Nodes in a linked list are dynamically created using the `new` operator, and they are destroyed using the `delete` operator.
2. A queue represents a waiting list. It can be viewed as a special type of list whose elements are inserted into the end (tail) and are accessed and deleted from the beginning (head).
3. If you don’t know the number of elements in advance, it is more efficient to use a linked list, which can grow and shrink dynamically.
4. If your application requires frequent insertion and deletion anywhere, it is more efficient to store elements using a linked list, because inserting an element into an array would require moving all the elements in the array after the insertion point.
5. If the elements need to be processed in a first-in, first-out fashion, use a queue to store the elements. A priority queue can be implemented using a heap, where the root is the element with the highest priority in the queue.
# References