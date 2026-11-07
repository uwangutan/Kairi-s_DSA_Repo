#include <stdio.h>
#include "ghost.h"

/* ---------- DO NOT EDIT BELOW THIS LINE ---------- */
void readSet(Set *S) {
    int k, j, x;
    initSet(S);

    printf("Enter count: ");
    scanf("%d", &k);
    printf("State: ");
    for (j = 0; j < k; j++) { scanf("%d", &x); insert(S, x); }
}

int main() {
    Set lights, switches[10];
    int m, p, i, used, presses[50];

    printf("ROOM STATE\n");
    readSet(&lights);

    printf("Number of switches: ");
    scanf("%d", &m);

    printf("ROOM that SWITCHES\n");
    for (i = 0; i < m; i++) readSet(&switches[i]);

    printf("Number of press: ");
    scanf("%d", &p);

    printf("Switch numbers 1 to switches(m): ");
    for (i = 0; i < p; i++) scanf("%d", &presses[i]);

    printf("\n\nSTATUS REPORT\n");
    printf("Start: "); displaySet(lights); printf("\n");
    used = banishGhost(&lights, switches, presses, p);
    if (used >= 0) printf("Ghost banished after %d presses!\n", used);
    else if (used == -1) printf("The ghost stays...\n");
    printf("Final: "); displaySet(lights); printf("\n");
    return 0;
}