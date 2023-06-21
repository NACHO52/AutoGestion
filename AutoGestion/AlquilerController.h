#pragma once
#include "Alquiler.h"

class AlquilerController
{
public:
	void mostrarMenu();
	void dibujarMenu();
	void crear();
	void listar(int x, int y);
	void listaHeader(int x, int y);
	void imprimirNoHayRegistros(int x, int y);
	void DibujarFila(int x, int y, int registrosImpresos, Alquiler& obj);
	void listarVigentes(int x, int y);
	void listarTerminados(int x, int y);
	void buscarPorId();
	void mostrarRegistro(Alquiler obj, bool mostrarAuto, bool mostrarCliente, bool mostrarEmpleado);
	void editar();
	bool reservado(int autoId);
	int listarPorCliente(int x, int y, int clienteId);
	int listarPorAuto(int x, int y, int autoId);
};