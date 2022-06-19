#pragma once
#include <iostream>
#include "Direccion.h"
#include "FechaHora.h"
#include "Producto.h"
#include "Cliente.h"
#include "Vendedor.h"

class Venta
{
private:
	int cantidadComprada, cantidadCuotas, descuentoPorCantidad;
	Direccion direccionLocal;
	Producto productoComprado;
	FechaHora fechaYHoraDeLaVenta;
	Cliente cliente;
	Vendedor vendedor;
	char metodoPago;
	bool envioADomicilio;
public:
	void cargar();
	void mostrar();
	bool grabarEnDisco();
	bool leerDeDisco(int pos);
    int getCantidadComprada() const;
    void setCantidadComprada(int cantidadComprada);

    int getCantidadCuotas() const;
    void setCantidadCuotas(int cantidadCuotas);

    int getDescuentoPorCantidad() const;
    void setDescuentoPorCantidad(int descuentoPorCantidad);

    Direccion getDireccionLocal() const;
    void setDireccionLocal(Direccion direccionLocal);

    Producto getProductoComprado() const;
    void setProductoComprado(Producto productoComprado);

    FechaHora getFechaYHoraDeLaVenta() const;
    void setFechaYHoraDeLaVenta(FechaHora fechaYHoraDeLaVenta);

    Cliente getCliente() const;
    void setCliente(Cliente cliente);

    Vendedor getVendedor() const;
    void setVendedor(Vendedor vendedor);

    char getMetodoPago() const;
    void setMetodoPago(char metodoPago);

    bool getEnvioADomicilio() const;
    void setEnvioADomicilio(bool envioADomicilio);

};
