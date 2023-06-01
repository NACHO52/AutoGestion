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
	void eliminar();
	void mostrarRegistro(Auto obj);
	void imprimirNoHayRegistros();
	void listarPorEstado();
	void buscarPorId();
};

