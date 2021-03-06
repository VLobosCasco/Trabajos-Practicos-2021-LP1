#pragma once
#include "cVehiculo.h"
class cTrafic :
	public cVehiculo
{
private:
	static float precio_base;
	static float precio_diario;

#pragma region Constructor
public:
	cTrafic(string patente_c, string chasis_c, string poliza_c, eColores color_c, int cant_pasaj_c, cFecha* ult_mantenimiento = NULL);

#pragma endregion

#pragma region Metodos

	inline static float GetPrecioBase() { return precio_base; }
	inline static float GetPrecioDiario() { return precio_diario; }

	//calcula el precio del alquiler del veh?culo (tarifa base + precio por d?a) sin tener en cuenta los adicionales
	float CalcularTarifa(int dias);

	/*calcula el precio del alquiler del veh?culo (tarifa base + precio por d?a) sin tener en cuenta los adicionales
	Recibe la fecha de inicio */
	float CalcularTarifa(cFecha& fecha_inicio, cFecha& fecha_fin);

	//Imprime los pasos de mantenimiento para el veh?culo
	void PasosMantenimiento();

#pragma endregion

#pragma region To_string e Imprimir

	string To_string();
	void Imprimir();

};

