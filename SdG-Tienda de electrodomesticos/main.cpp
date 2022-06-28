#include <iostream>
#include <cstring>
#include <iomanip>
#include "rlutil.h"
#include "Cliente.h"
#include "Empleado.h"
#include "Producto.h"
#include "Compra.h"
#include "Menu.h"
#include "Venta.h"

int main() {
	setlocale(LC_ALL, "Spanish");
	rlutil::setBackgroundColor(rlutil::MAGENTA);
	rlutil::cls();
	Menu m;
	m.menuPrincipal();
	return 0;
}