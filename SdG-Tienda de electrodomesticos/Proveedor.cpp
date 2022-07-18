#include "Proveedor.h"

void Proveedor::SetNumeroCliente(int Cliente)
{
	_NumeroCliente = Cliente;
}

void Proveedor::SetCuit(const char* cuit)
{
	strcpy(_cuit, cuit);
}

void Proveedor::SetNombreEmpresa(std::string nombreEmpresa)
{
	strcpy(_NombreEmpresa, nombreEmpresa.c_str());
}

void Proveedor::SetTelefono(const char* telefono)
{
	strcpy(_Telefono, telefono);
}

void Proveedor::SetDireccionFisical(std::string DireccionFiscal)
{
	strcpy(_DireccionFiscal, DireccionFiscal.c_str());
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

void Proveedor::SetRegistroDePago(const char* RegistroPago)
{
	strcpy(_RegistroDePago, RegistroPago);
}

int Proveedor::GetNumeroCliente()
{
	return _NumeroCliente;
}

char* Proveedor::GetCuit()
{
	return _cuit;
}

std::string Proveedor::GetNombreEmpresa()
{
	std::string pal = _NombreEmpresa;
	return pal;
}

char* Proveedor::GetTelefono()
{
	return _Telefono;
}

std::string Proveedor::GetDireccionFiscal()
{
	std::string pal = _DireccionFiscal;
	return pal;
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

bool Proveedor::leerDeDisco(int pos)
{
	FILE* p;
	p = fopen("proveedores.dat", "rb");
	if (p == NULL) { return false; }
	fseek(p, sizeof(Proveedor) * pos, 0);
	bool leyo = fread(this, sizeof(Proveedor), 1, p);
	fclose(p);
	return leyo;
}

bool Proveedor::grabarEnDisco()
{
	FILE* p;
	p = fopen("proveedores.dat", "ab");
	if (p == NULL) { return false; }
	fwrite(this, sizeof(Proveedor), 1, p);
	fclose(p);

	return true;
}


void Proveedor::mostrar()
{
	if (estado) {
		std::cout << "Cliente N°" << _NumeroCliente << std::endl;
		std::cout << "Cuit: " << _cuit << std::endl;
		std::cout << "Empresa: " << _NombreEmpresa << std::endl;
		std::cout << "Tel: " << _Telefono << std::endl;
		std::cout << "Dirección fiscal: " << _DireccionFiscal << std::endl;
		std::cout << "Email: " << _email << std::endl;
		std::cout << "Fecha: ";
		_FechaDeFactura.mostrarFecha();
		std::cout << "Factura N°" << _NumeroFactura << std::endl;
		std::cout << "Registro de pago: " << _RegistroDePago;
	}
}

void Proveedor::cargar()
{
	std::cout << "Numero de Cliente: ";
	std::cin >> _NumeroCliente;
	std::cout << "Cuit: ";
	std::cin >> _cuit;
	std::cout << "Nombre de Empresa: ";
	std::cin >> _NombreEmpresa;
	std::cout << "Telefono:";
	std::cin >> _Telefono;
	std::cout << "Direccion Fiscal: ";
	std::cin >> _DireccionFiscal;
	std::cout << "Email ";
	std::cin >> _email;
	std::cout << "Fecha De Factura: " << std::endl;
	_FechaDeFactura.mostrarFecha();
	std::cout << "Numero De Factura: ";
	std::cin >> _NumeroFactura;
	std::cout << "Registro De Pago: ";
	std::cin >> _RegistroDePago;
	estado = true;
}