#include <stdio.h>
#include "ghost.h"

void initSet(Set *S)            { *S = 0; }
void insert(Set *S, int x)      { *S = *S | (1 << x); }
void deleteElem(Set *S, int x)  { *S = *S & ~(1 << x); }
int  isMember(Set S, int x)     { return (S >> x) & 1; }

/* Prints the 8 bits (bit 7 first) and the room names, e.g. 00000101 {Attic, Kitchen} */
void displaySet(Set S) {
    int i, first = 1;
    for (i = 7; i >= 0; i--) printf("%d", (S >> i) & 1);
    printf(" {");
    for (i = 0; i < 8; i++)
        if ((S >> i) & 1) { printf(first ? "%s" : ", %s", ROOM[i]); first = 0; }
    printf("}");
}