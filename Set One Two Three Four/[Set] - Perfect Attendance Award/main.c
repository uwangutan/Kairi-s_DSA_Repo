#include <stdio.h>
#include "attend.h"

int main() {
    Set days[20], perfect, never;
    int d, k, i, j, x;

    printf("Number of days: ");
    scanf("%d", &d);

    for (i = 0; i < d; i++) {
        initSet(days[i]);
        printf("Day %d number of students: ", i+1);
        scanf("%d", &k);
        printf("Enter students od day %d: ", i+1);
        for (j = 0; j < k; j++) { scanf("%d", &x); insert(days[i], x); }
    }
    /* filled with 1s on purpose: your function must build both sets from scratch */
    for (i = 0; i < SIZE; i++) { perfect[i] = 1; never[i] = 1; }

    attendanceReport(days, d, perfect, never);
    printf("Perfect attendance: "); displaySet(perfect); printf("\n");
    printf("Never attended: ");     displaySet(never);   printf("\n");

    return 0;
}