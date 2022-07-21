#pragma once
#include "rlutil.h"
#include "Cliente.h"
#include "Compra.h"
#include "Empleado.h"
#include "Producto.h"
#include "VentaCabecera.h"
#include "Proveedor.h"

class  Menu {      // / entidades funciones locales ///atributos
private:
    int color = 1;
public:
    Menu();
    void Menurectangulo(int, int, int, int, const char*);
    void menuPrincipal();
    void menuReportes();
    void menuCompras();
    void menuClientes();
    void menuEmpleados();
    void menuVentas();
    void menuProductos();
    void menuProveedores();

};