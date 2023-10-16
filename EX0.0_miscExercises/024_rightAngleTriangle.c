#include <stdio.h>
int main () {

    while (1) {
        char userLikesTriangles;
        printf("I hear you like triangles? Please confirm with a 'Y' or 'N'. ");
        scanf(" %c", &userLikesTriangles);

        if (userLikesTriangles =='Y') { //What to do if user likes triangles
            int triangleSize;
            printf("How big of a triangle do you want to see? ");
            scanf("%d", &triangleSize);

            if(triangleSize<=0){ //checks to see if the integer provided is positive
                printf("Triangle size should be a positive integer. \n");
            } else { //Code how to generate triangles here....
                for (int i=1; i<=triangleSize; i++) { //increments i and hits an enter for every increment
                    for (int j=1; j<=i; j++) { //increments j and puts a * per each increment
                        printf("* ");
                    }
                    printf("\n");
                }
                printf("Here's your triangle!");
                break;
            }
            
        } else if (userLikesTriangles =='N') { //what to do if user doesn't like triangles
            printf("BOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOO\n");
            printf("Go Away!");
            break;
        } else { //what to do if user inputs a character other than Y or N
            printf("Illegal input. Please input either 'Y' or 'N'. ");
        }

    }
return 0;
}
