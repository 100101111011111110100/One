#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <windows.h>

struct bitCard {
    char face[15];
    char suit[10];
    int color;
    // unsigned face :4;
    // unsigned suit :2;
    // unsigned color:1;
};
typedef struct bitCard Card;

void fillDeck(Card *const wDeck);
void print(const Card *const wDeck);
void shuf_1(const Card *const wDeck, int *o, int size);
int p_1(const Card *const wDeck, int *o, int size);
int main() {
    int order[52] = {0};
    int i = 5;
    srand(time(NULL));
    Card deck[52];
    fillDeck(deck);
    // print(deck);
    shuf_1(deck, order, 52);
    /*{
        for (size_t i = 0; i < 52; i++){
            printf("order[%d] ==%d\n",i,order[i]);

        }

    }*/
    i += p_1(deck, order, i);
    // print(deck);
    // print(deck);
    return 0;
}

void fillDeck(Card *const wDeck) {
    char *f[] = {"Ace",   "Deuce", "Three", "Four", "Five",  "Six", "Seven",
                 "Eight", "Nine",  "Ten",   "Jack", "Queen", "King"};
    char *s[] = {"Hearts", "Diamonds", "Clubs", "Spades"};
    for (size_t i = 0; i < 52; i++) {
        strcpy(wDeck[i].face, f[i % 13]);
        // wDeck[i].face=*f[i%13];
        strcpy(wDeck[i].suit, s[(i / 13) % 4]);
        // wDeck[i].suit=*s[(i/13)%4];
        wDeck[i].color = i / 26;
    }
}

void shuf_1(const Card *const wDeck, int *o, int size) {
    int chek_shuf(int *j, int *o, int *size);
    int j = 0;
    for (int i = 0; i < size; i++) {
        j = (rand() + 1) % size;
        // printf("j is %d\n",j);
        if (chek_shuf(&j, o, &i)) {
            i--;
            continue;
        }
        *(o + i) = j;
    }
}

int chek_shuf(int *j, int *o, int *size) {
    for (size_t i = 0; i < *size; i++) {
        if (*j == *(o + i)) return 1;
    }
    return 0;
}
/*void deal(const Card *const wDeck){


}*/

void print(const Card *const wDeck) {
    for (size_t i = 0; i < 52; i++) {
        printf("%10s %s %-10s || %s\n", wDeck[i].face, "of", wDeck[i].suit,
               wDeck[i].color == 0 ? "Red" : "Black");
    }
}

int p_1(const Card *const wDeck, int *o, int size) {
    int i = 0;
    for (; i < size; i++) {
        if (wDeck[*(o + i)].color == 0) {
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 12);
        } else {
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0f | 0);
        }
        printf("%10s %s %-10s \n", wDeck[*(o + i)].face, "of", wDeck[*(o + i)].suit);
    }
    return i;
}