#include "Reporte.h"

void Reporte::mesMayorVenta()
{
	VentaCabecera venta;
	int meses[12] = { }, pos=0, mayorMes=0, mayorCant;
	while (venta.leerDeDisco(pos++))
	{
		meses[venta.getFechaYHoraDeLaVenta().getMes() - 1]++;
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
	/*
	Producto producto;
	Venta venta;
	int pos = 0, pos2, idMasVendido, cantMasVendido, ventasProd;
	bool primerRegistro = false;
	while (producto.leerDeDisco(pos++)) // Lee todos los productos
	{
		pos2 = 0;
		ventasProd = 0;
		while (venta.leerDeDisco(pos2++))
		{
			if (producto.getCodigo()==venta.getCodigoProducto())
			{

			}
		}
	} */
}

void Reporte::vendedoresConMasVentas()
{
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
