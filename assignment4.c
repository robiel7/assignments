#include <stdio.h>

void print_largest_divid(int ,int );
void print_largest_factor(int number,int i);
int is_prime(int number);
int factorize(int);
void print_largest_prime(int input,int prime);
void prime_factor(int number,int divides);
void print_prime(int number);

int main(){
    int number;
    do {
        printf("Please enter a positive integer: ");
        scanf("%d",&number);
        if(number == -1 ){
            printf("Thank you for using my program.\n");
            return 0;
        }
        if(number < 0) {
            printf("%d is not a positive integer\n",number);
            return 0;
        }
    }while (number < 0);
    print_prime(number);
    
}

void print_largest_divid(int number,int i){
   printf("Largest number that divides %d evenly is %d\n", number,i);
}

void print_largest_factor(int number,int i){
    int factor = number /i;
   printf("Largest integer factor set = %d * %d\n",factor,i);
}

int is_prime(int number){
    int divides;   
    for ( divides = number/2; divides >=2; divides--){
        if(number % divides == 0){
            return divides;
        }
    } 
    return 0;
}

int largest_prime(int number,int divides){
    int largest_prime;
    do{      
        if(divides != 0) largest_prime = divides;    
        divides = is_prime(divides);      
    }while(divides);
    return largest_prime;
}

void print_largest_prime(int input,int prime){
    printf("Largest prime number that divides %d evenly is %d\n",input, prime);
}

int factorize(int number){
    int i;  
    for ( i = 2; i < number; i++){
        if(number % i == 0){
            return i;
        }
    } 
    return number;
}

void prime_factor(int number,int divides){
    printf("Prime factors = %d",number/divides); 
    do{       
        printf(" * %d",factorize(divides));   
        divides = is_prime(divides);      
    }while(divides);

    printf("\n");
}

void print_prime(int number){
    int divides = is_prime(number) ;    
    if(divides != 0){
        printf("COMPOSITE\n");
        print_largest_divid(number,divides);
        print_largest_prime(number,largest_prime(number,divides));
        prime_factor(number,divides);
        print_largest_factor(number,divides);
    }else{
        printf("PRIME\n");
    }      
}

