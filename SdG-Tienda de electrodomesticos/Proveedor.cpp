#include "Proveedor.h"

void Proveedor::SetNumeroCliente(int Cliente)
{
	_NumeroCliente = Cliente;
}

void Proveedor::SetCuit(const char* cuit)
{
	strcpy(_cuit, cuit);
}

void Proveedor::SetNombreEmpresa(std::string nombreEmpresa)
{
	strcpy(_NombreEmpresa, nombreEmpresa.c_str());
}

void Proveedor::SetTelefono(const char* telefono)
{
	strcpy(_Telefono, telefono);
}

void Proveedor::SetDireccionFisical(std::string DireccionFiscal)
{
	strcpy(_DireccionFiscal, DireccionFiscal.c_str());
}

void Proveedor::SetEmail(const char* email)
{
	strcpy(_email, email);
}

void Proveedor::SetFechaFactura(FechaHora FechaProveedor)
{
	_FechaDeFactura = FechaProveedor;
}

void Proveedor::SetNumeroFactura(const char* numeroFactura)
{
	strcpy(_NumeroFactura, numeroFactura);
}

void Proveedor::SetRegistroDePago(const char* RegistroPago)
{
	strcpy(_RegistroDePago, RegistroPago);
}

int Proveedor::GetNumeroCliente()
{
	return _NumeroCliente;
}

char* Proveedor::GetCuit()
{
	return _cuit;
}

std::string Proveedor::GetNombreEmpresa()
{
	std::string pal = _NombreEmpresa;
	return pal;
}

char* Proveedor::GetTelefono()
{
	return _Telefono;
}

std::string Proveedor::GetDireccionFiscal()
{
	std::string pal = _DireccionFiscal;
	return pal;
}

char* Proveedor::GetEmail()
{
	return _email;
}

FechaHora Proveedor::GetFecha()
{
	return FechaHora();
}

char* Proveedor::GetNumeroFactura()
{
	return _NumeroFactura;
}

char* Proveedor::GetRegistroDepago()
{
	return _RegistroDePago;
}

bool Proveedor::leerDeDisco(int pos)
{
    FILE* p;
    p = fopen("proveedores.dat", "rb");
    if (p == NULL) {
        std::cout << "No hay registros.";
        return false;
    }
    fseek(p, sizeof(Proveedor) * pos, 0);
    bool leyo = fread(this, sizeof(Proveedor), 1, p);
    fclose(p);
    return leyo;
}

bool Proveedor::grabarEnDisco()
{
	FILE* p;
	p = fopen("proveedores.dat", "ab");
	if (p == NULL) { return false; }
	fwrite(this, sizeof(Proveedor), 1, p);
	fclose(p);

	return true;
}

void Proveedor::mostrar()
{
	if (estado) {
		std::cout << "Cliente N°" << _NumeroCliente << std::endl;
		std::cout << "Cuit: " << _cuit << std::endl;
		std::cout << "Empresa: " << _NombreEmpresa << std::endl;
		std::cout << "Tel: " << _Telefono << std::endl;
		std::cout << "Dirección fiscal: " << _DireccionFiscal << std::endl;
		std::cout << "Email: " << _email << std::endl;
		std::cout << "Fecha: ";
		_FechaDeFactura.mostrarFecha();
		std::cout << "Factura N°" << _NumeroFactura << std::endl;
		std::cout << "Registro de pago: " << _RegistroDePago;
	}
}

void Proveedor::cargar()
{
	std::string palabra;
    _NumeroCliente = contProveedores() + 1;
	std::cout << "Cuit: ";
	std::cin >> _cuit;
	std::cout << "Nombre de Empresa: ";
	std::cin.ignore();
	std::getline(std::cin, palabra);
	SetNombreEmpresa(palabra);
	std::cout << "Telefono:";
	std::cin >> _Telefono;
	std::cout << "Direccion Fiscal: ";
	std::cin.ignore();
	std::getline(std::cin, palabra);
	SetDireccionFisical(palabra);
	std::cout << "Email: ";
	std::cin >> _email;
	std::cout << "Numero De Factura: ";
	std::cin >> _NumeroFactura;
	std::cout << "Registro De Pago: ";
	std::cin >> _RegistroDePago;
	estado = true;
}

int Proveedor::contProveedores()
{
    FILE* p = fopen("proveedores.dat", "rb");
    if (p == NULL) {
        return 0; ///cantidad de registros cero 0
    }
    size_t bytes;
    int cant_reg;

    fseek(p, 0, SEEK_END);
    bytes = ftell(p);
    fclose(p);
    cant_reg = bytes / sizeof(Proveedor);
    return cant_reg;
}

void Proveedor::modificarProveedores() {
    bool bandera;
    int opcion, ingreso, n, nReg;
    std::string palabra;
    do {
        std::cout << "Ingrese el número de proveedor a modificar o 0 para volver: ";
        std::cin >> n;
        nReg = buscarRegistro(n);
        if (nReg > 0)
        {
            do
            {
                mostrar();
                std::cout << std::endl << std::endl;
                std::cout << "¿Qué desea modificar?" << std::endl << std::endl;
                std::cout << "1-N° cuit" << std::endl;
                std::cout << "2-Nombre de Empresa" << std::endl;
                std::cout << "3-Teléfono" << std::endl;
                std::cout << "4-Dirección fiscal" << std::endl; // NO OLVIDARSE DE PERMITIR COMPRAR MAS DE UN PRODUCTO
                std::cout << "5-Email" << std::endl;
                std::cout << "6-Registro de pago" << std::endl;
                std::cout << "-------------------" << std::endl;
                std::cout << "------------------" << std::endl;
                std::cout << "0-Volver" << std::endl << std::endl;
                std::cout << "Ingrese una opción: ";
                std::cin >> opcion;
                rlutil::cls();
                switch (opcion)
                {
                case 1:
                    std::cout << "Ingrse nuevo número de cuit: ";
                    std::cin >> _cuit;
                    break;
                case 2:
                    std::cout << "Ingrese el nuevo nombre de empresa:" << std::endl;
                    std::cin.ignore();
                    std::getline(std::cin, palabra);
                    SetNombreEmpresa(palabra);
                    break;
                case 3:
                    std::cout << "Ingrese nuevo teléfono: ";
                    std::cin >> _Telefono;
                    break;
                case 4:
                    std::cout << "Ingrese la nueva dirección fiscal:" << std::endl;
                    std::cin.ignore();
                    std::getline(std::cin, palabra);
                    SetDireccionFisical(palabra);
                    break;
                case 5:
                    std::cout << "Ingrese el nuevo mail: ";
                    std::cin >> _email;
                    break;
                case 6:
                    std::cout << "Ingrese el nuevo registro de pago: ";
                    std::cin >> _RegistroDePago;
                    break;
                default:
                    if (opcion != 0)
                    {
                        std::cout << "Por favor ingrese una opción correcta.";
                    }
                    break;
                }
                if (opcion != 0) {
                    if (modificarEnDisco(nReg - 1)) std::cout << "Modificación realizada con éxito.";
                    else std::cout << "Error al modificar.";
                }
                rlutil::cls();
            } while (opcion != 0);
        }
        else if (n != 0)
        {
            std::cout << "Error. No se ha encontrado el proveedor.";
            rlutil::anykey();
        }
        rlutil::cls();
    } while (n != 0);
}

void Proveedor::eliminarProveedores() {
    int n, confirmar, reg;
    do {
        std::cout << "Ingrese el número de proveedor que quiere eliminar o ingrese 0 para volver: ";
        std::cin >> n;
        reg = buscarRegistro(n);
        rlutil::cls();
        if (reg < 0) std::cout << "No se ha podido encontrar el proveedor.";
        else
        {
            if (estado) {
                rlutil::cls();
                mostrar();
                std::cout << std::endl << std::endl << "¿Seguro de eliminar el proveedor? Presione 1 para eliminar/2 para cancelar:" << std::endl;
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
            else std::cout << "No se ha podido encontrar el proveedor.";
        }
        if (n != 0) rlutil::anykey();
        rlutil::cls();
    } while (n != 0);
}

void Proveedor::listarProveedores() {
    int opcion, n, pos, numeroReg;
    bool bandera = false;
    do
    {
        pos = 0;
        std::cout << "1-Listar todos los proveedores" << std::endl;
        std::cout << "2-Listar un proveedor" << std::endl;
        std::cout << "-------------------" << std::endl;
        std::cout << "------------------" << std::endl;
        std::cout << "0-Volver" << std::endl << std::endl;
        std::cout << "Ingrese una opción: ";
        std::cin >> opcion;
        rlutil::cls();
        switch (opcion)
        {
        case 1:
            while (leerDeDisco(pos++))
            {
                mostrar();
                if (estado)std::cout << std::endl << std::endl << "/////////////////////////////////////////" << std::endl << "/////////////////////////////////////////" << std::endl;
            }
            break;
        case 2:
            std::cout << "Ingrese el número de proveedor que quiere listar o 0 para volver: ";
            std::cin >> n;
            if (n != 0) {
                rlutil::cls();
                if (buscarRegistro(n) < 0) std::cout << "No se ha podido encontrar el proveedor.";
                else
                {
                    if (estado) {
                        bandera = true;
                        mostrar();
                    }
                    else std::cout << "No se ha podido encontrar el proveedor.";
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

bool Proveedor::modificarEnDisco(int pos) {
    FILE* p = NULL;
    p = fopen("clientes.dat", "rb+");
    if (p == NULL)return 0;
    fseek(p, pos * sizeof(Proveedor), 0);
    bool escribio = fwrite(this, sizeof(Proveedor), 1, p);
    fclose(p);
    return escribio;
}

int Proveedor::buscarRegistro(int n) {
    int pos = 0;
    while (leerDeDisco(pos++))
    {

        if (n == _NumeroCliente) return pos;

    }

    return -1;
}