#include <stdio.h>

#define PI 3.141592
int main(){
    char shape;
    int base,height,side,width,raduis,area;
    printf("Enter a shape (t, s, r, c,): ");
    scanf("%c",&shape);
    switch(shape){
        case 't':
            printf("Enter the base of the traingle: ");
            scanf("%d",&base);
            printf("Enter the height of the traingle: ");
            scanf("%d",&height);
            area = base*height/2;
            printf("The area of the triangle is %d.\n",area);
            break;
        case 's':
            printf("Enter the side of the square: ");
            scanf("%d",&side);
            area = side*side;
            printf("The area of the square is %d.\n",area);
            break;
        case 'r':
            printf("Enter the height of the rectangle: ");
            scanf("%d",&height);
            printf("Enter the width of the rectangle: ");
            scanf("%d",&width);
            area = width*height;
            printf("The area of the rectangle is %d.\n",area);
            break;
        case 'c':
            printf("Enter the raduis of the circle: ");
            scanf("%d",&raduis);
            float area = raduis*raduis * PI;
            printf("The area of the circle is %.2f.\n",area); 
            break;
        default:
            printf("You don't enter the right shape.\n");
            break;
    }
}
