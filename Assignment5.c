#include <stdio.h>
#include <string.h>

void take_input(char*,char);
float convert_temperature(char*,int);

int main(){
    char temp;
    char *temperature[]={"Fahrenheit","Celsuis"};
    do {
        printf("Would you like to convert from Fahrenheit to Celsuis (F) or Celsuis to Fahrenheit(C)? ");
        scanf("%1c",&temp);
    } while ((temp != 'C') &&(temp != 'F'));
    
    if(temp =='F')take_input(temperature[0],temp);
    if(temp =='C')take_input(temperature[1],temp);
}
void take_input(char *temp,char t){
    
    int lower,higher,step,i;
    char t2 ;
    if(t != 'F') t2 = 'F';else t2 = 'C';
    
    printf("Enter the lower %s temperature: ",temp);
    scanf("%d",&lower);
    printf("Enter the higher %s temperature: ",temp);
    scanf("%d",&higher);
    printf("Enter the increment temperature change: ");
    scanf("%d",&step);

    if((lower >= higher) || ((higher -lower) < step || 0 >= step)){
        printf("Invalid input\n");
        return ;
    }

    for ( i = lower; i <= higher; i= i+step){
        printf("%d%c = %.2f%c\n",i, t, convert_temperature(temp,i),t2);
    }
}
float convert_temperature(char* temp,int i){
    return strcmp(temp,"Fahrenheit") == 0 ? ((i -32.0)*5/9):((i*9.0/5)+32);
}