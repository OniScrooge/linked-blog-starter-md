# Summary

# Related
Prev - [[COSC Chapter 20.4.4 Implementing removeFirst()]]

Next - [[COSC Chapter 20.4.6 Implementing removeAt(int index0)]]
# Content
The `removeLast()` function can be implemented as follows:
```cpp
  1  template<typename T>
  2  T LinkedList<T>::removeLast()
  3  {
  4    if (size == 0 || size == 1)
  5      return removeFirst(); // Same as removeFirst() in this case
  6    else
  7    {
  8      Node<T>* current = head;
  9      for (int i = 0; i < size - 2; i++)
 10        current = current->next;
 11  
 12      Node<T>* temp = tail;
 13      tail = current;
 14      tail->next = nullptr;
 15      size--;
 16      T element = temp->element;
 17      delete temp;
 18      return element;
 19    }
 20  }
```

Consider three cases:
1. If the list is empty or has a single element, invoking `removeFirst()` will take case of this case (lines 4-5);
2. Otherwise, locate `current` to point to the second-to-last node (lines 8-10), as shown in **Figure 20.11a**. Set `tail` to `current` (line 13).  `tail` now is repositioned to point to the second-to-last node, as shown in **Figure 20.11b**. The size is reduced by `1` after the deletion (line 15) and the last node is deleted, as shown in **Figure 20.11c**. The element value of the deleted node is returned (line 18).

## Figure 20.11
![[Pasted image 20241130135724.png]]
![[Pasted image 20241130135731.png]]
![[Pasted image 20241130135739.png]]
![[Pasted image 20241130135751.png]]

Since the algorithm needs to find the pointer before `tail`, it takes O(n) time to locate it. The `removeLast()` function takes O(n) time. The linked list used here is called a singly linked list, where nodes are traversed in one direction forward. In **Programming Exercise 20.8**, you can achieve O(1) time for the `removeLast()` function using a doubly linked list.

## Self-Check
### How does the `removeLast()` function handle the case for index 0 or 1?
When index is 0 or 1, `removeLast()` is the same as `removeFirst()`. Since `removeFirst()` is already implemented, the function invokes `removeFirst()`.
# References
