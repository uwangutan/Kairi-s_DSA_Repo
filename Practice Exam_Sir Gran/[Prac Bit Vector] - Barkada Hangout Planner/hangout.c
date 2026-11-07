#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include "hangout.h"

void initSet(Set S) {
    int i;
    for (i = 0; i < SIZE; i++) S[i] = 0;
}

void insert(Set S, int d)   { if (d >= 1 && d < SIZE) S[d] = 1; }
int  isMember(Set S, int d) { return (d >= 1 && d < SIZE) ? S[d] : 0; }