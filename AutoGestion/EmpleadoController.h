#pragma once
#include "Empleado.h"

class EmpleadoController
{
public:
	void buscarPorId();
	void crear();
	void dibujarFila(int registrosImpresos, Empleado& obj);
	void dibujarMenu();
	void editar();
	void eliminar();
	void imprimirNoHayRegistros();
	void listaHeader();
	void listar();
	void listarPorEstado();
	void mostrarMenu();
	void mostrarRegistro(Empleado obj);
};

