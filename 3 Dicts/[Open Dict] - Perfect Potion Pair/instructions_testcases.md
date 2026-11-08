# [Open Dict] - Perfect Potion Pair
by Gran Sabandal

Write one function: _int findPair(Dictionary D, int potions[], int n, int target, int *first, int *second)_

## Story Version
You are an apprentice alchemist. The Grand Wizard needs a brew with a power of exactly **target**, made by mixing two potions.
Potions come off the conveyor belt one at a time. Each potion has a power value, and cursed potions have negative power. When a potion arrives, you check your shelf. If the shelf already holds the potion that would complete the brew, you mix the two immediately. If not, you put the new potion on the shelf and wait for the next one.
Your shelf is an open dictionary, so checking for a potion takes about O(1). Find the first perfect pair.

## Direct Version
Given n integers and a target, scan them from left to right. For each value p:

1. Compute need = target - p.
2. If need is in D, set *first = need and *second = p, then return 1.
3. Otherwise, insert p into D.

If no pair is found, return 0. A potion cannot pair with itself, but two potions with the same value can pair.

# Test Cases 
## Test Case 1
Enter # of target and # of potion powers: 6 15
Enter potion powers: 3 8 12 5 7 10
Perfect brew: 3 + 12 = 15

## Test Case 2
Enter # of target and # of potion powers: 0 10
Enter potion powers: No perfect brew possible

## Test Case 3
Enter # of target and # of potion powers: 1 10
Enter potion powers: 10
No perfect brew possible

## Test Case 4
Enter # of target and # of potion powers: 4 10
Enter potion powers: 5 3 5 1
Perfect brew: 5 + 5 = 10

## Test Case 5
Enter # of target and # of potion powers: 3 10
Enter potion powers: 5 2 1
No perfect brew possible

## Test Case 6
Enter # of target and # of potion powers: 5 4
Enter potion powers: -3 8 1 7 2
Perfect brew: -3 + 7 = 4

## Test Case 7
Enter # of target and # of potion powers: 4 0
Enter potion powers: 6 0 -6 3
Perfect brew: 6 + -6 = 0

## Test Case 8
Enter # of target and # of potion powers: 6 100
Enter potion powers: 10 20 30 40 50 90
Perfect brew: 10 + 90 = 100

## Test Case 9
Enter # of target and # of potion powers: 6 12
Enter potion powers: 7 2 5 10 6 6
Perfect brew: 7 + 5 = 12

## Test Case 10
Enter # of target and # of potion powers: 10 50
Enter potion powers: 11 21 31 41 51 61 71 81 91 101
No perfect brew possible