#include <stdio.h>
#include "rank.h"

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
    MinHeap H;
    char name[100][30];
    int pts[100], k, n, i, cut = -1;
    initHeap(&H);

    printf("=== MYTHIC GLORY LEADERBOARD ===\n");
    printf("Only the Top k players this season get the Mythic Glory frame.\n");
    printf("How many players make the Top k? Enter k: ");
    k = readInt();
    printf("How many match results will be posted? ");
    n = readInt();
    for (i = 0; i < n; i++) {
        printf("[Match %d of %d] Player username: ", i + 1, n);
        readLine(name[i], 30);
        printf("[Match %d of %d] Rank points earned: ", i + 1, n);
        pts[i] = readInt();
    }

    printf("\n\n=== LIVE OVERLAY ===\n");
    for (i = 0; i < n; i++) {
        cut = gloryCutoff(&H, k, pts[i]);
        if (cut >= 0)       printf("%s pushed %d pts | Top %d cutoff: %d\n", name[i], pts[i], k, cut);
        else if (cut == -1) printf("%s pushed %d pts | Top %d not full yet\n", name[i], pts[i], k);
    }
    if (cut >= 0) printf("Final Mythic Glory cutoff: %d\n", cut);
    else if (cut == -1) printf("Leaderboard still loading...\n");

    return 0;
}