#pragma once
#include <string>
#include "Fecha.h"

class Cliente
{
private:
	int _id;
	char _nombre[50];
	char _apellido[50];
	Fecha _fechaDeNacimiento;
	char _dni[30];
	char _mail[40];
	char _telefono[50];

public:
	int getId();
	std::string getNombre();
	std::string getApellido();
	Fecha getFechaDeNacimiento();
	std::string getDni();
	std::string getMail();
	std::string getTelefono();
	void setId(int id);
	void setNombre(std::string nombre);
	void setApellido(std::string apellido);
	void setFechaDeNacimiento(Fecha fecha);
	void setDni(std::string dni);
	void setMail(std::string mail);
	void setTelefono(std::string telefono);
};

