#pragma once
#include <iostream>
#include "Direccion.h"
#include "FechaHora.h"
#include "Producto.h"
#include "Cliente.h"
#include "Empleado.h"
#include "Proveedor.h"
class Compra
{
private:
	int _NumeroDeFactura;////ENTEROS GENERADOS AUTOMÁTICAMENTE
	int codigoProducto;
	int numeroClienteProveedor;
	FechaHora FechaDeCompra;   /////// FECHA DE LA COMPRA
	float Valor;               ////////////// COSTO DE LA MERCADERIA
	float Cantidad;  
	bool estado; ///// CANTIDAD SE VENDE POR BULTO PERO CONTIENE UNA CANTIDAD DISTINTA POR PRODUCTOS
public:
	void SetNumeroDeFactura(int);
	void SetFechadeCompra(FechaHora);
	void SetModificarValor(float);
	void SetCantidadComprada(float);
	int GetNumeroDeFac();
	FechaHora GetFechaDeLaCompra();
	float GetCostoDelProducto();
	float GetCantidadDeProductos();
	int buscarRegistro(int);
	bool LeerDeDisco(int);
	bool GuardarEnDisco();
	int contRegistros();
	void Mostrar();
	void Cargar();
	bool modificarEnDisco(int);
	void listarCompra();
	void eliminarCompra();
	bool buscarProducto(int);
	bool buscarProveedor(int);
};

