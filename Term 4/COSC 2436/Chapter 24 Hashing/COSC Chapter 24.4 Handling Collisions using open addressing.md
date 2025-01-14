# Summary

# Learning Objectives

# Related
Prev - [[COSC Chapter 24.3 Hash Functions and Hash Codes]]

Next - [[COSC Chapter 24.5 Handling collisions using separate chaining]]
# Content
## Key Point

A collision occurs when two keys are mapped to the same index in a hash table. Generally, there are two ways for handling collisions: open addressing and separate chaining.

[[Open addressing]] is the process of finding an open location in the hash table in the event of a collision. Open addressing has several variations: [[linear probing]], [[quadratic probing]], and [[double hashing]].

## 24.4.1 Linear Probing
When a collision occurs during the insertion of an entry to a hash table, _linear probing_ finds the next available location sequentially. For example, if a collision occurs at `hashTable[k % N]`, check whether `hashTable[(k+1) % N]` is available. If not, check `hashTable[(k+2) % N]` and so on, until an available cell is found, as shown in **Figure 24.2**.

## Figure 24.2
![[74x71hta.bmp]]

>[!Note]
When probing reaches the end of the table, it goes back to the beginning of the table. Thus, the hash table is treated as if it were circular.

To search for an entry in the hash table, obtain the index, say `k`, from the hash function for the key. Check whether `hashTable[k % N]` contains the entry. If not, check whether `hashTable[(k+1) % N]` contains the entry, and so on, until it is found, or an empty cell is reached.

To remove an entry from the hash table, search the entry that matches the key. If the entry is found, place a special marker to denote that the entry is available. Each cell in the hash table has three possible states: occupied, marked, or empty. Note that a marked cell is also available for insertion.

Linear probing tends to cause groups of consecutive cells in the hash table to be occupied. Each group is called a [_cluster_](https://revel-ise.pearson.com/courses/66e7050d84448f59a62c6945/assignments/87856d65-d2fd-4fcc-8620-deac9b07b3ef/pages/urn:pearson:entity:22b51207-49d4-4f77-b4d9-686f4cfb3ffd?source=dashboard#). Each cluster is actually a probe sequence that you must search when retrieving, adding, or removing an entry. As clusters grow in size, they may merge into even larger clusters, further slowing down the search time. This is a big disadvantage of linear probing.

## 24.4.2 Quadratic Probing

_Quadratic probing_ can avoid the clustering problem that can occur in linear probing. Linear probing looks at the consecutive cells beginning at index _k_. Quadratic probing, on the other hand, looks at the cells at indices (k + j2) % N, for j ≥ 0, that is, k % N, (k + 1) % N, (k + 4) % n, (k + 9) % N, . . . , and so on, as shown in **Figure 24.4**.

## Figure 24.4
![[6bk6chmu.bmp]]

Quadratic probing works in the same way as linear probing except for a change in the search sequence. Quadratic probing avoids linear probing’s clustering problem, but it has its own clustering problem, called [[secondary clustering]]; that is, the entries that collide with an occupied entry use the same probe sequence.

Linear probing guarantees that an available cell can be found for insertion as long as the table is not full. However, there is no such guarantee for quadratic probing.

## 24.4.3 Double Hashing

Another open addressing scheme that avoids the clustering problem is known as [[double hashing]]. Starting from the initial index _k_, both linear probing and quadratic probing add an increment to _k_ to define a search sequence. The increment is `1` for linear probing and `j2` for quadratic probing. These increments are independent of the keys. Double hashing uses a secondary hash function _h'(key)_ on the keys to determine the increments to avoid the clustering problem. Specifically, double hashing looks at the cells at indices _(k + j * h′(key)) % N, for j ≥ 0_, that is, _k % N, (k + h′(key)) % N, (k + 2 * h′(key)) % N, (k + 3 * h′(key)) % N, ..._, and so on.

For example, let the primary hash function `h` and secondary hash function `h'` on a hash table of size `11` be defined as follows:
```cpp
h(key) = key % 11; 
h'(key) = 7 – key % 7; 
```

For a search key of `12`, we have
```cpp
h(12) = 12 % 11 = 1; 
h'(12) = 7 – 12 % 7 = 2; 
```

Suppose the elements with the keys `45`, `58`, `4`, `28`, and `21` are already placed in the hash table. We now insert the element with key `12`. The probe sequence for key `12` starts at index `1`. Since the cell at index `1` is already occupied, search the next cell at index `3 (1 + 1 * 2)`. Since the cell at index `3` is already occupied, search the next cell at index `5 (1 + 2 * 2)`. Since the cell at index `5` is empty, the element for the key `12` is now inserted at this cell. The search process is illustrated in **Figure 24.6**.

The indices of the probe sequence are as follows: 1, 3, 5, 7, 9, 0, 2, 4, 6, 8, 10. This sequence reaches the entire table. You should design your functions to produce a probe sequence that reaches the entire table. Note that the second function should never have a zero value, since zero is not an increment.

## Figure 24.6
![[9vqd6aa1.bmp]]

## Self-Check
### What is open addressing? What is linear probing? What is quadratic probing? What is double hashing?

Open addressing is to find an open location in the hash table in the event of collision. Open addressing has several variations: linear probing, quadratic probing, and double hashing. When a collision occurs during the insertion of an entry to a hash table, linear probing finds the next available location sequentially.  
Quadratic probing can avoid the clustering problem in linear probing. Linear probing looks at the consecutive cells beginning at index k. Quadratic probing, on the other hand, looks at the cells at indices (k + j2) % n, for j ≥ 0, i.e., k, (k + 1) % n, (k + 4) % n, (k + 9) % n, ..., and so on.  
Another open addressing scheme that avoids the clustering problem is known as double hashing. Starting from the initial index k, both linear probing and quadratic probing add an increment to k to define a search sequence. The increment is 1 for linear probing and j2 for quadratic probing. These increments are independent of the keys. Double hashing uses a secondary hash function on the keys to determine the increments to avoid the clustering problem.

### Describe the clustering problem for linear probing.

Linear probing tends to cause groups of consecutive cells in the hash table to be occupied. Each group is called a cluster. Each cluster is actually a probe sequence that you must search when retrieving, adding, or removing an entry. As clusters grow in size, they may merge into even larger clusters, further slowing down the search time. This is a big disadvantage of linear probing.

### What is secondary clustering?

Quadratic probing works in the same way as linear probing except for the change of search sequence. Quadratic probing avoids the clustering problem in linear probing, but it has its own clustering problem, called secondary clustering, i.e., the entries that collide with an occupied entry use the same probe sequence.

### Show the hash table of size 11 after inserting entries with keys 34, 29, 53, 44, 120, 39, 45, and 40, using linear probing.

Use the animation https://liveexample.pearsoncmg.com/dsanimation/LinearProbingeBook.html to verify your anwser. To start, click the Remove All button to empty the hash table and set the load factor threshhold to 0.99.

### Show the hash table of size 11 after inserting entries with keys 34, 29, 53, 44, 120, 39, 45, and 40, using quadratic probing.

Use the animation https://liveexample.pearsoncmg.com/dsanimation/QuadraticProbingeBook.html to verify your anwser. To start, click the Remove All button to empty the hash table and set the load factor threshold to 0.99.

### Show the hash table of size 11 after inserting entries with keys 34, 29, 53, 44, 120, 39, 45, and 40, using double hashing with the following secondary hash function:`h'(k) = 7 - k % 7;`

See the text.
# References
