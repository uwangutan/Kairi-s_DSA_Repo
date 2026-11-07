# \[Set\] - Ghost of the Mansion
by Gran Sabandal

Computer Word · Symmetric Difference (XOR) · write one function: _int banishGhost(Set *lights, Set switches[], int presses[], int p)_

## Story Version
A ghost haunts a mansion with 8 rooms. Each room's light is one bit of an unsigned char:

bit | room
0   | Attic
1   | Library
2   | Kitchen
3   | Cellar
4   | Hall
5   | Chapel
6   | Study
7   | Tower

The ghost only leaves when every light is OFF. The mansion has old switches, and each one toggles a group of rooms: lights that are ON go OFF, and lights that are OFF go ON.

You follow a sequence of switch presses. Stop the moment the mansion goes dark.

## Direct Version
Given a computer-word set *lights, an array of switches, and p switch numbers in presses (1-based):

1. If *lights == 0, return 0.
2. For each press s, do *lights ^= switches[s-1]. If *lights becomes 0, return the number of presses made so far.
3. If the lights never all go off, return -1.

*lights must hold the final state when the function ends.

# Test Cases 
## Test Case 1
ROOM STATE
Enter count: 0
State: Number of switches: 1
ROOM that SWITCHES
Enter count: 1
State: 0
Number of press: 2
Switch numbers 1 to switches(m): 1 1


STATUS REPORT
Start: 00000000 {}
Ghost banished after 0 presses!
Final: 00000000 {}

## Test Case 2
ROOM STATE
Enter count: 1
State: 0
Number of switches: 1
ROOM that SWITCHES
Enter count: 1
State: 1
Number of press: 3
Switch numbers 1 to switches(m): 1 1 1


STATUS REPORT
Start: 00000001 {Attic}
The ghost stays...
Final: 00000011 {Attic, Library}

## Test Case 3
ROOM STATE
Enter count: 1
State: 3
Number of switches: 2
ROOM that SWITCHES
Enter count: 2
State: 3 4
Enter count: 1
State: 4
Number of press: 4
Switch numbers 1 to switches(m): 1 1 1 2


STATUS REPORT
Start: 00001000 {Cellar}
Ghost banished after 4 presses!
Final: 00000000 {}

## Test Case 4
ROOM STATE
Enter count: 1
State: 5
Number of switches: 2
ROOM that SWITCHES
Enter count: 0
State: Enter count: 1
State: 5
Number of press: 3
Switch numbers 1 to switches(m): 1 1 2


STATUS REPORT
Start: 00100000 {Chapel}
Ghost banished after 3 presses!
Final: 00000000 {}

## Test Case 5
ROOM STATE
Enter count: 1
State: 7
Number of switches: 1
ROOM that SWITCHES
Enter count: 1
State: 7
Number of press: 0
Switch numbers 1 to switches(m):

STATUS REPORT
Start: 10000000 {Tower}
The ghost stays...
Final: 10000000 {Tower}

## Test Case 6
ROOM STATE
Enter count: 2
State: 0 1
Number of switches: 2
ROOM that SWITCHES
Enter count: 2
State: 0 1
Enter count: 1
State: 2
Number of press: 3
Switch numbers 1 to switches(m): 1 2 2


STATUS REPORT
Start: 00000011 {Attic, Library}
Ghost banished after 1 presses!
Final: 00000000 {}

## Test Case 7
ROOM STATE
Enter count: 8
State: 0 1 2 3 4 5 6 7
Number of switches: 1
ROOM that SWITCHES
Enter count: 8
State: 0 1 2 3 4 5 6 7
Number of press: 1
Switch numbers 1 to switches(m): 1


STATUS REPORT
Start: 11111111 {Attic, Library, Kitchen, Cellar, Hall, Chapel, Study, Tower}
Ghost banished after 1 presses!
Final: 00000000 {}

## Test Case 8
ROOM STATE
Enter count: 1
State: 6
Number of switches: 3
ROOM that SWITCHES
Enter count: 2
State: 6 7
Enter count: 2
State: 7 0
Enter count: 1 0
State: Number of press: 3
Switch numbers 1 to switches(m): 1 2 3


STATUS REPORT
Start: 01000000 {Study}
Ghost banished after 3 presses!
Final: 00000000 {}

## Test Case 9
ROOM STATE
Enter count: 4
State: 1 3 5 7
Number of switches: 5
ROOM that SWITCHES
Enter count: 3
State: 1 2 3
Enter count: 2
State: 5 7
Enter count: 4
State: 0 2 4 6
Enter count: 1
State: 6
Enter count: 3
State: 0 4 2
Number of press: 10
Switch numbers 1 to switches(m): 2 4 5 1 3 2 1 4 5 3


STATUS REPORT
Start: 10101010 {Library, Cellar, Chapel, Tower}
The ghost stays...
Final: 10101010 {Library, Cellar, Chapel, Tower}

## Test Case 10
ROOM STATE
Enter count: 2
State: 0 2
Number of switches: 3
ROOM that SWITCHES
Enter count: 2
State: 0 1
Enter count: 2
State: 1 2
Enter count: 1
State: 4
Number of press: 3
Switch numbers 1 to switches(m): 1 2 3


STATUS REPORT
Start: 00000101 {Attic, Kitchen}
Ghost banished after 2 presses!
Final: 00000000 {}
