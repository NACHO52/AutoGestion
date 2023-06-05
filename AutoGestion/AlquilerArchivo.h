#pragma once
#include <string>
#include "Alquiler.h"

class AlquilerArchivo
{
public:
	int getCantidadRegistros();
	bool guardar(Alquiler reg);
	Alquiler buscar(int ID);
	void leer(Alquiler* vec, int cantidadRegistrosALeer);
	void vaciar();
	bool guardar(Alquiler* vec, int cantidadRegistrosAEscribir);
	bool HacerCopiaDeSeguridad();
	bool RestaurarCopiaDeSeguridad();
	void ExportarDatos();
	AlquilerArchivo();
	AlquilerArchivo(std::string ruta);

private:
	std::string _ruta;
};

