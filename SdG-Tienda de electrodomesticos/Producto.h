#pragma once
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
		std::cout << "Cantidad de compras: ";
		std::cin >> ventas;
	}
	void mostrar() {
		std::cout << '\t' << std::left << std::setw(25) << codigo << std::setw(25) << categoria << std::setw(25) << nombre << std::setw(25) << marca << std::setw(25) << precio << std::setw(25) << ventas << std::endl;
	}
	bool grabarEnDisco();
	bool leerDeDisco(int pos);
    char getNombre() const;
    void setNombre(char nombre);

    char getMarca() const;
    void setMarca(char marca);

    char getDescripcion() const;
    void setDescripcion(char descripcion);

    int getCodigo() const;
    void setCodigo(int codigo);

    int getCategoria() const;
    void setCategoria(int categoria);

    int getStock() const;
    void setStock(int stock);

    float getPrecio() const;
    void setPrecio(float precio);

};
