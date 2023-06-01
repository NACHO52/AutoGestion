#include "Empleado.h"


Empleado::Empleado()
{
    _id = 0;
    strcpy(_nombre, "");
    strcpy(_apellido, "");
    strcpy(_mail, "");
    _sueldo = 0;
    _estado = EmpleadoEstado::Activo;
    _eliminado = false;
}

int Empleado::getId()
{
    return _id;
}

std::string Empleado::getNombre()
{
    return _nombre;
}

std::string Empleado::getApellido()
{
    return _apellido;
}

std::string Empleado::getMail()
{
    return _mail;
}

float Empleado::getSueldo()
{
    return _sueldo;
}

EmpleadoEstado Empleado::getEstado()
{
    return _estado;
}

bool Empleado::getEliminado()
{
    return _eliminado;
}

std::string Empleado::getEstadoStr()
{
    std::string estado = "";

    switch (_estado)
    {
    case Activo:
        estado = "Activo";
        break;
    case Baja:
        estado = "Baja";
        break;
    default:
        break;
    }

    return estado;
}

void Empleado::setId(int id)
{
    _id = id;
}

void Empleado::setNombre(std::string nombre)
{
    strcpy(_nombre, nombre.c_str());
}

void Empleado::setApellido(std::string apellido)
{
    strcpy(_apellido, apellido.c_str());
}

void Empleado::setMail(std::string mail)
{
    strcpy(_mail, mail.c_str());
}

void Empleado::setSueldo(float sueldo)
{
    _sueldo = sueldo;
}

void Empleado::setEstado(EmpleadoEstado estado)
{
    _estado = estado;
}

void Empleado::setEliminado(bool eliminado)
{
    _eliminado = eliminado;
}
