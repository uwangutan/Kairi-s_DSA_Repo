#ifndef PIZZA_H
#define PIZZA_H

typedef unsigned char Set;      /* COMPUTER WORD: bit i is 1 means topping i is in the set */

/* bit:            0         1           2           3        4            5         6         7      */
static const char *TOPPING[8] = {"Cheese", "Pepperoni", "Mushroom", "Onion", "Pineapple", "Shrimp", "Peanut", "Chili"};

void initSet(Set *S);
void insert(Set *S, int x);
void deleteElem(Set *S, int x);
int  isMember(Set S, int x);

/* Prints the 8 bits (bit 7 first) and the topping names, e.g. 00010011 {Cheese, Pepperoni, Pineapple} */
void displaySet(Set S);

/* ---------- FUNCTION YOU WILL WRITE ---------- */
int findPizzas(Set menu[], int n, Set allergy, Set craving, int result[]);

#endif