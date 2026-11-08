#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "trend.h"

/* Hash: sum of the ASCII codes of the characters, mod SIZE */
int hash(char tag[]) {
    int i, sum = 0;
    for (i = 0; tag[i] != '\0'; i++) sum += tag[i];
    return sum % SIZE;
}

void initDict(Dictionary D) {
    int i;
    for (i = 0; i < SIZE; i++) D[i] = NULL;
}

/* Number of DIFFERENT tags in the dictionary */
int countElems(Dictionary D) {
    int i, c = 0;
    List p;
    for (i = 0; i < SIZE; i++)
        for (p = D[i]; p != NULL; p = p->link) c++;
    return c;
}

/* Prints every bucket, e.g.  [3]: #cebu(3) -> #usc(1) */
void displayDict(Dictionary D) {
    int i;
    List p;
    for (i = 0; i < SIZE; i++) {
        printf("[%d]:", i);
        if (D[i] == NULL) printf(" (empty)");
        for (p = D[i]; p != NULL; p = p->link)
            printf(p == D[i] ? " %s(%d)" : " -> %s(%d)", p->tag, p->count);
        printf("\n");
    }
}