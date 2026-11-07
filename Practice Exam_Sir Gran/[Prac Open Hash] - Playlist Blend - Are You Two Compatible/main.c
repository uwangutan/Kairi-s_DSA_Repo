#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include "blend.h"

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

void readPlaylist(Dictionary D, char owner[]) {
    int n, i, got, ids[100];
    initDict(D);
    printf("[%s playlist] How many liked songs? ", owner);
    n = readInt();
    if (n <= 0) return;
    printf("[%s playlist] Enter the %d song IDs separated by spaces (e.g. 1001 1002 1003): ", owner, n);
    got = readIntList(ids, n);
    for (i = 0; i < got; i++) insert(D, ids[i]);
}

int main() {
    Dictionary A, B;
    int score;

    printf("=== PLAYLIST BLEND ===\n");
    printf("Song IDs are 4-digit numbers (1000-9999).\n");
    readPlaylist(A, "Your");
    readPlaylist(B, "Their");

    score = blendScore(A, B);
    printf("\n\n=== BLEND RESULT ===\n");
    if (score >= 0) {
        printf("Blend: %d%%\n", score);
        if (score >= 80)      printf("Certified soulmates\n");
        else if (score >= 50) printf("Vibes match\n");
        else if (score >= 20) printf("Situationship energy\n");
        else                  printf("It's giving strangers\n");
    }
    return 0;
}