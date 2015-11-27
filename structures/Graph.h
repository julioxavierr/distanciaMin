#include "List.h"

typedef struct {
    int numberOfVertex;
    List **adjList;
} Graph;

void initGraph(Graph *graph, int numberOfVertex) {
    graph->numberOfVertex = numberOfVertex;
    graph->adjList = malloc(numberOfVertex * sizeof(List*));
    
    int i;

    for(i = 0; i < numberOfVertex; ++i)
        graph->adjList[i] = malloc(sizeof(List));
}

void addEdge(Graph *graph, int from, int to, int length) {
    Edge edge;
    edge.to = to;
    edge.length = length;
    insertFront(graph->adjList[from], edge);
}

void destroyGraph(Graph *graph) {
    int i;
    for(i = 0; i < graph->numberOfVertex; ++i)
        destroyList(graph->adjList[i]);
    free(graph->adjList);
}

void printGraph(Graph *graph) {
    int i;
    for(i = 0; i < graph->numberOfVertex; ++i) {
        printf("from %d:\n", i);
        printList(graph->adjList[i]);
        printf("\n");
    }
}
