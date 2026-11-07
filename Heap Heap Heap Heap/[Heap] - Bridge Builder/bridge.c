#include <stdio.h>
#include "bridge.h"

/* Initializes the heap as empty. */
void initHeap(MinHeap *H) {
    H->lastNdx = -1;
}

/* Returns 1 if the heap is empty, 0 otherwise. */
int isEmpty(MinHeap H) {
    return H.lastNdx == -1;
}

/* Returns the number of elements in the heap. */
int size(MinHeap H) {
    return H.lastNdx + 1;
}

/* Swaps the values pointed to by a and b. */
void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

/* Inserts x and bubbles it up. */
void insert(MinHeap *H, int x) {
    int child, parent;

    if (H->lastNdx >= MAX - 1) {
        return; /* heap is full */
    }

    H->lastNdx++;
    H->Elem[H->lastNdx] = x;

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
    int min, parent, child;

    if (H->lastNdx == -1) {
        return -1;
    }

    min = H->Elem[0];

    /* Move last element to the root and shrink the heap. */
    H->Elem[0] = H->Elem[H->lastNdx];
    H->lastNdx--;

    /* Bubble the new root down. */
    parent = 0;
    while (1) {
        int left = 2 * parent + 1;
        int right = 2 * parent + 2;

        if (left > H->lastNdx) {
            break; /* no children */
        }

        child = left;
        if (right <= H->lastNdx && H->Elem[right] < H->Elem[left]) {
            child = right;
        }

        if (H->Elem[child] < H->Elem[parent]) {
            swap(&H->Elem[child], &H->Elem[parent]);
            parent = child;
        } else {
            break;
        }
    }

    return min;
}

/* Returns the smallest value without removing it. Returns -1 if empty. */
int peekMin(MinHeap H) {
    if (H.lastNdx == -1) {
        return -1;
    }
    return H.Elem[0];
}