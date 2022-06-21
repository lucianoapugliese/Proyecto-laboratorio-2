#include "Persona.h"
Persona::Persona(){
	strcpy(nombre, " ");
	strcpy(apellido, " ");
	dni = 0;
	estado = true;
}
void Persona::cargar() {
	std::cout << "Nombre: ";
	std::cin.getline(nombre, 50);
	std::cout << "Apellido: ";
	std::cin.getline(apellido, 50);
	std::cout << "DNI: ";
	std::cin >> dni;
	std::cout << "Fecha de nacimiento: \n";
	fechaDeNacimiento.cargarFecha();
	std::cout << "Domicilio: \n";
	domicilio.cargar();
}
void Persona::mostrar() {
	std::cout << "Nombre y apellido: ";
	std::cout << nombre << " " << apellido << std::endl;
	std::cout << "DNI: ";
	std::cout << dni;
	std::cout << "\nFecha de nacimiento: \n";
	fechaDeNacimiento.mostrarFecha();
	std::cout << "\nDomicilio: \n";
	domicilio.mostrar();	
}


const char *Persona::getApellido() 
{
    return apellido;
}

void Persona::setApellido(const char *apellido)
{
    strcpy(this->apellido,apellido);
}

const char *Persona::getNombre() 
{
    return nombre;
}

void Persona::setNombre(const char *nombre)
{
    strcpy(this->nombre, nombre);
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

Direccion Persona::getDomicilio() 
{
    return domicilio;
}

void Persona::setDomicilio(Direccion domicilio)
{
    this->domicilio = domicilio;
}