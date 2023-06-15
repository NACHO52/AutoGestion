#include "AutoArchivo.h"
#include <cstdio>
#include "Fecha.h"
#include <iostream>
#include <fstream>
#include <string.h>

AutoArchivo::AutoArchivo()
{
    _ruta = "autos.dat";
}

AutoArchivo::AutoArchivo(std::string ruta)
{
    _ruta = ruta;
}

int AutoArchivo::getCantidadRegistros()
{
    FILE* p = fopen(_ruta.c_str(), "rb");
    if (p == NULL)
    {
        return 0;
    }
    fseek(p, 0, SEEK_END);
    int bytes = ftell(p);
    fclose(p);
    return bytes / sizeof(Auto);
}

bool AutoArchivo::guardar(Auto reg)
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
        fseek(p, (id - 1) * sizeof(Auto), SEEK_SET);
    }

    guardo = fwrite(&reg, sizeof(Auto), 1, p);
    fclose(p);
    return guardo;
}

Auto AutoArchivo::buscar(int id)
{
    int i;
    int cant = getCantidadRegistros();
    Auto obj;
    bool encontro = false;
    for (i = 1; i <= cant; i++)
    {

        FILE* p = fopen(_ruta.c_str(), "rb");
        if (p == NULL)
        {
            return obj;
        }
        fseek(p, (i - 1) * sizeof(Auto), SEEK_SET);
        fread(&obj, sizeof(Auto), 1, p);
        fclose(p);


        if (obj.getId() == id)
        {
            encontro = true;
            break;
        }
    }
    if (encontro) return obj;
    else return Auto();
}

void AutoArchivo::leer(Auto* vec, int cantidadRegistrosALeer) {
    FILE* p = fopen(_ruta.c_str(), "rb");
    if (p == NULL)
    {
        return;
    }

    fread(vec, sizeof(Auto), cantidadRegistrosALeer, p);
    fclose(p);
}

void AutoArchivo::vaciar() {
    FILE* p = fopen(_ruta.c_str(), "wb");
    if (p == NULL)
    {
        return;
    }
    fclose(p);
}

bool AutoArchivo::guardar(Auto* vec, int cantidadRegistrosAEscribir) {
    FILE* p = fopen(_ruta.c_str(), "ab");
    if (p == NULL)
    {
        return false;
    }

    int cantidadRegistrosEscritos = fwrite(vec, sizeof(Auto), cantidadRegistrosAEscribir, p);
    fclose(p);
    return cantidadRegistrosEscritos == cantidadRegistrosAEscribir;
}

bool AutoArchivo::HacerCopiaDeSeguridad()
{
    bool exito = false;
    AutoArchivo archivoBKP("autos.bkp");
    AutoArchivo archivo;

    int cantidadRegistros = archivo.getCantidadRegistros();
    Auto* vec = new Auto[cantidadRegistros];
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

bool AutoArchivo::RestaurarCopiaDeSeguridad() {
    bool exito = false;
    AutoArchivo archivoBKP("autos.bkp");
    AutoArchivo archivo;
    int cantidadRegistros = archivoBKP.getCantidadRegistros();
    Auto* vec = new Auto[cantidadRegistros];

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

void AutoArchivo::ExportarDatos()
{
    std::fstream fout;
    fout.open("autos.csv", std::ios::out);

    int cant = getCantidadRegistros();
    if (cant == 0) return;
    fout << "Id,Marca,Modelo,Patente,Año,Estado\n";
    for (int i = 1; i <= cant; i++)
    {
        Auto obj = buscar(i);
        fout << obj.getId() << "," << obj.getMarca() << "," << obj.getModelo() << "," << obj.getPatente() << "," << obj.getAnio() << "," << obj.getEstadoStr() << "\n";
    }
    fout.close();
}
