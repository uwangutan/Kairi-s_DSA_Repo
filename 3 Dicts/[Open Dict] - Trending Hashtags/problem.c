#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "trend.h"

/*  TODO: Record one post of the given tag.
    1. Go to bucket D[hash(tag)].
    2. Walk the list. If a node has the same tag (use strcmp), add 1 to its count and stop.
    3. If the tag is not in the list, create a new node (tag copied with strcpy, count = 1)
       and attach it at the END of the list.
    Tags are case-sensitive: "#USC" and "#usc" are different tags.         */

void addTag(Dictionary D, char tag[]) {
    /* =========== DELETE ALL CODE BELOW THIS LINE =========== */
    int h = hash(tag);
    List *trav = &D[h];
    int found = 0;
    
    while (*trav) {
        if (strcmp((*trav)->tag, tag)==0) {
            (*trav)->count++;
            found = 1;
            break;
        }
        trav = &((*trav)->link);
    }
  
    if(!found) {
        List newTag = malloc(sizeof(struct node));
        strcpy(newTag->tag, tag);
        newTag->link = *trav;
        *trav = newTag;
        newTag->count = 1;
    }
}