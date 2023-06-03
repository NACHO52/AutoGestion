#include "ClienteController.h"
#include "ClienteArchivo.h"
#include "rlutil.h"
#include <iostream>

using namespace std;

Cliente ClienteController::ventanaNuevoCliente(std::string dni)
{
    Cliente cliente;
    std::string nombre, apellido, telefono, mail;
    int dia, mes, anio;

    rlutil::locate(5,6);
    cout << char(218);
    rlutil::locate(72, 6);
    cout << char(191);
    rlutil::locate(5, 12);
    cout << char(192);
    rlutil::locate(72, 12);
    cout << char(217);

    for (int i = 0; i < 66; i++)
    {
        rlutil::locate(6 + i, 6);
        cout << char(196);
        rlutil::locate(6 + i, 12);
        cout << char(196);
    }
    for (int i = 0; i < 5; i++)
    {
        rlutil::locate(5, 7+ i);
        cout << char(179);
        rlutil::locate(72, 7 + i);
        cout << char(179);
    }

    rlutil::locate(6, 7);
    cout << "NOMBRE:";
    rlutil::locate(6, 9);
    cout << "APELLIDO:";
    rlutil::locate(6, 11);
    cout << "FECHA DE NACIMIENTO (DD/MM/AAAA):";
    rlutil::locate(40, 11);
    cout << "__/__/____";

    rlutil::locate(41, 7);
    cout << "TEL"<< char(144) <<"FONO:";
    rlutil::locate(41, 9);
    cout << "MAIL:";

    rlutil::locate(14, 7);
    getline(cin, nombre);

    rlutil::locate(16, 9);
    getline(cin, apellido);

    rlutil::locate(51, 7);
    getline(cin, telefono);

    rlutil::locate(47, 9);
    getline(cin, mail);

    rlutil::locate(40, 11);
    cin >> dia;
    rlutil::locate(43, 11);
    cin >> mes;
    rlutil::locate(46, 11);
    cin >> anio;

    Fecha fechaNacimiento(dia, mes, anio);
    
    cliente.setApellido(apellido);
    cliente.setNombre(nombre);
    cliente.setDni(dni);
    cliente.setFechaDeNacimiento(fechaNacimiento);
    cliente.setMail(mail);
    cliente.setTelefono(telefono);

    ClienteArchivo().guardar(cliente);

    for (int i = 5; i < 74; i++)
    {
        for (int j = 5; j < 14; j++)
        {
            rlutil::locate(i, j);
            cout << " ";
        }
    }

    return cliente;
}
