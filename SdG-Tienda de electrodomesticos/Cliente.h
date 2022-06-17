#pragma once
#include "Persona.h"
class Cliente :
    public Persona
{
private:
	int dni, Numerotarjeta;
public:
	void cargar() {
		std::cout << "Apellido: ";
		std::cin >> apellido;
		std::cout << "Nombre: ";
		std::cin >> nombre;
		std::cout << "DNI: ";
		std::cin >> dni;
		std::cout << "Cantidad de compras: ";
		std::cin >> cantidadCompras;
	}
	void mostrar() {
		std::cout << '\t' << std::left << std::setw(25) << apellido << std::setw(25) << nombre << std::setw(25) << dni << std::setw(25) << cantidadCompras << std::endl;
	}
	bool grabarEnDisco();
	bool leerDeDisco(int pos);
    int getDni() const;
    void setDni(int dni);

    int getNumerotarjeta() const;
    void setNumerotarjeta(int Numerotarjeta);

};
