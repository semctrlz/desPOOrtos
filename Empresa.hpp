#pragma once

#ifndef Empresa_hpp
#define Empresa_hpp

#include <iostream>
#include "Time.hpp"
#include "Utils.hpp"
#include <vector>

using namespace std;

class Empresa {
public:
	Empresa(string nome);
	void ConsultaJogador(string nome);
	void ConsultaJogador(int matricula);
	void ListaJogadores();
	void RelatorioFinanceiro();
	string GetNome();
	void AdicionaTime(Time time);
	vector<Time> GetTimes();

private:
	void ImprimeInfoJogador(Time time, Jogador jogador);
	string nome_empresa;
	vector<Time> times;
};


#endif // !Empresa_hpp



