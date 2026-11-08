## Closed Hashing (Cursor-Based Implementation)
Closed Hashing using a Cursor-Based Implementation is a collision-handling technique that uses an array to simulate linked lists without using pointers or dynamic memory allocation.

In this method, the hash table is divided into two areas:

- Prime Area: Stores the first element for each hash index.
- Synonym Area: Stores additional elements that collide with an existing element. Each node uses an integer `next` field to point to the next node's array index.

### How It Works

1. Hashing: Apply the hash function to determine which prime area index an element belongs to.
2. Insertion: If the prime slot is empty, store the element directly. Otherwise, get an available node from the synonym area.
3. Collision Handling: Link the new element to the existing chain using its `next` index. In this implementation, new synonyms are inserted at the front of the chain.
4. Searching: Calculate the element's hash index, then follow the `next` indices until the element is found or the chain ends (`-1`).
5. Deletion: Unlink the element from its chain and return its index to the available-node list (`avail`). If deleting the prime element while synonyms exist, promote the first synonym into the prime slot.

### Example

Suppose `A`, `K`, and `U` all produce a hash index of `0`.

```
Prime Area              Synonym Area

Index   Data             Index   Data   Next
  0      A                 6      U      7
  1     EMPTY              7      K     -1
  2     EMPTY              8     EMPTY   9
  3     EMPTY              9     EMPTY  -1
  4     EMPTY
  5     EMPTY
```

- Index `0` stores `A`, the first element for that hash index.
- `A` points to index `6`, which stores `U`.
- `U` points to index `7`, which stores `K`.
- Index `7` has `next = -1`, meaning the chain ends.
- `avail = 8`, pointing to the first available node in the synonym area.

Note: In this implementation, new synonyms are inserted at the front of the linked chain. The `avail` variable keeps track of the first available synonym node.

Key takeaway: Unlike open hashing, which uses an array of pointers to dynamically allocated linked-list nodes, cursor-based hashing stores the linked lists inside the array itself. The `next` field stores array indices instead of memory addresses.

Time Complexity: Searching takes O(1) on average, assuming elements are distributed evenly across buckets. In the worst case, it takes O(n) because all elements could hash to the same index, requiring traversal of the entire chain.