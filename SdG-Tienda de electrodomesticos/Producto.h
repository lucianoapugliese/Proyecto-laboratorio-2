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
    std::string getNombre();
    void setNombre(std::string nombre);

    std::string getMarca();
    void setMarca(std::string marca);

    std::string getDescripcion();
    void setDescripcion(std::string descripcion);

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
