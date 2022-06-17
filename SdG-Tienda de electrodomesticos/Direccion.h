#pragma once
class Direccion
{
private:
	char calle[30], localidad[30], departamento;
	int numero, cp, piso;
public:
	void setCalle(const char* _calle) { strcpy(calle, _calle); };
	void setLocalidad(const char* _localidad) { strcpy(localidad, _localidad); };
	void setDepartamento(char _departamento) { departamento = _departamento; };
	void setNumero(int _numero) { if (_numero > -1)numero = _numero; };
	void setCp(int _cp) { if (cp > 0) cp = _cp; };
	void setPiso(int _piso) { piso = piso; };

	const char* getCalle() { return calle; };
	const char* getLocalidad() { return localidad; };
	char getDepartamento() { return departamento; };
	int getNumero() { return numero; };
	int getCp() { return cp; };
	int getPiso() { return piso; };

	void cargar();
	void mostrar();


};