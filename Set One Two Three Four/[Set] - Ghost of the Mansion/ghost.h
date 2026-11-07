#ifndef GHOST_H
#define GHOST_H

typedef unsigned char Set;      /* COMPUTER WORD: bit i is 1 means room i's light is ON */

/* bit:          0        1          2          3         4       5         6        7      */
static const char *ROOM[8] = {"Attic", "Library", "Kitchen", "Cellar", "Hall", "Chapel", "Study", "Tower"};

void initSet(Set *S);
void insert(Set *S, int x);
void deleteElem(Set *S, int x);
int  isMember(Set S, int x);

/* Prints the 8 bits (bit 7 first) and the room names, e.g. 00000101 {Attic, Kitchen} */
void displaySet(Set S);

/* ---------- FUNCTION YOU WILL WRITE (in main.c) ---------- */
int banishGhost(Set *lights, Set switches[], int presses[], int p);

#endif