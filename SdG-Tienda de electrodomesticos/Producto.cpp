#include "Producto.h"

const char *Producto::getNombre() 
{
    return nombre;
}

void Producto::setNombre(const char *nombre)
{
    strcpy(this->nombre, nombre);
}

const char *Producto::getMarca() 
{
    return marca;
}

void Producto::setMarca(const char *marca)
{
    strcpy(this->marca , marca);
}

const char *Producto::getDescripcion() 
{
    return descripcion;
}

void Producto::setDescripcion(const char *descripcion)
{
    strcpy(this->descripcion , descripcion);
}

int Producto::getCodigo() 
{
    return codigo;
}

void Producto::setCodigo(int codigo)
{
    this->codigo = codigo;
}

int Producto::getCategoria() 
{
    return categoria;
}

void Producto::setCategoria(int categoria)
{
    this->categoria = categoria;
}

int Producto::getStock() 
{
    return stock;
}

void Producto::setStock(int stock)
{
    this->stock = stock;
}

float Producto::getPrecio() 
{
    return precio;
}

void Producto::setPrecio(float precio)
{
    this->precio = precio;
}

