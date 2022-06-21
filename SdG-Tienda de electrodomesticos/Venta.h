#pragma once
#include <iostream>
#include "Direccion.h"
#include "FechaHora.h"
#include "Producto.h"
#include "Cliente.h"
#include "Empleado.h"

class Venta
{
private:
	int numeroVenta, cantidadComprada, cantidadCuotas, descuentoPorCantidad;
	//Direccion direccionLocal;
	Producto productoComprado;
	FechaHora fechaYHoraDeLaVenta;
	Cliente cliente;
	Empleado vendedor;
	char metodoPago;
	bool envioADomicilio, estado;
    float costoFinal, costoCuota;
public:
    Venta();
	void cargar();
	void mostrar();
	bool grabarEnDisco();
	bool leerDeDisco(int pos);
    int getCantidadComprada();
    void setCantidadComprada(int);

    int getNumeroVenta() { return numeroVenta; }

    bool getEstado() { return estado; }
    void setEstado(bool estado) { this->estado = estado; }

    int getCantidadCuotas();
    void setCantidadCuotas(int cantidadCuotas);

    int getDescuentoPorCantidad();
    //void setDescuentoPorCantidad();

    //Direccion getDireccionLocal();
    //void setDireccionLocal(Direccion direccionLocal);

    Producto getProductoComprado();
    void setProductoComprado(Producto productoComprado);

    FechaHora getFechaYHoraDeLaVenta();
    void setFechaYHoraDeLaVenta(FechaHora fechaYHoraDeLaVenta);

    Cliente getCliente();
    void setCliente(Cliente cliente);

    Empleado getVendedor();
    void setVendedor(Empleado vendedor);

    char getMetodoPago();
    void setMetodoPago(char metodoPago);

    bool getEnvioADomicilio();
    void setEnvioADomicilio(bool envioADomicilio);

    Empleado buscarVendedor();
    bool buscarCliente(int dni);

    Cliente cargarCliente(int);

    int contRegistros();
};
