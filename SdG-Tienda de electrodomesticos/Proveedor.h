#pragma once
#include <iostream>
#include "Direccion.h"
#include "FechaHora.h"
#include "Producto.h"
#include "Cliente.h"
#include "Empleado.h"
class Proveedor
{
private:
	int _NumeroCliente;
	char _cuit[12];
	char _NombreEmpresa[20];
	char _Telefono[30];
	char _DireccionFiscal[30];
	char _email[30];
	FechaHora _FechaDeFactura;
	char _NumeroFactura[20];
	char _RegistroDePago[20];

public:

	void SetNumeroCliente(int);
	void SetCuit(const char*);
	void SetNombreEmpresa(const char*);
	void SetTelefono(const char*);
	void SetDireccionFisical(const char*);
	void SetEmail(const char*);
	void SetFechaFactura(FechaHora);
	void SetNumeroFactura(const char*);
	void SetRegistroDePago(const char*);

	int   GetNumeroCliente();
	char*   GetCuit();
	char* GetNombreEmpresa();
	char* GetTelefono();
	char* GetDireccionFiscal();
	char* GetEmail();
	FechaHora GetFecha();
	char* GetNumeroFactura();
	char* GetRegistroDepago();

	bool LeeerDeDisco(int);
	bool GrabarEnDisco();

	void Mostrar();
	void Cargar();


};