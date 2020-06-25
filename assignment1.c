#include <stdio.h>

int main(){
    float resultat1, resultat2, resultat3;
    resultat1 = 16+34.2*35-39.2/2*45;
    resultat2 = 29*23-34/13+34/(23*13-12);
    resultat3 = (29-97*(72-9/3)+31/12)%14;
    printf("16 + 34.2 * 35 - 39.2 / 2 * 45 = %f\n",resultat1);
    printf("29 * 23 - 34 / 13 + 34 / (23 * 13 - 12) = %f\n",resultat2);
    printf("(29 - 97 * (72 - 9 / 3) + 31 / 12) %c 14 = %f\n",'%',resultat3);
}