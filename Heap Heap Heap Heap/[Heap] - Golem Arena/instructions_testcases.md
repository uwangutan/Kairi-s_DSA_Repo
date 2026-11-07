# \[Heap\] - Golem Arena
by Gran Sabandal

Max Heap · write one function: _int lastGolem(MaxHeap *H)_
 
## Story Version
Welcome to the Golem Arena! The crowd only wants to see the two heaviest golems fight.

Every round, the two heaviest golems step into the ring and smash into each other:

- If they weigh the same, both shatter into dust.
- If one is heavier, the lighter golem is destroyed. The heavier golem survives but loses weight equal to the lighter golem's weight, and it limps back into the waiting line.

The tournament ends when one golem or none is left. As the Arena Master, you must announce the weight of the champion. If no golem survives, return 0.

## Direct Version
Given a max heap of N positive integers, repeat until at most one value remains:

1. Remove the largest value a and the second largest value b.
2. If a != b, insert a - b.

Return the last remaining value, or 0 if the heap is empty.

# Test Cases 
## Test Case 1
N (number of golems): 0
N golem weights:
Arena is empty. No golem survives!

## Test Case 2
N (number of golems): 1
N golem weights: 9

Champion golem weight: 9

## Test Case 3
N (number of golems): 2
N golem weights: 5 5

Arena is empty. No golem survives!

## Test Case 4
N (number of golems): 6
N golem weights: 2 7 4 1 8 1

Champion golem weight: 1

## Test Case 5
N (number of golems): 2
N golem weights: 10 3

Champion golem weight: 7

## Test Case 6
N (number of golems): 4
N golem weights: 6 6 6 6

Arena is empty. No golem survives!

## Test Case 7
N (number of golems): 5
N golem weights: 4 4 4 4 4

Champion golem weight: 4

## Test Case 8
N (number of golems): 8
N golem weights: 1 2 3 4 5 6 7 9

Champion golem weight: 1

## Test Case 9
N (number of golems): 6
N golem weights: 100 1 1 1 1 1

Champion golem weight: 95

## Test Case 10
N (number of golems): 12
N golem weights: 31 26 33 21 40 26 15 8 40 19 3 27

Champion golem weight: 1