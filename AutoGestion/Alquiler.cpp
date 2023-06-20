#include "Alquiler.h"

Alquiler::Alquiler()
{
    _id = 0;
    _fechaDesde.hoy();
    _precio = 0;
    _estado = AlquilerEstado::Vigente;
}

int Alquiler::getId()
{
    return _id;
}

int Alquiler::getClienteId()
{
    return _clienteId;
}

int Alquiler::getAutoId()
{
    return _autoId;
}

Fecha Alquiler::getFechaDesde()
{
    return _fechaDesde;
}

Fecha Alquiler::getFechaHasta()
{
    return _fechaHasta;
}

Fecha Alquiler::getFechaDevolucion()
{
    return _fechaDevolucion;
}

float Alquiler::getPrecio()
{
    return _precio;
}

float Alquiler::getMulta()
{
    return _multa;
}

int Alquiler::getEmpleadoId()
{
    return _empleadoId;
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
    return estado;
}

void Alquiler::setId(int id)
{
    _id = id;
}

void Alquiler::setClienteId(int clienteId)
{
    _clienteId = clienteId;
}

void Alquiler::setAutoId(int a)
{
    _autoId = a;
}

void Alquiler::setFechaDesde(Fecha fechaDesde)
{
    _fechaDesde = fechaDesde;
}

void Alquiler::setFechaHasta(Fecha fechaHasta)
{
    _fechaHasta = fechaHasta;
}

void Alquiler::setFechaDevolucion(Fecha fechaDevolucion)
{
    _fechaDevolucion = fechaDevolucion;
}

void Alquiler::setPrecio(float precio)
{
    _precio = precio;
}

void Alquiler::setMulta(float multa)
{
    _multa = multa;
}

void Alquiler::setEmpleadoId(int empleadoId)
{
    _empleadoId = empleadoId;
}

void Alquiler::setEstado(AlquilerEstado estado)
{
    _estado = estado;
}
