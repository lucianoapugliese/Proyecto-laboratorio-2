#include "Cajero.h"

int Cajero::getCantidadDeFaltas() const
{
    return cantidadDeFaltas;
}

void Cajero::setCantidadDeFaltas(int cantidadDeFaltas)
{
    this->cantidadDeFaltas = cantidadDeFaltas;
}

int Cajero::getIdGerenteACargo() const
{
    return idGerenteACargo;
}

void Cajero::setIdGerenteACargo(int idGerenteACargo)
{
    this->idGerenteACargo = idGerenteACargo;
}

