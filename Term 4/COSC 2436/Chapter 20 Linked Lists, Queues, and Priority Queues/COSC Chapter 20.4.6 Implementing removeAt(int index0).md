# Summary

# Related
Prev - [[COSC Chapter 20.4.5 Implementing removeLast()]]

Next - [[COSC Chapter 20.4.7 The source code for LinkedList]]
# Content
The `removeAt(int index)` function finds the node at the specified index and then removes it. It can be implemented as follows:
```cpp
  1  template<typename T>
  2  T LinkedList<T>::removeAt(int index)
  3  {
  4    if (index < 0 || index >= size)
  5      throw runtime_error("Index out of range");
  6    else if (index == 0)
  7      return removeFirst();
  8    else if (index == size - 1)
  9      return removeAt(index);
 10    else
 11    {
 12      Node<T>* previous = head;
 13      for (int i = 1; i < index; i++)
 14      {
 15        previous = previous->next;
 16      }
 17  
 18      Node<T>* current = previous->next;
 19      previous->next = current->next;
 20      size--;
 21      T element = current->element;
 22      delete current;
 23      return element;
 24    }
 25  }
```

Consider four cases:
1. If `index` is beyond the range of the list (i.e., `index < 0 || index >= size`), throw an exception (line 5);
2. If `index` is `0`, invoke `removeFirst()` to remove the first node (line 7);
3. If `index` is `size - 1`, invoke `removeLast()` to remove the last node (line 9);
4. Otherwise, locate the node at the specified `index`. Let `current` denote this node and `previous` denote the node before it, as shown in **Figure 20.12a**. Assign `current->nex`t to `previous->next` to eliminate the current node (line 19), as shown in **Figure 20.12b**.

## Figure 20.12
![[Pasted image 20241130140056.png]]
![[Pasted image 20241130140106.png]]
![[Pasted image 20241130140114.png]]
`removeAt(index)` takes $O(n)$ time

## Self-Check
### Under what circumstances would the functions `removeFirst`, `removeLast`, and `removeAt` throw an exception?
If the list is empty, all three functions will throw exceptions. If the index is out of range, `removeAt(index)` will throw an exception.
# References
