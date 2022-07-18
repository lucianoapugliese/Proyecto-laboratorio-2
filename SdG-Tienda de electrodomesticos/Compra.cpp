#include "Compra.h"

void Compra::SetNumeroDeFactura(int Num)
{
	_NumeroDeFactura = Num;

}

void Compra::setTipoDeCompra(int Tipo)
{
	TipoDeCompra = Tipo;
}

void Compra::SetFechadeCompra(FechaHora SFecha)
{
	FechaDeCompra = SFecha;
}

void Compra::SetModificarValor(float val)
{
	Valor = val;
}

void Compra::SetNombreDeProducto(std::string NombreProdu)
{
	strcpy(NombreDeProducto, NombreProdu.c_str());
}

void Compra::SetCantidadComprada(float CantCompra)
{
	Cantidad = CantCompra;
}

int Compra::GetNumeroDeFac()
{
	return _NumeroDeFactura;
}

int Compra::GetTipoDeCompra()
{
	return TipoDeCompra;
}

FechaHora Compra::GetFechaDeLaCompra()
{
	return FechaDeCompra;
}

float Compra::GetCostoDelProducto()
{
	return Valor;
}
std::string Compra::GetNombreDeProducto()
{
	std::string nom = NombreDeProducto;
	return nom;
}

float Compra::GetCantidadDeProductos()
{
	return Cantidad;
}

bool Compra::LeerDeDisco(int pos)
{
	FILE* p;
	p = fopen("compras.dat", "rb");
	if (p == NULL) { return false; }
	fseek(p, pos * sizeof(Compra), 0);
	bool leyo=fread(this, sizeof(Compra), 1, p);
	fclose(p);
	return leyo;
}

bool Compra::GuardarEnDisco()
{
	FILE* p;
	p = fopen("compras.dat", "ab");
	if (p == NULL) { return false; }

	fwrite(this, sizeof(Compra), 1, p);
	fclose(p);
	return true;
}

void Compra::Mostrar()
{
	if (estado) {
		std::cout << "Factura N°" << _NumeroDeFactura << std::endl << std::endl;
		std::cout << "Tipo de compra: ";
		switch (TipoDeCompra)
		{
		case 1: std::cout << "Línea blanca" << std::endl;
			break;
		case 2: std::cout << "Electrónica" << std::endl;
			break;
		default: std::cout << "Videojuegos" << std::endl;
			break;
		}
		std::cout << "Fecha de compra:" << std::endl;
		FechaDeCompra.mostrarFecha();
		std::cout << "Precio: $" << Valor << std::endl;
		std::cout << "Nombre del producto: " << NombreDeProducto << std::endl;
		std::cout << "Cantidad: " << Cantidad;
	}
}

void Compra::Cargar()
{
	estado = true;
	_NumeroDeFactura = contRegistros() + 1;
	std::string palabra;
	std::cout << "Nombre del producto: ";
	std::cin.ignore();
	std::getline(std::cin, palabra);
	SetNombreDeProducto(palabra);
	do
	{
		std::cout << "Tipo de Compra (1 , 2 , 3):";
		std::cin >> TipoDeCompra;
		if (TipoDeCompra < 1 || TipoDeCompra>3) {
			rlutil::cls();
			std::cout << "Por favor ingrese una opción válida.";
			rlutil::anykey();
			rlutil::cls();
		}
	} while (TipoDeCompra < 1 || TipoDeCompra>3);
	std::cout << "Cargar la Fecha de compra:\n";
	FechaDeCompra.cargarFecha();
	std::cout << "Cargar Precio:";
	std::cin >> Valor;
	std::cout << "Cantidad de compra Dentro del bulto (en kg):";
	std::cin >> Cantidad;
}

int Compra::buscarRegistro(int n) {
	int pos = 0;
	while (LeerDeDisco(pos++))
	{
		if (n == _NumeroDeFactura) return pos;
	}

	return -1;
}

int Compra::contRegistros() {
	FILE* p = fopen("compras.dat", "rb");
	if (p == NULL) {
		return 0; ///cantidad de registros cero 0
	}
	size_t bytes;
	int cant_reg;

	fseek(p, 0, SEEK_END);
	bytes = ftell(p);
	fclose(p);
	cant_reg = bytes / sizeof(Cliente);
	return cant_reg;
}

void Compra::modificarCompra() {
	std::string palabra;
	int opcion, ingreso, d, nReg, entero;
	Direccion dom;
	FechaHora fec;
	char cad[50];
	bool ingresoCorrecto = true;
	do {
		std::cout << "Ingrese el número de compra a modificar o 0 para volver: ";
		std::cin >> d;
		nReg = buscarRegistro(d);
		if (nReg > 0)
		{
			do
			{
				Mostrar();
				std::cout << std::endl << std::endl;
				std::cout << "¿Qué desea modificar?" << std::endl << std::endl;
				std::cout << "1-Tipo de compra" << std::endl;
				std::cout << "2-Precio" << std::endl;
				std::cout << "3-Nombre del producto" << std::endl;
				std::cout << "4-Cantidad" << std::endl;
				std::cout << "-------------------" << std::endl;
				std::cout << "-------------------" << std::endl;
				std::cout << "0-Volver" << std::endl << std::endl;
				std::cout << "Ingrese una opción: ";
				std::cin >> opcion;
				rlutil::cls();
				switch (opcion)
				{
				case 1:
					do
					{
						std::cout << "Ingrese el tipo de compra nueva (1, 2 o 3): ";
						std::cin >> TipoDeCompra;
						if (TipoDeCompra < 1 || TipoDeCompra > 3) {
							rlutil::cls();
							std::cout << "Error. Por favor ingrese una opción válida.";
							rlutil::anykey();
							rlutil::cls();
						}
					} while (TipoDeCompra < 1 || TipoDeCompra > 3);
					break;
				case 2:
					std::cout << "Ingrese nuevo precio: " << std::endl;
					std::cin >> Valor;
					break;
				case 3:
					std::cout << "Ingrese el nombre nuevo: ";
					std::cin.ignore();
					std::getline(std::cin, palabra);
					SetNombreDeProducto(palabra);
					break;
				case 4:
					std::cout << "Ingrese la cantidad nueva: ";
					std::cin >> Cantidad;
					break;
				default:
					if (opcion != 0)
					{
						std::cout << "Por favor ingrese una opción correcta.";
						rlutil::anykey();
					}
					break;
				}
				if (opcion != 0)
				{
					if (modificarEnDisco(nReg - 1)) std::cout << std::endl << "Modificación realizada con éxito.";
					else std::cout << "Error al modificar.";
					rlutil::anykey();
				}
				rlutil::cls();
			} while (opcion != 0);
		}
		else if (d != 0)
		{
			std::cout << "Error. No se ha encontrado el cliente.";
			rlutil::anykey();
		}
		rlutil::cls();
	} while (d != 0);
}

void Compra::eliminarCompra() {
	int d, confirmar, reg;
	do {
		std::cout << "Ingrese el número de compra que quiere eliminar o ingrese 0 para volver: ";
		std::cin >> d;
		reg = buscarRegistro(d);
		rlutil::cls();
		if (reg < 0) std::cout << "No se ha podido encontrar la compra.";
		else
		{
			if (estado) {
				rlutil::cls();
				Mostrar();
				std::cout << std::endl << std::endl << "¿Seguro de eliminar compra? Presione 1 para eliminar/2 para cancelar:" << std::endl;
				std::cin >> confirmar;
				rlutil::cls();
				if (confirmar == 1)
				{
					estado = false;
					if (modificarEnDisco(reg - 1)) std::cout << "Eliminada con exito.";
					else std::cout << "Error al eliminar.";
				}
				else if (confirmar != 2) std::cout << "Por favor ingrese una opción válida.";
			}
			else std::cout << "No se ha podido encontrar la compra.";
		}
		if (d != 0) rlutil::anykey();
		rlutil::cls();
	} while (d != 0);
}

void Compra::listarCompra() {
	int opcion, d, pos, numeroReg;
	bool bandera = false;
	do
	{
		pos = 0;
		std::cout << "1-Listar todas las compraa" << std::endl;
		std::cout << "2-Listar una compra" << std::endl;
		std::cout << "-------------------" << std::endl;
		std::cout << "------------------" << std::endl;
		std::cout << "0-Volver" << std::endl << std::endl;
		std::cout << "Ingrese una opción: ";
		std::cin >> opcion;
		rlutil::cls();
		switch (opcion)
		{
		case 1:
			while (LeerDeDisco(pos++))
			{
				Mostrar();
				if (estado)std::cout << std::endl << std::endl;
			}
			break;
		case 2:
			std::cout << "Ingrese el número de compra que quiere listar o 0 para volver: ";
			std::cin >> d;
			if (d != 0) {
				rlutil::cls();
				if (buscarRegistro(d) < 0) std::cout << "No se ha podido encontrar la compra.";
				else
				{
					if (estado) {
						bandera = true;
						Mostrar();
					}
					else std::cout << "No se ha podido encontrar la compra.";
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
}

bool Compra::modificarEnDisco(int pos) {
	FILE* p = NULL;
	p = fopen("compras.dat", "rb+");
	if (p == NULL)return 0;
	fseek(p, pos * sizeof(Compra), 0);
	bool escribio = fwrite(this, sizeof(Compra), 1, p);
	fclose(p);
	return escribio;
}