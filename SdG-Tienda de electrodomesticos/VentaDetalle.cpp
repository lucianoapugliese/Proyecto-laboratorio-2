#include "VentaDetalle.h"

void VentaDetalle::cargar()
{
    Producto producto;
    bool bandera = false;
    int numeroRegistro;
    estado = true;
    do {
        std::cout << "Código del producto: ";
        std::cin >> codigoProducto;
        numeroRegistro = producto.buscarRegistro(codigoProducto);
        // A continuación se comprueba si existe el producto, en caso de encontrarlo la bandera se activa y sale del while.
        if (numeroRegistro==-1)
        {
            std::cout << std::endl << std::endl << "No se ha encontrado el producto. Por favor vuelva a intentarlo.";
            rlutil::anykey();
            rlutil::cls();
        }
        else if (producto.getStock()<1) // Verificación del stock
        {
            std::cout << std::endl << std::endl << "No hay stock del producto. Por favor elija otro producto.";
            rlutil::anykey();
            rlutil::cls();
        }
        else bandera = true;
    } while (!bandera);
    bandera = false;
    do
    {
        std::cout << "Cantidad comprada: ";
        std::cin >> cantidadComprada;
        if (producto.getStock() < cantidadComprada) // Verificación del máximo de productos posibles a comprar
        {
            std::cout << std::endl << std::endl << "La cantidad indicada es menor al stock disponible. Por favor vuelva a intentarlo.";
            rlutil::anykey();
            rlutil::cls();
        }
        else bandera = true;
    } while (!bandera);
    producto.setStock(producto.getStock() - cantidadComprada); // Actualización de stock
    producto.modificarEnDisco(numeroRegistro - 1); // Actualización en disco
    // Desarrollo del descuento por cantidad dependiendo la cantidad de compras
    if (cantidadComprada <= 25) descuentoPorCantidad = cantidadComprada / 5 * 5; // Cada 5 productos hace un %5 de descuento hasta llegar a 25 productos.
    else descuentoPorCantidad = 25;
    importePorProducto = producto.getPrecio() * cantidadComprada - producto.getPrecio() * cantidadComprada * descuentoPorCantidad / 100; // Formula para aplicar el descuento
    grabarEnDisco();
}

void VentaDetalle::mostrar()
{
    Producto producto;
    float precio;
    if (estado)
    {
        producto.buscarRegistro(codigoProducto);
        std::cout << "Producto: " << producto.getNombre() << std::endl;
        std::cout << "Cantidad: " << cantidadComprada << std::endl;
        precio = producto.getPrecio() * cantidadComprada - producto.getPrecio() * cantidadComprada * descuentoPorCantidad / 100;
        if (descuentoPorCantidad > 0) std::cout << "Descuento por cantidad comprada: " << descuentoPorCantidad << '%' << std::endl << std::endl;
        std::cout << "Precio: $" << precio << std::endl << std::endl;
    }
}

bool VentaDetalle::leerDeDisco(int pos)
{
    FILE* p = NULL;
    p = fopen("ventasDetalle.dat", "rb");
    if (p == NULL)
    {
        std::cout << "Todavía no se ha realizado ninguna venta.\n";
        system("pause");
        return 0;
    }
    fseek(p, pos * sizeof(VentaDetalle), 0);
    bool leyo = fread(this, sizeof(VentaDetalle), 1, p);
    fclose(p);
    return leyo;
}

bool VentaDetalle::grabarEnDisco()
{
    FILE* p = NULL;
    p = fopen("ventasDetalle.dat", "ab");
    if (p == NULL)
    {
        std::cout << "Error al guardar.\n";
        system("pause");
        return 0;
    }
    fwrite(this, sizeof(VentaDetalle), 1, p);
    fclose(p);
    return 1;
}

bool VentaDetalle::buscarProducto(int cod)
{
    Producto p;
    int pos = 0;
    while (p.leerDeDisco(pos++))
    {
        if (p.getCodigo() == cod && p.getEstado()) return true;
    }
    return false;
}
