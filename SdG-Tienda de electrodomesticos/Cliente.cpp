#include "Cliente.h"
Cliente::Cliente() {
	Numerotarjeta[0] = '0';
	strcpy(mail, "void@mail.com");
}
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

void Cliente::cargar() {
	Persona::cargar();
	std::cout << "Numero de tarjeta: ";
	std::cin >> Numerotarjeta;
	std::cout << "Email: ";
	std::cin >> mail;
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
	p = fopen("clientes.dat", "rb+");
	if (p==NULL)
	{
		std::cout << "Error al abrir.\n";
		system("pause");
		return 0;
	}
	fseek(p, pos * sizeof(Cliente), 0);
	fread(this, sizeof(Cliente), 1, p);
	fclose(p);
	return 1;
}

void Cliente::modificarCliente() {
	int opcion, ingreso;
	FechaHora nuevaFecha;
	std::string palabra;
	Direccion nuevoDom;
	char tarjeta[17];
	do
	{
		std::cout << "¿Qué desea modificar?" << std::endl << std::endl;
		std::cout << "1-DNI" << std::endl;
		std::cout << "2-Fecha de nacimiento" << std::endl;
		std::cout << "3-Nombre" << std::endl;
		std::cout << "4-Apellido" << std::endl;
		std::cout << "5-Domicilio" << std::endl;
		std::cout << "6-Numero de tarjeta" << std::endl;
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
			std::cout << "Ingrese el domicilio nuevo: " << std::endl;
			nuevoDom.cargar();
			setDomicilio(nuevoDom);
			rlutil::cls();
			std::cout << "Domicilio modificado con exito." << std::endl;
			break;
		case 6:
			std::cout << "Ingrese el nuevo numero de tarjeta: " << std::endl;
			std::cin >> tarjeta;
			setNumerotarjeta(tarjeta);
			rlutil::cls();
			std::cout << "Numero de tarjeta modificado con exito." << std::endl;
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
Direccion Cliente::getDomicilio() const
{
    return domicilio;
}

void Cliente::setDomicilio(Direccion domicilio)
{
    this->domicilio = domicilio;
}

void Cliente::eliminarCliente() {
	bool bandera = false;
	int ingreso, pos;
	do
	{
		pos = 0;
		std::cout << "Ingrese el DNI del cliente que va a eliminar o presione 0 para volver para atras: ";
		std::cin >> ingreso;
		if (ingreso != 0)
		{
			while (leerDeDisco(pos++) && !bandera)
			{
				if (dni == ingreso)
				{
					estado = false;
					bandera = true;
					rlutil::cls();
					std::cout << "Cliente eliminado con exito." << std::endl;
					rlutil::anykey();
				}
			}
			ingreso = 0;
		}
		if (ingreso != 0 && !bandera)
		{
			rlutil::cls();
			std::cout << "Error. No se ha podido encontrar el cliente. Por favor ingrese nuevamente el DNI." << std::endl;
			rlutil::anykey();
		}
		rlutil::cls();
	} while (ingreso != 0);
}

void Cliente::listarCliente() {
	int opcion, d, pos=0;
	bool bandera = false;
	do
	{
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
			for (int i = 0; i < contRegistros(); i++)
			{
				leerDeDisco(i);
				mostrar();
				std::cout << std::endl << std::endl;
			}
			break;
		case 2:
			std::cout << "Ingrese el DNI del cliente que quiere listar: ";
			std::cin >> d;
			rlutil::cls();
			while (leerDeDisco(pos++)&&!bandera)
			{
				if (d==dni)
				{
					mostrar();
					bandera = true;
				}
			}
			if (!bandera)std::cout << "No se ha podido encontrar el cliente." << std::endl;
			break;
		default:
			if (opcion!=0)
			{
				std::cout << "Por favor ingrese una opción correcta.";
			}
			break;
		}
		bandera = false;
		if(opcion!=0)rlutil::anykey();
		pos = 0;
	} while (opcion != 0);
}

Cliente Cliente::buscarCliente(int d)
{
	Cliente c;
	int pos = 0;
	while (c.leerDeDisco(pos++))
	{
		if(dni==d) return c;
	}
	std::cout << "No se ha podido encontrar el cliente." << std::endl;
	rlutil::anykey();
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