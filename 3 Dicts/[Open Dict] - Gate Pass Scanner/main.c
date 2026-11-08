#include <stdio.h>
#include "gate.h"

int main() {
    Dictionary D;
    int n, i, id[50];
    char cmd[50][5];

    initDict(D);

    printf("Enter number of scans: ");
    scanf("%d", &n);

    printf("IDs [IN <id> or OUT <id>]:\n");
    for (i = 0; i < n; i++) {
        scanf("%s %d", cmd[i], &id[i]);
    }

    printf("\n\n");
    for (i = 0; i < n; i++) {
        processScan(D, cmd[i], id[i]);
    }

    printf("People inside: %d\n", countElems(D));
    displayDict(D);

    return 0;
}