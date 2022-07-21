#pragma once
#include "Cliente.h"
#include "Empleado.h"
#include "Producto.h"
#include "VentaDetalle.h"

class VentaCabecera
{
private:
	int numeroVenta, cantidadCuotas, IDVendedor, dniCliente;
	FechaHora fechaYHoraDeLaVenta;
	char metodoPago;
	bool envioADomicilio, estado;
	float importeFinal, importeCuota;
    VentaDetalle ventaDetalle;
public:
    void cargar();
    void mostrar();
    bool grabarEnDisco();
    bool leerDeDisco(int pos);

    int getNumeroVenta() { return numeroVenta; }

    bool getEstado() { return estado; }
    void setEstado(bool estado) { this->estado = estado; }

    int getCantidadCuotas() { return cantidadCuotas; }
    void setCantidadCuotas(int cantidadCuotas) { this->cantidadCuotas = cantidadCuotas; }
    FechaHora getFechaYHoraDeLaVenta() { return fechaYHoraDeLaVenta; }
    void setFechaYHoraDeLaVenta(FechaHora fechaYHoraDeLaVenta) { this->fechaYHoraDeLaVenta = fechaYHoraDeLaVenta; }

    char getMetodoPago() { return metodoPago; }
    void setMetodoPago(char metodoPago) { this->metodoPago = metodoPago; }

    bool getEnvioADomicilio() { return envioADomicilio; }
    void setEnvioADomicilio(bool envioADomicilio) { this->envioADomicilio = envioADomicilio; }

    bool buscarVendedor(int);
    bool buscarProducto(int);
    bool buscarCliente(int);
    int contVentas();
    int getIDVendedor() { return IDVendedor; }
    void setIDVendedor(int IDVendedor) { this->IDVendedor = IDVendedor; }
    int getDniCliente() { return dniCliente; }
    void setDniCliente(int dniCliente) { this->dniCliente = dniCliente; }

    void modificarVenta();
    void eliminarVenta();
    void listarVenta();
    int buscarRegistro(int);
    bool modificarEnDisco(int);

};

