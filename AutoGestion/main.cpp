#include <iostream>

using namespace std;

int main()
{
	int option = 1;
	cout << "Bienvenido" << endl;

	while (option != 0)
	{
		cout << "1 _ AUTOS" << endl;
		cout << "2 _ EMPLEADOS" << endl;
		cout << "3 _ ALQUILERES" << endl;
		cout << "0 _ SALIR" << endl;
		cin >> option;

		switch (option)
		{
			case 1:
				system("cls");
				cout << "AUTOS" << endl;
				system("pause");
				system("cls");
				break;
			case 2:
				system("cls");
				cout << "EMPLEADOS" << endl;
				system("pause");
				system("cls");
				break;
			case 3:
				system("cls");
				cout << "ALQUILERES";
				system("pause");
				system("cls");
				break;
			case 0:
				break;
		default:
			break;
		}
	}

	return 0;
}