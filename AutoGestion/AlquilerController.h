#pragma once
#include "Alquiler.h"

class AlquilerController
{
public:
	void mostrarMenu();
	void dibujarMenu();
	void crear();
	void listar();
	void listaHeader();
	void imprimirNoHayRegistros();
	void DibujarFila(int registrosImpresos, Alquiler& obj);
	void listarVigentes();
	void listarTerminados();
	void buscarPorId();
	void mostrarRegistro(Alquiler obj, bool mostrarAuto, bool mostrarCliente, bool mostrarEmpleado);
	void editar();
};