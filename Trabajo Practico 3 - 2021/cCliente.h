#pragma once
#include <iostream>
#include "cFecha.h"
#include <string>

using namespace std;
class cCliente
{
public:
	const string IDCliente; //clave
		
private:
	string TarjetadeCredito;
	const string DNI;
	cFecha* Fecha_de_Nacimiento;
	string NombreCompleto;
//Este atributo lo voy a usar para ir asignando IDs �nicos
	static int Cant_clientes; 

#pragma region Constructores y Destructores
public:
//Constructor por defecto, la fecha de nacimiento ser� la fecha actual, tendr� un ID v�lido.
	cCliente();
//Constructor por par�metros, recibe puntero a cFecha
	cCliente(string dni, string nombreapellido, cFecha* fdn, string tarj_cred);
//Constructor por par�metros, recibe datos de dia, mes, a�o
	cCliente(string dni, string nombreapellido, int dia, int mes, int anio, string tarj_cred);
	~cCliente();
#pragma endregion 
#pragma region Getters y Setters
//devuelve el IDCliente (clave)
	string getclave();
//devuelve IDCliente
	string getID();
#pragma endregion
#pragma region To_string e Imprimir
	string To_string();
	void Imprimir();
#pragma endregion
};

