#include <iostream>
#include <string.h>
#include "Auto.h"


Auto::Auto()
{
	_id = 0;
	strcpy(_patente, "");
	strcpy(_marca, "");
	strcpy(_modelo, "");
	_anio = 0;
	_estado = AutoEstado::Disponible;
	_eliminado = false;
	_precioDia = 0;
}

int Auto::getId()
{
	return _id;
}

std::string Auto::getPatente()
{
	return _patente;
}

std::string Auto::getMarca()
{
	return _marca;
}

std::string Auto::getModelo()
{
	return _modelo;
}

int Auto::getAnio()
{
	return _anio;
}

AutoEstado Auto::getEstado()
{
	return _estado;
}

bool Auto::getEliminado()
{
	return _eliminado;
}

std::string Auto::getEliminadoStr()
{
    return _eliminado ? "Si" : "No";
}

void Auto::setId(int id)
{
	_id = id;
}

void Auto::setPatente(std::string patente)
{
	strcpy(_patente, patente.c_str());
}

void Auto::setMarca(std::string marca)
{
	strcpy(_marca, marca.c_str());
}

void Auto::setModelo(std::string modelo)
{
	strcpy(_modelo, modelo.c_str());
}

void Auto::setAnio(int anio)
{
	_anio = anio;
}

void Auto::setEstado(AutoEstado estado)
{
	_estado = estado;
}

void Auto::setEliminado(bool eliminado)
{
	_eliminado = eliminado;
}

void Auto::setPrecioDia(float precio)
{
	_precioDia = precio;
}

std::string Auto::getEstadoStr()
{
	std::string cadena;

	switch (_estado)
	{
	case Disponible:
		cadena = "Disponible";
		break;
	case FueraDeServicio:
		cadena = "Fuera de servicio";
		break;
	case Reservado:
		cadena = "Reservado";
		break;
	default:
		cadena = "";
		break;
	}

	return cadena;
}

float Auto::getPrecioDia()
{
    return _precioDia;
}
