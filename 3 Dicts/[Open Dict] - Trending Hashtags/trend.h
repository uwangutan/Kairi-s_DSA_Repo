#ifndef TREND_H
#define TREND_H

#define SIZE 10

typedef struct node {
    char tag[30];
    int count;                        /* how many times the tag was posted */
    struct node *link;
} *List;

typedef List Dictionary[SIZE];        /* open hashing: array of linked lists */

/* Hash: sum of the ASCII codes of the characters, mod SIZE */
int hash(char tag[]);

void initDict(Dictionary D);

/* Number of DIFFERENT tags in the dictionary */
int countElems(Dictionary D);

/* Prints every bucket, e.g.  [3]: #cebu(3) -> #usc(1) */
void displayDict(Dictionary D);

/* ---------- FUNCTION YOU WILL WRITE ---------- */
void addTag(Dictionary D, char tag[]);

#endif