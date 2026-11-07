# \[Heap\] - Bridge Builder
by Gran Sabandal

Min Heap · write one function: int minBridgeCost(MinHeap *H)

## Story Version
A river splits the kingdom, and the villagers have collected N wooden planks of different lengths. To cross, all of the planks must be joined into one long bridge.

The village carpenter can join two planks at a time. Joining planks of length a and b costs a + b gold and produces one plank of length a + b.

The village treasury is small. Find the minimum total gold needed to join all of the planks into one.

## Direct Version
Given a min heap of N positive integers, repeat while there are at least two values:

1. Remove the two smallest values a and b.
2. Add a + b to the total cost.
3. Insert a + b.

Return the total cost. If N is 0 or 1, the cost is 0.

# Test Cases 
## Test Case 1
N (number of planks): 4
N plank lengths: 4 3 2 6

Minimum gold spent: 29

## Test Case 2
N (number of planks): 0
N plank lengths:
Minimum gold spent: 0

## Test Case 3
N (number of planks): 1
N plank lengths: 15

Minimum gold spent: 0

## Test Case 4
N (number of planks): 2
N plank lengths: 5 9

Minimum gold spent: 14

## Test Case 5
N (number of planks): 4
N plank lengths: 5 5 5 5

Minimum gold spent: 40

## Test Case 6
N (number of planks): 6
N plank lengths: 1 1 1 1 1 1

Minimum gold spent: 16

## Test Case 7
N (number of planks): 5
N plank lengths: 9 7 5 3 1

Minimum gold spent: 54

## Test Case 8
N (number of planks): 5
N plank lengths: 100 1 2 1 2

Minimum gold spent: 118

## Test Case 9
N (number of planks): 7
N plank lengths: 8 4 8 2 4 6 2

Minimum gold spent: 90

## Test Case 10
N (number of planks): 10
N plank lengths: 20 4 8 15 16 23 42 1 7 11

Minimum gold spent: 435