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

void Empleado::cargar() {
	Persona::cargar();
	do
	{
		std::cout << "Categoria\t\t1-Gerente\t2-Cajero/a\t3-Vendedor/a\t4-Auxiliar de Limpieza" << std::endl <<'>';
		
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
	ID = contRegistros()+1;
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
        std::cout << "ID: " << ID << std::endl;
        Persona::mostrar();
        std::cout << "Categoria: ";
		switch (categoria)
		{
		case 1:
			std::cout << "1-Gerente" << std::endl;
			break;
		case 2:
			std::cout << "2-Cajero/a" << std::endl;
			break;
		case 3:
			std::cout << "3-Vendedor/a" << std::endl;
			break;
		default:
			std::cout << "4-Auxiliar de Limpieza" << std::endl;
			break;
		}
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

bool Empleado::leerDeDisco(int n) {
    FILE* p = NULL;
    p = fopen("empleados.dat", "rb");
    if (p == NULL)
    {
        std::cout << "Error al abrir.\n";
        system("pause");
        return false;
    }
    fseek(p, n * sizeof(Empleado), 0);
    int leyo=fread(this, sizeof(Empleado), 1, p);
    fclose(p);
    return leyo;
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
	int opcion, ingreso, id, nReg;
	bool ingresoCorrecto = true;
	FechaHora nuevaFecha;
	std::string palabra;
	bool bandera = false;
	do {
		std::cout << "Ingrese el ID del empleado a modificar o 0 para volver: ";
		std::cin >> id;
		nReg = buscarRegistro(id);
		if (nReg > 0)
		{
			do
			{
				mostrar();
				std::cout << std::endl << std::endl;
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
					break;
				case 2:
					std::cout << "Ingrese nueva fecha de nacimiento:" << std::endl;
					nuevaFecha.cargarFecha();
					setFechaDeNacimiento(nuevaFecha);
					break;
				case 3:
					std::cout << "Ingrese el nombre nuevo: ";
					std::cin.ignore();
					std::getline(std::cin, palabra);
					setNombre(palabra);
					break;
				case 4:
					std::cout << "Ingrese el apellido nuevo: ";
					std::cin.ignore();
					std::getline(std::cin, palabra);
					setApellido(palabra);
					break;
				case 5:
					do
					{
						std::cout << "Ingrese la categoría nueva: " << std::endl;
						std::cout << "Categoria\t\t1-Gerente\t2-Cajero/a\t3-Vendedor/a\t4-Auxiliar de Limpieza" << std::endl << '>';
						std::cin >> categoria;
						if (categoria < 1 || categoria>4) {
							rlutil::cls();
							std::cout << std::endl << std::endl << "Por favor ingrese una opción válida.";
							rlutil::anykey();
						}
						rlutil::cls();
					} while (categoria < 1 || categoria>4);
					break;
				case 6:
					do {
						std::cout << "Ingrese el nuevo tipo de jornada (p-Part time/f-Full time): " << std::endl;
						std::cin >> tipoJornada;
						rlutil::cls();
						if (tolower(tipoJornada) != 'p' && tolower(tipoJornada) != 'f')
						{
							std::cout << "Por favor ingrese una opción válida.";
							rlutil::anykey();
							rlutil::cls();
						}
					} while (tolower(tipoJornada) != 'p' && tolower(tipoJornada) != 'f');
					break;
				case 7:
					do
					{
						std::cout << "Ingrese el nuevo turno (m-Mañana/t-Tarde/n-Noche): " << std::endl;
						std::cin >> turno;
						rlutil::cls();
						if (tolower(turno) != 'm' && tolower(turno) != 't' && tolower(turno) != 'n')
						{
							std::cout << "Por favor ingrese una opción válida.";
							rlutil::anykey();
							rlutil::cls();
						}
					} while (tolower(turno) != 'm' && tolower(turno) != 't' && tolower(turno) != 'n');
					break;
				case 8:
					std::cout << "Ingrese el nuevo sueldo: " << std::endl;
					std::cin >> sueldo;
					break;
				default:
					if (opcion != 0)
					{
						std::cout << "Por favor ingrese una opción correcta.";
						rlutil::anykey();
					}
					break;
				}
				if (opcion != 0) {
					do
					{
						rlutil::cls();
						std::cout << "¿Seguro de realizar la modificación? 1-Sí/2-Cancelar" << std::endl << '>';
						std::cin >> ingreso;
						if (ingreso<1||ingreso>2)
						{
							rlutil::cls();
							std::cout << "Por favor ingrese una opción válida.";
							rlutil::anykey();
						}
					} while (ingreso<1||ingreso>2);
					if (ingreso == 1) {
						if (modificarEnDisco(nReg - 1)) std::cout << "Modificación realizada con éxito.";
						else std::cout << "Error al modificar.";
						rlutil::anykey();
					}
				}
				rlutil::cls();
			} while (opcion != 0);
		}
		else if (id != 0)
		{
			std::cout << "Error. No se ha encontrado el empleado.";
			rlutil::anykey();
		}
		rlutil::cls();
	} while (id != 0);
}

void Empleado::eliminarEmpleado() {
	/*
	FILE* p;
	int escribio;
	int id;
	bool bandera = false;
	p = fopen("empleados.dat", "rb+");
	if (p == NULL)
	{
		std::cout << "Error de archivo";
		return -1;
	}
	std::cout << "Ingrese el ID del empleado a eliminar o presione 0 para volver atras: ";
	std::cin >> id;
	if (id != 0) {
		while (fread(this, sizeof(Empleado), 1, p) == 1)
		{
			if (id == ID)
			{
				estado = false;
				// se cambia el valor del campo estado
				fseek(p, ftell(p) - sizeof(Empleado), 0);
				//desplazamiento de part un registro hacia atrás
				escribio = fwrite(this, sizeof(Empleado), 1, p);
				// escritura del registro modificado
				fclose(p);
				return escribio;

			}
		}
		fclose(p);
		std::cout << "Error. No se ha podido encontrar al empleado.";
	}
	return -2;
	*/
	/*
	bool bandera = false;
	int ingreso, pos, reg;
	do
	{
		pos = 0;
		std::cout << "Ingrese el ID del empleado que va a eliminar o presione 0 para volver para atras: ";
		std::cin >> ingreso;
		if (ingreso != 0) {
			 {
				while (leerDeDisco(pos++) && !bandera)
				{
					if (ID == ingreso)
					{
						reg = buscarRegistro(ID-1);
						estado = false;
						bandera = true;
						rlutil::cls();
						if (modificarEnDisco(reg-1)) std::cout << "Empleado eliminado con exito." << std::endl;
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
			} //
			reg = buscarRegistro(ingreso);
			if (reg==-1) std::cout << "No se ha encontrado el empleado.";
			else {
				leerDeDisco(reg);
				if (estado == false) std::cout << "No se ha encontrado el empleado.";
				else
				{
					estado = false;
					rlutil::cls();
					std::cout << "Empleado eliminado con exito.";
					modificarEnDisco(reg);
				}
			}
		}
		if(ingreso!=0)rlutil::anykey();
		rlutil::cls();
		*/
	int d, confirmar, reg;
	do {
		std::cout << "Ingrese el ID del empleado que quiere eliminar o 0 para volver: ";
		std::cin >> d;
		reg = buscarRegistro(d);
		rlutil::cls();
		if (reg < 0) std::cout << "No se ha podido encontrar el empleado.";
		else
		{
			if (estado) {
				rlutil::cls();
				mostrar();
				std::cout << std::endl << std::endl << "¿Seguro de eliminar empleado? Presione 1 para eliminar/2 para cancelar:" << std::endl;
				std::cin >> confirmar;
				rlutil::cls();
				if (confirmar == 1)
				{
					estado = false;
					if (modificarEnDisco(reg-1)) std::cout << "Eliminado con exito.";
					else std::cout << "Error al eliminar.";
				}
				else if (confirmar!=2) std::cout << "Por favor ingrese una opción válida.";
			}
			else std::cout << "No se ha podido encontrar el empleado.";
		}
		if (d != 0) rlutil::anykey();
		rlutil::cls();
	} while (d != 0);
}

void Empleado::listarEmpleado() {
	int opcion, d, pos, numeroReg;
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
			while (leerDeDisco(pos++))
			{
				mostrar();
				if(estado)std::cout << std::endl << std::endl;
			}
			break;
		case 2:
			std::cout << "Ingrese el ID del empleado que quiere listar o 0 para volver: ";
			std::cin >> d;
			rlutil::cls();
			if (d != 0)
			{
				if (buscarRegistro(d) < 0) std::cout << "No se ha podido encontrar el empleado.";
				else
				{
					if (estado) {
						bandera = true;
						mostrar();
						//std::cout << std::endl << std::endl << "pos: " << reg;
					}
					else std::cout << "No se ha podido encontrar el empleado.";
				}
				/*
				while (leerDeDisco(pos++) && !bandera) {
					if (d == ID && estado)
					{
						mostrar();
						bandera = true;
						std::cout << std::endl << std::endl << "pos: " << pos;
					}
				} */
				if (!bandera)std::cout << "No se ha podido encontrar el empleado." << std::endl;
			}
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

bool Empleado::modificarEnDisco(int pos) {
	FILE* p = NULL;
	p = fopen("empleados.dat", "rb+");
	if (p == NULL)return 0;
	fseek(p, pos * sizeof(Empleado), 0);
	bool escribio=fwrite(this, sizeof(Empleado), 1, p);
	fclose(p);
	return escribio;
}

int Empleado::buscarRegistro(int id) {
	int pos = 0;
	while (leerDeDisco(pos++))
	{

		if (id == ID) return pos;

	}

	return -1;
}
