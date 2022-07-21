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
		std::cout << "Categoria(1-Linea blanca/2-Electrónica/3-Videojuegos): ";
		std::cin >> categoria;

		if (categoria < 1 && categoria>3) {
			rlutil::cls();
			std::cout << "Por favor ingrese una opción válida.";
			rlutil::anykey();
			rlutil::cls();
		}
	} while (categoria < 1 && categoria>3);
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
void Producto::cargar(int cod) {
	codigo = cod;
	do {
		std::cout << "Categoria(1-Linea blanca/2-Electrónica/3-Videojuegos): ";
		std::cin >> categoria;

		if (categoria < 1 && categoria>3) {
			rlutil::cls();
			std::cout << "Por favor ingrese una opción válida.";
			rlutil::anykey();
			rlutil::cls();
		}
	} while (categoria < 1 && categoria>3);
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
		rlutil::cls();
		Menu ob;
		int y = 10;
		rlutil::setColor(rlutil::BLACK);
		rlutil::setBackgroundColor(rlutil::WHITE);
		ob.Menurectangulo(45, y, 35, 3, "");
        std::cout << "Código: ";
        std::cout << codigo << std::endl;
		ob.Menurectangulo(45, y+=3, 35, 3, "");
        std::cout << "Nombre: ";
        std::cout << nombre << std::endl;
		ob.Menurectangulo(45, y+=3, 35, 3, "");
        std::cout << "Categoría: ";
		switch (categoria)
		{
		case 1: std::cout << "Línea blanca";
			break;
		case 2: std::cout << "Electrónica";
			break;
		default: std::cout << "Videojuegos";
			break;
		}
		ob.Menurectangulo(45, y+=3, 35, 3, "");
        std::cout << "Marca: ";
        std::cout << marca << std::endl;
		ob.Menurectangulo(45, y+=3, 35, 3, "");
        std::cout << "Descripción: ";
        std::cout << descripcion << std::endl;
		ob.Menurectangulo(45, y+=3, 35, 3, "");
        std::cout << "Precio: $";
        std::cout << precio << std::endl;
		ob.Menurectangulo(45, y+=3, 35, 3, "");
        std::cout << "Stock: ";
        std::cout << stock << std::endl;
    }
}
void Producto::mostrarTodos() {
	int y = 0, pos = 0;
	Menu ob;
	rlutil::setColor(rlutil::BLACK);
	rlutil::setBackgroundColor(rlutil::WHITE);
	while (leerDeDisco(pos++))
	{
		if (estado) {
			y += 10;
			ob.Menurectangulo(45, y, 35, 3, "");
			std::cout << "Código: ";
			std::cout << codigo << std::endl;
			ob.Menurectangulo(45, y += 3, 35, 3, "");
			std::cout << "Nombre: ";
			std::cout << nombre << std::endl;
			ob.Menurectangulo(45, y += 3, 35, 3, "");
			std::cout << "Categoría: ";
			switch (categoria)
			{
			case 1: std::cout << "Línea blanca";
				break;
			case 2: std::cout << "Electrónica";
				break;
			default: std::cout << "Videojuegos";
				break;
			}
			ob.Menurectangulo(45, y += 3, 35, 3, "");
			std::cout << "Marca: ";
			std::cout << marca << std::endl;
			ob.Menurectangulo(45, y += 3, 35, 3, "");
			std::cout << "Descripción: ";
			std::cout << descripcion << std::endl;
			ob.Menurectangulo(45, y += 3, 35, 3, "");
			std::cout << "Precio: $";
			std::cout << precio << std::endl;
			ob.Menurectangulo(45, y += 3, 35, 3, "");
			std::cout << "Stock: ";
			std::cout << stock << std::endl;
		}
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
	Menu ob;
	rlutil::setColor(rlutil::BLACK);
	rlutil::setBackgroundColor(rlutil::WHITE);
	std::string palabra;
	int opcion, ingreso, c, nReg, y;
	bool ingresoCorrecto = true;
	do {
		rlutil::setBackgroundColor(rlutil::WHITE);
		rlutil::setColor(rlutil::BLACK);
		ob.Menurectangulo(30, 8, 65, 3, "");
		std::cout << "Ingrese el código del producto a modificar o 0 para volver: ";
		std::cin >> c;
		nReg = buscarRegistro(c);
		if (nReg > 0)
		{
			do
			{
				y = 8;
				rlutil::setColor(rlutil::BLACK);
				rlutil::setBackgroundColor(rlutil::WHITE);
				mostrar();
				ob.Menurectangulo(45, 8, 35, 2, "PRODUCTO:");
				ob.Menurectangulo(5, y, 25, 2, "");
				std::cout << "¿Qué desea modificar?" << std::endl << std::endl;
				ob.Menurectangulo(5, y += 2, 25, 2, "");
				std::cout << "1-Nombre" << std::endl;
				ob.Menurectangulo(5, y += 2, 25, 2, "");
				std::cout << "2-Marca" << std::endl;
				ob.Menurectangulo(5, y += 2, 25, 2, "");
				std::cout << "3-Descripción" << std::endl;
				ob.Menurectangulo(5, y += 2, 25, 2, "");
				std::cout << "4-Categoría" << std::endl;
				ob.Menurectangulo(5, y += 2, 25, 2, "");
				std::cout << "5-Stock" << std::endl;
				ob.Menurectangulo(5, y += 2, 25, 2, "");
				std::cout << "6-Precio" << std::endl;
				ob.Menurectangulo(5, y += 2, 25, 2, "");
				std::cout << "0-Volver" << std::endl << std::endl;
				ob.Menurectangulo(5, y += 2, 25, 2, "");
				std::cout << "Ingrese una opción: ";
				std::cin >> opcion;
				rlutil::cls();
				rlutil::setColor(rlutil::BLACK);
				rlutil::setBackgroundColor(rlutil::WHITE);
				ob.Menurectangulo(20, 11, 80, 3, "");
				switch (opcion)
				{
				case 1:
					std::cout << "Ingrese el nombre nuevo: ";

					ob.Menurectangulo(20, 14, 80, 3, "");
					std::cin.ignore();
					std::getline(std::cin, palabra);
					setNombre(palabra);
					break;
				case 2:
					std::cout << "Ingrese la nueva marca: ";

					ob.Menurectangulo(20, 14, 80, 3, "");
					std::cin.ignore();
					std::getline(std::cin, palabra);
					setMarca(palabra);
					break;
				case 3:
					std::cout << "Ingrese la nueva descripción: ";

					ob.Menurectangulo(20, 14, 80, 3, "");
					std::cin.ignore();
					std::getline(std::cin, palabra);
					setDescripcion(palabra);
					break;
				case 4:
					std::cout << "Ingrese la nueva categoría(1-Línea blanca, 2-Electrónica o 3-Videojuegos):" << std::endl;

					ob.Menurectangulo(20, 14, 80, 3, "");
					rlutil::locate(37, 15);
					std::cin >> categoria;
					break;
				case 5:
					std::cout << "Ingrese el stock actual: ";

					ob.Menurectangulo(20, 14, 80, 3, "");
					rlutil::locate(37, 15);
					std::cin >> stock;
					break;
				case 6:
					std::cout << "Ingrese el nuevo precio: ";

					ob.Menurectangulo(20, 14, 80, 3, "$");
					rlutil::locate(24, 15);
					std::cin >> precio;
					break;
				default:
					if (opcion != 0) {
						std::cout << "Por favor ingrese una opción correcta.";
						rlutil::anykey();
					}
					break;
				}
				if (opcion != 0) {
					rlutil::cls();
					ob.Menurectangulo(44, 20, 36, 3, "");
					if (modificarEnDisco(nReg - 1)) std::cout << "Modificación realizada con éxito.";
					else std::cout << "Error al modificar.";
					rlutil::anykey();
				}
				rlutil::cls();
			} while (opcion != 0);
		}
		else if (c != 0)
		{
			rlutil::cls();
			rlutil::setColor(rlutil::BLACK);
			rlutil::setBackgroundColor(rlutil::RED);
			ob.Menurectangulo(44, 20, 45, 3, "");
			std::cout << "Error. No se ha encontrado el producto.";
			rlutil::anykey();
		}
		rlutil::cls();
		rlutil::setBackgroundColor(rlutil::WHITE);
		rlutil::setColor(rlutil::BLACK);
	} while (c != 0);
}

void Producto::eliminarProducto() {
	int c, confirmar, reg;
	Menu ob;
	do {
		ob.Menurectangulo(5, 10, 70, 2, "");
		std::cout << "Ingrese el código del producto que quiere eliminar o 0 para volver: ";
		ob.Menurectangulo(5, 12, 70, 2, "");
		std::cin >> c;
		reg = buscarRegistro(c);
		rlutil::cls();
		rlutil::setColor(rlutil::BLACK);
		rlutil::setBackgroundColor(rlutil::RED);
		if (reg < 0) std::cout << "No se ha podido encontrar el producto.";
		else
		{
			if (estado) {
				rlutil::cls();
				mostrar();
				std::cout << std::endl << std::endl << "¿Seguro de eliminar producto? Presione 1 para eliminar/2 para cancelar:" << std::endl;
				std::cin >> confirmar;
				rlutil::cls();
				if (confirmar == 1)
				{
					estado = false;
					if (modificarEnDisco(reg - 1)) std::cout << "Eliminado con exito.";
					else std::cout << "Error al eliminar.";
				}
				else if (confirmar != 2) std::cout << "Por favor ingrese una opción válida.";
			}
			else std::cout << "No se ha podido encontrar el producto.";
		}
		if (c != 0) rlutil::anykey();
		rlutil::cls();
	} while (c != 0);
}

void Producto::listarProducto() {
	int opcion, c, pos, cont;
	bool bandera = false;
	rlutil::setColor(rlutil::BLACK);
	rlutil::setBackgroundColor(rlutil::WHITE);
	Menu ob;
	do
	{
		pos = 0;
		system("cls");

		rlutil::setColor(rlutil::BLACK);
		rlutil::setBackgroundColor(rlutil::WHITE);
		ob.Menurectangulo(45, 8, 35, 3, "");
		std::cout << "Seleccion una opcion" << std::endl;
		ob.Menurectangulo(45, 11, 35, 3, "");
		std::cout << "1-Listar todos los productos" << std::endl;
		ob.Menurectangulo(45, 14, 35, 3, "");
		std::cout << "2-Listar un producto por código" << std::endl;
		ob.Menurectangulo(45, 17, 35, 3, "");
		std::cout << "0 Volver " << std::endl;
		ob.Menurectangulo(45, 20, 35, 3, "");
		std::cin >> opcion;
		rlutil::cls();
		switch (opcion)
		{
		case 1:
			mostrarTodos();
			/*cont = 0;
			while (leerDeDisco(pos++))
			{
				rlutil::locate(54, 7 + (cont * 24));
				mostrar();
				if (estado)std::cout << std::endl << std::endl;
				if (estado) cont++;
			}*/
			break;
		case 2:
			std::cout << "Ingrese el código del producto que quiere listar o 0 para volver: ";
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
				std::cout << "Por favor ingrese una opción correcta.";
			}
			break;
		}
		bandera = false;
		if (opcion != 0)rlutil::anykey();
		rlutil::cls();
	} while (opcion != 0);
	rlutil::setColor(rlutil::WHITE);
	rlutil::setBackgroundColor(rlutil::BLUE);
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