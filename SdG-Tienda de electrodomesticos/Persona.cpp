#include "Persona.h"

void Persona::cargar() {
	std::string palabra;
	estado = true;
	std::cout << "Nombre: ";
	std::cin.ignore();
	std::getline(std::cin,palabra);
	setNombre(palabra);
	std::cout << "Apellido: ";
	std::getline(std::cin,palabra);
	setApellido(palabra);
	std::cout << "DNI: ";
	std::cin >> dni;
	std::cout << "Fecha de nacimiento: \n";
	fechaDeNacimiento.cargarFecha();
	//domicilio.cargar();
}
void Persona::cargar(int _dni) {
	std::string palabra;
	estado = true;
	std::cout << "Nombre: ";
	std::cin.ignore();
	std::getline(std::cin,palabra);
	setNombre(palabra);
	std::cout << "Apellido: ";
	std::getline(std::cin,palabra);
	setApellido(palabra);
	dni = _dni;
	std::cout << "Fecha de nacimiento: \n";
	fechaDeNacimiento.cargarFecha();
	//domicilio.cargar();
}
void Persona::mostrar() {
	std::cout << "Nombre y apellido: ";
	std::cout << nombre << " " << apellido << std::endl;
	std::cout << "DNI: ";
	std::cout << dni;
	std::cout << "\nFecha de nacimiento: \n";
	fechaDeNacimiento.mostrarFecha();
	std::cout << std::endl;
	//domicilio.mostrar();	
}


std::string Persona::getApellido() 
{
	std::string apellido = this->apellido;
    return apellido;
}

void Persona::setApellido(std::string apellido)
{
    strcpy(this->apellido,apellido.c_str());
}

std::string Persona::getNombre() 
{
	std::string nombre = this->nombre;
    return nombre;
}

void Persona::setNombre(std::string nombre)
{
    strcpy(this->nombre, nombre.c_str());
}

int Persona::getDni() const
{
    return dni;
}

void Persona::setDni(int dni)
{
    this->dni = dni;
}

FechaHora Persona::getFechaDeNacimiento() 
{
    return fechaDeNacimiento;
}

void Persona::setFechaDeNacimiento(FechaHora fechaDeNacimiento)
{
    this->fechaDeNacimiento = fechaDeNacimiento;
}

bool Persona::getEstado()
{
	return estado;
}

void Persona::setEstado(bool estado)
{
	this->estado = estado;
}