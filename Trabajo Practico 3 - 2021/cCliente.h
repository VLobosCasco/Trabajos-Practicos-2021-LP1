#pragma once
#include <iostream>
#include "cFecha.h"
#include <string>

using namespace std;
class cCliente
{
private:
	
	string TarjetadeCredito;
	const string DNI; //clave
	cFecha* Fecha_de_Nacimiento;
	string NombreCompleto;



#pragma region Constructores y Destructores
public:

	//Constructor por defecto, la fecha de nacimiento será la fecha actual, tendrá un ID válido.
	cCliente();

	//Constructor por parámetros, recibe puntero a cFecha
	cCliente(string dni, string nombreapellido, cFecha* fecha_nacimiento, string tarjeta_credito);

	//Constructor por parámetros, recibe datos de dia, mes, año
	cCliente(string dni, string nombreapellido, int dia, int mes, int anio, string tarjeta_credito);

	~cCliente();

#pragma endregion 

#pragma region Getters y Setters

	//devuelve el dni (clave)
	string getclave() const; //lo necesito para la lista

#pragma endregion

#pragma region To_string e Imprimir

	string To_string();
	void Imprimir();

#pragma endregion

#pragma region Sobrecarga

	bool operator ==(string otra_clave) {
		return this->getclave() == otra_clave;
	}

	bool operator !=(string otra_clave) {
		return this->getclave() != otra_clave;
	}
#pragma endregion
};

