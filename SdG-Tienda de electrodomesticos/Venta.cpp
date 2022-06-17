#include "Venta.h"

int Venta::getCantidadComprada() const
{
    return cantidadComprada;
}

void Venta::setCantidadComprada(int cantidadComprada)
{
    this->cantidadComprada = cantidadComprada;
}

int Venta::getCantidadCuotas() const
{
    return cantidadCuotas;
}

void Venta::setCantidadCuotas(int cantidadCuotas)
{
    this->cantidadCuotas = cantidadCuotas;
}

int Venta::getDescuentoPorCantidad() const
{
    return descuentoPorCantidad;
}

void Venta::setDescuentoPorCantidad(int descuentoPorCantidad)
{
    this->descuentoPorCantidad = descuentoPorCantidad;
}

Direccion Venta::getDireccionLocal() const
{
    return direccionLocal;
}

void Venta::setDireccionLocal(Direccion direccionLocal)
{
    this->direccionLocal = direccionLocal;
}

Producto Venta::getProductoComprado() const
{
    return productoComprado;
}

void Venta::setProductoComprado(Producto productoComprado)
{
    this->productoComprado = productoComprado;
}

FechaHora Venta::getFechaYHoraDeLaVenta() const
{
    return fechaYHoraDeLaVenta;
}

void Venta::setFechaYHoraDeLaVenta(FechaHora fechaYHoraDeLaVenta)
{
    this->fechaYHoraDeLaVenta = fechaYHoraDeLaVenta;
}

Cliente Venta::getCliente() const
{
    return cliente;
}

void Venta::setCliente(Cliente cliente)
{
    this->cliente = cliente;
}

Vendedor Venta::getVendedor() const
{
    return vendedor;
}

void Venta::setVendedor(Vendedor vendedor)
{
    this->vendedor = vendedor;
}

char Venta::getMetodoPago() const
{
    return metodoPago;
}

void Venta::setMetodoPago(char metodoPago)
{
    this->metodoPago = metodoPago;
}

bool Venta::getEnvioADomicilio() const
{
    return envioADomicilio;
}

void Venta::setEnvioADomicilio(bool envioADomicilio)
{
    this->envioADomicilio = envioADomicilio;
}

