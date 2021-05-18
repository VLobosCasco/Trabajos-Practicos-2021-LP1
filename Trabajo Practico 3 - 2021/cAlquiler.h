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
	const string ID;
	cCliente* cliente;
	cVehiculo* vehiculo;
	static cListaAlquiler* ListaAlquileres;
private:

};

