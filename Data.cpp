#include "Data.hpp"

Data::Data(int d, int m, int a) {
	this->dia = d;
	this->mes = m;
	this->ano = a;
}

string Data::GetDataString() {
	return to_string(this->dia) + "/" + to_string(this->mes) + "/" + to_string(this->ano);
}

int Data::GetDia() {
	return this->dia;
}

int Data::GetMes() {
	return this->mes;
}

int Data::GetAno() {
	return this->ano;
}

int Data::DiasDiferencaEntreDatas(Data dataI, Data dataF) {
	int diasI = GetDiasCorridos(dataI);
	int diasF = GetDiasCorridos(dataF);
	return diasF - diasI;
}

int Data::GetIdade(Data nascimento) {
	Data hoje = Data();

	int anos = 0;

	if (nascimento.GetMes() > hoje.GetMes() || (nascimento.GetMes() == hoje.GetMes() && nascimento.GetDia() > hoje.GetDia())) {		
		anos = hoje.GetAno() - nascimento.GetAno() - 1;
	}
	else {
		anos = hoje.GetAno() - nascimento.GetAno();
	}

	return anos;
}

int Data::GetDiasCorridos(Data data) 
{
	int ano = data.GetAno();
	int mes = data.GetMes();
	int dia = data.GetDia();

	int dias_bissextos = ano / 4;

	int dias_totais = dias_bissextos + (ano - 1) * 365; // Calculo o AnoI - 1 pois o restanto do ano será calculado com os meses
	
	// Cálculo dos dias do início do ano até o final do mês anterior ao informado
	for (int i = 1; i <= (mes - 1); i++) {
		if (i == 1 || i == 3 || i == 5 || i == 7 || i == 8 || i == 10 || i == 12) {
			dias_totais += 31;
		}
		else if (i == 2) {
			if (ano % 4 == 0) {
				dias_totais += 29;
			}
			else {
				dias_totais += 28;
			}
		}
		else {
			dias_totais += 30;
		}
	}

	dias_totais += dia;

	return dias_totais;
}
