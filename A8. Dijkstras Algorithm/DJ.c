#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define MAX 100
#define INF INT_MAX

// Structure for adjacency list node
typedef struct Node {
    int vertex;
    int weight;
    struct Node* next;
} Node;

// Structure for adjacency list
typedef struct {
    Node* head;
} AdjList;

// Function prototypes
void addEdgeMatrix(int graph[MAX][MAX], int src, int dest, int weight);
void addEdgeList(AdjList* adjList, int src, int dest, int weight);
void dijkstra(int graph[MAX][MAX], int n, int start, int end);
void printPath(int parent[], int j);
Node* createNode(int vertex, int weight);

// Function to create a new node for adjacency list
Node* createNode(int vertex, int weight) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->vertex = vertex;
    newNode->weight = weight;
    newNode->next = NULL;
    return newNode;
}

// Function to add an edge to the adjacency matrix
void addEdgeMatrix(int graph[MAX][MAX], int src, int dest, int weight) {
    graph[src][dest] = weight;
    graph[dest][src] = weight; // For undirected graph
}

// Function to add an edge to the adjacency list
void addEdgeList(AdjList* adjList, int src, int dest, int weight) {
    Node* newNode = createNode(dest, weight);
    newNode->next = adjList[src].head;
    adjList[src].head = newNode;

    newNode = createNode(src, weight);
    newNode->next = adjList[dest].head;
    adjList[dest].head = newNode;
}

// Function to find the vertex with the minimum distance value
int minDistance(int dist[], int sptSet[], int n) {
    int min = INF, min_index;
    for (int v = 0; v < n; v++) {
        if (sptSet[v] == 0 && dist[v] <= min) {
            min = dist[v];
            min_index = v;
        }
    }
    return min_index;
}

// Function to print the shortest path
void printPath(int parent[], int j) {
    if (parent[j] == -1) {
        printf("%d ", j);
        return;
    }
    printPath(parent, parent[j]);
    printf("-> %d ", j);
}

// Dijkstra's algorithm for finding the shortest path
void dijkstra(int graph[MAX][MAX], int n, int start, int end) {
    int dist[MAX];
    int sptSet[MAX] = {0};
    int parent[MAX];

    for (int i = 0; i < n; i++) {
        dist[i] = INF;
        parent[i] = -1;
    }
    dist[start] = 0;

    for (int count = 0; count < n - 1; count++) {
        int u = minDistance(dist, sptSet, n);
        sptSet[u] = 1;

        for (int v = 0; v < n; v++) {
            if (!sptSet[v] && graph[u][v] && dist[u] != INF && dist[u] + graph[u][v] < dist[v]) {
                dist[v] = dist[u] + graph[u][v];
                parent[v] = u;
            }
        }
    }

    printf("Shortest path from %d to %d is: ", start, end);
    printPath(parent, end);
    printf("\nTotal distance: %d\n", dist[end]);
}

int main() {
    int n, e, src, dest, weight;
    int graph[MAX][MAX] = {0};
    AdjList adjList[MAX];

    printf("Enter the number of areas in the city (nodes): ");
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        adjList[i].head = NULL;
    }

    printf("Enter the number of links (edges): ");
    scanf("%d", &e);

    printf("Enter the edges (src dest weight):\n");
    for (int i = 0; i < e; i++) {
        scanf("%d %d %d", &src, &dest, &weight);
        addEdgeMatrix(graph, src, dest, weight);
        addEdgeList(adjList, src, dest, weight);
    }

    int home, college;
    printf("Enter your home node: ");
    scanf("%d", &home);
    printf("Enter your college node: ");
    scanf("%d", &college);

    dijkstra(graph, n, home, college);

    return 0;
}