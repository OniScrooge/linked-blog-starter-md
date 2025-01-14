# Summary

# Related
Prev - [[COSC Chapter 20.3 The LinkedList Class]]

Next - [[COSC Chapter 20.4.2 Implementing addLast(T element)]]
# Content
The `addFirst(T element)` function can be implemented as follows:
```cpp
template<typename T>
void LinkedList<T>::addFirst(T element)
{
	Node<T>* newNode = new Node<T>(element);
	newNode->next = head;
	head = newNode;
	size++;
	
	if (tail ==nullptr)
		tail = head;
}
```

The `addFirst(T element)` function creates a new node (line 4) to store the element and insert the node to the beginning of the list (line 5), as shown in **Figure 20.7b**. After the insertion, `head` should point to this new element node (line 6), as shown in **Figure 20.7c**.

## Figure 20.7
![[Pasted image 20241130134007.png]]
![[Pasted image 20241130134024.png]]
![[Pasted image 20241130134038.png]]
![[Pasted image 20241130134046.png]]

If the list is empty (line 9), both `head` and `tail` will point to this new node (line 10). After the node is created, the size should be increased by `1` (line 7).

Clearly, the `addFirst` function takes O(1) time.
## Self-Check
### When a new node is inserted to the head of a linked list, will the head pointer and the tail pointer be changed?
The head pointer will be changed. The tail pointer will also be changed if the list is empty before the insertion.
# References