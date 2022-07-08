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
	int numeroVenta, cantidadComprada, cantidadCuotas, descuentoPorCantidad, IDVendedor, codigoProducto, dniCliente;
	FechaHora fechaYHoraDeLaVenta;
	char metodoPago;
	bool envioADomicilio, estado;
    float costoFinal, costoCuota;
    // solo id del vendedor, producto y dni del cliente
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

    FechaHora getFechaYHoraDeLaVenta();
    void setFechaYHoraDeLaVenta(FechaHora fechaYHoraDeLaVenta);

    char getMetodoPago();
    void setMetodoPago(char metodoPago);

    bool getEnvioADomicilio();
    void setEnvioADomicilio(bool envioADomicilio);

    bool buscarVendedor(int);
    Producto buscarProducto(int);
    bool buscarCliente(int dni);

    Cliente cargarCliente(int);
    Empleado cargarEmpleado(int);

    int contVentas();
    int getIDVendedor() ;
    void setIDVendedor(int IDVendedor);

    int getCodigoProducto() ;
    void setCodigoProducto(int codigoProducto);

    int getDniCliente() ;
    void setDniCliente(int dniCliente);

    void modificarVenta();
    void eliminarVenta();
    void listarVenta();
};
