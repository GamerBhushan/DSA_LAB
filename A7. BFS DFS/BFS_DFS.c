/*
WAP To Create A Graph use the map of your city as the graph
using adjacency list / adjacency matrix and perform BFS and DFS

*/

// In BFS We Use Queue FIFO.
// In DFS We Use Statck LIFO.

#include <stdio.h>
#include <string.h>

void initGraph(int vertex, int g1[vertex][vertex]) {
    for (int i = 0; i < vertex; i++) {
        for (int j = 0; j < vertex; j++) {
            g1[i][j] = 0;
        }
    }
}


int main(int argc, char const *argv[])
{
    // Graph G1 Representation In Adjacency Matrix :
    // No Of Vertex
    int vertex = 6;
    int g1[vertex][vertex];
    initGraph(g1,vertex);

    return 0;
}
