#include <iostream>
#include <cstring>
#include <iomanip>
#include "rlutil.h"
#include "Cliente.h"
#include "Empleado.h"

int main() {
	setlocale(LC_ALL, "Spanish");
	rlutil::setBackgroundColor(rlutil::MAGENTA);
	rlutil::cls();
	Empleado o;
	o.cargar();
	rlutil::cls();
	o.mostrar();
	return 0;
}