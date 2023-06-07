#pragma once
#include <string>
#include "Auto.h"

class AutoArchivo
{
public:
	AutoArchivo();
	AutoArchivo(std::string ruta);
	Auto buscar(int id);
	void ExportarDatos();
	int getCantidadRegistros();
	bool guardar(Auto reg);
	bool guardar(Auto* vec, int cantidadRegistrosAEscribir);
	bool HacerCopiaDeSeguridad();
	void leer(Auto* vec, int cantidadRegistrosALeer);
	bool RestaurarCopiaDeSeguridad();
	void vaciar();

private:
	std::string _ruta;
};

