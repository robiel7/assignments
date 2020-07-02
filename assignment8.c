//blackjack
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
    int i,j,k=0,players,decks;
    char file[30];
    char *suit[4] = {"Hearts","Diamonds","Clubs", "Spades"};
    char *faces[13] = {"Ace", "2", "3", "4", "5", "6", "7", "8", "9", "10", "Jack","Queen", "king"};
    FILE *fptr ;

    for ( i = 0; i < 4; i++){
        for ( j = 0; j < 13; j++){
            deck[k].suit = suit[i];
            deck[k].face =faces[j];
            k++;
        }
        
    }
    printf("What is the name of the output file? ");
    scanf("%s",file);
    do{
        printf("How many players are at the table (between 1 and 6) : ");
        scanf("%d",&players);
    }while((players >=6)|| (players <=1));

    do{
        printf("How many decks are in the shoe (between 1 and 6) : ");
        scanf("%d",&decks);
    }while((decks >=6)|| (decks <=1));
    
    fptr = fopen(file,"a");
    fprintf(fptr,"%d players and %d decks",players,decks);
    fclose(fptr);
}