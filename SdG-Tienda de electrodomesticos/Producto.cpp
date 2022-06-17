#include "Producto.h"

char Producto::getNombre() const
{
    return nombre;
}

void Producto::setNombre(char nombre)
{
    this->nombre = nombre;
}

char Producto::getMarca() const
{
    return marca;
}

void Producto::setMarca(char marca)
{
    this->marca = marca;
}

char Producto::getDescripcion() const
{
    return descripcion;
}

void Producto::setDescripcion(char descripcion)
{
    this->descripcion = descripcion;
}

int Producto::getCodigo() const
{
    return codigo;
}

void Producto::setCodigo(int codigo)
{
    this->codigo = codigo;
}

int Producto::getCategoria() const
{
    return categoria;
}

void Producto::setCategoria(int categoria)
{
    this->categoria = categoria;
}

int Producto::getStock() const
{
    return stock;
}

void Producto::setStock(int stock)
{
    this->stock = stock;
}

float Producto::getPrecio() const
{
    return precio;
}

void Producto::setPrecio(float precio)
{
    this->precio = precio;
}

