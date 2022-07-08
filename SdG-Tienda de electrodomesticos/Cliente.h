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
	Cliente();
	void cargar();
	void mostrar();
	bool grabarEnDisco();
	bool leerDeDisco(int);
    const char* getMail();
    void setMail(const char *mail);

    const char* getNumerotarjeta();
    void setNumerotarjeta(const char* Numerotarjeta);
	void modificarCliente();
    Direccion getDomicilio() const;
    void setDomicilio(Direccion domicilio);
	void eliminarCliente();
	Cliente buscarCliente(int);
	void listarCliente();
	int contRegistros();
};
