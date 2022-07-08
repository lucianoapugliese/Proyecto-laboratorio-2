#include "Compra.h"

void Compra::SetNumeroDeFactura(int Num)
{
	_NumeroDeFactura = Num;

}

void Compra::setTipoDeCompra(int Tipo)
{
	TipoDeCompra = Tipo;
}

void Compra::SetFechadeCompra(FechaHora SFecha)
{
	FechaDeCompra = SFecha;
}

void Compra::SetModificarValor(float val)
{
	Valor = val;
}

void Compra::SetNombreDeProducto(const char* NombreProdu)
{
	strcpy(NombreDeProducto, NombreProdu);
}

void Compra::SetCantidadComprada(float CantCompra)
{
	Cantidad = CantCompra;
}

int Compra::GetNumeroDeFac()
{
	return _NumeroDeFactura;
}

int Compra::GetTipoDeCompra()
{
	return TipoDeCompra;
}

FechaHora Compra::GetFechaDeLaCompra()
{
	return FechaHora();
}

float Compra::GetCostoDelProducto()
{
	return Valor;
}
char* Compra::GetNombreDeProducto()
{
	return NombreDeProducto;
}

float Compra::GetCantidadDeProductos()
{
	return Cantidad;
}

bool Compra::LeerDeDisco(int pos)
{
	FILE* p;
	p = fopen("Compra.dat", "rb");
	if (p == NULL) { return false; }
	fseek(p, pos * sizeof(Compra), 0);
	fread(this, sizeof(Compra), 1, p);
	fclose(p);
	return true;
}

bool Compra::GuardarEnDisco()
{
	FILE* p;
	p = fopen("Compra.dat", "ab");
	if (p == NULL) { return false; }

	fwrite(this, sizeof(Compra), 1, p);
	fclose(p);
	return true;
}

void Compra::Mostrar()
{
	std::cout << _NumeroDeFactura;
	std::cout << TipoDeCompra;
	FechaDeCompra.mostrarFecha();
	std::cout << Valor;
	std::cout << NombreDeProducto;
	std::cout << Cantidad;
}

void Compra::Cargar()
{
	std::cout << "Numero de Factura: ";
	std::cin >> _NumeroDeFactura;
	std::cout << "Tipo de Compra 1 , 2 , 3 ";
	std::cin >> TipoDeCompra;
	std::cout << "Cargar la Fecha de compra ";
	FechaDeCompra.cargarFecha();
	std::cout << "Cargar Precio ,Valor";
	std::cin >> Valor;
	std::cout << "Cantidad de compra Dentro del bulto";
	std::cin >> Cantidad;
}