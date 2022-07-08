#include "Empleado.h"

int Empleado::getID()
{
    return ID;
}

void Empleado::setID(int ID)
{
    this->ID = ID;
}

int Empleado::getCategoria()
{
    return categoria;
}

void Empleado::setCategoria(int categoria)
{
    this->categoria = categoria;
}

char Empleado::getTurno()
{
    return turno;
}

void Empleado::setTurno(char turno)
{
    this->turno = turno;
}

FechaHora Empleado::getFechaDeIngreso()
{
    return fechaDeIngreso;
}

void Empleado::setFechaDeIngreso(FechaHora fechaDeIngreso)
{
    this->fechaDeIngreso = fechaDeIngreso;
}

char Empleado::getTipoJornada()
{
    return tipoJornada;
}

void Empleado::setTipoJornada(char tipoJornada)
{
    this->tipoJornada = tipoJornada;
}

float Empleado::getSueldo()
{
    return sueldo;
}

void Empleado::setSueldo(float sueldo)
{
    this->sueldo = sueldo;
}

Empleado::Empleado() {
	int pos = 0;
    categoria = 0;
    tipoJornada = '-';
    turno = '-';
    sueldo = 0;
	ID = contEmpleados() + 1;
}

void Empleado::cargar() {
	Persona::cargar();
	do
	{
		std::cout << "Categoria (1-Gerente/2-Cajero/3-Vendedor/4-Auxiliar de Limpieza): ";
		std::cin >> categoria;
		if (categoria < 1 || categoria>4)
		{
			rlutil::cls();
			std::cout << "Error. Por favor ingrese un valor válido." << std::endl;
			rlutil::anykey();
			rlutil::cls();
		}
	} while (categoria < 1 || categoria>4);
	std::cout << "Fecha de ingreso:\n";
	fechaDeIngreso.cargarFecha();
	do
	{
		std::cout << "Tipo de jornada(f-Full-time/p-Part-time): ";
		std::cin >> tipoJornada;
		if (tolower(tipoJornada) != 'f' && tolower(tipoJornada) != 'p')
		{
			rlutil::cls();
			std::cout << "Error. Por favor ingrese un valor válido." << std::endl;
			rlutil::anykey();
			rlutil::cls();
		}
	} while (tolower(tipoJornada) != 'f' && tolower(tipoJornada) != 'p');
	do {
		std::cout << "Turno (M-Mañana/T-Tarde/N-Noche): ";
		std::cin >> turno;
		if (tolower(turno) != 'm' && tolower(turno) != 't' && tolower(turno) != 'n')
		{
			rlutil::cls();
			std::cout << "Error. Por favor ingrese un valor válido." << std::endl;
			rlutil::anykey();
			rlutil::cls();
		}
	} while (tolower(turno) != 'm' && tolower(turno) != 't' && tolower(turno) != 'n');
	do {
		std::cout << "Sueldo: ";
		std::cin >> sueldo;
		if (sueldo<=0)
		{
			rlutil::cls();
			std::cout << "Error. Por favor ingrese un sueldo válido." << std::endl;
			rlutil::anykey();
			rlutil::cls();
		}
	} while (sueldo<=0);
	if (grabarEnDisco())
	{
		system("cls");
		std::cout << "Empleado guardado con exito." << std::endl;
		system("pause");
		system("cls");
	}
}

void Empleado::mostrar() {
    if (estado)
    {
        Persona::mostrar();
        std::cout << "ID: " << ID << std::endl;
        std::cout << "Categoria: " << categoria << std::endl;
        std::cout << "Fecha de ingreso:\n";
        fechaDeIngreso.mostrarFecha();
        std::cout << std::endl << "Tipo de jornada: ";
        if (tolower(tipoJornada) == 'p')
        {
            std::cout << "Part-time";
        }
        else
        {
            std::cout << "Full-time";
        }
        std::cout << std::endl << "Turno: ";
        switch (tolower(turno))
        {
        case 'm':
            std::cout << "Mañana";
            break;
        case 't':
            std::cout << "Tarde";
            break;
        default:
            std::cout << "Noche";
            break;
        }
        std::cout << std::endl << "Sueldo: $" << sueldo << std::endl;
    }
}

bool Empleado::grabarEnDisco() {
    FILE* p = NULL;
    p = fopen("empleados.dat", "ab");
    if (p == NULL)
    {
        std::cout << "Error al guardar.\n";
        system("pause");
        return 0;
    }
    fwrite(this, sizeof(Empleado), 1, p);
    fclose(p);
    return 1;
}
bool Empleado::leerDeDisco(int pos) {
    FILE* p = NULL;
    p = fopen("empleados.dat", "rb");
    if (p == NULL)
    {
        std::cout << "Error al abrir.\n";
        system("pause");
        return false;
    }
    fseek(p, pos * sizeof(Empleado), 0);
    fread(this, sizeof(Empleado), 1, p);
    fclose(p);
    return true;
}

int Empleado::contEmpleados()
{
    FILE* p;
	int pos = 0;
    p = fopen("empleados.dat", "rb");
    if (p == NULL) {
        return 0;
    }
	fclose(p);
	return ID;
}
int Empleado::contRegistros()
{
	FILE* p = fopen("empleados.dat", "rb");
	if (p == NULL) {
		return 0; ///cantidad de registros cero 0
	}
	size_t bytes;
	int cant_reg;

	fseek(p, 0, SEEK_END);
	bytes = ftell(p);
	fclose(p);
	cant_reg = bytes / sizeof(Empleado);
	return cant_reg;
}

void Empleado::modificarEmpleado() {
	int opcion, ingreso;
	FechaHora nuevaFecha;
	std::string palabra;
	do
	{
		std::cout << "¿Qué desea modificar?" << std::endl << std::endl;
		std::cout << "1-DNI" << std::endl;
		std::cout << "2-Fecha de nacimiento" << std::endl;
		std::cout << "3-Nombre" << std::endl;
		std::cout << "4-Apellido" << std::endl;
		std::cout << "5-Categoría" << std::endl;
		std::cout << "6-Tipo de jornada" << std::endl;
		std::cout << "7-Turno" << std::endl;
		std::cout << "8-Sueldo" << std::endl;
		std::cout << "-------------------" << std::endl;
		std::cout << "------------------" << std::endl;
		std::cout << "0-Volver" << std::endl << std::endl;
		std::cout << "Ingrese una opción: ";
		std::cin >> opcion;
		rlutil::cls();
		switch (opcion)
		{
		case 1:
			std::cout << "Ingrese un nuevo DNI: ";
			std::cin >> dni;
			rlutil::cls();
			std::cout << "DNI modificado con exito." << std::endl;
			break;
		case 2:
			std::cout << "Ingrese nueva fecha de nacimiento:" << std::endl;
			nuevaFecha.cargarFecha();
			setFechaDeNacimiento(nuevaFecha);
			rlutil::cls();
			std::cout << "Fecha de nacimiento modificada con exito." << std::endl;
			break;
		case 3:
			std::cout << "Ingrese el nombre nuevo: ";
			std::cin.ignore();
			std::getline(std::cin, palabra);
			setNombre(palabra);
			rlutil::cls();
			std::cout << "Nombre modificado con exito." << std::endl;
			break;
		case 4:
			std::cout << "Ingrese el apellido nuevo: ";
			std::cin.ignore();
			std::getline(std::cin, palabra);
			setApellido(palabra);
			rlutil::cls();
			std::cout << "Apellido modificado con exito." << std::endl;
			break;
		case 5:
			std::cout << "Ingrese la categoría nueva: " << std::endl;
			std::cin >> categoria;
			rlutil::cls();
			std::cout << "Categoría modificada con exito." << std::endl;
			break;
		case 6:
			std::cout << "Ingrese el nuevo tipo de jornada (p-Part time/f-Full time): " << std::endl;
			std::cin >> tipoJornada;
			rlutil::cls();
			std::cout << "Tipo de jornada modificada con exito." << std::endl;
			break;
		case 7:
			std::cout << "Ingrese el nuevo turno (m-Mañana/t-Tarde/n-Noche): " << std::endl;
			std::cin >> turno;
			rlutil::cls();
			std::cout << "Turno modificado con exito." << std::endl;
			break;
		case 8:
			std::cout << "Ingrese el nuevo sueldo: " << std::endl;
			std::cin >> sueldo;
			rlutil::cls();
			std::cout << "Sueldo modificado con exito." << std::endl;
			break;
		default:
			if (opcion != 0)
			{
				std::cout << "Por favor ingrese una opción correcta.";
			}
			break;
		}
		if (opcion != 0)rlutil::anykey();
	} while (opcion != 0);
}

void Empleado::eliminarEmpleado() {
	bool bandera = false;
	int ingreso, pos;
	do
	{
		pos = 0;
		std::cout << "Ingrese el ID del empleado que va a eliminar o presione 0 para volver para atras: ";
		std::cin >> ingreso;
		if (ingreso != 0)
		{
			while (leerDeDisco(pos++) && !bandera)
			{
				if (ID == ingreso)
				{
					estado = false;
					bandera = true;
					rlutil::cls();
					std::cout << "Empleado eliminado con exito." << std::endl;
					rlutil::anykey();
				}
			}
			ingreso = 0;
		}
		if (ingreso != 0 && !bandera)
		{
			rlutil::cls();
			std::cout << "Error. No se ha podido encontrar el empleado. Por favor ingrese nuevamente el ID." << std::endl;
			rlutil::anykey();
		}
		rlutil::cls();
	} while (ingreso != 0);
}

void Empleado::listarEmpleado() {
	int opcion, d, pos;
	bool bandera = false;
	do
	{
		pos = 0;
		std::cout << "1-Listar todos los empleados" << std::endl;
		std::cout << "2-Listar un empleado" << std::endl;
		std::cout << "-------------------" << std::endl;
		std::cout << "------------------" << std::endl;
		std::cout << "0-Volver" << std::endl << std::endl;
		std::cout << "Ingrese una opción: ";
		std::cin >> opcion;
		rlutil::cls();
		switch (opcion)
		{
		case 1:
			for (int i = 0; i < contRegistros(); i++)
			{
				leerDeDisco(i);
				mostrar();
				std::cout << std::endl << std::endl;
			}
			break;
		case 2:
			std::cout << "Ingrese el ID del empleado que quiere listar: ";
			std::cin >> d;
			rlutil::cls();
			while (leerDeDisco(pos++) && !bandera)
			{
				if (d == ID)
				{
					mostrar();
					bandera = true;
				}
			}
			if (!bandera)std::cout << "No se ha podido encontrar el empleado." << std::endl;
			break;
		default:
			if (opcion != 0)
			{
				std::cout << "Por favor ingrese una opción correcta.";
			}
			break;
		}
		bandera = false;
		if (opcion != 0)rlutil::anykey();
		rlutil::cls();
	} while (opcion != 0);
}
