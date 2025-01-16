/*
* Aluno: Thiago da Silva Moraes
* Matricula: 232035137
* Atividade Avaliativa 2
* Questão 4 - MatrizQuadrada.cpp
* Universidade de Brasília - Faculdade de Tecnologia
*/
#include "MatrizQuadrada.h"

MatrizQuadrada::MatrizQuadrada(int n) : dimX(n), dimY(n){
	matrix.resize(dimX * dimY);

	for (float i = 0; i < (dimX * dimY); i++) matrix[i] = i + 1.0;
}
MatrizQuadrada::MatrizQuadrada(int n, float f) : dimX(n), dimY(n) {
	matrix.resize(dimX * dimY, f);
}

int MatrizQuadrada::_posicao(int x, int y) {
	if(x < dimX && y < dimX)
	{
		int it = -1;
		for (int i = 0; i <= x; i++) {
			for (int j = 0; j <= y; j++) it++;
			if (i != x && dimY != y) it += dimY - y - 1;
		}
		return it;
	}
	else {
		exit(1);
	}
}

float MatrizQuadrada::getXY(int x, int y) { return matrix[_posicao(x, y)]; }
void MatrizQuadrada::setXY(int x, int y, float f) { matrix[_posicao(x, y)] = f; }
vector<float> MatrizQuadrada::getMatrix() { return matrix; }
void MatrizQuadrada::fill(int x, int y, float f) { matrix.resize(x * y, f); }

vector<float> MatrizQuadrada::transpose() {
	vector<float> transpose(dimX * dimY);
	for (int y = 0; y < dimY; y++) {
		for (int x = 0; x < dimX; x++) {
			transpose[_posicao(x, y)] = matrix[_posicao(y, x)];
		}
	}

	return transpose;
}

vector<float> MatrizQuadrada::diagonal(int tipo) {
	vector<float> diagonal(dimX);

	if (tipo == 1) {
		for (int i = 0; i < dimX; i++) {
			diagonal[i] = matrix[_posicao(i, i)];
		}
	}
	else if (tipo == 2) {
		for (int i = 0; i < dimX; i++) {
			int j = dimX - 1 - i;
			diagonal[i] = matrix[_posicao(i, j)];
		}
	}
	else exit(2);

	return diagonal;
}


void MatrizQuadrada::imprime() {
	for (int x = 0; x < dimX; x++) {
		for (int y = 0; y < dimY; y++) cout << matrix[_posicao(x, y)] << "\t";
		cout << endl;
	}
		cout << endl;
}
