#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main(){
    
    char palindrome[20],conformation[4];
    int i;
    printf("Enter a world or phase (or \\q to quit) : ");
    scanf("%s",palindrome);
    if(!strcmp("\\q",palindrome)){
        printf("Thanks you for using my program!\n");
        return 0;
    }
    do{
        printf("Would you like to see if the phrase is palindrome? ");
        scanf("%s",conformation);

        while(conformation[i]) {
            conformation[i] = toupper(conformation[i]);
            i++;
        }
        printf("%s\n",conformation);

    }while(strcmp(conformation,"YES"));
    return 0;
}