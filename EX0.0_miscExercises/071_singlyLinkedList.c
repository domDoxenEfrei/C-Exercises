#include <stdio.h>
#include <stdlib.h>

//defines the structure of a singly linked list
//singly linked lists consist of the data of the node and the address to the next node
struct node {
    int data;
    struct node* next;
};

//function declaration
void insertBottom(struct node** head, int data);
void insertTop (struct node** head, int data);
void printSLL (struct node* head);
void searchList (struct node* head, int userNum);
void countListNodes (struct node*head);
void deletePos (struct node** head, int position);

int main (){
    struct node* head = NULL; //initializes the head of the linked list and sets it to null
    insertTop(&head,24);
    insertTop(&head,764);
    insertTop(&head,56);
    insertTop(&head,34);
    insertBottom(&head,94);

    printf("Here's the linked list: ");
    printSLL(head);

    int userChoice;
    int userNum;

    while (1) {
        printf("Option 1: add to top of list\n");
        printf("Option 2: add to bottom of list\n");
        printf("Option 3: TBD \n"); //add to user selected position of list
        printf("Option 4: search list and report position\n");
        printf("Option 5: delete a user selected position of list\n");
        printf("Option 6: print the list\n");
        printf("Option 7: exit the program\n");
        printf(".............\n");
        printf("Please enter your selection: ");
        scanf ("%d", &userChoice);
        
        switch (userChoice) {
            case 1: 
                printf("Option 1 Selected\n");
                printf("What integer would you like to add to the top of the list?");
                scanf("%d", &userNum);

                insertTop(&head, userNum);
                printSLL(head);
                break;
            case 2:
                printf("Option 2 Selected\n");
                printf("What integer would you like to add to the bottom of the list?");
                scanf("%d",&userNum);

                insertBottom(&head,userNum);
                printSLL(head);
                break;
            case 4:
                printf("Option 4 Selected\n");
                printf("What integer would you like to search the list for?: ");
                scanf("%d",&userNum);

                searchList(head, userNum);
                break;

            case 5:
                printf("Option 5 Selected\n");
                countListNodes(head);
                printf("What position would you like to delete?: ");
                scanf("%d", &userNum);
                deletePos(&head, userNum);
                printSLL(head);
                break;

            case 6:
                printSLL(head);
                break;
            case 7:
                printf("Exiting the program. Goodbye!");
                return 0;
            default:
                printf("Invalid choice. Please enter a valid option.\n");

        }
    }
    return 0;
}

//function definition
//function to print the singly linked list
void printSLL (struct node* head) {
    struct node* current = head; //the current step is at the head
    while (current!= NULL) { // while current is not Null, print the current's data. then move the current to next for next cycle
        printf("%d-> ", current->data);
        current = current -> next;
    }
    printf("NULL\n");
}

//function to insert a new node at the top of the list 
void insertTop (struct node** head, int data) {
    struct node* newNode = (struct node*)malloc(sizeof(struct node));
    if (newNode==NULL) { //handles situation if memory allocation fails
        printf("Memory Allocation Failed.\n");
        exit(1);
    }
    newNode -> data = data; //sets the newNode's data equal to the data provided
    newNode -> next = *head; //The new node's next pointer points to the old head
    *head = newNode; //the new head is the new Node
}


//function to insert a new node at the bottom of the list
void insertBottom(struct node** head, int data){ 
    struct node* newNode = (struct node*)malloc(sizeof(struct node)); //defines the newNode and allocates memory 
    if (newNode==NULL) { //handles situation if memory allocation fails
        printf("Memory Allocation Failed.\n");
        exit(1);
    }
    newNode -> data = data; //sets the newNode's data equal to the data provided
    newNode -> next = NULL; //the address of the new node (since it is going to bottom) is now Null

    if (*head ==NULL) { //handles if newNode is the first node in the SLL
        *head = newNode; //sets the newNode to be the head --> it tells the head it is now the new Node only if it is the first and only node.
        return;
    }

    struct node* current = *head; //the current step is at the head
    while (current -> next!= NULL) { //current continues down the stack so long as the current node's next pointer is not NULL
        current = current -> next; //moves the current down the list so long as the next pointer is not null
    }
    current ->next = newNode; //now that it's located the end of the list (when the node's 'next'=NULL) set that node's next pointer to be the newNode
}

void searchList (struct node* head, int userNum){
    struct node* current = head;
    int position = 0;
    int found=0;

    while (current!=NULL){
        if (current->data==userNum){
            printf("Number %d found at position %d in the linked list.\n", userNum, position);
            found = 1;
            break;
        }
        current = current -> next;
        position++;
    }

    if (!found){
    printf("Number %d was not found in the linked list.\n..........\n", userNum);
    return;
    }

}

void countListNodes (struct node*head){
    struct node* current = head;
    int nodeCount =0;
    
    while (current!=NULL){
        nodeCount++;
        current = current -> next;
    } 
    printf("There are currently %d nodes in the list\n",nodeCount);
}

void deletePos (struct node** head, int position){
    if (*head == NULL) {
        printf("The List is empty. Cannot Delete.");
        return;
    }

    if (position<0){
        printf("Invalid position. Position must be positive.");
        return;
    }

    if (position==0){
        struct node* temp = *head;
        *head = (*head)->next;
        free (temp);
        return;
    }

   // Traverse the list to find the node just before the position
    struct node* current = *head;
    int currentPosition = 0;
    while (current != NULL && currentPosition < position - 1) {
        current = current->next;
        currentPosition++;
    }

    // Check if the position is beyond the end of the list
    if (current == NULL || current->next == NULL) {
        printf("Invalid position. Position exceeds list length.\n");
        return;
    }

    // Delete the node at the specified position
    struct node* temp = current->next;
    current->next = temp->next;
    free(temp);
}