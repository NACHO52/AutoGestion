#pragma once
#include <string>
#include <iostream>

enum AutoEstado {
	Disponible = 1,
	FueraDeServicio = 2,
	Reservado = 3
};

class Auto
{
private:
	int _id;
	char _patente[50];
	char _marca[50];
	char _modelo[50];
	int _anio;
	AutoEstado _estado;
	bool _eliminado;
	float _precioDia;

public:
	Auto();
	int getId();
	std::string getPatente();
	std::string getMarca();
	std::string getModelo();
	int getAnio();
	AutoEstado getEstado();
	bool getEliminado();
	std::string getEliminadoStr();
	std::string getEstadoStr();
	float getPrecioDia();

	void setId(int id);
	void setPatente(std::string patente);
	void setMarca(std::string marca);
	void setModelo(std::string modelo);
	void setAnio(int anio);
	void setEstado(AutoEstado estado);
	void setEliminado(bool eliminado);
	void setPrecioDia(float precio);
};

