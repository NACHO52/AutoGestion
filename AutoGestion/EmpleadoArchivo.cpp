#include "EmpleadoArchivo.h"
#include <cstdio>

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