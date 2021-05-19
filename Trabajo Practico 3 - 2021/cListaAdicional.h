#pragma once
#include "cAdicional.h"
#include "cVehiculo.h"
#include "cMoto.h"
#include "cAuto.h"
#include "cCamioneta.h"
#include "cTrafic.h"
#include "Definiciones.h"
#include <iostream>

using namespace std;
class cListaAdicional
{
	friend class cAlquiler;
	cAdicional* adicional1;
	cAdicional* adicional2;
	int CA;
	float tarifa_diaria_adicionales;

public:
#pragma region Constructor Destructor
	cListaAdicional(cVehiculo* v, float costo1=0, float costo2=0);
	~cListaAdicional();
#pragma endregion
#pragma region Metodos
	void ActualizarTarifaDiaria();
	void AgregarAdicional(eTipoAdicional e, int cant);
#pragma endregion

};

