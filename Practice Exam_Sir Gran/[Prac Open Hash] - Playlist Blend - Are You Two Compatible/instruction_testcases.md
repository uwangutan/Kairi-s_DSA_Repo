# [Prac Open Hash] - Playlist Blend: Are You Two Compatible?
by Gran Sabandal

Concept: Open Dictionary (Open Hashing) · Time: 30 + 5 minutes · Write one function: _int blendScore(Dictionary A, Dictionary B)_

## Story Version
Your music app has a Blend feature. Two people combine their liked songs, and the app shows a match % to decide whether you're soulmates or just a situationship.

Each person's liked songs (4-digit song IDs) are stored in an open dictionary: 10 buckets, each a linked list. The app then needs the score:

Blend % = (songs you BOTH like) × 100 ÷ (songs EITHER of you likes)

The result is rounded down. Write the function that computes the blend.

## Direct Version
Given two open dictionaries A and B (SIZE = 10, hash(x) = x % 10), return

**|A ∩ B| * 100 / |A ∪ B| (integer division).**

If both are empty, return 0. You must walk the buckets' linked lists yourself. isMember is available.

# Test Cases 
## Test Case 1
=== PLAYLIST BLEND ===
Song IDs are 4-digit numbers (1000-9999).
[Your playlist] How many liked songs? 5
[Your playlist] Enter the 5 song IDs separated by spaces (e.g. 1001 1002 1003): 1001 1002 1003 1004 1005
[Their playlist] How many liked songs? 5
[Their playlist] Enter the 5 song IDs separated by spaces (e.g. 1001 1002 1003): 1003 1004 1005 1006 1007


=== BLEND RESULT ===
Blend: 42%
Situationship energy

## Test Case 2
=== PLAYLIST BLEND ===
Song IDs are 4-digit numbers (1000-9999).
[Your playlist] How many liked songs? 0
[Their playlist] How many liked songs? 0


=== BLEND RESULT ===
Blend: 0%
It's giving strangers

## Test Case 3
=== PLAYLIST BLEND ===
Song IDs are 4-digit numbers (1000-9999).
[Your playlist] How many liked songs? 3
[Your playlist] Enter the 3 song IDs separated by spaces (e.g. 1001 1002 1003): 2001 2002 2003
[Their playlist] How many liked songs? 0


=== BLEND RESULT ===
Blend: 0%
It's giving strangers

## Test Case 4
=== PLAYLIST BLEND ===
Song IDs are 4-digit numbers (1000-9999).
[Your playlist] How many liked songs? 4
[Your playlist] Enter the 4 song IDs separated by spaces (e.g. 1001 1002 1003): 3010 3021 3032 3043
[Their playlist] How many liked songs? 4
[Their playlist] Enter the 4 song IDs separated by spaces (e.g. 1001 1002 1003): 3043 3032 3021 3010


=== BLEND RESULT ===
Blend: 100%
Certified soulmates

## Test Case 5
=== PLAYLIST BLEND ===
Song IDs are 4-digit numbers (1000-9999).
[Your playlist] How many liked songs? 3
[Your playlist] Enter the 3 song IDs separated by spaces (e.g. 1001 1002 1003): 1111 2222 3333
[Their playlist] How many liked songs? 3
[Their playlist] Enter the 3 song IDs separated by spaces (e.g. 1001 1002 1003): 4444 5555 6666


=== BLEND RESULT ===
Blend: 0%
It's giving strangers

## Test Case 6
=== PLAYLIST BLEND ===
Song IDs are 4-digit numbers (1000-9999).
[Your playlist] How many liked songs? 4
[Your playlist] Enter the 4 song IDs separated by spaces (e.g. 1001 1002 1003): 1001 1001 1002 1001
[Their playlist] How many liked songs? 4
[Their playlist] Enter the 4 song IDs separated by spaces (e.g. 1001 1002 1003): 1002 1001 1002 1002


=== BLEND RESULT ===
Blend: 100%
Certified soulmates

## Test Case 7
=== PLAYLIST BLEND ===
Song IDs are 4-digit numbers (1000-9999).
[Your playlist] How many liked songs? 4
[Your playlist] Enter the 4 song IDs separated by spaces (e.g. 1001 1002 1003): 1011 1021 1031 1041
[Their playlist] How many liked songs? 3
[Their playlist] Enter the 3 song IDs separated by spaces (e.g. 1001 1002 1003): 1021 1041 1051


=== BLEND RESULT ===
Blend: 40%
Situationship energy

## Test Case 8
=== PLAYLIST BLEND ===
Song IDs are 4-digit numbers (1000-9999).
[Your playlist] How many liked songs? 3
[Your playlist] Enter the 3 song IDs separated by spaces (e.g. 1001 1002 1003): 1001 1002 1003
[Their playlist] How many liked songs? 1
[Their playlist] Enter the 1 song IDs separated by spaces (e.g. 1001 1002 1003): 1001


=== BLEND RESULT ===
Blend: 33%
Situationship energy

## Test Case 9
=== PLAYLIST BLEND ===
Song IDs are 4-digit numbers (1000-9999).
[Your playlist] How many liked songs? 4
[Your playlist] Enter the 4 song IDs separated by spaces (e.g. 1001 1002 1003): 5001 5002 5003 5004
[Their playlist] How many liked songs? 5
[Their playlist] Enter the 5 song IDs separated by spaces (e.g. 1001 1002 1003): 5001 5002 5003 5004 5005


=== BLEND RESULT ===
Blend: 80%
Certified soulmates

## Test Case 10
=== PLAYLIST BLEND ===
Song IDs are 4-digit numbers (1000-9999).
[Your playlist] How many liked songs? 8
[Your playlist] Enter the 8 song IDs separated by spaces (e.g. 1001 1002 1003): 1010 1020 1031 1041 1052 1062 1073 1083
[Their playlist] How many liked songs? 7
[Their playlist] Enter the 7 song IDs separated by spaces (e.g. 1001 1002 1003): 1020 1041 1062 1083 1010 1094 1095


=== BLEND RESULT ===
Blend: 50%
Vibes match