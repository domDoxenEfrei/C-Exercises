#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//function declarations
struct employee* createEmployee(int empNumber, const char* name, int grade);
void insertEmployee(struct employee** head, struct employee* newEmployee);
void deleteEmployee(struct employee** head, int empNumber);
void searchEmployee(struct employee* head, int empNumber);
void displayEmployees(struct employee* head);
int compareEmployees(const void *a, const void *b);
void displayDescendingGrade(struct employee *head);
struct employee* mergeLists(struct employee* list1, struct employee* list2);
void caseSix();

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
    
    insertEmployee(&head, createEmployee(101, "Dan Campbell", 5));
    insertEmployee(&head, createEmployee(102, "Jared Goff", 2));
    insertEmployee(&head, createEmployee(103, "Marvin Jones", 1));
    insertEmployee(&head, createEmployee(104, "CJ Gardner Johnson", 1));
    insertEmployee(&head, createEmployee(105, "Aidan Hutchinson", 5));
    insertEmployee(&head, createEmployee(106, "Sam Laporta", 4));

    while (choice != 7) {
        printf("Employee Management System Menu:\n");
        printf("Option 1: Insert Employee\n");
        printf("Option 2: Delete Employee\n");
        printf("Option 3: Search Employee\n");
        printf("Option 4: Display Employees\n");
        printf("Option 5: Display Employees by Descending Grade\n");
        printf("Option 6: Show how to merge two SLLs and then sort by descending grade\n");
        printf("Option 7: Exit\n");
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
                    break;
                }
                
            case 2:
                {
                    printf("Option 2 Selected: Delete Employee\n..........\n");
                    int empNumber;
                    printf("Enter Employee Number to delete: ");
                    scanf("%d", &empNumber);
                    deleteEmployee(&head, empNumber);
                    break;
                }

            case 3:
                {
                    printf("Option 3 Selected: Search Employee\n..........\n");
                    int empNumber;
                    printf("Enter Employee Number to search: ");
                    scanf("%d", &empNumber);
                    searchEmployee(head, empNumber);
                    break;
                }
                
            case 4:
                {
                    printf("Option 4 Selected: Display All Employees\n..........\n");
                    displayEmployees(head);
                    break;
                }
            case 5:
                {
                    printf("Option 5 selected: Display Employees by Descending Grade\n..........\n");
                    displayDescendingGrade(head);
                    break;
                }
            case 6:
                {
                    printf("Option 6 selected: Show how to merge two SLLs and then sort by descending grade\n..........\n");
                    caseSix();
                    break;
                }
            case 7:
                {
                    printf("Option 7 Selected: Exit\n..........\n");
                    printf("Exiting the program.\n Goodbye!\n");
                    break;
                }
            default:
                printf("Invalid choice. Please enter a valid option.\n");
        }
    } while (choice != 7);

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

//function to compare two employees for sorting
int compareEmployees(const void *a, const void *b) {
    struct employee *employeeA = *(struct employee **)a;
    struct employee *employeeB = *(struct employee **)b;

    if (employeeA->grade != employeeB->grade) {
        return employeeB->grade - employeeA->grade;
    }
    //uses employee number as tie breaker
    return employeeA->empNumber - employeeB->empNumber;
}

//function to display employees by descending grade
void displayDescendingGrade(struct employee *head) {
    struct employee *current = head;
    int numEmployees = 0;

    while (current != NULL) {
        numEmployees++;
        current = current->next;
    }

    struct employee **employeeArray = malloc(numEmployees * sizeof(struct employee *));
    if (employeeArray == NULL) {
        printf("Memory allocation failed.\n");
        exit(1);
    }

    current = head;
    for (int i = 0; i < numEmployees; i++) {
        employeeArray[i] = current;
        current = current->next;
    }

    qsort(employeeArray, numEmployees, sizeof(struct employee *), compareEmployees);

    printf("Employees by Descending Grade:\n");
    for (int i = 0; i < numEmployees; i++) {
        printf("Employee Number: %d\n", employeeArray[i]->empNumber);
        printf("Name: %s\n", employeeArray[i]->name);
        printf("Grade: %d\n", employeeArray[i]->grade);
        printf("\n");
    }

    free(employeeArray);
}

// function to merge two linked lists
struct employee* mergeLists(struct employee* list1, struct employee* list2) {
    if (list1 == NULL) {
        return list2;
    }

    struct employee* current = list1;
    while (current->next != NULL) {
        current = current->next;
    }

    current->next = list2;

    return list1;
}


void caseSix() {
    // Create two linked lists with different employee records
    struct employee* list1 = NULL;
    struct employee* list2 = NULL;

    insertEmployee(&list1, createEmployee(101, "Dan Campbell", 5));
    insertEmployee(&list1, createEmployee(102, "Jared Goff", 2));
    insertEmployee(&list1, createEmployee(103, "Marvin Jones", 1));

    insertEmployee(&list2, createEmployee(104, "CJ Gardner Johnson", 1));
    insertEmployee(&list2, createEmployee(105, "Aidan Hutchinson", 5));
    insertEmployee(&list2, createEmployee(106, "Sam Laporta", 4));

    struct employee* mergedList = mergeLists(list1, list2);
    printf("Merged Employee Records:\n");
    displayEmployees(mergedList);
    
    printf("Merged and Sorted Employee Records:\n");
    displayDescendingGrade(mergedList);

    // Free memory for merged list
    while (mergedList != NULL) {
        struct employee* temp = mergedList;
        mergedList = mergedList->next;
        free(temp);
    }
}