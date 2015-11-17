// Algoritmo usado durante o trabalho de EDA 2/2015
// para geração de uma matriz simétrica em arquivo .txt
// usando dados recolhidos

#include <iostream>
using namespace std;

float M[27][27];
FILE *arquivo;

void iniciaMatriz(){
	for(int i = 0; i<27; i++){
		for(int j = 0; j<27; j++){
			M[i][j] = 0;
		}
	}
}

void escreveMatriz(){
	for(int i = 0; i<27; i++){
		for(int j = 0; j<27; j++){
			if(j<26){
				fprintf(arquivo, "%.1f ", M[i][j]);
			}else{
				fprintf(arquivo, "%.1f\n", M[i][j]);
			}
		}
	}
}

void populaPosicao(int i, int j, float numero){
	M[i][j] = numero;
	M[j][i] = numero;
}

int main(){

	iniciaMatriz();

	arquivo = fopen("../Data/matrizcidades.txt", "w+");

	if(arquivo == NULL){
		cout << "ERRO AO ABRIR ARQUIVO!" << endl;
	}

	populaPosicao(0, 1, 21.2);
	populaPosicao(0, 5, 23.9);
	populaPosicao(0, 7, 49.9);
	populaPosicao(0, 15, 33.3);
	populaPosicao(0, 16, 37.1);
	populaPosicao(0, 17, 28.7);
	populaPosicao(0, 19, 22.6);

	populaPosicao(1, 2, 20.2);
	populaPosicao(1, 20, 29.2);

	populaPosicao(2, 3, 38.7);
	populaPosicao(2, 4, 51.7);

	populaPosicao(3, 5, 36.9);

	populaPosicao(5, 6, 34.7);
	populaPosicao(5, 7, 36.4);

	populaPosicao(6, 7, 29.3);
	populaPosicao(6, 8, 46.4);

	populaPosicao(7, 9, 25.0);
	populaPosicao(7, 15, 17.0);

	populaPosicao(8, 9, 69.8);
	populaPosicao(8, 25, 79.2);

	populaPosicao(9, 10, 43.0);
	populaPosicao(9, 12, 53.2);
	populaPosicao(9, 16, 63.4);
	populaPosicao(9, 17, 27.2);

	populaPosicao(10, 11, 27.8);
	populaPosicao(10, 12, 51.1);
	populaPosicao(11, 26, 95.2);

	populaPosicao(12, 13, 20.3);
	populaPosicao(12, 14, 20.7);

	populaPosicao(13, 14, 40.6);

	populaPosicao(15, 16, 52.3);

	populaPosicao(16, 24, 34.1);

	populaPosicao(17, 18, 23.3);
	populaPosicao(17, 22, 38.4);
	populaPosicao(17, 24, 19.7);

	populaPosicao(18, 19, 16.5);
	populaPosicao(18, 21, 36.8);
	populaPosicao(18, 22, 27.1);

	populaPosicao(19, 20, 18.3);
	populaPosicao(19, 21, 19.5);

	populaPosicao(20, 21, 19.7);

	populaPosicao(22, 23, 34.4);
	populaPosicao(22, 24, 55.7);

	populaPosicao(24, 23, 73.3);

	populaPosicao(25, 26, 105.0);
	escreveMatriz();

	fclose(arquivo);

	return 0;
}