#include <stdio.h>

int main(){

    int totalSeconds;
    printf("Please input total amount of seconds as an integer: ");
    scanf ("%d",&totalSeconds);

    int totalHours = totalSeconds/3600;
    int hoursToSecondsRemaining = totalSeconds % 3600;
    
    int totalMinutes = hoursToSecondsRemaining/60;
    int totalRemainingSeconds = hoursToSecondsRemaining % 60;
    
    printf("%d seconds is equal to %d hours, %d minutes, and %d seconds.",
                totalSeconds, totalHours, totalMinutes, totalRemainingSeconds);




}