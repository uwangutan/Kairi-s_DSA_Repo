#include <stdio.h>
#include "rank.h"

/*  TODO: Process one new score and return the current Top-k cutoff,
          or -1 if fewer than k scores have been posted.             */

int gloryCutoff(MinHeap *H, int k, int points) {
    /* =========== DELETE ALL CODE BELOW THIS LINE =========== */
    /* PSEUDOCODE:
        There are 3 different situations.
        1.) When there are less than k elements
        2.) When there are more than k elements
        3.) When there are exactly k elements, board shouldn't say loading
    */
    insert(H, points);
    if (size(*H) < k) { return -1; }
    if (size(*H) > k) { deleteMin(H); }
    return peekMin(*H);
}