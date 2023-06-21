#pragma once
#include <string>

class Funciones
{
public:
	void MenuPrincipal();
	void DibujarMenu();
	bool esDecimal(std::string s);
	bool esNumero(std::string s);
    int inputNumero(int x, int y);
    int inputDecimal(int x, int y);
};
