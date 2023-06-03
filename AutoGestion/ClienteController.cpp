#include "ClienteController.h"
#include "ClienteArchivo.h"
#include "rlutil.h"
#include <iostream>
#include <iomanip>
#include "AlquilerController.h"

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


void ClienteController::mostrarMenu()
{
    int opcion;
    do {
        rlutil::cls();

        dibujarMenu();

        rlutil::locate(32, 15);
        cin >> opcion;

        switch (opcion)
        {
        case 1:
            listar();
            break;
        case 2:
            buscarPorId();
            break;
            /*case 3:
            listarVigentes();
            break;
        case 4:
            listarTerminados();
            break;
        case 5:
            editar();
            break;
        case 6:
            buscarPorId();
            break;*/
        case 0:
            break;
        default:
            rlutil::setColor(rlutil::LIGHTRED);
            rlutil::locate(23, 17);
            cout << "OPCI" << char(224) << "N INCORRECTA" << endl;
            rlutil::setColor(rlutil::WHITE);
            rlutil::locate(40, 17);
            rlutil::anykey();
            break;
        }

    } while (opcion != 0);
}

void ClienteController::dibujarMenu()
{
    rlutil::locate(28, 2);
    cout << "CLIENTE" << endl;

    rlutil::locate(24, 6);
    cout << "1 _ LISTAR" << endl;
    rlutil::locate(24, 7);
    cout << "2 _ BUSCAR" << endl;
    rlutil::locate(24, 13);
    cout << "0 _ VOLVER" << endl;

    rlutil::locate(24, 15);
    cout << "OPCI" << char(224) << "N: " << endl;

    rlutil::locate(15, 4);
    cout << char(201);
    rlutil::locate(47, 4);
    cout << char(187);

    rlutil::locate(15, 18);
    cout << char(200);
    rlutil::locate(47, 18);
    cout << char(188);

    for (int i = 0; i < 31; i++)
    {
        rlutil::locate(16 + i, 4);
        cout << char(205);
        rlutil::locate(16 + i, 18);
        cout << char(205);
    }
    for (int i = 0; i < 13; i++)
    {
        rlutil::locate(15, 5 + i);
        cout << char(186);
        rlutil::locate(47, 5 + i);
        cout << char(186);
    }
}

void ClienteController::listarHeader()
{
    rlutil::locate(2, 2);
    cout << "ID";
    rlutil::locate(7, 2);
    cout << "NOMBRE";
    rlutil::locate(22, 2);
    cout << "APELLIDO";
    rlutil::locate(35, 2);
    cout << "FEC. DE NACIMIENTO";
    rlutil::locate(55, 2);
    cout << "D.N.I.";
    rlutil::locate(64, 2);
    cout << "E-MAIL";

    rlutil::locate(1, 1);
    cout << char(218);
    rlutil::locate(1, 3);
    cout << char(192);
    for (int i = 2; i < 80; i++)
    {
        rlutil::locate(i, 1);
        cout << char(196);
        rlutil::locate(i, 3);
        cout << char(196);
    }
    rlutil::locate(80, 1);
    cout << char(191);
    rlutil::locate(80, 3);
    cout << char(217);

    rlutil::locate(1, 2);
    cout << char(179);
    rlutil::locate(5, 2);
    cout << char(179);
    rlutil::locate(20, 2);
    cout << char(179);
    rlutil::locate(34, 2);
    cout << char(179);
    rlutil::locate(53, 2);
    cout << char(179);
    rlutil::locate(62, 2);
    cout << char(179);
    rlutil::locate(80, 2);
    cout << char(179);


    rlutil::locate(5, 1);
    cout << char(194);
    rlutil::locate(5, 3);
    cout << char(193);

    rlutil::locate(20, 1);
    cout << char(194);
    rlutil::locate(20, 3);
    cout << char(193);

    rlutil::locate(34, 1);
    cout << char(194);
    rlutil::locate(34, 3);
    cout << char(193);

    rlutil::locate(53, 1);
    cout << char(194);
    rlutil::locate(53, 3);
    cout << char(193);

    rlutil::locate(62, 1);
    cout << char(194);
    rlutil::locate(62, 3);
    cout << char(193);
}

void ClienteController::listar()
{
    rlutil::cls();
    listarHeader();

    ClienteArchivo archivo;
    int registrosImpresos = 0;
    int cant = archivo.getCantidadRegistros();
    if (cant == 0)
    {
        imprimirNoHayRegistros();
    }
    else
    {
        for (int j = 1; j <= cant; j++)
        {
            Cliente obj;
            obj = archivo.buscar(j);

            DibujarFila(registrosImpresos, obj);
            registrosImpresos++;
        }

        if (registrosImpresos == 0) {
            imprimirNoHayRegistros();
        }
    }

    rlutil::locate(1, registrosImpresos * 2 + 8);
    cout << endl << endl << endl << system("pause");
}

void ClienteController::imprimirNoHayRegistros()
{
    rlutil::locate(27, 5);
    cout << "No hay registros cargados.";

    rlutil::locate(1, 6);
    cout << char(192);
    rlutil::locate(1, 4);
    cout << char(179);
    rlutil::locate(1, 5);
    cout << char(179);
    rlutil::locate(78, 4);
    cout << char(179);
    rlutil::locate(78, 5);
    cout << char(179);
    rlutil::locate(78, 6);
    cout << char(217);

    rlutil::locate(1, 3);
    cout << char(195);

    rlutil::locate(78, 3);
    cout << char(180);
    for (int i = 0; i < 76; i++)
    {
        rlutil::locate(2 + i, 6);
        cout << char(196);
    }

    cout << endl;
}


void ClienteController::DibujarFila(int corrimiento, Cliente& obj)
{
    rlutil::locate(1, 3 + corrimiento * 2);
    cout << char(195);

    rlutil::locate(1, 4 + corrimiento * 2);
    cout << char(179);
    rlutil::locate(80, 4 + corrimiento * 2);
    cout << char(179);

    rlutil::locate(5, 3 + corrimiento * 2);
    cout << char(197);
    rlutil::locate(20, 3 + corrimiento * 2);
    cout << char(197);
    rlutil::locate(34, 3 + corrimiento * 2);
    cout << char(197);
    rlutil::locate(53, 3 + corrimiento * 2);
    cout << char(197);
    rlutil::locate(62, 3 + corrimiento * 2);
    cout << char(197);

    rlutil::locate(80, 3 + corrimiento * 2);
    cout << char(180);

    rlutil::locate(2, 4 + corrimiento * 2);
    cout << setw(3) << obj.getId();
    rlutil::locate(6, 4 + corrimiento * 2);
    cout << setw(13) << obj.getNombre();
    rlutil::locate(21, 4 + corrimiento * 2);
    cout << setw(12) << obj.getApellido();
    rlutil::locate(35, 4 + corrimiento * 2);
    cout << setw(17) << obj.getFechaDeNacimiento().FechaStr();
    rlutil::locate(54, 4 + corrimiento * 2);
    cout << setw(8) << obj.getDni();
    rlutil::locate(63, 4 + corrimiento * 2);
    cout << setw(16) << obj.getMail();

    rlutil::locate(5, 4 + corrimiento * 2);
    cout << char(179);
    rlutil::locate(20, 4 + corrimiento * 2);
    cout << char(179);
    rlutil::locate(34, 4 + corrimiento * 2);
    cout << char(179);
    rlutil::locate(53, 4 + corrimiento * 2);
    cout << char(179);
    rlutil::locate(62, 4 + corrimiento * 2);
    cout << char(179);

    rlutil::locate(1, 5 + corrimiento * 2);
    cout << char(192);
    rlutil::locate(80, 5 + corrimiento * 2);
    cout << char(217);
    for (int j = 2; j < 80; j++)
    {
        rlutil::locate(j, 5 + corrimiento * 2);
        cout << char(196);
    }
    rlutil::locate(5, 5 + corrimiento * 2);
    cout << char(193);
    rlutil::locate(20, 5 + corrimiento * 2);
    cout << char(193);
    rlutil::locate(34, 5 + corrimiento * 2);
    cout << char(193);
    rlutil::locate(53, 5 + corrimiento * 2);
    cout << char(193);
    rlutil::locate(62, 5 + corrimiento * 2);
    cout << char(193);
}

void ClienteController::buscarPorId()
{
    rlutil::cls();
    rlutil::locate(30, 2);
    cout << "BUSCAR CLIENTE";

    Cliente obj;
    ClienteArchivo archivo;
    int id;
    rlutil::locate(9, 3);
    cout << "ID: ";
    rlutil::locate(13, 3);
    cin >> id;

    obj = archivo.buscar(id);
    if (obj.getId() > 0)
    {
        mostrarRegistro(obj);
    }
    else
    {
        rlutil::locate(2, 8);
        cout << "El registro con Id " << id << " no se encuentra en el sistema." << endl;
    }
}

void ClienteController::mostrarRegistro(Cliente obj)
{
    rlutil::locate(9, 5);
    cout << "APELLIDO: ";
    rlutil::locate(19, 5);
    cout << obj.getApellido();

    rlutil::locate(9, 7);
    cout << "NOMBRE: ";
    rlutil::locate(19, 7);
    cout << obj.getNombre();

    rlutil::locate(9, 9);
    cout << "D.N.I.: ";
    rlutil::locate(19, 9);
    cout << obj.getDni();

    rlutil::locate(44, 5);
    cout << "FECHA DE NACIMIENTO: ";
    rlutil::locate(65, 5);
    cout << obj.getFechaDeNacimiento().FechaStr();

    rlutil::locate(44, 7);
    cout << "TELEF" << char(224) << "NO: ";
    rlutil::locate(54, 7);
    cout << obj.getTelefono();

    rlutil::locate(44, 9);
    cout << "E-MAIL: ";
    rlutil::locate(52, 9);
    cout << obj.getMail();

    int registrosImpresos = AlquilerController().listarPorCliente(0,10, obj.getId());


    rlutil::locate(2, registrosImpresos * 2 + 17);
    cout << endl << endl << endl << system("pause");
}
