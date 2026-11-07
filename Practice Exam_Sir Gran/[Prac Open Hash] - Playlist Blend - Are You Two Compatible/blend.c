#include <stdio.h>
#include <stdlib.h>
#include "blend.h"

int hash(int x) { return x % SIZE; }  /* last digit of the song ID */

void initDict(Dictionary D) {
    int i;
    for (i = 0; i < SIZE; i++) D[i] = NULL;
}

int isMember(Dictionary D, int x) {
    List p;
    for (p = D[hash(x)]; p != NULL && p->data != x; p = p->link) {}
    return p != NULL;
}

/* Inserts x at the END of its bucket. Duplicates are ignored. */
void insert(Dictionary D, int x) {
    List *trav;
    for (trav = &D[hash(x)]; *trav != NULL && (*trav)->data != x; trav = &(*trav)->link) {}
    if (*trav == NULL) {
        *trav = (List) malloc(sizeof(struct node));
        (*trav)->data = x;
        (*trav)->link = NULL;
    }
}