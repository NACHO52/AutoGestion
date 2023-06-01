#pragma once
#include <string>
#include "Empleado.h"

class EmpleadoArchivo
{
public:
	int getCantidadRegistros();
	bool guardar(Empleado reg);
	Empleado buscar(int ID);

	EmpleadoArchivo();
	EmpleadoArchivo(std::string ruta);

private:
	std::string _ruta;
};

