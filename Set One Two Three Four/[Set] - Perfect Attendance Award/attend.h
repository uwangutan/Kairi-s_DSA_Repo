#ifndef ATTEND_H
#define ATTEND_H

#include <stdio.h>

#define SIZE 16                 /* students are numbered 0..15 */

typedef int Set[SIZE];          /* BIT VECTOR: S[x] == 1 means student x is in the set */

void initSet(Set S);

void insert(Set S, int x);

int isMember(Set S, int x);

/* Prints the set, e.g. {0, 4, 15} */
void displaySet(Set S);

/* ---------- FUNCTION YOU WILL WRITE ---------- */
void attendanceReport(Set days[], int d, Set perfect, Set never);

#endif