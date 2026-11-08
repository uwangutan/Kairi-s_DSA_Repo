#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#define MAX 10

typedef struct node {
    char elem;
    struct node *next;
} Node, *NodePtr;

typedef NodePtr OpenDict[MAX];

int HASH(char key) {
    return (toupper(key) - 'A') % MAX;
}

void displayDict(OpenDict D) {
    printf("\n--- OPEN HASH DICTIONARY (Chaining) ---\n");
    for (int i = 0; i < MAX; i++) {
        printf("[%d]: ", i);
        NodePtr trav = D[i];
        while (trav != NULL) {
            printf("%c -> ", trav->elem);
            trav = trav->next;
        }
        printf("NULL\n");
    }
}


// TODO EXERCISES FOR STUDENTS:

void initDict(OpenDict D) {
	// TODO: Loop through array D and set every bucket pointer to NULL
    for (int i = 0; i < MAX; i++) {
        D[i] = NULL;
    }
}

void insertDict(OpenDict D, char elem) {
	// TODO: Hash elem, malloc a new node, and insert at head of list at D[HASH(elem)]
	// CHALLENGE: Try implementing insert REAR & insert SORTED (most efficient for searching).
    int h = HASH(elem);
    NodePtr newNode = (NodePtr)malloc(sizeof(Node));
    if (newNode != NULL) {
        newNode->elem = elem;
        newNode->next = D[h];   
        D[h] = newNode;         
    }
    
}

void deleteDict(OpenDict D, char elem) {
	// TODO: Search linked list at D[HASH(elem)], unlink target node, and free memory
    NodePtr *trav = &D[HASH(elem)];
    while (*trav != NULL && (*trav)->elem != elem) {
        trav = &(*trav)->next;
    }
    if (*trav != NULL) {
        NodePtr temp = *trav; // *trav: points to node in next field
        *trav = temp->next;   // *trav: next field of current node;
        free(temp);
    }
}

/* !!! DO NOT MODIFY CODE BELOW THIS LINE !!! */
int main() {
    OpenDict D;
    initDict(D);

    printf("\n======= TEST INSERT FUNCTION ========\n");
    printf("Inserting 'A', 'K', 'U' (All hash to index 0)...\n");
    insertDict(D, 'A');
    insertDict(D, 'K');
    insertDict(D, 'U');
    displayDict(D);
    
    printf("\n======= TEST DELETE FUNCTION ========\n");
    printf("Deleting 'K'...\n");
    deleteAllDuplicateDict(D, 'K');
    displayDict(D);

    return 0;
}