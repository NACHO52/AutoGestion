#pragma once
#include <string>

enum AutoEstado {
	Disponible = 1,
	FueraDeServicio = 2,
	EnUso = 3
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

public:
	Auto();
	int getId();
	std::string getPatente();
	std::string getMarca();
	std::string getModelo();
	int getAnio();
	AutoEstado getEstado();
	bool getEliminado();
	std::string getEstadoStr();

	void setId(int id);
	void setPatente(std::string patente);
	void setMarca(std::string marca);
	void setModelo(std::string modelo);
	void setAnio(int anio);
	void setEstado(AutoEstado estado);
	void setEliminado(bool eliminado);
};

