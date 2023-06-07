#include <string>
#include "Fecha.h"
#include <ctime>

int dias[12] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };

bool Fecha::esBisiesto() {
    if ((_anio % 4 == 0 && _anio % 100 != 0) || _anio % 400 == 0) {
        return true;
    }
    return false;
}

void Fecha::agregarDias(int cantidadDias) {

    if (cantidadDias > 0) {
        for (int i = 0; i < cantidadDias; i++) {

            if (esBisiesto()) {
                dias[1]++;
            }

            _dia++;
            if (_dia > dias[_mes - 1]) {
                _dia = 1;
                _mes++;
                if (_mes > 12) {
                    _mes = 1;
                    _anio++;
                }
            }
        }
    }
}

Fecha::Fecha() {
    _dia = 1;
    _mes = 1;
    _anio = 1900;
    _hora = 0;
    _minutos = 0;
    _segundos = 0;

}

void Fecha::hoy() {

    time_t t;
    t = time(NULL);
    struct tm* fecha;
    fecha = localtime(&t);
    _anio = fecha->tm_year + 1900;
    _mes = fecha->tm_mon + 1;
    _dia = fecha->tm_mday;
    _hora = 0;
    _minutos = 0;
    _segundos = 0;
}

void Fecha::ahora()
{
    time_t t;
    t = time(NULL);
    struct tm* fecha;
    fecha = localtime(&t);
    _anio = fecha->tm_year + 1900;
    _mes = fecha->tm_mon + 1;
    _dia = fecha->tm_mday;
    _hora = fecha->tm_hour;
    _minutos = fecha->tm_min;
    _segundos = fecha->tm_sec;
}

std::string Fecha::ahoraFormato()
{
    ahora();
    std::string formato = "";

    std::string dia = std::to_string(_dia);
    std::string mes = std::to_string(_mes);
    std::string anio = std::to_string(_anio);

    std::string hora = std::to_string(_hora);
    std::string minutos = std::to_string(_minutos);
    std::string segundos = std::to_string(_segundos);

    if (_dia < 10) {
        dia = "0" + std::to_string(_dia);
    }
    if (_mes < 10) {
        mes = "0" + std::to_string(_mes);
    }

    if (_hora < 10) hora = "0" + std::to_string(_hora);
    if (_minutos < 10) minutos = "0" + std::to_string(_minutos);
    if (_segundos < 10) segundos = "0" + std::to_string(_segundos);

    formato = anio + mes + dia + "_" + hora + minutos + segundos;

    return formato;
}

Fecha::Fecha(int dia, int mes, int anio) {

    _dia = 1;
    _mes = 1;
    _anio = 1900;
    _hora = 0;
    _minutos = 0;
    _segundos = 0;
    if (dia <= 0 || mes <= 0 || anio <= 0 || mes > 12) {
        return;
    }
    else {
        if (esBisiesto()) {
            dias[1]++;
        }

        if (_dia > dias[_mes - 1]) {
            return;
        }
    }
    _dia = dia;
    _mes = mes;
    _anio = anio;
}

int Fecha::getDia() {
    return _dia;
}

int Fecha::getMes() {
    return _mes;
}

int Fecha::getAnio() {
    return _anio;
}

int Fecha::getHora()
{
    return _hora;
}

int Fecha::getMinutos()
{
    return _minutos;
}

int Fecha::getSegundos()
{
    return _segundos;
}

std::string Fecha::FechaStr() {

    std::string texto = "";

    std::string dia = std::to_string(_dia);
    std::string mes = std::to_string(_mes);
    std::string anio = std::to_string(_anio);

    if (_dia < 10) {
        dia = "0" + std::to_string(_dia);
    }
    if (_mes < 10) {
        mes = "0" + std::to_string(_mes);
    }

    texto = dia + "/" + mes + "/" + anio;

    return texto;
}

int Fecha::diferenciaDias(Fecha desde, Fecha hasta)
{
    int resultado = 0;


    while (!(desde.getAnio() == hasta.getAnio() && desde.getMes() == hasta.getMes() && desde.getDia() == hasta.getDia()))
    {
        desde.agregarDias(1);
        resultado++;
    }
    return resultado;
}
