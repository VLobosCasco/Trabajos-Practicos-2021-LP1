#pragma once
#include <iostream>
#include "cFecha.h"
#include "cMoto.h"
#include "cAuto.h"
#include "cCamioneta.h"
#include "cTrafic.h"
#include "cCliente.h"

using namespace std;
class cListaAlquiler;
class cAlquiler
{
public:
	const string clave;
	cCliente* cliente;
	cVehiculo* vehiculo;
	static cListaAlquiler* ListaAlquileres;
	cFecha* fecha_inicio;
	cFecha* fecha_fin;
	float monto_total;
	float tarifa_diaria_adicionales;

#pragma region Constructor y Destructor

#pragma endregion
#pragma region To_string e Imprimir
	string to_string();
	void Imprimir();
#pragma endregion
#pragma region Getters y Setters
//devuelve IDAlquiler (clave)
	string getclave(); //lo necesito para la lista
//devuelve IDAlquiler
	string getID();
#pragma endregion
};

