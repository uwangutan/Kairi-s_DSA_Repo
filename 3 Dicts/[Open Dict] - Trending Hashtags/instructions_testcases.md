# \[Open Dict\] - Trending Hashtags
by Gran Sabandal

Write one function: _void addTag(Dictionary D, char tag[])_

## Story Version
You are an intern at ChikaFeed, the hottest social app in Cebu. Every post comes with a hashtag, and the app shows which tag is trending.

Each hashtag is stored in an open dictionary together with a counter. When a post comes in:

- If its tag is already in the dictionary, add 1 to that tag's counter.
- If it is a new tag, add it with a count of 1 at the end of its bucket.

The dashboard code is already done. It prints the dictionary and announces the top tag. Your job is the function that records each post.

## Direct Version
Given an open dictionary D (10 buckets, hash = sum of ASCII codes % 10) of nodes {tag, count, link}, and a string tag:

- If a node with the same tag is in bucket hash(tag), increase its count by 1.
- Otherwise, create a node with count = 1 and append it to the end of that bucket.

Tags are case-sensitive.

# Test Cases 
## Test Case 1
Enter # of post: 7
Hashtags:
#usc
#cebu
#dsa
#cebu
#usc
#cebu
#heaps
Unique hashtags: 4
\[0]: #cebu(3)
\[1]: (empty)
\[2]: (empty)
\[3]: (empty)
\[4]: #heaps(1)
\[5]: (empty)
\[6]: #usc(2)
\[7]: #dsa(1)
\[8]: (empty)
\[9]: (empty)
Top trending: #cebu with 3 posts

## Test Case 2
Enter # of post: 1
Hashtags:
#hello
Unique hashtags: 1
\[0]: (empty)
\[1]: (empty)
\[2]: (empty)
\[3]: (empty)
\[4]: (empty)
\[5]: (empty)
\[6]: (empty)
\[7]: #hello(1)
\[8]: (empty)
\[9]: (empty)
Top trending: #hello with 1 posts

## Test Case 3
Enter # of post: 4
Hashtags:
#sinulog
#sinulog
#sinulog
#sinulog
Unique hashtags: 1
\[0]: (empty)
\[1]: (empty)
\[2]: (empty)
\[3]: (empty)
\[4]: #sinulog(4)
\[5]: (empty)
\[6]: (empty)
\[7]: (empty)
\[8]: (empty)
\[9]: (empty)
Top trending: #sinulog with 4 posts

## Test Case 4
Enter # of post: 4
Hashtags:
#zebra
#mango
#apple
#kiwi
Unique hashtags: 4
\[0]: (empty)
\[1]: #kiwi(1)
\[2]: (empty)
\[3]: (empty)
\[4]: (empty)
\[5]: #mango(1) -> #apple(1)
\[6]: (empty)
\[7]: #zebra(1)
\[8]: (empty)
\[9]: (empty)
Top trending: #apple with 1 posts

## Test Case 5
Enter # of post: 4
Hashtags:
#USC
#usc
#Usc
#usc
Unique hashtags: 3
\[0]: #USC(1)
\[1]: (empty)
\[2]: (empty)
\[3]: (empty)
\[4]: #Usc(1)
\[5]: (empty)
\[6]: #usc(2)
\[7]: (empty)
\[8]: (empty)
\[9]: (empty)
Top trending: #usc with 2 posts

## Test Case 6
Enter # of post: 5
Hashtags:
#cebu
#cebu2026
#cebu
\#ceb
#cebu2026
Unique hashtags: 3
\[0]: #cebu(2)
\[1]: (empty)
\[2]: #cebu2026(2)
\[3]: \#ceb(1)
\[4]: (empty)
\[5]: (empty)
\[6]: (empty)
\[7]: (empty)
\[8]: (empty)
\[9]: (empty)
Top trending: #cebu with 2 posts

## Test Case 7
Enter # of post: 5
Hashtags:
\#abc
\#cba
\#bca
\#abc
\#cba
Unique hashtags: 3
\[0]: (empty)
\[1]: (empty)
\[2]: (empty)
\[3]: (empty)
\[4]: (empty)
\[5]: (empty)
\[6]: (empty)
\[7]: (empty)
\[8]: (empty)
\[9]: \#abc(2) -> \#cba(2) -> \#bca(1)
Top trending: #abc with 2 posts

## Test Case 8
Enter # of post: 5
Hashtags:
#b
#a
#b
#a
#c
Unique hashtags: 3
\[0]: (empty)
\[1]: (empty)
\[2]: #a(2)
\[3]: #b(2)
\[4]: #c(1)
\[5]: (empty)
\[6]: (empty)
\[7]: (empty)
\[8]: (empty)
\[9]: (empty)
Top trending: #a with 2 posts

## Test Case 9
Enter # of post: 6
Hashtags:
#old
#old
#new
#new
#new
#old2
Unique hashtags: 3
\[0]: (empty)
\[1]: (empty)
\[2]: (empty)
\[3]: (empty)
\[4]: #old(2) -> #old2(1)
\[5]: #new(3)
\[6]: (empty)
\[7]: (empty)
\[8]: (empty)
\[9]: (empty)
Top trending: #new with 3 posts

## Test Case 10
Enter # of post: 15
Hashtags:
#exam
#dsa
#heap
#hash
#dsa
#coffee
#exam
#dsa
#hash
#sleep
#coffee
#dsa
#hash
#exam
#hash
Unique hashtags: 6
\[0]: (empty)
\[1]: #coffee(2)
\[2]: #exam(3) -> #sleep(1)
\[3]: (empty)
\[4]: (empty)
\[5]: #hash(4)
\[6]: (empty)
\[7]: #dsa(4)
\[8]: (empty)
\[9]: #heap(1)
Top trending: #dsa with 4 posts