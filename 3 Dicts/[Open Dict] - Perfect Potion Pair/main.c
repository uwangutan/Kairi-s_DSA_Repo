#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "potion.h"

int main() {
    Dictionary D;
    int n, target, i, first, second, found;
    int potions[100];
    initDict(D);

    printf("Enter # of target and # of potion powers: ");
    scanf("%d %d", &n, &target);

    printf("Enter potion powers: ");
    for (i = 0; i < n; i++) scanf("%d", &potions[i]);

    found = findPair(D, potions, n, target, &first, &second);

    if (found == 1) printf("Perfect brew: %d + %d = %d\n", first, second, target);
    else if (found == 0) printf("No perfect brew possible\n");

    return 0;
}