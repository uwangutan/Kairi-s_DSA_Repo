#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include "hangout.h"

/*  TODO: Return the length of the longest run of consecutive days that are
          free for ALL friends, and store its first day in *start.
          If there is no such day, return 0 and set *start to 0.            */

int bestHangout(Set friends[], int f, int *start) {
    /* =========== DELETE ALL CODE BELOW THIS LINE =========== */
    /* PSEUDOCODE:
        Assume a completely free calendar
        Property of & : &'ing anything with 0 will always return 0 and will only return 1 if it's AND'ED with 1.
        Use & Property to cross out date if one person is unavailable.
           e.g - free calendar & not free friend = 0;
    */
    
    Set frees; // free calendar, assume everyone is AVAILABLE. 
    for (int k = 1; k < SIZE; k++) {
        frees[k] = 1;
    }
    
    // start crossing out people here, use & property to write only 0s and keep only 1s if no 0s.
    for (int i = 0; i < f; i++) {
        for (int j = 1; j < SIZE; j++) {
            frees[j] = frees[j] & friends[i][j];
        }
    }
    
    // find the longest run of ones
    int longest = 0;
    int stretch = 0;
    for (int k = 1; k < SIZE; k++) {
        if (frees[k]==1) {
            stretch++;
            
            if (stretch > longest) {
                longest = stretch;
                *start = k - longest + 1;
            }
        }
        
        else {
            stretch = 0;
        }
    }
    if (longest == 0) { *start = 0; return 0; }
    else { return longest; }
}