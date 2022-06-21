#include "Venta.h"

Venta::Venta() {
    // Valores por omisión
    cantidadComprada = cantidadCuotas = 0;
    metodoPago = '-';
    envioADomicilio = false;
    estado = true;

    // Desarrollo del descuento por cantidad dependiendo la cantidad de compras
    if (cantidadComprada<=25)
    {
        descuentoPorCantidad = cantidadComprada / 5 * 10;
    }
    else
    {
        descuentoPorCantidad = 50;
    }

    // Importe final de la compra
    if (descuentoPorCantidad > 0)costoFinal = productoComprado.getPrecio() * cantidadComprada - productoComprado.getPrecio() * cantidadComprada * descuentoPorCantidad / 100;
    else costoFinal = productoComprado.getPrecio();

    // Costo por cuota
    if (cantidadCuotas > 0) costoCuota = costoFinal / cantidadCuotas;
    else costoCuota = costoFinal;

    // Numero de venta
    numeroVenta = contRegistros() + 1;
}

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
Producto Venta::getProductoComprado()
{
    return productoComprado;
}

void Venta::setProductoComprado(Producto productoComprado)
{
    this->productoComprado = productoComprado;
}

FechaHora Venta::getFechaYHoraDeLaVenta()
{
    return fechaYHoraDeLaVenta;
}

void Venta::setFechaYHoraDeLaVenta(FechaHora fechaYHoraDeLaVenta)
{
    this->fechaYHoraDeLaVenta = fechaYHoraDeLaVenta;
}

Cliente Venta::getCliente()
{
    return cliente;
}

void Venta::setCliente(Cliente cliente)
{
    this->cliente = cliente;
}

Empleado Venta::getVendedor()
{
    return vendedor;
}

void Venta::setVendedor(Empleado vendedor)
{
    this->vendedor = vendedor;
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

Empleado Venta::buscarVendedor()
{
    Empleado e;
    int pos, id;
    while (true)
    {
        pos = 0;
        std::cout << "ID del vendedor: ";
        std::cin >> id;
        while (e.leerDeDisco(pos++))
        {
            if (e.getID() == id) return e;
        }
        std::cout << "No se ha encotrado al vendedor. Por favor ingrese un ID existente\n";
        system("pause");
        system("cls");
    }
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
       if(c.getDni()==dni) return c;
    }
}

int Venta::contRegistros()
{
    int bytes;
    FILE* p;
    p = fopen("ventas.dat", "rb");
    if (p == NULL) {
        return 0;
    }
    fseek(p, 0, SEEK_END);
    bytes = ftell(p);
    fclose(p);
    return bytes / sizeof(Venta);
}

void Venta::cargar() {
    int dniCliente;
    std::cout << "Cantidad comprada: ";
    std::cin >> cantidadComprada;
    std::cout << "Cuotas: ";
    std::cin >> cantidadCuotas;
    std::cout << "Método de pago (e - efectivo/t - tarjeta): ";
    std::cin >> metodoPago;
    std::cout << "¿Se envía al domicilio del cliente? (1 - Sí/2 - No): ";
    std::cin >> envioADomicilio;
    vendedor = buscarVendedor();
    std::cout << "DNI del cliente: ";
    std::cin >> dniCliente;
    if (buscarCliente(dniCliente)) cliente = cargarCliente(dniCliente);
    else {
        system("cls");
        std::cout << "NUEVO CLIENTE:" << std::endl << std::endl;
        cliente.cargar();
    }

    // Desarrollo del descuento por cantidad dependiendo la cantidad de compras
    if (cantidadComprada <= 25)
        descuentoPorCantidad = cantidadComprada / 5 * 10;
    else descuentoPorCantidad = 50;

    // Importe final de la compra
    if (descuentoPorCantidad > 0)costoFinal = productoComprado.getPrecio() * cantidadComprada - productoComprado.getPrecio() * cantidadComprada * descuentoPorCantidad / 100;
    else costoFinal = productoComprado.getPrecio();

    // Costo por cuota
    if (cantidadCuotas > 0) costoCuota = costoFinal / cantidadCuotas;
    else costoCuota = costoFinal;

    system("cls");
    if (grabarEnDisco()) std::cout << "Venta cargada con exito." << std::endl;
    system("pause");
    system("cls");
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
    p = fopen("ventas.dat", "rb+");
    if (p == NULL)
    {
        std::cout << "Error al abrir.\n";
        system("pause");
        return 0;
    }
    fseek(p, pos * sizeof(Venta), 0);
    fread(this, sizeof(Venta), 1, p);
    fclose(p);
    return 1;
}


void Venta::mostrar() {
    if (estado)
    {
        std::cout << "Venta N°" << numeroVenta << std::endl << std::endl;
        std::cout << "--------------------------------------------------------------------------------------" << std::endl << std::endl;
        std::cout << "Producto: " << productoComprado.getNombre() << std::endl;
        std::cout << "Cantidad: " << cantidadComprada << std::endl;
        if (metodoPago == tolower('e')) std::cout << "Metodo de pago: Efectivo";
        else std::cout << "Metodo de pago: Efectivo";
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

/* int cantidadComprada, cantidadCuotas, descuentoPorCantidad;
	Direccion direccionLocal;
	Producto productoComprado;
	FechaHora fechaYHoraDeLaVenta;
	Cliente cliente;
	Empleado vendedor;
	char metodoPago;
	bool envioADomicilio; */

