#include "Producto.h"

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
	do {
		std::cout << "Categoria(1-Linea blanca/2-Electr�nica/3-Videojuegos): ";
		std::cin >> categoria;

		if (categoria < 1 && categoria>3) {
			rlutil::cls();
			std::cout << "Por favor ingrese una opci�n v�lida.";
			rlutil::anykey();
			rlutil::cls();
		}
	} while (categoria < 1 && categoria>3);
    std::cout << "Marca: ";
    std::cin.ignore();
    std::cin.getline(marca, 50);
    std::cout << "Nombre: ";
    std::cin.getline(nombre, 50);
    std::cout << "Descripci�n: ";
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
void Producto::cargar(int cod) {
	codigo = cod;
	do {
		std::cout << "Categoria(1-Linea blanca/2-Electr�nica/3-Videojuegos): ";
		std::cin >> categoria;

		if (categoria < 1 && categoria>3) {
			rlutil::cls();
			std::cout << "Por favor ingrese una opci�n v�lida.";
			rlutil::anykey();
			rlutil::cls();
		}
	} while (categoria < 1 && categoria>3);
    std::cout << "Marca: ";
    std::cin.ignore();
    std::cin.getline(marca, 50);
    std::cout << "Nombre: ";
    std::cin.getline(nombre, 50);
    std::cout << "Descripci�n: ";
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
		switch (categoria)
		{
		case 1: std::cout << "L�nea blanca";
			break;
		case 2: std::cout << "Electr�nica";
			break;
		default: std::cout << "Videojuegos";
			break;
		}
        std::cout << std::endl << "Marca: ";
        std::cout << marca << std::endl;
        std::cout << "Nombre: ";
        std::cout << nombre << std::endl;
        std::cout << "Descripci�n: ";
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
    p = fopen("productos.dat", "rb");
    if (p == NULL)
    {
        std::cout << "Error al abrir.\n";
        system("pause");
        return 0;
    }
    fseek(p, pos * sizeof(Producto), 0);
    bool leyo=fread(this, sizeof(Producto), 1, p);
    fclose(p);
    return leyo;
}

int Producto::contRegistros() {
	FILE* p = fopen("productos.dat", "rb");
	if (p == NULL) {
		return 0; ///cantidad de registros cero 0
	}
	size_t bytes;
	int cant_reg;

	fseek(p, 0, SEEK_END);
	bytes = ftell(p);
	fclose(p);
	cant_reg = bytes / sizeof(Producto);
	return cant_reg;
}

void Producto::modificarProducto() {
	std::string palabra;
	int opcion, ingreso, c, nReg;
	bool ingresoCorrecto = true;
	do {
		std::cout << "Ingrese el c�digo del producto a modificar o 0 para volver: ";
		std::cin >> c;
		nReg = buscarRegistro(c);
		if (nReg > 0)
		{
			do
			{
				mostrar();
				std::cout << std::endl << std::endl;
				std::cout << "�Qu� desea modificar?" << std::endl << std::endl;
				std::cout << "1-Nombre" << std::endl;
				std::cout << "2-Marca" << std::endl;
				std::cout << "3-Descripci�n" << std::endl;
				std::cout << "4-Categor�a" << std::endl;
				std::cout << "5-Stock" << std::endl;
				std::cout << "6-Precio" << std::endl;
				std::cout << "-------------------" << std::endl;
				std::cout << "-------------------" << std::endl;
				std::cout << "0-Volver" << std::endl << std::endl;
				std::cout << "Ingrese una opci�n: ";
				std::cin >> opcion;
				rlutil::cls();
				switch (opcion)
				{
				case 1:
					std::cout << "Ingrese el nombre nuevo: ";
					std::cin.ignore();
					std::getline(std::cin, palabra);
					setNombre(palabra);
					break;
				case 2:
					std::cout << "Ingrese la nueva marca: ";
					std::cin.ignore();
					std::getline(std::cin, palabra);
					setMarca(palabra);
					break;
				case 3:
					std::cout << "Ingrese la nueva descripci�n: ";
					std::cin.ignore();
					std::getline(std::cin, palabra);
					setDescripcion(palabra);
					break;
				case 4:
					std::cout << "Ingrese la nueva categor�a:" << std::endl;
					categoria;
					break;
				case 5:
					std::cout << "Ingrese el stock actual: ";
					std::cin >> stock;
					break;
				case 6:
					std::cout << "Ingrese el nuevo precio: ";
					std::cin >> precio;
					break;
				default:
					if (opcion != 0) {
						std::cout << "Por favor ingrese una opci�n correcta.";
						rlutil::anykey();
					}
					break;
				}
				if (opcion != 0) {
					do
					{
						rlutil::cls();
						std::cout << "�Seguro de realizar la modificaci�n? 1-S�/2-Cancelar" << std::endl << '>';
						std::cin >> ingreso;
						if (ingreso < 1 || ingreso>2)
						{
							rlutil::cls();
							std::cout << "Por favor ingrese una opci�n v�lida.";
							rlutil::anykey();
						}
					} while (ingreso < 1 || ingreso>2);
					if (ingreso == 1) {
						if (modificarEnDisco(nReg - 1)) std::cout << "Modificaci�n realizada con �xito.";
						else std::cout << "Error al modificar.";
						rlutil::anykey();
					}
				}
				rlutil::cls();
			} while (opcion != 0);
		}
		else if (c != 0)
		{
			std::cout << "Error. No se ha encontrado el producto.";
			rlutil::anykey();
		}
		rlutil::cls();
	} while (c != 0);
}

void Producto::eliminarProducto() {
	int c, confirmar, reg;
	do {
		std::cout << "Ingrese el c�digo del producto que quiere eliminar o 0 para volver: ";
		std::cin >> c;
		reg = buscarRegistro(c);
		rlutil::cls();
		if (reg < 0) std::cout << "No se ha podido encontrar el producto.";
		else
		{
			if (estado) {
				rlutil::cls();
				mostrar();
				std::cout << std::endl << std::endl << "�Seguro de eliminar producto? Presione 1 para eliminar/2 para cancelar:" << std::endl;
				std::cin >> confirmar;
				rlutil::cls();
				if (confirmar == 1)
				{
					estado = false;
					if (modificarEnDisco(reg - 1)) std::cout << "Eliminado con exito.";
					else std::cout << "Error al eliminar.";
				}
				else if (confirmar != 2) std::cout << "Por favor ingrese una opci�n v�lida.";
			}
			else std::cout << "No se ha podido encontrar el producto.";
		}
		if (c != 0) rlutil::anykey();
		rlutil::cls();
	} while (c != 0);
}

void Producto::listarProducto() {
	int opcion, c, pos, numeroReg;
	bool bandera = false;
	do
	{
		pos = 0;
		std::cout << "1-Listar todos los productos" << std::endl;
		std::cout << "2-Listar un producto" << std::endl;
		std::cout << "-------------------" << std::endl;
		std::cout << "-------------------" << std::endl;
		std::cout << "0-Volver" << std::endl << std::endl;
		std::cout << "Ingrese una opci�n: ";
		std::cin >> opcion;
		rlutil::cls();
		switch (opcion)
		{
		case 1:
			while (leerDeDisco(pos++))
			{
				mostrar();
				if (estado)std::cout << std::endl << std::endl;
			}
			break;
		case 2:
			std::cout << "Ingrese el c�digo del producto que quiere listar o 0 para volver: ";
			std::cin >> c;
			rlutil::cls();
			if (c != 0)
			{
				if (buscarRegistro(c) < 0) std::cout << "No se ha podido encontrar el producto.";
				else
				{
					if (estado) {
						bandera = true;
						mostrar();
					}
					else std::cout << "No se ha podido encontrar el producto.";
				}
			}
			break;
		default:
			if (opcion != 0)
			{
				std::cout << "Por favor ingrese una opci�n correcta.";
			}
			break;
		}
		bandera = false;
		if (opcion != 0)rlutil::anykey();
		rlutil::cls();
	} while (opcion != 0);
}

bool Producto::modificarEnDisco(int pos) {
	FILE* p = NULL;
	p = fopen("productos.dat", "rb+");
	if (p == NULL)return 0;
	fseek(p, pos * sizeof(Producto), 0);
	bool escribio = fwrite(this, sizeof(Producto), 1, p);
	fclose(p);
	return escribio;
}

int Producto::buscarRegistro(int c) {
	int pos = 0;
	while (leerDeDisco(pos++))
	{

		if (c == codigo) return pos;

	}

	return -1;
}