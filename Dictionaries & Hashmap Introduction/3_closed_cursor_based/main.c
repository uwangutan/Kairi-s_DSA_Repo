#include <stdio.h>
#include <ctype.h>

#define MAX 10
#define EMPTY '?'
#define DELETED '!'

typedef struct {
    char data;
    int next;
} VirtualNode;

typedef struct {
    VirtualNode table[MAX]; // Prime Area: indices 0..5, Synonym Area: indices 6..9
    int avail;             // Points to head of free synonym list
} CursorDict;

int HASH(char key) {
    return (toupper(key) - 'A') % 6; // Hash directly into prime area (0..5)
}

void displayDict(CursorDict D) {
    printf("\n--- CLOSED HASH DICTIONARY (Cursor-Based / Synonym Area) ---\n");
    printf("Avail Head Index: %d\n", D.avail);
    printf("%5s | %-5s | %5s\n", "IDX", "DATA", "NEXT");
    printf("%5s - %5s - %5s\n", "----", "----", "----");
    for (int i = 0; i < MAX; i++) {
        printf(" %5d  |  %-5c  |  %5d\n", i, D.table[i].data, D.table[i].next);
    }
}

// TODO EXERCISES FOR STUDENTS:

void initDict(CursorDict *D) {
    // TODO: 
    // 1. Prime area (0..5): data = EMPTY, next = -1
    // 2. Synonym area (6..9): link next pointers sequentially to form free list
    // 3. Set D->avail = 6
    /* =========== DELETE CODE BELOW THIS LINE =========== */
    for (int i = 0; i < 6; i++) {
        D->table[i].data = EMPTY;
        D->table[i].next = -1;
    }
    for (int i = 6; i < MAX; i++) {
        D->table[i].data = EMPTY;
        if (i != MAX - 1) {
            D->table[i].next = i + 1;
        }
        else {
            D->table[i].next = -1;  
        }
    }
    D->avail = 6;
}

void insertDict(CursorDict *D, char elem) {
    // TODO: 
    // 1. Compute H = HASH(elem)
    // 2. If table[H] is EMPTY or DELETED, store elem directly at H
    // 3. Else, pull index from D->avail, store elem, and append to table[H].next chain
    /* =========== DELETE CODE BELOW THIS LINE =========== */
    int H = HASH(elem);
    if (D->table[H].data == EMPTY || D->table[H].data == DELETED) {
        D->table[H].data = elem;
    }
    else {
        int avail = D->avail;
        if (avail == -1) { return; }          // no free synonym slot

        D->table[avail].data = elem;
        D->avail = D->table[avail].next;  // advance free list

        D->table[avail].next = D->table[H].next;  // insert after prime node
        D->table[H].next = avail;
    }
}

void deleteDict(CursorDict *D, char elem) {
    // TODO: Search key in prime slot or linked synonym chain. Unlink node and recycle index to avail. 
    /* =========== DELETE CODE BELOW THIS LINE =========== */
        int H = HASH(elem);

    // Case 1: element is in the prime slot
    if (D->table[H].data == elem) {
        int first = D->table[H].next;
        if (first == -1) {
            D->table[H].data = EMPTY;            // no synonyms
        } else {
            // pull first synonym into prime slot, recycle its node
            D->table[H].data = D->table[first].data;
            D->table[H].next = D->table[first].next;
            D->table[first].data = EMPTY;
            D->table[first].next = D->avail;
            D->avail = first;
        }
        return;
    }

    // Case 2: search the synonym chain
    int prev = H;
    int curr = D->table[H].next;
    while (curr != -1 && D->table[curr].data != elem) {
        prev = curr;
        curr = D->table[curr].next;
    }
    if (D->table[curr].data == elem) {                            // found
        D->table[prev].next = D->table[curr].next;
        D->table[curr].data = EMPTY;
        D->table[curr].next = D->avail;
        D->avail = curr;
    }
}

/* !!! DO NOT MODIFY CODE BELOW THIS LINE !!! */
int main() {
    CursorDict D;
    initDict(&D);

    printf("Inserting 'A', 'G', 'M' (All hash to Prime Index 0)...\n");
    insertDict(&D, 'A');
    insertDict(&D, 'G');
    insertDict(&D, 'M');
    displayDict(D);

    printf("Deleting 'G'...\n");
    deleteDict(&D, 'G');
    displayDict(D);

    return 0;
}