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

	void leer(Cliente* vec, int cantidadRegistrosALeer);

	void vaciar();

	bool guardar(Cliente* vec, int cantidadRegistrosAEscribir);

	bool HacerCopiaDeSeguridad();

	bool RestaurarCopiaDeSeguridad();

	void ExportarDatos();

	ClienteArchivo();
	ClienteArchivo(std::string ruta);

private:
	std::string _ruta;
};
