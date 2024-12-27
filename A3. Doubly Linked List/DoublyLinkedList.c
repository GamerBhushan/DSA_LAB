#include<stdio.h>
#include<stdlib.h>

typedef struct Node
{
    struct Node *prev;
    int data;
    struct Node * next;
}Node;

Node *createNode(){
    Node * node = (Node*) malloc(sizeof(Node));
    int data;
    printf("\nEnter Data : ");
    scanf("%d",&data);
    node->data=data;
    node->prev = NULL;
    node->next = NULL;
    return node;
}

void insertNode(Node **head){
    Node *newnode;
    newnode = createNode();
    if (*head == NULL){
        newnode->prev = *head;
        newnode->next = NULL;
        *head = newnode;
    }else{
        Node *temp = *head;
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = newnode;
        newnode->prev = temp;
        newnode->next = NULL;
    }
    printf("\n\nSuccessfully Inserted : '%d'\n",newnode->data);
}

void display(Node **head){

    if (*head == NULL){
        printf("\n\nList Is Empty.\n\n");
        return;
    }
    

    Node * temp = *head;
    printf("\n\nDisplaying List : ");
    while (temp!=NULL)
    {
        printf("%d\t",temp->data);
        temp = temp->next;
    }
    printf("\n\n");
    
}

void deleteNode(Node **head){
    if (*head == NULL ){
        printf("\n\nList Is Empty.\n\n");
        return;
    }
    int data;
    printf("Enter Data To Delete : ");
    scanf("%d",&data);    
    
    Node *temp = *head, *prev = *head;
    while (temp!=NULL){
        if (temp->data == data){
            prev = temp->prev;
            prev->next = temp->next;
            printf("\n\nDeleted : '%d'\n\n",temp->data);
            free(temp);
            return;
        }
        temp = temp->next;
    }
    printf("\n\nData '%d' Is Not Found In List.\n\n",data);
}

int menu(){
    int ch;
    printf("\n1. Insert Node.");
    printf("\n2. Delete Node.");
    printf("\n3. Display List.");
    printf("\n4. Exit.");
    printf("\n\nChoose Your Option : ");
    scanf("%d",&ch);
    return ch;
}

int main(int argc, char const *argv[]){
    Node *head = NULL;
    int ch;
    do
    {
        ch = menu();

        if (ch == 1){
            insertNode(&head);
        }else if (ch == 2){
            deleteNode(&head);
        }else if (ch == 3){
            display(&head);
        }else if (ch == 4){
            
        }else{
            printf("\n\nInvalid Option.\n\n");
        }
    
    } while (ch!=4);
    
    return 0;
}
