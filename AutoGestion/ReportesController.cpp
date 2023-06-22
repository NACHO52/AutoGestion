#include "ReportesController.h"
#include "rlutil.h"
#include "EmpleadoArchivo.h"
#include "AlquilerArchivo.h"
#include "ClienteArchivo.h"
#include "AutoArchivo.h"
#include <iomanip>
#include "Funciones.h"

using namespace std;

void ReportesController::mostrarMenu()
{
    int opcion;
    do
    {
        rlutil::cls();
        dibujarMenu();

        opcion = Funciones().inputNumero(32,15,13);

        switch (opcion)
        {
        case 1:
            recaudacionPorEmpleado();
            break;
        case 2:
            rlutil::cls();
            recaudacionPorCliente();
            break;
        case 3:
            reportePorAuto();
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
    cout << "1 _ RECAUDACI" << char(224) << "N POR EMPLEADO" << endl;
    rlutil::locate(24, 7);
    cout << "2 _ RECAUDACI" << char(224) << "N POR CLIENTE" << endl;
    rlutil::locate(24, 8);
    cout << "3 _ RECAUDACI" << char(224) << "N POR AUTO" << endl;
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
    rlutil::cls();

    rlutil::locate(30, 1);
	cout << "RECAUDACI"<< char(224) <<"N POR EMPLEADO";
	bool errores = false;
    int diaDesde, mesDesde, anioDesde, diaHasta, mesHasta, anioHasta;
    Fecha fechaDesde, fechaHasta;
    do
	{
		rlutil::locate(3, 2);
		cout << "FECHA DESDE: D" << char(214) << "A:    MES:    A" << char(165) << "O: ";
		rlutil::locate(21, 2);
		diaDesde = Funciones().inputNumero(21,2,3);
		rlutil::locate(29, 2);
		mesDesde = Funciones().inputNumero(29,2,3);
		rlutil::locate(37, 2);
		anioDesde = Funciones().inputNumero(37,2,5);

		fechaDesde = Fecha(diaDesde,mesDesde,anioDesde);

		if(fechaDesde.getAnio() != anioDesde || fechaDesde.getMes() != mesDesde || fechaDesde.getDia() != diaDesde)
		{
			rlutil::locate(20, 2);
			cout << "                                                                  ";
			rlutil::locate(21, 2);
			rlutil::setColor(rlutil::LIGHTRED);
			cout << "FECHA INV"<< char(181) <<"LIDA";
			rlutil::setColor(rlutil::WHITE);
			errores = true;
			rlutil::anykey();
			rlutil::locate(20, 2);
			cout << "                                                                  ";
		}

		else
			errores = false;
	} while (errores);

    do
	{
		rlutil::locate(62, 2);
		cout << "                                                                  ";
		rlutil::locate(43, 2);
		cout << "FECHA HASTA: D" << char(214) << "A:    MES:    A" << char(165) << "O: ";
		rlutil::locate(62, 2);
		diaHasta = Funciones().inputNumero(61,2,3);
		rlutil::locate(70, 2);
		mesHasta = Funciones().inputNumero(69,2,3);
		rlutil::locate(78, 2);
		anioHasta = Funciones().inputNumero(77,2,4);
		if(diaHasta == 0 && mesHasta == 0 && anioHasta == 0) return;

		fechaHasta = Fecha(diaHasta,mesHasta,anioHasta);
		if(fechaHasta.getAnio() != anioHasta || fechaHasta.getMes() != mesHasta || fechaHasta.getDia() != diaHasta)
		{
			rlutil::locate(62, 2);
			cout << "                                                                  ";
			rlutil::locate(62, 2);
			rlutil::setColor(rlutil::LIGHTRED);
			cout << "FECHA INV"<< char(181) <<"LIDA";
			rlutil::setColor(rlutil::WHITE);
			errores = true;
			rlutil::anykey();
		}
		else if(Fecha().fechasInvalidas(fechaDesde, fechaHasta))
		{
			rlutil::locate(62, 2);
			cout << "                                                                  ";
			rlutil::locate(62, 2);
			rlutil::setColor(rlutil::LIGHTRED);
			cout << "\"FECHA DESDE\" MAYOR A \"FECHA HASTA\"";
			rlutil::setColor(rlutil::WHITE);
			errores = true;
			rlutil::anykey();
		}
		else
			errores = false;
	} while (errores);

	rlutil::locate(3, 4);
	cout << "ID";
	rlutil::locate(8,4);
	cout << "NOMBRE";
	rlutil::locate(23,4);
	cout << "APELLIDO";
	rlutil::locate(39, 4);
	cout << "ALQUILERES";
	rlutil::locate(52,4);
	cout << "SUELDO";
	rlutil::locate(62,4);
	cout << "TOTAL RECAUDADO";

	rlutil::locate(1, 3);
	cout << char(218);
	for (int i = 0; i < 78; i++)
	{
		rlutil::locate(2 + i, 3);
		cout << char(196);
		rlutil::locate(2 + i, 5);
		cout << char(196);
	}
	rlutil::locate(79, 3);
	cout << char(191);

	rlutil::locate(1, 4);
	cout << char(179);
	rlutil::locate(6, 4);
	cout << char(179);
	rlutil::locate(21, 4);
	cout << char(179);
	rlutil::locate(37, 4);
	cout << char(179);
	rlutil::locate(50, 4);
	cout << char(179);
	rlutil::locate(60, 4);
	cout << char(179);
	rlutil::locate(79, 4);
	cout << char(179);


	rlutil::locate(6, 3);
	cout << char(194);
	rlutil::locate(21, 3);
	cout << char(194);
	rlutil::locate(37, 3);
	cout << char(194);
	rlutil::locate(50, 3);
	cout << char(194);
	rlutil::locate(60, 3);
	cout << char(194);


	Empleado empleado;
	EmpleadoArchivo empleadoArchivo;
	Alquiler alquiler;
	int corrimiento = 0;
	int cantEmpleados = empleadoArchivo.getCantidadRegistros();
	if (cantEmpleados == 0)
	{
		noHayRegistrosReporteEmpleados();
		system("pause");
		return;
	}

	AlquilerArchivo alquilerArchivo;
	int cantAlquileres = alquilerArchivo.getCantidadRegistros();
	for (int i = 1; i <= cantEmpleados; i++)
	{
		empleado = empleadoArchivo.buscar(i);


		rlutil::locate(1, 5 + corrimiento * 2 );
		cout << char(195);
		rlutil::locate(79, 5 + corrimiento * 2);
		cout << char(180);

		rlutil::locate(1, 6 + corrimiento * 2 );
		cout << char(179);
		rlutil::locate(79, 6 + corrimiento * 2 );
		cout << char(179);

		rlutil::locate(6, 5 + corrimiento * 2 );
		cout << char(197);
		rlutil::locate(21, 5 + corrimiento * 2 );
		cout << char(197);
		rlutil::locate(37, 5 + corrimiento * 2);
		cout << char(197);
		rlutil::locate(50, 5 + corrimiento * 2 );
		cout << char(197);
		rlutil::locate(60, 5 + corrimiento * 2 );
		cout << char(197);

        switch (empleado.getEstado())
        {
        case EmpleadoEstado::Activo :
            rlutil::setColor(rlutil::LIGHTGREEN);
            break;
        case EmpleadoEstado::Baja:
            rlutil::setColor(rlutil::LIGHTRED);
            break;
        default:
            break;
        }

		rlutil::locate(2, 6 + corrimiento * 2 );
		cout << setw(4) << empleado.getId();
		rlutil::locate(7, 6 + corrimiento * 2 );
		cout << setw(13) << empleado.getNombre();
		rlutil::locate(22, 6 + corrimiento * 2 );
		cout << setw(14) << empleado.getApellido();
		rlutil::locate(38, 6 + corrimiento * 2);

		int alquileres = 0;
		float total = 0;

		if (cantAlquileres > 0)
		{
			for (int j = 1; j <= cantAlquileres; j++)
			{
				alquiler = alquilerArchivo.buscar(j);
				if (alquiler.getEmpleadoId() == empleado.getId() && alquiler.getEstado() != AlquilerEstado::Vigente &&
                    (( fechaHasta >= alquiler.getFechaDesde() && alquiler.getFechaDesde() >= fechaDesde) || (fechaDesde <= alquiler.getFechaHasta() && alquiler.getFechaHasta() <= fechaHasta)))
				{
					alquileres++;
					total += alquiler.getPrecio();
				}
			}
		}

		cout << setw(11) << alquileres;
		rlutil::locate(51, 6 + corrimiento * 2 );
		cout << setw(8) << empleado.getSueldo();
		rlutil::locate(61, 6 + corrimiento * 2 );
		cout << setw(16) << total;

        rlutil::setColor(rlutil::WHITE);

		rlutil::locate(1, 6 + corrimiento * 2);
		cout << char(179);
		rlutil::locate(6, 6 + corrimiento * 2 );
		cout << char(179);
		rlutil::locate(21, 6 + corrimiento * 2 );
		cout << char(179);
		rlutil::locate(37, 6 + corrimiento * 2);
		cout << char(179);
		rlutil::locate(50, 6 + corrimiento * 2 );
		cout << char(179);
		rlutil::locate(60, 6 + corrimiento * 2 );
		cout << char(179);



		for (int j = 0; j < 78; j++)
		{
			rlutil::locate(2 + j, 7 + corrimiento * 2 );
			cout << char(196);
		}
		rlutil::locate(1, 7 + corrimiento * 2);
		cout << char(192);
		rlutil::locate(79, 7 + corrimiento * 2);
		cout << char(217);

		rlutil::locate(6, 7 + corrimiento * 2 );
		cout << char(193);
		rlutil::locate(21, 7 + corrimiento * 2 );
		cout << char(193);
		rlutil::locate(37, 7 + corrimiento * 2);
		cout << char(193);
		rlutil::locate(50, 7 + corrimiento * 2 );
		cout << char(193);
		rlutil::locate(60, 7 + corrimiento * 2 );
		cout << char(193);

		corrimiento++;
	}

	rlutil::locate(1, corrimiento * 2 + 8);
	system("pause");
}

void ReportesController::recaudacionPorCliente()
{
    rlutil::cls();

    rlutil::locate(30, 1);
	cout << "RECAUDACI"<< char(224) <<"N POR CLIENTE";
	bool errores = false;
    int diaDesde, mesDesde, anioDesde, diaHasta, mesHasta, anioHasta;
    Fecha fechaDesde, fechaHasta;
    do
	{
		rlutil::locate(3, 2);
		cout << "FECHA DESDE: D" << char(214) << "A:    MES:    A" << char(165) << "O: ";
		rlutil::locate(21, 2);
		diaDesde = Funciones().inputNumero(21,2,3);
		rlutil::locate(29, 2);
		mesDesde = Funciones().inputNumero(29,2,3);
		rlutil::locate(37, 2);
		anioDesde = Funciones().inputNumero(37,2,5);

		fechaDesde = Fecha(diaDesde,mesDesde,anioDesde);

		if(fechaDesde.getAnio() != anioDesde || fechaDesde.getMes() != mesDesde || fechaDesde.getDia() != diaDesde)
		{
			rlutil::locate(20, 2);
			cout << "                                                                  ";
			rlutil::locate(21, 2);
			rlutil::setColor(rlutil::LIGHTRED);
			cout << "FECHA INV"<< char(181) <<"LIDA";
			rlutil::setColor(rlutil::WHITE);
			errores = true;
			rlutil::anykey();
			rlutil::locate(20, 2);
			cout << "                                                                  ";
		}

		else
			errores = false;
	} while (errores);

    do
	{
		rlutil::locate(62, 2);
		cout << "                                                                  ";
		rlutil::locate(43, 2);
		cout << "FECHA HASTA: D" << char(214) << "A:    MES:    A" << char(165) << "O: ";
		rlutil::locate(62, 2);
		diaHasta = Funciones().inputNumero(61,2,3);
		rlutil::locate(70, 2);
		mesHasta = Funciones().inputNumero(69,2,3);
		rlutil::locate(78, 2);
		anioHasta = Funciones().inputNumero(77,2,4);
		if(diaHasta == 0 && mesHasta == 0 && anioHasta == 0) return;

		fechaHasta = Fecha(diaHasta,mesHasta,anioHasta);
		if(fechaHasta.getAnio() != anioHasta || fechaHasta.getMes() != mesHasta || fechaHasta.getDia() != diaHasta)
		{
			rlutil::locate(62, 2);
			cout << "                                                                  ";
			rlutil::locate(62, 2);
			rlutil::setColor(rlutil::LIGHTRED);
			cout << "FECHA INV"<< char(181) <<"LIDA";
			rlutil::setColor(rlutil::WHITE);
			errores = true;
			rlutil::anykey();
		}
		else if(Fecha().fechasInvalidas(fechaDesde, fechaHasta))
		{
			rlutil::locate(62, 2);
			cout << "                                                                  ";
			rlutil::locate(62, 2);
			rlutil::setColor(rlutil::LIGHTRED);
			cout << "\"FECHA DESDE\" MAYOR A \"FECHA HASTA\"";
			rlutil::setColor(rlutil::WHITE);
			errores = true;
			rlutil::anykey();
		}
		else
			errores = false;
	} while (errores);

    rlutil::locate(3, 4);
	cout << "ID";
	rlutil::locate(8,4);
	cout << "NOMBRE";
	rlutil::locate(23,4);
	cout << "APELLIDO";
	rlutil::locate(39, 4);
	cout << "DNI";
	rlutil::locate(52,4);
	cout << "MAIL";
	rlutil::locate(72,4);
	cout << "TOTAL";

	rlutil::locate(1, 3);
	cout << char(218);
	for (int i = 0; i < 78; i++)
	{
		rlutil::locate(2 + i, 3);
		cout << char(196);
		rlutil::locate(2 + i, 5);
		cout << char(196);
	}
	rlutil::locate(79, 3);
	cout << char(191);

	rlutil::locate(1, 4);
	cout << char(179);
	rlutil::locate(6, 4);
	cout << char(179);
	rlutil::locate(21, 4);
	cout << char(179);
	rlutil::locate(37, 4);
	cout << char(179);
	rlutil::locate(50, 4);
	cout << char(179);
	rlutil::locate(70, 4);
	cout << char(179);
	rlutil::locate(79, 4);
	cout << char(179);


	rlutil::locate(6, 3);
	cout << char(194);
	rlutil::locate(21, 3);
	cout << char(194);
	rlutil::locate(37, 3);
	cout << char(194);
	rlutil::locate(50, 3);
	cout << char(194);
	rlutil::locate(70, 3);
	cout << char(194);


	int corrimiento = 0;

    AlquilerArchivo archivo;

    int cant = archivo.getCantidadRegistros();
    if (cant == 0)
	{
		noHayRegistrosReporteEmpleados();
		system("pause");
		return;
	}

    ClienteArchivo archivo2;

    int cant2 = archivo2.getCantidadRegistros();

    Cliente obj;
    Alquiler obj2;

    float recaudacion = 0;
    for (int i = 1; i <= cant2; i++)
    {
        obj = archivo2.buscar(i);
        rlutil::locate(1, 5 + corrimiento * 2 );
		cout << char(195);
		rlutil::locate(79, 5 + corrimiento * 2);
		cout << char(180);

		rlutil::locate(1, 6 + corrimiento * 2 );
		cout << char(179);
		rlutil::locate(79, 6 + corrimiento * 2 );
		cout << char(179);

		rlutil::locate(6, 5 + corrimiento * 2 );
		cout << char(197);
		rlutil::locate(21, 5 + corrimiento * 2 );
		cout << char(197);
		rlutil::locate(37, 5 + corrimiento * 2);
		cout << char(197);
		rlutil::locate(50, 5 + corrimiento * 2 );
		cout << char(197);
		rlutil::locate(70, 5 + corrimiento * 2 );
		cout << char(197);

        rlutil::setColor(rlutil::LIGHTGREEN);

		rlutil::locate(2, 6 + corrimiento * 2 );
		cout << setw(4) << obj.getId();
		rlutil::locate(7, 6 + corrimiento * 2 );
		cout << setw(13) << obj.getNombre();
		rlutil::locate(22, 6 + corrimiento * 2 );
		cout << setw(14) << obj.getApellido();
		rlutil::locate(38, 6 + corrimiento * 2);
		if (cant > 0 )
        {
            for (int j = 1; j <= cant; j++)
            {
                obj2 = archivo.buscar(j);
                if (obj.getId() == obj2.getClienteId())
                {
                    recaudacion += obj2.getPrecio();
                }
            }
        }

        cout << setw(11) << obj.getDni();
		rlutil::locate(52, 6 + corrimiento * 2 );
		cout << setw(2) << obj.getMail();
		rlutil::locate(71, 6 + corrimiento * 2 );
		cout << setw(8) << recaudacion;

        rlutil::setColor(rlutil::WHITE);

		rlutil::locate(1, 6 + corrimiento * 2);
		cout << char(179);
		rlutil::locate(6, 6 + corrimiento * 2 );
		cout << char(179);
		rlutil::locate(21, 6 + corrimiento * 2 );
		cout << char(179);
		rlutil::locate(37, 6 + corrimiento * 2);
		cout << char(179);
		rlutil::locate(50, 6 + corrimiento * 2 );
		cout << char(179);
		rlutil::locate(70, 6 + corrimiento * 2 );
		cout << char(179);



		for (int j = 0; j < 78; j++)
		{
			rlutil::locate(2 + j, 7 + corrimiento * 2 );
			cout << char(196);
		}
		rlutil::locate(1, 7 + corrimiento * 2);
		cout << char(192);
		rlutil::locate(79, 7 + corrimiento * 2);
		cout << char(217);

		rlutil::locate(6, 7 + corrimiento * 2 );
		cout << char(193);
		rlutil::locate(21, 7 + corrimiento * 2 );
		cout << char(193);
		rlutil::locate(37, 7 + corrimiento * 2);
		cout << char(193);
		rlutil::locate(50, 7 + corrimiento * 2 );
		cout << char(193);
		rlutil::locate(70, 7 + corrimiento * 2 );
		cout << char(193);

		corrimiento++;
    }

    rlutil::locate(1, corrimiento * 2 + 8);
	system("pause");
}

void ReportesController::reportePorAuto()
{
    rlutil::cls();
	bool errores = false;
    int diaDesde, mesDesde, anioDesde, diaHasta, mesHasta, anioHasta;
    Fecha fechaDesde, fechaHasta;
    rlutil::locate(30, 1);
	cout << "RECAUDACI" << char(224) << "N POR AUTO";
    do
	{
		rlutil::locate(3, 2);
		cout << "FECHA DESDE: D" << char(214) << "A:    MES:    A" << char(165) << "O: ";
		rlutil::locate(21, 2);
		diaDesde = Funciones().inputNumero(21,2,3);
		rlutil::locate(29, 2);
		mesDesde = Funciones().inputNumero(29,2,3);
		rlutil::locate(37, 2);
		anioDesde = Funciones().inputNumero(37,2,5);

		fechaDesde = Fecha(diaDesde,mesDesde,anioDesde);

		if(fechaDesde.getAnio() != anioDesde || fechaDesde.getMes() != mesDesde || fechaDesde.getDia() != diaDesde)
		{
			rlutil::locate(20, 2);
			cout << "                                                                  ";
			rlutil::locate(21, 2);
			rlutil::setColor(rlutil::LIGHTRED);
			cout << "FECHA INV"<< char(181) <<"LIDA";
			rlutil::setColor(rlutil::WHITE);
			errores = true;
			rlutil::anykey();
			rlutil::locate(20, 2);
			cout << "                                                                  ";
		}

		else
			errores = false;
	} while (errores);

    do
	{
		rlutil::locate(62, 2);
		cout << "                                                                  ";
		rlutil::locate(43, 2);
		cout << "FECHA HASTA: D" << char(214) << "A:    MES:    A" << char(165) << "O: ";
		rlutil::locate(62, 2);
		diaHasta = Funciones().inputNumero(61,2,3);
		rlutil::locate(70, 2);
		mesHasta = Funciones().inputNumero(69,2,3);
		rlutil::locate(78, 2);
		anioHasta = Funciones().inputNumero(77,2,4);
		if(diaHasta == 0 && mesHasta == 0 && anioHasta == 0) return;

		fechaHasta = Fecha(diaHasta,mesHasta,anioHasta);
		if(fechaHasta.getAnio() != anioHasta || fechaHasta.getMes() != mesHasta || fechaHasta.getDia() != diaHasta)
		{
			rlutil::locate(62, 2);
			cout << "                                                                  ";
			rlutil::locate(62, 2);
			rlutil::setColor(rlutil::LIGHTRED);
			cout << "FECHA INV"<< char(181) <<"LIDA";
			rlutil::setColor(rlutil::WHITE);
			errores = true;
			rlutil::anykey();
		}
		else if(Fecha().fechasInvalidas(fechaDesde, fechaHasta))
		{
			rlutil::locate(62, 2);
			cout << "                                                                  ";
			rlutil::locate(62, 2);
			rlutil::setColor(rlutil::LIGHTRED);
			cout << "\"FECHA DESDE\" MAYOR A \"FECHA HASTA\"";
			rlutil::setColor(rlutil::WHITE);
			errores = true;
			rlutil::anykey();
		}
		else
			errores = false;
	} while (errores);


	rlutil::locate(3, 4);
	cout << "ID";
	rlutil::locate(8, 4);
	cout << "MARCA";
	rlutil::locate(23, 4);
	cout << "MODELO";
	rlutil::locate(36, 4);
	cout << "PATENTE";
	rlutil::locate(49, 4);
	cout << "ALQUILERES";
	rlutil::locate(62, 4);
	cout << "D"<< char(214) <<"AS";
	rlutil::locate(69, 4);
	cout << "RECAUDADO";

	rlutil::locate(1, 3);
	cout << char(218);
	for (int i = 0; i < 78; i++)
	{
		rlutil::locate(2 + i, 3);
		cout << char(196);
		rlutil::locate(2 + i, 5);
		cout << char(196);
	}
	rlutil::locate(79, 3);
	cout << char(191);

	rlutil::locate(1, 4);
	cout << char(179);
	rlutil::locate(6, 4);
	cout << char(179);
	rlutil::locate(21, 4);
	cout << char(179);
	rlutil::locate(34, 4);
	cout << char(179);
	rlutil::locate(47, 4);
	cout << char(179);
	rlutil::locate(60, 4);
	cout << char(179);
	rlutil::locate(67, 4);
	cout << char(179);
	rlutil::locate(79, 4);
	cout << char(179);


	rlutil::locate(6, 3);
	cout << char(194);
	rlutil::locate(21, 3);
	cout << char(194);
	rlutil::locate(34, 3);
	cout << char(194);
	rlutil::locate(47, 3);
	cout << char(194);
	rlutil::locate(60, 3);
	cout << char(194);
	rlutil::locate(67, 3);
	cout << char(194);


	Auto aut;
	AutoArchivo autoArchivo;
	Alquiler alquiler;
	int corrimiento = 0;
	int cantAutos = autoArchivo.getCantidadRegistros();
	if (cantAutos == 0)
	{
		noHayRegistrosReporteAutos();
		system("pause");
		return;
	}

	AlquilerArchivo alquilerArchivo;
	int cantAlquileres = alquilerArchivo.getCantidadRegistros();
	for (int i = 1; i <= cantAutos; i++)
	{
		aut = autoArchivo.buscar(i);

		if (aut.getEliminado() == 0 && aut.getEstado())
		{
			rlutil::locate(1, 5 + corrimiento * 2);
			cout << char(195);
			rlutil::locate(79, 5 + corrimiento * 2);
			cout << char(180);

			rlutil::locate(1, 6 + corrimiento * 2);
			cout << char(179);
			rlutil::locate(79, 6 + corrimiento * 2);
			cout << char(179);

			rlutil::locate(6, 5 + corrimiento * 2);
			cout << char(197);
			rlutil::locate(21, 5 + corrimiento * 2);
			cout << char(197);
			rlutil::locate(34, 5 + corrimiento * 2);
			cout << char(197);
			rlutil::locate(47, 5 + corrimiento * 2);
			cout << char(197);
			rlutil::locate(60, 5 + corrimiento * 2);
			cout << char(197);
			rlutil::locate(67, 5 + corrimiento * 2);
			cout << char(197);

			switch (aut.getEstado())
			{
			case AutoEstado::Disponible:
				rlutil::setColor(rlutil::LIGHTGREEN);
				break;
			case AutoEstado::Reservado:
				rlutil::setColor(rlutil::YELLOW);
				break;
			case AutoEstado::FueraDeServicio:
				rlutil::setColor(rlutil::LIGHTRED);
				break;
			default:
				break;
			}

			rlutil::locate(2, 6 + corrimiento * 2);
			cout << setw(4) << aut.getId();
			rlutil::locate(7, 6 + corrimiento * 2);
			cout << setw(13) << aut.getMarca();
			rlutil::locate(22, 6 + corrimiento * 2);
			cout << setw(11) << aut.getModelo();
			rlutil::locate(35, 6 + corrimiento * 2);
			cout << setw(11) << aut.getPatente();

			int alquileres = 0;
			int dias = 0;
			float total = 0;

			if (cantAlquileres > 0)
			{
				for (int j = 1; j <= cantAlquileres; j++)
				{
					alquiler = alquilerArchivo.buscar(j);
					if (alquiler.getAutoId() == aut.getId() && alquiler.getEstado() != AlquilerEstado::Vigente &&
                    (( fechaHasta >= alquiler.getFechaDesde() && alquiler.getFechaDesde() >= fechaDesde) || (fechaDesde <= alquiler.getFechaHasta() && alquiler.getFechaHasta() <= fechaHasta)))
					{
						alquileres++;
						total += alquiler.getPrecio();
						dias += Fecha().diferenciaDias(alquiler.getFechaDesde(), alquiler.getFechaHasta()) + 1;
					}
				}
			}

			rlutil::locate(48, 6 + corrimiento * 2);
			cout << setw(11) << alquileres;
			rlutil::locate(61, 6 + corrimiento * 2);
			cout << setw(5) << dias;
			rlutil::locate(68, 6 + corrimiento * 2);
			cout << setw(10) << total;
			rlutil::setColor(rlutil::WHITE);


			rlutil::locate(1, 6 + corrimiento * 2);
			cout << char(179);
			rlutil::locate(6, 6 + corrimiento * 2);
			cout << char(179);
			rlutil::locate(21, 6 + corrimiento * 2);
			cout << char(179);
			rlutil::locate(34, 6 + corrimiento * 2);
			cout << char(179);
			rlutil::locate(47, 6 + corrimiento * 2);
			cout << char(179);
			rlutil::locate(60, 6 + corrimiento * 2);
			cout << char(179);
			rlutil::locate(67, 6 + corrimiento * 2);
			cout << char(179);



			for (int j = 0; j < 78; j++)
			{
				rlutil::locate(2 + j, 7 + corrimiento * 2);
				cout << char(196);
			}
			rlutil::locate(1, 7 + corrimiento * 2);
			cout << char(192);
			rlutil::locate(79, 7 + corrimiento * 2);
			cout << char(217);

			rlutil::locate(6, 7 + corrimiento * 2);
			cout << char(193);
			rlutil::locate(21, 7 + corrimiento * 2);
			cout << char(193);
			rlutil::locate(34, 7 + corrimiento * 2);
			cout << char(193);
			rlutil::locate(47, 7 + corrimiento * 2);
			cout << char(193);
			rlutil::locate(60, 7 + corrimiento * 2);
			cout << char(193);
			rlutil::locate(67, 7 + corrimiento * 2);
			cout << char(193);

			corrimiento++;
		}
	}

	rlutil::locate(1, corrimiento * 2 + 8);
    system("pause");
}

void ReportesController::listarHeader()
{
    rlutil::locate(2, 2);
    cout << "ID";
    rlutil::locate(7, 2);
    cout << "PATENTE";
    rlutil::locate(22, 2);
    cout << "MODELO";
    rlutil::locate(22, 2);
    cout << "RECAUDACI" << char(224) << "N";
    rlutil::locate(22, 2);
    cout << "ALQUILERES";

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

void ReportesController::noHayRegistrosReporteAutos()
{
	rlutil::locate(30, 7);
	cout << "No hay registros cargados.";

	rlutil::locate(6, 5);
	cout << char(193);
	rlutil::locate(21, 5);
	cout << char(193);
	rlutil::locate(34, 5);
	cout << char(193);
	rlutil::locate(47, 5);
	cout << char(193);
	rlutil::locate(60, 5);
	cout << char(193);
	rlutil::locate(67, 5);
	cout << char(193);


	rlutil::locate(1, 8);
	cout << char(192);
	rlutil::locate(1, 6);
	cout << char(179);
	rlutil::locate(1, 7);
	cout << char(179);
	rlutil::locate(79, 6);
	cout << char(179);
	rlutil::locate(79, 7);
	cout << char(179);
	rlutil::locate(79, 8);
	cout << char(217);

	rlutil::locate(1, 5);
	cout << char(195);

	rlutil::locate(79, 5);
	cout << char(180);
	for (int i = 0; i < 77; i++)
	{
		rlutil::locate(2 + i, 8);
		cout << char(196);
	}

	cout << endl;
}

void ReportesController::noHayRegistrosReporteEmpleados()
{
    rlutil::locate(30, 7);
	cout << "No hay registros cargados.";

	rlutil::locate(6, 5);
	cout << char(193);
	rlutil::locate(21, 5);
	cout << char(193);
	rlutil::locate(37, 5);
	cout << char(193);
	rlutil::locate(50, 5);
	cout << char(193);
	rlutil::locate(70, 5);
	cout << char(193);


	rlutil::locate(1, 8);
	cout << char(192);
	rlutil::locate(1, 6);
	cout << char(179);
	rlutil::locate(1, 7);
	cout << char(179);
	rlutil::locate(79, 6);
	cout << char(179);
	rlutil::locate(79, 7);
	cout << char(179);
	rlutil::locate(79, 8);
	cout << char(217);

	rlutil::locate(1, 5);
	cout << char(195);

	rlutil::locate(79, 5);
	cout << char(180);
	for (int i = 0; i < 77; i++)
	{
		rlutil::locate(2 + i, 8);
		cout << char(196);
	}

	cout << endl;
}
