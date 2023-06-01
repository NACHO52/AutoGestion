#pragma once
#include <string>

enum EmpleadoEstado {
	Activo = 1,
	Baja = 2
};

class Empleado
{
private:
	int _id;
	char _nombre[50];
	char _apellido[50];
	char _mail[30];
	float _sueldo;
	EmpleadoEstado _estado;
	bool _eliminado;

public:
	Empleado();
	int getId();
	std::string getNombre();
	std::string getApellido();
	std::string getMail();
	float getSueldo();
	EmpleadoEstado getEstado();
	bool getEliminado();
	std::string getEstadoStr();

	void setId(int id);
	void setNombre(std::string nombre);
	void setApellido(std::string apellido);
	void setMail(std::string mail);
	void setSueldo(float sueldo);
	void setEstado(EmpleadoEstado estado);
	void setEliminado(bool eliminado);
};