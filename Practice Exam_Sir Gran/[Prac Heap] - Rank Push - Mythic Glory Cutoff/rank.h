#ifndef RANK_H
#define RANK_H

#define MAX 100

typedef struct {
    int Elem[MAX];
    int lastNdx;                /* index of last element, -1 if empty */
} MinHeap;

void initHeap(MinHeap *H);
int  isEmpty(MinHeap H);
int  size(MinHeap H);
void swap(int *a, int *b);

/* Inserts x and bubbles it up. */
void insert(MinHeap *H, int x);

/* Removes and returns the SMALLEST value. Returns -1 if empty. */
int deleteMin(MinHeap *H);

/* Returns the smallest value without removing it. Returns -1 if empty. */
int peekMin(MinHeap H);

/* ---------- FUNCTION YOU WILL WRITE ---------- */
int gloryCutoff(MinHeap *H, int k, int points);

#endif