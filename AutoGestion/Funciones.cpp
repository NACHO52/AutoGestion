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
		rlutil::locate(39, 22);
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
		case 0:
			break;
		default:
			rlutil::setColor(rlutil::LIGHTRED);
			rlutil::locate(26, 23);
			cout << "OPCI" << char(224) << "N INCORRECTA" << endl;
			rlutil::setColor(rlutil::WHITE);
			rlutil::anykey();
			break;
		}
	} while (opcion != 0);
}

void Funciones::DibujarMenu()
{
	rlutil::setBackgroundColor(rlutil::BLACK);
	rlutil::setColor(rlutil::WHITE);


	cout << "      _____    ___  ___ ________ _____" << endl;
	cout << "    /  ___  \\ /  / /  //__   __//  __  \\" << endl;
	cout << "   /  /  /  //  / /  /   /  /  /  / /  /" << endl;
	cout << "  /  /__/  //  / /  /   /  /  /  / /  /              _" << endl;
	cout << " /  __    //  /_/  /   /  /  /  /_/  /              / /" << endl;
	cout << "/__/  /__/ \\______/   /__/   \\_____ /              /_/" << endl;

	cout << "     _______   ______  _____     ________  ___  _____     ___    ___" << endl;
	cout << "    /  _____/ / ____/ /  __  \\  /__   __/ /  / /  __  \\  /   |  /  /" << endl;
	cout << "   / / ___   / /___   \\  \\ \\__\\   /  /   /  / /  / /  / /    | /  /" << endl;
	cout << "  / / /_  / / ____/___ \\  \\      /  /   /  / /  / /  / /  /| |/  /" << endl;
	cout << " / /_ _/ / / /____ \\  \\_/  /    /  /   /  / /  /_/  / /  / |    /" << endl;
	cout << "/_______/ /______/  \\_____/    /__/   /__/  \\______/ /__/  |___/" << endl;


	rlutil::locate(27, 16);
	cout << "1  _  AUTOS" << endl;
	rlutil::locate(27, 17);
	cout << "2  _  EMPLEADOS" << endl;
	rlutil::locate(27, 18);
	cout << "3  _  ALQUILERES" << endl;
	rlutil::locate(27, 20);
	cout << "0  _  SALIR" << endl;

	rlutil::locate(26, 22);
	cout << "SELECCI" << char(224) << "NE: " << endl;

	rlutil::locate(21, 14);
	cout << char(201);
	for (int i = 0; i < 24; i++)
	{
		cout << char(205);
	}
	cout << char(187);

	rlutil::locate(21, 24);
	cout << char(200);
	for (int i = 0; i < 24; i++)
	{
		cout << char(205);
	}
	cout << char(188);

	for (int i = 0; i < 9; i++)
	{
		rlutil::locate(21, 15 + i);
		cout << char(186);
		rlutil::locate(46, 15 + i);
		cout << char(186);
	}

}
