#include "Configuracion.h"
#include "rlutil.h"
#include <iostream>
#include "AutoArchivo.h"
#include "AlquilerArchivo.h"
#include "ClienteArchivo.h"
#include "EmpleadoArchivo.h"
#include <cstdlib>
#include "Funciones.h"

using namespace std;

void Configuracion::Menu()
{
	int opcion;
	do {
		rlutil::cls();

		rlutil::locate(29, 2);
		cout << "CONFIGURACIONES" << endl;

		rlutil::locate(24, 6);
		cout << "1 _ REALIZAR COPIA DE SEGURIDAD" << endl;
		rlutil::locate(24, 7);
		cout << "2 _ RESTAURAR COPIA DE SEGURIDAD" << endl;
		rlutil::locate(24, 8);
		cout << "3 _ EXPORTAR DATOS" << endl;
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

		rlutil::locate(32, 15);
		cin >> opcion;

		switch (opcion)
		{
		case 1:
		    rlutil::cls();
			HacerCopia();
			break;
		case 2:
		    rlutil::cls();
			RestaurarCopia();
			break;
		case 3:
		    rlutil::cls();
			MenuExportarDatos();
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

void Configuracion::HacerCopia()
{
	rlutil::cls();
	int opcion;
	do {
		rlutil::cls();

		rlutil::locate(29, 2);
		cout << "REALIZAR COPIA DE SEGURIDAD" << endl;
		rlutil::locate(5, 3);
		cout << "SE GUARDAR" << char(181) << "N TODOS LOS DATOS DE TODOS LOS ARCHIVOS HASTA ESTE MOMENTO";

		
		rlutil::locate(5, 5);
		cout << char(168) << "DESEA CONTINUAR?";
		rlutil::locate(5, 7);
		cout << "1 _ HACER COPIA";
		rlutil::locate(5, 8);
		cout << "0 _ CANCELAR";
		rlutil::locate(5, 9);
		cout << "OPCI" << char(224) << "N: ";

		rlutil::locate(13, 9);
		opcion = Funciones().inputNumero(13,9,40);

		int copiado = false;
		switch (opcion)
		{
		case 1:
			copiado = AutoArchivo().HacerCopiaDeSeguridad();
			if(copiado) copiado = EmpleadoArchivo().HacerCopiaDeSeguridad();
			if (copiado) copiado = ClienteArchivo().HacerCopiaDeSeguridad();
			if (copiado) copiado = AlquilerArchivo().HacerCopiaDeSeguridad();


			if (copiado)
			{
				rlutil::locate(23, 11);
				rlutil::setColor(rlutil::LIGHTGREEN);
				cout << "LOS DATOS HAN SIDO COPIADOS EXITOSAMENTE";
				rlutil::setColor(rlutil::WHITE);
				opcion = 0;
				rlutil::locate(2, 14);
				system("pause");
			}
			else
			{
				rlutil::locate(23, 11);
				rlutil::setColor(rlutil::LIGHTRED);
				cout << "HA OCURRIDO UN ERROR AL REALIZAR LA COPIA";
				rlutil::setColor(rlutil::WHITE);
				rlutil::locate(2, 14);
				system("pause");
			}
			break;
		case 0:
			break;
		default:
			rlutil::setColor(rlutil::LIGHTRED);
			rlutil::locate(32, 15);
			cout << "OPCI" << char(224) << "N INCORRECTA" << endl;
			rlutil::setColor(rlutil::WHITE);
			rlutil::locate(32, 15);
			rlutil::anykey();
			cout << "                                      " << endl;
			break;
		}

	} while (opcion != 0);
}

void Configuracion::RestaurarCopia()
{
	rlutil::cls();
	int opcion;
	do {
		rlutil::cls();

		rlutil::locate(29, 2);
		cout << "RESTAURAR COPIA DE SEGURIDAD" << endl;

		rlutil::locate(5, 3);
		cout << "SE RESTAURAR" << char(181) << "N TODOS LOS DATOS DE TODOS LOS ARCHIVOS HASTA ESTE MOMENTO";

		rlutil::locate(5, 5);
		cout << char(168) << "DESEA CONTINUAR?";

		/*srand((unsigned)time(NULL));*/
		Fecha fecha;
		fecha.ahora();
		srand(fecha.getSegundos() * (fecha.getSegundos() + 1) );
		int random = rand() % 9000 + 1000;
		
		rlutil::locate(5, 7);
		cout << random  << " _ RESTAURAR COPIA";
		rlutil::locate(5, 8);
		cout << "0 _ CANCELAR";
		rlutil::locate(5, 9);
		cout << "OPCI" << char(224) << "N: ";

		opcion = Funciones().inputNumero(13,9,60);

		int copiado = false;

		if(opcion == random)
		{
			copiado = AutoArchivo().RestaurarCopiaDeSeguridad();
			if (copiado) copiado = EmpleadoArchivo().RestaurarCopiaDeSeguridad();
			if (copiado) copiado = ClienteArchivo().RestaurarCopiaDeSeguridad();
			if (copiado) copiado = AlquilerArchivo().RestaurarCopiaDeSeguridad();

			if (copiado)
			{
				rlutil::locate(23, 11);
				rlutil::setColor(rlutil::LIGHTGREEN);
				cout << "LOS DATOS HAN SIDO REESTABLECIDOS EXITOSAMENTE";
				rlutil::setColor(rlutil::WHITE);
				opcion = 0;
				rlutil::locate(2, 14);
				system("pause");
			}
			else
			{
				rlutil::locate(23, 11);
				rlutil::setColor(rlutil::LIGHTRED);
				cout << "HA OCURRIDO UN ERROR AL REESTAURAR LOS DATOS";
				rlutil::setColor(rlutil::WHITE);
				rlutil::locate(2, 14);
				system("pause");
			}
		}
		else if (opcion != 0)
		{
			rlutil::locate(14, 10);
			rlutil::setColor(rlutil::LIGHTRED);
			cout << "OPCI" << char(224) << "N INCORRECTA";
			rlutil::setColor(rlutil::WHITE);
			rlutil::anykey();
		}

	} while (opcion != 0);
}

void Configuracion::MenuExportarDatos()
{
	rlutil::cls();
	int opcion;
	do {
		rlutil::cls();
		rlutil::locate(29, 2);
		cout << "EXPORTAR DATOS" << endl;
		rlutil::locate(24, 6);
		cout << "1 _ AUTOS" << endl;
		rlutil::locate(24, 7);
		cout << "2 _ EMPLEADOS" << endl;
		rlutil::locate(24, 8);
		cout << "3 _ CLIENTES" << endl;
		rlutil::locate(24, 9);
		cout << "4 _ ALQUILERES" << endl;
		rlutil::locate(24, 10);
		cout << "5 _ TODOS" << endl;
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
		rlutil::locate(32, 15);
		cin >> opcion;
		switch (opcion)
		{
		case 1:
			AutoArchivo().ExportarDatos();
			rlutil::locate(11, 20);
			rlutil::setColor(rlutil::LIGHTGREEN);
			cout << "EL ARCHIVO SE HA EXPORTADO EXITOSAMENTE" << endl;
			rlutil::setColor(rlutil::WHITE);
			rlutil::anykey();
			break;
		case 2:
			EmpleadoArchivo().ExportarDatos();
			rlutil::locate(11, 20);
			rlutil::setColor(rlutil::LIGHTGREEN);
			cout << "EL ARCHIVO SE HA EXPORTADO EXITOSAMENTE" << endl;
			rlutil::setColor(rlutil::WHITE);
			rlutil::anykey();
			break;
		case 3:
			ClienteArchivo().ExportarDatos();
			rlutil::locate(11, 20);
			rlutil::setColor(rlutil::LIGHTGREEN);
			cout << "EL ARCHIVO SE HA EXPORTADO EXITOSAMENTE" << endl;
			rlutil::setColor(rlutil::WHITE);
			rlutil::anykey();
			break;
		case 4:
			AlquilerArchivo().ExportarDatos();
			rlutil::locate(11, 20);
			rlutil::setColor(rlutil::LIGHTGREEN);
			cout << "EL ARCHIVO SE HA EXPORTADO EXITOSAMENTE" << endl;
			rlutil::setColor(rlutil::WHITE);
			rlutil::anykey();
			break;
		case 5:
			AutoArchivo().ExportarDatos();
			EmpleadoArchivo().ExportarDatos();
			ClienteArchivo().ExportarDatos();
			AlquilerArchivo().ExportarDatos();
			rlutil::locate(11, 20);
			rlutil::setColor(rlutil::LIGHTGREEN);
			cout << "LOS ARCHIVOS SE HAN EXPORTADO EXITOSAMENTE" << endl;
			rlutil::setColor(rlutil::WHITE);
			rlutil::anykey();
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