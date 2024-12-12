#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct {
    char label[100];
    int id;
} Vertex;

typedef struct {
    Vertex *from, *to;
    int distance;
}Edge;

typedef struct {
    int totalVertex, totalEdge;
    Vertex *vertexList;
    Edge *edgeList;
}Graph;

Graph *createGraph(int tv,int te);
void initGraph(Graph *graph);


Graph *createGraph(int tv,int te){
    Graph *graph = (Graph*) malloc(sizeof(Graph));
    graph->vertexList = (Vertex*) malloc(tv * sizeof(Vertex));
    graph->edgeList = (Edge*) malloc(te*sizeof(Edge));
    graph->totalVertex = tv;
    graph->totalEdge = te;

    return graph;
}

void initGraph(Graph *graph){
    int tv = graph->totalVertex;
    for (int i = 0; i < tv; i++)
    {
        graph->vertexList[i].id = i;
        strcpy(graph->vertexList[i].label,"Bhushan");
    }
    
    printf("\nDisplaying Graph\n\n");
    for (int i = 0; i < tv; i++)
    {
        printf("Vertex %d ID : %d,  Name : %s\n",i+1,graph->vertexList[i].id,graph->vertexList[i].label);
    }
}

int main(int argc, char const *argv[]){

    int nv,ne;
    printf("Enter Total Number of Vertex : ");
    scanf("%d",&nv);
    printf("Enter Total Number of Edges : ");
    scanf("%d",&nv);
    Graph *graph = createGraph(nv,ne);

    free(graph->edgeList);
    free(graph->vertexList);
    free(graph);
    return 0;
}
