#pragma once

#include <string>

class Fecha {
private:
    int _dia;
    int _mes;
    int _anio;
    bool esBisiesto();
    int _hora;
    int _minutos;
    int _segundos;

public:
    Fecha();
    Fecha(int dia, int mes, int anio);

    int getDia();
    int getMes();
    int getAnio();
    int getHora();
    int getMinutos();
    int getSegundos();
    void agregarDias(int cantidadDias);
    std::string FechaStr();
    int diferenciaDias(Fecha desde, Fecha hasta);
    void hoy();
    void ahora();
    std::string ahoraFormato();
};