#pragma once
#include "Empleado.h"
class Cajero :
    public Empleado
{
private:
	int cantidadDeFaltas, idGerenteACargo;
public:
	void cargar();
	void mostrar();
	bool grabarEnDisco();
	bool leerDeDisco(int pos);
    int getCantidadDeFaltas() const;
    void setCantidadDeFaltas(int cantidadDeFaltas);

    int getIdGerenteACargo() const;
    void setIdGerenteACargo(int idGerenteACargo);

};
