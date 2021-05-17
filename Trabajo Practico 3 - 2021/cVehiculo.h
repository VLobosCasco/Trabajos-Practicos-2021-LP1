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
	//fecha ultimo mantenimiento
	
public:
	const string patente;
	int cant_pasajeros;
	eColores color;
#pragma region Constructores y Destructores
	cVehiculo(string patente_c, string chasis_c, string poliza_c, eColores color_c, int cant_pasajeros_c);
	
#pragma endregion
#pragma region Metodos

#pragma endregion
#pragma region Métodos virtuales
	//calcula el precio del alquiler del vehículo (tarifa base + precio por día) sin tener en cuenta los adicionales
	virtual float CalcularTarifa(int dias) = 0; 
	/*calcula el precio del alquiler del vehículo (tarifa base + precio por día) sin tener en cuenta los adicionales
	Recibe la fecha de inicio 	
	*/
	virtual float CalcularTarifa(cFecha fecha_inicio, cFecha fecha_fin) = 0;
#pragma endregion

};

