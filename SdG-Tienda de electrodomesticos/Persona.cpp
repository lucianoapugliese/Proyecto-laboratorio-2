#include "Persona.h"

const char *Persona::getApellido() 
{
    return apellido;
}

void Persona::setApellido(const char *apellido)
{
    strcpy(this->apellido,apellido);
}

const char *Persona::getNombre() 
{
    return nombre;
}

void Persona::setNombre(const char *nombre)
{
    strcpy(this->nombre, nombre);
}

int Persona::getDni() const
{
    return dni;
}

void Persona::setDni(int dni)
{
    this->dni = dni;
}

FechaHora Persona::getFechaDeNacimiento() const
{
    return fechaDeNacimiento;
}

void Persona::setFechaDeNacimiento(FechaHora fechaDeNacimiento)
{
    this->fechaDeNacimiento = fechaDeNacimiento;
}

Direccion Persona::getDomicilio() const
{
    return domicilio;
}

void Persona::setDomicilio(Direccion domicilio)
{
    this->domicilio = domicilio;
}