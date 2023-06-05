#include "ClienteArchivo.h"
#include <cstdio>
#include <iostream>
#include <fstream>

ClienteArchivo::ClienteArchivo()
{
    _ruta = "cliente.dat";
}

ClienteArchivo::ClienteArchivo(std::string ruta)
{
    _ruta = ruta;
}

int ClienteArchivo::getCantidadRegistros()
{
    FILE* p = fopen(_ruta.c_str(), "rb");
    if (p == NULL)
    {
        return 0;
    }
    fseek(p, 0, SEEK_END);
    int bytes = ftell(p);
    fclose(p);
    return bytes / sizeof(Cliente);
}

bool ClienteArchivo::guardar(Cliente reg)
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
        fseek(p, (id - 1) * sizeof(Cliente), SEEK_SET);
    }

    guardo = fwrite(&reg, sizeof(Cliente), 1, p);
    fclose(p);
    return guardo;
}

Cliente ClienteArchivo::buscar(int ID)
{
    int i;
    int cant = getCantidadRegistros();
    Cliente obj;
    bool encontro = false;
    for (i = 1; i <= cant; i++)
    {

        FILE* p = fopen(_ruta.c_str(), "rb");
        if (p == NULL)
        {
            return obj;
        }
        fseek(p, (i - 1) * sizeof(Cliente), SEEK_SET);
        fread(&obj, sizeof(Cliente), 1, p);
        fclose(p);


        if (obj.getId() == ID)
        {
            encontro = true;
            break;
        }
    }
    if (encontro) return obj;
    else return Cliente();
}

Cliente ClienteArchivo::buscarPorDNI(std::string dni)
{
    int i;
    int cant = getCantidadRegistros();
    Cliente obj;
    bool encontro = false;
    for (i = 1; i <= cant; i++)
    {

        FILE* p = fopen(_ruta.c_str(), "rb");
        if (p == NULL)
        {
            return obj;
        }
        fseek(p, (i - 1) * sizeof(Cliente), SEEK_SET);
        fread(&obj, sizeof(Cliente), 1, p);
        fclose(p);


        if (strcmp(obj.getDni().c_str(), dni.c_str()) == 0)
        {
            encontro = true;
            break;
        }
    }
    if (encontro) return obj;
    else return Cliente();
}


void ClienteArchivo::leer(Cliente* vec, int cantidadRegistrosALeer) {
    FILE* p = fopen(_ruta.c_str(), "rb");
    if (p == NULL)
    {
        return;
    }

    fread(vec, sizeof(Cliente), cantidadRegistrosALeer, p);
    fclose(p);
}

void ClienteArchivo::vaciar() {
    FILE* p = fopen(_ruta.c_str(), "wb");
    if (p == NULL)
    {
        return;
    }
    fclose(p);
}

bool ClienteArchivo::guardar(Cliente* vec, int cantidadRegistrosAEscribir) {
    FILE* p = fopen(_ruta.c_str(), "ab");
    if (p == NULL)
    {
        return false;
    }

    int cantidadRegistrosEscritos = fwrite(vec, sizeof(Cliente), cantidadRegistrosAEscribir, p);
    fclose(p);
    return cantidadRegistrosEscritos == cantidadRegistrosAEscribir;
}

bool ClienteArchivo::HacerCopiaDeSeguridad()
{
    bool exito = false;
    ClienteArchivo archivoBKP("clientes.bkp");
    ClienteArchivo archivo;

    int cantidadRegistros = archivo.getCantidadRegistros();
    Cliente* vec = new Cliente[cantidadRegistros];
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

bool ClienteArchivo::RestaurarCopiaDeSeguridad() {
    bool exito = false;
    ClienteArchivo archivoBKP("clientes.bkp");
    ClienteArchivo archivo;
    int cantidadRegistros = archivoBKP.getCantidadRegistros();
    Cliente* vec = new Cliente[cantidadRegistros];

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

void ClienteArchivo::ExportarDatos()
{
    std::fstream fout;
    fout.open("clientes.csv", std::ios::out);

    int cant = getCantidadRegistros();
    if (cant == 0) return;
    fout << "Id,Apellido,Nombre,DNI,FechaDeNacimiento,EMail,Tel"<< char(130) <<"fono\n";
    for (int i = 1; i <= cant; i++)
    {
        Cliente obj = buscar(i);
        fout << obj.getId() << "," << obj.getApellido() << "," << obj.getNombre() << "," << obj.getDni() << "," << obj.getFechaDeNacimiento().FechaStr() << "," << obj.getMail() << obj.getTelefono() << "\n";
    }
    fout.close();
}