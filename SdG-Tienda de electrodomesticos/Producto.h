#pragma once
#include <iostream>
#include <iomanip>
class Producto
{
private:
	char nombre[25], marca[25], descripcion[50];
	int codigo, categoria, stock;
	float precio;
public:
	void cargar() {
		std::cout << "Codigo: ";
		std::cin >> codigo;
		std::cout << "Categoria: ";
		std::cin >> categoria;
		std::cout << "Nombre: ";
		std::cin >> nombre;
		std::cout << "Marca: ";
		std::cin >> marca;
		std::cout << "Precio: ";
		std::cin >> precio;
	}
	void mostrar() {
		std::cout << '\t' << std::left << std::setw(25) << codigo << std::setw(25) << categoria << std::setw(25) << nombre << std::setw(25) << marca << std::setw(25) << precio << std::endl;
	}
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

};
