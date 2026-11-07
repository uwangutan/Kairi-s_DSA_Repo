#include <stdio.h>
#include "attend.h"

/*  TODO: Build two sets.
      perfect = students present on ALL days   (intersection of every day)
      never   = students present on NO day     (complement of the union of every day)
    Note: perfect and never contain garbage when this function is called,
          so fill in every index 0..SIZE-1 yourself.
    Hint: for bit vectors, intersection uses &&, union uses ||, complement uses !    */

void attendanceReport(Set days[], int d, Set perfect, Set never) {
    /* =========== DELETE ALL CODE BELOW THIS LINE =========== */
    for (int i = 0; i < SIZE; i++) {
        perfect[i] = 1;
        never[i] = 0;
    }
        
    for (int j = 0; j < d; j++) {
        for (int i = 0; i < SIZE; i++) {
            perfect[i] = perfect[i] && days[j][i];
            never[i] = never[i] || days[j][i];
        }
    }
    
    for (int i = 0; i < SIZE; i++) {
        never[i] = !never[i];
    }
    
}