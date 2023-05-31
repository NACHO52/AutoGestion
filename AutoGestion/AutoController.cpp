#include "AutoController.h"
#include <iostream>
#include "rlutil.h"
#include <string>
#include "AutoArchivo.h"

using namespace std;

void AutoController::mostrarMenu()
{
	int opcion;
	do {
		rlutil::cls();

		dibujarMenu();

		rlutil::locate(34, 14);
		cin >> opcion;

		switch (opcion)
		{
		case 1:
			crear();
			break;
		case 2:
			editar();
			break;
		case 3:
			listar();
			break;
		case 4:
			eliminar();
			break;
		case 0:
			break;
		default:
			rlutil::setColor(rlutil::LIGHTRED);
			rlutil::locate(22, 16);
			cout << "OPCI" << char(224) << "N INCORRECTA" << endl;
			rlutil::setColor(rlutil::WHITE);
			rlutil::anykey();
			break;
		}

	} while (opcion != 0);
}

void AutoController::dibujarMenu() {

	rlutil::locate(29, 2);
	cout << "AUTOS" << endl;

	rlutil::locate(24, 6);
	cout << "1 _ CREAR" << endl;
	rlutil::locate(24, 7);
	cout << "2 _ EDITAR" << endl;
	rlutil::locate(24, 8);
	cout << "3 _ LISTAR TODOS" << endl;
	rlutil::locate(24, 9);
	cout << "4 _ ELIMINAR" << endl;
	rlutil::locate(24, 11);
	cout << "0 _ VOLVER" << endl;

	rlutil::locate(24, 14);
	cout << "OPCI" << char(224) << "N: " << endl;

	rlutil::locate(15, 4);
	cout << char(201);

	rlutil::locate(47, 4);
	cout << char(187);

	rlutil::locate(15, 17);
	cout << char(200);

	rlutil::locate(47, 17);
	cout << char(188);

	for (int i = 0; i < 31; i++)
	{
		rlutil::locate(16 + i, 4);
		cout << char(205);
		rlutil::locate(16 + i, 17);
		cout << char(205);
	}
	for (int i = 0; i < 12; i++)
	{
		rlutil::locate(15, 5 + i);
		cout << char(186);
		rlutil::locate(47, 5 + i);
		cout << char(186);
	}
}

void AutoController::crear() {
	rlutil::cls();
	string patente, marca, modelo;
	int anio;

	rlutil::locate(37, 2);
	cout << "CREAR AUTO";


	rlutil::locate(11, 4);
	cout << "PATENTE: ";

	rlutil::locate(11, 6);
	cout << "MARCA: ";

	rlutil::locate(11, 8);
	cout << "MODELO: ";

	rlutil::locate(11, 10);
	cout << "A" << char(165) << "O: ";

	rlutil::locate(20, 4);
	cin.ignore();
	getline(cin, patente);
	rlutil::locate(20, 6);
	//cin.ignore();
	getline(cin, marca);
	rlutil::locate(20, 8);
	//cin.ignore();
	getline(cin, modelo);
	rlutil::locate(20, 10);
	cin >> anio;

	int opcion;
	do {
		rlutil::locate(12, 17);
		cout << "                                                                        ";

		rlutil::locate(12, 13);
		cout << "                                                                        ";
		rlutil::locate(12, 13);
		cout << "1 _ GUARDAR";
		rlutil::locate(12, 14);
		cout << "                                                                        ";
		rlutil::locate(12, 14);
		cout << "9 _ CANCELAR/VOLVER";
		rlutil::locate(12, 15);
		cout << "                                                                        ";


		rlutil::locate(12, 16);
		cout << "SELECCI" << char(224) << "N: " << endl;
		rlutil::locate(22, 16);
		cout << "                                                                                         ";
		rlutil::locate(22, 16);
		cin >> opcion;

		AutoArchivo archivo;
		int cantArchivos = 0;
		Auto obj;
		bool guardo;
		switch (opcion)
		{
		case 1:
			cantArchivos = archivo.getCantidadRegistros();
			obj.setMarca(marca);
			obj.setModelo(modelo);
			obj.setPatente(patente);
			obj.setEstado(AutoEstado::Disponible);
			obj.setAnio(anio);
			guardo = archivo.guardar(obj);
			if (guardo)
			{
				rlutil::locate(20, 17);
				cout << "                                                                        ";
				rlutil::locate(20, 17);
				rlutil::setColor(rlutil::LIGHTGREEN);
				cout << "GUARDADO EXITOSO" << endl;
				rlutil::setColor(rlutil::WHITE);
				rlutil::locate(10, 20);
				system("pause");
			}
			else {
				rlutil::locate(12, 17);
				cout << "                                                                        ";
				rlutil::locate(12, 17);
				rlutil::setColor(rlutil::LIGHTRED);
				cout << "HA OCURRIDO UN ERROR AL GUARDAR EL REGISTRO" << endl;
				rlutil::setColor(rlutil::WHITE);
				rlutil::anykey();
			}
			opcion = 9;
			break;
		case 9:
			break;
		default:
			rlutil::setColor(rlutil::LIGHTRED);
			/*rlutil::locate(12, 17);
			cout << "                                                                        ";*/
			rlutil::locate(12, 17);
			cout << "OPCION INCORRECTA" << endl;
			rlutil::setColor(rlutil::WHITE);
			rlutil::anykey();
		}

	} while (opcion != 9);

}

void AutoController::editar()
{
	rlutil::cls();
	rlutil::locate(37, 2);
	cout << "EDITAR AUTO";


	Auto obj;
	AutoArchivo archivo;
	int id;
	rlutil::locate(11, 3);
	cout << "INGRESE EL ID: ";
	cin >> id;

	obj = archivo.buscar(id);
	if (obj.getId() > 0)
	{
		if (obj.getEliminado()) {
			rlutil::locate(2, 8);
			cout << "El registro con Id " << id << " fu" << char(130) << " eliminado." << endl;
			rlutil::locate(2, 16);
			system("pause");
			return;
		}
		mostrarRegistro(obj);
		cout << endl;

		int nuevoEstado;

		rlutil::locate(11, 12);
		cout << "1 _ DISPONIBLE";
		rlutil::locate(11, 13);
		cout << "2 _ FUERA DE SERVICIO";
		rlutil::locate(11, 15);
		cout << "9 _ CANCELAR/VOLVER";


		do
		{
			rlutil::locate(23, 19);
			cout << "                   ";
			rlutil::locate(11, 17);
			cout << "                                                       ";
			rlutil::locate(11, 17);
			cout << "NUEVO ESTADO: ";
			cin >> nuevoEstado;
			if (nuevoEstado == 1 || nuevoEstado == 2)
			{
				obj.setEstado((AutoEstado)nuevoEstado);
				archivo.guardar(obj);
				rlutil::setColor(rlutil::LIGHTGREEN);

				rlutil::locate(23, 19);
				cout << "GUARDADO EXITOSO";
				rlutil::setColor(rlutil::WHITE);
				rlutil::locate(2, 21);
				system("pause");
				break;
			}
			else if (nuevoEstado != 9)
			{
				rlutil::locate(23, 19);
				rlutil::setColor(rlutil::LIGHTRED);
				cout << "ESTADO INCORRECTO";
				rlutil::setColor(rlutil::WHITE);
				rlutil::anykey();
			}

		} while (nuevoEstado != 9);

	}
	else
	{
		rlutil::locate(2, 8);
		cout << "El registro con Id " << id << ", no existe." << endl;
		rlutil::locate(2, 21);
		system("pause");
	}

}

void AutoController::listaHeader() {

	rlutil::locate(3, 2);
	cout << "ID";
	rlutil::locate(9, 2);
	cout << "PATENTE";
	rlutil::locate(21, 2);
	cout << "MARCA";
	rlutil::locate(39, 2);
	cout << "MODELO";
	rlutil::locate(53, 2);
	cout << "A" << char(165) << "O";
	rlutil::locate(60, 2);
	cout << "ESTADO";

	rlutil::locate(1, 1);
	cout << char(218);
	rlutil::locate(1, 3);
	cout << char(192);
	for (int i = 0; i < 77; i++)
	{
		rlutil::locate(2 + i, 1);
		cout << char(196);
		rlutil::locate(2 + i, 3);
		cout << char(196);
	}
	rlutil::locate(78, 1);
	cout << char(191);
	rlutil::locate(78, 3);
	cout << char(217);

	rlutil::locate(1, 2);
	cout << char(179);
	rlutil::locate(7, 2);
	cout << char(179);
	rlutil::locate(18, 2);
	cout << char(179);
	rlutil::locate(36, 2);
	cout << char(179);
	rlutil::locate(51, 2);
	cout << char(179);
	rlutil::locate(57, 2);
	cout << char(179);
	rlutil::locate(78, 2);
	cout << char(179);


	rlutil::locate(7, 1);
	cout << char(194);
	rlutil::locate(7, 3);
	cout << char(193);

	rlutil::locate(18, 1);
	cout << char(194);
	rlutil::locate(18, 3);
	cout << char(193);

	rlutil::locate(36, 1);
	cout << char(194);
	rlutil::locate(36, 3);
	cout << char(193);

	rlutil::locate(51, 1);
	cout << char(194);
	rlutil::locate(51, 3);
	cout << char(193);

	rlutil::locate(57, 1);
	cout << char(194);
	rlutil::locate(57, 3);
	cout << char(193);
}

void AutoController::listar()
{
	rlutil::cls();
	listaHeader();

	AutoArchivo archivo;
	int registrosImpresos = 0;
	int cant = archivo.getCantidadRegistros();
	if (cant == 0)
	{
		imprimirNoHayRegistros();
	}
	else
	{
		for (int j = 1; j < cant; j++)
		{
			Auto obj;
			obj = archivo.buscar(j);
			if (obj.getId() > 0 && obj.getEliminado() == 1)
			{
				continue;
			}

			rlutil::locate(1, 3 + registrosImpresos * 2);
			cout << char(195);

			rlutil::locate(1, 4 + registrosImpresos * 2);
			cout << char(179);
			rlutil::locate(78, 4 + registrosImpresos * 2);
			cout << char(179);

			rlutil::locate(7, 3 + registrosImpresos * 2);
			cout << char(197);
			rlutil::locate(18, 3 + registrosImpresos * 2);
			cout << char(197);
			rlutil::locate(36, 3 + registrosImpresos * 2);
			cout << char(197);
			rlutil::locate(51, 3 + registrosImpresos * 2);
			cout << char(197);
			rlutil::locate(57, 3 + registrosImpresos * 2);
			cout << char(197);

			rlutil::locate(78, 3 + registrosImpresos * 2);
			cout << char(180);

			switch (obj.getEstado())
			{
			case AutoEstado::Disponible:
				rlutil::setColor(rlutil::LIGHTGREEN);
				break;
			case AutoEstado::EnUso:
				rlutil::setColor(rlutil::YELLOW);
				break;
			case AutoEstado::FueraDeServicio:
				rlutil::setColor(rlutil::LIGHTRED);
				break;
			default:
				break;
			}

			rlutil::locate(3, 4 + registrosImpresos * 2);
			cout << obj.getId();
			rlutil::locate(9, 4 + registrosImpresos * 2);
			cout << obj.getPatente();
			rlutil::locate(21, 4 + registrosImpresos * 2);
			cout << obj.getMarca();
			rlutil::locate(39, 4 + registrosImpresos * 2);
			cout << obj.getModelo();
			rlutil::locate(53, 4 + registrosImpresos * 2);
			cout << obj.getAnio();
			rlutil::locate(60, 4 + registrosImpresos * 2);
			cout << obj.getEstadoStr();
			rlutil::setColor(rlutil::WHITE);

			rlutil::locate(7, 4 + registrosImpresos * 2);
			cout << char(179);
			rlutil::locate(18, 4 + registrosImpresos * 2);
			cout << char(179);
			rlutil::locate(36, 4 + registrosImpresos * 2);
			cout << char(179);
			rlutil::locate(51, 4 + registrosImpresos * 2);
			cout << char(179);
			rlutil::locate(57, 4 + registrosImpresos * 2);
			cout << char(179);

			rlutil::locate(1, 5 + registrosImpresos * 2);
			cout << char(192);
			rlutil::locate(78, 5 + registrosImpresos * 2);
			cout << char(217);
			for (int j = 0; j < 76; j++)
			{
				rlutil::locate(2 + j, 5 + registrosImpresos * 2);
				cout << char(196);
			}
			rlutil::locate(7, 5 + registrosImpresos * 2);
			cout << char(193);
			rlutil::locate(18, 5 + registrosImpresos * 2);
			cout << char(193);
			rlutil::locate(36, 5 + registrosImpresos * 2);
			cout << char(193);
			rlutil::locate(51, 5 + registrosImpresos * 2);
			cout << char(193);
			rlutil::locate(57, 5 + registrosImpresos * 2);
			cout << char(193);
			registrosImpresos++;
		}

		if (registrosImpresos == 0) {
			imprimirNoHayRegistros();
		}
	}

	rlutil::locate(1, registrosImpresos * 2 + 8);
	cout << endl << endl << endl << system("pause");
}

void AutoController::imprimirNoHayRegistros()
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

void AutoController::mostrarRegistro(Auto obj)
{
	rlutil::locate(5, 5);
	cout << "ID: ";
	rlutil::locate(16, 5);
	cout << obj.getId();

	rlutil::locate(5, 7);
	cout << "PATENTE: ";
	rlutil::locate(16, 7);
	cout << obj.getPatente();

	rlutil::locate(5, 9);
	cout << "MARCA: ";
	rlutil::locate(16, 9);
	cout << obj.getMarca();

	rlutil::locate(45, 5);
	cout << "MODELO: ";
	rlutil::locate(56, 5);
	cout << obj.getModelo();

	rlutil::locate(45, 7);
	cout << "A" << char(165) << "O: ";
	rlutil::locate(56, 7);
	cout << obj.getAnio();

	rlutil::locate(45, 9);
	cout << "ESTADO: ";
	rlutil::locate(56, 9);
	cout << obj.getEstadoStr();
}

void AutoController::eliminar()
{
	rlutil::cls();
	rlutil::locate(37, 2);
	cout << "ELIMINAR AUTO";

	Auto obj;
	int id;
	AutoArchivo archivo;


	rlutil::locate(11, 3);
	cout << "INGRESE EL ID: ";
	cin >> id;
	cout << endl;
	int opcion;
	obj = archivo.buscar(id);
	if (obj.getId() > 0 && !obj.getEliminado())
	{

		mostrarRegistro(obj);

		rlutil::locate(11, 15);
		cout << char(168) << "Est" << char(160) << " seguro que desea eliminar el registro?";
		rlutil::locate(11, 17);
		cout << "1 _ ELIMINAR";
		rlutil::locate(11, 18);
		cout << "9 _ CANCELAR/VOLVER";
		do
		{
			rlutil::locate(23, 23);
			cout << "                                                                        ";
			rlutil::locate(23, 21);
			cout << "                                                                        ";
			rlutil::locate(11, 21);
			cout << "SELECCI" << char(224) << "N: ";
			rlutil::locate(23, 21);
			cin >> opcion;

			switch (opcion)
			{
			case 1:
				obj.setEliminado(true);
				archivo.guardar(obj);
				rlutil::locate(17, 23);
				rlutil::setColor(rlutil::LIGHTGREEN);
				cout << "El auto con Id " << id << ", fu" << char(130) << " eliminado exitosamente." << endl;
				rlutil::setColor(rlutil::WHITE);
				cout << endl << endl << system("pause");
				opcion = 9;
				break;
			case 9:
				break;
			default:
				rlutil::setColor(rlutil::LIGHTRED);
				rlutil::locate(23, 23);
				cout << "OPCI" << char(224) << "N INCORRECTA" << endl;
				rlutil::setColor(rlutil::WHITE);
				rlutil::anykey();
				break;
			}

		} while (opcion != 9);
	}
	else
	{
		cout << "El registro con Id " << id << ", no existe." << endl;
		rlutil::locate(1, 20);
		cout << system("pause");
	}

}
