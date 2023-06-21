#include "ReportesController.h"
#include "rlutil.h"
#include "EmpleadoArchivo.h"
#include "AlquilerArchivo.h"
#include "ClienteArchivo.h"
#include "AutoArchivo.h"
#include <iomanip>

using namespace std;

void ReportesController::mostrarMenu()
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
		    rlutil::cls();
			recaudacionPorEmpleado();
			system("pause");
			break;
		case 2:
		    rlutil::cls();
			recaudacionPorCliente();
			system("pause");
			break;
		case 3:
		    rlutil::cls();
			reportePorAuto();
			system("pause");
			break;
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

void ReportesController::dibujarMenu()
{
        rlutil::locate(29, 2);
		cout << "REPORTES" << endl;

		rlutil::locate(24, 6);
		cout << "1 _ RECAUDACION POR EMPLEADO" << endl;
		rlutil::locate(24, 7);
		cout << "2 _ RECAUDACION POR CLIENTE" << endl;
		rlutil::locate(24, 8);
		cout << "3 _ AUTOS MAS ELEGIDOS" << endl;
		rlutil::locate(24, 13);
		cout << "0 _ VOLVER" << endl;

		rlutil::locate(24, 15);
		cout << "OPCI" << char(224) << "N: " << endl;

		rlutil::locate(15, 4);
		cout << char(201);
		rlutil::locate(63, 4);
		cout << char(187);

		rlutil::locate(15, 18);
		cout << char(200);
		rlutil::locate(63, 18);
		cout << char(188);

		for (int i = 16; i < 63; i++)
		{
			rlutil::locate(i, 4);
			cout << char(205);
			rlutil::locate(i, 18);
			cout << char(205);
		}
		for (int i = 0; i < 13; i++)
		{
			rlutil::locate(15, 5 + i);
			cout << char(186);
			rlutil::locate(63, 5 + i);
			cout << char(186);
		}
}

void ReportesController::recaudacionPorEmpleado()
{
    listarHeader();

    EmpleadoArchivo archivo;

	int cant = archivo.getCantidadRegistros();
	if (cant == 0) return;

	AlquilerArchivo archivo2;

	int cant2 = archivo2.getCantidadRegistros();
	if (cant2 == 0) return;

    float recaudacion = 0;
    for (int i = 1; i <= cant; i++)
	{
		Empleado obj;
		obj = archivo.buscar(i);
		if (obj.getEliminado() == 1 || obj.getEstado() == EmpleadoEstado::Baja)
		{
			continue;
		}
		for (int j = 1; j <= cant2; j++)
            {
                Alquiler obj2;
                obj2 = archivo2.buscar(j);
                if (obj.getId() == obj2.getEmpleadoId())
                {
                    recaudacion += obj2.getPrecio();
                }
            }
        cout<<endl;
        cout<< obj.getNombre()<<endl;
        cout<< obj.getApellido()<<endl;
        cout<< recaudacion<<endl;

        recaudacion=0;
	}
}

void ReportesController::recaudacionPorCliente()
{
    listarHeader();

    AlquilerArchivo archivo;

	int cant = archivo.getCantidadRegistros();
	if (cant == 0) return;

	ClienteArchivo archivo2;

	int cant2 = archivo2.getCantidadRegistros();
	if (cant2 == 0) return;

    Cliente obj;
    Alquiler obj2;

    float recaudacion = 0;
    for (int i = 1; i <= cant2; i++)
	{
		obj = archivo2.buscar(i);
		for (int j = 1; j <= cant; j++)
            {
                obj2 = archivo.buscar(j);
                if (obj.getId() == obj2.getClienteId())
                {
                    recaudacion += obj2.getPrecio();
                }
            }
        cout<<endl;
        cout<< obj.getNombre()<<endl;
        cout<< obj.getApellido()<<endl;
        cout<< recaudacion<<endl;
        recaudacion=0;
	}
}

void ReportesController::reportePorAuto()
{
    listarHeader();

    AutoArchivo archivo;

	int cant = archivo.getCantidadRegistros();
	if (cant == 0) return;

	AlquilerArchivo archivo2;

	int cant2 = archivo2.getCantidadRegistros();
	if (cant2 == 0) return;

    Auto obj;
    Alquiler obj2;

    float recaudacion = 0;
    for (int i = 1; i <= cant; i++)
	{
		obj = archivo.buscar(i);
		for (int j = 1; j <= cant2; j++)
            {
                obj2 = archivo2.buscar(j);
                if (obj.getId() == obj2.getAutoId())
                {
                    recaudacion += obj2.getPrecio();
                }
            }
        cout<<endl;
        cout<< obj.getMarca()<<endl;
        cout<< obj.getModelo()<<endl;
        cout<< obj.getPatente()<<endl;
        cout<< obj.getAnio()<<endl;
        cout<<"Recaudo: "<< recaudacion<<endl;
        recaudacion=0;
	}
}


void ReportesController::listarHeader()
{
    rlutil::locate(2, 2);
    cout << "NOMBRE";
    rlutil::locate(7, 2);
    cout << "APELLIDO";
    rlutil::locate(22, 2);
    cout << "RECAUDACION";

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
