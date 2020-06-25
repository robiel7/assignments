#include <stdio.h>
//COMPOSITE PRIME is not a positive integer
int main(){
    int number,i;
    do {
        printf("Please enter a positive integer: ");
        scanf("%d",&number);
        if(number == -1 ){
            printf("Thank you for using my program.\n");
            return 0;
        }
        if(number < 0) {
            printf("%d is not a positive integer\n",number);
            continue;
        }
    }while (number < 0);

    for ( i = number/2; i >=2; i--){
        if(number % i == 0){
             printf("%d COMPOSITE %d\n", number,i);
             return 0;
        }
    }
    printf("%d PRIMES\n",number);
}