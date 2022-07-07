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
/* Menu::Menu()
{
    rlutil::setBackgroundColor(rlutil::BLACK);
    rlutil::setColor(rlutil::BLUE);
    // std::cout << "\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\BIENVENIDOS A TIENDA DE ELECTROCOMPRAME " << std::endl;
    rlutil::setBackgroundColor(rlutil::BLUE);
    rlutil::setColor(rlutil::GREY);
    
} */
void showItem(const char* texto, int x, int y, bool seleccionar)
{
    if (seleccionar) {
        rlutil::setBackgroundColor(rlutil::BLUE);
    }
    else { rlutil::setBackgroundColor(rlutil::BLACK); }

    rlutil::locate(x, y);
    std::cout << texto << std::endl;

}
void Menu::Menurectangulo(int x, int y, int ancho, int alto, const char* texto)
{



    for (int i = x; i <= x + ancho; i++) {

        gotoxy(i, y);
        std::cout << "*";
        gotoxy(i, y + alto);
        std::cout << "*";
    }
    for (int i = y; i <= y + alto; i++) {
        gotoxy(x, i);
        std::cout << "*";
        gotoxy(x + ancho, i);
        std::cout << "*";
    }
    gotoxy(x + 2, y + alto / 2);
    std::cout << texto;



}
Menu::Menu()
{
    color = 1 + rand() % 10;
    if (color == 0) { rlutil::setColor(rlutil::WHITE); }
    if (color == 15 || color == 14 || color == 7) { rlutil::setColor(rlutil::BLACK); }
    rlutil::setBackgroundColor(color);
    Menurectangulo(40, 1, 44, 5, " BIENVENIDOS A TIENDA DE ELECTROCOMPRAME ");
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
        rlutil::cls();
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
            std::cout << "Por favor ingrese una opción correcta." << std::endl;
            rlutil::anykey();
        }
    }
}
void Menu::menuPrincipal() {
    int opcion;
    bool salir = true;
    char salirdelSistema;
    rlutil::setColor(rlutil::WHITE);
    rlutil::setBackgroundColor(rlutil::BLUE);
    while (salir)
    {
        system("cls");
        Menu();
        rlutil::setColor(rlutil::WHITE);
        rlutil::setBackgroundColor(rlutil::BLUE);
        Menurectangulo(32, 7, 60, 12, "");
        // int x = 40;
        rlutil::locate(40, 9);
        std::cout << "MENU PRINCIPAL DE GESTION " << std::endl;
        rlutil::locate(40, 10);
        std::cout << "---------------------------------------" << std::endl;
        rlutil::locate(40, 11);
        std::cout << "1 - VENTAS" << std::endl;
        rlutil::locate(40, 12);
        std::cout << "2 - COMPRAS " << std::endl;
        rlutil::locate(40, 13);
        std::cout << "3 - EMPLEADOS " << std::endl;
        rlutil::locate(40, 14);
        std::cout << "3 - CLIENTES " << std::endl;
        rlutil::locate(40, 15);
        std::cout << "3 - REPORTES " << std::endl;
        rlutil::locate(40, 16);
        std::cout << "----------------------------------------" << std::endl;
        rlutil::locate(40, 17);
        std::cout << "---------------------------------------" << std::endl;
        rlutil::locate(40, 18);
        std::cout << "0 - SALIR" << std::endl;
        rlutil::locate(38, 19);
        std::cout << "> ";
        std::cin >> opcion;
        switch (opcion) {

        case 1:menuReportes();
            break;
        case 2: menuCompras();
            system("cls");
            break;
        case 3:
            system("cls");
            break;
        case 0:
            system("cls");
            rlutil::setBackgroundColor(rlutil::RED);
            rlutil::setColor(rlutil::WHITE);
            Menurectangulo(40, 1, 30, 3, " CONFIRMAR SALIDA? S/N \0"); std::cout << std::endl;
            // rlutil::locate(40, 2);
             //std::cout << " CONFIRMAR SALIDA? S/N " << std::endl;
            rlutil::locate(53, 3);
            std::cin >> salirdelSistema;
            if (tolower(salirdelSistema) == 's') { salir = false; }
            rlutil::setBackgroundColor(rlutil::BLUE);
            rlutil::setColor(rlutil::WHITE);
            system("cls");
            break;
        }
    }
}
void Menu::menuReportes() { /// reporte de ventas
    bool salir = true;
    rlutil::setBackgroundColor(rlutil::LIGHTBLUE);
    rlutil::setColor(rlutil::WHITE);
    while (salir)
    {
        system("cls");
        Menu();
        rlutil::setBackgroundColor(rlutil::LIGHTBLUE);
        rlutil::setColor(rlutil::WHITE);
        Menurectangulo(32, 7, 60, 15, "");
        rlutil::locate(40, 9);
        std::cout << "MENU PRINCIPAL DE VENTAS " << std::endl;
        rlutil::locate(40, 10);
        std::cout << "---------------------------------------" << std::endl;
        rlutil::locate(40, 11);
        std::cout << "1 - EL MES CON MAYOR VENTA" << std::endl;///refiere a clase venta
        rlutil::locate(40, 12);
        std::cout << "2 - PRODUCTO MAS VENDIDO " << std::endl;/// refiere clase pruduto dentro venta contar el producto mas vendido
        rlutil::locate(40, 13);
        std::cout << "3 - VENDEDORES CON MAS VENTAS" << std::endl;///refiere a clase venta
        rlutil::locate(40, 14);
        std::cout << "4 - MESES CON MAS VENTAS" << std::endl;
        rlutil::locate(40, 15);
        std::cout << "5 - PRODUCTO MAS VENDIDOS MARCAS " << std::endl;//refiere a clase venta
        rlutil::locate(40, 16);
        std::cout << "---------------------------------------" << std::endl;
        rlutil::locate(40, 17);
        std::cout << "---------------------------------------" << std::endl;
        rlutil::locate(40, 18);
        std::cout << "0 - VOLVER" << std::endl;
        int pos;
        rlutil::locate(38, 19);
        std::cout << "> ";
        std::cin >> pos;

        switch (pos)
        {
        case 1:
            break;
        case 2:
            break;
        case 3:
            break;
        case 0:
            rlutil::setBackgroundColor(rlutil::BLUE);
            rlutil::setColor(rlutil::WHITE); salir = false;
            break;
        }
        std::cin.ignore();
    }
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
        rlutil::cls();
        switch (opcion) {
        case 1: compra.Cargar();
            break;
        case 2:
            break;
        case 3:
            break;
        case 4:
            break;
        default:
            if (opcion != 0) {
                std::cout << "Por favor ingrese una opción correcta.";
                rlutil::anykey();
            }
            break;
        }
    } while (opcion !=0);
}
void Menu::menuClientes() {
    Cliente cliente;
    int opcion;
    rlutil::cls();
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
            rlutil::cls();
        switch (opcion) {
        case 1:
            cliente.cargar();
            break;
        case 2:
            cliente.modificarCliente();
            break;
        case 3: cliente.eliminarCliente();
            break;
        case 4: cliente.listarCliente();
            break;
        default:
            if (opcion != 0) {
                std::cout << "Por favor ingrese una opción correcta.";
                rlutil::anykey();
            }
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
        rlutil::cls();
        switch (opcion) {
        case 1: venta.cargar();
            break;
        case 2:venta.modificarVenta();
            break;
        case 3:venta.eliminarVenta();
            break;
        case 4:venta.listarVenta();
            break;
        default:
            if(opcion!=0){
            std::cout << "Por favor ingrese una opción correcta.";
            rlutil::anykey();
            }
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
        rlutil::cls();
        switch (opcion) {
        case 1:
            empleado.cargar();
            break;
        case 2: empleado.modificarEmpleado();
            break;
        case 3: empleado.eliminarEmpleado();
            break;
        case 4: empleado.listarEmpleado();
            break;
        default:
            if (opcion != 0)
            {
                std::cout << "Por favor ingrese una opción correcta.";
                rlutil::anykey();
            }
            break;
        }
    } while (opcion != 0);
}
void Menu::menuReportes() {
    bool salir = false;
    int pos;
    while (salir)
    {
        std::cout << "1 - EL MES CON MAYOR VENTA" << std::endl;
        std::cout << "2 - EL ARTICULO MAS VENDIDO" << std::endl;
        std::cout << "3 - LA RECAUDACION ANUEL EN VENTAS " << std::endl;
        std::cout << "-------------------" << std::endl;
        std::cout << "------------------" << std::endl;
        std::cout << "0 - VOLVER" << std::endl;
        std::cout << std::endl << "> ";
        std::cin >> pos;
        rlutil::cls();
        switch (pos)
        {
        case 1:
            break;
        case 2:
            break;
        case 3:
            break;
        case 0: salir = true;
            break;
        }
    }
}
