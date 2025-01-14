# Summary

# Related
Prev - [[COSC Chapter 20.4.3 Implementing add(int index, T element)]]

Next - [[COSC Chapter 20.4.5 Implementing removeLast()]]
# Content
The `removeFirst()` function can be implemented as follows:
```CPP
  1  template<typename T>
  2  T LinkedList<T>::removeFirst() throw (runtime_error)
  3  {
  4    if (size == 0)
  5      throw runtime_error("No elements in the list");
  6    else
  7    {
  8      Node<T>* temp = head;
  9      head = head->next;
 10      if (head == nullptr) tail = nullptr;
 11      size--;
 12      T element = temp->element;
 13      delete temp;
 14      return element;
 15    }
 16  }
```

Consider three cases:
1. If the list is empty, an exception is thrown (line 5);
2. Otherwise, remove the first node from the list by pointing `head` to the second node (line 9), as shown in **Figure 20.10**. 
3. If the list has just one node, then after removing it, `tail` should be set to `nullptr` (line 10).
4.  The size is reduced by 1 after the deletion (line 11).

## Figure 20.10
![[Pasted image 20241130135336.png]]
![[Pasted image 20241130135345.png]]
`removeFirst()` takes $O(1)$ time

## Self-Check
### When a node is removed from a linked list, what will happen if you don't explicitly use the delete operator to release the node?

This would cause memory leak.
# Related
