#ifndef BINGO_H
#define BINGO_H

#include <stdio.h>

#define SIZE 51                 /* numbers 1..50 (index 0 is not used) */

typedef int Set[SIZE];          /* BIT VECTOR: S[x] == 1 means x is in the set */

void initSet(Set S);

void insert(Set S, int x);

void deleteElem(Set S, int x);

int isMember(Set S, int x);

/* Prints the set, e.g. {3, 7, 12} */
void displaySet(Set S);

/* ---------- FUNCTION YOU WILL WRITE ---------- */
int bingoWinTurn(Set card, int calls[], int n);

#endif