#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 5

struct Queue
{
    int front, rear;
    int tickets[MAX_SIZE];
};

void initQueue(struct Queue *q)
{
    q->front = -1;
    q->rear = -1;
}

int isEmpty(struct Queue *q)
{
    return (q->front == -1);
}

int isFull(struct Queue *q)
{
    return ((q->rear + 1) % MAX_SIZE == q->front);
}

void submitTicket(struct Queue *q, int ticket_id)
{
    if (isFull(q))
    {
        printf("Queue is full! Cannot accept more tickets.\n");
    }
    else
    {
        if (q->front == -1)
        {
            q->front = 0;
        }
        q->rear = (q->rear + 1) % MAX_SIZE;
        q->tickets[q->rear] = ticket_id;
        printf("Ticket %d submitted successfully.\n", ticket_id);
    }
}

void processTicket(struct Queue *q)
{
    if (isEmpty(q))
    {
        printf("No tickets to process.\n");
    }
    else
    {
        int processedTicket = q->tickets[q->front];
        printf("Ticket %d processed.\n", processedTicket);
        if (q->front == q->rear)
        {

            q->front = q->rear = -1;
        }
        else
        {
            q->front = (q->front + 1) % MAX_SIZE;
        }
    }
}

void displayQueue(struct Queue *q)
{
    if (isEmpty(q))
    {
        printf("Queue is empty.\n");
    }
    else
    {
        printf("Current Queue Status: ");
        int i = q->front;
        while (i != q->rear)
        {
            printf("%d -> ", q->tickets[i]);
            i = (i + 1) % MAX_SIZE;
        }
        printf("%d\n", q->tickets[q->rear]);
    }
}

int main()
{
    struct Queue ticketQueue;
    initQueue(&ticketQueue);

    int choice, ticket_id;

    do
    {

        printf("\nCustomer Support Ticket Management System\n");
        printf("1. Submit a Ticket\n");
        printf("2. Process a Ticket\n");
        printf("3. Display Current Queue Status\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:

            printf("Enter Ticket ID to submit: ");
            scanf("%d", &ticket_id);
            submitTicket(&ticketQueue, ticket_id);
            break;
        case 2:

            processTicket(&ticketQueue);
            break;
        case 3:

            displayQueue(&ticketQueue);
            break;
        case 4:
            printf("Exiting the program...\n");
            break;
        default:
            printf("Invalid choice! Please enter a valid option.\n");
        }

    } while (choice != 4);

    return 0;
}
