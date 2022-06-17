#pragma once
class FechaHora
{
	class FechaHora {
	public:
		int  getDia();
		int  getMes();
		int  getAnio();
		int  getHora();
		int  getMinuto();
		void setDia(int dia);
		void setMes(int mes);
		void setAnio(int anio);
		void setHora(int hora);
		void setMinuto(int minuto);
		FechaHora(int dia, int mes, int anio, int hora, int minuto);
		FechaHora();
		std::string toString();

	private:
		int _dia, _mes, _anio;
		int _hora, _minuto;

	};
};