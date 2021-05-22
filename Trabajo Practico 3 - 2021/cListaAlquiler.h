#pragma once
#include "cListaT.h"
#include "cAlquiler.h"
class cListaAlquiler :
    protected cListaT<cAlquiler>
{
public:
#pragma region Metodos

	// Lista todos los alquileres de un cierto tipo de vehiculo
	template <class TipoVehiculo>
	void ListarAlquiler();

	// Lista todos los alquileres y devuelve la ganancia total de un cierto tipo de vehiculo
	template <class TipoVehiculo>
	void ListarGananciaAlquiler();

	//Agregar Alquiler, verifica que el vehiculo no se superponga
	void AgregarItem(cAlquiler* item);

#pragma endregion
};


template<class TipoVehiculo>
inline void cListaAlquiler::ListarGananciaAlquiler()
{
	float ganancia = 0;
	TipoVehiculo* aux = NULL;
	for (int i = 0; i < CA; i++)
	{
		aux = dynamic_cast<TipoVehiculo*>(vector[i]->vehiculo);
		if (aux != NULL) {
			vector[i]->Imprimir();
			ganancia = ganancia + vector[i]->monto_total;
		}
	}
	return ganancia;
}

template<class TipoVehiculo>
inline void cListaAlquiler::ListarAlquiler()
{
	TipoVehiculo* aux = NULL;
	for (int i = 0; i < CA; i++)
	{
		aux = dynamic_cast<TipoVehiculo*>(vector[i]->vehiculo);
		if (aux != NULL) {
			vector[i]->Imprimir();
		}
	}
}

