#pragma once
#include "rlutil.h"
#include "Cliente.h"
#include "Compra.h"
#include "Empleado.h"
#include "Producto.h"
#include "Venta.h"

class  Menu {      // / entidades funciones locales ///atributos

public:
    Menu();
    ~Menu();
    void menuPrincipal();
    void menuReportes();
    void menuCompras();
    void menuClientes();
    void menuEmpleados();
    void menuVentas();



};