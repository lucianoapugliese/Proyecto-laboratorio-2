#pragma once
#include "Persona.h"
class Empleado :
    public Persona
{
private:
	int ID, categoria; // Categoria del 1 al 4
	FechaHora fechaDeIngreso;
	char tipoJornada, turno; // jornada part-time o full-time // turno mañana, tarde o noche
	float sueldo;
    //float comision del 0 al 100
public:
	void cargar();
	void mostrar();
    bool modificarEnDisco(int);
	bool grabarEnDisco();
	bool leerDeDisco(int pos);
    int getID();
    void setID(int ID);

    int getCategoria();
    void setCategoria(int categoria);

    char getTurno();
    void setTurno(char turno);

    FechaHora getFechaDeIngreso();
    void setFechaDeIngreso(FechaHora fechaDeIngreso);

    char getTipoJornada();
    void setTipoJornada(char tipoJornada);

    float getSueldo();
    void setSueldo(float sueldo);
    //int contEmpleados();
    void modificarEmpleado();
    int eliminarEmpleado();
    void listarEmpleado();
    int contRegistros();
    int buscarRegistro(int);
};