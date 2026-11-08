#include <stdio.h>
#include <ctype.h>

#define MAX 10
#define EMPTY '?'
#define DELETED '!'

typedef char LinearDict[MAX];

int HASH(char key) {
    return (toupper(key) - 'A') % MAX;
}

void displayDict(LinearDict D) {
    printf("\n--- CLOSED HASH DICTIONARY (Linear Probing) ---\n");
    printf("%5s | %-5s\n", "IDX", "DATA");
    printf("%5s | %5s\n", "----", "----");
    for (int i = 0; i < MAX; i++) {
        printf(" %5d  |  %-5c\n", i, D[i]);
    }
}

// TODO EXERCISES FOR STUDENTS:

void initDict(LinearDict D) {
    // TODO: Loop through array and initialize all slots to EMPTY ('?')
    /* =========== DELETE CODE BELOW THIS LINE =========== */
    for (int i = 0; i < MAX; i++) {
        D[i] = EMPTY;
    }
}

void insertDict(LinearDict D, char elem) {
    // TODO: Use probing formula (HASH(elem) + i) % MAX to find first EMPTY or DELETED slot
    /* =========== DELETE CODE BELOW THIS LINE =========== */
    for (int i = 0; i < MAX; i++) {
        int ndx = (HASH(elem) + i) % MAX;
        if (D[ndx] == EMPTY || D[ndx] == DELETED) {
            D[ndx] = elem;
            break;
        }
    }
}

void deleteDict(LinearDict D, char elem) {
    // TODO: Search sequentially starting at HASH(elem) until element is found or EMPTY hit
    // Mark target slot as DELETED ('!')
    /* =========== DELETE CODE BELOW THIS LINE =========== */
    int ndx;
    for (int i = 0; i < MAX; i++) {
        ndx = (HASH(elem) + i) % MAX;
        if (D[ndx] == elem || D[ndx] == EMPTY) {
            D[ndx] = (D[ndx] == EMPTY) ? EMPTY : DELETED;  // If elem is empty: leave it as is. Else, mark deleted.
            break;
        }
    } 
}

/* !!! DO NOT MODIFY CODE BELOW THIS LINE !!! */
int main() {
    LinearDict D;
    initDict(D);

    printf("Inserting 'A', 'K', 'U' (All hash to index 0)...\n");
    insertDict(D, 'A');
    insertDict(D, 'K');
    insertDict(D, 'U');
    displayDict(D);

    printf("Deleting 'K'...\n");
    deleteDict(D, 'K');
    displayDict(D);

    return 0;
}