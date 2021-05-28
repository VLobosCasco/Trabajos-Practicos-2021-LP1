#pragma once
#include "cAdicional.h"
#include "cVehiculo.h"
#include "Definiciones.h"
#include <iostream>

using namespace std;
class cDuplaAdicional
{
	friend class cAlquiler;
	cAdicional* adicional1;
	cAdicional* adicional2;
	int CA;
	float tarifa_diaria_adicionales;

public:

#pragma region Constructor Destructor


	cDuplaAdicional(cVehiculo* vehiculo, float costo_primer_adicional = 0, float costo_segundo_adicional = 0);

	~cDuplaAdicional();

#pragma endregion

#pragma region Metodos

	//Actualiza la tarifa diaria de todos los adicionales en la lista
	void ActualizarTarifaDiaria();

	void AgregarAdicional(eTipoAdicional tipoadicional, int cantidad);

	void QuitarAdicional(eTipoAdicional tipoadicional, int cantidad);

	string To_string();

private:
	void setAdicionales(eTipoAdicional primer_adicional, float primer_costo, eTipoAdicional segundo_adicional = eTipoAdicional::NONE, float segundo_costo = 0);

#pragma endregion

};

