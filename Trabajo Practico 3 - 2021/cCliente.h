#pragma once
#include <iostream>
#include "cFecha.h"
#include <string>

using namespace std;
class cCliente
{
private:
	const string IDCliente; //clave
	string TarjetadeCredito;
	const string DNI;
	cFecha* Fecha_de_Nacimiento;
	string NombreCompleto;

	//Este atributo lo voy a usar para ir asignando IDs únicos
	static int Cant_clientes;

#pragma region Constructores y Destructores
public:

	//Constructor por defecto, la fecha de nacimiento será la fecha actual, tendrá un ID válido.
	cCliente();

	//Constructor por parámetros, recibe puntero a cFecha
	cCliente(string dni, string nombreapellido, cFecha* fdn, string tarj_cred);

	//Constructor por parámetros, recibe datos de dia, mes, año
	cCliente(string dni, string nombreapellido, int dia, int mes, int anio, string tarj_cred);

	~cCliente();

#pragma endregion 

#pragma region Getters y Setters

	//devuelve el IDCliente (clave)
	string getclave() const;

	//devuelve IDCliente
	string getID() const;

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

