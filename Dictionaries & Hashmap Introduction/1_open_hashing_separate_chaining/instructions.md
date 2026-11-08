## Open Hashing (Separate Chaining)
Open Hashing, also called Separate Chaining, is a collision-handling technique that uses linked lists.

In this method, each slot in the hash table (array) stores a pointer to the head of a linked list. Each linked list contains the elements that belong to that particular hash index.

### How It Works
1. Hashing: Apply the hash function to determine which array index (bucket) an element belongs to.
2. Insertion: Insert the element into the linked list at its corresponding bucket.
3. Collision Handling: If two or more elements have the same hash index, they are stored in the same linked list instead of overwriting each other.
4. Searching: Calculate the element's hash index, then traverse the linked list at that index to find it.
5. Deletion: Find the element in its corresponding linked list, unlink the node, and free its memory.

### Example
Suppose `A`, `K`, and `U` all produce a hash index of `0`.

```
Hash Table (Array)

Index     Linked List
  0       U -> K -> A -> NULL
  1       NULL
  2       NULL
  3       NULL
  ...
  9       NULL
```

- Index `0` points to the head of a linked list containing `U`, `K`, and `A`.
- Indexes `1` to `9` are empty, so their pointers are `NULL`.
- Since all three elements have the same hash index, they belong to the same linked list.

Note: In this implementation, new elements are inserted at the front of the linked list (head insertion), not appended to the end.

Key takeaway: Each array slot is the head pointer of a linked list. Elements with the same hash index share that linked list.

Time Complexity: Searching in a hash table using separate chaining takes O(1) on average, assuming elements are distributed evenly across buckets. However, in the worst case, it takes O(n) because all elements could hash to the same bucket, requiring traversal of the entire linked list.