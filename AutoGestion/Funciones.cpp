#include "Funciones.h"
#include "rlutil.h"
#include <iostream>
#include "AutoController.h"

using namespace std;


void Funciones::MenuPrincipal()
{
	int opcion;
	do
	{
		rlutil::cls();
		DibujarMenu();
		rlutil::locate(25, 22);
		cin >> opcion;

		switch (opcion)
		{
		case 1:
			rlutil::cls();
			AutoController().mostrarMenu();
			rlutil::cls();
			break;
		case 2:
			system("cls");
			cout << "EMPLEADOS" << endl;
			system("pause");
			system("cls");
			break;
		case 3:
			system("cls");
			cout << "ALQUILERES" << endl;
			system("pause");
			system("cls");
			break;
		case 4:
			system("cls");
			cout << "CLIENTES" << endl;
			system("pause");
			system("cls");
			break;
		case 5:
			system("cls");
			cout << "REPORTES" << endl;
			system("pause");
			system("cls");
			break;
		case 6:
			system("cls");
			cout << "CONFIGURACIONES" << endl;
			system("pause");
			system("cls");
			break;
		case 0:
			break;
		default:
			rlutil::setColor(rlutil::LIGHTRED);
			rlutil::locate(25, 22);
			cout << "OPCI" << char(224) << "N INCORRECTA" << endl;
			rlutil::setColor(rlutil::WHITE);
			rlutil::locate(42, 22);
			rlutil::anykey();
			break;
		}
	} while (opcion != 0);
}

void Funciones::DibujarMenu()
{
	rlutil::setBackgroundColor(rlutil::BLACK);
	rlutil::setColor(rlutil::WHITE);


	cout << "         _____    ___  ___ ________ _____" << endl;
	cout << "       /  ___  \\ /  / /  //__   __//  __  \\" << endl;
	cout << "      /  /  /  //  / /  /   /  /  /  / /  /" << endl;
	cout << "     /  /__/  //  / /  /   /  /  /  / /  /              _" << endl;
	cout << "    /  __    //  /_/  /   /  /  /  /_/  /              / /" << endl;
	cout << "   /__/  /__/ \\______/   /__/   \\_____ /              /_/" << endl;

	cout << "        _______   ______  _____     ________  ___  _____     ___    ___" << endl;
	cout << "       /  _____/ / ____/ /  __  \\  /__   __/ /  / /  __  \\  /   |  /  /" << endl;
	cout << "      / / ___   / /___   \\  \\ \\__\\   /  /   /  / /  / /  / /    | /  /" << endl;
	cout << "     / / /_  / / ____/___ \\  \\      /  /   /  / /  / /  / /  /| |/  /" << endl;
	cout << "    / /_ _/ / / /____ \\  \\_/  /    /  /   /  / /  /_/  / /  / |    /" << endl;
	cout << "   /_______/ /______/  \\_____/    /__/   /__/  \\______/ /__/  |___/" << endl;


	rlutil::locate(12, 16);
	cout << "1 _ AUTOS" << endl;
	rlutil::locate(12, 17);
	cout << "2 _ EMPLEADOS" << endl;
	rlutil::locate(12, 18);
	cout << "3 _ ALQUILERES" << endl;

	rlutil::locate(30, 16);
	cout << "4 _ CLIENTES" << endl;
	rlutil::locate(30, 17);
	cout << "5 _ REPORTES" << endl;
	rlutil::locate(30, 18);
	cout << "6 _ CONFIGURACIONES" << endl;

	rlutil::locate(14, 20);
	cout << "0 _ SALIR" << endl;

	rlutil::locate(14, 22);
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
		rlutil::locate(10+i, 14);
		cout << char(205);
		rlutil::locate(10+i, 24);
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
