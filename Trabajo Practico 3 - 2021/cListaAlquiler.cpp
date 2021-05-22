#include "cListaAlquiler.h"


void cListaAlquiler::AgregarItem(cAlquiler* item)
{

	cAlquiler* i_f = BuscarItem(item->getclave());
	if (i_f != NULL)
		throw new exception("Ya se encuentra en la lista");
	if ()
	if (CA < TAM)
		vector[CA++] = item;
	else
		throw new exception("No hay tamaño suficiente para agregar el item");
		

}
