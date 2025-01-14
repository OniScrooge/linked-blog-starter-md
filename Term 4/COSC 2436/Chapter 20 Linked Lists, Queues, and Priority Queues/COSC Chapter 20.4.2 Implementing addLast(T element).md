# Summary

# Related
Prev - [[COSC Chapter 20.4.1 Implementing addFirst(T element)]]

Next - [[COSC Chapter 20.4.3 Implementing add(int index, T element)]]
# Content
The `addLast(T element)` function creates a node to hold an element and appends the node at the end of the list. It can be implemented as follows:
```cpp
template<typename T>
void LinkedList<T>::addLast(T element)
{
	if (tail == nullptr)
	{
		head = tail = newNode<T>(element);
	}
	else
	{
		tail->next = new Node<T>(element);
		tail = tail-next;
	}
	size++;
}
```

Consider two cases:
1. if the list is empty (line 4), both `head` and `tail` will point to this new node (line 6);
2. otherwise, insert the node at the end of the list (line 10). After the insertion, `tail` should refer to this new element node (line 11), as shown in **Figure 20.8**. In any case, after the node is created, the size should be increased by `1` (line 14).

## Figure 20.8
![[Pasted image 20241130134557.png]]
![[Pasted image 20241130134609.png]]
![[Pasted image 20241130134617.png]]
![[Pasted image 20241130134627.png]]
`addLast` function takes $O(1)$ time

## Self-Check
### When a new node is appended to the end of a linked list, will the head pointer and the tail pointer be changed?
The head pointer will be changed if the list is empty before the insertion. The tail pointer will always be changed.
# References