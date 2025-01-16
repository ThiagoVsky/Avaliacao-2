/*
* Aluno: Thiago da Silva Moraes
* Matricula: 232035137
* Atividade Avaliativa 2
* Questão 4 - MatrizQuadrada.h
* Universidade de Brasília - Faculdade de Tecnologia
*/
#pragma once

#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

class MatrizQuadrada
{
	vector<float> matrix;
	int
		dimX,
		dimY;
	int _posicao(int x, int y);
public:
	MatrizQuadrada(int n);
	MatrizQuadrada(int n, float f);

	float getXY(int x, int y);
	void setXY(int x, int y, float f);
	vector<float> getMatrix();

	void fill(int x, int y, float f);
	vector<float> transpose();
	vector<float> diagonal(int tipo);
	void imprime();



};

