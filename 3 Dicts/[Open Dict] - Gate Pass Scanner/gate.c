#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "gate.h"

/* Hash: last digit of x (works for negatives too) */
int hash(int x) { return ((x % SIZE) + SIZE) % SIZE; }

void initDict(Dictionary D) {
    int i;
    for (i = 0; i < SIZE; i++) D[i] = NULL;
}

/* Returns 1 if x is in the dictionary, else 0 */
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

/* Deletes x from its bucket if it exists */
void deleteElem(Dictionary D, int x) {
    List *trav, temp;
    for (trav = &D[hash(x)]; *trav != NULL && (*trav)->data != x; trav = &(*trav)->link) {}
    if (*trav != NULL) {
        temp = *trav;
        *trav = temp->link;
        free(temp);
    }
}

/* Number of elements in the dictionary */
int countElems(Dictionary D) {
    int i, c = 0;
    List p;
    for (i = 0; i < SIZE; i++)
        for (p = D[i]; p != NULL; p = p->link) c++;
    return c;
}

/* Prints every bucket, e.g.  [3]: 1023 -> 3013 */
void displayDict(Dictionary D) {
    int i;
    List p;
    for (i = 0; i < SIZE; i++) {
        printf("[%d]:", i);
        if (D[i] == NULL) printf(" (empty)");
        for (p = D[i]; p != NULL; p = p->link)
            printf(p == D[i] ? " %d" : " -> %d", p->data);
        printf("\n");
    }
}