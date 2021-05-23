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

	cEmpresa(string nombre, cListaT<cVehiculo>* lista_vehiculos, cListaT<cCliente>* lista_clientes, cListaAlquiler* lista_alquileres);

#pragma endregion

#pragma region Adquirir y Retirar de Circulaci�n Vehiculos

	//Agrega veh�culo a la lista de veh�culos
	void AdquirirVehiculo(cVehiculo* vehiculo);

	//Cambia estado del veh�culo a fuera de circulaci�n
	void RetirardeCirculacion(cVehiculo* vehiculo);

	//Busca al veh�culo por patente y cambia estado del veh�culo a fuera de circulaci�n
	void RetirardeCirculacion(string patente);

#pragma endregion

#pragma region Mantenimiento

	//Imprime los pasos de mantenimiento y cambia el estado a "en mantenimiento"
	void Mantenimiento(cVehiculo* vehiculo);

	//Imprime los pasos de mantenimiento y cambia el estado a "en mantenimiento"
	void Mantenimiento(string patente);

	//Actualiza la fecha de mantenimiento y cambia el estado a libre
	void TerminarMantenimiento(cVehiculo* vehiculo);

	//Actualiza la fecha de mantenimiento y cambia el estado a libre
	void TerminarMantenimiento(string patente);

#pragma endregion

#pragma region To_string e Imprimir

	string To_string();
	void Imprimir();

#pragma endregion

#pragma region Getters y Setters

	//Devuelve la lista de vehiculos
	cListaT<cVehiculo>* getListaVehiculos();

	//Devuelve la lista de alquileres
	cListaAlquiler* getListaAlquileres();

#pragma endregion
};

