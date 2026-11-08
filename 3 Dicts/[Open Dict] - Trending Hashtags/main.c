#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "trend.h"

int main() {
    Dictionary D;
    int n, i;
    char tag[30];
    List p, top = NULL;
    initDict(D);

    printf("Enter # of post: ");
    scanf("%d", &n);

    printf("Hashtags: \n");
    for (i = 0; i < n; i++) {
        scanf("%s", tag);
        addTag(D, tag);
    }

    printf("Unique hashtags: %d\n", countElems(D));
    displayDict(D);

    /* find the top tag; ties go to the alphabetically smaller tag */
    for (i = 0; i < SIZE; i++)
        for (p = D[i]; p != NULL; p = p->link)
            if (top == NULL || p->count > top->count ||
               (p->count == top->count && strcmp(p->tag, top->tag) < 0))
                top = p;

    if (top == NULL) printf("No trends yet\n");
    else printf("Top trending: %s with %d posts\n", top->tag, top->count);

    return 0;
}