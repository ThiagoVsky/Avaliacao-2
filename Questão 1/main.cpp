#include <iostream>
#include <map>
#include <vector>
#include <sstream>

using namespace std;

struct Reserva
{
	string
		usuario,
		data,
		horario;

	Reserva(string usuario, string data, string horario)
		: usuario(usuario), data(data), horario(horario) { }
};

enum Quadra {
	TENIS = 0,
	FUTEBOL,
	BASQUETE,
	BASEBALL,
	VOLEI
};

class SistemaReserva {

	map<Quadra, vector<Reserva>> reservaQuadra;

	bool res(Quadra quadra, string usuario, string data, string horario) {
		for (auto i : reservaQuadra[quadra]) {
			if (i.data == data && i.horario == horario) return false;
		}
		reservaQuadra[quadra].emplace_back(usuario, data, horario);
		return true;
	}

	bool rem(Quadra quadra, string data, string horario) {

		for (auto i = reservaQuadra[quadra].begin(); i != reservaQuadra[quadra].end(); i++) {
			if (i->data == data && i->horario == horario) {
				reservaQuadra[quadra].erase(i);
				cout << typeid(i).name() << endl; // teste
				return true;
			}
			return false;
		}
	}

	string quadraPrint(Quadra quadra) {
		switch (quadra) {
		case 0: return "Tênis";
		case 1: return "Futebol";
		case 2: return "Basquete";
		case 3: return "Baseball";
		case 4: return "Vôlei";
		default: return "UAI, algo deu errado";
		}
	}

public:

	void reservar(Quadra quadra, string usuario, string data, string horario) {
		stringstream ss;
		if (res(quadra, usuario, data, horario)) {
			ss
				<< "Reserva feita com sucesso!" << endl
				<< "Quadra: " << quadraPrint(quadra) << endl
				<< "Usuário: " << usuario << endl
				<< "data: " << data << endl
				<< "horário: " << horario << endl << endl;
			cout << ss.str();
		}
		else ss << "ERRO! não foi possível reservar! Tente outro horário." << endl;
		cout << ss.str();
	}

	void removerReserva(Quadra quadra, string data, string horario) {
		if (rem(quadra, data, horario)) {
			cout << "Reserva removida com sucesso!" << endl;
		}
		else {
			cout << "Reserva não localizada." << endl;
		}
		listarReservas(quadra);
	}

	void listarReservas(Quadra quadra) {
		
		cout << "Reservas feitas para a quadra " << quadraPrint(quadra) << ":" << endl;
		for (auto i = reservaQuadra[quadra].begin(); i != reservaQuadra[quadra].end(); i++) {
			cout
				<< "Usuário: " << i->usuario << "; "
				<< "Data: " << i->data << "; "
				<< "Horário: " << i->horario << endl << endl;
		}

	}
};

int main() {
	setlocale(LC_ALL, "");
	SistemaReserva sistema;


	sistema.reservar(TENIS, "Jonas", "01/12/2024", "10:00");
	sistema.reservar(TENIS, "Alberto", "01/12/2024", "11:00");
	sistema.reservar(FUTEBOL, "Carlos", "02/12/2024", "15:00");
	sistema.reservar(FUTEBOL, "Manoel", "02/12/2024", "15:00");
	sistema.reservar(FUTEBOL, "Manoel", "02/12/2024", "16:00");

	sistema.listarReservas(TENIS);
	sistema.listarReservas(FUTEBOL);
	sistema.listarReservas(VOLEI);

	sistema.removerReserva(TENIS, "01/12/2024", "10:00");
	sistema.removerReserva(TENIS, "10/01/2025", "10:00");
	sistema.listarReservas(TENIS);
	sistema.listarReservas(FUTEBOL);
}