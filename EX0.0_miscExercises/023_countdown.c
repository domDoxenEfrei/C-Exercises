#include <stdio.h>

int main() {
    int countEnd;
    int countDownSuccess = 0;
    int countUpSuccess = 0;

    char userCountDownChoice;
    printf("Hello, I am a countdown machine. I countdown from 100. Want me to show you?: ");
    scanf(" %c", &userCountDownChoice);

    if (userCountDownChoice == 'Y') {
        int countdownStart = 100;
        for (int i = countdownStart; i >= 0; i--) {
            printf("Countdown %d\n", i);
        }
        printf("I can stop at a number you choose. At what number should I end my countdown?: ");
        scanf("%d", &countEnd);

        if (countEnd >= 0) {
            for (int k = 100; k >= countEnd; k--) {
                printf("Countdown %d\n", k);
            }
            countDownSuccess = 1; // Indicate success
        }
    } else if (userCountDownChoice == 'N') {
        while (1) {
            printf("I can stop at a number you choose. At what number should I end my countdown?: ");
            scanf("%d", &countEnd);

            if (countEnd >= 0) {
                for (int k = 100; k >= countEnd; k--) {
                    printf("Countdown %d\n", k);
                }
                countDownSuccess = 1; // Indicate success
                break;
            } else {
                printf("Please input a non-negative integer. \n");
            }
        }
    } else {
        printf("Please input a 'Y' or 'N'. \n");
    }

    if (countDownSuccess == 1) {
        printf("See, I did it!\n");
    }

    if (countDownSuccess == 1 || userCountDownChoice == 'Y') {
        while (1) {
            char userCountUpChoice;
            printf("Would you like me to count up to your number? Please input a Y or N: ");
            scanf(" %c", &userCountUpChoice);

            if (userCountUpChoice == 'Y') {
                for (int j = 0; j <= countEnd; j++) {
                    printf("Countup %d\n", j);
                }
                countUpSuccess = 1;
                break;
            } else if (userCountUpChoice == 'N') {
                printf("Okay, byeeeeeeee \n");
                break;
            } else {
                printf("Invalid Input. Please enter 'Y' or 'N'. \n");
            }
        }
    }

    if (countUpSuccess == 1) {
        printf("See, I did it!\n");
    }

    return 0;
}
