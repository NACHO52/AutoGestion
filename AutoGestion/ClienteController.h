#pragma once
#include "Cliente.h"
#include <string>

class ClienteController
{
public:
	Cliente ventanaNuevoCliente(std::string dni);
	void mostrarMenu();
	void dibujarMenu();
	void listar();
	void listarHeader();
	void imprimirNoHayRegistros();
	void DibujarFila(int corrimiento, Cliente& obj);
	void buscarPorId();
	void mostrarRegistro(Cliente cliente);
};

