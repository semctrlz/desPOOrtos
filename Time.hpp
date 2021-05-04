#pragma once

#ifndef Time_hpp
#define Time_hpp

#include <iostream>
#include "Jogador.hpp"
#include "Esportes.hpp"
#include "Utils.hpp"
#include <vector>

using namespace std;

class Time {
public:	
	Time(string nome, Esportes esporte);
	void AdicionaJogador(Jogador jogador);
	void RelatorioGeral();
	void RelatorioFinanceiro();
	int GetMatrigula();
	string GetNome();
	vector<Jogador> GetJogadores();

private:
	Esportes esporte;
	string nome;
	int matricula;
	bool categoria_profissional;

	int static ultimo_numero_matricula;
	int GeraNumeromatricula();
	vector<Jogador> jogadores;
};


#endif // !Time_hpp



