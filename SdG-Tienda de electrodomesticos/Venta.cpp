#include "Venta.h"
//
//Venta::Venta() {
//    // Valores por omisión
//    cantidadComprada = cantidadCuotas = 0;
//    metodoPago = '-';
//    envioADomicilio = false;
//    estado = true;
//
//    // Desarrollo del descuento por cantidad dependiendo la cantidad de compras
//    if (cantidadComprada<=25)
//    {
//        descuentoPorCantidad = cantidadComprada / 5 * 10;
//    }
//    else
//    {
//        descuentoPorCantidad = 50;
//    }
//    /*
//    // Importe final de la compra
//    costoFinal = productoComprado.getPrecio() * cantidadComprada - productoComprado.getPrecio() * cantidadComprada * descuentoPorCantidad / 100;
//
//    // Costo por cuota
//    if (cantidadCuotas > 0) costoCuota = costoFinal / cantidadCuotas;
//    else costoCuota = costoFinal;
//    */
//    // Numero de venta
//    numeroVenta = contVentas() + 1;
//}

int Venta::getCantidadComprada()
{
    return cantidadComprada;
}

void Venta::setCantidadComprada(int cantidadComprada)
{
    this->cantidadComprada = cantidadComprada;
}

int Venta::getCantidadCuotas()
{
    return cantidadCuotas;
}

void Venta::setCantidadCuotas(int cantidadCuotas)
{
    this->cantidadCuotas = cantidadCuotas;
}

int Venta::getDescuentoPorCantidad()
{
    return descuentoPorCantidad;
}

/*
void Venta::setDescuentoPorCantidad()
{
    
}

Direccion Venta::getDireccionLocal()
{
    return direccionLocal;
}

void Venta::setDireccionLocal(Direccion direccionLocal)
{
    this->direccionLocal = direccionLocal;
}
*/

FechaHora Venta::getFechaYHoraDeLaVenta()
{
    return fechaYHoraDeLaVenta;
}

void Venta::setFechaYHoraDeLaVenta(FechaHora fechaYHoraDeLaVenta)
{
    this->fechaYHoraDeLaVenta = fechaYHoraDeLaVenta;
}

char Venta::getMetodoPago()
{
    return metodoPago;
}

void Venta::setMetodoPago(char metodoPago)
{
    this->metodoPago = metodoPago;
}

bool Venta::getEnvioADomicilio()
{
    return envioADomicilio;
}

void Venta::setEnvioADomicilio(bool envioADomicilio)
{
    this->envioADomicilio = envioADomicilio;
}

bool Venta::buscarVendedor(int id)
{
    Empleado e;
    int pos = 0;
    while (e.leerDeDisco(pos++))
    {
        if (id == e.getID())return 1;
    }
    return 0;
}

bool Venta::buscarProducto(int codigo)
{
    Producto p;
    int pos = 0;
    while (p.leerDeDisco(pos++))
    {
        if (p.getCodigo() == codigo) return true;
    }
    return false;
}

bool Venta::buscarCliente(int dni)
{
    Cliente c;
    int pos = 0;
    while (c.leerDeDisco(pos++))
    {
        if (c.getDni() == dni)return true;
    }
    return false;
}

Cliente Venta::cargarCliente(int dni)
{
    Cliente c;
    int pos = 0;
    while (c.leerDeDisco(pos++))
    {
        if (c.getDni() == dni) return c;
    }
}

Empleado Venta::cargarEmpleado(int id)
{
    Empleado e;
    int pos = 0;
    while (e.leerDeDisco(pos++))
    {
        if (e.getID() == id) return e;
    }
}
/* int cantidadComprada, cantidadCuotas, descuentoPorCantidad;
	Direccion direccionLocal;
	Producto productoComprado;
	FechaHora fechaYHoraDeLaVenta;
	Cliente cliente;
	Empleado vendedor;
	char metodoPago;
	bool envioADomicilio; */

int Venta::getIDVendedor()
{
    return IDVendedor;
}

void Venta::setIDVendedor(int IDVendedor)
{
    this->IDVendedor = IDVendedor;
}

int Venta::getCodigoProducto()
{
    return codigoProducto;
}

void Venta::setCodigoProducto(int codigoProducto)
{
    this->codigoProducto = codigoProducto;
}

int Venta::getDniCliente()
{
    return dniCliente;
}

void Venta::setDniCliente(int dniCliente)
{
    this->dniCliente = dniCliente;
}

void Venta::cargar() {
    bool bandera = false;
    Cliente c;
    Producto producto;
    do {
        std::cout << "Código del producto: ";
        std::cin >> codigoProducto;
        if (!buscarProducto(codigoProducto))
        {
            std::cout << std::endl << std::endl << "No se ha encontrado el producto. Por favor vuelva a intentarlo.";
            rlutil::anykey();
            rlutil::cls();
        }
        else bandera = true;
    } while (!bandera);
    std::cout << "Cantidad comprada: ";
    std::cin >> cantidadComprada;
    std::cout << "Cuotas: ";
    std::cin >> cantidadCuotas;
    do {
        std::cout << "Método de pago (e - efectivo/t - tarjeta): ";
        std::cin >> metodoPago;
        if (tolower(metodoPago) != 'e' && tolower(metodoPago) == 't') {
            std::cout << std::endl << std::endl << "Por favor ingrese una opción válida.";
            rlutil::anykey();
            rlutil::cls();
        }
    } while (tolower(metodoPago) != 'e' && tolower(metodoPago) == 't');
    std::cout << "¿Se envía al domicilio del cliente? (1 - Sí/0 - No): ";
    std::cin >> envioADomicilio;
    bandera = false;
    do {
        std::cout << "ID del vendedor: ";
        std::cin >> IDVendedor;
        if (!buscarVendedor(IDVendedor))
        {
            std::cout << std::endl << std::endl << "No se ha encontrado el vendedor. Por favor vuelva a intentarlo.";
            rlutil::anykey();
            rlutil::cls();
        }
        else bandera = true;
    } while (!bandera);
    std::cout << "DNI del cliente: ";
    std::cin >> dniCliente;
    if (!buscarCliente(dniCliente))
    {
        system("cls");
        std::cout << "NUEVO CLIENTE:" << std::endl << std::endl;
        c.cargar();
    }

    // Desarrollo del descuento por cantidad dependiendo la cantidad de compras
    if (cantidadComprada <= 25)
        descuentoPorCantidad = cantidadComprada / 5 * 10;
    else descuentoPorCantidad = 50;

    // Importe final de la compra
    costoFinal = producto.getPrecio() * cantidadComprada - producto.getPrecio() * cantidadComprada * descuentoPorCantidad / 100;

    // Costo por cuota
    if (cantidadCuotas > 0) costoCuota = costoFinal / cantidadCuotas;
    else costoCuota = costoFinal;
    numeroVenta = contVentas()+1;
    system("cls");
    if (grabarEnDisco()) std::cout << "Venta cargada con exito." << std::endl;
    system("pause");
    system("cls");
}

void Venta::mostrar() {
    if (estado)
    {
        Producto producto = buscarProducto(codigoProducto);
        Cliente cliente = cargarCliente(dniCliente);
        Empleado vendedor = cargarEmpleado(IDVendedor);
        std::cout << "Venta N°" << numeroVenta << std::endl << std::endl;
        std::cout << "--------------------------------------------------------------------------------------" << std::endl << std::endl;
        std::cout << "Producto: " << producto.getNombre() << std::endl;
        std::cout << "Cantidad: " << cantidadComprada << std::endl;
        if (metodoPago == tolower('e')) std::cout << "Metodo de pago: Efectivo";
        else std::cout << "Metodo de pago: Tarjeta";
        if (cantidadCuotas > 0)
            std::cout << cantidadCuotas << " cuotas de $" << costoCuota << std::endl;
        if (descuentoPorCantidad > 0) std::cout << "Descuento por cantidad de productos comprados: " << descuentoPorCantidad << std::endl << std::endl;
        std::cout << "Importe total: " << costoFinal << std::endl << std::endl;
        std::cout << "--------------------------------------------------------------------------------------" << std::endl << std::endl;
        std::cout << cliente.getNombre() << ' ' << cliente.getApellido() << std::endl;
        std::cout << "DNI: " << cliente.getDni() << std::endl << std::endl;
        std::cout << "Envío a domicilio: ";
        if (envioADomicilio) std::cout << "Sí";
        else std::cout << "No";
        std::cout << std::endl << std::endl << "Venta a cargo de: " << vendedor.getNombre() << ' ' << vendedor.getApellido() << std::endl;
        std::cout << "Vendedor N°: " << vendedor.getID() << std::endl << std::endl;
        std::cout << "--------------------------------------------------------------------------------------" << std::endl << std::endl;
        std::cout << "Fecha: \t";
        fechaYHoraDeLaVenta.mostrarFecha();
        std::cout << std::endl << "Hora: \t";
        fechaYHoraDeLaVenta.mostrarHora();
    }
}

bool Venta::grabarEnDisco()
{
    FILE* p = NULL;
    p = fopen("ventas.dat", "ab");
    if (p == NULL)
    {
        std::cout << "Error al guardar.\n";
        system("pause");
        return 0;
    }
    fwrite(this, sizeof(Venta), 1, p);
    fclose(p);
    return 1;
}

bool Venta::leerDeDisco(int pos)
{
    FILE* p = NULL;
    p = fopen("ventas.dat", "rb");
    if (p == NULL)
    {
        std::cout << "Error al abrir.\n";
        system("pause");
        return 0;
    }
    fseek(p, pos * sizeof(Venta), 0);
    bool leyo=fread(this, sizeof(Venta), 1, p);
    fclose(p);
    return leyo;
}

int Venta::contVentas()
{
    FILE* p = fopen("ventas.dat", "rb");
    if (p == NULL) {
        return 0; ///cantidad de registros cero 0
    }
    size_t bytes;
    int cant_reg;

    fseek(p, 0, SEEK_END);
    bytes = ftell(p);
    fclose(p);
    cant_reg = bytes / sizeof(Venta);
    return cant_reg;
}

void Venta::modificarVenta() {
    bool bandera;
    int opcion, ingreso, n, nReg;
    do {
        std::cout << "Ingrese el número de venta a modificar o 0 para volver: ";
        std::cin >> n;
        nReg = buscarRegistro(n);
        if (nReg > 0)
        {
            do
            {
                mostrar();
                std::cout << std::endl << std::endl;
                std::cout << "¿Qué desea modificar?" << std::endl << std::endl;
                std::cout << "1-Cantidad Comprada" << std::endl;
                std::cout << "2-Cantidad de cuotas" << std::endl;
                std::cout << "3-Vendedor" << std::endl;
                std::cout << "4-Producto/s" << std::endl; // NO OLVIDARSE DE PERMITIR COMPRAR MAS DE UN PRODUCTO
                std::cout << "5-Cliente" << std::endl;
                std::cout << "6-Método de pago" << std::endl;
                std::cout << "7-Envío a domicilio" << std::endl;
                std::cout << "-------------------" << std::endl;
                std::cout << "------------------" << std::endl;
                std::cout << "0-Volver" << std::endl << std::endl;
                std::cout << "Ingrese una opción: ";
                std::cin >> opcion;
                rlutil::cls();
                switch (opcion)
                {
                case 1:
                    std::cout << "Ingrese el nuevo monto de cantidad comprada: ";
                    std::cin >> cantidadComprada;
                    break;
                case 2:
                    std::cout << "Ingrese la cantidad de cuotas a pagar:" << std::endl;
                    std::cin >> cantidadCuotas;
                    break;
                case 3:
                    std::cout << "Ingrese ID de vendedor: ";
                    std::cin >> IDVendedor;
                    break;
                case 4:
                    do {
                        std::cout << "1-Modificar producto/2-Eliminar producto" << std::endl << '>';
                        std::cin >> ingreso;
                        if (ingreso < 1 || ingreso > 2)
                        {
                            std::cout << "Por favor ingrese una opción válida.";
                            rlutil::anykey();
                        }
                        else if (ingreso == 1) {
                            std::cout << "Ingrese ID de producto: ";
                            std::cin >> codigoProducto;
                            rlutil::cls();
                            do {
                                std::cout << "¿Desea modificar o eliminar algún otro producto? 1-Sí/2-No." << std::endl << '>';
                                std::cin >> ingreso;
                                if (ingreso < 1 || ingreso > 2) {
                                    std::cout << "Por favor ingrese una opción válida.";
                                    rlutil::anykey();
                                }
                            } while (ingreso < 1 || ingreso > 2);
                        }
                        /*else
                        {

                        }*/
                    } while (ingreso == 1);
                    break;
                case 5:
                    std::cout << "Ingrese DNI del cliente: ";
                    std::cin >> dniCliente;
                    break;
                case 6:
                    bandera = false;
                    do
                    {
                        std::cout << "Ingrese el nuevo método de pago: " << std::endl;
                        std::cin >> metodoPago;
                        if (tolower(metodoPago) == 'e' || tolower(metodoPago) == 't') bandera = true;
                        else
                        {
                            rlutil::cls();
                            std::cout << "Error. Por favor ingrese una opción válida." << std::endl;
                            rlutil::anykey();
                        }
                    } while (!bandera);
                    rlutil::cls();
                    std::cout << "Método de pago modificado con éxito." << std::endl;
                    break;
                case 7:
                    if (envioADomicilio == false) envioADomicilio = true;
                    else envioADomicilio = false;
                    break;
                default:
                    if (opcion != 0)
                    {
                        std::cout << "Por favor ingrese una opción correcta.";
                    }
                    break;
                }
                if (opcion != 0) {
                    do
                    {
                        rlutil::cls();
                        std::cout << "¿Seguro de realizar la modificación? 1-Sí/2-Cancelar" << std::endl << '>';
                        std::cin >> ingreso;
                        if (ingreso < 1 || ingreso>2)
                        {
                            rlutil::cls();
                            std::cout << "Por favor ingrese una opción válida.";
                            rlutil::anykey();
                        }
                    } while (ingreso < 1 || ingreso>2);
                    if (ingreso == 1) {
                        if (modificarEnDisco(nReg - 1)) std::cout << "Modificación realizada con éxito.";
                        else std::cout << "Error al modificar.";
                        rlutil::anykey();
                    }
                }
            } while (opcion != 0);
        }
        else if (n != 0)
        {
            std::cout << "Error. No se ha encontrado la venta.";
            rlutil::anykey();
        }
        rlutil::cls();
    } while (n != 0);
}

void Venta::eliminarVenta() {
    int n, confirmar, reg;
    do {
        std::cout << "Ingrese el número de la venta que quiere eliminar o ingrese 0 para volver: ";
        std::cin >> n;
        reg = buscarRegistro(n);
        rlutil::cls();
        if (reg < 0) std::cout << "No se ha podido encontrar la venta.";
        else
        {
            if (estado) {
                rlutil::cls();
                mostrar();
                std::cout << std::endl << std::endl << "¿Seguro de eliminar la venta? Presione 1 para eliminar/2 para cancelar:" << std::endl;
                std::cin >> confirmar;
                rlutil::cls();
                if (confirmar == 1)
                {
                    estado = false;
                    if (modificarEnDisco(reg - 1)) std::cout << "Eliminada con exito.";
                    else std::cout << "Error al eliminar.";
                }
                else if (confirmar != 2) std::cout << "Por favor ingrese una opción válida.";
            }
            else std::cout << "No se ha podido encontrar la venta.";
        }
        if (n != 0) rlutil::anykey();
        rlutil::cls();
    } while (n != 0);
}

void Venta::listarVenta() {
    int opcion, d, pos, numeroReg;
    bool bandera = false;
    do
    {
        pos = 0;
        std::cout << "1-Listar todas las ventas" << std::endl;
        std::cout << "2-Listar una venta" << std::endl;
        std::cout << "-------------------" << std::endl;
        std::cout << "------------------" << std::endl;
        std::cout << "0-Volver" << std::endl << std::endl;
        std::cout << "Ingrese una opción: ";
        std::cin >> opcion;
        rlutil::cls();
        switch (opcion)
        {
        case 1:
            while (leerDeDisco(pos++))
            {
                mostrar();
                if (estado)std::cout << std::endl << std::endl;
            }
            break;
        case 2:
            std::cout << "Ingrese el número de ventaque quiere listar o 0 para volver: ";
            std::cin >> d;
            if (d != 0) {
                rlutil::cls();
                if (buscarRegistro(d) < 0) std::cout << "No se ha podido encontrar la venta.";
                else
                {
                    if (estado) {
                        bandera = true;
                        mostrar();
                    }
                    else std::cout << "No se ha podido encontrar la venta.";
                }
            }
            break;
        default:
            if (opcion != 0)
            {
                std::cout << "Por favor ingrese una opción correcta.";
            }
            break;
        }
        bandera = false;
        if (opcion != 0)rlutil::anykey();
        rlutil::cls();
    } while (opcion != 0);
}

bool Venta::modificarEnDisco(int pos) {
    FILE* p = NULL;
    p = fopen("clientes.dat", "rb+");
    if (p == NULL)return 0;
    fseek(p, pos * sizeof(Venta), 0);
    bool escribio = fwrite(this, sizeof(Venta), 1, p);
    fclose(p);
    return escribio;
}

int Venta::buscarRegistro(int n) {
    int pos = 0;
    while (leerDeDisco(pos++))
    {

        if (n == numeroVenta) return pos;

    }

    return -1;
}