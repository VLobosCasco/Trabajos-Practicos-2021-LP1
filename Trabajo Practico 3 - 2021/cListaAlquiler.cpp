#include "cListaAlquiler.h"


cListaAlquiler::cListaAlquiler():cListaT<cAlquiler>()
{
}

cListaAlquiler::cListaAlquiler(int tam, bool eliminar):cListaT<cAlquiler>(tam,eliminar)
{
}

void cListaAlquiler::AgregarItem(cAlquiler* item)
{

	cAlquiler* i_f = BuscarItem(item->getclave());
	if (i_f != NULL)
		throw runtime_error("Ya se encuentra en la lista");

	for (unsigned int i = 0; i < CA; i++) {

		//me fijo que no haya otro alquiler con el mismo vehiculo en las mismas fechas
		if (*(vector[i]->getvehiculo()) == *(item->getvehiculo())) {

			if (!vector[i]->VerificarDisponibilidad(item->getfechainicio(),item->getfechafin()))
				throw runtime_error("El vehículo no se encuentra disponible en esas fechas");
		}
	}

	if (CA < TAM)
		vector[CA++] = item;
	else
		throw runtime_error("No hay tamaño suficiente para agregar el item");
		

}

string cListaAlquiler::To_String()
{
	string Total;
	for (unsigned int i = 0; i < CA; i++)
	{
		Total += vector[i]->To_string();// imprimir
	}
	return Total;
}

void cListaAlquiler::operator+(cAlquiler* item)
{
	AgregarItem(item);
}
