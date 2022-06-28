#include "Menu.h"
#include "rlutil.h"
#include <iostream>
/*
void Menu::menuPrincipal() {
    int opcion;
    bool salir = true;
    while (salir)
    {
        std::cout << "MENU PRINCIPAL DE GESTION " << std::endl;
        std::cout << "1 - ARTICULOS A LA VENTA" << std::endl;
        std::cout << "2 - COMPRAS " << std::endl; // A PROVEEDORES
        std::cout << "3 - REPORTES " << std::endl;
        std::cout << "------------------" << std::endl;
        std::cout << "0 - SALIR" << std::endl;
        std::cout << "INGRESE UNA OPCION " << std::endl;
        std::cin >> opcion;
        switch (opcion)
        {
        case 1:system("cls");
            break;
        case 2:menuCompras();
            system("cls");
            break;
        case 3:menuReportes();
            system("cls");
            break;
        case 0: salir = false;

            break;

        }
    }
}*/
Menu::Menu()
{
    /*rlutil::setBackgroundColor(rlutil::BLACK);
    rlutil::setColor(rlutil::BLUE);
    // std::cout << "\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\BIENVENIDOS A TIENDA DE ELECTROCOMPRAME " << std::endl;
    rlutil::setBackgroundColor(rlutil::BLUE);
    rlutil::setColor(rlutil::GREY);
    */
}
Menu::~Menu()
{


}
void Menu::menuCompras() {
    Compra compra;
    int opcion;
    do {
        std::cout << "1 - AGREGAR COMPRA" << std::endl;
        std::cout << "2 - MODIFICAR COMPRA" << std::endl;
        std::cout << "3 - ELIMINAR COMPRA " << std::endl;
        std::cout << "4 - LISTAR COMPRA/S " << std::endl;
        std::cout << "-------------------" << std::endl;
        std::cout << "------------------" << std::endl;
        std::cout << "0 - VOLVER" << std::endl;
        std::cout << std::endl << "Ingrese una opción: ";
        std::cin >> opcion;
        switch (opcion) {
        case 1: compra.Cargar();
            break;
        case 2:
            break;
        case 3:
            break;
        case 4:
            break;
        case 5:
            break;
        case 0:
            break;
        default:
            rlutil::cls();
            std::cout << "Por favor ingrese una opción correcta.";
            rlutil::anykey();
            break;
        }
    } while (opcion >=0 && opcion <=5);
}
void Menu::menuClientes() {
    Cliente cliente;
    int opcion;
    do {
        std::cout << "1 - AGREGAR CLIENTE" << std::endl;
        std::cout << "2 - MODIFICAR CLIENTE" << std::endl;
        std::cout << "3 - ELIMINAR CLIENTE " << std::endl;
        std::cout << "4 - LISTAR CLIENTE/S " << std::endl;
        std::cout << "-------------------" << std::endl;
        std::cout << "------------------" << std::endl;
        std::cout << "0 - VOLVER" << std::endl;
        std::cout << std::endl << "Ingrese una opción: ";
        std::cin >> opcion;
        switch (opcion) {
        case 1:
            cliente.cargar();
            break;
        case 2:
            cliente.modificarCliente();
            break;
        case 3:
            break;
        case 4:
            break;
        case 5:
            break;
        case 0:
            break;
        default:
            rlutil::cls();
            std::cout << "Por favor ingrese una opción correcta.";
            rlutil::anykey();
            break;
        }
    } while (opcion !=0);
}
void Menu::menuVentas() {
    Venta venta;
    int opcion;
    do {
        std::cout << "1 - AGREGAR VENTA" << std::endl;
        std::cout << "2 - MODIFICAR VENTA" << std::endl;
        std::cout << "3 - ELIMINAR VENTA" << std::endl;
        std::cout << "4 - LISTAR VENTA/S " << std::endl;
        std::cout << "-------------------" << std::endl;
        std::cout << "------------------" << std::endl;
        std::cout << "0 - VOLVER" << std::endl;
        std::cout << std::endl << "Ingrese una opción: ";
        std::cin >> opcion;
        switch (opcion) {
        case 1: venta.cargar();
            break;
        case 2:
            break;
        case 3:
            break;
        case 4:
            break;
        case 5:
            break;
        case 0:
            break;
        default:
            rlutil::cls();
            std::cout << "Por favor ingrese una opción correcta.";
            rlutil::anykey();
            break;
        }
    } while (opcion!=0);
}
void Menu::menuEmpleados() {
    Empleado empleado;
    int opcion;
    do {
        std::cout << "1 - AGREGAR EMPLEADO" << std::endl;
        std::cout << "2 - MODIFICAR EMPLEADO" << std::endl;
        std::cout << "3 - ELIMINAR EMPLEADO" << std::endl;
        std::cout << "4 - LISTAR EMPLEADO/S " << std::endl;
        std::cout << "-------------------" << std::endl;
        std::cout << "------------------" << std::endl;
        std::cout << "0 - VOLVER" << std::endl;
        std::cout << std::endl << "Ingrese una opción: ";
        std::cin >> opcion;
        switch (opcion) {
        case 1:
            empleado.cargar();
            break;
        case 2:
            break;
        case 3:
            break;
        case 4:
            break;
        case 5:
            break;
        case 0:
            break;
        default:
            rlutil::cls();
            std::cout << "Por favor ingrese una opción correcta.";
            rlutil::anykey();
            break;
        }
    } while (opcion!=0);
}
void Menu::menuReportes() {
    bool salir = true;
    while (salir)
    {
        std::cout << "1 - EL MES CON MAYOR VENTA" << std::endl;
        std::cout << "2 - EL ARTICULO MAS VENDIDO" << std::endl;
        std::cout << "3 - LA RECAUDACION ANUEL EN VENTAS " << std::endl;
        std::cout << "-------------------" << std::endl;
        std::cout << "------------------" << std::endl;
        std::cout << "0 - VOLVER" << std::endl;
        int pos;
        std::cout << std::endl << "> ";
        std::cin >> pos;
        switch (pos)
        {
        case 1:
            break;
        case 2:
            break;
        case 3:
            break;
        case 0: salir = false;
            break;
        }
    }
}

void Menu::menuPrincipal() {
    int opcion;
    bool salir = true;
    while (salir)
    {
        std::cout << "MENÚ PRINCIPAL DE GESTIÓN " << std::endl;
        std::cout << "1 - VENTAS" << std::endl;//Lucho
        std::cout << "2 - COMPRAS " << std::endl;//Jony
        std::cout << "3 - EMPLEADOS " << std::endl;//Lucho
        std::cout << "4 - CLIENTES " << std::endl;//Lucho
        std::cout << "5 - REPORTES " << std::endl;//Jony
        std::cout << "------------------" << std::endl;
        std::cout << "0 - SALIR" << std::endl;
        std::cout << "INGRESE UNA OPCION " << std::endl;
        std::cin >> opcion;
        switch (opcion)
        {
        case 1: menuVentas();
            break;
        case 2: menuCompras();
            break;
        case 3: menuEmpleados();
            break;
        case 4: menuClientes();
            break;
        case 5: menuReportes();
            break;
        case 0: salir = false;
            break;
        default:
            rlutil::cls();
            std::cout << "Por favor ingrese una opción correcta." << std::endl;
            rlutil::anykey();
        }
            rlutil::cls();
    }
}