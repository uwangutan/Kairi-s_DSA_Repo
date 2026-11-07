# \[Heap\] - Mana Crystal Harvest
by Gran Sabandal

Max Heap · write one function: int harvestMana(MaxHeap *H, int k)

## Story Version
You are a wizard in the Crystal Caves. Each crystal stores some mana. You have exactly k turns before the cave collapses.
On each turn you pick one crystal, absorb all of its mana, and the crystal slowly regrows to half its previous mana (rounded down).
A greedy wizard always picks the richest crystal on every turn. Return the total mana absorbed after k turns.

## Direct Version
Given a max heap of N non-negative integers and an integer k, repeat k times:

Remove the largest value m.
Add m to a running total.
Insert m / 2 (integer division).
Return the total. If the heap is empty, stop early.

# Test Cases 
## Test Case 1
Number of crystals and number of turns: 1 5
N crystal mana values: 100
Total mana harvested: 193

## Test Case 2
Number of crystals and number of turns: 3 4
N crystal mana values: 0 0 0
Total mana harvested: 0

## Test Case 3
Number of crystals and number of turns: 4 6
N crystal mana values: 1 1 1 1
Total mana harvested: 4

## Test Case 4
Number of crystals and number of turns: 5 5
N crystal mana values: 50 40 30 20 10
Total mana harvested: 165

## Test Case 5
Number of crystals and number of turns: 3 8
N crystal mana values: 16 8 4
Total mana harvested: 48

## Test Case 6
Number of crystals and number of turns: 6 4
N crystal mana values: 25 25 25 10 10 3
Total mana harvested: 87

## Test Case 7
Number of crystals and number of turns: 8 12
N crystal mana values: 1000 750 500 999 1 64 333 128
Total mana harvested: 5892

## Test Case 8
Number of crystals and number of turns: 3 3
N crystal mana values: 10 20 7
Total mana harvested: 40

## Test Case 9
Number of crystals and number of turns: 4 0
N crystal mana values: 5 9 3 8
Total mana harvested: 0

## Test Case 10
Number of crystals and number of turns: 0 5
N crystal mana values: Total mana harvested: 0