#include <stdio.h>

int main(){

    int hours;
    int minutes;
    int seconds;

    printf("Please input the number of hours: ");
    scanf("%d",&hours);

    printf("Please input the number of minutes: ");
    scanf("%d",&minutes);

    printf("Please input the number of seconds: ");
    scanf("%d",&seconds);

    int hoursToSeconds = hours*3600;
    int minutesToSeconds = minutes*60;
    int timeInSeconds = hoursToSeconds + minutesToSeconds + seconds;

    printf("the total time in Seconds is: %d", timeInSeconds);

}