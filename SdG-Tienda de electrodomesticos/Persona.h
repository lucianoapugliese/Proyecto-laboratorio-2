#pragma once
#include <iostream>
#include <cstring>
#include <iomanip>
#include "FechaHora.h"
#include "Direccion.h"
#include "Funciones.h"
#include "rlutil.h"

class Persona
{
protected:
	int dni;
	bool estado;
	FechaHora fechaDeNacimiento;
	//Direccion domicilio;
	char apellido[50], nombre[50];
public:
	Persona();
	void cargar();
	void mostrar();
	//bool grabarEnDisco();
	//bool leerDeDisco(int pos);
    std::string getApellido();
    void setApellido(std::string apellido);
   
    std::string getNombre();
    void setNombre(std::string nombre);

    int getDni() const;
    void setDni(int dni);

    FechaHora getFechaDeNacimiento() ;
    void setFechaDeNacimiento(FechaHora fechaDeNacimiento);

    //Direccion getDomicilio() ;
    //void setDomicilio(Direccion domicilio);
	//~Persona();

	bool getEstado();
	void setEstado(bool estado);
};