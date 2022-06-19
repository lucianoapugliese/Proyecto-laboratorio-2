#pragma once
#include <iostream>
#include <iomanip>
#include "FechaHora.h"
#include "Direccion.h"
class Persona
{
protected:
	char apellido[25], nombre[25];
	int dni;
	FechaHora fechaDeNacimiento;
	Direccion domicilio;
public:
	void cargar() {
		std::cout << "Apellido: ";
		std::cin >> apellido;
		std::cout << "Nombre: ";
		std::cin >> nombre;
		std::cout << "DNI: ";
		std::cin >> dni;
	}
	void mostrar() {
		std::cout << '\t' << std::left << std::setw(25) << apellido << std::setw(25) << nombre << std::setw(25) << dni << std::setw(25) << std::endl;
	}
	bool grabarEnDisco();
	bool leerDeDisco(int pos);
    const char *getApellido();
    void setApellido(const char *apellido);

    const char *getNombre();
    void setNombre(const char *nombre);

    int getDni() const;
    void setDni(int dni);

    FechaHora getFechaDeNacimiento() const;
    void setFechaDeNacimiento(FechaHora fechaDeNacimiento);

    Direccion getDomicilio() const;
    void setDomicilio(Direccion domicilio);
};