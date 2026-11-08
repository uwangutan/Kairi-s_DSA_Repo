# \[Open Dict\] - Gate Pass Scanner
by Gran Sabandal

Write one function: _void processScan(Dictionary D, char cmd[], int id)_

## Story Version
The campus is hosting CodeFest, and you are in charge of the smart gate. Each visitor has a numbered badge. Every time a badge is tapped, the gate scans it as IN or OUT.

The guard wants the gate to catch trouble right away:

- A badge tapped IN while the person is already inside is a borrowed badge, so the gate denies it.
- A badge tapped OUT when the person was never inside is suspicious, so the gate raises an alert.
    - IN
        - If id is in D, print DENIED: `<id>` is already inside.
        - Otherwise, insert id and print WELCOME: `<id>`.
    - OUT
        - If id is in D, delete it and print GOODBYE: `<id>`.
        - Otherwise, print ALERT: `<id>` is not inside.

The gate keeps track of everyone inside using an open dictionary. A badge goes into bucket id % 10, which is its last digit. Write the brain of the gate.

## Direct Version
Given an open dictionary D (10 buckets, hash = id % 10) and one scan (cmd, id):

# Test Cases 
## Test Case 1
Enter number of scans: 5
IDs [IN `<id>` or OUT `<id>`]:
IN 1023
IN 2045
IN 3013
OUT 1023
IN 4050


WELCOME: 1023
WELCOME: 2045
WELCOME: 3013
GOODBYE: 1023
WELCOME: 4050
People inside: 3
\[0]: 4050
\[1]: (empty)
\[2]: (empty)
\[3]: 3013
\[4]: (empty)
\[5]: 2045
\[6]: (empty)
\[7]: (empty)
\[8]: (empty)
\[9]: (empty)

## Test Case 2
Enter number of scans: 2
IDs [IN `<id>` or OUT `<id>`]:
OUT 1001
OUT 1002


ALERT: 1001 is not inside
ALERT: 1002 is not inside
People inside: 0
\[0]: (empty)
\[1]: (empty)
\[2]: (empty)
\[3]: (empty)
\[4]: (empty)
\[5]: (empty)
\[6]: (empty)
\[7]: (empty)
\[8]: (empty)
\[9]: (empty)

## Test Case 3
Enter number of scans: 2
IDs [IN `<id>` or OUT `<id>`]:
IN 1005
IN 1005


WELCOME: 1005
DENIED: 1005 is already inside
People inside: 1
\[0]: (empty)
\[1]: (empty)
\[2]: (empty)
\[3]: (empty)
\[4]: (empty)
\[5]: 1005
\[6]: (empty)
\[7]: (empty)
\[8]: (empty)
\[9]: (empty)

## Test Case 4
Enter number of scans: 2
IDs [IN `<id>` or OUT `<id>`]:
IN 2001
OUT 2001


WELCOME: 2001
GOODBYE: 2001
People inside: 0
\[0]: (empty)
\[1]: (empty)
\[2]: (empty)
\[3]: (empty)
\[4]: (empty)
\[5]: (empty)
\[6]: (empty)
\[7]: (empty)
\[8]: (empty)
\[9]: (empty)

## Test Case 5
Enter number of scans: 5
IDs [IN `<id>` or OUT `<id>`]:
IN 1010
OUT 1010
IN 1010
OUT 1010
IN 1010


WELCOME: 1010
GOODBYE: 1010
WELCOME: 1010
GOODBYE: 1010
WELCOME: 1010
People inside: 1
\[0]: 1010
\[1]: (empty)
\[2]: (empty)
\[3]: (empty)
\[4]: (empty)
\[5]: (empty)
\[6]: (empty)
\[7]: (empty)
\[8]: (empty)
\[9]: (empty)

## Test Case 6
Enter number of scans: 4
IDs [IN `<id>` or OUT `<id>`]:
IN 1007
IN 2007
IN 3007
IN 4007


WELCOME: 1007
WELCOME: 2007
WELCOME: 3007
WELCOME: 4007
People inside: 4
\[0]: (empty)
\[1]: (empty)
\[2]: (empty)
\[3]: (empty)
\[4]: (empty)
\[5]: (empty)
\[6]: (empty)
\[7]: 1007 -> 2007 -> 3007 -> 4007
\[8]: (empty)
\[9]: (empty)

## Test Case 7
Enter number of scans: 4
IDs [IN `<id>` or OUT `<id>`]:
IN 1004
IN 2004
IN 3004
OUT 1004


WELCOME: 1004
WELCOME: 2004
WELCOME: 3004
GOODBYE: 1004
People inside: 2
\[0]: (empty)
\[1]: (empty)
\[2]: (empty)
\[3]: (empty)
\[4]: 2004 -> 3004
\[5]: (empty)
\[6]: (empty)
\[7]: (empty)
\[8]: (empty)
\[9]: (empty)

## Test Case 8
Enter number of scans: 6
IDs [IN `<id>` or OUT `<id>`]:
IN 1008
IN 2008
IN 3008
OUT 2008
OUT 3008
OUT 3008


WELCOME: 1008
WELCOME: 2008
WELCOME: 3008
GOODBYE: 2008
GOODBYE: 3008
ALERT: 3008 is not inside
People inside: 1
\[0]: (empty)
\[1]: (empty)
\[2]: (empty)
\[3]: (empty)
\[4]: (empty)
\[5]: (empty)
\[6]: (empty)
\[7]: (empty)
\[8]: 1008
\[9]: (empty)

## Test Case 9
Enter number of scans: 8
IDs [IN `<id>` or OUT `<id>`]:
IN 1111
IN 2222
IN 3331
OUT 2222
OUT 1111
IN 2222
OUT 3331
OUT 2222


WELCOME: 1111
WELCOME: 2222
WELCOME: 3331
GOODBYE: 2222
GOODBYE: 1111
WELCOME: 2222
GOODBYE: 3331
GOODBYE: 2222
People inside: 0
\[0]: (empty)
\[1]: (empty)
\[2]: (empty)
\[3]: (empty)
\[4]: (empty)
\[5]: (empty)
\[6]: (empty)
\[7]: (empty)
\[8]: (empty)
\[9]: (empty)

## Test Case 10
Enter number of scans: 15
IDs [IN `<id>` or OUT `<id>`]:
IN 1000
IN 2019
IN 3029
IN 1000
OUT 4444
IN 4444
IN 5009
OUT 2019
IN 6000
OUT 1000
IN 2019
OUT 5009
IN 7777
OUT 6000
IN 8009


WELCOME: 1000
WELCOME: 2019
WELCOME: 3029
DENIED: 1000 is already inside
ALERT: 4444 is not inside
WELCOME: 4444
WELCOME: 5009
GOODBYE: 2019
WELCOME: 6000
GOODBYE: 1000
WELCOME: 2019
GOODBYE: 5009
WELCOME: 7777
GOODBYE: 6000
WELCOME: 8009
People inside: 5
\[0]: (empty)
\[1]: (empty)
\[2]: (empty)
\[3]: (empty)
\[4]: 4444
\[5]: (empty)
\[6]: (empty)
\[7]: 7777
\[8]: (empty)
\[9]: 3029 -> 2019 -> 8009
