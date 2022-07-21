#include "Cliente.h"

const char* Cliente::getMail() 
{
    return mail;
}

void Cliente::setMail(const char* mail)
{
	strcpy(this->mail, mail);
}

const char* Cliente::getNumerotarjeta()
{
    return Numerotarjeta;
}

void Cliente::setNumerotarjeta(const char* Numerotarjeta)
{
	strcpy(this->Numerotarjeta, Numerotarjeta);
}

Direccion Cliente::getDomicilio()
{
    return domicilio;
}

void Cliente::setDomicilio(Direccion domicilio)
{
    this->domicilio = domicilio;
}

void Cliente::cargar() {
	Persona::cargar();
	std::cout << "Numero de tarjeta (si no es necesario ingrese '-'): ";
	std::cin >> Numerotarjeta;
	std::cout << "Email: ";
	std::cin >> mail;
	domicilio.cargar();
	if (grabarEnDisco())
	{
		system("cls");
		std::cout << "Cliente guardado con exito." << std::endl;
		system("pause");
		system("cls");
	}
}

void Cliente::cargar(int _dni) {
	Persona::cargar(_dni);
	std::cout << "Numero de tarjeta (si no es necesario ingrese '-'): ";
	std::cin >> Numerotarjeta;
	std::cout << "Email: ";
	std::cin >> mail;
	domicilio.cargar();
	if (grabarEnDisco())
	{
		system("cls");
		std::cout << "Cliente guardado con exito." << std::endl;
		system("pause");
		system("cls");
	}
}

void Cliente::mostrar() {
	if (estado) {
		Persona::mostrar();
		std::cout << std::endl << mail;
	}
}

bool Cliente::grabarEnDisco() {
	FILE* p = NULL;
	p = fopen("clientes.dat", "ab");
	if (p==NULL)
	{
		std::cout << "Error al guardar.\n";
		system("pause");
		return 0;
	}
	fwrite(this, sizeof(Cliente), 1, p);
	fclose(p);
	return 1;
}

bool Cliente::leerDeDisco(int pos) {
	FILE* p = NULL;
	p = fopen("clientes.dat", "rb");
	if (p==NULL)
	{
		std::cout << "No hay registros.";
		rlutil::anykey();
		return 0;
	}
	fseek(p, pos * sizeof(Cliente), 0);
	bool leyo=fread(this, sizeof(Cliente), 1, p);
	fclose(p);
	return leyo;
}

int Cliente::contRegistros() {
	FILE* p = fopen("clientes.dat", "rb");
	if (p == NULL) {
		return 0; ///cantidad de registros cero 0
	}
	size_t bytes;
	int cant_reg;

	fseek(p, 0, SEEK_END);
	bytes = ftell(p);
	fclose(p);
	cant_reg = bytes / sizeof(Cliente);
	return cant_reg;
}

void Cliente::modificarCliente() {
	std::string palabra;
	int opcion, ingreso, d, nReg, entero;
	Direccion dom;
	FechaHora fec;
	char cad[50];
	bool ingresoCorrecto = true;
	do {
		std::cout << "Ingrese el DNI del cliente a modificar o 0 para volver: ";
		std::cin >> d;
		nReg = buscarRegistro(d);
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
				std::cout << "5-Email" << std::endl;
				std::cout << "6-Número de tarjeta" << std::endl;
				std::cout << "7-Domicilio" << std::endl;
				std::cout << "-------------------" << std::endl;
				std::cout << "-------------------" << std::endl;
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
					fechaDeNacimiento.cargarFecha();
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
					std::cout << "Ingrese el email nuevo: ";
					std::cin >> mail;
					break;
				case 6:
					std::cout << "Ingrese el Número de tarjeta nuevo: ";
					std::cin >> Numerotarjeta;
					break;
				case 7:
					std::cout << "Ingrese el domicilio nuevo:" << std::endl;
					domicilio.cargar();
					break;
				default:
					if (opcion != 0)
					{
						std::cout << "Por favor ingrese una opción correcta.";
						rlutil::anykey();
					}
					break;
				}
				if (opcion != 0)
				{
					if (modificarEnDisco(nReg - 1)) std::cout << "Modificación realizada con éxito.";
					else std::cout << "Error al modificar.";
					rlutil::anykey();
				}
				rlutil::cls();
			} while (opcion != 0);
		}
		else if (d != 0)
		{
			std::cout << "Error. No se ha encontrado el cliente.";
			rlutil::anykey();
		}
		rlutil::cls();
	} while (d != 0);
}

void Cliente::eliminarCliente() {
	int d, confirmar, reg;
	do {
		std::cout << "Ingrese el DNI del cliente que quiere eliminar o ingrese 0 para volver: ";
		std::cin >> d;
		reg = buscarRegistro(d);
		rlutil::cls();
		if (reg < 0) std::cout << "No se ha podido encontrar el cliente.";
		else
		{
			if (estado) {
				rlutil::cls();
				mostrar();
				std::cout << std::endl << std::endl << "¿Seguro de eliminar cliente? Presione 1 para eliminar/2 para cancelar:" << std::endl;
				std::cin >> confirmar;
				rlutil::cls();
				if (confirmar == 1)
				{
					estado = false;
					if (modificarEnDisco(reg - 1)) std::cout << "Eliminado con exito.";
					else std::cout << "Error al eliminar.";
				}
				else if (confirmar != 2) std::cout << "Por favor ingrese una opción válida.";
			}
			else std::cout << "No se ha podido encontrar el cliente.";
		}
		if (d != 0) rlutil::anykey();
		rlutil::cls();
	} while (d != 0);
}

void Cliente::listarCliente() {
	int opcion, d, pos, numeroReg;
	bool bandera = false;
	do
	{
		pos = 0;
		std::cout << "1-Listar todos los clientes" << std::endl;
		std::cout << "2-Listar un cliente" << std::endl;
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
				if (estado)std::cout << std::endl << std::endl;
			}
			break;
		case 2:
			std::cout << "Ingrese el DNI del cliente que quiere listar o 0 para volver: ";
			std::cin >> d;
			if (d != 0) {
				rlutil::cls();
				if (buscarRegistro(d) < 0) std::cout << "No se ha podido encontrar el cliente.";
				else
				{
					if (estado) {
						bandera = true;
						mostrar();
					}
					else std::cout << "No se ha podido encontrar el cliente.";
				}
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

bool Cliente::modificarEnDisco(int pos) {
	FILE* p = NULL;
	p = fopen("clientes.dat", "rb+");
	if (p == NULL)return 0;
	fseek(p, pos * sizeof(Cliente), 0);
	bool escribio=fwrite(this, sizeof(Cliente), 1, p);
	fclose(p);
	return escribio;
}

int Cliente::buscarRegistro(int d) {
	int pos = 0;
	while (leerDeDisco(pos++))
	{

		if (d == dni) return pos;

	}

	return -1;
}