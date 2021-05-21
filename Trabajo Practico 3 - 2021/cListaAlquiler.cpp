#include "cListaAlquiler.h"

void cListaAlquiler::ListarAlquilerMotos()
{
	cMoto* aux = NULL;
	for (int i = 0; i < CA; i++) 
	{
		aux = dynamic_cast<cMoto*>(vector[i]->vehiculo);
		if (aux != NULL) {
			vector[i]->Imprimir();
		}
	}
}

void cListaAlquiler::ListarAlquilerAutos()
{
	cAuto* aux = NULL;
	for (int i = 0; i < CA; i++)
	{
		aux = dynamic_cast<cAuto*>(vector[i]->vehiculo);
		if (aux != NULL) {
			vector[i]->Imprimir();
		}
	}
}

void cListaAlquiler::ListarAlquilerCamionetas()
{
	cCamioneta* aux = NULL;
	for (int i = 0; i < CA; i++)
	{
		aux = dynamic_cast<cCamioneta*>(vector[i]->vehiculo);
		if (aux != NULL) {
			vector[i]->Imprimir();
		}
	}
}

void cListaAlquiler::ListarAlquilerTrafics()
{
	cTrafic* aux = NULL;
	for (int i = 0; i < CA; i++)
	{
		aux = dynamic_cast<cTrafic*>(vector[i]->vehiculo);
		if (aux != NULL) {
			vector[i]->Imprimir();
		}
	}
}

float cListaAlquiler::ListaryGananciaAlquilerMotos()
{
	float ganancia = 0;
	cMoto* aux = NULL;
	for (int i = 0; i < CA; i++)
	{
		aux = dynamic_cast<cMoto*>(vector[i]->vehiculo);
		if (aux != NULL) {
			vector[i]->Imprimir();
			ganancia = ganancia + vector[i]->monto_total;
		}
	}
	return ganancia;
}

float cListaAlquiler::ListaryGananciaAlquilerAutos()
{
	float g = 0;
	cAuto* aux = NULL;
	for (int i = 0; i < CA; i++)
	{
		aux = dynamic_cast<cAuto*>(vector[i]->vehiculo);
		if (aux != NULL) {
			vector[i]->Imprimir();
			g = g + vector[i]->monto_total;
		}
	}
	return g;
}

float cListaAlquiler::ListaryGananciaAlquilerCamionetas()
{
	float g = 0;
	cCamioneta* aux = NULL;
	for (int i = 0; i < CA; i++)
	{
		aux = dynamic_cast<cCamioneta*>(vector[i]->vehiculo);
		if (aux != NULL) {
			vector[i]->Imprimir();
			g = g + vector[i]->monto_total;
		}
	}
	return g;
}

float cListaAlquiler::ListaryGananciaAlquilerTrafics()
{
	float g = 0;
	cTrafic* aux = NULL;
	for (int i = 0; i < CA; i++)
	{
		aux = dynamic_cast<cTrafic*>(vector[i]->vehiculo);
		if (aux != NULL) {
			vector[i]->Imprimir();
			g = g + vector[i]->monto_total;
		}
	}
	return g;
}

float cListaAlquiler::ListaryGanancia()
{
	float g = 0;
	for (unsigned int i = 0; i < CA; i++)
	{
		vector[i]->Imprimir();
		g = g + vector[i]->monto_total;
	}
	return g;
}

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
