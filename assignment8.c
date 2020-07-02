#include <stdio.h>
#include <time.h>
#include <stdlib.h>

typedef struct {
    char *face;
    char *suit;
}card;

void shuffle(card deck[52]){
    int i,random;
    card temp;
    srand(time(NULL));
    for(i = 0; i < 52;i++){
        random = rand()%52;
        temp = deck[i];
        deck[i] = deck[random];
        deck[random] = temp;

    }
}

void print_deck (card deck[52]){
    int i;
    for(i = 0; i < 52;i++){
        printf("%s of %s\n",deck[i].face, deck[i].suit);
    }
    printf("-----\n");
}

int main(){
    card deck[52];
    int i,j,k=0;
    char *suit[4] = {"Hearts","Diamonds","Clubs", "Spades"};
    char *faces[13] = {"Ace", "2", "3", "4", "5", "6", "7", "8", "9", "10", "Jack","Queen", "king"};

    for ( i = 0; i < 4; i++){
        for ( j = 0; j < 13; j++){
            deck[k].suit = suit[i];
            deck[k].face =faces[j];
            k++;
        }
        
    }
    print_deck(deck);
    shuffle(deck);
    print_deck(deck);
}