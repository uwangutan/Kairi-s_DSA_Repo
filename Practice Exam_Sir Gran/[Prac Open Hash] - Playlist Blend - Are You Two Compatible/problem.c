#include <stdio.h>
#include <stdlib.h>
#include "blend.h"

/*  TODO: Return the blend score  |A intersection B| * 100 / |A union B|
          (integer division). Return 0 if both playlists are empty.        */

int blendScore(Dictionary A, Dictionary B) {
    /* =========== DELETE ALL CODE BELOW THIS LINE =========== */
    /* PSEUDOCODE:*/
    // formula for finding union = common elements + unique elements in A + unique elements in B.
    // union = common + uniqueA + uniqueB
    
    int common = 0;
    int exclusiveA = 0;
    int exclusiveB = 0;
    
    // find all unique from a and find common
    for (int i = 0; i < SIZE; i++) {
        List trav = A[i];
        while (trav) {
            if (isMember(B, trav->data)) {
                common++;
            }
            else {
                exclusiveA++;
            }
            trav = trav->link;
        }
    }
    
    // find all unique from b, no need common since found in A alr
    for (int i = 0; i < SIZE; i++) {
        List trav = B[i];
        while (trav) {
            if (isMember(A, trav->data)==0) {
                exclusiveB++;
            }
            trav = trav->link;
        }
    }
    
    // formula according to problem: common * 100 / everything
    int everything = common + exclusiveB + exclusiveA;
    if (everything == 0) return 0;
    return common * 100 / everything;
}