#include <stdio.h>
#include "bridge.h"

int main() {
    MinHeap H;
    int n, i, p;
    initHeap(&H);

    printf("N (number of planks): ");
    scanf("%d", &n);

    printf("N plank lengths: ");
    for (i = 0; i < n; i++) {
        scanf("%d", &p); insert(&H, p);
    }

    printf("\n");
    printf("Minimum gold spent: %d\n", minBridgeCost(&H));

    return 0;
}