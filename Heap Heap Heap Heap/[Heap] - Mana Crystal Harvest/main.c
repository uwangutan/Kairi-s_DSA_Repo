#include <stdio.h>
#include "mana.h"

int main() {
    MaxHeap H;
    int n, k, i, m;
    initHeap(&H);

    printf("Number of crystals and number of turns: ");
    scanf("%d %d", &n, &k);

    printf("N crystal mana values: ");
    for (i = 0; i < n; i++) {
        scanf("%d", &m);
        insert(&H, m);
    }

    printf("Total mana harvested: %d\n", harvestMana(&H, k));

    return 0;
}