#ifndef POTION_H
#define POTION_H

#define SIZE 10

typedef struct node {
    int data;
    struct node *link;
} *List;

typedef List Dictionary[SIZE];        /* open hashing: array of linked lists */

/* Hash: last digit of x (works for negatives too) */
int hash(int x);

void initDict(Dictionary D);

/* Returns 1 if x is in the dictionary, else 0 */
int isMember(Dictionary D, int x);

/* Inserts x at the END of its bucket. Duplicates are ignored. */
void insert(Dictionary D, int x);

/* Deletes x from its bucket if it exists */
void deleteElem(Dictionary D, int x);

/* Number of elements in the dictionary */
int countElems(Dictionary D);

/* Prints every bucket, e.g.  [3]: 1023 -> 3013 */
void displayDict(Dictionary D);

/* ---------- FUNCTION YOU WILL WRITE ---------- */
int findPair(Dictionary D, int potions[], int n, int target, int *first, int *second);

#endif