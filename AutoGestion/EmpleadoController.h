#pragma once
#include "Empleado.h"

class EmpleadoController
{
public:
	void mostrarMenu();
	void dibujarMenu();
	void listaHeader();
	void crear();
	void editar();
	void listar();
	void eliminar();
	void mostrarRegistro(Empleado obj);
	void imprimirNoHayRegistros();
	void listarPorEstado();
	void buscarPorId();
};

