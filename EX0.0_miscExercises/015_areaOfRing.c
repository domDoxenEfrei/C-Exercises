#include <stdio.h>

int main(){
    
    float largerRadius, smallerRadius;
    printf ("What is the radius of the larger circle?: ");
    scanf ("%f", &largerRadius);

    printf ("What is the radius of the smaller circle?: ");
    scanf ("%f", &smallerRadius);

    if (smallerRadius > largerRadius) {
        printf("Please make sure the larger area you input is larger");
    }

        else if (smallerRadius == largerRadius){
            printf("The sizes you entered would not produce a ring, they are the same size");
        }

    else  {
        const float Pi=3.14159;
        float largerArea = largerRadius*largerRadius*Pi;
        float smallerArea = smallerRadius*smallerRadius*Pi;
        float ringArea = largerArea-smallerArea;
        printf("The Area of the Ring is %g", ringArea);
    }

    return 0;
}
