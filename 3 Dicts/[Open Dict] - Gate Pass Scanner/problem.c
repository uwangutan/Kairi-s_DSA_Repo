#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "gate.h"

/*  TODO: Process one scan.
    cmd is "IN" or "OUT".
      IN  : if id is already inside -> print "DENIED: <id> is already inside"
            else insert it          -> print "WELCOME: <id>"
      OUT : if id is inside         -> delete it, print "GOODBYE: <id>"
            else                    -> print "ALERT: <id> is not inside"
    Available: isMember(D, x), insert(D, x), deleteElem(D, x)            */

void processScan(Dictionary D, char cmd[], int id) {
    /* =========== DELETE ALL CODE BELOW THIS LINE =========== */
    if (strcmp(cmd, "IN")==0) {
        if (isMember(D, id)) {
            printf("DENIED: %d is already inside\n", id);
        }
        else {
            insert(D, id);
            printf("WELCOME: %d\n", id);
        }
    }
    else {
        if (isMember(D, id)) {
            printf("GOODBYE: %d\n", id);
            deleteElem(D, id);
        }
        else {
            printf("ALERT: %d is not inside\n", id);
        }
    }
}