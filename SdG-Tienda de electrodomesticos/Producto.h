#pragma once
#include <iostream>
#include <iomanip>
class Producto
{
private:
	char nombre[50], marca[50], descripcion[50];
	int codigo, categoria, stock;
	float precio;
    bool estado;
public:
    Producto();
    void cargar();
    void mostrar();
	bool grabarEnDisco();
	bool leerDeDisco(int pos);
    const char *getNombre();
    void setNombre(const char *nombre);

    const char *getMarca();
    void setMarca(const char *marca);

    const char *getDescripcion();
    void setDescripcion(const char *descripcion);

    int getCodigo();
    void setCodigo(int codigo);

    int getCategoria();
    void setCategoria(int categoria);

    int getStock();
    void setStock(int stock);

    float getPrecio();
    void setPrecio(float precio);

    bool getEstado();
    void setEstado(bool estado);

};
