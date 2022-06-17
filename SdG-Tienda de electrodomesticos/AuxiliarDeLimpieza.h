#pragma once
#include "Empleado.h"
class AuxiliarDeLimpieza :
    public Empleado
{
	private:
		char sector;
	public:
		void cargar();
		void mostrar();
		bool grabarEnDisco();
		bool leerDeDisco(int pos);
    char getSector() const;
    void setSector(char sector);

};
