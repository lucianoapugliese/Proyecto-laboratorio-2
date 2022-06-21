#pragma once
#include "Persona.h"
class Cliente :
    public Persona
{
private:
	char mail[50];
	char Numerotarjeta[17];
public:
	Cliente();
	void cargar();
	void mostrar();
	bool grabarEnDisco();
	bool leerDeDisco(int pos);
    const char* getMail();
    void setMail(const char *mail);

    const char* getNumerotarjeta();
    void setNumerotarjeta(const char* Numerotarjeta);

};
