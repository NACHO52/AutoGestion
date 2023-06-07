#pragma once
#include "Cliente.h"
#include <string>

class ClienteController
{
public:
	void buscarPorId();
	void DibujarFila(int corrimiento, Cliente& obj);
	void dibujarMenu();
	void imprimirNoHayRegistros();
	void listar();
	void listarHeader();
	void mostrarMenu();
	void mostrarRegistro(Cliente cliente);
	Cliente ventanaNuevoCliente(std::string dni);

};

