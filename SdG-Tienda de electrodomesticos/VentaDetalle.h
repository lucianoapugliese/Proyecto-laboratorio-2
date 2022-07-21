#pragma once
#include "Cliente.h"
#include "Empleado.h"
#include "Producto.h"

class VentaDetalle
{
private:
	int cantidadComprada, descuentoPorCantidad, codigoProducto, numeroVenta;
	float importePorProducto;
	bool estado;
public:
	float getImportePorProducto() { return importePorProducto; }
	int getNumeroVenta() { return numeroVenta; }
	void setNumeroVenta(int _numeroVenta) { numeroVenta=_numeroVenta; }
	int getCantidadComprada() { return cantidadComprada; }
	void setCantidadComprada(int _cantidadComprada) { cantidadComprada = _cantidadComprada; }
	int getCodigoProducto() { return codigoProducto; }
	void setCodigoProducto(int _codigoProducto) { codigoProducto = _codigoProducto; }
	bool getEstado() { return estado; }
	void setEstado(bool e) { estado = e; }
	void cargar();
	void mostrar();
	bool leerDeDisco(int);
	bool grabarEnDisco();
	bool buscarProducto(int);
};