#ifndef HANGOUT_H
#define HANGOUT_H

#define SIZE 31                 /* days 1..30 of November (index 0 is not used) */

typedef int Set[SIZE];          /* BIT VECTOR: S[d] == 1 means day d is free */

void initSet(Set S);

void insert(Set S, int d);
int  isMember(Set S, int d);

/* ---------- FUNCTION YOU WILL WRITE ---------- */
int bestHangout(Set friends[], int f, int *start);

#endif