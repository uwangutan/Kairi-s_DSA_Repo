# \[Set\] - Lucky Bingo Night
by Gran Sabandal

Bit Vector · Subset · write one function: _int bingoWinTurn(Set card, int calls[], int n)_

# Test Cases 
## Test Case 1
Enter number of cards: 5
Card numbers: 7 12 30 41 3
Number of calls: 10
Numbers called: 12 5 7 41 22 3 18 30 9 1
Card: {3, 7, 12, 30, 41}
BINGO! on call #8 (number 30)

## Test Case 2
Enter number of cards: 1
Card numbers: 25
Number of calls: 3
Numbers called: 25 10 11
Card: {25}
BINGO! on call #1 (number 25)

## Test Case 3
Enter number of cards: 3
Card numbers: 1 2 3
Number of calls: 4
Numbers called: 1 2 4 5
Card: {1, 2, 3}
No BINGO after 4 calls

## Test Case 4
Enter number of cards: 2
Card numbers: 4 9
Number of calls: 0
Numbers called: Card: {4, 9}
No BINGO after 0 calls

## Test Case 5
Enter number of cards: 3
Card numbers: 10 20 30
Number of calls: 5
Numbers called: 10 10 10 20 30
Card: {10, 20, 30}
BINGO! on call #5 (number 30)

## Test Case 6
Enter number of cards: 4
Card numbers: 8 8 15 15
Number of calls: 3
Numbers called: 15 8 2
Card: {8, 15}
BINGO! on call #2 (number 8)

## Test Case 7
Enter number of cards: 4
Card numbers: 2 4 6 8
Number of calls: 6
Numbers called: 8 1 6 3 4 2
Card: {2, 4, 6, 8}
BINGO! on call #6 (number 2)

## Test Case 8
Enter number of cards: 2
Card numbers: 1 50
Number of calls: 4
Numbers called: 50 25 1 49
Card: {1, 50}
BINGO! on call #3 (number 1)

## Test Case 9
Enter number of cards: 3
Card numbers: 11 22 33
Number of calls: 8
Numbers called: 33 22 11 44 1 2 3 4
Card: {11, 22, 33}
BINGO! on call #3 (number 11)

## Test Case 10
Enter number of cards: 10
Card numbers: 5 9 14 18 23 27 31 38 44 50
Number of calls: 25
Numbers called: 1 9 14 2 50 9 3 18 23 4 44 5 6 27 7 31 8 14 10 11 12 38 13 15 16
Card: {5, 9, 14, 18, 23, 27, 31, 38, 44, 50}
BINGO! on call #22 (number 38)