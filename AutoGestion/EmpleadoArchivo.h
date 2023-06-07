#pragma once
#include <string>
#include "Empleado.h"

class EmpleadoArchivo
{
public:
	EmpleadoArchivo();
	EmpleadoArchivo(std::string ruta);
	Empleado buscar(int id);
	void ExportarDatos();
	int getCantidadRegistros();
	bool guardar(Empleado reg);
	bool guardar(Empleado* vec, int cantidadRegistrosAEscribir);
	bool HacerCopiaDeSeguridad();
	void leer(Empleado* vec, int cantidadRegistrosALeer);
	bool RestaurarCopiaDeSeguridad();
	void vaciar();

private:
	std::string _ruta;
};

