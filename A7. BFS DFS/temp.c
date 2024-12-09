#include <stdio.h>
#include <stdlib.h>

#define MAX 20

typedef struct Node {
    int vertex;
    struct Node* next;
} Node;

typedef struct Graph {
    int numVertices;
    Node** adjLists;
    int** adjMatrix;
    int* visited;
} Graph;

// Function prototypes
Graph* createGraph(int vertices);
Node* createNode(int vertex);
void addEdgeList(Graph* graph, int src, int dest);
void addEdgeMatrix(Graph* graph, int src, int dest);
void printGraphList(Graph* graph);
void printGraphMatrix(Graph* graph);
void BFS(Graph* graph, int startVertex);
void DFSIterative(Graph* graph, int startVertex);
void DFSRecursive(Graph* graph, int startVertex);
void resetVisited(Graph* graph);

int main() {
    int vertices, edges, src, dest, startVertex;
    printf("Enter the number of Vertices : ");
    scanf("%d", &vertices);

    Graph* graph = createGraph(vertices);

    printf("Enter the number of Edges : ");
    scanf("%d", &edges);

    printf("Enter the edges (source and destination):\n");
    for (int i = 0; i < edges; i++) {
        scanf("%d %d", &src, &dest);
        addEdgeList(graph, src, dest); // For adjacency list
        addEdgeMatrix(graph, src, dest); // For adjacency matrix
    }

    printf("Adjacency List Representation:\n");
    printGraphList(graph);

    printf("\nAdjacency Matrix Representation:\n");
    printGraphMatrix(graph);

    printf("\nEnter the starting vertex for BFS and DFS: ");
    scanf("%d", &startVertex);

    printf("\nBFS Traversal: ");
    BFS(graph, startVertex);

    resetVisited(graph);
    printf("\nDFS Traversal (Iterative): ");
    DFSIterative(graph, startVertex);

    resetVisited(graph);
    printf("\nDFS Traversal (Recursive): ");
    DFSRecursive(graph, startVertex);

    return 0;
}

// Function to create a graph
Graph* createGraph(int vertices) {
    Graph* graph = malloc(sizeof(Graph));
    graph->numVertices = vertices;

    graph->adjLists = malloc(vertices * sizeof(Node*));
    graph->adjMatrix = malloc(vertices * sizeof(int*));
    graph->visited = malloc(vertices * sizeof(int));

    for (int i = 0; i < vertices; i++) {
        graph->adjLists[i] = NULL;
        graph->adjMatrix[i] = malloc(vertices * sizeof(int));
        graph->visited[i] = 0;
        for (int j = 0; j < vertices; j++) {
            graph->adjMatrix[i][j] = 0;
        }
    }

    return graph;
}

// Function to create a node
Node* createNode(int vertex) {
    Node* newNode = malloc(sizeof(Node));
    newNode->vertex = vertex;
    newNode->next = NULL;
    return newNode;
}

// Add edge for adjacency list
void addEdgeList(Graph* graph, int src, int dest) {
    Node* newNode = createNode(dest);
    newNode->next = graph->adjLists[src];
    graph->adjLists[src] = newNode;

    newNode = createNode(src);
    newNode->next = graph->adjLists[dest];
    graph->adjLists[dest] = newNode;
}

// Add edge for adjacency matrix
void addEdgeMatrix(Graph* graph, int src, int dest) {
    graph->adjMatrix[src][dest] = 1;
    graph->adjMatrix[dest][src] = 1; // For undirected graph
}

// Print adjacency list
void printGraphList(Graph* graph) {
    for (int i = 0; i < graph->numVertices; i++) {
        printf("Vertex %d: ", i);
        Node* temp = graph->adjLists[i];
        while (temp) {
            printf("%d -> ", temp->vertex);
            temp = temp->next;
        }
        printf("NULL\n");
    }
}

// Print adjacency matrix
void printGraphMatrix(Graph* graph) {
    for (int i = 0; i < graph->numVertices; i++) {
        for (int j = 0; j < graph->numVertices; j++) {
            printf("%d ", graph->adjMatrix[i][j]);
        }
        printf("\n");
    }
}

// BFS traversal
void BFS(Graph* graph, int startVertex) {
    int queue[MAX], front = 0, rear = 0;
    queue[rear++] = startVertex;
    graph->visited[startVertex] = 1;

    while (front != rear) {
        int currentVertex = queue[front++];
        printf("%d ", currentVertex);

        Node* temp = graph->adjLists[currentVertex];
        while (temp) {
            int adjVertex = temp->vertex;
            if (!graph->visited[adjVertex]) {
                queue[rear++] = adjVertex;
                graph->visited[adjVertex] = 1;
            }
            temp = temp->next;
        }
    }
}

// DFS iterative
void DFSIterative(Graph* graph, int startVertex) {
    int stack[MAX], top = -1;
    stack[++top] = startVertex;

    while (top != -1) {
        int currentVertex = stack[top--];

        if (!graph->visited[currentVertex]) {
            printf("%d ", currentVertex);
            graph->visited[currentVertex] = 1;
        }

        Node* temp = graph->adjLists[currentVertex];
        while (temp) {
            int adjVertex = temp->vertex;
            if (!graph->visited[adjVertex]) {
                stack[++top] = adjVertex;
            }
            temp = temp->next;
        }
    }
}

// DFS recursive
void DFSRecursive(Graph* graph, int startVertex) {
    graph->visited[startVertex] = 1;
    printf("%d ", startVertex);

    Node* temp = graph->adjLists[startVertex];
    while (temp) {
        int adjVertex = temp->vertex;
        if (!graph->visited[adjVertex]) {
            DFSRecursive(graph, adjVertex);
        }
        temp = temp->next;
    }
}

// Reset visited array
void resetVisited(Graph* graph) {
    for (int i = 0; i < graph->numVertices; i++) {
        graph->visited[i] = 0;
    }
}
