#include "Empresa.hpp"

Empresa::Empresa(string nome) {
	this->nome_empresa = nome;
}

void Empresa::ConsultaJogador(string nome) {
	for (Time time : this->times) {
		for (Jogador jogador : time.GetJogadores()) {
			if (jogador.GetNome() == nome) {
				ImprimeInfoJogador(time, jogador);
				return;
			}
		}
	}	
	cout << "Jogador não encontrado" << endl;
}

void Empresa::ConsultaJogador(int matricula) {
	for (Time time : this->times) {
		for (Jogador jogador : time.GetJogadores()) {
			if (jogador.GetMatricula() == matricula) {
				ImprimeInfoJogador(time, jogador);
				return;
			}
		}
	}

	cout << "Jogador não encontrado" << endl;
}

void Empresa::ListaJogadores() {

	Utils::PreencheTexto("=", 58);
	cout << endl;
	Utils::Titulo("Relatório geral da empresa " + this->nome_empresa, "=", 58);
	cout << endl;
	Utils::PreencheTexto("=", 58);
	cout << "\n" << endl;

	for (Time time : this->times) {
		
		Utils::PreencheTexto("=", 58);
		cout << endl;
		Utils::Titulo("Time " + time.GetNome(), "=", 58);
		cout << endl;
		Utils::PreencheTexto("=", 58);
		cout << endl;

		for (Jogador jogador : time.GetJogadores()) {
			cout << "Matrícula: " << jogador.GetMatricula() << endl;
			cout << "Nome: " << jogador.GetNome() << endl;
			cout << "Nacionalidade: " << jogador.GetNacionalidade() << endl;
			cout << "Nasceu em : " << jogador.GetNascimento().GetDataString() << ", " << jogador.GetIdade() << endl;
			cout << jogador.GetTempoParaAposentadoria() << endl;
			Utils::PreencheTexto("-", 58);
			cout << endl;
		}
		cout << endl;
	}
}

void Empresa::RelatorioFinanceiro() {

	float total_salarios_brutos = 0.f;
	float total_salarios_liquidos = 0.f;
	float subtotal_salarios_brutos = 0.f;
	float subtotal_salarios_liquidos = 0.f;

	float total_inss = 0.f;
	float total_irff = 0.f;
	float subtotal_inss = 0.f;
	float subtotal_irff = 0.f;

	Utils::PreencheTexto("=", 80);
	cout << endl;
	Utils::Titulo("Relatório financeiro da empresa " + this->nome_empresa, "=", 80);
	cout << endl;
	Utils::PreencheTexto("=", 80);
	cout << "\n" << endl;

	for (Time time : this->times) {

		Utils::PreencheTexto("=", 80);
		cout << endl;
		cout << "|";
		Utils::Titulo("Time " + time.GetNome(), " ", 78);
		cout << "|" << endl;		

		cout << "+";
		Utils::PreencheTexto("-", 32);
		cout << "+";
		Utils::PreencheTexto("-", 11);
		cout << "+";
		Utils::PreencheTexto("-", 10);
		cout << "+";
		Utils::PreencheTexto("-", 10);
		cout << "+";
		Utils::PreencheTexto("-", 11);
		cout << "+" << endl;

		cout << "|";
		Utils::LimitadorTexto(" Nome jogador", 32);
		cout << "|";
		Utils::LimitadorTexto(" Bruto", 11);
		cout << "|";
		Utils::LimitadorTexto(" INSS", 10);
		cout << "|";
		Utils::LimitadorTexto(" IRFF", 10);
		cout << "|";
		Utils::LimitadorTexto(" Líquido", 11);
		cout << "|" << endl;

		cout << "+";
		Utils::PreencheTexto("-", 32);
		cout << "+";
		Utils::PreencheTexto("-", 11);
		cout << "+";
		Utils::PreencheTexto("-", 10);
		cout << "+";
		Utils::PreencheTexto("-", 10);
		cout << "+";
		Utils::PreencheTexto("-", 11);
		cout << "+" << endl;

		subtotal_salarios_brutos = 0;
		subtotal_salarios_liquidos  = 0;
		subtotal_inss += 0;
		subtotal_irff += 0;

		for (Jogador jogador : time.GetJogadores()) {
			cout << "|";
			Utils::LimitadorTexto(" " + jogador.GetNome() + " ", 32);
			cout << "|";
			Utils::LimitadorTexto(" " + Utils::FloatToString(jogador.GetSalarioBruto()), 11);
			cout << "|";
			Utils::LimitadorTexto(" " + Utils::FloatToString(jogador.GetInss()), 10);
			cout << "|";
			Utils::LimitadorTexto(" " + Utils::FloatToString(jogador.GetIrff()), 10);
			cout << "|";
			Utils::LimitadorTexto(" " + Utils::FloatToString(jogador.GetSalarioLiquido()), 11);
			cout << "|" << endl;

			cout << "+";
			Utils::PreencheTexto("-", 32);
			cout << "+";
			Utils::PreencheTexto("-", 11);
			cout << "+";
			Utils::PreencheTexto("-", 10);
			cout << "+";
			Utils::PreencheTexto("-", 10);
			cout << "+";
			Utils::PreencheTexto("-", 11);
			cout << "+" << endl;

			subtotal_salarios_brutos += jogador.GetSalarioBruto();
			subtotal_salarios_liquidos += jogador.GetSalarioLiquido();

			total_salarios_brutos += subtotal_salarios_brutos;
			total_salarios_liquidos += subtotal_salarios_liquidos;

			subtotal_inss += jogador.GetInss();
			subtotal_irff += jogador.GetIrff();

			total_inss += subtotal_inss;
			total_irff += subtotal_irff;
		}

		cout << "|";
		Utils::LimitadorTexto(" Total "+time.GetNome(), 32);
		cout << "|";
		Utils::LimitadorTexto(" " + Utils::FloatToString(subtotal_salarios_brutos), 11);
		cout << "|";
		Utils::LimitadorTexto(" " + Utils::FloatToString(subtotal_inss), 10);
		cout << "|";
		Utils::LimitadorTexto(" " + Utils::FloatToString(subtotal_irff), 10);
		cout << "|";
		Utils::LimitadorTexto(" " + Utils::FloatToString(subtotal_salarios_liquidos), 11);
		cout << "|" << endl;

		cout << "+";
		Utils::PreencheTexto("-", 32);
		cout << "+";
		Utils::PreencheTexto("-", 11);
		cout << "+";
		Utils::PreencheTexto("-", 10);
		cout << "+";
		Utils::PreencheTexto("-", 10);
		cout << "+";
		Utils::PreencheTexto("-", 11);
		cout << "+" << "\n" << endl;
	}

	Utils::PreencheTexto("=", 80);	
	cout << endl;
	cout << "|";
	Utils::LimitadorTexto(" Total Geral empresa", 32);
	cout << "|";
	Utils::LimitadorTexto(" " + Utils::FloatToString(total_salarios_brutos), 11);
	cout << "|";
	Utils::LimitadorTexto(" " + Utils::FloatToString(total_inss), 10);
	cout << "|";
	Utils::LimitadorTexto(" " + Utils::FloatToString(total_irff), 10);
	cout << "|";
	Utils::LimitadorTexto(" " + Utils::FloatToString(total_salarios_liquidos), 11);
	cout << "|" << endl;

	Utils::PreencheTexto("=", 80);
	cout << endl;

}

string Empresa::GetNome() {
	return this->nome_empresa;
}

void Empresa::AdicionaTime(Time time) {
	this->times.push_back(time);
}

vector<Time> Empresa::GetTimes() {
	return this->times;
}

void Empresa::ImprimeInfoJogador(Time time, Jogador jogador) {

	Utils::PreencheTexto("=", 83);
	cout << endl;
	Utils::Titulo("Informações do Jogador " + jogador.GetNome(), "=", 83);
	cout << endl;
	Utils::PreencheTexto("=", 83);
	cout << "\n" << endl;

	cout << "+";
	Utils::PreencheTexto("-", 32);
	cout << "+";
	Utils::PreencheTexto("-", 8);
	cout << "+";
	Utils::PreencheTexto("-", 15);
	cout << "+";
	Utils::PreencheTexto("-", 11);
	cout << "+";
	Utils::PreencheTexto("-", 11);
	cout << "+" << endl;

	cout << "|";
	Utils::LimitadorTexto(" Nome jogador", 32);
	cout << "|";
	Utils::LimitadorTexto(" Idade", 8);
	cout << "|";
	Utils::LimitadorTexto(" Time", 15);
	cout << "|";
	Utils::LimitadorTexto(" Bruto", 11);
	cout << "|";
	Utils::LimitadorTexto(" Líquido", 11);
	cout << "|" << endl;

	cout << "+";
	Utils::PreencheTexto("-", 32);
	cout << "+";
	Utils::PreencheTexto("-", 8);
	cout << "+";
	Utils::PreencheTexto("-", 15);
	cout << "+";
	Utils::PreencheTexto("-", 11);
	cout << "+";
	Utils::PreencheTexto("-", 11);
	cout << "+" << endl;

	cout << "|";
	Utils::LimitadorTexto(" "+ jogador.GetNome() , 32);
	cout << "|";
	Utils::LimitadorTexto(" "+jogador.GetIdade(), 8);
	cout << "|";
	Utils::LimitadorTexto(" "+time.GetNome(), 15);
	cout << "|";
	Utils::LimitadorTexto(" "+Utils::FloatToString(jogador.GetSalarioBruto()), 11);
	cout << "|";
	Utils::LimitadorTexto(" " + Utils::FloatToString(jogador.GetSalarioLiquido()), 11);
	cout << "|" << endl;

	cout << "+";
	Utils::PreencheTexto("-", 32);
	cout << "+";
	Utils::PreencheTexto("-", 8);
	cout << "+";
	Utils::PreencheTexto("-", 15);
	cout << "+";
	Utils::PreencheTexto("-", 11);
	cout << "+";
	Utils::PreencheTexto("-", 11);
	cout << "+" << endl;


}