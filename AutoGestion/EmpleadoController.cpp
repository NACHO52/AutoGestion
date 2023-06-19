#include "EmpleadoController.h"
#include <iostream>
#include "rlutil.h"
#include <string>
#include "EmpleadoArchivo.h"
#include <iomanip>

using namespace std;

void EmpleadoController::mostrarMenu()
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

void EmpleadoController::dibujarMenu() {

	rlutil::locate(29, 2);
	cout << "EMLPEADOS" << endl;

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

void EmpleadoController::crear() {
	rlutil::cls();
	string nombre, apellido, email;
	float sueldo;

	rlutil::locate(37, 2);
	cout << "CREAR EMLPEADO";


	rlutil::locate(11, 4);
	cout << "NOMBRE: ";

	rlutil::locate(11, 6);
	cout << "APELLIDO: ";

	rlutil::locate(11, 8);
	cout << "EMAIL: ";

	rlutil::locate(11, 10);
	cout << "SUELDO: ";

	rlutil::locate(22, 4);
	cin.ignore();
	getline(cin, nombre);
	rlutil::locate(22, 6);
	getline(cin, apellido);
	rlutil::locate(22, 8);
	getline(cin, email);
	rlutil::locate(22, 10);
	cin >> sueldo;

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

		EmpleadoArchivo archivo;
		int cantArchivos = 0;
		Empleado obj;
		bool guardo;
		switch (opcion)
		{
		case 1:
			cantArchivos = archivo.getCantidadRegistros();
			obj.setNombre(nombre);
			obj.setApellido(apellido);
			obj.setMail(email);
			obj.setEstado(EmpleadoEstado::Activo);
			obj.setSueldo(sueldo);
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
			cout << "OPCI"<< char(224) <<"N INCORRECTA" << endl;
			rlutil::setColor(rlutil::WHITE);
			rlutil::anykey();
		}

	} while (opcion != 0);

}

void EmpleadoController::editar()
{
	rlutil::cls();
	rlutil::locate(37, 2);
	cout << "EDITAR EMLPEADO";


	Empleado obj;
	EmpleadoArchivo archivo;
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
		cout << "1 _ ACTIVO";
		rlutil::locate(11, 13);
		cout << "2 _ BAJA";
		rlutil::locate(11, 15);
		cout << "0 _ CANCELAR/VOLVER";


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
				obj.setEstado((EmpleadoEstado)nuevoEstado);
				archivo.guardar(obj);
				rlutil::setColor(rlutil::LIGHTGREEN);

				rlutil::locate(23, 19);
				cout << "GUARDADO EXITOSO";
				rlutil::setColor(rlutil::WHITE);
				rlutil::locate(2, 21);
				system("pause");
				break;
			}
			else if (nuevoEstado != 0)
			{
				rlutil::locate(23, 19);
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
		cout << "El registro con Id " << id << " no existe." << endl;
		rlutil::locate(2, 21);
		system("pause");
	}

}

void EmpleadoController::listaHeader() {

	rlutil::locate(3, 2);
	cout << "ID";
	rlutil::locate(8, 2);
	cout << "NOMBRE";
	rlutil::locate(25, 2);
	cout << "APELLIDO";
	rlutil::locate(43, 2);
	cout << "E-MAIL";
	rlutil::locate(62, 2);
	cout << "SUELDO";
	rlutil::locate(71, 2);
	cout << "ESTADO";

	rlutil::locate(1, 1);
	cout << char(218);
	rlutil::locate(1, 3);
	cout << char(192);
	for (int i = 0; i < 79; i++)
	{
		rlutil::locate(2 + i, 1);
		cout << char(196);
		rlutil::locate(2 + i, 3);
		cout << char(196);
	}
	rlutil::locate(80, 1);
	cout << char(191);
	rlutil::locate(80, 3);
	cout << char(217);

	rlutil::locate(1, 2);
	cout << char(179);
	rlutil::locate(6, 2);
	cout << char(179);
	rlutil::locate(23, 2);
	cout << char(179);
	rlutil::locate(41, 2);
	cout << char(179);
	rlutil::locate(60, 2);
	cout << char(179);
	rlutil::locate(69, 2);
	cout << char(179);
	rlutil::locate(80, 2);
	cout << char(179);


	rlutil::locate(6, 1);
	cout << char(194);
	rlutil::locate(6, 3);
	cout << char(193);

	rlutil::locate(23, 1);
	cout << char(194);
	rlutil::locate(23, 3);
	cout << char(193);

	rlutil::locate(41, 1);
	cout << char(194);
	rlutil::locate(41, 3);
	cout << char(193);

	rlutil::locate(60, 1);
	cout << char(194);
	rlutil::locate(60, 3);
	cout << char(193);

	rlutil::locate(69, 1);
	cout << char(194);
	rlutil::locate(69, 3);
	cout << char(193);
}

void EmpleadoController::listar()
{
	rlutil::cls();
	listaHeader();

	EmpleadoArchivo archivo;
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
			Empleado obj;
			obj = archivo.buscar(j);
			if (obj.getId() > 0 && obj.getEliminado() == 1)
			{
				continue;
			}

			dibujarFila(registrosImpresos, obj);
			registrosImpresos++;
		}

		if (registrosImpresos == 0) {
			imprimirNoHayRegistros();
		}
	}

	rlutil::locate(1, registrosImpresos * 2 + 8);
	cout << endl << endl << endl << system("pause");
}

void EmpleadoController::dibujarFila(int corrimiento, Empleado& obj)
{
	rlutil::locate(1, 3 + corrimiento * 2);
	cout << char(195);

	rlutil::locate(1, 4 + corrimiento * 2);
	cout << char(179);
	rlutil::locate(80, 4 + corrimiento * 2);
	cout << char(179);

	rlutil::locate(6, 3 + corrimiento * 2);
	cout << char(197);
	rlutil::locate(23, 3 + corrimiento * 2);
	cout << char(197);
	rlutil::locate(41, 3 + corrimiento * 2);
	cout << char(197);
	rlutil::locate(60, 3 + corrimiento * 2);
	cout << char(197);
	rlutil::locate(69, 3 + corrimiento * 2);
	cout << char(197);

	rlutil::locate(80, 3 + corrimiento * 2);
	cout << char(180);

	switch (obj.getEstado())
	{
	case EmpleadoEstado::Activo:
		rlutil::setColor(rlutil::LIGHTGREEN);
		break;
	case EmpleadoEstado::Baja:
		rlutil::setColor(rlutil::LIGHTRED);
		break;
	default:
		break;
	}

	rlutil::locate(2, 4 + corrimiento * 2);
	cout << setw(3) << obj.getId();
	rlutil::locate(7, 4 + corrimiento * 2);
	cout << setw(15) << obj.getNombre();
	rlutil::locate(24, 4 + corrimiento * 2);
	cout << setw(16) << obj.getApellido();
	rlutil::locate(42, 4 + corrimiento * 2);
	cout << setw(17) << obj.getMail();
	rlutil::locate(61, 4 + corrimiento * 2);
	cout << setw(7) << obj.getSueldo();
	rlutil::locate(70, 4 + corrimiento * 2);
	cout << setw(9) << obj.getEstadoStr();
	rlutil::setColor(rlutil::WHITE);

	rlutil::locate(6, 4 + corrimiento * 2);
	cout << char(179);
	rlutil::locate(23, 4 + corrimiento * 2);
	cout << char(179);
	rlutil::locate(41, 4 + corrimiento * 2);
	cout << char(179);
	rlutil::locate(60, 4 + corrimiento * 2);
	cout << char(179);
	rlutil::locate(69, 4 + corrimiento * 2);
	cout << char(179);

	rlutil::locate(1, 5 + corrimiento * 2);
	cout << char(192);
	rlutil::locate(80, 5 + corrimiento * 2);
	cout << char(217);
	for (int j = 0; j < 78; j++)
	{
		rlutil::locate(2 + j, 5 + corrimiento * 2);
		cout << char(196);
	}
	rlutil::locate(6, 5 + corrimiento * 2);
	cout << char(193);
	rlutil::locate(23, 5 + corrimiento * 2);
	cout << char(193);
	rlutil::locate(41, 5 + corrimiento * 2);
	cout << char(193);
	rlutil::locate(60, 5 + corrimiento * 2);
	cout << char(193);
	rlutil::locate(69, 5 + corrimiento * 2);
	cout << char(193);
}

void EmpleadoController::listarPorEstado()
{
	rlutil::cls();
	listaHeader();

	EmpleadoArchivo archivo;
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
			Empleado obj;
			obj = archivo.buscar(j);
			if (obj.getEliminado() == 1)
			{
				continue;
			}
			else if (obj.getEstado() == EmpleadoEstado::Activo)
			{
				/*rlutil::locate(1, 3 + registrosDisponibles * 2);
				cout << char(195);
				rlutil::locate(1, 4 + registrosDisponibles * 2);
				cout << char(179);
				rlutil::locate(79, 4 + registrosDisponibles * 2);
				cout << char(179);
				rlutil::locate(6, 3 + registrosDisponibles * 2);
				cout << char(197);
				rlutil::locate(23, 3 + registrosDisponibles * 2);
				cout << char(197);
				rlutil::locate(41, 3 + registrosDisponibles * 2);
				cout << char(197);
				rlutil::locate(60, 3 + registrosDisponibles * 2);
				cout << char(197);
				rlutil::locate(69, 3 + registrosDisponibles * 2);
				cout << char(197);
				rlutil::locate(79, 3 + registrosDisponibles * 2);
				cout << char(180);

				rlutil::setColor(rlutil::LIGHTGREEN);
				rlutil::locate(3, 4 + registrosDisponibles * 2);
				cout << obj.getId();
				rlutil::locate(8, 4 + registrosDisponibles * 2);
				cout << obj.getNombre();
				rlutil::locate(26, 4 + registrosDisponibles * 2);
				cout << obj.getApellido();
				rlutil::locate(44, 4 + registrosDisponibles * 2);
				cout << obj.getMail();
				rlutil::locate(62, 4 + registrosDisponibles * 2);
				cout << obj.getSueldo();
				rlutil::locate(71, 4 + registrosDisponibles * 2);
				cout << obj.getEstadoStr();
				rlutil::setColor(rlutil::WHITE);

				rlutil::locate(6, 4 + registrosDisponibles * 2);
				cout << char(179);
				rlutil::locate(23, 4 + registrosDisponibles * 2);
				cout << char(179);
				rlutil::locate(41, 4 + registrosDisponibles * 2);
				cout << char(179);
				rlutil::locate(60, 4 + registrosDisponibles * 2);
				cout << char(179);
				rlutil::locate(69, 4 + registrosDisponibles * 2);
				cout << char(179);

				rlutil::locate(1, 5 + registrosDisponibles * 2);
				cout << char(192);
				rlutil::locate(79, 5 + registrosDisponibles * 2);
				cout << char(217);
				for (int j = 0; j < 77; j++)
				{
					rlutil::locate(2 + j, 5 + registrosDisponibles * 2);
					cout << char(196);
				}
				rlutil::locate(6, 5 + registrosDisponibles * 2);
				cout << char(193);
				rlutil::locate(23, 5 + registrosDisponibles * 2);
				cout << char(193);
				rlutil::locate(41, 5 + registrosDisponibles * 2);
				cout << char(193);
				rlutil::locate(60, 5 + registrosDisponibles * 2);
				cout << char(193);
				rlutil::locate(69, 5 + registrosDisponibles * 2);
				cout << char(193);*/
				dibujarFila(registrosDisponibles, obj);
				registrosDisponibles++;
			}
		}

		for (int j = registrosDisponibles; j <= cant; j++)
		{
			Empleado obj;
			obj = archivo.buscar(j);
			if (obj.getEliminado() == 1)
			{
				continue;
			}
			if (obj.getEstado() == EmpleadoEstado::Baja)
			{
				/*rlutil::locate(1, 3 + registrosDisponibles * 2);
				cout << char(195);
				rlutil::locate(1, 4 + registrosDisponibles * 2);
				cout << char(179);
				rlutil::locate(79, 4 + registrosDisponibles * 2);
				cout << char(179);
				rlutil::locate(6, 3 + registrosDisponibles * 2);
				cout << char(197);
				rlutil::locate(23, 3 + registrosDisponibles * 2);
				cout << char(197);
				rlutil::locate(41, 3 + registrosDisponibles * 2);
				cout << char(197);
				rlutil::locate(60, 3 + registrosDisponibles * 2);
				cout << char(197);
				rlutil::locate(69, 3 + registrosDisponibles * 2);
				cout << char(197);
				rlutil::locate(79, 3 + registrosDisponibles * 2);
				cout << char(180);

				rlutil::setColor(rlutil::LIGHTRED);
				rlutil::locate(3, 4 + registrosDisponibles * 2);
				cout << obj.getId();
				rlutil::locate(8, 4 + registrosDisponibles * 2);
				cout << obj.getApellido();
				rlutil::locate(26, 4 + registrosDisponibles * 2);
				cout << obj.getNombre();
				rlutil::locate(44, 4 + registrosDisponibles * 2);
				cout << obj.getMail();
				rlutil::locate(62, 4 + registrosDisponibles * 2);
				cout << obj.getSueldo();
				rlutil::locate(71, 4 + registrosDisponibles * 2);
				cout << obj.getEstadoStr();
				rlutil::setColor(rlutil::WHITE);

				rlutil::locate(6, 4 + registrosDisponibles * 2);
				cout << char(179);
				rlutil::locate(23, 4 + registrosDisponibles * 2);
				cout << char(179);
				rlutil::locate(41, 4 + registrosDisponibles * 2);
				cout << char(179);
				rlutil::locate(60, 4 + registrosDisponibles * 2);
				cout << char(179);
				rlutil::locate(69, 4 + registrosDisponibles * 2);
				cout << char(179);

				rlutil::locate(1, 5 + registrosDisponibles * 2);
				cout << char(192);
				rlutil::locate(79, 5 + registrosDisponibles * 2);
				cout << char(217);
				for (int j = 0; j < 77; j++)
				{
					rlutil::locate(2 + j, 5 + registrosDisponibles * 2);
					cout << char(196);
				}
				rlutil::locate(6, 5 + registrosDisponibles * 2);
				cout << char(193);
				rlutil::locate(23, 5 + registrosDisponibles * 2);
				cout << char(193);
				rlutil::locate(41, 5 + registrosDisponibles * 2);
				cout << char(193);
				rlutil::locate(60, 5 + registrosDisponibles * 2);
				cout << char(193);
				rlutil::locate(69, 5 + registrosDisponibles * 2);
				cout << char(193);*/
				dibujarFila(registrosDisponibles, obj);
				registrosDisponibles++;
			}
		}

	}

	rlutil::locate(1, registrosDisponibles * 2 + 8);
	cout << endl << endl << endl << system("pause");
}

void EmpleadoController::imprimirNoHayRegistros()
{
	rlutil::locate(27, 5);
	cout << "No hay registros cargados.";

	rlutil::locate(1, 6);
	cout << char(192);
	rlutil::locate(1, 4);
	cout << char(179);
	rlutil::locate(1, 5);
	cout << char(179);
	rlutil::locate(80, 4);
	cout << char(179);
	rlutil::locate(80, 5);
	cout << char(179);
	rlutil::locate(80, 6);
	cout << char(217);

	rlutil::locate(1, 3);
	cout << char(195);

	rlutil::locate(80, 3);
	cout << char(180);
	for (int i = 0; i < 78; i++)
	{
		rlutil::locate(2 + i, 6);
		cout << char(196);
	}

	cout << endl;
}

void EmpleadoController::mostrarRegistro(Empleado obj)
{
	rlutil::locate(5, 5);
	cout << "ID: ";
	rlutil::locate(16, 5);
	cout << obj.getId();

	rlutil::locate(5, 7);
	cout << "APELLIDO: ";
	rlutil::locate(16, 7);
	cout << obj.getApellido();

	rlutil::locate(5, 9);
	cout << "NOMBRE: ";
	rlutil::locate(16, 9);
	cout << obj.getNombre();

	rlutil::locate(45, 5);
	cout << "E-MAIL: ";
	rlutil::locate(56, 5);
	cout << obj.getMail();

	rlutil::locate(45, 7);
	cout << "SUELDO: ";
	rlutil::locate(56, 7);
	cout << obj.getSueldo();

	rlutil::locate(45, 9);
	cout << "ESTADO: ";
	rlutil::locate(56, 9);
	cout << obj.getEstadoStr();
}

void EmpleadoController::eliminar()
{
	rlutil::cls();
	rlutil::locate(37, 2);
	cout << "ELIMINAR EMLPEADO";

	Empleado obj;
	int id;
	EmpleadoArchivo archivo;


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
		cout << "0 _ CANCELAR/VOLVER";
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
				cout << "El registro con Id " << id << " fu" << char(130) << " eliminado exitosamente." << endl;
				rlutil::setColor(rlutil::WHITE);
				cout << endl << endl << system("pause");
				opcion = 0;
				break;
			case 0:
				break;
			default:
				rlutil::setColor(rlutil::LIGHTRED);
				rlutil::locate(23, 23);
				cout << "OPCI" << char(224) << "N INCORRECTA" << endl;
				rlutil::setColor(rlutil::WHITE);
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

void EmpleadoController::buscarPorId()
{
	rlutil::cls();
	rlutil::locate(37, 2);
	cout << "BUSCAR EMLPEADO";

	Empleado obj;
	EmpleadoArchivo archivo;
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
		cout << endl;

		int nuevoEstado;


	}
	else
	{
		rlutil::locate(2, 8);
		cout << "El registro con Id " << id << " no se encuentra en el sistema." << endl;
	}

	rlutil::locate(2, 21);
	system("pause");
}

int EmpleadoController::getEmpleadosDisponibles()
{
	EmpleadoArchivo archivo;
	int reg = 0;
	int cant = archivo.getCantidadRegistros();
	if (cant == 0) return 0;

	for (int i = 1; i <= cant; i++)
	{
		Empleado obj;
		obj = archivo.buscar(i);
		if (obj.getEliminado() == 1 || obj.getEstado() == EmpleadoEstado::Baja)
		{
			continue;
		}
		reg++;
	}
	return reg;
}

int EmpleadoController::ventanaEmpleadosDisponibles(int x, int y)
{
	EmpleadoArchivo archivo;
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

	rlutil::locate(x + 2, y + 1);
	cout << "ID";
	rlutil::locate(x + 8, y + 1);
	cout << "NOMBRE";
	rlutil::locate(x + 40, y + 1);
	cout << "APELLIDO";


	for (int i = 1; i <= cant; i++)
	{
		Empleado obj;
		obj = archivo.buscar(i);
		if (obj.getEliminado() == 1 || obj.getEstado() == EmpleadoEstado::Baja)
		{
			continue;
		}

		for (int j = 0; j < 75; j++)
		{
			rlutil::locate(x + j, y + 4 + registrosImpresos * 2);
			cout << char(196);
		}

		rlutil::locate(x, y + 4 + registrosImpresos * 2);
		cout << char(192);
		rlutil::locate(x + 6, y + 4 + registrosImpresos * 2);
		cout << char(193);
		rlutil::locate(x + 38, y + 4 + registrosImpresos * 2);
		cout << char(193);
		rlutil::locate(x + 75, y + 4 + registrosImpresos * 2);
		cout << char(217);

		rlutil::locate(x, y + 2 + registrosImpresos * 2);
		cout << char(195);
		rlutil::locate(x + 6, y + 2 + registrosImpresos * 2);
		cout << char(197);
		rlutil::locate(x + 38, y + 2 + registrosImpresos * 2);
		cout << char(197);
		rlutil::locate(x + 75, y + 2 + registrosImpresos * 2);
		cout << char(180);

		rlutil::locate(x, y + 3 + registrosImpresos * 2);
		cout << char(179);
		rlutil::locate(x + 6, y + 3 + registrosImpresos * 2);
		cout << char(179);
		rlutil::locate(x + 38, y + 3 + registrosImpresos * 2);
		cout << char(179);
		rlutil::locate(x + 75, y + 3 + registrosImpresos * 2);
		cout << char(179);

		rlutil::locate(x + 1, y + 3 + registrosImpresos * 2);
		cout << setw(4) << obj.getId();

		rlutil::locate(x + 7, y + 3 + registrosImpresos * 2);
		cout << setw(30) << obj.getNombre();

		rlutil::locate(x + 39, y + 3 + registrosImpresos * 2);
		cout << setw(29) << obj.getApellido();



		registrosImpresos++;
	}
	return registrosImpresos;
}

void EmpleadoController::limpiarVentanaEmpleaadosDisponibles(int x, int y, int registros)
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