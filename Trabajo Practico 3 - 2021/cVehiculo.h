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

	const string patente;//clave
	int cant_pasajeros;
	eColores color;
	eEstado estado;

#pragma region Constructores y Destructores
public:
	//Constructor. Inicializa la fecha de último mantenimiento como NULL si no se la pasa
	cVehiculo(string patente_c, string chasis_c, string poliza_c, eColores color_c, int cant_pasajeros_c, cFecha* ult_mantenimiento = NULL);

	~cVehiculo();

#pragma endregion

#pragma region Metodos

	//Actualiza la fecha de mantenimiento
	void ActualizarMantenimiento();

	//Modifica la cantidad de plazas, si el número es <0 las quita, si es >0 las agrega
	void ModificarAsientos(int cantidad);

#pragma region Métodos virtuales

	//Calcula el precio del alquiler del vehículo (tarifa base + precio por día) sin tener en cuenta los adicionales
	virtual float CalcularTarifa(int dias) = 0;

	/*Calcula el precio del alquiler del vehículo (tarifa base + precio por día) sin tener en cuenta los adicionales
	Recibe la fecha de inicio */
	virtual float CalcularTarifa(cFecha& fecha_inicio, cFecha& fecha_fin) = 0;

	//Imprime los pasos de mantenimiento para el vehículo
	virtual void PasosMantenimiento() = 0;

#pragma endregion

#pragma region To_string e Imprimir

	string To_string();
	void Imprimir();

#pragma endregion

#pragma region Getters y Setters

	//Devuelve la patente(clave)
	string getclave() const { return patente; }//necesaria para usar lista

	//Devuelve la patente
	string getpatente() const { return patente; }

	//Devuelve la patente
	eEstado getEstado() const { return estado; }

	void setEstado(eEstado estado_nuevo) { estado = estado_nuevo; }

#pragma endregion
#pragma endregion

#pragma region Sobrecarga
	bool operator ==(cVehiculo* otro) {
		return this->getclave() == otro->getclave();
	}
	bool operator !=(cVehiculo* otro) {
		return this->getclave() != otro->getclave();
	}
	bool operator ==(string otra_clave) {
		return this->getclave() == otra_clave;
	}
	bool operator !=(string otra_clave) {
		return this->getclave() != otra_clave;
	}
#pragma endregion
};

