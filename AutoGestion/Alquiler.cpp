#include "Alquiler.h"

int Alquiler::getId()
{
    return _id;
}

Cliente Alquiler::getCliente()
{
    return _cliente;
}

Auto Alquiler::getAuto()
{
    return _auto;
}

Fecha Alquiler::getFechaDesde()
{
    return _fechaDesde;
}

Fecha Alquiler::getFechaHasta()
{
    return _fechaHasta;
}

float Alquiler::getPrecio()
{
    return _precio;
}

Empleado Alquiler::getEmpleado()
{
    return _empleado;
}

AlquilerEstado Alquiler::getEstado()
{
    return _estado;
}

std::string Alquiler::getEstadoStr()
{
    std::string estado = "";
    switch (_estado)
    {
    case Activo:
        estado = "Vigente";
        break;
    case TerminadoCorrecto:
        estado = "Terminado";
        break;
    case TerminadoConVencimiento:
        estado = "Terminado/Vencido";
        break;
    default:
        break;
    }
    return std::string();
}

void Alquiler::setId(int id)
{
    _id = id;
}

void Alquiler::setCliente(Cliente cliente)
{
    _cliente = cliente;
}

void Alquiler::setAuto(Auto a)
{
    _auto = a;
}

void Alquiler::setFechaDesde(Fecha fechaDesde)
{
    _fechaDesde = fechaDesde;
}

void Alquiler::setFechaHasta(Fecha fechaHasta)
{
    _fechaHasta = fechaHasta;
}

void Alquiler::setPrecio(float precio)
{
    _precio = precio;
}

void Alquiler::setEmpleado(Empleado empleado)
{
    empleado = _empleado;
}
