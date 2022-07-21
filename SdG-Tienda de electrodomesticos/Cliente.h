#pragma once
#include "Persona.h"
#include "rlutil.h"
class Cliente :
    public Persona
{
private:
	char mail[50];
	char Numerotarjeta[17];
	Direccion domicilio;
public:
	void cargar();
	void cargar(int );
	void mostrar();
	bool grabarEnDisco();
	bool leerDeDisco(int);
    const char* getMail();
    void setMail(const char *mail);

    const char* getNumerotarjeta();
    void setNumerotarjeta(const char* Numerotarjeta);
	void modificarCliente();
    Direccion getDomicilio();
    void setDomicilio(Direccion domicilio);
	void eliminarCliente();
	void listarCliente();
	int contRegistros();
	int buscarRegistro(int);
	bool modificarEnDisco(int);
};
