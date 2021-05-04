#include <locale.h>
#include "Data.hpp"
#include "Esportes.hpp"
#include "Jogador.hpp"
#include "Time.hpp"
#include "Empresa.hpp"

int main() {
	setlocale(LC_ALL, "Portuguese");

	#pragma region Asci para deixar bonitinho

		cout << "       _            ______  _____        _    _____      " << endl;
		cout << "      | |           | ___ \\|  _  |      | |  |  _  |     " << endl;
		cout << "    __| |  ___  ___ | |_/ /| | | | _ __ | |_ | | | | ___ " << endl;
		cout << "   / _` | / _ \\/ __||  __/ | | | || '__|| __|| | | |/ __|" << endl;
		cout << "  | (_| ||  __/\\__ \\| |    \\ \\_/ /| |   | |_ \\ \\_/ /\\__ \\" << endl;
		cout << "   \\__,_| \\___||___/\\_|     \\___/ |_|    \\__| \\___/ |___/" << endl;
		cout << "                                                         " << endl;
		cout << "==========================================================" << endl;
		cout << "                                                         " << endl;

	#pragma endregion

	#pragma region DefineEsportes
		struct Esportes futebol;
		futebol.nome = "Futebol";
		futebol.idadeAposentadoria = 40;

		struct Esportes xadrez;
		xadrez.nome = "Xadrez";
		xadrez.idadeAposentadoria = 70;

		struct Esportes peteca;
		peteca.nome = "Peteca";
		peteca.idadeAposentadoria = 50;

		struct Esportes truco;
		truco.nome = "Truco";
		truco.idadeAposentadoria = 65;

		struct Esportes tenis_de_mesa;
		tenis_de_mesa.nome = "Tênis de mesa";
		tenis_de_mesa.idadeAposentadoria = 45;
	
		struct Esportes lol;
		lol.nome = "League of Legends";
		lol.idadeAposentadoria = 30;

	#pragma endregion

	Jogador vagner("Vágner Lenon", futebol, Data(30, 9, 1983), "Brasileiro", true, 1500.f);
	Jogador vagner_2("Vágner Lolzeiro", futebol, Data(30, 9, 1983), "Brasileiro", true, 1500.f);

	Jogador amanda("Amanda Silva", lol, Data(30, 9, 1983), "Brasileiro", true, 5300.f);
	Jogador pepe("Pepe", lol, Data(30, 9, 1983), "Brasileiro", true, 450.f);

	Time timeDeFutebol("Time de Futebas", futebol);

	timeDeFutebol.AdicionaJogador(vagner_2);
	timeDeFutebol.AdicionaJogador(vagner);

	Time timeDeLol("Time de Lol", lol);

	timeDeLol.AdicionaJogador(amanda);
	timeDeLol.AdicionaJogador(pepe);

	Empresa emp = Empresa("Empresa de lol");
	emp.AdicionaTime(timeDeFutebol);
	emp.AdicionaTime(timeDeLol);

	emp.RelatorioFinanceiro();

	//cout << vagner_2.GetMatricula() <<  endl;
	
	system("pause");
	return 0;
}