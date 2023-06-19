#include "AutoController.h"
#include <iostream>
#include "rlutil.h"
#include <string>
#include "AutoArchivo.h"
#include <iomanip>
#include "AlquilerController.h"
#include "AlquilerArchivo.h"

using namespace std;

void AutoController::mostrarMenu()
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
			crear();
			break;
		case 2:
			editar();
			break;
		case 3:
			listar();
			break;
		case 4:
			listarPorEstado();
			break;
		case 5:
			buscarPorId();
			break;
		case 6:
			eliminar();
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
	cout << "4 _ LISTAR POR ESTADO" << endl;
	rlutil::locate(24, 10);
	cout << "5 _ BUSCAR POR ID" << endl;
	rlutil::locate(24, 11);
	cout << "6 _ ELIMINAR" << endl;
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
	getline(cin, marca);
	rlutil::locate(20, 8);
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
		cout << "0 _ CANCELAR/VOLVER";
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
			opcion = 0;
			break;
		case 0:
			break;
		default:
			rlutil::setColor(rlutil::LIGHTRED);
			/*rlutil::locate(12, 17);
			cout << "                                                                        ";*/
			rlutil::locate(12, 17);
			cout << "OPCI" << char(224) << "N INCORRECTA" << endl;
			rlutil::setColor(rlutil::WHITE);
			rlutil::anykey();
		}

	} while (opcion != 0);

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
		int registrosImpresos = historialAlquiler(0, 11, obj);

		if (registrosImpresos == 0)
		{

			for (int i = 0; i < 80; i++)
			{
				for (int j = 11; j < 19; j++)
				{
					rlutil::locate(i, j);
					cout << " ";
				}
			}
		}

		int nuevoEstado;

		if (registrosImpresos == 0)
		{
			rlutil::locate(10, registrosImpresos * 2 + 3 + 12);
			cout << "1 _ DISPONIBLE";
			rlutil::locate(10, registrosImpresos * 2 + 3 + 13);
			cout << "2 _ FUERA DE SERVICIO";
		}
		rlutil::locate(10, registrosImpresos * 2 + 3 + 14);
		cout << "0 _ CANCELAR/VOLVER";


		do
		{
			rlutil::locate(24, registrosImpresos * 2 + 3 + 16);
			cout << "                                                       ";
			rlutil::locate(10, registrosImpresos * 2 + 3 + 16);
			cout << "NUEVO ESTADO: ";
			rlutil::locate(24, registrosImpresos * 2 + 3 + 16);
			cin >> nuevoEstado;
			if ((nuevoEstado == 1 || nuevoEstado == 2) && registrosImpresos == 0)
			{
				obj.setEstado((AutoEstado)nuevoEstado);
				archivo.guardar(obj);
				rlutil::setColor(rlutil::LIGHTGREEN);

				rlutil::locate(15, registrosImpresos * 2 + 3 + 17);
				cout << "GUARDADO EXITOSO";
				rlutil::setColor(rlutil::WHITE);
				rlutil::locate(24, registrosImpresos * 2 + 3 + 19);
				system("pause");
				break;
			}
			else if (nuevoEstado != 0)
			{
				rlutil::locate(24, registrosImpresos * 2 + 3 + 16);
				rlutil::setColor(rlutil::LIGHTRED);
				cout << "ESTADO INCORRECTO";
				rlutil::setColor(rlutil::WHITE);
				rlutil::anykey();
			}

		} while (nuevoEstado != 0);

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
	rlutil::locate(55, 2);
	cout << "A" << char(165) << "O";
	rlutil::locate(62, 2);
	cout << "ESTADO";

	rlutil::locate(1, 1);
	cout << char(218);
	rlutil::locate(1, 3);
	cout << char(192);
	for (int i = 0; i < 78; i++)
	{
		rlutil::locate(2 + i, 1);
		cout << char(196);
		rlutil::locate(2 + i, 3);
		cout << char(196);
	}
	rlutil::locate(79, 1);
	cout << char(191);
	rlutil::locate(79, 3);
	cout << char(217);

	rlutil::locate(1, 2);
	cout << char(179);
	rlutil::locate(7, 2);
	cout << char(179);
	rlutil::locate(18, 2);
	cout << char(179);
	rlutil::locate(36, 2);
	cout << char(179);
	rlutil::locate(53, 2);
	cout << char(179);
	rlutil::locate(59, 2);
	cout << char(179);
	rlutil::locate(79, 2);
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

	rlutil::locate(53, 1);
	cout << char(194);
	rlutil::locate(53, 3);
	cout << char(193);

	rlutil::locate(59, 1);
	cout << char(194);
	rlutil::locate(59, 3);
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
		for (int j = 1; j <= cant; j++)
		{
			Auto obj;
			obj = archivo.buscar(j);
			//TODO: sacar la primer condicion y probar
			if (obj.getId() > 0 && obj.getEliminado() == 1)
			{
				continue;
			}

			DibujarFila(registrosImpresos, obj);
			registrosImpresos++;
		}

		if (registrosImpresos == 0) {
			imprimirNoHayRegistros();
		}
	}

	rlutil::locate(1, registrosImpresos * 2 + 8);
	system("pause");
}

void AutoController::DibujarFila(int corrimiento, Auto& obj)
{
	rlutil::locate(1, 3 + corrimiento * 2);
	cout << char(195);

	rlutil::locate(1, 4 + corrimiento * 2);
	cout << char(179);
	rlutil::locate(79, 4 + corrimiento * 2);
	cout << char(179);

	rlutil::locate(7, 3 + corrimiento * 2);
	cout << char(197);
	rlutil::locate(18, 3 + corrimiento * 2);
	cout << char(197);
	rlutil::locate(36, 3 + corrimiento * 2);
	cout << char(197);
	rlutil::locate(53, 3 + corrimiento * 2);
	cout << char(197);
	rlutil::locate(59, 3 + corrimiento * 2);
	cout << char(197);

	rlutil::locate(79, 3 + corrimiento * 2);
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

	rlutil::locate(2, 4 + corrimiento * 2);
	cout << setw(4) << obj.getId();
	rlutil::locate(8, 4 + corrimiento * 2);
	cout << setw(9) << obj.getPatente();
	rlutil::locate(19, 4 + corrimiento * 2);
	cout << setw(16) << obj.getMarca();
	rlutil::locate(37, 4 + corrimiento * 2);
	cout << setw(15) << obj.getModelo();
	rlutil::locate(54, 4 + corrimiento * 2);
	cout << setw(5) << obj.getAnio();
	rlutil::locate(59, 4 + corrimiento * 2);
	cout << setw(19) << obj.getEstadoStr();
	rlutil::setColor(rlutil::WHITE);

	rlutil::locate(7, 4 + corrimiento * 2);
	cout << char(179);
	rlutil::locate(18, 4 + corrimiento * 2);
	cout << char(179);
	rlutil::locate(36, 4 + corrimiento * 2);
	cout << char(179);
	rlutil::locate(53, 4 + corrimiento * 2);
	cout << char(179);
	rlutil::locate(59, 4 + corrimiento * 2);
	cout << char(179);

	rlutil::locate(1, 5 + corrimiento * 2);
	cout << char(192);
	rlutil::locate(79, 5 + corrimiento * 2);
	cout << char(217);
	for (int j = 0; j < 77; j++)
	{
		rlutil::locate(2 + j, 5 + corrimiento * 2);
		cout << char(196);
	}
	rlutil::locate(7, 5 + corrimiento * 2);
	cout << char(193);
	rlutil::locate(18, 5 + corrimiento * 2);
	cout << char(193);
	rlutil::locate(36, 5 + corrimiento * 2);
	cout << char(193);
	rlutil::locate(53, 5 + corrimiento * 2);
	cout << char(193);
	rlutil::locate(59, 5 + corrimiento * 2);
	cout << char(193);
}

void AutoController::listarPorEstado()
{
	rlutil::cls();
	listaHeader();
	
	AutoArchivo archivo;
	int registrosDisponibles = 0;
	int cant = archivo.getCantidadRegistros();
	if (cant == 0)
	{
		imprimirNoHayRegistros();
	}
	else
	{

		for (int j = 1; j <= cant; j++)
		{
			Auto obj;
			obj = archivo.buscar(j);
			if (obj.getEliminado() == 1)
			{
				continue;
			}
			else if (obj.getEstado() == AutoEstado::Disponible) 
			{
				DibujarFila(registrosDisponibles, obj);
				registrosDisponibles++;
			}
		}

		for (int j = 1; j <= cant; j++)
		{
			Auto obj;
			obj = archivo.buscar(j);
			if (obj.getEliminado() == 1)
			{
				continue;
			}
			if (obj.getEstado() == AutoEstado::EnUso)
			{

				DibujarFila(registrosDisponibles, obj);
				registrosDisponibles++;
			}
		}


		for (int j = 1; j <= cant; j++)
		{
			Auto obj;
			obj = archivo.buscar(j);
			if (obj.getEliminado() == 1)
			{
				continue;
			}
			else if (obj.getEstado() == AutoEstado::FueraDeServicio)
			{
				DibujarFila(registrosDisponibles, obj);
				registrosDisponibles++;
			}
		}

	}

	rlutil::locate(1, registrosDisponibles * 2 + 8);
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
	rlutil::locate(79, 4);
	cout << char(179);
	rlutil::locate(79, 5);
	cout << char(179);
	rlutil::locate(79, 6);
	cout << char(217);

	rlutil::locate(1, 3);
	cout << char(195);

	rlutil::locate(79, 3);
	cout << char(180);
	for (int i = 0; i < 77; i++)
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

int AutoController::historialAlquiler(int x, int y, Auto obj)
{
	rlutil::locate(x+1, y);
	cout << "HISTORIAL DE ALQUILER";

	return AlquilerController().listarPorAuto(x,y,obj.getId());

}

void AutoController::eliminar()
{
	rlutil::cls();
	rlutil::locate(30, 2);
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
		int registrosImpresos = historialAlquiler(0,12, obj);
		if (registrosImpresos > 0)
		{
			rlutil::locate(2, registrosImpresos * 2 + 19);
			rlutil::setColor(rlutil::LIGHTRED);
			cout << "El auto no puede ser eliminado porque posee alquileres asociados." << endl;
			rlutil::setColor(rlutil::WHITE);
			rlutil::locate(2, registrosImpresos * 2 + 20);
			cout << system("pause");
			return;
		}
		else
		{
			for (int i = 0; i < 80; i++)
			{
				for (int j = 11; j < 19; j++)
				{
					rlutil::locate(i, j);
					cout << " ";
				}
			}
		}

		rlutil::locate(11, 14);
		cout << char(168) << "Est" << char(160) << " seguro que desea eliminar el registro?";
		rlutil::locate(11, 15);
		cout << "1 _ ELIMINAR";
		rlutil::locate(11, 16);
		cout << "0 _ CANCELAR/VOLVER";
		do
		{
			rlutil::locate(23, 20);
			cout << "                                                                        ";
			rlutil::locate(11, 20);
			cout << "SELECCI" << char(224) << "N: ";
			rlutil::locate(23, 20);
			cin >> opcion;

			switch (opcion)
			{
			case 1:
				obj.setEliminado(true);
				archivo.guardar(obj);
				rlutil::locate(17, 22);
				rlutil::setColor(rlutil::LIGHTGREEN);
				cout << "El auto con Id " << id << ", fu" << char(130) << " eliminado exitosamente." << endl;
				rlutil::setColor(rlutil::WHITE);
				cout << endl << endl << system("pause");
				opcion = 0;
				break;
			case 0:
				break;
			default:
				rlutil::setColor(rlutil::LIGHTRED);
				rlutil::locate(23, 20);
				cout << "OPCI" << char(224) << "N INCORRECTA" << endl;
				rlutil::setColor(rlutil::WHITE);
				rlutil::locate(23, 20);
				rlutil::anykey();
				break;
			}

		} while (opcion != 0);
	}
	else
	{
		cout << "El registro con Id " << id << ", no existe." << endl;
		rlutil::locate(1, 20);
		cout << system("pause");
	}

}

void AutoController::buscarPorId()
{
	rlutil::cls();
	rlutil::locate(37, 2);
	cout << "BUSCAR AUTO";

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
			cout << "El registro con Id " << id << " no se encuentra en el sistema." << endl;
			rlutil::locate(2, 16);
			system("pause");
			return;
		}
		mostrarRegistro(obj);
		int registrosImpresos = historialAlquiler(0,11, obj);
		cout << endl;
		rlutil::locate(2, registrosImpresos * 2 + 17);
		cout << endl << endl << endl << endl << endl;
		system("pause");
	}
	else
	{
		rlutil::locate(2, 8);
		cout << "El registro con Id " << id << " no se encuentra en el sistema." << endl;
		rlutil::locate(2, 21);
		system("pause");
	}

}

int AutoController::ventanaAutosDisponibles(int x, int y)
{
	AutoArchivo archivo;
	int registrosImpresos = 0;
	int cant = archivo.getCantidadRegistros();
	if (cant == 0) return 0;


	rlutil::locate(x, y);
	cout << char(218);
	rlutil::locate(x + 75, y);
	cout << char(191);


	rlutil::locate(x, y + 1);
	cout << char(179);

	rlutil::locate(x + 6, y + 1);
	cout << char(179);
	rlutil::locate(x + 38, y + 1);
	cout << char(179);
	rlutil::locate(x + 69, y + 1);
	cout << char(179);

	rlutil::locate(x + 75, y + 1);
	cout << char(179);

	for (int i = 1; i < 75; i++)
	{
		rlutil::locate(x + i, y);
		cout << char(196);
		rlutil::locate(x + i, y + 2);
		cout << char(196);
	}

	rlutil::locate(x + 6, y);
	cout << char(194);
	rlutil::locate(x + 38, y);
	cout << char(194);
	rlutil::locate(x + 69, y);
	cout << char(194);

	rlutil::locate(x + 2, y + 1);
	cout << "ID";
	rlutil::locate(x + 8, y + 1);
	cout << "MARCA";
	rlutil::locate(x + 40, y + 1);
	cout << "MODELO";
	rlutil::locate(x + 71, y + 1);
	cout << "A"<< char(165) << "O";


	for (int i = 1; i <= cant; i++)
	{
		Auto obj;
		obj = archivo.buscar(i);
		if (obj.getEliminado() == 1 || obj.getEstado() != AutoEstado::Disponible)
		{
			continue;
		}

		for (int j = 0; j < 75; j++)
		{
			rlutil::locate(x + j, y + 4 + registrosImpresos *2);
			cout << char(196);
		}

		rlutil::locate(x, y + 4 + registrosImpresos *2);
		cout << char(192);
		rlutil::locate(x + 6, y + 4 + registrosImpresos *2);
		cout << char(193);
		rlutil::locate(x + 38, y + 4 + registrosImpresos *2);
		cout << char(193);
		rlutil::locate(x + 69, y + 4 + registrosImpresos *2);
		cout << char(193);
		rlutil::locate(x + 75, y + 4 + registrosImpresos *2);
		cout << char(217);

		rlutil::locate(x, y + 2 + registrosImpresos * 2);
		cout << char(195);
		rlutil::locate(x + 6, y + 2 + registrosImpresos * 2);
		cout << char(197);
		rlutil::locate(x + 38, y + 2 + registrosImpresos * 2);
		cout << char(197);
		rlutil::locate(x + 69, y + 2 + registrosImpresos * 2);
		cout << char(197);
		rlutil::locate(x + 75, y + 2 + registrosImpresos * 2);
		cout << char(180);

		rlutil::locate(x, y + 3 + registrosImpresos * 2);
		cout << char(179);
		rlutil::locate(x+6, y + 3 + registrosImpresos * 2);
		cout << char(179);
		rlutil::locate(x + 38, y + 3 + registrosImpresos * 2);
		cout << char(179);
		rlutil::locate(x + 69, y + 3 + registrosImpresos * 2);
		cout << char(179);
		rlutil::locate(x + 75, y + 3 + registrosImpresos * 2);
		cout << char(179);

		rlutil::locate(x + 1, y + 3 + registrosImpresos * 2);
		cout << setw(4) << obj.getId();

		rlutil::locate(x + 7, y + 3 + registrosImpresos * 2);
		cout << setw(30) << obj.getMarca();

		rlutil::locate(x + 39, y + 3 + registrosImpresos * 2);
		cout << setw(29) << obj.getModelo();

		rlutil::locate(x + 70, y + 3 + registrosImpresos * 2);
		cout << setw(5) << obj.getAnio();


		registrosImpresos++;
	}
	return registrosImpresos;
}

int AutoController::getAutosDisponibles()
{
	AutoArchivo archivo;
	int reg = 0;
	int cant = archivo.getCantidadRegistros();
	if (cant == 0) return 0;

	for (int i = 1; i <= cant; i++)
	{
		Auto obj;
		obj = archivo.buscar(i);
		if (obj.getEliminado() == 1 || obj.getEstado() != AutoEstado::Disponible)
		{
			continue;
		}
		reg++;
	}
	return reg;
}

void AutoController::limpiarVentanaAutosDisponibles(int x, int y, int registros) 
{
	rlutil::locate(x, y);
	for (int i = 0; i < (3 + registros * 2); i++)
	{
		for (int j = 0; j < 76; j++)
		{
			rlutil::locate(x + j, y + i);
			cout << " ";
		}
	}
}
//1 =>  5 = 1 + 4 = 1 + 3 + 1 = 3 +  2 = 3 + 2 * 1 
//2 =>  7 = 2 + 5 = 2 + 3 + 2 = 3 +  4 = 3 + 2 * 2
//3 =>  9 = 3 + 6 = 3 + 3 + 3 = 3 +  6 = 3 + 2 * 3
//4 => 11 = 4 + 7 = 4 + 3 + 4 = 3 +  8 = 3 + 2 * 4
//5 => 13 = 5 + 8 = 5 + 3 + 5 = 3 + 10 = 3 + 2 * 5
