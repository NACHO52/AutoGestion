#include "ClienteArchivo.h"
#include <cstdio>

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
