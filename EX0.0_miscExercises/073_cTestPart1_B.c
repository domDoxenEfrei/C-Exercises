#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//function declarations
struct employee* createEmployee(int empNumber, const char* name, int grade);
void insertEmployee(struct employee** head, struct employee* newEmployee);
void deleteEmployee(struct employee** head, int empNumber);
void searchEmployee(struct employee* head, int empNumber);
void displayEmployees(struct employee* head);
void swapEmployees(struct employee** a, struct employee** b);
void sortGradeDescending(struct employee** head);

//define the structure for an employee
struct employee {
    int empNumber;
    char name[100];
    int grade;
    struct employee* next;
};

int main() {
    struct employee* head = NULL;
    int choice;
    
    while (choice != 6) {
        printf("Employee Management System Menu:\n");
        printf("Option 1: Insert Employee\n");
        printf("Option 2: Delete Employee\n");
        printf("Option 3: Search Employee\n");
        printf("Option 4: Display Employees\n");
        printf("Option 5: Display Employees by Descending Grade\n");
        printf("Option 6: Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                {
                    printf("Option 1 Selected: Insert Employee\n..........\n");
                    int empNumber, grade;
                    char name[100];
                    printf("Enter Employee Number: ");
                    scanf("%d", &empNumber);
                    printf("Enter Name: ");
                    scanf(" %[^\n]", name);
                    printf("Enter Grade: ");
                    scanf("%d", &grade);
                    struct employee* newEmployee = createEmployee(empNumber, name, grade);
                    insertEmployee(&head, newEmployee);
                    printf("Employee added successfully.\n");
                }
                break;
            case 2:
                {
                    printf("Option 2 Selected: Delete Employee\n..........\n");
                    int empNumber;
                    printf("Enter Employee Number to delete: ");
                    scanf("%d", &empNumber);
                    deleteEmployee(&head, empNumber);
                }
                break;
            case 3:
                {
                    printf("Option 3 Selected: Search Employee\n..........\n");
                    int empNumber;
                    printf("Enter Employee Number to search: ");
                    scanf("%d", &empNumber);
                    searchEmployee(head, empNumber);
                }
                break;
            case 4:
                printf("Option 4 Selected: Display All Employees\n..........\n");
                displayEmployees(head);
                break;
            case 5: 
                printf("Option 5 selected: Display Employees by Descending Grade\n..........\n");
                sortGradeDescending(&head);
                displayEmployees(head);
                break;
            case 6:
                printf("Option 6 Selected: Exit\n..........\n");
                printf("Exiting the program.\n Goodbye!\n");
                break;
            default:
                printf("Invalid choice. Please enter a valid option.\n");
        }
    } while (choice != 6);

    //free memory before exiting
    while (head != NULL) {
        struct employee* temp = head;
        head = head->next;
        free(temp);
    }

    return 0;
}

//function definitions
//function to create a new employee node
struct employee* createEmployee(int empNumber, const char* name, int grade) {
    int validGrade = 0;

    while (!validGrade) {
        // Check if grade is within the valid range (1 to 5)
        if (grade < 1 || grade > 5) {
            printf("Invalid grade. Grade must be between 1 and 5. Please try again: ");
            scanf("%d", &grade);
        } else {
            validGrade = 1; // Set to 1 to exit the loop
        }
    }

    struct employee* newEmployee = (struct employee*)malloc(sizeof(struct employee));
    if (newEmployee == NULL) {
        printf("Memory allocation failed.\n");
        exit(1);
    }
    newEmployee->empNumber = empNumber;
    strcpy(newEmployee->name, name);
    newEmployee->grade = grade;
    newEmployee->next = NULL;
    return newEmployee;
}


//function to insert a new employee into the linked list
void insertEmployee(struct employee** head, struct employee* newEmployee) {
    if (*head == NULL) {
        *head = newEmployee;
        return;
    }
    struct employee* current = *head;
    while (current->next != NULL) {
        current = current->next;
    }
    current->next = newEmployee;
}

//function to delete an employee from the linked list by employee number
void deleteEmployee(struct employee** head, int empNumber) {
    if (*head == NULL) {
        printf("List is empty. Cannot delete.\n");
        return;
    }
    struct employee* current = *head;
    struct employee* prev = NULL;

    while (current != NULL && current->empNumber != empNumber) {
        prev = current;
        current = current->next;
    }

    if (current == NULL) {
        printf("Employee with Employee Number %d not found.\n", empNumber);
        return;
    }

    if (prev == NULL) {
        *head = current->next;
    } else {
        prev->next = current->next;
    }

    free(current);
    printf("Employee with Employee Number %d deleted successfully.\n", empNumber);
}

//function to search for an employee by employee number
void searchEmployee(struct employee* head, int empNumber) {
    struct employee* current = head;
    while (current != NULL) {
        if (current->empNumber == empNumber) {
            printf("Employee found:\n");
            printf("Employee Number: %d\n", current->empNumber);
            printf("Name: %s\n", current->name);
            printf("Grade: %d\n", current->grade);
            return;
        }
        current = current->next;
    }
    printf("Employee with Employee Number %d not found.\n", empNumber);
}

//function to display all employee records
void displayEmployees(struct employee* head) {
    struct employee* current = head;
    if (current == NULL) {
        printf("No employee records to display.\n");
        return;
    }
    printf("Employee Records:\n");
    while (current != NULL) {
        printf("Employee Number: %d\n", current->empNumber);
        printf("Name: %s\n", current->name);
        printf("Grade: %d\n", current->grade);
        printf("\n");
        current = current->next;
    }
}

//function to swap two employee nodes
void swapEmployees(struct employee** a, struct employee** b) {
    struct employee* temp = *a;
    *a = *b;
    *b = temp;
}

// NOT FUNCTIONING CORRECTLY CURRENTLY, BUT I TRIED:  function to sort employee records in descending order by grade
void sortGradeDescending(struct employee** head) {
    int swapped;
    struct employee* current;
    struct employee* last = NULL;

    if (*head == NULL) {
        return;
    }

    do {
        swapped = 0;
        current = *head;
        struct employee* prev = NULL;

        while (current->next != last) {
            if (current->grade < current->next->grade || (current->grade == current->next->grade && current->empNumber < current->next->empNumber)) {
                swapEmployees(&current, &(current->next));
                swapped = 1;

                // Update the previous node's next pointer
                if (prev != NULL) {
                    prev->next = current;
                } else {
                    *head = current;
                }

                // Swap the next pointers of the current and next nodes
                struct employee* temp = current->next;
                current->next = temp->next;
                temp->next = temp;
            }
            prev = current;
            current = current->next;
        }
        last = current;
    } while (swapped);
}
