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

bool Cliente::getEstado()
{
	return estado;
}

void Cliente::setEstado(bool estado)
{
	this->estado = estado;
}

void Cliente::cargar() {
	Persona::cargar();
	std::cout << "Numero de tarjeta: ";
	std::cin >> Numerotarjeta;
	std::cout << "Mail: ";
	std::cin >> mail;
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