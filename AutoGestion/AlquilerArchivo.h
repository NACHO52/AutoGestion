#pragma once
#include <string>
#include "Alquiler.h"

class AlquilerArchivo
{
public:
	int getCantidadRegistros();
	bool guardar(Alquiler reg);
	Alquiler buscar(int ID);

	AlquilerArchivo();
	AlquilerArchivo(std::string ruta);

private:
	std::string _ruta;
};

