#pragma once
class Persona
{
protected:
	char apellido[25], nombre[25];
	int dni;
	FechaHora fechaDeNacimiento;
	Direccion domicilio;
public:
	void cargar() {
		std::cout << "Apellido: ";
		std::cin >> apellido;
		std::cout << "Nombre: ";
		std::cin >> nombre;
		std::cout << "DNI: ";
		std::cin >> dni;
		std::cout << "Cantidad de compras: ";
		std::cin >> cantidadCompras;
	}
	void mostrar() {
		std::cout << '\t' << std::left << std::setw(25) << apellido << std::setw(25) << nombre << std::setw(25) << dni << std::setw(25) << cantidadCompras << std::endl;
	}
	bool grabarEnDisco();
	bool leerDeDisco(int pos);
    char getApellido() const;
    void setApellido(char apellido);

    char getNombre() const;
    void setNombre(char nombre);

    int getDni() const;
    void setDni(int dni);

    FechaHora getFechaDeNacimiento() const;
    void setFechaDeNacimiento(FechaHora fechaDeNacimiento);

    Direccion getDomicilio() const;
    void setDomicilio(Direccion domicilio);



};