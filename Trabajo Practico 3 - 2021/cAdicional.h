#pragma once
#include <iostream>
#include "Definiciones.h"
using namespace std;
class cAdicional
{
public:
	const eTipoAdicional elemento;
	float costo_diario;
	int cantidad;

#pragma region Constructor y Destructor

	cAdicional(eTipoAdicional e, float costo, int cant = 0);

#pragma endregion

#pragma region Metodos

	// Calcula el Costo diario para todos los elementos de este tipo
	float CalcularCostoDiarioTotal();

	//Modifica la cantidad. Aumenta la cantidad de cantidad>0, la reduce si cantidad<0
	void ModificarElementos(int cant = 1);

	string To_string();

#pragma endregion
};

