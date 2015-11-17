#include <iostream>
#include <string>
#include <climits>
#include <vector> // Devemos usar nossa própria
#include <queue> // Devemos usar nossa própria
using namespace std;

#define INFINITY INT_MAX
#define EDGES_COUNT 90 // Normalmente seria 45, porém foram feitos também caminhos inversos (*2)

const int numVertices = 27; // Numero de vertices
vector<pair<int,int> > adjList[numVertices]; // Lista de adjacencia
int dis[numVertices]; // Guarda a menor distância
bool vis[numVertices] = {0}; // Determina quando o nó foi ou não visitado

int shortestPath(int source, int destination);
void Dijkstra(int source, int n);
void setInitialDistancesToInfinity();
void fillListWithData();

class comparator{
	public:
		bool operator()(pair<int, int> &a1, pair<int, int> &a2){
			a1.second > a2.second;
		}
};

int main(){
	fillListWithData();

	int source, destination;
	cout << "Digite o índice da cidade de partida e o índice da cidade destino: ";
	cin >> source >> destination;
	cout << "MENOR CAMINHO DE " << source << " PARA " << destination << " = " << shortestPath(source, destination) << endl;

	return 0;
}

void Dijkstra(int source){

	setInitialDistancesToInfinity();

	priority_queue<pair<int,int> ,vector<pair<int,int> >,comparator> pq;

	// Adicionando source (nó de partida) com distancia dele mesmo sendo 0
	pq.push(make_pair(source, dis[source] = 0));

	while(pq.empty() == false){
		pair<int, int> curr = pq.top();
		pq.pop();

		int cv = curr.first;
		int cw = curr.second;
		vis[cv] = true; // Marca como visitado

		for(int i = 0; i < adjList[cv].size(); i++){
			// Verifica se ainda não foi visitado...
			if(vis[adjList[cv][i].first] == false){
				// ... Verifica se a distancia é menor que a distância atual...
				if((adjList[cv][i].second+cw) < (dis[adjList[cv][i].first])){
					// ... Se sim, atualiza
					pq.push(make_pair(adjList[cv][i].first, (dis[adjList[cv][i].first]=adjList[cv][i].second+cw)));
				}
			}
		}

	}

}

int shortestPath(int source, int destination){
	Dijkstra(source);

	if(dis[destination] != INFINITY){
		return dis[destination];
	}else{
		return -1;
	}

}

void setInitialDistancesToInfinity(){
	for(int i = 0; i < numVertices; i++){
		dis[i] = INFINITY;
	}
}

void fillListWithData(){
	FILE *arq; // Arquivo contendo distâncias entre cidades 
	arq = fopen("./Data/listaCidades.txt", "r");

	if(arq == NULL){
		cout << "Erro ao abrir arquivo " << endl;
		return;
	}

	for(int i = 0; i < EDGES_COUNT; i++){
		int x, y, weight;
		fscanf(arq, "%i %i %i\n", &x, &y, &weight);
		adjList[x].push_back(make_pair(y, weight));
		adjList[x].push_back(make_pair(x, weight));
	}

	fclose(arq);

}