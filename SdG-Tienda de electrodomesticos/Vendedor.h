#pragma once
#include "Empleado.h"
class Vendedor :
    public Empleado
{
private:
	int cantidadDeVentas, cantidadDeFaltas, puntaje, idGerenteACargo;

public:
	void cargar();
	void mostrar();
	bool grabarEnDisco();
	bool leerDeDisco(int pos);
    int getCantidadDeVentas() const;
    void setCantidadDeVentas(int cantidadDeVentas);

    int getCantidadDeFaltas() const;
    void setCantidadDeFaltas(int cantidadDeFaltas);

    int getPuntaje() const;
    void setPuntaje(int puntaje);

    int getIdGerenteACargo() const;
    void setIdGerenteACargo(int idGerenteACargo);

};
