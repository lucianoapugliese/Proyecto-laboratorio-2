#include "Vendedor.h"

int Vendedor::getCantidadDeVentas() const
{
    return cantidadDeVentas;
}

void Vendedor::setCantidadDeVentas(int cantidadDeVentas)
{
    this->cantidadDeVentas = cantidadDeVentas;
}

int Vendedor::getCantidadDeFaltas() const
{
    return cantidadDeFaltas;
}

void Vendedor::setCantidadDeFaltas(int cantidadDeFaltas)
{
    this->cantidadDeFaltas = cantidadDeFaltas;
}

int Vendedor::getPuntaje() const
{
    return puntaje;
}

void Vendedor::setPuntaje(int puntaje)
{
    this->puntaje = puntaje;
}

int Vendedor::getIdGerenteACargo() const
{
    return idGerenteACargo;
}

void Vendedor::setIdGerenteACargo(int idGerenteACargo)
{
    this->idGerenteACargo = idGerenteACargo;
}

