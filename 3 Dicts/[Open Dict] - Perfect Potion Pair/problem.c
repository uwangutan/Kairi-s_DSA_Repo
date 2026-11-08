#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "potion.h"

/*  TODO: Scan the potions from left to right.
    For each potion p:
      - need = target - p
      - if need is already in D: set *first = need, *second = p, return 1
      - otherwise insert p into D
    If no pair is found, return 0.
    Available: isMember(D, x), insert(D, x)                              */

int findPair(Dictionary D, int potions[], int n, int target, int *first, int *second) {
    /* =========== DELETE ALL CODE BELOW THIS LINE =========== */
    for (int i = 0; i < n; i++) {
        int p = potions[i];
        int need = target - p;
        
        if (isMember(D, need)) {
            *first = need;
            *second = p;
            return 1;
        }
        
        else {
            insert(D, p);
        }
    }

    return 0;
}