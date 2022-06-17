#include "Empleado.h"

int Empleado::getID() const
{
    return ID;
}

void Empleado::setID(int ID)
{
    this->ID = ID;
}

int Empleado::getCategoria() const
{
    return categoria;
}

void Empleado::setCategoria(int categoria)
{
    this->categoria = categoria;
}

int Empleado::getTurno() const
{
    return turno;
}

void Empleado::setTurno(int turno)
{
    this->turno = turno;
}

FechaHora Empleado::getFechaDeIngreso() const
{
    return fechaDeIngreso;
}

void Empleado::setFechaDeIngreso(FechaHora fechaDeIngreso)
{
    this->fechaDeIngreso = fechaDeIngreso;
}

char Empleado::getTipoJornada() const
{
    return tipoJornada;
}

void Empleado::setTipoJornada(char tipoJornada)
{
    this->tipoJornada = tipoJornada;
}

float Empleado::getSueldo() const
{
    return sueldo;
}

void Empleado::setSueldo(float sueldo)
{
    this->sueldo = sueldo;
}

