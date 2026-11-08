## Closed Hashing (Linear Probing with Student Structure)
Closed Hashing using Linear Probing is a collision-handling technique that stores all elements directly inside the hash table array. Unlike open hashing, it does not use linked lists to handle collisions. Instead, it searches for the next available array slot.

In this implementation, each slot stores a `Student` structure containing the student's ID, name, and a linked list of enrolled courses. The student ID serves as the key used for hashing.

### How It Works

1. Hashing: Apply the hash function to the student's ID to determine the initial array index.
2. Insertion: If the index is empty or deleted, store the student there.
3. Collision Handling: If the index is occupied, check the next slot using linear probing until an available slot is found.
4. Searching: Calculate the student's hash index using their ID, then follow the same probing sequence until the student is found or an empty slot is encountered.
5. Deletion: Find the student using their ID and mark the slot as `DELETED` instead of `EMPTY`, allowing searches to continue through previously occupied slots.

### Example

Suppose students with IDs `100`, `110`, and `120` all produce a hash index of `0`.

```
Hash Table (Array)

Index    Student ID    Name
  0         100        Alice
  1         110        Bob
  2         120        Charlie
  3        EMPTY
  4        EMPTY
  ...
  9        EMPTY
```

- Student `100` is stored at index `0`.
- Student `110` also hashes to index `0`, but since it is occupied, it is stored at index `1`.
- Student `120` also hashes to index `0`, so it checks indices `1` and `2` before finding an empty slot.

Each student structure also contains a linked list of enrolled courses, accessible through the `enrolled` head pointer.

Note: The `status` field determines whether a slot is occupied, empty, or deleted. The `Student` structure stores the actual student information, while `studentID` is the key used for hashing.

Key takeaway: Each array slot stores one complete `Student` structure. Collisions are handled by checking the next available slot rather than creating a linked list of dictionary elements.

Time Complexity: Searching takes O(1) on average when elements are distributed evenly. In the worst case, it takes O(n) because linear probing may need to check the entire array.