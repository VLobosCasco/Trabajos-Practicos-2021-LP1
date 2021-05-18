#pragma once
#include <iostream>
#include <string>
#include "Definiciones.h"
#include "cFecha.h"
using namespace std;

class cVehiculo
{
protected:	
	const string chasis;
	const string poliza;
	cFecha* Ultimo_Mantenimiento;
	
public:
	const string patente;
	int cant_pasajeros;
	eColores color;

#pragma region Constructores y Destructores
//Constructor. Inicializa la fecha de último mantenimiento como la fecha actual.
	cVehiculo(string patente_c, string chasis_c, string poliza_c, eColores color_c, int cant_pasajeros_c);
	cVehiculo(string patente_c, string chasis_c, string poliza_c, eColores color_c, int cant_pasajeros_c, cFecha* ult_mantenimiento);
	~cVehiculo();
#pragma endregion
#pragma region Metodos
	void ActualizarMantenimiento();
#pragma endregion
#pragma region Métodos virtuales
	//calcula el precio del alquiler del vehículo (tarifa base + precio por día) sin tener en cuenta los adicionales
	virtual float CalcularTarifa(int dias) = 0; 
	/*calcula el precio del alquiler del vehículo (tarifa base + precio por día) sin tener en cuenta los adicionales
	Recibe la fecha de inicio */
	virtual float CalcularTarifa(cFecha& fecha_inicio, cFecha& fecha_fin) = 0;
	//Imprime los pasos de mantenimiento para el vehículo
	virtual void PasosMantenimiento() = 0;
#pragma endregion
#pragma region To_string e Imprimir
	string to_string();
	void Imprimir();
#pragma endregion
};

