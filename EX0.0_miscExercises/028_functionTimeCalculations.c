#include <stdio.h>

int timeDecompHoursCalc (int numSeconds){ //function decomposes #of seconds into hours 
    int numHours = numSeconds/3600;
    return numHours;
}

int timeDecompMinsCalc (int numSeconds){ //function calculates the remainder of minutes after hours calc
    int numMins = (numSeconds%3600)/60;
    return numMins;
}

int timeDecompSecsCalc (int numSeconds) { //function calculates the remainder of seconds after hours,minutes calcs
    int numHours = numSeconds/3600;
    int numMins = (numSeconds%3600)/60;
    int numSecondsRemaining = numSeconds-(numHours*3600)-(numMins*60);
    return numSecondsRemaining;
}

int timeCompCalc (int h, int m, int s) { //function calculates the total number of seconds given hours, minutes, seconds
    int secondsHours = h*3600;
    int secondsMinutes = m*60;
    int totalSeconds = secondsHours + secondsMinutes + s;
    return totalSeconds;
}

int main () { //asks user which function they would like to run
    printf("I like to do time calculations.\n");
    printf("I can decompose a total amount of seconds into hours, minutes, and seconds. That is option 1.\n");
    printf("I can also calculate the number od seconds given hours, minutes, seconds. That is option 2.\n");
    printf("Option 3 exits the program. \n");

    while (1) { //checks for user selected option
        int userChoice;
        printf("Please enter either '1', '2', or '3': ");
        scanf(" %d", &userChoice);

        if (userChoice==1) {
            int userSeconds, decompHours, decompMinutes, decompSeconds;
            printf("Please provide a total number of seconds: ");
            scanf("%d",&userSeconds);
            decompHours=timeDecompHoursCalc (userSeconds);
            decompMinutes=timeDecompMinsCalc (userSeconds);
            decompSeconds=timeDecompSecsCalc (userSeconds);
            printf("%d seconds is equal to %d hours, %d minutes, and %d seconds.\n", userSeconds, decompHours, decompMinutes, decompSeconds);
            printf("Goodbye");
            break;
        } else if (userChoice==2) {
            int userCompHours, userCompMins, userCompSecs;
            printf ("Please provide the number of hours, minutes, and seconds separated by commas: ");
            scanf("%d,%d,%d", &userCompHours, &userCompMins, &userCompSecs);
            int totalSecs = timeCompCalc (userCompHours, userCompMins, userCompSecs);
            printf("That is a total of %d seconds.\n", totalSecs);
            printf("GoodBye!");
            break;                
        } else if (userChoice==3) {
            printf("Goodbye");
            break;
        } else {
            printf("Please input either a 'Y' or 'N'. \n");
        }
    }
}