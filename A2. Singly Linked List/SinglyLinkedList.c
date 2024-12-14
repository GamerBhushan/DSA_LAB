#include <stdio.h>
#include <stdlib.h>

// Define the structure for a node
typedef struct nd{
    int data;
    struct nd* next;
}Node;

// Function prototypes
void addNode(Node** head, int data);
void removeNode(Node** head, int data);
void displayList(Node* head);

int main() {
    Node* head = NULL; // Initialize an empty list
    int choice, data;

    while (1) {
        printf("\nOperations:\n");
        printf("1. Add\n2. Remove by data\n3. Display all\n4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter data to add: ");
                scanf("%d", &data);
                addNode(&head, data);
                break;
            case 2:
                printf("Enter data to remove: ");
                scanf("%d", &data);
                removeNode(&head, data);
                break;
            case 3:
                displayList(head);
                break;
            case 4:
                printf("Exiting...\n");
                return 0;
            default:
                printf("Invalid choice! Please try again.\n");
        }
    }

    return 0;
}

// Function to add a node to the end of the list
void addNode(Node** head, int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;

    if (*head == NULL) {
        *head = newNode;
    } else {
        Node* temp = *head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newNode;
    }
    printf("%d added to the list.\n", data);
}

// Function to remove a node by its data
void removeNode(Node** head, int data) {
    Node* temp = *head;
    Node* prev = NULL;

    // Check if the head node contains the data
    if (temp != NULL && temp->data == data) {
        *head = temp->next; // Change head
        free(temp);         // Free memory
        printf("%d removed from the list.\n", data);
        return;
    }

    // Search for the node containing the data
    while (temp != NULL && temp->data != data) {
        prev = temp;
        temp = temp->next;
    }

    // If the data was not found
    if (temp == NULL) {
        printf("%d not found in the list.\n", data);
        return;
    }

    // Unlink the node from the list
    prev->next = temp->next;
    free(temp); // Free memory
    printf("%d removed from the list.\n", data);
}

// Function to display all nodes in the list
void displayList(Node* head) {
    if (head == NULL) {
        printf("The list is empty.\n");
        return;
    }

    printf("List elements: ");
    Node* temp = head;
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}
