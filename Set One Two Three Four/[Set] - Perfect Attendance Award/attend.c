#include <stdio.h>
#include "attend.h"

void initSet(Set S) {
    int i;
    for (i = 0; i < SIZE; i++) S[i] = 0;
}

void insert(Set S, int x) {
    if (x >= 0 && x < SIZE) S[x] = 1;
}

int isMember(Set S, int x) {
    return (x >= 0 && x < SIZE) ? S[x] : 0;
}

/* Prints the set, e.g. {0, 4, 15} */
void displaySet(Set S) {
    int i, first = 1;
    printf("{");
    for (i = 0; i < SIZE; i++)
        if (S[i]) { printf(first ? "%d" : ", %d", i); first = 0; }
    printf("}");
}