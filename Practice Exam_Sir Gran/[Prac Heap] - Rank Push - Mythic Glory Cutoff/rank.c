#include <stdio.h>
#include "rank.h"

void initHeap(MinHeap *H)  { H->lastNdx = -1; }
int  isEmpty(MinHeap H)    { return H.lastNdx == -1; }
int  size(MinHeap H)       { return H.lastNdx + 1; }
void swap(int *a, int *b)  { int t = *a; *a = *b; *b = t; }

/* Inserts x and bubbles it up. */
void insert(MinHeap *H, int x) {
    int child, parent;
    if (H->lastNdx == MAX - 1) return;
    H->Elem[++H->lastNdx] = x;
    child = H->lastNdx;
    parent = (child - 1) / 2;
    while (child > 0 && H->Elem[child] < H->Elem[parent]) {
        swap(&H->Elem[child], &H->Elem[parent]);
        child = parent;
        parent = (child - 1) / 2;
    }
}

/* Removes and returns the SMALLEST value. Returns -1 if empty. */
int deleteMin(MinHeap *H) {
    int min, ndx = 0, smallest, left, right;
    if (isEmpty(*H)) return -1;
    min = H->Elem[0];
    H->Elem[0] = H->Elem[H->lastNdx--];
    while (1) {
        smallest = ndx; left = 2 * ndx + 1; right = 2 * ndx + 2;
        if (left <= H->lastNdx && H->Elem[left] < H->Elem[smallest]) smallest = left;
        if (right <= H->lastNdx && H->Elem[right] < H->Elem[smallest]) smallest = right;
        if (smallest == ndx) break;
        swap(&H->Elem[ndx], &H->Elem[smallest]);
        ndx = smallest;
    }
    return min;
}

/* Returns the smallest value without removing it. Returns -1 if empty. */
int peekMin(MinHeap H) { return isEmpty(H) ? -1 : H.Elem[0]; }