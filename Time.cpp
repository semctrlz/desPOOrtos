#include "Time.hpp"
#include "Esportes.hpp"

int Time::ultimo_numero_matricula = 0;

Time::Time(string nome, Esportes esporte) {
	this->nome = nome;
	this->esporte = esporte;
}

void Time::AdicionaJogador(Jogador jogador) {
	if (jogador.GetEsporte().nome != this->esporte.nome) {
		cout 
			<< "O Jogador não pode entrar para este time pois o jogador pratica " 
			<< jogador.GetEsporte().nome 
			<< " e este time é de " 
			<< this->esporte.nome 
			<< endl;		
	}
	else {
		for (Jogador jogador_existente : this->jogadores) {
			if (jogador_existente.GetMatricula() == jogador.GetMatricula())
			{
				cout << "O jogador " << jogador.GetNome() << " já está neste time." << endl;
				return;
			}
		}

		this->jogadores.push_back(jogador);		
	}
}

void Time::RelatorioGeral() {
	Utils::PreencheTexto("=", 58);
	cout << endl;
	Utils::Titulo("Relatório geral do time " + this->nome, "=", 58);
	cout << endl;
	Utils::PreencheTexto("=", 58);
	cout << "\n" << endl;

	Utils::Titulo("Jogadores", "=", 58);
	cout <<  "\n" << endl;	

	for (Jogador jogador : this->jogadores) {		
		cout << endl;
		cout << "Matrícula: " << jogador.GetMatricula() << endl;
		cout << "Nome: "<< jogador.GetNome() << endl;
		cout << "Nacionalidade: " << jogador.GetNacionalidade() << endl;
		cout << "Nasceu em : " << jogador.GetNascimento().GetDataString() << ", " << jogador.GetIdade() << endl;
		cout << jogador.GetTempoParaAposentadoria() << endl;
		Utils::PreencheTexto("-", 58);
		cout << "\n" << endl;
	}
}

void Time::RelatorioFinanceiro() {

	float total_salarios_brutos = 0.f;
	float total_salarios_liquidos = 0.f;

	Utils::PreencheTexto("=", 58);
	cout << endl;
	Utils::Titulo("Relatório financeiro do time " + this->nome, "=", 58);
	cout << endl;
	Utils::PreencheTexto("=", 58);
	cout << "\n" << endl;	

	cout << "+";
	Utils::PreencheTexto("-", 32);
	cout << "+";
	Utils::PreencheTexto("-", 11);
	cout << "+";
	Utils::PreencheTexto("-", 11);
	cout << "+" << endl;

	cout << "|";
	Utils::LimitadorTexto(" Nome jogador", 32);	
	cout << "|";
	Utils::LimitadorTexto(" Bruto", 11);
	cout << "|";
	Utils::LimitadorTexto(" Líquido", 11);
	cout << "|" << endl;

	cout << "+";
	Utils::PreencheTexto("-", 32);
	cout << "+";
	Utils::PreencheTexto("-", 11);
	cout << "+";
	Utils::PreencheTexto("-", 11);
	cout << "+" << endl;

	for (Jogador jogador : this->jogadores) {
		cout << "|";
		Utils::LimitadorTexto(" "+ jogador.GetNome()+" ", 32);
		cout << "|";
		Utils::LimitadorTexto(" " + Utils::FloatToString(jogador.GetSalarioBruto()), 11);
		cout << "|";
		Utils::LimitadorTexto(" " + Utils::FloatToString(jogador.GetSalarioLiquido()), 11);
		cout << "|" << endl;

		cout << "+";
		Utils::PreencheTexto("-", 32);
		cout << "+";
		Utils::PreencheTexto("-", 11);
		cout << "+";
		Utils::PreencheTexto("-", 11);
		cout << "+" << endl;

		total_salarios_brutos += jogador.GetSalarioBruto();
		total_salarios_liquidos += jogador.GetSalarioLiquido();
	}

	cout << "+";
	Utils::PreencheTexto("-", 32);
	cout << "+";
	Utils::PreencheTexto("-", 11);
	cout << "+";
	Utils::PreencheTexto("-", 11);
	cout << "+" << endl;


	cout << "|";
	Utils::LimitadorTexto(" Total ", 32);
	cout << "|";
	Utils::LimitadorTexto(" " + Utils::FloatToString(total_salarios_brutos), 11);
	cout << "|";
	Utils::LimitadorTexto(" " + Utils::FloatToString(total_salarios_liquidos), 11);
	cout << "|" << endl;

	cout << "+";
	Utils::PreencheTexto("-", 32);
	cout << "+";
	Utils::PreencheTexto("-", 11);
	cout << "+";
	Utils::PreencheTexto("-", 11);
	cout << "+" << endl;
}

int Time::GetMatrigula() {
	return this->matricula;
}

string Time::GetNome() {
	return this->nome;
}

vector<Jogador> Time::GetJogadores() {
	return this->jogadores;
}

int Time::GeraNumeromatricula()
{
	ultimo_numero_matricula++;
	return ultimo_numero_matricula;
}