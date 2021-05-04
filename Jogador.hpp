#ifndef Jogador_hpp
#define Jogador_hpp

#include <iostream>
#include "Esportes.hpp"
#include "Data.hpp"

using namespace std;

class Jogador {
public:
	Jogador(string nome, Esportes esporte, Data nascimento, string nacionalidade, bool profissional, float salario_bruto);
	string GetNome();
	Esportes GetEsporte();
	Data GetNascimento();
	string GetNascimentoString();
	int GetMatricula();
	string GetNacionalidade();
	bool GetCategoriaProfissional();
	float GetSalarioBruto();
	float GetSalarioLiquido();
	float GetInss();
	float GetIrff();
	string GetTempoParaAposentadoria();
	string GetIdade();

private:
	string nome;
	Esportes esporte;
	Data nascimento;
	int matricula;
	string nacionalidade;
	bool categoria_profissional;
	float salario_bruto;	

	int static ultimo_numero_matricula;
	int GeraNumeromatricula();
};


#endif // !Jogador_hpp
