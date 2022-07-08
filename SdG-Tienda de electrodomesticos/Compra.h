#pragma once
#include <iostream>
#include "Direccion.h"
#include "FechaHora.h"
#include "Producto.h"
#include "Cliente.h"
#include "Empleado.h"
class Compra
{
private:
	int _NumeroDeFactura;////ENTEROS GENERADOS AUTOMÁTICAMENTE
	int TipoDeCompra;         ////TIPO DE COMPRA 1-LINEA BLANCA 2-ELECTRONICA 3 VIDEOS JUEGOS 
	FechaHora FechaDeCompra;   /////// FECHA DE LA COMPRA
	float Valor;               ////////////// COSTO DE LA MERCADERIA
	char NombreDeProducto[30]; ////////////// NOMBRE DEL BULTO / PRODUCTO EJMEPLO TVSMART 80 , PLAYSTATION 5 , AFEITADORA , ETC.
	float Cantidad;            ///// CANTIDAD SE VENDE POR VULTO PERO CONTIENE UNA CANTIDAD DISTINTA POR PRODUCTOS
public:
	void SetNumeroDeFactura(int);
	void setTipoDeCompra(int);
	void SetFechadeCompra(FechaHora);
	void SetModificarValor(float);
	void SetNombreDeProducto(const char*);
	void SetCantidadComprada(float);
	int GetNumeroDeFac();
	int GetTipoDeCompra();
	FechaHora GetFechaDeLaCompra();
	float GetCostoDelProducto();
	char* GetNombreDeProducto();
	float GetCantidadDeProductos();

	bool LeerDeDisco(int);
	bool GuardarEnDisco();

	void Mostrar();
	void Cargar();

};

