#include <iostream>
#include "rlutil.h"
#include "Funciones.h"
#include "AutoController.h"
#include "EmpleadoController.h"
#include "AlquilerController.h"
#include "ClienteController.h"
#include "ReportesController.h"
#include "Configuracion.h"

using namespace std;

void Funciones::MenuPrincipal()
{
	int opcion = 99;
	string seleccion = "";
	do
	{
		rlutil::cls();
		DibujarMenu();
		opcion = inputNumero(27, 22, 28);

		switch (opcion)
		{
		case 1:
			rlutil::cls();
			AutoController().mostrarMenu();
			break;
		case 2:
			rlutil::cls();
			EmpleadoController().mostrarMenu();
			break;
		case 3:
			rlutil::cls();
			AlquilerController().mostrarMenu();
			break;
		case 4:
			rlutil::cls();
			ClienteController().mostrarMenu();
			break;
		case 5:
			rlutil::cls();
			ReportesController().mostrarMenu();
			break;
		case 6:
			rlutil::cls();
			Configuracion().Menu();
			break;
		case 0:
			break;
		default:
			rlutil::setColor(rlutil::LIGHTRED);
			rlutil::locate(27, 22);
			cout << "OPCI" << char(224) << "N INCORRECTA" << endl;
			rlutil::setColor(rlutil::WHITE);
			rlutil::locate(44, 22);
			rlutil::anykey();
			break;
		}
		system("cls");
	} while (opcion != 0);
}

void Funciones::DibujarMenu()
{
	rlutil::setBackgroundColor(rlutil::BLACK);
	rlutil::setColor(rlutil::WHITE);

	cout << "         ______   ___  ___ ________ ______" << endl;
	cout << "       /  ___  \\ /  / /  //__   __//  __  \\" << endl;
	cout << "      /  /  /  //  / /  /   /  /  /  / /  /" << endl;
	cout << "     /  /__/  //  / /  /   /  /  /  / /  /              _" << endl;
	cout << "    /  __    //  /_/  /   /  /  /  /_/  /              / /" << endl;
	cout << "   /__/  /__/ \\______/   /__/   \\_____ /              /_/" << endl;

	cout << "        ________  ______  ______    ________  ___  ______    ___    ___" << endl;
	cout << "       /  _____/ / ____/ /  __  \\  /__   __/ /  / /  __  \\  /   |  /  /" << endl;
	cout << "      / / ___   / /___   \\  \\ \\__\\   /  /   /  / /  / /  / /    | /  /" << endl;
	cout << "     / / /_  / / ____/___ \\  \\      /  /   /  / /  / /  / /  /| |/  /" << endl;
	cout << "    / /_ _/ / / /____ \\  \\_/  /    /  /   /  / /  /_/  / /  / |    /" << endl;
	cout << "   /_______/ /______/  \\_____/    /__/   /__/  \\______/ /__/  |___/" << endl;

	rlutil::locate(14, 16);
	cout << "1 _ AUTOS" << endl;
	rlutil::locate(14, 17);
	cout << "2 _ EMPLEADOS" << endl;
	rlutil::locate(14, 18);
	cout << "3 _ ALQUILERES" << endl;

	rlutil::locate(32, 16);
	cout << "4 _ CLIENTES" << endl;
	rlutil::locate(32, 17);
	cout << "5 _ REPORTES" << endl;
	rlutil::locate(32, 18);
	cout << "6 _ CONFIGURACIONES" << endl;

	rlutil::locate(14, 20);
	cout << "0 _ SALIR" << endl;

	rlutil::locate(16, 22);
	cout << "SELECCI" << char(224) << "N: " << endl;

	rlutil::locate(9, 14);
	cout << char(201);
	rlutil::locate(55, 14);
	cout << char(187);

	rlutil::locate(9, 24);
	cout << char(200);
	rlutil::locate(55, 24);
	cout << char(188);

	for (int i = 0; i < 45; i++)
	{
		rlutil::locate(10 + i, 14);
		cout << char(205);
		rlutil::locate(10 + i, 24);
		cout << char(205);
	}

	for (int i = 0; i < 9; i++)
	{
		rlutil::locate(9, 15 + i);
		cout << char(186);
		rlutil::locate(55, 15 + i);
		cout << char(186);
	}
}

bool Funciones::esDecimal(string s)
{
	int cantidadDePuntos = 0;
	for (int i = 0; i < s.length(); i++)
	{
		if (s[i] == char(46))
		{
			cantidadDePuntos++;
		}
		if (cantidadDePuntos > 1)
			return false;
		if (s[i] != char(46) && !isdigit(s[i]))
			return false;
	}
	return true;
}

bool Funciones::esNumero(string s)
{
	for (int i = 0; i < s.length(); i++)
	{
		if (!isdigit(s[i]))
			return false;
	}
	return true;
}

int Funciones::inputNumero(int x, int y, int b)
{
	string s = "";
	do
	{
		rlutil::locate(x, y);
		for (int i = 0; i < b; i++)
		{
			cout << " ";
		}
		rlutil::locate(x, y);
		getline(cin, s);
	} while (s.length() == 0 || !Funciones().esNumero(s));
	return stoi(s);
}

float Funciones::inputDecimal(int x, int y, int b)
{
	string s = "";
	do
	{
		rlutil::locate(x, y);
		for (int i = 0; i < b; i++)
		{
			cout << " ";
		}
		rlutil::locate(x, y);
		getline(cin, s);
	} while (s.length() == 0 || !Funciones().esDecimal(s));
	return stof(s);
}