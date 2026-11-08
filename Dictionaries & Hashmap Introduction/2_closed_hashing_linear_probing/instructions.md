## Closed Hashing (Linear Probing)
Unlike open hashing, which stores colliding elements in a linked list at the same index, closed hashing stores all elements directly inside the hash table array.

### How It Works
When a collision occurs, linear probing checks the next index until an empty slot is found. If it reaches the end of the array, it wraps around to index 0.

### Example
Using the hash function `HASH(key) = (key - 'A') % 10`, suppose A, K, and U are inserted. All three hash to index 0.

Collision process:

1. Insert A → index 0 is empty, so store A.
2. Insert K → index 0 is occupied, so check index 1. Store K there.
3. Insert U → index 0 is occupied, check index 1, then index 2. Store U there.

Resulting hash table:

```
Index   Element
  0       A
  1       K
  2       U
  3      NULL
  4      NULL
  ...
  9      NULL
```

Key difference:

- Open hashing: Multiple elements can occupy the same bucket through a linked list.
- Closed hashing: Each array index holds only one element. Collisions are handled by finding another empty index.

Linear probing checks the next index (`index + 1`). Other probing methods include quadratic probing, which checks positions using squared intervals, and double hashing, which uses a second hash function to determine the next position.