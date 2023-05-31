#pragma once
#include <string>
#include "Auto.h"

class AutoArchivo
{
public:
	int getCantidadRegistros();
	bool guardar(Auto reg);
	Auto buscar(int ID);

	AutoArchivo();
	AutoArchivo(std::string ruta);

private:
	std::string _ruta;
};

