/*
* Aluno: Thiago da Silva Moraes
* Matricula: 232035137
* Atividade Avaliativa 2
* Questão 4 - main
* Universidade de Brasília - Faculdade de Tecnologia
*/
#include "MatrizQuadrada.h"

using namespace std;

int posicao(int x, int y, int tam) {
	int dim = sqrt(tam);
		int it = -1;
		for (int i = 0; i <= x; i++) {
			for (int j = 0; j <= y; j++) it++;
			if (i != x && dim != y) it += dim - y - 1;
		}
		return it;
}

void imprime(vector<float> matriz) {
	int dim = sqrt(matriz.size());
	for (int x = 0; x < dim; x++) {
		for (int y = 0; y < dim; y++) cout << matriz[posicao(x, y, matriz.size())] << "\t";
		cout << endl;
	}
	cout << endl;
}

void imprimeVector(vector<float> vetor) {
	for (int i = 0; i < vetor.size(); i++) {
		cout << vetor[i] << " ";
	}
	cout << endl;
}

int main() {

	MatrizQuadrada m(4);

	m.imprime();

	imprime(m.getMatrix());

	imprime(m.transpose());

	imprimeVector(m.diagonal(1));

	imprimeVector(m.diagonal(2));

	m.fill(5, 4, 3.14159);

	m.setXY(4, 3, 789.987);

	m.imprime();

	cout << endl << "final: " << m.getXY(4, 3);

}

