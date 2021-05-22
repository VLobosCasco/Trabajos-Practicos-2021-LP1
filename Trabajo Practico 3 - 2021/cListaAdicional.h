#pragma once
#include "cAdicional.h"
#include "cVehiculo.h"
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


	cListaAdicional(cVehiculo* vehiculo, float costo_primer_adicional = 0, float costo_segundo_adicional = 0);

	~cListaAdicional();

#pragma endregion

#pragma region Metodos

	void ActualizarTarifaDiaria();

	void AgregarAdicional(eTipoAdicional tipoadicional, int cantidad);

	void QuitarAdicional(eTipoAdicional tipoadicional, int cantidad);

private:
	void setAdicionales(eTipoAdicional primer_adicional, float primer_costo, eTipoAdicional segundo_adicional = eTipoAdicional::NONE, float segundo_costo = 0);

#pragma endregion

};

