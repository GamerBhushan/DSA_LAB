#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>


#define MAX 5

typedef struct
{
    int id;
    char desc[100];
} Ticket;

typedef struct Queue
{
    int front;
    int rear;
    Ticket tickets[MAX];
} CircularQueue;

CircularQueue *TicketQueue;

void initQueue()
{
    TicketQueue = (CircularQueue *)malloc(sizeof(CircularQueue));
    TicketQueue->front = -1;
    TicketQueue->rear = -1;
}

bool isFull()
{
    return ((TicketQueue->rear + 1) % MAX == TicketQueue->front);
}

bool isEmpty()
{
    return (TicketQueue->front == -1);
}

void submitTicket()
{
    if (isFull())
    {
        printf("\nQueue is Full.\n");
    }
    else
    {
        TicketQueue->rear = (TicketQueue->rear + 1) % MAX;
        if (TicketQueue->front == -1)
        {
            TicketQueue->front = 0;
        }

        int ticket_id;
        char ticket_desc[100];

        printf("\nEnter Ticket ID: ");
        scanf("%d", &ticket_id);
        getchar();

        printf("Enter Ticket Description: ");
        fgets(ticket_desc, 100, stdin);
        ticket_desc[strcspn(ticket_desc, "\n")] = 0;

        TicketQueue->tickets[TicketQueue->rear].id = ticket_id;
        snprintf(TicketQueue->tickets[TicketQueue->rear].desc, sizeof(TicketQueue->tickets[TicketQueue->rear].desc), "%s", ticket_desc);

        printf("\nTicket %d submitted successfully.\n", ticket_id);
    }
}

void processTicket()
{
    if (isEmpty())
    {
        printf("\nNo tickets to process.\n");
    }
    else
    {
        int processedTicket = TicketQueue->tickets[TicketQueue->front].id;
        printf("Ticket %d processed: %s\n", processedTicket, TicketQueue->tickets[TicketQueue->front].desc);
        if (TicketQueue->front == TicketQueue->rear)
        {
            TicketQueue->front = TicketQueue->rear = -1;
        }else{
            TicketQueue->front = (TicketQueue->front + 1) % MAX;
        }
        
    }
}

void displayQueue()
{
    if (isEmpty())
    {
        printf("\nQueue is empty.\n");
    }
    else
    {
        printf("\nCurrent Queue Status: \n");
        int i = TicketQueue->front;
        while (i != TicketQueue->rear)
        {
            printf("Ticket ID: %d, Description: %s\n", TicketQueue->tickets[i].id, TicketQueue->tickets[i].desc);
            i = (i + 1) % MAX;
        }
        printf("Ticket ID: %d, Description: %s\n", TicketQueue->tickets[TicketQueue->rear].id, TicketQueue->tickets[TicketQueue->rear].desc);
    }
}

void menu()
{
    printf("\nCustomer Support Ticket Management System\n");
    printf("1. Submit a Ticket\n");
    printf("2. Process a Ticket\n");
    printf("3. Display Current Queue Status\n");
    printf("4. Exit\n");
    printf("\nChoose Your Option: ");
}

int main()
{
    initQueue();
    int ch = 0;
    do
    {
        menu();
        scanf("%d", &ch);
        if (ch == 1)
        {
            submitTicket();
        }
        else if (ch == 2)
        {
            processTicket();
        }
        else if (ch == 3)
        {
            displayQueue();
        }
        else if (ch == 4)
        {
            exit(0);
        }
    } while (ch != 4);

    return 0;
}
