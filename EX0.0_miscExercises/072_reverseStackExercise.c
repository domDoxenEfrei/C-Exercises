#include <stdio.h>
#include <stdlib.h>

//defines structure for a stack node
struct node {
    int data;
    struct node* next;
};

//declares functions
struct node* createNode (int data); //001: function to create a new node
int isEmpty(struct node* top); //002: function to check if stack is empty
void push(struct node** top, int data); //003: function to push an element onto the stack
int pop(struct node** top); //004: function to pop an element from the stack
void reverseStack(struct node** stack); //005: function to reverse a stack
void printStack(struct node* top); //006: function to print the stack

int main() {
    struct node* stack = NULL;

    //push elements onto the stack
    push(&stack, 1);
    push(&stack, 2);
    push(&stack, 3);
    push(&stack, 4);

    printf("Original: ");
    printStack(stack);

    reverseStack(&stack);
    printf("Reversed: ");
    printStack(stack);

    return 0;
}

//001:function to create a new node
struct node* createNode (int data) {
    struct node* newNode = (struct node*)malloc(sizeof(struct node));
    if (newNode == NULL){
        printf("Memory allocation failed!\n");
        exit(1);
    }
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

//002: function checks if stack is empty
int isEmpty(struct node* top){
    return (top == NULL);
}

//003: function to push an element onto the stack
void push(struct node** top, int data) {
    struct node* newNode = createNode(data);
    newNode->next = *top;
    *top = newNode;
}

//004: function to pop an element from the stack
int pop(struct node** top) {
    if (isEmpty(*top)) {
        printf("Stack Underflow!\n");
        exit(1);
    }
    struct node* temp = *top;
    int data = temp->data;
    *top = temp-> next;
    free(temp); //frees the memory from the heap
    temp = NULL; //clears the pointer and sets to NULL
    return data;
}

//005: function to reverse a stack
void reverseStack(struct node** stack) {
    struct node* reversedStack = NULL;
    while (!isEmpty(*stack)) {
        int data = pop(stack);
        push(&reversedStack, data);
    }
    *stack = reversedStack;
}

//006: function to print the stack
void printStack(struct node* top) {
    printf("Stack: ");
    while (top !=NULL) {
        printf("%d ", top->data);
        top=top->next;
    }
    printf("\n");
}
