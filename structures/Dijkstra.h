#include <utility>
#include "Graph.h"
#define INF (1 << 30)

class Dijkstra {
private:
    Graph graph;
    Vector<int> minDistance;
    Vector<bool> visited;
    int numberOfVertex;

    void setMinDistance(int source);
    void setVisited();
    void findClosestVertexAvailable(int &vertex, int &distance);
    void relaxVertex(const int vertex, const int distance);

public:
    Dijkstra(Graph graph) {
        this->graph = Graph(graph);
        numberOfVertex = this->graph.getNumberOfVertex();
    }

    int shortestDistance(int source, int target) {
        setMinDistance(source);
        setVisited();

        while(true) {
            int vertex, distance;
            findClosestVertexAvailable(vertex, distance);
            if(distance == INF) break;
            if(vertex == target)
                return distance;
            relaxVertex(vertex, distance);
        }
    }
};

void Dijkstra::setMinDistance(int source) {
    this->minDistance = Vector<int>(numberOfVertex, INF);
    minDistance[source] = 0;
}

void Dijkstra::setVisited() {
    this->visited = Vector<bool>(numberOfVertex, false);
}

void Dijkstra::findClosestVertexAvailable(int &vertex, int &distance) {
    distance = INF;
    for(int i = 0; i < numberOfVertex; ++i) {
        if(!visited[i] and minDistance[i] < distance) {
            distance = minDistance[i];
            vertex = i;
        }
    }
}

void Dijkstra::relaxVertex(const int vertex, const int distance) {
    Node<Graph::Edge> * currentEdge = graph.adjList[vertex].getHead();
    for(int v = 0; v < graph.adjList[vertex].size(); ++v) {
        int to = currentEdge->data.to;
        int length = currentEdge->data.length;

        if(!visited[to]) {
            int currentDistance = minDistance[to];
            int newDistance = distance + length;
            
            if(newDistance < currentDistance)
                minDistance[to] = newDistance;
        }
    }
}
