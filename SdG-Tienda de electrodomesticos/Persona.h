#pragma once
#include <iostream>
#include <string>
#include <iomanip>
#include "FechaHora.h"
#include "Direccion.h"
#include "Funciones.h"
class Persona
{
protected:
	char apellido[50], nombre[50];
	int dni;
	bool estado;
	FechaHora fechaDeNacimiento;
	Direccion domicilio;
public:
	Persona();
	void cargar();
	void mostrar();
	//bool grabarEnDisco();
	//bool leerDeDisco(int pos);
    const char *getApellido();
    void setApellido(const char *apellido);
   
    const char *getNombre();
    void setNombre(const char *nombre);

    int getDni() const;
    void setDni(int dni);

    FechaHora getFechaDeNacimiento() ;
    void setFechaDeNacimiento(FechaHora fechaDeNacimiento);

    Direccion getDomicilio() ;
    void setDomicilio(Direccion domicilio);
	//~Persona();
};