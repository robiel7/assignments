#include <stdio.h>
#include <string.h>
#include <ctype.h>

int is_palindrome(char*);
void print_palindrome(char*);

int main(){
    
    char palindrome[20],conformation[4];
    int i;
    //take input
    printf("Enter a world or phase (or \\q to quit) : ");
    scanf("%s",palindrome);
    if(!strcmp("\\q",palindrome)){
        printf("Thanks you for using my program!\n");
        return 0;
    }
    //valide conformation
    do{
        printf("Would you like to see if the phrase is palindrome? ");
        scanf("%s",conformation);

        while(conformation[i]) {
            conformation[i] = toupper(conformation[i]);
            i++;
        }

    }while(strcmp(conformation,"YES"));
    print_palindrome(palindrome);
    

    return 0;
}

int is_palindrome(char* palindrome){
    int i,j,k=0, size = strlen(palindrome) +1;
    char reverse[size];
    strcpy(reverse,palindrome);
    
    while (palindrome[k] != '\0'){
        k++;
        j = k-1;
        for ( i = 0; i < k; i++){
            reverse[i] = palindrome[j];
            j--;
        }
        reverse[i] = '\0';
    }
    
    if(strcmp(palindrome,reverse)) return 0;

    return 1;
}
void print_palindrome(char* palindrome){
    if(is_palindrome(palindrome)) {
        printf("The phrase \"%s\" IS a palindrome.\n",palindrome);
    }else{
         printf("The phrase \"%s\" NOT a palindrome.\n",palindrome);
    }
}