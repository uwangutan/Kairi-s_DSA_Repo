# [Prac Heap] - Rank Push: Mythic Glory Cutoff
by Gran Sabandal

Concept: Heap (Priority Queue) · Time: 30 + 5 minutes · Write one function: _int gloryCutoff(MinHeap *H, int k, int points)_

## Story Version
It's the last night of the ranked season in Mobile Legendz. Only the Top k players get the exclusive Mythic Glory frame for their profile, and everyone in the group chat keeps asking "what's the cutoff na?"

Match results come in one at a time. After every match, the stream overlay shows the cutoff, which is the lowest score that is still in the Top k. If fewer than k players have posted a score, the overlay shows that the board is not full yet.

The overlay runs on a potato PC, so it can't sort the whole leaderboard after every match. You get a min heap to work with. Write the function that updates the cutoff.

## Direct Version
This function is called once for each new score. H keeps its contents between calls, and k ≥ 1.

1. Keep the k highest scores seen so far in H.
2. Return the smallest of those k scores (the k-th highest overall).
3. If fewer than k scores have been posted, return -1.
Use the given heap operations: insert, deleteMin, peekMin, size.

# Test Cases 
## Test Case 1
=== MYTHIC GLORY LEADERBOARD ===
Only the Top k players this season get the Mythic Glory frame.
How many players make the Top k? Enter k: 3
How many match results will be posted? 6
[Match 1 of 6] Player username: Kai
[Match 1 of 6] Rank points earned: 1200
[Match 2 of 6] Player username: Bea
[Match 2 of 6] Rank points earned: 1500
[Match 3 of 6] Player username: Lio
[Match 3 of 6] Rank points earned: 900
[Match 4 of 6] Player username: Mika
[Match 4 of 6] Rank points earned: 1600
[Match 5 of 6] Player username: Zed
[Match 5 of 6] Rank points earned: 1000
[Match 6 of 6] Player username: Ana
[Match 6 of 6] Rank points earned: 1550


=== LIVE OVERLAY ===
Kai pushed 1200 pts | Top 3 not full yet
Bea pushed 1500 pts | Top 3 not full yet
Lio pushed 900 pts | Top 3 cutoff: 900
Mika pushed 1600 pts | Top 3 cutoff: 1200
Zed pushed 1000 pts | Top 3 cutoff: 1200
Ana pushed 1550 pts | Top 3 cutoff: 1500
Final Mythic Glory cutoff: 1500

## Test Case 2
=== MYTHIC GLORY LEADERBOARD ===
Only the Top k players this season get the Mythic Glory frame.
How many players make the Top k? Enter k: 1
How many match results will be posted? 5
[Match 1 of 5] Player username: Ren
[Match 1 of 5] Rank points earned: 300
[Match 2 of 5] Player username: Yuki
[Match 2 of 5] Rank points earned: 500
[Match 3 of 5] Player username: Jo
[Match 3 of 5] Rank points earned: 200
[Match 4 of 5] Player username: Pia
[Match 4 of 5] Rank points earned: 800
[Match 5 of 5] Player username: Max
[Match 5 of 5] Rank points earned: 700


=== LIVE OVERLAY ===
Ren pushed 300 pts | Top 1 cutoff: 300
Yuki pushed 500 pts | Top 1 cutoff: 500
Jo pushed 200 pts | Top 1 cutoff: 500
Pia pushed 800 pts | Top 1 cutoff: 800
Max pushed 700 pts | Top 1 cutoff: 800
Final Mythic Glory cutoff: 800

## Test Case 3
=== MYTHIC GLORY LEADERBOARD ===
Only the Top k players this season get the Mythic Glory frame.
How many players make the Top k? Enter k: 5
How many match results will be posted? 3
[Match 1 of 3] Player username: Aya
[Match 1 of 3] Rank points earned: 900
[Match 2 of 3] Player username: Ben
[Match 2 of 3] Rank points earned: 950
[Match 3 of 3] Player username: Cy
[Match 3 of 3] Rank points earned: 1000


=== LIVE OVERLAY ===
Aya pushed 900 pts | Top 5 not full yet
Ben pushed 950 pts | Top 5 not full yet
Cy pushed 1000 pts | Top 5 not full yet
Leaderboard still loading...

## Test Case 4
=== MYTHIC GLORY LEADERBOARD ===
Only the Top k players this season get the Mythic Glory frame.
How many players make the Top k? Enter k: 4
How many match results will be posted? 4
[Match 1 of 4] Player username: A
[Match 1 of 4] Rank points earned: 10
[Match 2 of 4] Player username: B
[Match 2 of 4] Rank points earned: 40
[Match 3 of 4] Player username: C
[Match 3 of 4] Rank points earned: 30
[Match 4 of 4] Player username: D
[Match 4 of 4] Rank points earned: 20


=== LIVE OVERLAY ===
A pushed 10 pts | Top 4 not full yet
B pushed 40 pts | Top 4 not full yet
C pushed 30 pts | Top 4 not full yet
D pushed 20 pts | Top 4 cutoff: 10
Final Mythic Glory cutoff: 10

## Test Case 5
=== MYTHIC GLORY LEADERBOARD ===
Only the Top k players this season get the Mythic Glory frame.
How many players make the Top k? Enter k: 2
How many match results will be posted? 5
[Match 1 of 5] Player username: P1
[Match 1 of 5] Rank points earned: 100
[Match 2 of 5] Player username: P2
[Match 2 of 5] Rank points earned: 100
[Match 3 of 5] Player username: P3
[Match 3 of 5] Rank points earned: 100
[Match 4 of 5] Player username: P4
[Match 4 of 5] Rank points earned: 50
[Match 5 of 5] Player username: P5
[Match 5 of 5] Rank points earned: 200


=== LIVE OVERLAY ===
P1 pushed 100 pts | Top 2 not full yet
P2 pushed 100 pts | Top 2 cutoff: 100
P3 pushed 100 pts | Top 2 cutoff: 100
P4 pushed 50 pts | Top 2 cutoff: 100
P5 pushed 200 pts | Top 2 cutoff: 100
Final Mythic Glory cutoff: 100

## Test Case 6
=== MYTHIC GLORY LEADERBOARD ===
Only the Top k players this season get the Mythic Glory frame.
How many players make the Top k? Enter k: 3
How many match results will be posted? 7
[Match 1 of 7] Player username: Gab
[Match 1 of 7] Rank points earned: 500
[Match 2 of 7] Player username: Tin
[Match 2 of 7] Rank points earned: 600
[Match 3 of 7] Player username: Lou
[Match 3 of 7] Rank points earned: 700
[Match 4 of 7] Player username: Ram
[Match 4 of 7] Rank points earned: 100
[Match 5 of 7] Player username: Sam
[Match 5 of 7] Rank points earned: 200
[Match 6 of 7] Player username: Tom
[Match 6 of 7] Rank points earned: 300
[Match 7 of 7] Player username: Uly
[Match 7 of 7] Rank points earned: 650


=== LIVE OVERLAY ===
Gab pushed 500 pts | Top 3 not full yet
Tin pushed 600 pts | Top 3 not full yet
Lou pushed 700 pts | Top 3 cutoff: 500
Ram pushed 100 pts | Top 3 cutoff: 500
Sam pushed 200 pts | Top 3 cutoff: 500
Tom pushed 300 pts | Top 3 cutoff: 500
Uly pushed 650 pts | Top 3 cutoff: 600
Final Mythic Glory cutoff: 600

## Test Case 7
=== MYTHIC GLORY LEADERBOARD ===
Only the Top k players this season get the Mythic Glory frame.
How many players make the Top k? Enter k: 3
How many match results will be posted? 5
[Match 1 of 5] Player username: V1
[Match 1 of 5] Rank points earned: 777
[Match 2 of 5] Player username: V2
[Match 2 of 5] Rank points earned: 777
[Match 3 of 5] Player username: V3
[Match 3 of 5] Rank points earned: 777
[Match 4 of 5] Player username: V4
[Match 4 of 5] Rank points earned: 777
[Match 5 of 5] Player username: V5
[Match 5 of 5] Rank points earned: 777


=== LIVE OVERLAY ===
V1 pushed 777 pts | Top 3 not full yet
V2 pushed 777 pts | Top 3 not full yet
V3 pushed 777 pts | Top 3 cutoff: 777
V4 pushed 777 pts | Top 3 cutoff: 777
V5 pushed 777 pts | Top 3 cutoff: 777
Final Mythic Glory cutoff: 777

## Test Case 8
=== MYTHIC GLORY LEADERBOARD ===
Only the Top k players this season get the Mythic Glory frame.
How many players make the Top k? Enter k: 1
How many match results will be posted? 1
[Match 1 of 1] Player username: Solo
[Match 1 of 1] Rank points earned: 1337


=== LIVE OVERLAY ===
Solo pushed 1337 pts | Top 1 cutoff: 1337
Final Mythic Glory cutoff: 1337

## Test Case 9
=== MYTHIC GLORY LEADERBOARD ===
Only the Top k players this season get the Mythic Glory frame.
How many players make the Top k? Enter k: 3
How many match results will be posted? 6
[Match 1 of 6] Player username: Q
[Match 1 of 6] Rank points earned: 900
[Match 2 of 6] Player username: W
[Match 2 of 6] Rank points earned: 800
[Match 3 of 6] Player username: E
[Match 3 of 6] Rank points earned: 700
[Match 4 of 6] Player username: R
[Match 4 of 6] Rank points earned: 600
[Match 5 of 6] Player username: T
[Match 5 of 6] Rank points earned: 500
[Match 6 of 6] Player username: Y
[Match 6 of 6] Rank points earned: 400


=== LIVE OVERLAY ===
Q pushed 900 pts | Top 3 not full yet
W pushed 800 pts | Top 3 not full yet
E pushed 700 pts | Top 3 cutoff: 700
R pushed 600 pts | Top 3 cutoff: 700
T pushed 500 pts | Top 3 cutoff: 700
Y pushed 400 pts | Top 3 cutoff: 700
Final Mythic Glory cutoff: 700

## Test Case 10
=== MYTHIC GLORY LEADERBOARD ===
Only the Top k players this season get the Mythic Glory frame.
How many players make the Top k? Enter k: 5
How many match results will be posted? 15
[Match 1 of 15] Player username: Ash
[Match 1 of 15] Rank points earned: 1200
[Match 2 of 15] Player username: Bry
[Match 2 of 15] Rank points earned: 1350
[Match 3 of 15] Player username: Cel
[Match 3 of 15] Rank points earned: 980
[Match 4 of 15] Player username: Dex
[Match 4 of 15] Rank points earned: 1500
[Match 5 of 15] Player username: Eli
[Match 5 of 15] Rank points earned: 1420
[Match 6 of 15] Player username: Fae
[Match 6 of 15] Rank points earned: 1100
[Match 7 of 15] Player username: Gio
[Match 7 of 15] Rank points earned: 1600
[Match 8 of 15] Player username: Hal
[Match 8 of 15] Rank points earned: 1001
[Match 9 of 15] Player username: Ivy
[Match 9 of 15] Rank points earned: 1430
[Match 10 of 15] Player username: Jin
[Match 10 of 15] Rank points earned: 1430
[Match 11 of 15] Player username: Kat
[Match 11 of 15] Rank points earned: 999
[Match 12 of 15] Player username: Leo
[Match 12 of 15] Rank points earned: 1700
[Match 13 of 15] Player username: Moe
[Match 13 of 15] Rank points earned: 1250
[Match 14 of 15] Player username: Nia
[Match 14 of 15] Rank points earned: 1650
[Match 15 of 15] Player username: Oz
[Match 15 of 15] Rank points earned: 1440


=== LIVE OVERLAY ===
Ash pushed 1200 pts | Top 5 not full yet
Bry pushed 1350 pts | Top 5 not full yet
Cel pushed 980 pts | Top 5 not full yet
Dex pushed 1500 pts | Top 5 not full yet
Eli pushed 1420 pts | Top 5 cutoff: 980
Fae pushed 1100 pts | Top 5 cutoff: 1100
Gio pushed 1600 pts | Top 5 cutoff: 1200
Hal pushed 1001 pts | Top 5 cutoff: 1200
Ivy pushed 1430 pts | Top 5 cutoff: 1350
Jin pushed 1430 pts | Top 5 cutoff: 1420
Kat pushed 999 pts | Top 5 cutoff: 1420
Leo pushed 1700 pts | Top 5 cutoff: 1430
Moe pushed 1250 pts | Top 5 cutoff: 1430
Nia pushed 1650 pts | Top 5 cutoff: 1430
Oz pushed 1440 pts | Top 5 cutoff: 1440
Final Mythic Glory cutoff: 1440