#pragma once
#include <string>
#include "Cliente.h"

class ClienteArchivo
{
public:
	ClienteArchivo();
	ClienteArchivo(std::string ruta);
	Cliente buscar(int id);
	Cliente buscarPorDNI(std::string dni);
	void ExportarDatos();
	int getCantidadRegistros();
	bool guardar(Cliente reg);
	bool guardar(Cliente* vec, int cantidadRegistrosAEscribir);
	void leer(Cliente* vec, int cantidadRegistrosALeer);
	bool RestaurarCopiaDeSeguridad();
	void vaciar();
	bool HacerCopiaDeSeguridad();

private:
	std::string _ruta;
};
