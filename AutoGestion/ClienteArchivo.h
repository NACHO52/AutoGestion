#pragma once
#include <string>
#include "Cliente.h"

class ClienteArchivo
{
public:
	int getCantidadRegistros();
	bool guardar(Cliente reg);
	Cliente buscar(int id);
	Cliente buscarPorDNI(std::string dni);

	ClienteArchivo();
	ClienteArchivo(std::string ruta);

private:
	std::string _ruta;
};
