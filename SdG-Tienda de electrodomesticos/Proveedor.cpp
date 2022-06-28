#include "Proveedor.h"

void Proveedor::SetNumeroCliente(int Cliente)
{
	_NumeroCliente = Cliente;
}

void Proveedor::SetCuit(int cuit)
{
	_cuit = cuit;
}

void Proveedor::SetNombreEmpresa(const char* nombreEmpresa)
{
	strcpy(_NombreEmpresa, nombreEmpresa);
}

void Proveedor::SetTelefono(const char* telefono)
{
	strcpy(_Telefono, telefono);
}

void Proveedor::SetDireccionFisical(const char* DireccionFiscal)
{
	strcpy(_DireccionFiscal, DireccionFiscal);
}

void Proveedor::SetEmail(const char* email)
{
	strcpy(_email, email);
}

void Proveedor::SetFechaFactura(FechaHora FechaProveedor)
{
	_FechaDeFactura = FechaProveedor;
}

void Proveedor::SetNumeroFactura(const char* numeroFactura)
{
	strcpy(_NumeroFactura, numeroFactura);
}

char Proveedor::SetRegistroDePago(const char* RegistroPago)
{
	strcpy(_RegistroDePago, RegistroPago);
}

int Proveedor::GetNumeroCliente()
{
	return _NumeroCliente;
}

int Proveedor::GetCuit()
{
	return _cuit;
}

char* Proveedor::GetNombreEmpresa()
{
	return _NombreEmpresa;
}

char* Proveedor::GetTelefono()
{
	return _Telefono;
}

char* Proveedor::GetDireccionFiscal()
{
	return _DireccionFiscal;
}

char* Proveedor::GetEmail()
{
	return _email;
}

FechaHora Proveedor::GetFecha()
{
	return FechaHora();
}

char* Proveedor::GetNumeroFactura()
{
	return _NumeroFactura;
}

char* Proveedor::GetRegistroDepago()
{
	return _RegistroDePago;
}

bool Proveedor::LeeerDeDisco(int pos)
{
	FILE* p;
	p = fopen("Proveedores.dat", "rb+");
	if (p == NULL) { return false; }
	fseek(p, sizeof(Proveedor) * pos, 0);
	fread(this, sizeof(Proveedor), 1, p);
	fclose(p);
	return true;
}

bool Proveedor::GrabarEnDisco()
{
	FILE* p;
	p = fopen("Proveedores.dat", "ab");
	if (p == NULL) { return false; }
	fwrite(this, sizeof(Proveedor), 1, p);
	fclose(p);

	return true;
}


void Proveedor::Mostrar()
{
	int _NumeroCliente;
	int _cuit;
	char _NombreEmpresa[20];
	char _Telefono[30];
	char _DireccionFiscal[30];
	char _email[30];
	FechaHora _FechaDeFactura;
	char _NumeroFactura[20];
	char _RegistroDePago[20];
	std::cout << _NumeroCliente;
	std::cout << _cuit;
	std::cout << _NombreEmpresa;
	std::cout << _Telefono;
	std::cout << _DireccionFiscal;
	std::cout << _email;
	_FechaDeFactura.mostrarFecha();
	std::cout << _NumeroFactura;
	std::cout << _RegistroDePago;
}

void Proveedor::Cargar()
{
	std::cout << "Numero de Cliente: ";
	std::cin >> _NumeroCliente;
	std::cout << "Cuit  ";
	std::cin >> _cuit;
	std::cout << "Nombre de Empresa ";
	std::cin >> _NombreEmpresa;
	std::cout << "Telefono";
	std::cin >> _Telefono;
	std::cout << "Direccion Fiscal ";
	std::cin >> _DireccionFiscal;
	std::cout << "Email ";
	std::cin >> _email;
	std::cout << "Fecha De Factura ";
	_FechaDeFactura.mostrarFecha();
	std::cout << "Numero De Factura ";
	std::cin >> _NumeroFactura;
	std::cout << "Registro De Pago";
	std::cin >> _RegistroDePago;
