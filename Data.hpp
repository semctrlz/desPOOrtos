#ifndef Data_hpp
#define Data_hpp

#include <iostream>
#include <string>
#include <time.h>
using namespace std;

class Data {
public:
	Data() {
		time_t t = time(NULL);
		struct tm buf;
		localtime_s(&buf, &t);
		this->ano = buf.tm_year + 1900;
		this->mes = buf.tm_mon + 1;
		this->dia = buf.tm_mday;
	
	}; // Construtor padrão
	Data(int d, int m, int a);
	string GetDataString();
	int GetDia();
	int GetMes();
	int GetAno();
	
	static int DiasDiferencaEntreDatas(Data antiga, Data nova);
	static int GetIdade(Data nascimento);

private:
	int dia, mes, ano;

	static int GetDiasCorridos(Data data);
};

#endif // !Data_hpp
