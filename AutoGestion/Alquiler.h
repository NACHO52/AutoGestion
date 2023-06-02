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
	Cliente _cliente;
	Auto _auto;
	Fecha _fechaDesde;
	Fecha _fechaHasta;
	float _precio;
	Empleado _empleado;
	AlquilerEstado _estado;

public:
	int getId();
	Cliente getCliente();
	Auto getAuto();
	Fecha getFechaDesde();
	Fecha getFechaHasta();
	float getPrecio();
	Empleado getEmpleado();
	AlquilerEstado getEstado();
	std::string getEstadoStr();

	void setId(int id);
	void setCliente(Cliente cliente);
	void setAuto(Auto a);
	void setFechaDesde(Fecha fechaDesde);
	void setFechaHasta(Fecha fechaHasta);
	void setPrecio(float precio);
	void setEmpleado(Empleado empleado);
	void setEstado();
};

