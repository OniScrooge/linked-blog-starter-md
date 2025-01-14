# Summary

# Related
Prev - [[COSC Chapter 20.4.2 Implementing addLast(T element)]]

Next - [[COSC Chapter 20.4.4 Implementing removeFirst()]]
# Content
The `add(int index, T element)` function adds an element to the list at the specified index. It can be implemented as follows:
```cpp
  1 template<typename T>
  2  void LinkedList<T>::add(int index, T element)
  3  {
  4    if (index == 0)
  5      addFirst(element);
  6    else if (index >= size)
  7      addLast(element);
  8    else
  9    {
 10      Node<T>* current = head;
 11      for (int i = 1; i < index; i++)
 12        current = current->next;
 13      Node<T>* temp = current->next;
 14      current->next = new Node<T>(element);
 15      (current->next)->next = temp;
 16      size++;
 17    }
 18  }
```

Consider three cases:
1. If `index` is `0`, invoke `addFirst(element)` (line 5) to insert the element at the beginning of the list;
2. If `index` is greater than or equal to `size`, invoke `addLast(element)` (line 7) to insert the element at the end of the list;
3. Otherwise, create a new node to store the new element and locate where to insert it. As shown in **Figure 20.9b**, the new node is to be inserted between the nodes `current` and `temp`. The function assigns the new node to `current``-``>``next` and assigns `temp` to the new node’s `next`, as shown in **Figure 20.9c**. The size is now increased `b`y 1 (line 16).

## Figure 20.9
![[Pasted image 20241130134951.png]]
![[Pasted image 20241130135001.png]]
![[Pasted image 20241130135008.png]]
![[Pasted image 20241130135022.png]]
`add(index, element)` takes $O(n)$ time

## Self-Check
### How does the add(index, element) function handle the case for index 0 and index >= size?
When index is 1, it is the same as addFirst(element). Since addFirst(element) is already implemented, the function invokes addFirst(element). When index >= size, it is the same as addlast(element). Since addLast(element) is already implemented, the function invokes addLast(element).
# References
