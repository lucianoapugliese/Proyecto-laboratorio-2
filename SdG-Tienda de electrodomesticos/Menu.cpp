#include "Menu.h"
#include <iostream>

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
    char salirdelSistema;
    rlutil::setColor(rlutil::WHITE);
    rlutil::setBackgroundColor(rlutil::BLUE);
    while (salir)
    {
        system("cls");
        Menu();
        rlutil::setColor(rlutil::WHITE);
        rlutil::setBackgroundColor(rlutil::BLUE);
        Menurectangulo(32, 7, 60, 16, "");
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
        std::cout << "4 - CLIENTES " << std::endl;
        rlutil::locate(40, 15);
        std::cout << "5 - REPORTES " << std::endl;
        rlutil::locate(40, 16);
        std::cout << "6 - PRODUCTOS " << std::endl;
        rlutil::locate(40, 17);
        std::cout << "---------------------------------------" << std::endl;
        rlutil::locate(40, 18);
        std::cout << "0 - SALIR" << std::endl;
        rlutil::locate(38, 19);
        std::cout << "> ";
        std::cin >> opcion;
        switch (opcion) {

        case 1:menuVentas();
            break;
        case 2: menuCompras();
            system("cls");
            break;
        case 3:menuEmpleados();
            system("cls");
            break;
        case 4:menuClientes();
            system("cls");
            break;
        case 5:menuReportes();
            system("cls");
            break;
        case 6:menuProductos();
            system("cls");
            break;
        case 0:
            system("cls");
            rlutil::setBackgroundColor(rlutil::RED);
            rlutil::setColor(rlutil::WHITE);
            Menurectangulo(40, 20, 30, 3, " CONFIRMAR SALIDA? S/N \0"); std::cout << std::endl;
            // rlutil::locate(40, 2);
             //std::cout << " CONFIRMAR SALIDA? S/N " << std::endl;
            rlutil::locate(53, 22);
            std::cin >> salirdelSistema;
            if (tolower(salirdelSistema) == 's') { salir = false; }
            rlutil::setBackgroundColor(rlutil::BLUE);
            rlutil::setColor(rlutil::WHITE);
            system("cls");
            break;
        }
    }
}
void Menu::menuVentas() {
    VentaCabecera venta;
    int opcion;
    rlutil::setColor(rlutil::WHITE);
    rlutil::setBackgroundColor(rlutil::BLACK);
    do {
        system("cls");
        Menu();
        rlutil::setColor(rlutil::WHITE);
        rlutil::setBackgroundColor(rlutil::BLACK);
        Menurectangulo(49, 8, 25, 3, "");
        std::cout << "1 - AGREGAR VENTA" << std::endl;
        Menurectangulo(49, 11, 25, 3, "");
        std::cout << "2 - MODIFICAR VENTA" << std::endl;
        Menurectangulo(49, 14, 25, 3, "");
        std::cout << "3 - ELIMINAR VENTA" << std::endl;
        Menurectangulo(49, 17, 25, 3, "");
        std::cout << "4 - LISTAR VENTA/S " << std::endl;
        Menurectangulo(49, 20, 25, 3, "");
        std::cout << "0 - VOLVER" << std::endl;
        Menurectangulo(49, 23, 25, 3, "");
        std::cout << "> ";
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
            rlutil::cls();
            if (opcion != 0) {

                rlutil::setBackgroundColor(rlutil::RED);
                rlutil::setColor(rlutil::WHITE);
                Menurectangulo(45, 11, 23, 4, "OPCION INCORRECTA!");

                rlutil::anykey();
                rlutil::setBackgroundColor(rlutil::BLACK);
                rlutil::setColor(rlutil::WHITE);
            }
            break;
        }
    } while (opcion != 0);
    rlutil::setColor(rlutil::WHITE);
    rlutil::setBackgroundColor(rlutil::BLUE);
}
void Menu::menuCompras() {
    Compra compra;
    int opcion;
    rlutil::setColor(rlutil::WHITE);
    rlutil::setBackgroundColor(rlutil::LIGHTBLUE);
    do {
        system("cls");
        Menu();
        rlutil::setColor(rlutil::WHITE);
        rlutil::setBackgroundColor(rlutil::LIGHTBLUE);
        Menurectangulo(49, 8, 25, 3, "");
        std::cout << "1 - AGREGAR COMPRA" << std::endl;
        Menurectangulo(49, 11, 25, 3, "");
        std::cout << "2 - ELIMINAR COMPRA " << std::endl;
        Menurectangulo(49, 14, 25, 3, "");
        std::cout << "3 - LISTAR COMPRA/S " << std::endl;
        Menurectangulo(49, 17, 25, 3, "");
        std::cout << "0 - VOLVER" << std::endl;
        Menurectangulo(49, 20, 25, 3, "");
        std::cout << "> ";
        std::cin >> opcion;
        rlutil::cls();
        switch (opcion) {
        case 1: compra.Cargar();
            break;
        case 2: compra.eliminarCompra();
            break;
        case 3: compra.listarCompra();
            break;
        default:
            if (opcion != 0) {
                system("cls");
                rlutil::setBackgroundColor(rlutil::RED);
                rlutil::setColor(rlutil::WHITE);
                Menurectangulo(45, 11, 23, 4, "OPCION INCORRECTA!");
                rlutil::anykey();
                rlutil::setBackgroundColor(rlutil::LIGHTBLUE);
                rlutil::setColor(rlutil::WHITE);
            }
            break;
        }
    } while (opcion != 0);
    system("cls");
    rlutil::setBackgroundColor(rlutil::BLUE);
    rlutil::setColor(rlutil::WHITE);
}
void Menu::menuEmpleados() {
    Empleado empleado;
    int opcion;
    rlutil::setColor(rlutil::WHITE);
    rlutil::setBackgroundColor(rlutil::GREEN);
    do {
        system("cls");
        Menu();
        rlutil::setColor(rlutil::WHITE);
        rlutil::setBackgroundColor(rlutil::GREEN);
        Menurectangulo(49, 8, 25, 3, "");
        std::cout << "1 - AGREGAR EMPLEADO" << std::endl;
        Menurectangulo(49, 11, 25, 3, "");
        std::cout << "2 - MODIFICAR EMPLEADO" << std::endl;
        Menurectangulo(49, 14, 25, 3, "");
        std::cout << "3 - ELIMINAR EMPLEADO" << std::endl;
        Menurectangulo(49, 17, 25, 3, "");
        std::cout << "4 - LISTAR EMPLEADO/S " << std::endl;
        Menurectangulo(49, 20, 25, 3, "");
        std::cout << "0 - VOLVER" << std::endl;
        Menurectangulo(49, 23, 25, 3, "");
        std::cout << "> ";
        std::cin >> opcion;
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
            if (opcion != 0) {
                system("cls");
                rlutil::setBackgroundColor(rlutil::RED);
                rlutil::setColor(rlutil::WHITE);
                Menurectangulo(45, 11, 23, 4, "OPCION INCORRECTA!");
                rlutil::anykey();
                rlutil::setBackgroundColor(rlutil::GREEN);
                rlutil::setColor(rlutil::WHITE);
            }

        }

    } while (opcion != 0);
    rlutil::setColor(rlutil::WHITE);
    rlutil::setBackgroundColor(rlutil::BLUE);
}
void Menu::menuClientes() {
    Cliente cliente;
    int opcion;
    rlutil::setColor(rlutil::WHITE);
    rlutil::setBackgroundColor(rlutil::MAGENTA);
    do {
        system("cls");
        Menu();
        rlutil::setColor(rlutil::WHITE);
        rlutil::setBackgroundColor(rlutil::MAGENTA);
        Menurectangulo(49, 8, 25, 3, "");
        std::cout << "1 - AGREGAR CLIENTE" << std::endl;
        Menurectangulo(49, 11, 25, 3, "");
        std::cout << "2 - MODIFICAR CLIENTE" << std::endl;
        Menurectangulo(49, 14, 25, 3, "");
        std::cout << "3 - ELIMINAR CLIENTE " << std::endl;
        Menurectangulo(49, 17, 25, 3, "");
        std::cout << "4 - LISTAR CLIENTE/S " << std::endl;
        Menurectangulo(49, 20, 25, 3, "");
        std::cout << "0 - VOLVER" << std::endl;
        Menurectangulo(49, 23, 25, 3, "");
        std::cout << "> ";

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
                system("cls");
                rlutil::setBackgroundColor(rlutil::RED);
                rlutil::setColor(rlutil::WHITE);
                Menurectangulo(45, 11, 23, 4, "OPCION INCORRECTA!");
                rlutil::anykey();
                rlutil::setBackgroundColor(rlutil::MAGENTA);
                rlutil::setColor(rlutil::WHITE);
            }
            break;
        }

    } while (opcion != 0);
    rlutil::setColor(rlutil::WHITE);
    rlutil::setBackgroundColor(rlutil::BLUE);
}
void Menu::menuReportes() { /// reporte de ventas
    int pos;
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
        std::cout << "MENÚ PRINCIPAL DE VENTAS " << std::endl;
        rlutil::locate(40, 10);
        std::cout << "---------------------------------------" << std::endl;
        rlutil::locate(40, 11);
        std::cout << "1 - EL MES CON MAYOR VENTA" << std::endl;///refiere a clase venta
        rlutil::locate(40, 12);
        std::cout << "2 - PRODUCTO MÁS VENDIDO " << std::endl;/// refiere clase pruduto dentro venta contar el producto mas vendido
        rlutil::locate(40, 13);
        std::cout << "3 - VENDEDORES CON MÁS VENTAS" << std::endl;///refiere a clase venta
        rlutil::locate(40, 14);
        std::cout << "4 - MESES CON MÁS VENTAS" << std::endl;
        rlutil::locate(40, 15);
        std::cout << "5 - PRODUCTO MÁS VENDIDOS MARCAS " << std::endl;//refiere a clase venta
        rlutil::locate(40, 16);
        std::cout << "6 - RECAUDACIÓN ANUAL EN VENTAS " << std::endl;
        rlutil::locate(40, 17);
        std::cout << "---------------------------------------" << std::endl;
        rlutil::locate(40, 18);
        std::cout << "---------------------------------------" << std::endl;
        rlutil::locate(40, 19);
        std::cout << "0 - VOLVER" << std::endl;
        rlutil::locate(38, 20);
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
        case 4:
            break;
        case 5:
            break;
        case 6:
            break;
        case 0:
            rlutil::setBackgroundColor(rlutil::BLUE);
            rlutil::setColor(rlutil::WHITE); salir = false;
            break;
        }
        rlutil::cls();
    }
}
void Menu::menuProveedores() {
    Proveedor proveedor;
    int opcion;
    do {
        std::cout << "1 - AGREGAR PROVEEDOR" << std::endl;
        std::cout << "2 - MODIFICAR PROVEEDOR" << std::endl;
        std::cout << "3 - ELIMINAR PROVEEDOR " << std::endl;
        std::cout << "4 - LISTAR PROVEEDOR/ES " << std::endl;
        std::cout << "-------------------" << std::endl;
        std::cout << "------------------" << std::endl;
        std::cout << "0 - VOLVER" << std::endl;
        std::cout << std::endl << "Ingrese una opción: ";
        std::cin >> opcion;
        rlutil::cls();
        switch (opcion) {
        case 1: proveedor.cargar();
            break;
        case 2: proveedor.modificarProveedores();
            break;
        case 3: proveedor.eliminarProveedores();
            break;
        case 4: proveedor.listarProveedores();
            break;
        default:
            if (opcion != 0) {
                std::cout << "Por favor ingrese una opción correcta.";
                rlutil::anykey();
            }
            break;
        }
    } while (opcion != 0);
}
void Menu::menuProductos() {
    Producto producto;
    int opcion;
    bool ok = true;
    rlutil::setColor(rlutil::BLACK);
    rlutil::setBackgroundColor(rlutil::WHITE);
    do {
        system("cls");
        rlutil::setColor(rlutil::BLACK);
        rlutil::setBackgroundColor(rlutil::WHITE);
        Menurectangulo(49, 8, 25, 3, "");
        std::cout << "1 - AGREGAR PRODUCTO" << std::endl;
        Menurectangulo(49, 11, 25, 3, "");
        std::cout << "2 - MODIFICAR PRODUCTO" << std::endl;
        Menurectangulo(49, 14, 25, 3, "");
        std::cout << "3 - ELIMINAR PRODUCTO" << std::endl;
        Menurectangulo(49, 17, 25, 3, "");
        std::cout << "4 - LISTAR PRODUCTOS " << std::endl;
        Menurectangulo(49, 20, 25, 3, "");
        std::cout << "0 - VOLVER" << std::endl;
        Menurectangulo(49, 23, 25, 3, "");
        std::cout << "> ";
        std::cin >> opcion;
        rlutil::cls();
        switch (opcion) {
        case 1:
            producto.cargar();
            break;
        case 2:
            producto.modificarProducto();
            break;
        case 3:
            producto.eliminarProducto();

            break;
        case 4: producto.listarProducto();
            break;
        default:
            if (opcion != 0) {
                std::cout << "Por favor ingrese una opción correcta.";
                rlutil::anykey();
            }
            break;
        }
        rlutil::cls();
    } while (opcion != 0);
}
/* void Menu::menuPrincipal() {
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
}*/