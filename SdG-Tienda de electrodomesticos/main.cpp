#include <iostream>
#include <cstring>
#include <iomanip>
#include "rlutil.h"
#include "Cliente.h"
#include "Empleado.h"
#include "Producto.h"

int main() {
	setlocale(LC_ALL, "Spanish");
	rlutil::setBackgroundColor(rlutil::MAGENTA);
	rlutil::cls();
	Persona o;
	o.cargar();
	rlutil::cls();
	o.mostrar();
	return 0;
}