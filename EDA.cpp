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

int ShortestPath(int source, int destination);
void Dijkstra(int source, int n);
void SetInitialDistancesToInfinity();
void FillListWithData();
void CamMin();
void Menu();
void PresentCidades();

class comparator{
	public:
		bool operator()(pair<int, int> &a1, pair<int, int> &a2){
			return a1.second > a2.second;
		}
};

int main(){
	FillListWithData();

	Menu();

	return 0;
}

void Menu(){
	int option;

	cout <<  "1) Verificar caminho mínimo entre duas cidades." << endl
	<< "2) Encerrar execução do programa." << endl
	<< "Selecione uma das opções: ";

	cin >> option;

	switch(option){
		case 1:
			CamMin();
			break;
		case 2:
			exit(0);
		default:
			cout << "\nOPÇÃO INVÁLIDA! TENTE NOVAMENTE.\n" << endl;
			Menu();
	}

}

void CamMin(){
	int source, destination;

	cout << "\n-------------------LISTA DE CIDADES-------------------\n" << endl;
	PresentCidades();

	cout << "Digite o índice da cidade de partida e o índice da cidade de destino: ";
	cin >> source >> destination;

	int shortest = ShortestPath(source, destination);
	cout << "MENOR CAMINHO DE " << source << " PARA " << destination << " = " << shortest << "km" << endl;
	cout << "\n-------------------------------------------------------\n" << endl;
	Menu();
}

void Dijkstra(int source){

	SetInitialDistancesToInfinity();
	
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

int ShortestPath(int source, int destination){
	Dijkstra(source);

	if(dis[destination] != INFINITY){
		return dis[destination];
	}else{
		return -1;
	}

}

void SetInitialDistancesToInfinity(){
	for(int i = 0; i < numVertices; i++){
		dis[i] = INFINITY;
	}
}

void FillListWithData(){
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

void PresentCidades(){
	FILE *presentationIndices;
	presentationIndices = fopen("./Data/presentationIndices.txt", "r");

	if(presentationIndices == NULL){
		cout << "Erro ao abrir lista de cidades" << endl;
		return;
	}

	char ch;
	while(1){
		ch = fgetc(presentationIndices);
		if(ch != EOF){
			cout << ch;
		}else{
			break;
		}
	}

}