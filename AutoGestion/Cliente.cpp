#include <string.h>
#include <iostream>
#include "Cliente.h"

Cliente::Cliente()
{
    _id = 0;
    strcpy(_nombre, "");
    strcpy(_apellido, "");
    _fechaDeNacimiento = Fecha();
    strcpy(_dni, "");
    strcpy(_mail, "");
    strcpy(_telefono, "");
}

int Cliente::getId()
{
    return _id;
}

std::string Cliente::getNombre()
{
    return _nombre;
}

std::string Cliente::getApellido()
{
    return _apellido;
}

Fecha Cliente::getFechaDeNacimiento()
{
    return _fechaDeNacimiento;
}

std::string Cliente::getDni()
{
    return _dni;
}

std::string Cliente::getMail()
{
    return _mail;
}

std::string Cliente::getTelefono()
{
    return _telefono;
}

void Cliente::setId(int id)
{
    _id = id;
}

void Cliente::setNombre(std::string nombre)
{
    strcpy(_nombre, nombre.c_str());
}

void Cliente::setApellido(std::string apellido)
{
    strcpy(_apellido, apellido.c_str());
}

void Cliente::setFechaDeNacimiento(Fecha fecha)
{
    _fechaDeNacimiento = fecha;
}

void Cliente::setDni(std::string dni)
{
    strcpy(_dni, dni.c_str());
}

void Cliente::setMail(std::string mail)
{
    strcpy(_mail, mail.c_str());
}

void Cliente::setTelefono(std::string telefono)
{
    strcpy(_telefono , telefono.c_str());
}
