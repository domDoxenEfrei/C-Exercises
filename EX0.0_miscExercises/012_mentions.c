
#include <stdio.h>
int main () {
    int userGrade;
    printf ("Please input your average grade: ");
    scanf ("%d", &userGrade);
    
    if (userGrade <=10) {
        printf ("You failed...");
    }
    
    else if (userGrade >10 && userGrade <14) {
        printf ("That is a fairly good grade");
    }
    
    else if (userGrade >=14 && userGrade <16) {
        printf ("That is a good grade");
    }
    
    else if (userGrade >=16 && userGrade <=20) {
        printf ("That is a very good grade");
    }
    
    else if (userGrade >20) {
        printf ("You're Lying ------");
    }
}