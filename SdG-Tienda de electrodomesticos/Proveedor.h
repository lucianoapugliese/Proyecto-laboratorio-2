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
	char _NombreEmpresa[50];
	char _Telefono[30];
	char _DireccionFiscal[50];
	char _email[50];
	FechaHora _FechaDeFactura;
	char _NumeroFactura[20];
	char _RegistroDePago[20];
	bool estado;
public:
	void SetNumeroCliente(int);
	void SetCuit(const char*);
	void SetNombreEmpresa(std::string);
	void SetTelefono(const char*);
	void SetDireccionFisical(std::string);
	void SetEmail(const char*);
	void SetFechaFactura(FechaHora);
	void SetNumeroFactura(const char*);
	void SetRegistroDePago(const char*);
	bool getEstado() { return estado; }

	int   GetNumeroCliente();
	char* GetCuit();
	std::string GetNombreEmpresa();
	char* GetTelefono();
	std::string GetDireccionFiscal();
	char* GetEmail();
	FechaHora GetFecha();
	char* GetNumeroFactura();
	char* GetRegistroDepago();
	void setEstado(bool _estado) { estado = _estado; }

	bool leerDeDisco(int);
	bool grabarEnDisco();

	void mostrar();
	void cargar();
	int contProveedores();
	void modificarProveedores();
	void eliminarProveedores();
	void listarProveedores();
	bool modificarEnDisco(int);
	int buscarRegistro(int);
};