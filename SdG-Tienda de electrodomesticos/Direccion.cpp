#include "Direccion.h"

Direccion::Direccion() {
	strcpy(calle, " ");
	strcpy(localidad, " ");
	departamento = 0;
	numero = 0;
	cp = 0;
	piso = 0;
}

void Direccion::cargar() {
	std::cout << "Localidad: ";
	std::cin.ignore();
	std::cin.getline(localidad, 50);
	std::cout << "Código postal: ";
	std::cin >> cp;
	std::cout << "Calle: ";
	std::cin.ignore();
	std::cin.getline(calle, 50);	
	std::cout << "Altura: ";
	std::cin >> numero;
	std::cout << "Piso: ";
	std::cin >> piso;
	std::cout << "Departamento: ";
	std::cin >> departamento;
}
void Direccion::mostrar() {
	std::cout << "Localidad: ";
	std::cout << localidad << std::endl;
	std::cout << "Código postal: ";
	std::cout << cp << std::endl;
	std::cout << "Calle: ";
	std::cout << calle << " ";
	std::cout << numero << " ";
	std::cout << piso << " ";
	std::cout << departamento << std::endl;
}