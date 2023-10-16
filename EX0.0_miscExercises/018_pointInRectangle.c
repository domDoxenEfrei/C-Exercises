#include <stdio.h>

int main (){

    int x1,y1,x2,y2,x,y;
    printf ("Enter the x,y coordinate of point one - separate by comma ");
    scanf ("%d, %d",&x1, &y1);

    printf ("Enter the x,y coordinate of point two - separate by comma ");
    scanf ("%d, %d",&x2, &y2);

    printf ("Enter the x,y coordinate of a test point - separate by comma ");
    scanf ("%d, %d",&x, &y);

    //printf ("The x1 coordinate is %d \n The y1 coordinate is %d \n", x1, y1);
    //printf ("The x2 coordinate is %d \n The y2 coordinate is %d \n", x2, y2);

    if ((x >= x1 && x <= x2) || (x >= x2 && x <= x1)) {
        if ((y >= y1 && y <= y2) || (y >= y2 && y <= y1)) {
            printf("Point P is inside the rectangle.\n");
        } else {
            printf("Point P is outside the rectangle.\n");
        }
    } else {
        printf("Point P is outside the rectangle.\n");
    }

return 0;
}