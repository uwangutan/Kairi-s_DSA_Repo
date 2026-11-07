#include <stdio.h>
#include "pizza.h"




/*  TODO: Store in result[] the index of every pizza that is
        SAFE      : has NO topping from allergy   (intersection is empty)
        SATISFYING: has EVERY topping in craving  (craving is a subset of the pizza)
    Keep the menu order. Return how many pizzas were stored.
    Use the bitwise operators (&, |, ~) on the whole Set; no need to loop over the 8 bits.  */

int findPizzas(Set menu[], int n, Set allergy, Set craving, int result[]) {
    /* =========== DELETE ALL CODE BELOW THIS LINE =========== */
    /* PSEUDOCODE:
        - Loop through menu items
        - If pizzas are SAFE and SATISFYING (use formulas)
        - Store the index of the menu item in results[] and return count
    */

    int count = 0;
    for (int i = 0; i < n; i++) {
        if ((menu[i] & allergy)==0 && (menu[i]&craving)==craving) {
            result[count++] = i;
        }
    } 
    return count;
}