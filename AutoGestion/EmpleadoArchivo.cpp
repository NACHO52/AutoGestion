#include "EmpleadoArchivo.h"
#include <cstdio>
#include "Fecha.h"
#include <iostream>
#include <fstream>

EmpleadoArchivo::EmpleadoArchivo()
{
    _ruta = "empleado.dat";
}

EmpleadoArchivo::EmpleadoArchivo(std::string ruta)
{
    _ruta = ruta;
}

int EmpleadoArchivo::getCantidadRegistros()
{
    FILE* p = fopen(_ruta.c_str(), "rb");
    if (p == NULL)
    {
        return 0;
    }
    fseek(p, 0, SEEK_END);
    int bytes = ftell(p);
    fclose(p);
    return bytes / sizeof(Empleado);
}

bool EmpleadoArchivo::guardar(Empleado reg)
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
        fseek(p, (id - 1) * sizeof(Empleado), SEEK_SET);
    }

    guardo = fwrite(&reg, sizeof(Empleado), 1, p);
    fclose(p);
    return guardo;
}

Empleado EmpleadoArchivo::buscar(int ID)
{
    int i;
    int cant = getCantidadRegistros();
    Empleado obj;
    bool encontro = false;
    for (i = 1; i <= cant; i++)
    {

        FILE* p = fopen(_ruta.c_str(), "rb");
        if (p == NULL)
        {
            return obj;
        }
        fseek(p, (i - 1) * sizeof(Empleado), SEEK_SET);
        fread(&obj, sizeof(Empleado), 1, p);
        fclose(p);


        if (obj.getId() == ID)
        {
            encontro = true;
            break;
        }
    }
    if (encontro) return obj;
    else return Empleado();
}

void EmpleadoArchivo::leer(Empleado* vec, int cantidadRegistrosALeer) {
    FILE* p = fopen(_ruta.c_str(), "rb");
    if (p == NULL)
    {
        return;
    }

    fread(vec, sizeof(Empleado), cantidadRegistrosALeer, p);
    fclose(p);
}

void EmpleadoArchivo::vaciar() {
    FILE* p = fopen(_ruta.c_str(), "wb");
    if (p == NULL)
    {
        return;
    }
    fclose(p);
}

bool EmpleadoArchivo::guardar(Empleado* vec, int cantidadRegistrosAEscribir) {
    FILE* p = fopen(_ruta.c_str(), "ab");
    if (p == NULL)
    {
        return false;
    }

    int cantidadRegistrosEscritos = fwrite(vec, sizeof(Empleado), cantidadRegistrosAEscribir, p);
    fclose(p);
    return cantidadRegistrosEscritos == cantidadRegistrosAEscribir;
}

bool EmpleadoArchivo::HacerCopiaDeSeguridad()
{
    bool exito = false;
    EmpleadoArchivo archivoBKP("empleados.bkp");
    EmpleadoArchivo archivo;

    int cantidadRegistros = archivo.getCantidadRegistros();
    Empleado* vec = new Empleado[cantidadRegistros];
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

bool EmpleadoArchivo::RestaurarCopiaDeSeguridad() {
    bool exito = false;
    EmpleadoArchivo archivoBKP("empleados.bkp");
    EmpleadoArchivo archivo;
    int cantidadRegistros = archivoBKP.getCantidadRegistros();
    Empleado* vec = new Empleado[cantidadRegistros];

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

void EmpleadoArchivo::ExportarDatos()
{
    std::fstream fout;
    fout.open("empleados.csv", std::ios::out);

    int cant = getCantidadRegistros();
    if (cant == 0) return;
    fout << "Id,Apellido,Nombre,Estado,Sueldo,Email\n";
    for (int i = 1; i <= cant; i++)
    {
        Empleado obj = buscar(i);
        fout << obj.getId() << "," << obj.getApellido() << "," << obj.getNombre() << "," << obj.getEstadoStr() << "," << obj.getSueldo() << "," << obj.getMail() << "\n";
    }
    fout.close();
}