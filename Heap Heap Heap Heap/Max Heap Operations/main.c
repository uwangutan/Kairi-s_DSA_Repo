#include <stdio.h>
#include <math.h>
#define MAX 20

typedef struct {
    int Elem[MAX];
    int lastNdx;            /* index of last element, -1 if empty */
} ListHeap;

/* ============================================================================
   MASTER POOL (50 NUMBERS)
   Includes duplicates, zero and negative numbers.
   ============================================================================ */
static const int MASTER_DATA[50] = {
    /* 1 to 10  */  45, 12, 78,  3, 56, 89, 23, 67, 34, 91,
    /* 11 to 20 */  15, 72,  8, 60, 41, 99, 27, 50,  5, 83,
    /* 21 to 30 */  38, 64, 19, 76, 30, 55, 55, -7,  0, 42,
    /* 31 to 40 */  42, 18, -15, 70, 9, 88, -3, 61, 25, 25,
    /* 41 to 50 */ 100, -20, 47, 13, 36, 2, 95, -1, 58, 74
};

void initHeap(ListHeap *H) {
    /* =========== DELETE CODE BELOW THIS LINE =========== */
    /* TODO: Set lastNdx to -1 */
    H->lastNdx=-1;
}

void swap(int *a, int *b) {
    /* =========== DELETE CODE BELOW THIS LINE =========== */
    /* TODO: Swap two pointers */
    int temp = *a;
    *a = *b;
    *b = temp;
}

int isEmpty(ListHeap H) {
    /* =========== DELETE CODE BELOW THIS LINE =========== */
    /* TODO: Return -1 if heap is EMPTY (lastNdx = -1)*/
    if(H.lastNdx <= -1) {
        return -1;
    }
    return 0;
}

int isFull(ListHeap H) {
    /* =========== DELETE CODE BELOW THIS LINE =========== */
    /* TODO: Return -1 if heap is FULL (lastNdx > SIZE - 1)*/
    if(H.lastNdx >= 19) {
        return -1;
    }
    return 0;
}

void insert(ListHeap *H, int x) {
    /* =========== DELETE CODE BELOW THIS LINE =========== */
    /* TODO: Bubble up value x. Swap child with parent while child node is larger */
    if(isFull(*H)) { printf("Heap is full: %d not inserted\n", x); }
    else {
        H->lastNdx++;
        int n = H->lastNdx;
        H->Elem[n] = x;
        
        while (x > H->Elem[(n-1)/2] && n > 0) {
            swap(&(H->Elem[n]), &(H->Elem[(n-1)/2]));
            n = (n - 1)/2;
        }
    }
}

void maxHeapify(ListHeap *H, int ndx) {
    /* =========== DELETE CODE BELOW THIS LINE =========== */
    /* TODO: Percolate down value x. Swap parent with child while parent is smaller */
    int left, right, larger;

    while (1) {
        left = 2 * ndx + 1;
        right = 2 * ndx + 2;

        if (left > H->lastNdx) {
            break;
        }

        larger = left;

        if (right <= H->lastNdx &&
            H->Elem[right] > H->Elem[left]) {
            larger = right;
        }

        if (H->Elem[ndx] >= H->Elem[larger]) {
            break;
        }

        swap(&H->Elem[ndx], &H->Elem[larger]);
        ndx = larger;
    }
}

int deleteMax(ListHeap *H) {
    /* =========== DELETE CODE BELOW THIS LINE =========== */
    /* TODO: To delete, set root H[0] = to the last element and call maxHeapify on the root */
    if (isEmpty(*H)) { printf("Heap is empty\n"); return -1; }
    int deleted = H->Elem[0];
    H->Elem[0] = H->Elem[H->lastNdx];
    maxHeapify(H, 0);
    H->lastNdx--;
    
    printf("Deleted: %d\n", deleted);
    return 0; 
}

/* !!! DO NOT TOUCH ANY OF THE CODE BELOW THIS AREA !!! */

/* ============================================================================
   POPULATE FUNCTION
   order 0 = all records in sequence (1st to 50th)
   order 1 = odd records  (1st, 3rd, 5th ...)
   order 2 = even records (2nd, 4th, 6th ...)
   order 3 = 1st half     (1st to 25th)
   order 4 = 2nd half     (26th to 50th)
   ============================================================================ */
void populateData(ListHeap *H, int count, int order) {
    int start = 0, end = 50, step = 1, loaded = 0, i;

    if (order == 1)      { start = 0;  step = 2; }
    else if (order == 2) { start = 1;  step = 2; }
    else if (order == 3) { start = 0;  end = 25; }
    else if (order == 4) { start = 25; end = 50; }

    for (i = start; i < end && loaded < count; i += step) {
        insert(H, MASTER_DATA[i]);
        loaded++;
    }
}

void display(ListHeap H, char label[]) {
    int i;
    printf("%s:", label);
    if (isEmpty(H)) { printf(" (empty)\n"); return; }
    for (i = 0; i <= H.lastNdx; i++) printf(" %d", H.Elem[i]);
    printf("\n");
}
int main() {
    ListHeap H;
    int count, order, del, i;
    initHeap(&H);

    printf("Enter number of data to insert and sequence: ");
    scanf("%d %d", &count, &order);
    printf("Enter number of data to delete: ");
    scanf("%d", &del);

    populateData(&H, count, order);
    display(H, "Initial Heap");

    for (i = 0; i < del; i++) deleteMax(&H);
    display(H, "Final Heap");
    printf("Size: %d\n", H.lastNdx + 1);
    return 0;
}