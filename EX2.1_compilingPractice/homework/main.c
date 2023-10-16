#include "header.h"
#include <stdio.h>
#include <stdlib.h>

void add_node_at_end_of_list (Node** head, int data);
void test_add_node_at_end_of_list();

int main () {
    //I commented all of this out to incorporate the test function
    
    //initialize empty linked list
    //Node* list = NULL;
    
    //linked list generation by for loop to count by 5's
    //for (int i=0; i<=10; i++) {
    //    add_node_at_end_of_list (&list, 5*i);
    //}

    //print the linked list
    //Node* current = list;
    //while (current!=NULL) {
    //    printf("%d -> ",current -> data);
    //    current = current -> next;
    //} 
    //printf("NULL\n");

    //#thnxfrthemmry
    //while (list != NULL) {
    //    Node* temp = list;
    //    list = list->next;
    //    free(temp);
    //}
    

    // Run the unit test for add_node_at_end_of_list
    test_add_node_at_end_of_list();
    return 0;
}