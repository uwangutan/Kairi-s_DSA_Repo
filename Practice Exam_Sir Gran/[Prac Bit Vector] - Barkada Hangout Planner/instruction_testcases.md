# [Prac Bit Vector] - Barkada Hangout Planner
by Gran Sabandal

Concept: Set: Bit Vector · Time: 30 + 5 minutes · Write one function: _int bestHangout(Set friends[], int f, int *start)_

## Story Version
Your barkada has been saying "G tayo this sembreak!" in the group chat for weeks, but nothing has been planned. You decide to fix it with code.

Each friend sends the days in November (1–30) when they're free. Each friend's list is stored as a bit vector, where S\[d\] = 1 means they're free on day d.

Find the longest stretch of consecutive days when EVERYONE is free, so the out-of-town trip can finally happen. If two stretches are equally long, pick the earlier one so nobody has time to back out.

## Direct Version
Given f bit vectors over days 1..30 (index 0 unused):

1. A day is common if it is in every set (intersection).
2. Return the length of the longest run of consecutive common days, and store its first day in *start.
3. If two runs tie, choose the earliest one.
4. If there is no common day, return 0 and set *start = 0.


# Test Cases 
## Test Case 1
=== BARKADA HANGOUT PLANNER ===
Let's find days in November (1-30) when EVERYONE is free.
How many friends are in the barkada? 3
[Friend 1 of 3] Name: Ari
[Friend 1 of 3] How many free days does Ari have? 8
[Friend 1 of 3] Enter Ari's 8 free days separated by spaces (e.g. 5 6 7): 5 6 7 8 9 15 16 20
[Friend 2 of 3] Name: Bea
[Friend 2 of 3] How many free days does Bea have? 6
[Friend 2 of 3] Enter Bea's 6 free days separated by spaces (e.g. 5 6 7): 6 7 8 15 16 20
[Friend 3 of 3] Name: Cy
[Friend 3 of 3] How many free days does Cy have? 7
[Friend 3 of 3] Enter Cy's 7 free days separated by spaces (e.g. 5 6 7): 4 6 7 8 9 16 20


=== HANGOUT RESULT ===
Best hangout: Nov 6 to Nov 8 (3 days)

## Test Case 2
=== BARKADA HANGOUT PLANNER ===
Let's find days in November (1-30) when EVERYONE is free.
How many friends are in the barkada? 1
[Friend 1 of 1] Name: Solo
[Friend 1 of 1] How many free days does Solo have? 6
[Friend 1 of 1] Enter Solo's 6 free days separated by spaces (e.g. 5 6 7): 1 2 10 11 12 13


=== HANGOUT RESULT ===
Best hangout: Nov 10 to Nov 13 (4 days)

## Test Case 3
=== BARKADA HANGOUT PLANNER ===
Let's find days in November (1-30) when EVERYONE is free.
How many friends are in the barkada? 2
[Friend 1 of 2] Name: A
[Friend 1 of 2] How many free days does A have? 3
[Friend 1 of 2] Enter A's 3 free days separated by spaces (e.g. 5 6 7): 1 2 3
[Friend 2 of 2] Name: B
[Friend 2 of 2] How many free days does B have? 3
[Friend 2 of 2] Enter B's 3 free days separated by spaces (e.g. 5 6 7): 4 5 6


=== HANGOUT RESULT ===
No common free day. GC stays on seen.

## Test Case 4
=== BARKADA HANGOUT PLANNER ===
Let's find days in November (1-30) when EVERYONE is free.
How many friends are in the barkada? 2
[Friend 1 of 2] Name: A
[Friend 1 of 2] How many free days does A have? 30
[Friend 1 of 2] Enter A's 30 free days separated by spaces (e.g. 5 6 7): 1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16 17 18 19 20 21 22 23 24 25 26 27 28 29 30
[Friend 2 of 2] Name: B
[Friend 2 of 2] How many free days does B have? 30
[Friend 2 of 2] Enter B's 30 free days separated by spaces (e.g. 5 6 7): 30 29 28 27 26 25 24 23 22 21 20 19 18 17 16 15 14 13 12 11 10 9 8 7 6 5 4 3 2 1


=== HANGOUT RESULT ===
Best hangout: Nov 1 to Nov 30 (30 days)

## Test Case 5
=== BARKADA HANGOUT PLANNER ===
Let's find days in November (1-30) when EVERYONE is free.
How many friends are in the barkada? 2
[Friend 1 of 2] Name: A
[Friend 1 of 2] How many free days does A have? 6
[Friend 1 of 2] Enter A's 6 free days separated by spaces (e.g. 5 6 7): 3 4 10 11 20 21
[Friend 2 of 2] Name: B
[Friend 2 of 2] How many free days does B have? 6
[Friend 2 of 2] Enter B's 6 free days separated by spaces (e.g. 5 6 7): 3 4 10 11 20 21


=== HANGOUT RESULT ===
Best hangout: Nov 3 to Nov 4 (2 days)

## Test Case 6
=== BARKADA HANGOUT PLANNER ===
Let's find days in November (1-30) when EVERYONE is free.
How many friends are in the barkada? 2
[Friend 1 of 2] Name: A
[Friend 1 of 2] How many free days does A have? 5
[Friend 1 of 2] Enter A's 5 free days separated by spaces (e.g. 5 6 7): 2 27 28 29 30
[Friend 2 of 2] Name: B
[Friend 2 of 2] How many free days does B have? 4
[Friend 2 of 2] Enter B's 4 free days separated by spaces (e.g. 5 6 7): 2 28 29 30


=== HANGOUT RESULT ===
Best hangout: Nov 28 to Nov 30 (3 days)

## Test Case 7
=== BARKADA HANGOUT PLANNER ===
Let's find days in November (1-30) when EVERYONE is free.
How many friends are in the barkada? 2
[Friend 1 of 2] Name: A
[Friend 1 of 2] How many free days does A have? 5
[Friend 1 of 2] Enter A's 5 free days separated by spaces (e.g. 5 6 7): 1 2 3 4 20
[Friend 2 of 2] Name: B
[Friend 2 of 2] How many free days does B have? 4
[Friend 2 of 2] Enter B's 4 free days separated by spaces (e.g. 5 6 7): 1 2 3 20


=== HANGOUT RESULT ===
Best hangout: Nov 1 to Nov 3 (3 days)

## Test Case 8
=== BARKADA HANGOUT PLANNER ===
Let's find days in November (1-30) when EVERYONE is free.
How many friends are in the barkada? 3
[Friend 1 of 3] Name: A
[Friend 1 of 3] How many free days does A have? 3
[Friend 1 of 3] Enter A's 3 free days separated by spaces (e.g. 5 6 7): 5 6 7
[Friend 2 of 3] Name: B
[Friend 2 of 3] How many free days does B have? 0
[Friend 3 of 3] Name: C
[Friend 3 of 3] How many free days does C have? 3
[Friend 3 of 3] Enter C's 3 free days separated by spaces (e.g. 5 6 7): 5 6 7


=== HANGOUT RESULT ===
No common free day. GC stays on seen.

## Test Case 9
=== BARKADA HANGOUT PLANNER ===
Let's find days in November (1-30) when EVERYONE is free.
How many friends are in the barkada? 2
[Friend 1 of 2] Name: A
[Friend 1 of 2] How many free days does A have? 5
[Friend 1 of 2] Enter A's 5 free days separated by spaces (e.g. 5 6 7): 9 9 9 14 22
[Friend 2 of 2] Name: B
[Friend 2 of 2] How many free days does B have? 4
[Friend 2 of 2] Enter B's 4 free days separated by spaces (e.g. 5 6 7): 14 14 22 9


=== HANGOUT RESULT ===
Best hangout: Nov 9 to Nov 9 (1 days)

## Test Case 10
=== BARKADA HANGOUT PLANNER ===
Let's find days in November (1-30) when EVERYONE is free.
How many friends are in the barkada? 5
[Friend 1 of 5] Name: Ana
[Friend 1 of 5] How many free days does Ana have? 12
[Friend 1 of 5] Enter Ana's 12 free days separated by spaces (e.g. 5 6 7): 1 2 3 5 6 7 8 12 13 14 15 25
[Friend 2 of 5] Name: Ben
[Friend 2 of 5] How many free days does Ben have? 11
[Friend 2 of 5] Enter Ben's 11 free days separated by spaces (e.g. 5 6 7): 2 3 5 6 7 8 13 14 15 25 26
[Friend 3 of 5] Name: Cel
[Friend 3 of 5] How many free days does Cel have? 10
[Friend 3 of 5] Enter Cel's 10 free days separated by spaces (e.g. 5 6 7): 2 3 6 7 8 13 14 15 25 30
[Friend 4 of 5] Name: Dan
[Friend 4 of 5] How many free days does Dan have? 10
[Friend 4 of 5] Enter Dan's 10 free days separated by spaces (e.g. 5 6 7): 3 6 7 8 9 13 14 15 25 29
[Friend 5 of 5] Name: Eve
[Friend 5 of 5] How many free days does Eve have? 9
[Friend 5 of 5] Enter Eve's 9 free days separated by spaces (e.g. 5 6 7): 3 6 7 8 13 14 15 24 25


=== HANGOUT RESULT ===
Best hangout: Nov 6 to Nov 8 (3 days)