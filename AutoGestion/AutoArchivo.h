#pragma once
#include <string>
#include "Auto.h"

class AutoArchivo
{
public:
	AutoArchivo();
	AutoArchivo(std::string ruta);

	int getCantidadRegistros();
	bool guardar(Auto reg);
	Auto buscar(int ID);
	void leer(Auto* vec, int cantidadRegistrosALeer);
	void vaciar();
	bool guardar(Auto* vec, int cantidadRegistrosAEscribir);
	bool HacerCopiaDeSeguridad();
	bool RestaurarCopiaDeSeguridad();

	void ExportarDatos();

private:
	std::string _ruta;
};

