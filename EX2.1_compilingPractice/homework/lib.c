//in the library we write the funcitons
#include "header.h"
#include <stdio.h>
#include <stdlib.h>

//function adds node to end of SLL
void add_node_at_end_of_list (Node** head, int data) {
    //allocate memory for a new node
    Node* newNode = (Node*)malloc(sizeof(Node));

    //if allocation fails - handle 
    if (newNode == NULL) {
        printf("Memory Allocation Failed\n");
        exit(1);
    }


    newNode -> data = data; // set data for new node
    newNode -> next = NULL; // sets next for new node to NULL since it is the last on the list

    //if list is empty, make the new node the head of the list
        //else move through the list to find the last node
    if (*head == NULL) {
        *head = newNode;
    } else {
        Node* current = *head; //current is now pointed to head node
        while (current->next != NULL) { //while the current node's 'next' address is not NULL
            current = current -> next;  // set current to be the current node's 'next'
        }
        current -> next = newNode; //after it found where the next is NULL, place newNode there at the end
    }
}


// Function to test the add_node_at_end_of_list function
void test_add_node_at_end_of_list() {
    Node* list = NULL;  //initializes SLL

    for (int i = 0; i <= 10; i++) {     // for loop calls the function and provides info to make nodes incrementing by 5
        add_node_at_end_of_list(&list, 5 * i);
    }

    Node* current = list; //sets the current to be the head of the list
    int expected_data = 0; //initializes expected data to 0

    while (current != NULL) { //while not NULL
        if (current->data != expected_data) { //check if current data is equal to expected data
            printf("Test failed: Expected %d, Got %d\n", expected_data, current->data); //if it's not print the test failed
            return;
        }
        expected_data += 5; // count by 5's
        current = current->next; // traverse the list
    }

    printf("Test passed: All elements added correctly.\n"); //print if everything passed

    //#thnxfrthemmry
    while (list != NULL) {
        Node* temp = list;
        list = list->next;
        free(temp);
    }
}

