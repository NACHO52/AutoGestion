#include "rlutil.h"
#include <iostream>
#include <iomanip>
#include "AlquilerController.h"
#include "AlquilerArchivo.h"
#include "Cliente.h"
#include "ClienteArchivo.h"
#include "ClienteController.h"
#include "AutoController.h"
#include "AutoArchivo.h"
#include "EmpleadoArchivo.h"

using namespace std;

void AlquilerController::mostrarMenu()
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
			listar(0,0);
			break;
		case 3:
			listarVigentes(0,0);
			break;
		case 4:
			listarTerminados(0,0);
			break;
		case 5:
			editar();
			break;
		case 6:
			buscarPorId();
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

void AlquilerController::dibujarMenu()
{
	rlutil::locate(29, 2);
	cout << "ALQUILERES" << endl;

	rlutil::locate(24, 6);
	cout << "1 _ CREAR" << endl;
	rlutil::locate(24, 7);
	cout << "2 _ LISTAR TODOS" << endl;
	rlutil::locate(24, 8);
	cout << "3 _ LISTAR VIGENTES" << endl;
	rlutil::locate(24, 9);
	cout << "4 _ LISTAR TERMINADOS" << endl;
	rlutil::locate(24, 10);
	cout << "5 _ EDITAR" << endl;
	rlutil::locate(24, 11);
	cout << "6 _ BUSCAR POR ID" << endl;
	rlutil::locate(24, 13);
	cout << "0 _ VOLVER" << endl;

	rlutil::locate(24, 15);
	cout << "OPCI" << char(224) << "N: " << endl;

	rlutil::locate(18, 4);
	cout << char(201);
	rlutil::locate(50, 4);
	cout << char(187);

	rlutil::locate(18, 18);
	cout << char(200);
	rlutil::locate(50, 18);
	cout << char(188);

	for (int i = 19; i < 50; i++)
	{
		rlutil::locate(i, 4);
		cout << char(205);
		rlutil::locate(i, 18);
		cout << char(205);
	}
	for (int i = 5; i < 18; i++)
	{
		rlutil::locate(18, i);
		cout << char(186);
		rlutil::locate(50, i);
		cout << char(186);
	}
}

void AlquilerController::crear()
{
	rlutil::cls();

	string dni;
	int autoId, dia, mes, anio, empleadoId;
	AutoController autoController;
	float precio;

	rlutil::locate(22, 2);
	cout << "CREAR ALQUILER";

	rlutil::locate(3, 4);
	cout << "CLIENTE D.N.I.: ";


	rlutil::locate(19, 4);
	cin.ignore();
	getline(cin, dni);

	ClienteArchivo archivoCliente;
	Cliente cliente = archivoCliente.buscarPorDNI(dni);

	if (cliente.getId() == 0)
	{
		cliente = ClienteController().ventanaNuevoCliente(dni);

	}
	rlutil::locate(42, 4);
	cout << cliente.getApellido() << ", " << cliente.getNombre();


	int autosObtenidos = autoController.ventanaAutosDisponibles(4,8);
	Auto obj;

	bool errores;
	do
	{
		rlutil::locate(3, 6);
		cout << "AUTO ID: ";

		rlutil::locate(13, 6);
		cin >> autoId;
		obj = AutoArchivo().buscar(autoId);
		if (obj.getId() == 0 || obj.getEstado() != AutoEstado::Disponible)
		{

			rlutil::locate(20, 7);
			rlutil::setColor(rlutil::LIGHTRED);
			cout << "EL ID INGRESADO NO PERTENECE A UN AUTO DE LA LISTA";
			rlutil::setColor(rlutil::WHITE);

			rlutil::locate(9, 6);
			cout << "                                       ";
			errores = true;
		}
		else errores = false;
		
	} while (errores);
	
	autoController.limpiarVentanaAutosDisponibles(4, 8, autosObtenidos);


	rlutil::locate(42, 6);
	cout << "FECHA HASTA: __/__/____";

	rlutil::locate(3, 8);
	cout << "PRECIO: $";

	rlutil::locate(42, 8);
	cout << "EMPLEADO: ";


	rlutil::locate(55, 6);
	cin >> dia;
	rlutil::locate(58, 6);
	cin >> mes;
	rlutil::locate(61, 6);
	cin >> anio;

	rlutil::locate(12, 8);
	cin >> precio;

	rlutil::locate(55, 8);
	cin >> empleadoId;


	int opcion;
	do
	{
		rlutil::locate(21, 13);
		cout << "                                            ";
		rlutil::locate(13, 10);
		cout << "1 _ CREAR";
		rlutil::locate(13, 11);
		cout << "0 _ CANCELAR";
		rlutil::locate(13, 13);
		cout << "OPCI"<< char(224) <<"N: ";
		rlutil::locate(21, 13);
		cin >> opcion;

		Alquiler alquiler;

		switch (opcion)
		{
		case 1:
			alquiler.setAutoId(obj.getId());
			alquiler.setClienteId(cliente.getId());
			alquiler.setEmpleadoId(empleadoId);
			alquiler.setFechaHasta(Fecha(dia,mes,anio));
			alquiler.setPrecio(precio);
			if (AlquilerArchivo().guardar(alquiler)) {
				rlutil::locate(13, 15);
				rlutil::setColor(rlutil::LIGHTGREEN);
				cout << "EL REGISTRO SE HA GUARDADO EXITOSAMENTE" << endl;
				rlutil::setColor(rlutil::WHITE);
				cout << endl << endl << system("pause");
				opcion = 0;
			}

			break;
		case 0:
			break;
		default:
			rlutil::setColor(rlutil::LIGHTRED);
			rlutil::locate(21, 13);
			cout << "OPCI" << char(224) << "N INCORRECTA";
			rlutil::setColor(rlutil::WHITE);
			rlutil::anykey();
			break;
		}

	} while (opcion != 0);


}

void AlquilerController::listaHeader(int x, int y) {

	rlutil::locate(x + 3, y + 2);
	cout << "ID";
	rlutil::locate(x + 7, y + 2);
	cout << "CLIENTE ID";
	rlutil::locate(x + 18, y + 2);
	cout << "AUTO ID";
	rlutil::locate(x + 28, y + 2);
	cout << "DESDE";
	rlutil::locate(x + 39, y + 2);
	cout << "HASTA";
	rlutil::locate(x + 49, y + 2);
	cout << "ESTADO";
	rlutil::locate(x + 59, y + 2);
	cout << "PRECIO";
	rlutil::locate(x + 67, y + 2);
	cout << "EMPLEADO ID";

	rlutil::locate(x + 1, y + 1);
	cout << char(218);
	for (int i = 0; i < 78; i++)
	{
		rlutil::locate(x + 2 + i, y + 1);
		cout << char(196);
		rlutil::locate(x + 2 + i, y + 3);
		cout << char(196);
	}
	rlutil::locate(x + 79, y + 1);
	cout << char(191);

	rlutil::locate(x + 1, y + 2);
	cout << char(179);
	rlutil::locate(x + 6, y + 2);
	cout << char(179);
	rlutil::locate(x + 17, y + 2);
	cout << char(179);
	rlutil::locate(x + 25, y + 2);
	cout << char(179);
	rlutil::locate(x + 36, y + 2);
	cout << char(179);
	rlutil::locate(x + 47, y + 2);
	cout << char(179);
	rlutil::locate(x + 57, y + 2);
	cout << char(179);
	rlutil::locate(x + 66, y + 2);
	cout << char(179);
	rlutil::locate(x + 79, y + 2);
	cout << char(179);


	rlutil::locate(x + 6, y + 1);
	cout << char(194);
	rlutil::locate(x + 17, y + 1);
	cout << char(194);
	rlutil::locate(x + 25, y + 1);
	cout << char(194);
	rlutil::locate(x + 36, y + 1);
	cout << char(194);
	rlutil::locate(x + 47, y + 1);
	cout << char(194);
	rlutil::locate(x + 57, y + 1);
	cout << char(194);
	rlutil::locate(x + 66, y + 1);
	cout << char(194);

}
void AlquilerController::imprimirNoHayRegistros(int x, int y)
{
	rlutil::locate(x + 27, y + 5);
	cout << "No hay registros cargados.";

	rlutil::locate(x + 6, y + 3);
	cout << char(193);
	rlutil::locate(x + 17, y + 3);
	cout << char(193);
	rlutil::locate(x + 25, y + 3);
	cout << char(193);
	rlutil::locate(x + 36, y + 3);
	cout << char(193);
	rlutil::locate(x + 47, y + 3);
	cout << char(193);
	rlutil::locate(x + 57, y + 3);
	cout << char(193);
	rlutil::locate(x + 66, y + 3);
	cout << char(193);

	rlutil::locate(x + 1, y + 6);
	cout << char(192);
	rlutil::locate(x + 1, y + 4);
	cout << char(179);
	rlutil::locate(x + 1, y + 5);
	cout << char(179);
	rlutil::locate(x + 79, y + 4);
	cout << char(179);
	rlutil::locate(x + 79, y + 5);
	cout << char(179);
	rlutil::locate(x + 79, y + 6);
	cout << char(217);

	rlutil::locate(x + 1, y + 3);
	cout << char(195);

	rlutil::locate(x + 79, y + 3);
	cout << char(180);
	for (int i = 0; i < 77; i++)
	{
		rlutil::locate(x + 2 + i, y + 6);
		cout << char(196);
	}

	cout << endl;
}

void AlquilerController::listar(int x, int y)
{
	rlutil::cls();
	listaHeader(x,y);

	AlquilerArchivo archivo;
	int registrosImpresos = 0;
	int cant = archivo.getCantidadRegistros();
	if (cant == 0)
	{
		imprimirNoHayRegistros(x,y);
	}
	else
	{
		for (int j = 1; j <= cant; j++)
		{
			Alquiler obj;
			obj = archivo.buscar(j);

			DibujarFila(x, y, registrosImpresos, obj);
			registrosImpresos++;
		}

		if (registrosImpresos == 0) {
			imprimirNoHayRegistros(x,y);
		}
	}

	rlutil::locate(1, registrosImpresos * 2 + 8);
	cout << endl << endl << endl << system("pause");
}


int AlquilerController::listarPorCliente(int x, int y, int clienteId)
{
	listaHeader(x, y);

	AlquilerArchivo archivo;
	int registrosImpresos = 0;
	int cant = archivo.getCantidadRegistros();
	if (cant == 0)
	{
		imprimirNoHayRegistros(x, y);
	}
	else
	{
		for (int j = 1; j <= cant; j++)
		{
			Alquiler obj;
			obj = archivo.buscar(j);

			if (obj.getClienteId() == clienteId)
			{
				DibujarFila(x, y, registrosImpresos, obj);
				registrosImpresos++;
			}
		}

		if (registrosImpresos == 0) {
			imprimirNoHayRegistros(x, y);
		}
	}

	return registrosImpresos;
}

void AlquilerController::DibujarFila(int x, int y, int corrimiento, Alquiler& obj)
{
	rlutil::locate(x + 1, 3 + corrimiento * 2 + y);
	cout << char(195);

	rlutil::locate(x + 1, 4 + corrimiento * 2 + y);
	cout << char(179);
	rlutil::locate(x + 79, 4 + corrimiento * 2 + y);
	cout << char(179);

	rlutil::locate(x + 6, 3 + corrimiento * 2 + y);
	cout << char(197);
	rlutil::locate(x + 17, 3 + corrimiento * 2 + y);
	cout << char(197);
	rlutil::locate(x + 25, 3 + corrimiento * 2 + y);
	cout << char(197);
	rlutil::locate(x + 36, 3 + corrimiento * 2 + y);
	cout << char(197);
	rlutil::locate(x + 47, 3 + corrimiento * 2 + y);
	cout << char(197);
	rlutil::locate(x + 57, 3 + corrimiento * 2 + y);
	cout << char(197);
	rlutil::locate(x + 66, 3 + corrimiento * 2 + y);
	cout << char(197);

	rlutil::locate(x + 79, 3 + corrimiento * 2 + y);
	cout << char(180);

	switch (obj.getEstado())
	{
	case AlquilerEstado::TerminadoCorrecto:
		rlutil::setColor(rlutil::LIGHTGREEN);
		break;
	case AlquilerEstado::Vigente:
		rlutil::setColor(rlutil::YELLOW);
		break;
	case AlquilerEstado::TerminadoConVencimiento:
		rlutil::setColor(rlutil::LIGHTGREEN);
		break;
	default:
		break;
	}

	rlutil::locate(x + 2, 4 + corrimiento * 2 + y);
	cout << setw(4) << obj.getId();
	rlutil::locate(x + 7, 4 + corrimiento * 2 + y);
	cout << setw(9) << obj.getClienteId();
	rlutil::locate(x + 18, 4 + corrimiento * 2 + y);
	cout << setw(6) << obj.getAutoId();
	rlutil::locate(x + 26, 4 + corrimiento * 2 + y);
	cout << setw(10) << obj.getFechaDesde().FechaStr();
	rlutil::locate(x + 37, 4 + corrimiento * 2 + y);
	cout << setw(10) << obj.getFechaHasta().FechaStr();
	rlutil::locate(x + 48, 4 + corrimiento * 2 + y);
	cout << setw(9) << obj.getEstadoStr();
	rlutil::locate(x + 58, 4 + corrimiento * 2 + y);
	cout << setw(8) << obj.getPrecio();
	rlutil::locate(x + 67, 4 + corrimiento * 2 + y);
	cout << setw(11) << obj.getEmpleadoId();
	rlutil::setColor(rlutil::WHITE);

	rlutil::locate(x + 6, 4 + corrimiento * 2 + y);
	cout << char(179);
	rlutil::locate(x + 17, 4 + corrimiento * 2 + y);
	cout << char(179);
	rlutil::locate(x + 25, 4 + corrimiento * 2 + y);
	cout << char(179);
	rlutil::locate(x + 36, 4 + corrimiento * 2 + y);
	cout << char(179);
	rlutil::locate(x + 47, 4 + corrimiento * 2 + y);
	cout << char(179);
	rlutil::locate(x + 57, 4 + corrimiento * 2 + y);
	cout << char(179);
	rlutil::locate(x + 66, 4 + corrimiento * 2 + y);
	cout << char(179);

	rlutil::locate(x + 1, 5 + corrimiento * 2 + y);
	cout << char(192);
	rlutil::locate(x + 79, 5 + corrimiento * 2 + y);
	cout << char(217);

	for (int j = 0; j < 77; j++)
	{
		rlutil::locate(x + 2 + j, 5 + corrimiento * 2 + y);
		cout << char(196);
	}

	rlutil::locate(x + 6, 5 + corrimiento * 2 + y);
	cout << char(193);
	rlutil::locate(x + 17, 5 + corrimiento * 2 + y);
	cout << char(193);
	rlutil::locate(x + 25, 5 + corrimiento * 2 + y);
	cout << char(193);
	rlutil::locate(x + 36, 5 + corrimiento * 2 + y);
	cout << char(193);
	rlutil::locate(x + 47, 5 + corrimiento * 2 + y);
	cout << char(193);
	rlutil::locate(x + 57, 5 + corrimiento * 2 + y);
	cout << char(193);
	rlutil::locate(x + 66, 5 + corrimiento * 2 + y);
	cout << char(193);
}

void AlquilerController::listarVigentes(int x, int y)
{
	rlutil::cls();
	listaHeader(x,y);

	AlquilerArchivo archivo;
	int registrosImpresos = 0;
	int cant = archivo.getCantidadRegistros();
	if (cant == 0)
	{
		imprimirNoHayRegistros(x,y);
	}
	else
	{
		for (int j = 1; j <= cant; j++)
		{
			Alquiler obj;
			obj = archivo.buscar(j);
			if (obj.getEstado() == AlquilerEstado::Vigente)
			{
				DibujarFila(x,y,registrosImpresos, obj);
				registrosImpresos++;
			}
		}

		if (registrosImpresos == 0) {
			imprimirNoHayRegistros(x,y);
		}
	}

	rlutil::locate(1, registrosImpresos * 2 + 8);
	cout << endl << endl << endl << system("pause");
}
void AlquilerController::listarTerminados(int x, int y)
{
	rlutil::cls();
	listaHeader(x,y);

	AlquilerArchivo archivo;
	int registrosImpresos = 0;
	int cant = archivo.getCantidadRegistros();
	if (cant == 0)
	{
		imprimirNoHayRegistros(x,y);
	}
	else
	{
		for (int j = 1; j <= cant; j++)
		{
			Alquiler obj;
			obj = archivo.buscar(j);
			if (obj.getEstado() == AlquilerEstado::TerminadoCorrecto || obj.getEstado() == AlquilerEstado::TerminadoConVencimiento)
			{
				DibujarFila(x, y, registrosImpresos, obj);
				registrosImpresos++;
			}
		}

		if (registrosImpresos == 0) {
			imprimirNoHayRegistros(x,y);
		}
	}

	rlutil::locate(1, registrosImpresos * 2 + 8);
	cout << endl << endl << endl << system("pause");
}


void AlquilerController::buscarPorId()
{
	rlutil::cls();
	rlutil::locate(25, 1);
	cout << "BUSCAR ALQUILER";

	Alquiler obj;
	AlquilerArchivo archivo;
	int id;
	rlutil::locate(5, 2);
	cout << "ID: ";
	rlutil::locate(9, 2);
	cin >> id;

	obj = archivo.buscar(id);
	if (obj.getId() == 0)
	{
		rlutil::locate(2, 8);
		cout << "El registro con Id " << id << " no se encuentra en el sistema." << endl;
	}
	else
	{
		mostrarRegistro(obj, true, true, true);
		cout << endl << endl;
	}

	system("pause");
}

void AlquilerController::mostrarRegistro(Alquiler obj, bool mostrarAuto, bool mostrarCliente, bool mostrarEmpleado)
{

	rlutil::locate(5, 4);
	cout << "DESDE: ";
	rlutil::locate(12, 4);
	cout << obj.getFechaDesde().FechaStr();

	rlutil::locate(41, 4);
	cout << "HASTA: ";
	rlutil::locate(48, 4);
	cout << obj.getFechaHasta().FechaStr();

	rlutil::locate(5, 6);
	cout << "ESTADO: ";
	rlutil::locate(13, 6);
	cout << obj.getEstadoStr();

	rlutil::locate(41, 6);
	cout << "PRECIO: $";
	rlutil::locate(50, 6);
	cout << obj.getPrecio();



	if (mostrarAuto)
	{
		rlutil::locate(4, 9);
		cout << char(218);
		rlutil::locate(4, 12);
		cout << char(192);
		rlutil::locate(77, 9);
		cout << char(191);
		rlutil::locate(77, 12);
		cout << char(217);
		for (int i = 5; i < 77; i++)
		{
			rlutil::locate(i, 9);
			cout << char(196);
			rlutil::locate(i, 12);
			cout << char(196);
		}
		rlutil::locate(4, 11);
		cout << char(179);
		rlutil::locate(4, 10);
		cout << char(179);
		rlutil::locate(77, 10);
		cout << char(179);
		rlutil::locate(77, 11);
		cout << char(179);

		rlutil::locate(5, 8);
		cout << "AUTO";
		Auto aut = AutoArchivo().buscar(obj.getAutoId());
		rlutil::locate(5, 10);
		cout << "ID: ";
		rlutil::locate(9, 10);
		cout << aut.getId();
		rlutil::locate(5, 11);
		cout << "A" << char(165) << "O: ";
		rlutil::locate(10, 11);
		cout << aut.getAnio();
		rlutil::locate(17, 10);
		cout << "MARCA: ";
		rlutil::locate(24, 10);
		cout << aut.getMarca();
		rlutil::locate(17, 11);
		cout << "MODELO: ";
		rlutil::locate(25, 11);
		cout << aut.getModelo();
		rlutil::locate(55, 10);
		cout << "PATENTE: ";
		rlutil::locate(64, 10);
		cout << aut.getPatente();
	}

	if (mostrarCliente)
	{
		rlutil::locate(4, 14);
		cout << char(218);
		rlutil::locate(4, 17);
		cout << char(192);
		rlutil::locate(77, 14);
		cout << char(191);
		rlutil::locate(77, 17);
		cout << char(217);
		for (int i = 5; i < 77; i++)
		{
			rlutil::locate(i, 14);
			cout << char(196);
			rlutil::locate(i, 17);
			cout << char(196);
		}
		rlutil::locate(4, 16);
		cout << char(179);
		rlutil::locate(4, 15);
		cout << char(179);
		rlutil::locate(77, 15);
		cout << char(179);
		rlutil::locate(77, 16);
		cout << char(179);

		rlutil::locate(5, 13);
		cout << "CLIENTE";
		Cliente cliente = ClienteArchivo().buscar(obj.getClienteId());
		rlutil::locate(5, 15);
		cout << "ID: ";
		rlutil::locate(9, 15);
		cout << cliente.getId();
		rlutil::locate(5, 16);
		cout << "D.N.I.: ";
		rlutil::locate(13, 16);
		cout << cliente.getDni();
		rlutil::locate(25, 15);
		cout << "NOMBRE: ";
		rlutil::locate(33, 15);
		cout << cliente.getNombre();
		rlutil::locate(25, 16);
		cout << "APELLIDO: ";
		rlutil::locate(35, 16);
		cout << cliente.getApellido();
		rlutil::locate(50, 15);
		cout << "TEL" << char(144) << "FONO: ";
		rlutil::locate(60, 15);
		cout << cliente.getTelefono();
		rlutil::locate(50, 16);
		cout << "E-MAIL: ";
		rlutil::locate(58, 16);
		cout << cliente.getMail();
	}
	
	if (mostrarEmpleado)
	{
		rlutil::locate(4, 20);
		cout << char(218);
		rlutil::locate(4, 23);
		cout << char(192);
		rlutil::locate(77, 20);
		cout << char(191);
		rlutil::locate(77, 23);
		cout << char(217);
		for (int i = 5; i < 77; i++)
		{
			rlutil::locate(i, 20);
			cout << char(196);
			rlutil::locate(i, 23);
			cout << char(196);
		}
		rlutil::locate(4, 22);
		cout << char(179);
		rlutil::locate(4, 21);
		cout << char(179);
		rlutil::locate(77, 21);
		cout << char(179);
		rlutil::locate(77, 22);
		cout << char(179);

		rlutil::locate(5, 19);
		cout << "EMPLEADO: ";
		Empleado empleado = EmpleadoArchivo().buscar(obj.getId());
		rlutil::locate(5, 21);
		cout << "ID: ";
		rlutil::locate(9, 21);
		cout << empleado.getId();
		rlutil::locate(5, 22);
		cout << "ESTADO: ";
		rlutil::locate(13, 22);
		cout << empleado.getEstadoStr();
		rlutil::locate(21, 21);
		cout << "NOMBRE: ";
		rlutil::locate(29, 21);
		cout << empleado.getNombre();
		rlutil::locate(21, 22);
		cout << "APELLIDO: ";
		rlutil::locate(31, 22);
		cout << empleado.getApellido();
		rlutil::locate(49, 21);
		cout << "E-MAIL: ";
		rlutil::locate(57, 21);
		cout << empleado.getMail();
		rlutil::locate(49, 22);
		cout << "SUELDO: $";
		rlutil::locate(58, 22);
		cout << empleado.getSueldo();
	}
	
	
}

void AlquilerController::editar()
{
	rlutil::cls();
	rlutil::locate(25, 1);
	cout << "EDITAR ALQUILER";

	Alquiler obj;
	AlquilerArchivo archivo;
	int id;
	rlutil::locate(5, 2);
	cout << "ID: ";
	rlutil::locate(9, 2);
	cin >> id;

	obj = archivo.buscar(id);
	if (obj.getId() > 0)
	{
		mostrarRegistro(obj, true, true, false);
		cout << endl;

		int nuevoEstado;

		rlutil::locate(17, 18);
		cout << "1 _ VIGENTE";
		rlutil::locate(17, 19);
		cout << "2 _ TERMINADO";
		rlutil::locate(17, 20);
		cout << "3 _ TERMINADO/VENCIDO";
		rlutil::locate(17, 21);
		cout << "0 _ CANCELAR/VOLVER";

		do
		{
			rlutil::locate(31, 23);
			cout << "                                                   ";
			rlutil::locate(17, 23);
			cout << "NUEVO ESTADO: ";
			rlutil::locate(31, 23);
			cin >> nuevoEstado;
			if (nuevoEstado == 1 || nuevoEstado == 2 || nuevoEstado == 3)
			{
				obj.setEstado((AlquilerEstado)nuevoEstado);
				archivo.guardar(obj);
				rlutil::setColor(rlutil::LIGHTGREEN);

				rlutil::locate(25, 24);
				cout << "GUARDADO EXITOSO";
				rlutil::setColor(rlutil::WHITE);
				rlutil::locate(1, 25);
				system("pause");
				break;
			}
			else if (nuevoEstado != 0)
			{
				rlutil::locate(31, 23);
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