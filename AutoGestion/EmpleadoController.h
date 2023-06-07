#pragma once
#include "Empleado.h"

class EmpleadoController
{
public:
	void buscarPorId();
	int getEmpleadosDisponibles();
	int ventanaEmpleadosDisponibles(int x, int y);
	void limpiarVentanaEmpleaadosDisponibles(int x, int y, int registros);
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

