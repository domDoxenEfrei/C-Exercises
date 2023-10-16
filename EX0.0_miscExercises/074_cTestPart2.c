#include <stdio.h>
#include <stdlib.h>

//doubly linked list structure
struct node {
    int data;
    struct node* prev;
    struct node* next;
};

//function declaration
struct node* createNode(int data);
void insertAtEnd(struct node** head, int data);
int searchElement(struct node* head, int target);
void deleteAtPosition(struct node** head, int position);
void sortList(struct node** head);
void makeCircular(struct node** head);
void displayCircular(struct node* head);

int main() {
    struct node* head = NULL;

//just using a for loop to populate the list....
    for (int i = 5; i >= 0; i--) {
        insertAtEnd(&head, i);
    }

    printf("Doubly Linked List: ");
    struct node* current = head;
    while (current != NULL) {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");

    int searchValue;
    printf("Enter the element to search: ");
    scanf("%d", &searchValue);
    int position = searchElement(head, searchValue);
    if (position != -1) {
        printf("%d found at position %d\n", searchValue, position);
    } else {
        printf("%d not found in the list\n", searchValue);
    }

    int deletePosition;
    printf("Enter the position to delete: ");
    scanf("%d", &deletePosition);
    deleteAtPosition(&head, deletePosition);
    printf("After deleting at position %d: ", deletePosition);
    current = head;
    while (current != NULL) {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");

    sortList(&head);
    printf("Sorted List: ");
    current = head;
    while (current != NULL) {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");

    makeCircular(&head);
    printf("Circular Doubly Linked List: ");
    displayCircular(head);

    return 0;
}

//function definitions

struct node* createNode(int data) {
    struct node* newNode = (struct node*)malloc(sizeof(struct node));
    newNode->data = data;
    newNode->prev = NULL;
    newNode->next = NULL;
    return newNode;
}

void insertAtEnd(struct node** head, int data) {
    struct node* newNode = createNode(data);
    if (*head == NULL) {
        *head = newNode;
    } else {
        struct node* current = *head;
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = newNode;
        newNode->prev = current;
    }
}

int searchElement(struct node* head, int target) {
    int position = 1;
    struct node* current = head;
    while (current != NULL) {
        if (current->data == target) {
            return position;
        }
        current = current->next;
        position++;
    }
    return -1; 
}

void deleteAtPosition(struct node** head, int position) {
    if (*head == NULL) {
        return; 
    }

    struct node* current = *head;
    int currentPosition = 1;

    while (current != NULL && currentPosition < position) {
        current = current->next;
        currentPosition++;
    }

    if (current == NULL) {
        return; 
    }

    if (current->prev != NULL) {
        current->prev->next = current->next;
    } else {
        *head = current->next;
    }

    if (current->next != NULL) {
        current->next->prev = current->prev;
    }

    free(current);
}

void sortList(struct node** head) {
    if (*head == NULL || (*head)->next == NULL) {
        return; 
    }

    int swapped;
    struct node* temp;
    struct node* end = NULL;

    do {
        swapped = 0;
        struct node* current = *head;

        while (current->next != end) {
            if (current->data > current->next->data) {
                int tempData = current->data;
                current->data = current->next->data;
                current->next->data = tempData;
                swapped = 1;
            }
            current = current->next;
        }
        end = current;
    } while (swapped);
}

void makeCircular(struct node** head) {
    if (*head == NULL) {
        return; 
    }

    struct node* current = *head;
    while (current->next != NULL) { //find the tail
        current = current->next;
    }

    current->next = *head; //point the last node's "next" back to the head
    (*head)->prev = current; //point the head node's "previous" back to the tail
}

void displayCircular(struct node* head) {
    if (head == NULL) {
        return; 
    }

    struct node* current = head;

    do {
        printf("%d ", current->data);
        current = current->next;
    } while (current != head);

    printf("\n");
}
