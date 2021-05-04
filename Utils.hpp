#ifndef Utils_hpp
#define Utils_hpp

#include <iostream>
#include <string>

using namespace std;

class Utils {
public:
	static void LimitadorTexto(string texto, int quantidade);
	static void PreencheTexto(string texto, int quantidade);
	static void Titulo(string titulo, string decorador, int quantidadeTotal);
	static string FloatToString(float valor);
};

#endif // !Utils_hpp
