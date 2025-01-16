/*
* Aluno: Thiago da Silva Moraes
* Matricula: 232035137
* Atividade Avaliativa 2
* Questão 3
* Universidade de Brasília - Faculdade de Tecnologia
*/
#include <iostream>

#define PI 3.14159265359

using namespace std;

class Paralelepipedo {
	double
		altura,
		largura,
		profundidade;
public:
	Paralelepipedo(double a, double b, double c) : altura(a), largura(b), profundidade(c) {}

	double getAltura() { return altura; }
	double getLargura() { return largura; }
	double getProfundidade() { return profundidade; }

	double getArea() { return 2 * ((altura * largura) + (altura * profundidade) + (largura * profundidade)); }
	double getVolume() { return profundidade * largura * altura; }

};

class Cilindro {
	double
		raio,
		altura;
public:
	Cilindro(double r, double a) : raio(r), altura(a){}

	double getAltura() { return altura; }
	double getRaio() { return raio; }
	double getArea() { return 2 * PI * raio * (raio + altura); }
	double getVolume() { return PI * (raio * raio) * altura; }
};

class Esfera {
	double raio;
public:
	Esfera(double r) : raio(r) {}

	double getRaio() { return raio; }
	double getArea() { return 4 * PI * (raio * raio); }
	double getVolume() { return (4.0 * PI * (raio * raio * raio)) / 3.0; }
};

int main() {
	Paralelepipedo p(8.5, 4, 3);
	cout
		<< "Paralelepípedo:" << endl
		<< "Altura: " << p.getAltura() << endl
		<< "Largura: " << p.getLargura() << endl
		<< "Profundidade: " << p.getProfundidade() << endl
		<< "Area: " << p.getArea() << endl
		<< "Volume: " << p.getVolume() << endl << endl;

	Cilindro c(12, 15.6);
	cout
		<< "Cilindro:" << endl
		<< "Altura: " << c.getAltura() << endl
		<< "Raio: " << c.getRaio() << endl
		<< "Area: " << c.getArea() << endl
		<< "Volume: " << c.getVolume() << endl << endl;

	Esfera e(56);
	cout
		<< "Esfera:" << endl
		<< "Raio: " << e.getRaio() << endl
		<< "Diâmetro: " << e.getRaio() * 2 << endl
		<< "Area: " << e.getArea() << endl
		<< "Volume: " << e.getVolume() << endl << endl;

}