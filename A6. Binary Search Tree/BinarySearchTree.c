#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct node {
    long phone;
    char name[100];
    struct node *left, *right;
} BST;


BST* createNewNode(char name[], long phone) {
    BST *newNode = (BST *)malloc(sizeof(BST));
    if (!newNode) {
        printf("Memory allocation failed!\n");
        return NULL;
    }
    newNode->phone = phone;
    strcpy(newNode->name, name);
    newNode->left = newNode->right = NULL;
    return newNode;
}


BST* insertNewNode(BST *root, char name[], long phone) {
    if (root == NULL) {
        return createNewNode(name, phone);
    }
    if (strcmp(name, root->name) < 0) {
        root->left = insertNewNode(root->left, name, phone);
    } else if (strcmp(name, root->name) > 0) {
        root->right = insertNewNode(root->right, name, phone);
    } else {
        printf("Duplicate name not allowed!\n");
    }
    return root;
}


void inOrderTraversal(BST *root) {
    if (root != NULL) {
        inOrderTraversal(root->left);
        printf("Name: %s, Phone: %ld\n", root->name, root->phone);
        inOrderTraversal(root->right);
    }
}


BST* searchByName(BST *root, char name[]) {
    if (root == NULL || strcmp(root->name, name) == 0) {
        return root;
    }
    if (strcmp(name, root->name) < 0) {
        return searchByName(root->left, name);
    }
    return searchByName(root->right, name);
}

BST* findMin(BST *root) {
    while (root->left != NULL) {
        root = root->left;
    }
    return root;
}


BST* deleteNode(BST *root, char name[]) {
    if (root == NULL) {
        printf("\nName not found!\n");
        return root;
    }
    if (strcmp(name, root->name) < 0) {
        root->left = deleteNode(root->left, name);
    } else if (strcmp(name, root->name) > 0) {
        root->right = deleteNode(root->right, name);
    } else {

        if (root->left == NULL) {
            BST *temp = root->right;
            free(root);
            return temp;
        } else if (root->right == NULL) {
            BST *temp = root->left;
            free(root);
            return temp;
        }
     
        BST *temp = findMin(root->right);
        strcpy(root->name, temp->name);
        root->phone = temp->phone;
        root->right = deleteNode(root->right, temp->name);
    }
    return root;
}

void menu() {
    printf("\n\nMenu:");
    printf("\n1. Insert");
    printf("\n2. Search by Name");
    printf("\n3. Display");
    printf("\n4. Delete by Name");
    printf("\n5. Exit");
    printf("\nChoose Your Option: ");
}


int main() {
    BST *root = NULL;
    int choice;
    char name[100];
    long phone;

    do {
        menu();
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("\nEnter name: ");
                scanf("%s", name);
                printf("Enter phone number: ");
                scanf("%ld", &phone);
                root = insertNewNode(root, name, phone);
                break;

            case 2:
                printf("\nEnter name to search: ");
                scanf("%s", name);
                BST *result = searchByName(root, name);
                if (result) {
                    printf("\nFound - Name: %s, Phone: %ld\n", result->name, result->phone);
                } else {
                    printf("\nName not found!\n");
                }
                break;

            case 3:
                printf("\nPhone list in sorted order:\n\n");
                inOrderTraversal(root);
                break;

            case 4:
                printf("\nEnter name to delete: ");
                scanf("%s", name);
                root = deleteNode(root, name);
                break;

            case 5:
                printf("\nExiting...\n");
                break;

            default:
                printf("\nInvalid choice! Please try again.\n");
        }
    } while (choice != 5);

    return 0;
}
