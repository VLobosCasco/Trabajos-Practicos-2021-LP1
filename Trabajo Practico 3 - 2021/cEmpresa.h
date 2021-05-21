#pragma once
#include "cListaAlquiler.h"
#include "cListaT.h"
class cEmpresa
{
private:
	const string nombre;
	cListaT<cVehiculo>* vehiculos;
	cListaAlquiler* alquileres;
	cListaT<cCliente>* clientes;

public:
#pragma region Constructor y Destructor
	cEmpresa(string n, cListaT<cVehiculo>* v, cListaT<cCliente>* c, cListaAlquiler* a);
#pragma endregion
#pragma region Adquirir y Retirar de Circulaci�n Vehiculos
//Agrega veh�culo a la lista de veh�culos
	void AdquirirVehiculo(cVehiculo* v);
//Elimina veh�culo de la lista de veh�culos
	void RetirardeCirculacion(cVehiculo* v);
//Busca al veh�culo por patente y lo elimina de la lista de vehiculos
	void RetirardeCirculacion(string patente);
#pragma endregion
#pragma region Mantenimiento
//Imprime los pasos de mantenimiento y cambia el estado a "en mantenimiento"
	void Mantenimiento(cVehiculo* v);
//Imprime los pasos de mantenimiento y cambia el estado a "en mantenimiento"
	void Mantenimiento(string patente);
//Actualiza la fecha de mantenimiento y cambia el estado a libre
	void TerminarMantenimiento(cVehiculo* v);
	//Actualiza la fecha de mantenimiento y cambia el estado a libre
	void TerminarMantenimiento(string p);
#pragma endregion
#pragma region To_string e Imprimir
	string to_string();
	void Imprimir();
#pragma endregion
};

