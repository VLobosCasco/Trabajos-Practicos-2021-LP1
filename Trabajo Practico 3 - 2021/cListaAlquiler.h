#pragma once
#include "cListaT.h"
#include "cAlquiler.h"
class cListaAlquiler :
    public cListaT<cAlquiler>
{
public:
#pragma region Constructor
	cListaAlquiler();
	cListaAlquiler(int tam, bool eliminar);
#pragma endregion

#pragma region Metodos

	// Lista todos los alquileres de un cierto tipo de vehiculo
	template <class TipoVehiculo> //esto me permite usar el mismo código para las 4 impresiones
	void ListarAlquiler();

	// Lista todos los alquileres y devuelve la ganancia total de un cierto tipo de vehiculo
	template <class TipoVehiculo>//esto me permite usar el mismo código para las 4 impresiones y cálculo de ganancia
	float ListarGananciaAlquiler();

	//Agregar Alquiler, verifica que el vehiculo no se superponga
	void AgregarItem(cAlquiler* item); //sobreescribo el de cListaT porque necesito ahcer otras verificaciones
	
	//To String
	string To_String();

	//AgregarAlquiler
	void operator+(cAlquiler* item); //sobreescribo el de lista

#pragma endregion
};

template<class TipoVehiculo>
float cListaAlquiler::ListarGananciaAlquiler()
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
		aux = dynamic_cast<TipoVehiculo*>(vector[i]->getvehiculo());
		if (aux != NULL) {
			vector[i]->Imprimir();
		}
	}
}

