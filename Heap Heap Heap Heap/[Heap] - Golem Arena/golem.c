#include <stdio.h>
#include "golem.h"

void initHeap(MaxHeap *H) { H->lastNdx = -1; }

int isEmpty(MaxHeap H) { return H.lastNdx == -1; }

int size(MaxHeap H) { return H.lastNdx + 1; }

void swap(int *a, int *b) { int t = *a; *a = *b; *b = t; }

/* Inserts x and bubbles it up. */
void insert(MaxHeap *H, int x) {
    // Kairi's AI generated pseudocode
    // STEP 1: Declare ints child and parent
    // STEP 2: Make a conditional: is H->lastNdx already MAX - 1? (array is full)
    //         If yes, return
    // STEP 3: Add 1 to H->lastNdx, then store x at H->Elem[H->lastNdx]
    //         (the new element always goes in the first open spot at the end)
    // STEP 4: Set child to H->lastNdx
    // STEP 5: Set parent using the parent formula
    // STEP 6: BUBBLE UP: make a while loop that keeps going while
    //         child is greater than 0 (it isn't the root yet)
    //         AND the child's value is BIGGER than the parent's value
    //         Inside the loop:
    //   STEP 7: Swap the child and parent values (pass addresses with &)
    //   STEP 8: Move child up to where parent was
    //   STEP 9: Recompute parent from the new child
    int child, parent;
    if (H->lastNdx==MAX - 1) { return; }
    H->Elem[++H->lastNdx] = x;
    
    child = H->lastNdx;
    parent = (child - 1)/2; 
    
    while (child > 0 && H->Elem[child] > H->Elem[parent]) {
        swap(&H->Elem[child], &H->Elem[parent]);
        child = parent;
        parent = (child - 1)/2;
    }
}

/* Removes and returns the LARGEST value. Returns -1 if empty. */
int deleteMax(MaxHeap *H) {
    int max, ndx, largest, left, right; 
    if(isEmpty(*H)) { return -1; }
    max = H->Elem[0];
    ndx = 0;
    H->Elem[0] = H->Elem[H->lastNdx--];
    while (1) {
        largest = ndx; 
        left = 2 * ndx + 1; 
        right = 2 * ndx + 2;
        if (left <= H->lastNdx && H->Elem[left]>=H->Elem[largest]) {
            largest = left;
        }
        if (right <= H->lastNdx && H->Elem[right]>=H->Elem[largest]) {
            largest = right;
        }
        // check if value stayed the same and didn't change
        if (largest == ndx) {
           break; 
        }
        swap(&H->Elem[largest], &H->Elem[ndx]);
        ndx = largest;
    }
    return max;
}

/* Returns the largest value without removing it. Returns -1 if empty. */
int peekMax(MaxHeap H) { return isEmpty(H) ? -1 : H.Elem[0]; }