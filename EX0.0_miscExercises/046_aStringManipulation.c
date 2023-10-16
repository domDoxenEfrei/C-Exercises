#include <stdio.h>
#include <string.h>
#include <stdbool.h>

//main functions in order they're called from main
void getUserName(char firstName[],char lastName[], char fullName[], int firstNameSize, int lastNameSize, int fullNameSize);
void printMenu();
void optionOne (char firstName[], char lastName[]);
void optionTwo (char firstName[], char lastName[]);
void optionThree (char fullName[]);
void optionFour(char fullName[]);
void optionFive(char firstName[], char lastName[]);
void optionSix (char userSentence[], int sentenceSize);

//subfunctions: in order of main function they're called in
void concatenateWithSpace(char fullName[], char firstName[], char lastName[]); //getUserName
int getNameLength(char name[], int nameSize); //optionOne
int isVowel(char c); //optionFive
void getSentence (char userSentence[],int sentenceSize); //optionSix

//new functions to organize later

int main () {
    char firstName[30];
    char lastName[30];
    char fullName[60];
    char userSentence[1000];

    //gets name from user, greets them and initializes start menu 
    getUserName(firstName, lastName, fullName, sizeof(firstName), sizeof(lastName), sizeof(fullName));
    printf("This program plays with strings. I can do many different things. Here are your options.\n");
    
    //defines the userMenu and switches to each case depending on selection
    int continueProgram=1;
    int userChoice;
    
    printMenu();

    while (continueProgram==1) {
        printf("The menu can be found by entering '8'\n Otherwise, please enter the number corresponding to your menu selection: ");
        scanf("%d", &userChoice);

        switch (userChoice) {
            case 1: 
                printf("Option 1 Selected\n");
                optionOne(firstName, lastName);
                break;
            case 2: 
                printf("Option 2 Selected\n");
                optionTwo(firstName, lastName);
                break;
            case 3: 
                printf("Option 3 Selected\n");
                optionThree(fullName);
                break;
            case 4: 
                printf("Option 4 Selected\n");
                optionFour(fullName);
                break;
            case 5: 
                printf("Option 5 Selected\n");
                optionFive(firstName, lastName);
                break;
            case 6: 
                printf("Option 6 Selected\n");
                optionSix (userSentence, sizeof(userSentence));
                break;
            case 7: 
                printf("Option 7 Selected.\n");
                break;
            case 8:
                printMenu();
                break;
            case 9:
                printf("Option 9 Selected. Goodbye.\n");
                continueProgram = 0;
                break;
            default:
                printf("Invalid selection, please select an option 1-7\n");
        }
    }
    return 0;
}


//main functions

    //aquires user's first and last name separately and greets them.
    void getUserName(char firstName[],char lastName[], char fullName[], int firstNameSize, int lastNameSize, int fullNameSize) {
        printf("Please enter your first name: ");
        scanf("%s", firstName);
        printf("Please enter your last name: ");
        scanf("%s", lastName);
        concatenateWithSpace(fullName, firstName, lastName);
        printf("Hello %s\n", fullName);   
    }

    //print menu function
    void printMenu (){
        printf("Option 1: Report the number of characters in your name\n");
        printf("Option 2: Report the first and last characters of your name(s)\n");
        printf("Option 3: Search for a letter in your full name, counts how many there are, and reports the position of the characters\n");
        printf("Option 4: Writes your full name backwards\n");
        printf("Option 5: Counts how many vowels are in your name\n");
        printf("Option 6: Counts the number of words in a sentence you input\n");
        printf("Option 7: Creates an acronym out of a phrase you put in\n");
        printf("Option 8: Print menu\n");
        printf("Option 9: Exit program\n");
    }

    //defines option 1: # characters in user's name
    void optionOne (char firstName[], char lastName[]) {
        int firstNameLength = getNameLength(firstName, 30);
        int lastNameLength = getNameLength(lastName, 30);
        printf("First Name: %d Characters\n Last Name: %d Characters\n Name Total: %d Characters\n", firstNameLength, lastNameLength, firstNameLength+lastNameLength);
    }

    //defines option 2: first and last characters in first and last name
    void optionTwo (char firstName[], char lastName[]){
        printf("First Name First Character: %c\n First Name Last Character: %c\n",firstName[0],firstName[strlen(firstName)-1]);
        printf("First Name First Character: %c\n First Name Last Character: %c\n",lastName[0],lastName[strlen(lastName)-1]);
    }

    //defines option 3: user provides a character, searches for it, counts, and tells positions
    void optionThree (char fullName[]){
        char userLetter;
        printf("Please input a letter you would like to search for in your full name: ");
        scanf(" %c", &userLetter);
        printf("Your full name is: %s\n", fullName);
        int position=1;
        int count=0;

        for (int i=0; fullName[i] !='\0'; i++) {
            if (fullName[i]==userLetter) {
                printf("Found '%c' at position %d\n", userLetter, i);
                count++;
            } if (fullName[i]==' ') {
                position++;
            }
        }

        if (count == 0) {
            printf("The character '%c' is not found in your full name.\n");
        } else {
            printf("There's a total of '%d' occurences of '%c' in your full name.\n", count, userLetter);
        }
    }
    
    //option 4: Writes your name backwards
    void optionFour(char fullName[]) {
        int nameLength = strlen(fullName);
        printf("Your full name forwards: %s", fullName);
        
        printf("\nYour full name backwards: ");
        for (int i=nameLength-1; i>=0; i--){
            printf("%c", fullName[i]);
        }
        printf("\n");
    }

    //option5: counts how many vowels are in your name
    void optionFive(char firstName[], char lastName[]) {
        int firstNameVowelCount=0;
        int lastNameVowelCount=0;
        for (int i=0; firstName[i] !='\0'; i++) {
            if (isVowel(firstName[i])) {
            firstNameVowelCount++;
            }
        }
        for (int i=0; lastName[i] !='\0'; i++) { 
            if (isVowel(lastName[i])) {
            lastNameVowelCount++;
            }
        }

        printf("There are %d vowels in your first Name, and %d in your last Name.",firstNameVowelCount, lastNameVowelCount);
        printf("That is a total of %d vowels!\n", firstNameVowelCount+lastNameVowelCount);
    }

    //option 6: #words in a sentence
    void optionSix (char userSentence[], int sentenceSize){
        getSentence (userSentence, sentenceSize);
        int wordCount=0;
        bool inWord=false;

        for (int i = 0; userSentence[i] != '\0'; i++) {
            if (userSentence[i] == ' ' || userSentence[i] == '\t' || userSentence[i] == '\n' || userSentence[i] == '\r') {
            if (inWord) {
                wordCount++;
                inWord = false;
            }
            } else {
                // If we're not in whitespace, we're in a word
                inWord = true;
            }
        }
        if (inWord) {
            wordCount++;
        }
    printf("There are %d words in that sentence.\n", wordCount);
    }


//subfunctions

    //returns the number of letters in a name
    int getNameLength(char name[], int nameSize) {
        int nameLength = strlen(name);
        return nameLength;
    }

    //string concatenate with space in between
    void concatenateWithSpace(char fullName[], char firstName[], char lastName[]){
        strcpy(fullName, firstName);
        strcat(fullName, " ");
        strcat(fullName, lastName);
    }

    int isVowel(char c){
        return (c=='a'||c=='A'||c=='e'||c=='E'||c=='i'||c=='I'||c=='o'||c=='O'||c=='u'||c=='U');
    }

    //aquire string sentence
    void getSentence (char userSentence[],int sentenceSize) {
        printf("Please enter a short-ish sentence: ");
        scanf(" ");
        fgets(userSentence, sentenceSize,stdin);
        printf("Your Sentence: %s", userSentence);
    }


//new functions to organize later...

    

    