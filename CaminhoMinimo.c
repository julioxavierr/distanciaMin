// Algorithm that finds the shortest path to a source city
// to a destination city
//
// Developed by Marlon Mendes and Júlio Xavier
// EDA - 2/2015
//
// Should be compiled using gcc.

#include "./structures/Dijkstra.h"

#define EDGES_COUNT 90
#define NUMBER_OF_VERTEX 27

void initializeGraph();
void freeGraph();
int calculateDistance(int source, int destination);
void Menu();
void PresentCities();
void CamMin();

Graph *graph;

int main(){
	initializeGraph();

	Menu();

	return 0;
}

void initializeGraph(){
	// Initializing graph
	graph = (Graph*) malloc(sizeof(Graph));
	initGraph(graph, NUMBER_OF_VERTEX);

	// Adding edges using an file with data
	FILE *arq; // File containing distances between cities 
	arq = fopen("./Data/listaAdjCidades.txt", "r");

	if(arq == NULL){
		printf("Erro ao abrir arquivo ");
		exit(0);
	}

	for(int i = 0; i < EDGES_COUNT; i++){
		int x, y, weight;
		fscanf(arq, "%i %i %i\n", &x, &y, &weight);
		addEdge(graph, x, y, weight);
	}

	fclose(arq);
}

void freeGraph(){
	destroyGraph(graph);
    free(graph);
}

int calculateDistance(int source, int destination){
	int distance = 0;

	// Building Dijkstra
	Dijkstra *dijkstra = malloc(sizeof(Dijkstra));
	initDijkstra(dijkstra, graph, source);

	distance = shortestDistance(dijkstra, destination);

	// Freeing Dijkstra
	destroyDijkstra(dijkstra);
	free(dijkstra);

	return distance;
}

void Menu(){
	int option = 2;

	printf("1) Verificar caminho mínimo entre duas cidades.\n2) Encerrar execução do programa.\nSelecione uma das opções: ");
	scanf("%d", &option);

	switch(option){
		case 1:
			CamMin();
			break;
		case 2:
			freeGraph();
			exit(0);
		default:
			printf("\nOPÇÃO INVÁLIDA! TENTE NOVAMENTE.\n");
			Menu();
	}

}

void CamMin(){
	int source = 0, destination = 0;

	printf("\n-------------------LISTA DE CIDADES-------------------\n");
	PresentCities();

	printf("Digite o índice da cidade de partida: ");
	scanf("%d", &source);
	printf("Digite o índice da cidade de destino: ");
	scanf("%d", &destination);

	int distance = calculateDistance(source, destination);
	printf("MENOR CAMINHO DE %d PARA %d = %d km", source, destination, distance);
	printf("\n-------------------------------------------------------\n");
	Menu();
}

void PresentCities(){
	FILE *presentationIndices;
	char ch;
	presentationIndices = fopen("./Data/presentationIndices.txt", "r");

	if(presentationIndices == NULL){
		printf("Erro ao carregar lista de cidades");
		exit(0);
	}

	while(1){
		ch = fgetc(presentationIndices);
		if(ch != EOF){
			printf("%c", ch);
		}else{
			break;
		}
	}

}