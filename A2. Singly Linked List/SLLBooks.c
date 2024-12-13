#include<stdio.h>
#include<stdlib.h>
#include<string.h>


typedef struct bk{
    char Name[100];
    double Price;
    struct bk *Next;
}BookNode;



BookNode *createBookNode(char name[], double price){
    BookNode *node = (BookNode*) malloc(sizeof(BookNode));
    strcpy(node->Name,name);
    node->Price = price;
    node->Next = NULL;
    return node;
}

void count(BookNode *head){
    if (head == NULL){
        printf("\n\nList Is Empty.\n\n");
        return;
    }
    int cnt = 0;
    BookNode *temp = head;
    while (temp != NULL){
        cnt++;
        temp = temp->Next;
    }
    printf("Total Number Of Books : %d",cnt);
    
}
void displayPerticularBook(BookNode *node){
    printf("\n\nBook Name : %s",node->Name);
    printf("\nBook Price : %f\n\n",node->Price);

}

void displayBooks(BookNode *head){
    if (head == NULL){
        printf("\n\nList Is Empty.\n\n");
        return;
    }
    BookNode *temp = head;
    printf("\n\nDisplaying Books : ");
    while (temp != NULL){
        displayPerticularBook(temp);
        temp = temp->Next;
    }
}

void searchBookByName(BookNode *head,char name[]){
    if (head == NULL){
        printf("\n\nList Is Empty.\n\n");
        return;
    }
    int flag = 0;
    BookNode *temp = head;
    while (temp != NULL){
        if (strcmp(temp->Name,name) == 0){
            printf("\nBook Found : \n");
            displayPerticularBook(temp);
            flag = 1;
        }
        temp = temp->Next;
    }
    if (flag == 0){
        printf("\n\nBook '%s' is Not Found.\n\n",name);
    }
}

void insertBook(BookNode **head,char name[],double price){
    if (*head == NULL){
        *head = createBookNode(name,price);
    }else{
        BookNode *temp = *head;
        while (temp->Next != NULL){
            temp = temp->Next;
        }
        temp->Next = createBookNode(name,price);
    }
}

void removeBook(BookNode *head, char name[]){
    if (head == NULL){
        printf("\n\nList Is Empty.\n\n");
        return;
    }
    BookNode *temp = head, *prev = head;
    int flag = 0;
    while (temp != NULL){
        if(strcmp(temp->Name,name) == 0){
            if (prev == head){
                prev = temp->Next;
            }else{
                prev->Next = temp->Next;   
            }
            printf("\n\nSuccessfully Removed : %s\n\n",temp->Name);
            free(temp);
            flag = 1;
            break;
        }
        prev = temp;
        temp = temp->Next;
    }
    if (flag == 0)
    {
        printf("\n\nBook '%s' is Not Found.\n\n",name);
    }
    
}

void menu(){
    printf("\n1. Add Book.");
    printf("\n2. Remove Book.");
    printf("\n3. Search Book.");
    printf("\n4. Display All Book.");
    printf("\n5. Exit.");
    printf("\nChoose Your Option : ");
}



int main(int argc, char const *argv[]){
    BookNode *head = NULL;
    int ch;
    do{
        menu();
        scanf("%d",&ch);
        if (ch == 1){
            char name[100];
            double price = 0;
            printf("\n\nEnter Book Name : ");
            scanf("%s",&name);
            printf("\n\nEnter Book Price : ");
            scanf("%f",&price);
            insertBook((&head),name,price);
        }else if (ch == 2){
            char name[100];
            printf("\n\nEnter Book Name : ");
            scanf("%s",&name);
            removeBook(head,name);
        }else if (ch == 3){
            char name[100];
            printf("\n\nEnter Book Name : ");
            scanf("%s",&name);
            searchBookByName(head,name);
        }else if (ch == 4){
            displayBooks(head);
        }else if (ch == 5){

        }else{
            printf("\n\nInavlid Option.\n\n");
        }
        
    } while (ch!=5);

    free(head);    
    return 0;
}
