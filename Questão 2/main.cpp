/*
* Aluno: Thiago da Silva Moraes
* Matricula: 232035137
* Atividade Avaliativa 2
* Questão 2
* Universidade de Brasília - Faculdade de Tecnologia
*/

#include <iostream>
#include <vector>
#include <sstream>

using namespace std;

class Conjunto {
	vector<int> elementos;

public:

	Conjunto uniao(Conjunto& outro) const { // a) retorna união de conjuntos
		Conjunto resultado = *this;
		for (int i : outro.elementos) {
			resultado.inserir(i);
		}
		return resultado;
	}

	Conjunto(){} // b) cria um conjunto vazio

	bool inserir(int elemento) { // c) insere
		bool i = !contem(elemento);
		if (i) elementos.push_back(elemento);
		else return false;
		return true;
	}

	void remover(int elemento) { // d) remove
		elementos.erase(remove(elementos.begin(), elementos.end(), elemento), elementos.end());
	}

	Conjunto intersec(Conjunto c) { // e) intersecção
		Conjunto r;
		for (int i : elementos) if (c.contem(i)) r.inserir(i);
		return r;
	}

	Conjunto dif(Conjunto c) { // f) diferença
		Conjunto r;
		for (int i : elementos) if (!c.contem(i)) r.inserir(i);
		return r;
	}

	bool contem(int elemento) const { // g) testa se pertence ao conjunto
		return find(elementos.begin(), elementos.end(), elemento) != elementos.end();
	}

	int testaMenor() { // h) retorna menor valor
		return *min_element(elementos.begin(), elementos.end());

	}

	int testaMaior() { // h) retorna maior valor
		return *max_element(elementos.begin(), elementos.end());
	}

	bool saoIguais(Conjunto c) { // i) testa se os conjuntos são iguais
		if (elementos.size() != c.tamanho()) return false;
		for (int i : elementos) if (!c.contem(i)) return false;
		return true;
	}

	int tamanho() { // j) tamanho
		return elementos.size();
	}

	bool seVazio() const { // testa se o conjunto é vazio
		return elementos.empty();
	}

	string toString() {
		stringstream ss;
		ss << "{";
		for (size_t i = 0; i < elementos.size(); ++i) {
			ss << elementos[i];
			if (i < elementos.size() - 1) {
				ss << ", ";
			}
		}
		ss << "}" << endl;
		return ss.str();
	}
};

int main() {
	setlocale(LC_ALL, "");

	Conjunto teste1;
	teste1.inserir(123);
	teste1.inserir(456);
	teste1.inserir(789);
	teste1.inserir(12);

	Conjunto teste2;
	teste2.inserir(184);
	teste2.inserir(484);
	teste2.inserir(784);
	teste2.inserir(84);

	Conjunto teste3;


	cout 
		<< "Conjunto 1: "
		<< teste1.toString();

	cout 
		<< "Conjunto 2: "
		<< teste2.toString();

	Conjunto uniao = teste1.uniao(teste2);
	cout 
		<< "União 1 e 2: ";
	uniao.toString();

	Conjunto interseccao = teste1.intersec(teste2);
	cout 
		<< "Intersecção 1 e 2: "
		<< interseccao.toString() << endl;

	Conjunto diferenca = teste1.dif(teste2);
	cout 
		<< "Diferença 1 e 2: "
		<< diferenca.toString()
		<< endl;

	cout << "Tamanho do Conjunto 1: " << teste1.tamanho() << endl;

	cout << "Conjunto 1 está vazio? " << (teste1.seVazio() ? "Sim" : "Não") << endl;

	cout << "Conjunto 3 está vazio? " << (teste3.seVazio() ? "Sim" : "Não") << endl;

	cout 
		<< "Menor e maior valores no Conjunto 1: "
		<< "Menor = " << teste1.testaMenor() << ", Maior = " << teste1.testaMaior() << endl;

	return 0;
}