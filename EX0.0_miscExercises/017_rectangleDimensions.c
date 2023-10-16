#include <stdio.h>

int main (){

    int x1,y1,x2,y2;
    printf ("Enter the x,y coordinate of point one - separate by comma ");
    scanf ("%d, %d",&x1, &y1);

    printf ("Enter the x,y coordinate of point two - separate by comma ");
    scanf ("%d, %d",&x2, &y2);

    //printf ("The x1 coordinate is %d \n The y1 coordinate is %d \n", x1, y1);
    //printf ("The x2 coordinate is %d \n The y2 coordinate is %d \n", x2, y2);

    int length, width;

        if (x1 < x2) {
            length = x2 - x1;
        } else {
            length = x1 - x2;
        }

        if (y1 < y2) {
            width = y2 - y1;
        } else {
            width = y1 - y2;
        }
        
    printf("The length of the rectangle is %d, and the width of the rectangle is %d", length,width);

return 0;
}