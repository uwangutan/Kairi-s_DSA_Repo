#include <stdio.h>
#include "golem.h"

/*  TODO: Return the weight of the last surviving golem, or 0 if none.
    Available: size(*H), isEmpty(*H), deleteMax(H), insert(H, x), peekMax(*H) */
int lastGolem(MaxHeap *H) {
    /* =========== DELETE ALL CODE BELOW THIS LINE =========== */
    if (isEmpty(*H)) { return 0; }
    
    while (H->lastNdx!=0) {
        // delete first largest
        int a = peekMax(*H);
        deleteMax(H);
        
        // delete second largest
        int b = (peekMax(*H) > 0) ? peekMax(*H) : 0;
        deleteMax(H);
        
        // insert difference
        int x = a - b;
        if (x) { insert(H, x); }
        // need to return weight not just insert
    }
    return (H->Elem[H->lastNdx] > 0) ? H->Elem[H->lastNdx] : 0;
}