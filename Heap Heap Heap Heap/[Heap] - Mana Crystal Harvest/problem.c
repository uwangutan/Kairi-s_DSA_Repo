#include <stdio.h>
#include "mana.h"

/*  TODO: Return the total mana harvested after k turns.
    Each turn: take the richest crystal, add its mana, put back half (integer division).
    Available: size(*H), isEmpty(*H), deleteMax(H), insert(H, x), peekMax(*H) */
int harvestMana(MaxHeap *H, int k) {
    /* =========== DELETE ALL CODE BELOW THIS LINE =========== */
    int total = 0;
    for (int i = 0; i < k && H->lastNdx > -1; i++) {
        int m = peekMax(*H);
        deleteMax(H);
        insert(H, m/2);
        total += m;
    }
    return total;
}