#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "pizza.h"

/* Reads ONE whole line into buf (removes \n and \r).
   Using fgets for every input avoids leftover-newline problems
   when mixing text and numbers.                               */
void readLine(char buf[], int size) {
    if (fgets(buf, size, stdin) == NULL) { buf[0] = '\0'; return; }
    buf[strcspn(buf, "\r\n")] = '\0';
}

int readInt(void) {
    char buf[100];
    readLine(buf, sizeof buf);
    return atoi(buf);
}

/* Asks for a topping count, then (if > 0) a line of topping numbers. */
void readSet(Set *S, char label[]) {
    char buf[200], *p, *end;
    int k, j, x;
    initSet(S);
    printf("%s - number of toppings: ", label);
    k = readInt();
    if (k <= 0) return;
    printf("%s - topping numbers (0-7): ", label);
    readLine(buf, sizeof buf);
    p = buf;
    for (j = 0; j < k; j++) {
        x = (int) strtol(p, &end, 10);
        if (p == end) break;                     /* no more numbers on the line */
        if (x >= 0 && x <= 7) insert(S, x);
        p = end;
    }
}

int main() {
    Set menu[20], allergy, craving;
    char name[20][30], label[50];
    int n, i, count, result[20];

    printf("TOPPINGS: 0-Cheese 1-Pepperoni 2-Mushroom 3-Onion 4-Pineapple 5-Shrimp 6-Peanut 7-Chili\n");
    printf("Enter number of pizzas: ");
    n = readInt();
    for (i = 0; i < n; i++) {
        printf("Pizza #%d name: ", i + 1);
        readLine(name[i], 30);
        sprintf(label, "Pizza #%d", i + 1);
        readSet(&menu[i], label);
    }
    readSet(&allergy, "Allergy");
    readSet(&craving, "Craving");

    printf("\n\n=== KIOSK RESULT ===\n");
    printf("Allergy: "); displaySet(allergy); printf("\n");
    printf("Craving: "); displaySet(craving); printf("\n");

    count = findPizzas(menu, n, allergy, craving, result);
    if (count >= 0) {
        printf("Matches: %d\n", count);
        for (i = 0; i < count; i++) {
            printf("- %s ", name[result[i]]);
            displaySet(menu[result[i]]);
            printf("\n");
        }
        if (count == 0) printf("Sorry, no pizza for you!\n");
    }
    return 0;
}