/*
WAP To Create A Graph use the map of your city as the graph
using adjacency list / adjacency matrix and perform BFS and DFS

*/

// In BFS We Use Queue FIFO.
// In DFS We Use Statck LIFO.

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define vertex 6

int graph[vertex][vertex];
int visited[vertex]; 

typedef struct nd{
    int data;
    struct nd* next; 
} Node;

// For Queue
Node *qFront, *qRear;

// For Stack
Node *sTop;

void initStack(){
    sTop = NULL;
}

int sIsEmpty(){
    if (sTop == NULL)
    {
        return 1;
    }
    return 0;
}

void sPush(int data){
    Node *node = (Node *) malloc(sizeof(Node));
    node->data = data;
    node->next = sTop;
    sTop = node;
}

int sPop(){
    if (sIsEmpty() == 1)
    {
        printf("\n\nStack Is Empty\n\n");
        return 0;
    }
    Node *temp = sTop;
    sTop = sTop->next;
    // free(temp);
    return temp->data;
}

int sPeek(){
    if (sIsEmpty() == 1)
    {
        printf("\n\nStack Is Empty\n\n");
        return 0;
    }
    return sTop->data;
}

void sDisplay(){
    if (sIsEmpty() == 1)
    {
        printf("\n\nStack Is Empty\n\n");
        return;
    }
    Node *temp = qFront;
    printf("\n\nDisplaying Stack : \n\n");
    while (temp != NULL){
        printf(" %d ",temp->data);
        temp = temp->next;
    }
    printf("\n\n");
}

void initQueue(){
    qFront = NULL;
    qRear = NULL;
}

int qIsEmpty(){
    if (qFront == NULL || qRear == NULL)
    {
        return 1;
    }
    return 0; 
}

void enqueue(int data){
    Node *node = (Node*) malloc(sizeof(Node));
    node->data = data;
    if (qIsEmpty() == 1){
        qFront = qRear = node;
    }
    qRear->next = node;
    qRear = node;
}

int dequeue(){
    if (qIsEmpty() == 1)
    {
        printf("\n\nQueue Is Empty\n\n");
        return 0;
    }
    
    Node *temp = qFront;
    qFront = qFront->next;
    // free(temp);
    return temp->data;
}

int qPeek(){
    if (qIsEmpty() == 1)
    {
        printf("\n\nQueue Is Empty\n\n");
        return 0;
    }
    return qFront->data;
}

void qDisplay(){
    if (qIsEmpty() == 1)
    {
        printf("\n\nQueue Is Empty\n\n");
        return;
    }
    Node *temp = qFront;
    printf("\n\nDisplaying Queue : \n\n");
    
    while (temp != NULL){
        printf(" %d ",temp->data);
        temp = temp->next;
    }
    printf("\n\n");
}


void initGraph() {
    for (int i = 0; i < vertex; i++) {
        for (int j = 0; j < vertex; j++) {
            graph[i][j] = 0;
        }
        visited[i] = -1;
    }
}

void addEdge(int from, int to){
    if (from >= vertex && to >= vertex){
        printf("Vertex Is Out of Range");
        return;
    }
    graph[from][to] = 1;
}

void confiGraph(){
    initStack();
    initQueue();
    initGraph();
    addEdge(0,1);
    addEdge(1,2);
    addEdge(2,3);
    addEdge(2,4);
    addEdge(4,5);
}

void BFS(){
    
}

int main(int argc, char const *argv[])
{
    // Graph G1 Representation In Adjacency Matrix :
    // No Of Vertex
    confiGraph();

    return 0;
}
