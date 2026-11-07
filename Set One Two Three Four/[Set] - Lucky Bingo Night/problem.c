#include <stdio.h>
#include "bingo.h"

/*  TODO: Return the call number (1, 2, 3, ...) when the card is complete,
    or 0 if the card is never completed.
    Steps:
      1. Make a Set "called" and initialize it.
      2. For each call: insert the number into "called".
      3. Check if card is a SUBSET of called:
         every x with card[x] == 1 must also have called[x] == 1.
      4. If yes, return the current call number.
    Available: initSet(S), insert(S, x), isMember(S, x)                    */

int bingoWinTurn(Set card, int calls[], int n) {
    /* =========== DELETE ALL CODE BELOW THIS LINE =========== */
    /* PSEUDOCODE:
        - All elements of card must be called to win bingo
        - New number is called -> loop to compare card and called array again
        - Formula to find if an element is in A and NOT in B = A && !B
        - For as long as not all elements of A are in B, keep calling "n" new numbers
    */

    Set called;
    initSet(called);
    
    for (int i = 0; i < n; i++) {
        insert(called, calls[i]);
        
        // use a flag to remember whether a difference in the sets was detected
        int flag = 1;
        for (int j = 0; j < SIZE; j++) {
            // condition checks if a number on the CARD is NOT IN the called
            if (card[j] && !called[j]) {
                flag = 0; // reset to 0 if an element of card is not in called.
            }
        }
        
        // means every element of card was found in called
        if(flag==1) {
            return i + 1;
        }
    }
    return 0;
}