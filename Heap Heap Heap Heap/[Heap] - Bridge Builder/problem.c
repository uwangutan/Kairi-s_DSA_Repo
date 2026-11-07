#include <stdio.h>
#include "bridge.h"

/*  TODO: Return the minimum total gold needed to join all planks into one.
    Joining planks of length a and b costs a + b gold and makes one plank of length a + b.
    Available: size(*H), isEmpty(*H), deleteMin(H), insert(H, x), peekMin(*H) */
int minBridgeCost(MinHeap *H) {
    /* =========== DELETE ALL CODE BELOW THIS LINE =========== */
    int total = 0;
    while (H->lastNdx > 0) {
        // save min value then delete
        int a = peekMin(*H);
        deleteMin(H);
        int b = peekMin(*H);
        deleteMin(H);
    
        insert(H, a + b);
        total += a + b;
    }
    return total;
}