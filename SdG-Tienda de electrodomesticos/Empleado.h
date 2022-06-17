#pragma once
#include "Persona.h"
class Empleado :
    public Persona
{
private:
	int ID, categoria, turno;
	FechaHora fechaDeIngreso;
	char tipoJornada;
	float sueldo;
public:
	void cargar();
	void mostrar();
	bool grabarEnDisco();
	bool leerDeDisco(int pos);
    int getID() const;
    void setID(int ID);

    int getCategoria() const;
    void setCategoria(int categoria);

    int getTurno() const;
    void setTurno(int turno);

    FechaHora getFechaDeIngreso() const;
    void setFechaDeIngreso(FechaHora fechaDeIngreso);

    char getTipoJornada() const;
    void setTipoJornada(char tipoJornada);

    float getSueldo() const;
    void setSueldo(float sueldo);

};