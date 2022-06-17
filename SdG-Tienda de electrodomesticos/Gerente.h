#pragma once
#include "Empleado.h"
class Gerente :
    public Empleado
{
private:
	int vendedoresACargo;
public:
	void cargar();
	void mostrar();
	bool grabarEnDisco();
	bool leerDeDisco(int pos);
    int getVendedoresACargo() const;
    void setVendedoresACargo(int vendedoresACargo);

};
