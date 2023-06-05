#pragma once
#include <string>
#include "Empleado.h"

class EmpleadoArchivo
{
public:
	int getCantidadRegistros();
	bool guardar(Empleado reg);
	Empleado buscar(int ID);
	void leer(Empleado* vec, int cantidadRegistrosALeer);
	void vaciar();
	bool guardar(Empleado* vec, int cantidadRegistrosAEscribir);
	bool HacerCopiaDeSeguridad();
	bool RestaurarCopiaDeSeguridad();
	void ExportarDatos();
	EmpleadoArchivo();
	EmpleadoArchivo(std::string ruta);

private:
	std::string _ruta;
};

