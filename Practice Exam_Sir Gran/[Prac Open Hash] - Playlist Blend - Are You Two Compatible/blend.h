#ifndef BLEND_H
#define BLEND_H

#define SIZE 10

typedef struct node {
    int data;
    struct node *link;
} *List;

typedef List Dictionary[SIZE];        /* open hashing: array of linked lists */

int hash(int x);

void initDict(Dictionary D);

int isMember(Dictionary D, int x);

/* Inserts x at the END of its bucket. Duplicates are ignored. */
void insert(Dictionary D, int x);

/* ---------- FUNCTION YOU WILL WRITE ---------- */
int blendScore(Dictionary A, Dictionary B);

#endif