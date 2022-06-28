#include "Producto.h"

Producto::Producto() {
    std::string vacio = " ";
    categoria = 0;
    codigo = 0;
    precio = 0;
    stock = 0;
    estado = 1;
    strcpy(nombre, vacio.c_str());
    strcpy(descripcion, vacio.c_str());
    strcpy(marca, vacio.c_str());
}

std::string Producto::getNombre() 
{
    std::string nombre = this->nombre;
    return nombre;
}

void Producto::setNombre(std::string nombre)
{
    strcpy(this->nombre, nombre.c_str());
}

std::string Producto::getMarca() 
{
    std::string marca = this->marca;
    return marca;
}

void Producto::setMarca(std::string marca)
{
    strcpy(this->marca , marca.c_str());
}

std::string Producto::getDescripcion() 
{
    std::string descripcion = this->descripcion;
    return descripcion;
}

void Producto::setDescripcion(std::string descripcion)
{
    strcpy(this->descripcion , descripcion.c_str());
}

int Producto::getCodigo() 
{
    return codigo;
}

void Producto::setCodigo(int codigo)
{
    this->codigo = codigo;
}

bool Producto::getEstado() 
{
    return estado;
}

void Producto::setEstado(bool estado)
{
    this->estado = estado;
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

void Producto::cargar() {
    std::cout << "Codigo: ";
    std::cin >> codigo;
    std::cout << "Categoria: ";
    std::cin >> categoria;
    std::cout << "Marca: ";
    std::cin.ignore();
    std::cin.getline(marca, 50);
    std::cout << "Nombre: ";
    std::cin.getline(nombre, 50);
    std::cout << "Descripción: ";
    std::cin.getline(descripcion, 50);
    std::cout << "Precio: $";
    std::cin >> precio;
    std::cout << "Stock: ";
    std::cin >> stock;
    if (grabarEnDisco())
    {
        system("cls");
        std::cout << "Producto guardado con exito" << std::endl;
        system("pause");
        system("cls");
    }
}
void Producto::mostrar() {
    if (estado) {
        std::cout << "Codigo: ";
        std::cout << codigo << std::endl;
        std::cout << "Categoria: ";
        std::cout << categoria << std::endl;
        std::cout << "Marca: ";
        std::cout << marca << std::endl;
        std::cout << "Nombre: ";
        std::cout << nombre << std::endl;
        std::cout << "Descripción: ";
        std::cout << descripcion << std::endl;
        std::cout << "Precio: $";
        std::cout << precio << std::endl;
        std::cout << "Stock: ";
        std::cout << stock << std::endl;
    }
}

bool Producto::grabarEnDisco() {
    FILE* p = NULL;
    p = fopen("productos.dat", "ab");
    if (p == NULL)
    {
        std::cout << "Error al guardar.\n";
        system("pause");
        return 0;
    }
    fwrite(this, sizeof(Producto), 1, p);
    fclose(p);
    return 1;
}
bool Producto::leerDeDisco(int pos) {
    FILE* p = NULL;
    p = fopen("productos.dat", "rb+");
    if (p == NULL)
    {
        std::cout << "Error al abrir.\n";
        system("pause");
        return 0;
    }
    fseek(p, pos * sizeof(Producto), 0);
    fread(this, sizeof(Producto), 1, p);
    fclose(p);
    return 1;
}