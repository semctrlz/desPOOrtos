#include "Utils.hpp"

void Utils::LimitadorTexto(string texto, int quant) {
	
	string texto_formatado = texto;
	string retorno = "";

	if (texto.length() == quant) {
		texto_formatado = texto;
	}
	else if (texto.length() > quant) {
		texto_formatado = texto.substr(0, quant);
	}else{

		for (int i = 0; i < quant - texto.length(); i++) {
			retorno += " ";
		}
	}

	cout << texto_formatado << retorno;
}

void Utils::PreencheTexto(string texto, int quant) {

	string retorno = "";

	for (int i = 0; i < quant; i++) {
		retorno += texto;
	}

	cout <<  retorno;
}

void Utils::Titulo(string titulo, string decorador, int quant) {

	int tamanhoTitulo = titulo.length();

	if ((tamanhoTitulo+2) >= quant) {
		cout << titulo;
	}

	int tamanho_direita = (quant - (tamanhoTitulo + 2)) / 2;
	int tamanho_esquerda = quant - tamanho_direita - (tamanhoTitulo + 2);

	PreencheTexto(decorador, tamanho_esquerda);
	cout << " " << titulo << " ";	
	PreencheTexto(decorador, tamanho_direita);

}
 
string Utils::FloatToString(float v) {
	string valor = to_string(v);
	size_t size = valor.find(",");
	return valor.substr(0, size + 3);
}