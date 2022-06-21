#include "Empleado.h"

int Empleado::getID()
{
    return ID;
}

void Empleado::setID(int ID)
{
    this->ID = ID;
}

int Empleado::getCategoria()
{
    return categoria;
}

void Empleado::setCategoria(int categoria)
{
    this->categoria = categoria;
}

char Empleado::getTurno()
{
    return turno;
}

void Empleado::setTurno(char turno)
{
    this->turno = turno;
}

FechaHora Empleado::getFechaDeIngreso()
{
    return fechaDeIngreso;
}

void Empleado::setFechaDeIngreso(FechaHora fechaDeIngreso)
{
    this->fechaDeIngreso = fechaDeIngreso;
}

char Empleado::getTipoJornada()
{
    return tipoJornada;
}

void Empleado::setTipoJornada(char tipoJornada)
{
    this->tipoJornada = tipoJornada;
}

float Empleado::getSueldo()
{
    return sueldo;
}

void Empleado::setSueldo(float sueldo)
{
    this->sueldo = sueldo;
}

Empleado::Empleado() {
    ID = 0;
    categoria = 0;
    tipoJornada = '-';
    turno = '-';
    sueldo = 0;
}

void Empleado::cargar() {
    Persona::cargar();
    std::cout << "ID: ";
    std::cin >> ID;
    std::cout << "Categoria (1-Gerente/2-Cajero/3-Vendedor/4-Auxiliar de Limpieza): ";
    std::cin >> categoria;
    std::cout << "Fecha de ingreso:\n";
    fechaDeIngreso.cargarFecha();
    std::cout << "Tipo de jornada(f-Full-time/p-Part-time): ";
    std::cin >> tipoJornada;
    std::cout << "Turno (m-Mañana/T-Tarde/N-Noche): ";
    std::cin >> turno;
    std::cout << "Sueldo: ";
    std::cin >> sueldo;
}

void Empleado::mostrar() {
    Persona::mostrar();
    std::cout << "ID: " << ID << std::endl;
    std::cout << "Categoria: " << categoria << std::endl;
    std::cout << "Fecha de ingreso:\n";
    fechaDeIngreso.mostrarFecha();
    std::cout << std::endl <<"Tipo de jornada: ";
    if (tolower(tipoJornada)=='p')
    {
        std::cout << "Part-time";
    }
    else
    {
        std::cout << "Full-time";
    }
    std::cout << std::endl << "Turno: ";
    switch (tolower(turno))
    {
    case 'm':
        std::cout << "Mañana";
        break;
    case 't':
        std::cout << "Tarde";
        break;
    default:
        std::cout << "Noche";
        break;
    }
    std::cout << std::endl<< "Sueldo: $" << sueldo << std::endl;
}

bool Empleado::grabarEnDisco() {
    FILE* p = NULL;
    p = fopen("empleados.dat", "ab");
    if (p == NULL)
    {
        std::cout << "Error al guardar.\n";
        system("pause");
        return 0;
    }
    fwrite(this, sizeof(Empleado), 1, p);
    fclose(p);
    return 1;
}
bool Empleado::leerDeDisco(int pos) {
    FILE* p = NULL;
    p = fopen("empleados.dat", "rb+");
    if (p == NULL)
    {
        std::cout << "Error al abrir.\n";
        system("pause");
        return 0;
    }
    fseek(p, pos * sizeof(Empleado), 0);
    fread(this, sizeof(Empleado), 1, p);
    fclose(p);
    return 1;
}