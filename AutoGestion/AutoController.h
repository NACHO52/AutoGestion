#pragma once
#include "Auto.h"
#include "Fecha.h"

class AutoController
{
public:
	void buscarPorId();
	void crear();
	void DibujarFila(int registrosImpresos, Auto& obj);
	void dibujarMenu();
	void editar();
	void eliminar();
	int historialAlquiler(int x, int y, Auto obj);
	void imprimirNoHayRegistros();
	void limpiarVentanaAutosDisponibles(int x, int y, int registros);
	void listaHeader();
	void listar();
	void listarPorEstado();
	void mostrarMenu();
	void mostrarRegistro(Auto obj);
	int ventanaAutosDisponibles(int x, int y, int dias, Fecha desde, Fecha hasta);
    bool autoPeriodoReservado(Fecha fechaDesde, Fecha fechaHasta, int autoId);
    int getAutosDisponibles();
    int getAutosDisponibles(Fecha desde, Fecha hasta);
};