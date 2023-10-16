#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int guessValidator (int userGuess, int *guessCounter);
int guessChecker (int random, int userGuess);

int main () {
    //generates random number
    srand(time(NULL));
    int random = rand() % 100 + 1;
    
    //prompts user
    printf("I'm thinking of a number 1 through 100. If you guess it within 10 tries, you win!\n");

    int correctnessIndex = 0; //0 if user incorrect and 1 if user correct
    int validnessIndex = 0; //0 if the guess is invalid and 1 if guess is valid
    int guessCounter = 1;//counts number of guesses
    int userGuess; //stores the user's guess to run the game
    
    //defines the game
    while (correctnessIndex==0 && guessCounter <=10) { //game continues so long as correctness index is 0 and guess counter <10
        printf(" Please enter your #%d guess: ", guessCounter);
        scanf("%d", &userGuess);

        validnessIndex = guessValidator (userGuess, &guessCounter); //function one - validates correct input 1-100 from the user
        if (validnessIndex == 1){ //makes sure the guess is valid before checking
            correctnessIndex = guessChecker (random, userGuess); //function two - checks if user guess is correct
        } else {}
        
    
        if (correctnessIndex==1){ //checks if correctness index has indicated the user one and terminates the program
            break;
        }
    }

    if (correctnessIndex==0) { //checks if user has spend more than 10 guesses and terminates the program
        printf("You have used all 10 tries. The correct number was %d. You Lose...", random);
    }
    return 0;
}

// validates the guess is a number between 1 and 100
int guessValidator (int userGuess, int *guessCounter) {
    if (userGuess < 1 || userGuess >100) {
        printf("Please enter an integer between 1 and 100.");
        return 0;
    } else {
        (*guessCounter)++;
        return 1;
    }
}

//checks the guess to see if it is correct and replies appropriately
int guessChecker (int random, int userGuess){
    if (userGuess == random) {
        printf("Congratulations! You Win!");
        return 1;
    } else if (userGuess < random) {
        printf("Higher! ");
        return 0;
    } else {
        printf("Lower! ");
        return 0;
    }
}

