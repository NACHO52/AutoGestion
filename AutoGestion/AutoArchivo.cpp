#include "AutoArchivo.h"
#include <cstdio>

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

Auto AutoArchivo::buscar(int ID)
{
    int i;
    int cant = getCantidadRegistros();
    Auto obj;
    bool encontro = false;
    for (i = 1; i < cant; i++)
    {

        FILE* p = fopen(_ruta.c_str(), "rb");
        if (p == NULL)
        {
            return obj;
        }
        fseek(p, (i - 1) * sizeof(Auto), SEEK_SET);
        fread(&obj, sizeof(Auto), 1, p);
        fclose(p);


        if (obj.getId() == ID)
        {
            encontro = true;
            break;
        }
    }
    if (encontro) return obj;
    else return Auto();
}