#pragma once

#include <string>

class Fecha {
private:
    int _dia;
    int _mes;
    int _anio;
    bool esBisiesto();

public:
    Fecha();
    Fecha(int dia, int mes, int anio);

    int getDia();
    int getMes();
    int getAnio();
    void agregarDias(int cantidadDias);
    std::string FechaStr();
    void hoy();
};