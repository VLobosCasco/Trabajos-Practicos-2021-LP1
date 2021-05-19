#pragma once
#include "cListaAlquiler.h"
#include "cListaCliente.h"
#include "cListaVehiculo.h"
class cEmpresa
{
private:
	const string nombre;
	cListaVehiculo* vehiculos;
	cListaAlquiler* alquileres;
	cListaCliente* clientes;
public:
#pragma region Constructor y Destructor
	cEmpresa(string n, cListaVehiculo* v, cListaCliente* c, cListaAlquiler* a);
#pragma endregion
#pragma region Adquirir y Retirar de Circulación Vehiculos
//Agrega vehículo a la lista de vehículos
	void AdquirirVehiculo(cVehiculo* v);
//Elimina vehículo de la lista de vehículos
	void RetirardeCirculacion(cVehiculo* v);
//Busca al vehículo por patente y lo elimina de la lista de vehiculos
	void RetirardeCirculacion(string patente);
#pragma endregion
#pragma region Mantenimiento
//Imprime los pasos de mantenimiento y actualiza la fecha de ultimo mantenimiento
	void Mantenimiento(cVehiculo* v);
#pragma endregion
#pragma region To_string e Imprimir
	string to_string();
	void Imprimir();
#pragma endregion
};

