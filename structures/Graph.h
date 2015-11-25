#include "Vector.h"
#include "List.h"

// graph representation as an adjacencyList;

class Graph {
public:
    class Edge {
        public:
            int to;
            int length;

        Edge() {}

        Edge(int to, int length) {
            this-> to = to;
            this-> length = length;
        }
    };

    Vector< List<Edge> > adjList;
    
    Graph(int numberOfVertex) {
        this->adjList = Vector< List<Edge> >(numberOfVertex);
    }
    void addEdge(int from, int to, int length);
};

void Graph::addEdge(int from, int to, int length) {
    Edge edge = Edge(to, length);
    this->adjList[from].push_front(edge);
}
