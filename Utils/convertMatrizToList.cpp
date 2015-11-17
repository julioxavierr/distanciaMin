// Algoritmo usado durante o trabalho de EDA 2/2015
// para converter matriz de adjacência
// para lista de adjacência


#include <iostream>
#include <fstream>
using namespace std;

#define ORDEM_MATRIZ 27

float distances[ORDEM_MATRIZ][ORDEM_MATRIZ];
FILE *result;

void LoadMatriz() {
	int x, y;
	ifstream in("../Data/matrizcidades.txt");

	if (!in) {
	cout << "Cannot open file.\n";
	return;
	}

	for (y = 0; y < ORDEM_MATRIZ; y++) {
		for (x = 0; x < ORDEM_MATRIZ; x++) {
			in >> distances[x][y];
		}
	}

	in.close();
}

int main(){
	LoadMatriz();

	result = fopen("../Data/listaCidades.txt", "w+");

	int k = 0;
	for(int i = 0; i < ORDEM_MATRIZ; i++){
		for(int j = k; j < ORDEM_MATRIZ; j++){
			if(distances[i][j] != 0){
				fprintf(result, "%i %i %i\n", i, j, int(distances[i][j])); // Normal
				fprintf(result, "%i %i %i\n", j, i, int(distances[i][j])); // Inverso
			}
		}
		k++;
	}

	fclose(result);
}