#include <cstdio>
#include <iostream>
#include <fstream>
#include <string.h>
#include "AlquilerArchivo.h"


AlquilerArchivo::AlquilerArchivo()
{
    _ruta = "alquiler.dat";
}

AlquilerArchivo::AlquilerArchivo(std::string ruta)
{
    _ruta = ruta;
}

int AlquilerArchivo::getCantidadRegistros()
{
    FILE* p = fopen(_ruta.c_str(), "rb");
    if (p == NULL)
    {
        return 0;
    }
    fseek(p, 0, SEEK_END);
    int bytes = ftell(p);
    fclose(p);
    return bytes / sizeof(Alquiler);
}

bool AlquilerArchivo::guardar(Alquiler reg)
{
    int id = reg.getId();
    bool guardo = false;
    std::string mode = "";
    if (id == 0)
    {
        mode = "ab";
        reg.setId(getCantidadRegistros() + 1);
    }
    else if (id > 0)
    {
        mode = "rb+";
    }
    FILE* p = fopen(_ruta.c_str(), mode.c_str());
    if (p == NULL)
    {
        return false;
    }

    if (strcmp(mode.c_str(), "rb+") == 0)
    {
        fseek(p, (id - 1) * sizeof(Alquiler), SEEK_SET);
    }

    guardo = fwrite(&reg, sizeof(Alquiler), 1, p);
    fclose(p);
    return guardo;
}

Alquiler AlquilerArchivo::buscar(int ID)
{
    int i;
    int cant = getCantidadRegistros();
    Alquiler obj;
    bool encontro = false;
    for (i = 1; i <= cant; i++)
    {

        FILE* p = fopen(_ruta.c_str(), "rb");
        if (p == NULL)
        {
            return obj;
        }
        fseek(p, (i - 1) * sizeof(Alquiler), SEEK_SET);
        fread(&obj, sizeof(Alquiler), 1, p);
        fclose(p);


        if (obj.getId() == ID)
        {
            encontro = true;
            break;
        }
    }
    if (encontro) return obj;
    else return Alquiler();
}

void AlquilerArchivo::leer(Alquiler* vec, int cantidadRegistrosALeer) {
    FILE* p = fopen(_ruta.c_str(), "rb");
    if (p == NULL)
    {
        return;
    }

    fread(vec, sizeof(Alquiler), cantidadRegistrosALeer, p);
    fclose(p);
}

void AlquilerArchivo::vaciar() {
    FILE* p = fopen(_ruta.c_str(), "wb");
    if (p == NULL)
    {
        return;
    }
    fclose(p);
}

bool AlquilerArchivo::guardar(Alquiler* vec, int cantidadRegistrosAEscribir) {
    FILE* p = fopen(_ruta.c_str(), "ab");
    if (p == NULL)
    {
        return false;
    }

    int cantidadRegistrosEscritos = fwrite(vec, sizeof(Alquiler), cantidadRegistrosAEscribir, p);
    fclose(p);
    return cantidadRegistrosEscritos == cantidadRegistrosAEscribir;
}

bool AlquilerArchivo::HacerCopiaDeSeguridad()
{
    bool exito = false;
    AlquilerArchivo archivoBKP("alquileres.bkp");
    AlquilerArchivo archivo;

    int cantidadRegistros = archivo.getCantidadRegistros();
    Alquiler* vec = new Alquiler[cantidadRegistros];
    if (vec == nullptr) {
        exito = false;
    }

    archivo.leer(vec, cantidadRegistros);
    archivoBKP.vaciar();
    if (archivoBKP.guardar(vec, cantidadRegistros)) {
        exito = true;
    }
    else {
        exito = false;
    }
    delete[]vec;
    return exito;
}

bool AlquilerArchivo::RestaurarCopiaDeSeguridad() {
    bool exito = false;
    AlquilerArchivo archivoBKP("alquileres.bkp");
    AlquilerArchivo archivo;
    int cantidadRegistros = archivoBKP.getCantidadRegistros();
    Alquiler* vec = new Alquiler[cantidadRegistros];

    if (vec == nullptr) {
        exito = false;
    }

    archivoBKP.leer(vec, cantidadRegistros);
    archivo.vaciar();
    if (archivo.guardar(vec, cantidadRegistros)) {
        exito = true;
    }
    else {
        exito = false;
    }
    delete[]vec;
    return exito;
}

void AlquilerArchivo::ExportarDatos()
{
    std::fstream fout;
    std::string archivo = "alquileres";
    Fecha ahora;
    ahora.ahora();
    archivo = archivo + "_" + ahora.ahoraFormato() + ".csv";
    fout.open(archivo, std::ios::out);

    int cant = getCantidadRegistros();
    if (cant == 0) return;
    fout << "Id,AutoId,ClienteId,EmpleadoId,EstadoId,FechaDesde,FechaHasta,Precio\n";
    for (int i = 1; i <= cant; i++)
    {
        Alquiler obj = buscar(i);
        fout << obj.getId() << "," << obj.getAutoId() << "," << obj.getClienteId() << "," << obj.getEmpleadoId() << "," << obj.getEstadoStr() << "," << obj.getFechaDesde().FechaStr() << obj.getFechaHasta().FechaStr() << obj.getPrecio() << "\n";
    }
    fout.close();
}
