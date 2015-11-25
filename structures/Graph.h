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
    
    Graph() {}
    Graph(int numberOfVertex) {
        this->adjList = Vector< List<Edge> >(numberOfVertex);
    }
    Graph(Graph &graph);
    void addEdge(int from, int to, int length);
    int getNumberOfVertex();
};

void Graph::addEdge(int from, int to, int length) {
    Edge edge = Edge(to, length);
    this->adjList[from].push_front(edge);
}

int Graph::getNumberOfVertex() {
    return this->adjList.size();
}

Graph::Graph(Graph &graph) {
    int numberOfVertex = graph.getNumberOfVertex();
    this->adjList = Vector< List<Edge> >(numberOfVertex);

    for(int i = 0; i < numberOfVertex; ++i) {
        this->adjList[i] = List<Edge>(graph.adjList[i]);
    }
}
