#include <stdio.h>
#include "bingo.h"

int main() {
    Set card;
    int k, n, i, x, turn;
    int calls[100];
    initSet(card);

    printf("Enter number of cards: ");
    scanf("%d", &k);

    printf("Card numbers: ");
    for (i = 0; i < k; i++) { scanf("%d", &x); insert(card, x); }

    printf("Number of calls: ");
    scanf("%d", &n);

    printf("Numbers called: ");
    for (i = 0; i < n; i++) scanf("%d", &calls[i]);

    printf("Card: "); displaySet(card); printf("\n");

    turn = bingoWinTurn(card, calls, n);
    if (turn > 0) printf("BINGO! on call #%d (number %d)\n", turn, calls[turn - 1]);
    else if (turn == 0) printf("No BINGO after %d calls\n", n);

    return 0;
}