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
	std::cout << "Mail: ";
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
		std::cout << mail;
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
		std::cout << "0-Volver" << std::endl;
		rlutil::cls();
		switch (opcion)
		{
		case 1:
			std::cout << "Ingrese un nuevo DNI: ";
			std::cin >> ingreso;
			setDni(ingreso);
			rlutil::cls();
			std::cout << "DNI modificado con exito." << std::endl;
			rlutil::anykey();
			break;
		case 2:
			std::cout << "Ingrese nueva fecha de nacimiento:" << std::endl;
			nuevaFecha.cargarFecha();
			setFechaDeNacimiento(nuevaFecha);
			rlutil::cls();
			std::cout << "Fecha de nacimiento modificada con exito." << std::endl;
			rlutil::anykey();
			break;
		case 3:
			std::cout << "Ingrese el nombre nuevo: ";
			std::cin.ignore();
			std::getline(std::cin, palabra);
			setNombre(palabra);
			rlutil::cls();
			std::cout << "Nombre modificado con exito." << std::endl;
			rlutil::anykey();
			break;
		case 4:
			std::cout << "Ingrese el apellido nuevo: ";
			std::cin.ignore();
			std::getline(std::cin, palabra);
			setApellido(palabra);
			rlutil::cls();
			std::cout << "Apellido modificado con exito." << std::endl;
			rlutil::anykey();
			break;
		case 5:
			std::cout << "Ingrese el domicilio nuevo: " << std::endl;
			nuevoDom.cargar();
			setDomicilio(nuevoDom);
			rlutil::cls();
			std::cout << "Domicilio modificado con exito." << std::endl;
			rlutil::anykey();
			break;
		case 6:
			std::cout << "Ingrese el nuevo numero de tarjeta: " << std::endl;
			std::cin >> tarjeta;
			setNumerotarjeta(tarjeta);
			rlutil::cls();
			std::cout << "Numero de tarjeta modificado con exito." << std::endl;
			rlutil::anykey();
			break;
		default:
			if (opcion != 0)
			{
				rlutil::cls();
				std::cout << "Por favor ingrese una opción correcta.";
				rlutil::anykey();
			}
			break;
		}
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

