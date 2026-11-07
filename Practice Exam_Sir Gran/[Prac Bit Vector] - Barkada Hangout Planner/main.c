#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include "hangout.h"

/* Every input is read as ONE whole line with fgets, then converted.
   This avoids leftover-newline problems when mixing text and numbers,
   and also works with Windows line endings (\r\n).                     */
void readLine(char buf[], int size) {
    if (fgets(buf, size, stdin) == NULL) { buf[0] = '\0'; return; }
    buf[strcspn(buf, "\r\n")] = '\0';
}

int readInt(void) {
    char buf[100];
    readLine(buf, sizeof buf);
    return atoi(buf);
}

/* Reads up to k integers from ONE line into arr[]. Returns how many were read. */
int readIntList(int arr[], int k) {
    char buf[600], *p, *end;
    int j;
    readLine(buf, sizeof buf);
    p = buf;
    for (j = 0; j < k; j++) {
        arr[j] = (int) strtol(p, &end, 10);
        if (p == end) break;
        p = end;
    }
    return j;
}

int main() {
    Set friends[10];
    char name[30];
    int f, k, i, j, got, days[40], start = -1, len;

    printf("=== BARKADA HANGOUT PLANNER ===\n");
    printf("Let's find days in November (1-30) when EVERYONE is free.\n");
    printf("How many friends are in the barkada? ");
    f = readInt();
    for (i = 0; i < f; i++) {
        initSet(friends[i]);
        printf("[Friend %d of %d] Name: ", i + 1, f);
        readLine(name, 30);
        printf("[Friend %d of %d] How many free days does %s have? ", i + 1, f, name);
        k = readInt();
        if (k > 0) {
            printf("[Friend %d of %d] Enter %s's %d free days separated by spaces (e.g. 5 6 7): ", i + 1, f, name, k);
            got = readIntList(days, k);
            for (j = 0; j < got; j++) insert(friends[i], days[j]);
        }
    }

    len = bestHangout(friends, f, &start);
    printf("\n\n=== HANGOUT RESULT ===\n");
    if (len > 0)       printf("Best hangout: Nov %d to Nov %d (%d days)\n", start, start + len - 1, len);
    else if (len == 0) printf("No common free day. GC stays on seen.\n");
    return 0;
}