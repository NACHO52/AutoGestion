#pragma once
#include "Auto.h"

class AutoController
{
public:
	void mostrarMenu();
	void dibujarMenu();
	void listaHeader();
	void crear();
	void editar();
	void listar();
	void DibujarFila(int registrosImpresos, Auto& obj);
	void eliminar();
	void mostrarRegistro(Auto obj);
	void imprimirNoHayRegistros();
	void listarPorEstado();
	void buscarPorId();
	int ventanaAutosDisponibles(int x, int y);
	void limpiarVentanaAutosDisponibles(int x, int y, int registros);
};

