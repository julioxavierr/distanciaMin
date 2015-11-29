#include "Dijkstra.h"

int main() {

    // BUILDING THE GRAPH
    Graph *graph = malloc(sizeof(Graph));
    int numberOfVertex = 5;

    initGraph(graph, numberOfVertex);

    addEdge(graph, 0, 1, 1); 
    addEdge(graph, 1, 0, 1);

    addEdge(graph, 0, 2, 8);
    addEdge(graph, 2, 0, 8);

    addEdge(graph, 0, 3, 3);
    addEdge(graph, 3, 0, 3);

    addEdge(graph, 1, 2, 5);    // distance between vertex 1 and 2 is 5
    addEdge(graph, 2, 1, 5);

    addEdge(graph, 3, 4, 1);
    addEdge(graph, 4, 3, 1);

    addEdge(graph, 4, 2, 1);
    addEdge(graph, 2, 4, 1);

    // BUILDING DIJKSTRA;
    
    Dijkstra *dijkstra = malloc(sizeof(Dijkstra));
    int source = 2,            // leaving from "source"
        target = 0;            // goint to "target"
    initDijkstra(dijkstra, graph, source);

    int distance = shortestDistance(dijkstra, target);
    printf("shortest distance from %d to %d is = %d\n", source,
                                                        target,
                                                        distance);
    // DESTROYING (FREEING) STRUCTURES
    destroyDijkstra(dijkstra);
    destroyGraph(graph);
    free(dijkstra);
    free(graph);

    return 0;
}
