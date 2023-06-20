#pragma once
#include "Cliente.h"
#include "Auto.h"
#include "Fecha.h"
#include "Empleado.h"

enum AlquilerEstado {
	Vigente = 1,
	TerminadoCorrecto = 2,
	TerminadoConVencimiento = 3
};

class Alquiler
{
private:
	int _id;
	int _clienteId;
	int _autoId;
	Fecha _fechaDesde;
	Fecha _fechaHasta;
	Fecha _fechaDevolucion;
	float _precio;
	float _multa;
	int _empleadoId;
	AlquilerEstado _estado;

public:
	Alquiler();
	int getId();
	int getClienteId();
	int getAutoId();
	Fecha getFechaDesde();
	Fecha getFechaHasta();
	Fecha getFechaDevolucion();
	float getPrecio();
	float getMulta();
	int getEmpleadoId();
	AlquilerEstado getEstado();
	std::string getEstadoStr();

	void setId(int id);
	void setClienteId(int clienteId);
	void setAutoId(int aId);
	void setFechaDesde(Fecha fechaDesde);
	void setFechaHasta(Fecha fechaHasta);
	void setFechaDevolucion(Fecha fechaDevolucion);
	void setPrecio(float precio);
	void setMulta(float multa);
	void setEmpleadoId(int empleadoId);
	void setEstado(AlquilerEstado estado);
};

