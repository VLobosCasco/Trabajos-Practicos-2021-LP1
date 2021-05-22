#include "cListaAlquiler.h"


void cListaAlquiler::AgregarItem(cAlquiler* item)
{

	cAlquiler* i_f = BuscarItem(item->getclave());
	if (i_f != NULL)
		throw new exception("Ya se encuentra en la lista");

	for (unsigned int i = 0; i < CA; i++) {

		if (vector[i]->getvehiculo() == item->getvehiculo()) {
			if (!vector[i]->VerificarDisponibilidad(item->getfechainicio(),item->getfechafin()))
				throw new exception("El vehículo no se encuentra disponible en esas fechas");
		}
	}

	if (CA < TAM)
		vector[CA++] = item;
	else
		throw new exception("No hay tamaño suficiente para agregar el item");
		

}
