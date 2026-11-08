# Max Heap Operations
by Gran Sabandal

## Direct Version
A max heap is an array where every parent is greater than or equal to its children, so the largest value is always at index 0.

For an element at index i:
- parent = (i-1)/2
- left child = 2i+1
- right child = 2i+2

The heap holds up to MAX = 20 elements. lastNdx is the index of the last element, and -1 means the heap is empty.
The program has a pool of 50 numbers. populateData(count, order) inserts up to count of them using your insert, picked by order:
orderNumbers used0All, in sequence1Odd records2Even records31st half42nd half
After populating, the program deletes the maximum D times.

## Task
Complete the 5 TODO functions:

1. isEmpty: return 1 if the heap is empty.
2. isFull: return 1 if the heap has MAX elements.
3. insert: add the value at the end, then swap it with its parent while it is bigger.
    - If the heap is full, print Heap is full: `<x>` not inserted.
4. maxHeapify: swap the element with its larger child until it is bigger than both children.
5. deleteMax: move the last element to the root, shrink the heap, call maxHeapify(H, 0), then print Deleted: `<value>`.
    - If the heap is empty, print Heap is empty.

**Challenge: Implement the MinHeap version.**

# Test Cases 
## Test Case 1
Enter number of data to insert and sequence: 5 0
Enter number of data to delete: 1
Initial Heap: 78 56 45 3 12
Deleted: 78
Final Heap: 56 12 45 3
Size: 4

## Test Case 2
Enter number of data to insert and sequence: 0 0
Enter number of data to delete: 0
Initial Heap: (empty)
Final Heap: (empty)
Size: 0

## Test Case 3
Enter number of data to insert and sequence: 0 0
Enter number of data to delete: 2
Initial Heap: (empty)
Heap is empty
Heap is empty
Final Heap: (empty)
Size: 0

## Test Case 4
Enter number of data to insert and sequence: 1 3
Enter number of data to delete: 1
Initial Heap: 45
Deleted: 45
Final Heap: (empty)
Size: 0

## Test Case 5
Enter number of data to insert and sequence: 25 0
Enter number of data to delete: 2
Heap is full: 38 not inserted
Heap is full: 64 not inserted
Heap is full: 19 not inserted
Heap is full: 76 not inserted
Heap is full: 30 not inserted
Initial Heap: 99 91 78 89 83 72 60 56 50 67 15 45 8 23 41 3 27 34 5 12
Deleted: 99
Deleted: 91
Final Heap: 89 83 78 56 67 72 60 27 50 5 15 45 8 23 41 3 12 34
Size: 18

## Test Case 6
Enter number of data to insert and sequence: 10 1
Enter number of data to delete: 3
Initial Heap: 78 45 56 41 34 15 8 23 27 5
Deleted: 78
Deleted: 56
Deleted: 45
Final Heap: 41 34 15 27 23 5 8
Size: 7

## Test Case 7
Enter number of data to insert and sequence: 10 2
Enter number of data to delete: 3
Initial Heap: 99 91 72 89 83 12 60 3 50 67
Deleted: 99
Deleted: 91
Deleted: 89
Final Heap: 83 67 72 3 50 12 60
Size: 7

## Test Case 8
Enter number of data to insert and sequence: 10 4
Enter number of data to delete: 4
Initial Heap: 70 55 42 55 42 -7 18 -15 0 9
Deleted: 70
Deleted: 55
Deleted: 55
Deleted: 42
Final Heap: 42 9 18 -15 0 -7
Size: 6

## Test Case 9
Enter number of data to insert and sequence: 3 4
Enter number of data to delete: 5
Initial Heap: 55 55 -7
Deleted: 55
Deleted: 55
Deleted: -7
Heap is empty
Heap is empty
Final Heap: (empty)
Size: 0

## Test Case 10
Enter number of data to insert and sequence: 3 4
Enter number of data to delete: 5
Initial Heap: 55 55 -7
Deleted: 55
Deleted: 55
Deleted: -7
Heap is empty
Heap is empty
Final Heap: (empty)
Size: 0

Test case 10


Your Output

No Output

Expected Output

Enter number of data to insert and sequence: 20 4
Enter number of data to delete: 20
Initial Heap: 100 88 61 70 55 42 25 55 47 36 42 -7 -3 18 25 -15 -20 0 13 9
Deleted: 100
Deleted: 88
Deleted: 70
Deleted: 61
Deleted: 55
Deleted: 55
Deleted: 47
Deleted: 42
Deleted: 42
Deleted: 36
Deleted: 25
Deleted: 25
Deleted: 18
Deleted: 13
Deleted: 9
Deleted: 0
Deleted: -3
Deleted: -7
Deleted: -15
Deleted: -20
Final Heap: (empty)
Size: 0