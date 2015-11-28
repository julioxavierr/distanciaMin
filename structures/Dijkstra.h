#include <string.h>
#include "Graph.h"

#define INFINITY (1 << 30)

typedef struct {

    int *minDistance;
    int *visited;
    Graph *graph;

} Dijkstra;

void initMinDistance(int **minDistance, int numberOfVertex, int source) {
    *minDistance = malloc(numberOfVertex * sizeof(int));
    int i;
    for(i = 0; i < numberOfVertex; ++i)
        (*minDistance)[i] = INFINITY;
    (*minDistance)[source] = 0;
}

void initVisited(int **visited, int numberOfVertex) {
    unsigned int size = numberOfVertex * sizeof(int);
    *visited = malloc(size);
    memset(*visited, 0, size);
}

void initDijkstra(Dijkstra *dijkstra, Graph *graph, int source) {
    dijkstra->graph = graph;
    initMinDistance(&(dijkstra->minDistance), graph->numberOfVertex, source);
    initVisited(&(dijkstra->visited), graph->numberOfVertex);
}

void findClosestVertexAvailable(Dijkstra *dijkstra, int *vertex, int *distance) {
    *distance = INFINITY;
    int numberOfVertex = dijkstra->graph->numberOfVertex,
        i;

    for(i = 0; i < numberOfVertex; ++i) {
        if(!dijkstra->visited[i] && dijkstra->minDistance[i] < *distance) {
            *distance = dijkstra->minDistance[i];
            *vertex = i;
        }
    }
}

void printMinDistance(int *minDistance, int size) {
    int i;
    for(i = 0; i < size; ++i)
        printf("minDistance[%d] = %d\n", i, minDistance[i]);
}

void relaxVertex(Dijkstra *dijkstra, int vertex) {
    printf("relaxing vertex %d\n", vertex);
    int currentDistance, newDistance, i;
    node *currentNode = dijkstra->graph->adjList[vertex]->head;
    Edge edge;


    for( ; currentNode != NULL; currentNode = currentNode->next) {
        edge = currentNode->edge;
        printf("next neighbor = %d\n", edge.to);
        if(!dijkstra->visited[edge.to]) {
            currentDistance = dijkstra->minDistance[edge.to];
            newDistance     = dijkstra->minDistance[vertex] +
                              edge.length;
            printf("currentDistance = %d\n", currentDistance);
            printf("newDistance = %d\n", newDistance);
            if(newDistance < currentDistance) {
                dijkstra->minDistance[edge.to] = newDistance;
            }
        }
    }
}

int shortestDistance(Dijkstra *dijkstra, int target) {
    int vertex = -1, distance = -1;
    while(1) {
        findClosestVertexAvailable(dijkstra, &vertex, &distance);
        printf("currentVertex = %d\n"
               "distance = %d\n\n", vertex, distance);
        if(distance == INFINITY)
            break;
        if(vertex == target)
            return distance;
        relaxVertex(dijkstra, vertex);
        dijkstra->visited[vertex] = 1;
    }
    //printMinDistance(dijkstra->minDistance, dijkstra->graph->numberOfVertex);
    return INFINITY;
}

void destroyDijkstra(Dijkstra *dijkstra) {
    free(dijkstra->minDistance);
    free(dijkstra->visited);
}
