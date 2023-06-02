#pragma once
#include <string>
#include "Cliente.h"

class ClienteArchivo
{
public:
	int getCantidadRegistros();
	bool guardar(Cliente reg);
	Cliente buscar(int ID);

	ClienteArchivo();
	ClienteArchivo(std::string ruta);

private:
	std::string _ruta;
};
