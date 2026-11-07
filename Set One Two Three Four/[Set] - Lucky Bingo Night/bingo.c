#include <stdio.h>
#include "bingo.h"

void initSet(Set S) {
    int i;
    for (i = 0; i < SIZE; i++) S[i] = 0;
}

void insert(Set S, int x) {
    if (x >= 1 && x < SIZE) S[x] = 1;
}

void deleteElem(Set S, int x) {
    if (x >= 1 && x < SIZE) S[x] = 0;
}

int isMember(Set S, int x) {
    return (x >= 1 && x < SIZE) ? S[x] : 0;
}

/* Prints the set, e.g. {3, 7, 12} */
void displaySet(Set S) {
    int i, first = 1;
    printf("{");
    for (i = 1; i < SIZE; i++)
        if (S[i]) { printf(first ? "%d" : ", %d", i); first = 0; }
    printf("}");
}