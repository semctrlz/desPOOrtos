#include "Jogador.hpp"

int Jogador::ultimo_numero_matricula = 0;

Jogador::Jogador(string nome, Esportes esporte, Data nascimento, string nacionalidade, bool profissional, float salario_bruto) {
	this->nome = nome;
	this->esporte = esporte;
	this->nascimento = nascimento;
	this->nacionalidade = nacionalidade;
	this->categoria_profissional = profissional;
	this->salario_bruto = salario_bruto;
	this->matricula = GeraNumeromatricula();
}

string Jogador::GetNome() {
	return this->nome;
}

Esportes Jogador::GetEsporte() {
	return this->esporte;
}

Data Jogador::GetNascimento() {
	return this->nascimento;
}

string Jogador::GetNascimentoString() {
	return this->nascimento.GetDataString();
}

int Jogador::GetMatricula() {
	return this->matricula;
}

string Jogador::GetNacionalidade() {
	return this->nacionalidade;
}
bool Jogador::GetCategoriaProfissional() {
	return this->categoria_profissional;
}

float Jogador::GetSalarioBruto() {
	return this->salario_bruto;
}

float Jogador::GetSalarioLiquido() {
	float salario = this->salario_bruto;
	float inss = GetInss();
	float ir = GetIrff();	

	return salario - inss - ir;
}

float Jogador::GetInss() {
	float salario = this->salario_bruto;
	float inss = 0.f;	

	if (salario <= 1100.f) {
		inss = salario * 0.075;
	}
	else if (salario <= 2000.f) {
		inss = salario * 0.09f;		
	}
	else if (salario <= 3100.f) {
		inss = salario * 0.12f;		
	}
	else if (salario <= 4100.f) {
		inss = salario * 0.14f;		
	}
	else if (salario > 4100.f) {
		inss = salario * 0.14f;		
	}

	return inss;
}

float Jogador::GetIrff() {
	float salario = this->salario_bruto;
	float irff;

	if (salario <= 1100.f) {
		irff = 0;
	}
	else if (salario <= 2000.f) {
		irff = salario * 0.075f;
	}
	else if (salario <= 3100.f) {
		irff = salario * 0.15f;
	}
	else if (salario <= 4100.f) {
		irff = salario * 0.22f;
	}
	else if (salario > 4100.f) {
		irff = salario * 0.27f;
	}

	return irff;	
}

string Jogador::GetTempoParaAposentadoria() {
	// Pegar o nascimento da criatura e aumentar os anos do esporte
	int anos_para_aposentar = this->esporte.idadeAposentadoria;
	Data nascimento = this->nascimento;

	Data aposentadoria = Data();

	if (nascimento.GetMes() == 2 && nascimento.GetDia() == 29) {
		
		aposentadoria = Data(1, 3, nascimento.GetAno() + anos_para_aposentar);
	}
	else {
		aposentadoria = Data(nascimento.GetDia(), nascimento.GetMes(), nascimento.GetAno() + anos_para_aposentar);
	}	

	int s_ano = 0;
	int s_mes = 0;
	int s_dia = 0;

	Data hoje = Data();

	int dias = Data::DiasDiferencaEntreDatas(hoje, aposentadoria);

	if (dias > 0) {

		string apos = "Pode se aposentar em aproximadamente ";

		if (dias > 365) {
			s_ano = dias / 365;
			apos += to_string(s_ano);
			if (s_ano == 1) {
				apos += " ano";
			}
			else {
				apos += " anos";
			}
		}

		if ((dias - (s_ano * 365)) > 30) {
			s_mes = (dias - (s_ano * 365)) / 30;
			if (s_ano > 0) {
				apos += ", ";
			}
			apos += to_string(s_mes);
			if (s_mes == 1) {
				apos += "mês";
			}
			else {
				apos += " meses";
			}
		}

		if (dias - ((s_ano * 365) + s_mes * 30) > 0) {
			s_dia = dias - ((s_ano * 365) + s_mes * 30);
			if (s_mes > 0) {
				apos += " e ";
			}
			apos += to_string(s_dia);
			if (s_dia == 1) {
				apos += " dia.";
			}
			else {
				apos += " dias.";
			}
		}

		return apos;
	}
	else {
		return "Já poderia ter se aposentado.";
	}
}

string Jogador::GetIdade() {
	int idade = Data::GetIdade(this->nascimento);

	string idade_string = to_string(idade) + " anos";

	return idade_string;
}

int Jogador::GeraNumeromatricula()
{
	ultimo_numero_matricula++;
	return ultimo_numero_matricula;
}
