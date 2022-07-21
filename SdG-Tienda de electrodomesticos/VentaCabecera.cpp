#include "VentaCabecera.h"

void VentaCabecera::cargar()
{
    VentaDetalle ventaDetalle;
    Producto producto;
	bool salir = false;
    int confirmar, pos = 0;
    numeroVenta = contVentas() + 1;
    estado = true;
	do
	{
		ventaDetalle.cargar();
        ventaDetalle.setNumeroVenta(numeroVenta);
		rlutil::cls();
		do
		{
			std::cout << "¿Agrega otro producto a la venta? 1-Sí/2-No: ";
			std::cin >> confirmar;
			if (confirmar < 1 || confirmar > 2) {
				std::cout << "Por favor ingrese una opción válida.";
				rlutil::anykey();
				rlutil::cls();
			}
		} while (confirmar < 1 || confirmar > 2);
		if (confirmar == 2)
		{
			salir = true;
		}
	} while (!salir);
	Cliente cliente;
    std::cout << "Cuotas: ";
    std::cin >> cantidadCuotas;
    do { // Comprobación de ingreso correcto
        std::cout << "Método de pago (e - efectivo/t - tarjeta): ";
        std::cin >> metodoPago;
        if (tolower(metodoPago) != 'e' && tolower(metodoPago) != 't') {
            std::cout << std::endl << std::endl << "Por favor ingrese una opción válida.";
            rlutil::anykey();
            rlutil::cls();
        }
    } while (tolower(metodoPago) != 'e' && tolower(metodoPago) != 't');
    std::cout << "¿Se envía al domicilio del cliente? (1 - Sí/0 - No): ";
    std::cin >> envioADomicilio;
    salir = false;
    do { // Comprobación de existencia del archivo del vendedor
        std::cout << "ID del vendedor: ";
        std::cin >> IDVendedor;
        if (!buscarVendedor(IDVendedor))
        {
            std::cout << std::endl << std::endl << "No se ha encontrado el vendedor. Por favor vuelva a intentarlo.";
            rlutil::anykey();
            rlutil::cls();
        }
        else salir = true;
    } while (!salir);
    std::cout << "DNI del cliente: ";
    std::cin >> dniCliente;
    if (!buscarCliente(dniCliente)) // Si no lo encuentra, lo carga
    {
        system("cls");
        std::cout << "NUEVO CLIENTE:" << std::endl << std::endl;
        cliente.cargar(dniCliente);
    }
    importeFinal = 0; // Inicia en 0 para empezar a acumular
    while (ventaDetalle.leerDeDisco(pos++))
    {
        if (ventaDetalle.getNumeroVenta()==numeroVenta) // Busca los registros de la misma venta
        {
            importeFinal += ventaDetalle.getImportePorProducto(); // Acumula cada uno de la misma venta
        }
    }
    importeCuota = importeFinal / (float)cantidadCuotas;
    if (grabarEnDisco()) std::cout << "Venta cargada con exito." << std::endl;
}

void VentaCabecera::mostrar()
{
    VentaDetalle ventaDetalle;
    int pos = 0;
    bool primeraVuelta = false;
    Producto producto;
    Cliente cliente;
    Empleado vendedor;
    cliente.buscarRegistro(dniCliente);
    vendedor.buscarRegistro(IDVendedor);
    std::cout << "Venta N°" << numeroVenta << std::endl << std::endl;
    std::cout << "--------------------------------------------------------------------------------------" << std::endl << std::endl;
    while (ventaDetalle.leerDeDisco(pos++)) // Muestra todos los productos
    {
        if (numeroVenta == ventaDetalle.getNumeroVenta() && ventaDetalle.getEstado()) {  // Verifica que los productos sean de la misma venta
            if (!primeraVuelta)
            {
                ventaDetalle.mostrar();
                primeraVuelta = true;
            }
            else
            {
                std::cout << std::endl << std::endl << "-------------------------------------" << std::endl;
                ventaDetalle.mostrar();
            }
        }
    }
    std::cout << "Importe total: $" << importeFinal << std::endl << std::endl;
    std::cout << "--------------------------------------------------------------------------------------" << std::endl << std::endl;
    std::cout << "Comprador/a: " << cliente.getNombre() << ' ' << cliente.getApellido() << '\t';
    std::cout << "DNI: " << cliente.getDni() << std::endl << std::endl;
    std::cout << "Envío a domicilio: ";
    if (envioADomicilio) std::cout << "Sí";
    else std::cout << "No";
    std::cout << std::endl << std::endl << "Venta a cargo de: " << vendedor.getNombre() << ' ' << vendedor.getApellido() << std::endl;
    std::cout << "Vendedor N°: " << IDVendedor << std::endl << std::endl;
    std::cout << "--------------------------------------------------------------------------------------" << std::endl << std::endl;
    std::cout << "Fecha: \t";
    fechaYHoraDeLaVenta.mostrarFecha();
    std::cout << std::endl << "Hora: \t";
    fechaYHoraDeLaVenta.mostrarHora();
}

bool VentaCabecera::grabarEnDisco()
{
    FILE* p = NULL;
    p = fopen("ventasCabecera.dat", "ab");
    if (p == NULL)
    {
        std::cout << "Error al guardar.\n";
        return 0;
    }
    fwrite(this, sizeof(VentaCabecera), 1, p);
    fclose(p);
    return 1;
}

bool VentaCabecera::leerDeDisco(int pos)
{
    FILE* p = NULL;
    p = fopen("ventasCabecera.dat", "rb");
    if (p == NULL)
    {
        std::cout << "Todavía no se ha realizado ninguna venta.\n";
        return 0;
    }
    fseek(p, pos * sizeof(VentaCabecera), 0);
    bool leyo = fread(this, sizeof(VentaCabecera), 1, p);
    fclose(p);
    return leyo;
}

bool VentaCabecera::buscarVendedor(int id)
{
    Empleado e;
    int pos = 0;
    while (e.leerDeDisco(pos++))
    {
        if (id == e.getID() && e.getEstado())return 1;
    }
    return 0;
}

bool VentaCabecera::buscarProducto(int codigo)
{
    Producto p;
    int pos = 0;
    while (p.leerDeDisco(pos++))
    {
        if (p.getCodigo() == codigo && p.getEstado()) return true;
    }
    return false;
}

bool VentaCabecera::buscarCliente(int dni)
{
    Cliente c;
    int pos = 0;
    while (c.leerDeDisco(pos++))
    {
        if (c.getDni() == dni) {
            //if (c.getEstado())
            //{

            return true;
            //}
        }
    }
    return false;
}

int VentaCabecera::contVentas()
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
    cant_reg = bytes / sizeof(VentaCabecera);
    return cant_reg;
}

void VentaCabecera::modificarVenta()
{
    int opcion, ingreso, n, nReg;
    Producto producto;
    VentaDetalle ventaDetalle;
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
                std::cout << "1-Cantidad de cuotas" << std::endl;
                std::cout << "2-Método de pago" << std::endl;
                std::cout << "3-Envío a domicilio" << std::endl;
                std::cout << "-------------------" << std::endl;
                std::cout << "------------------" << std::endl;
                std::cout << "0-Volver" << std::endl << std::endl;
                std::cout << "Ingrese una opción: ";
                std::cin >> opcion;
                rlutil::cls();
                switch (opcion)
                {
                case 1:
                    std::cout << "Ingrese la cantidad de cuotas a pagar:" << std::endl;
                    std::cin >> cantidadCuotas;
                    break;
                case 2:
                    if (tolower(metodoPago) == 'e') metodoPago = 't';
                    else metodoPago = 'e';
                    break;
                case 3:
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
                    if (modificarEnDisco(nReg - 1)) std::cout << "Modificación realizada con éxito.";
                    else std::cout << "Error al modificar.";
                }
                rlutil::cls();
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

void VentaCabecera::eliminarVenta()
{
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

void VentaCabecera::listarVenta()
{
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
                if (estado)std::cout << std::endl << std::endl << "/////////////////////////////////////////" << std::endl << "/////////////////////////////////////////" << std::endl;
            }
            break;
        case 2:
            std::cout << "Ingrese el número de venta que quiere listar o 0 para volver: ";
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

int VentaCabecera::buscarRegistro(int n)
{
    int pos = 0;
    while (leerDeDisco(pos++))
    {

        if (n == numeroVenta) return pos;

    }

    return -1;
}

bool VentaCabecera::modificarEnDisco(int pos)
{
    FILE* p = NULL;
    p = fopen("ventasCabecera.dat", "rb+");
    if (p == NULL)return 0;
    fseek(p, pos * sizeof(VentaCabecera), 0);
    bool escribio = fwrite(this, sizeof(VentaCabecera), 1, p);
    fclose(p);
    return escribio;
}