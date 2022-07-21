#include "Reporte.h"

void Reporte::mesMayorVenta()
{
	VentaCabecera venta;
	int meses[12] = { }, pos=0, mayorMes=0, mayorCant;
	while (venta.leerDeDisco(pos++))
	{
		if(venta.getEstado()) meses[venta.getFechaYHoraDeLaVenta().getMes() - 1]++;
	}
	mayorCant = meses[0];
	for (int i = 0; i < 12; i++)
	{
		if (meses[i]>mayorCant)
		{
			mayorCant = meses[i];
			mayorMes = i;
		}
	}
	std::cout << "El mes con mayor cantidad de ventas es ";
	switch (mayorMes)
	{
	case 0:
		std::cout << "enero";
		break;
	case 1:
		std::cout << "febrero";
		break;
	case 2:
		std::cout << "marzo";
		break;
	case 3:
		std::cout << "abril";
		break;
	case 4:
		std::cout << "mayo";
		break;
	case 5:
		std::cout << "junio";
		break;
	case 6:
		std::cout << "julio";
		break;
	case 7:
		std::cout << "agosto";
		break;
	case 8:
		std::cout << "septiembre";
		break;
	case 9:
		std::cout << "octubre";
		break;
	case 10:
		std::cout << "noviembre";
		break;
	default:
		std::cout << "diciembre";
		break;
	}
	std::cout << " con un total de " << mayorCant << " ventas.";
	rlutil::anykey();
}

void Reporte::productoMasVendido()
{/*
	Producto producto;
	bool primeraVuelta = false;
	int *vec, pos=0, cantProductos = producto.contRegistros(), masVentas;
	vec = new int[cantProductos];
	if (vec == NULL) exit(0);
	while (producto.leerDeDisco(pos++))
	{
		vec[pos - 1] = producto.getCodigo();
		if (!primeraVuelta)
		{
			primeraVuelta = true;

		}
	}*/
	// La idea de abajo es la que mas cierra
	
	Producto producto;
	VentaDetalle venta;
	int pos = 0, pos2, codMasVendido, cantMasVendido, ventasProd;
	bool primerRegistro = false;
	while (producto.leerDeDisco(pos++)) // Lee todos los productos
	{
		pos2 = 0;
		ventasProd = 0;
		while (venta.leerDeDisco(pos2++))
		{
			if (producto.getCodigo() == venta.getCodigoProducto() && venta.getEstado() && producto.getEstado())
			{
				ventasProd += venta.getCantidadComprada();
			}
		}
		if (!primerRegistro)
		{
			primerRegistro = true;
			codMasVendido = producto.getCodigo();
			cantMasVendido = ventasProd;
		}
		if (ventasProd>cantMasVendido)
		{
			codMasVendido = producto.getCodigo();
			cantMasVendido = ventasProd;
		}
	}
	producto.buscarRegistro(codMasVendido);
	std::cout << "El producto más vendido es: " << producto.getNombre() << " con un total de " << cantMasVendido << " ventas.";
}

void Reporte::vendedoresConMasVentas()
{
	Empleado vendedor;
	VentaCabecera venta;
	int* vec, cantVendedores = 0, pos = 0, totalVentasVendedor, pos2;
	while (vendedor.leerDeDisco(pos++))
	{
		if (vendedor.getEstado() && vendedor.getCategoria() == 3)
		{
			cantVendedores++; // Cuenta vendedores
		}
	}
	vec = new int[cantVendedores]; // Pide memoria dinamica
	if (vec == NULL) exit(0);
	for (int i = 0; i < cantVendedores; i++)
	{
		vec[i] = 0;
	}
	cantVendedores = 0;
	while (vendedor.leerDeDisco(pos++)) // Lee todos los vendedores
	{
		if (vendedor.getEstado() && vendedor.getCategoria() == 3) // Busca que la categoria sea 3 y que no tenga baja logica
		{
			pos2 = 0;
			while (venta.leerDeDisco(pos2++)) // Busca todas la ventas
			{
				if (vendedor.getID() == venta.getIDVendedor() && venta.getEstado()) // Compara ids y corrobora que la venta no tenga baja logica
				{
					vec[cantVendedores]++; // Cuenta venta
				}
			}
			cantVendedores++; // Pasa al siguiente vendedor
		}
	}
	int aux;
	for (int i = 0; i < cantVendedores - 1; i++) { // Ordena de mayor a menor
		for (int j = i + 1; j < cantVendedores; j++) {
			if (vec[i] < vec[j]) {
				aux = vec[i];
				vec[i] = vec[j];
				vec[j] = aux;
			}
		}
	}
	pos = 0;
	int contVentasActual;
	std::cout << std::left << std::setw(25) << "Apellido" << std::setw(25) << "Nombre" << std::setw(25) << "Cantidad vendida" << std::endl << std::endl;
	for (int i = 0; i < cantVendedores; i++)
	{
		while (vendedor.leerDeDisco(pos++)) // Lee todos los vendedores
		{
			if (vendedor.getEstado() && vendedor.getCategoria() == 3) // Busca que la categoria sea 3 y que no tenga baja logica
			{
				contVentasActual = 0;
				pos2 = 0;
				while (venta.leerDeDisco(pos2++)) // Busca todas la ventas
				{
					if (vendedor.getID() == venta.getIDVendedor() && venta.getEstado()) // Compara ids y corrobora que la venta no tenga baja logica
					{
						contVentasActual++; // Cuenta venta
					}
				}
				if (contVentasActual==vec[i])
				{
					std::cout << std::left << std::setw(25) << vendedor.getApellido() << std::setw(25) << vendedor.getNombre() << std::setw(25) << contVentasActual << std::endl;
				}
			}
		}
	}
	delete vec;
}

void Reporte::mesesMenosVentas()
{
}

void Reporte::marcasMasVendidas()
{
}

void Reporte::recaudacionAnualVentas()
{
}
