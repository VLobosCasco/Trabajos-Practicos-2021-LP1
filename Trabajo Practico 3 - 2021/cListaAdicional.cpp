#include "cListaAdicional.h"
#include "cMoto.h"
#include "cAuto.h"
#include "cCamioneta.h"
#include "cTrafic.h"

cListaAdicional::cListaAdicional(cVehiculo* vehiculo, float costo_primer_adicional, float costo_segundo_adicional)
{
	adicional1 = NULL;
	adicional2 = NULL;
	CA = 0;
	tarifa_diaria_adicionales = 0;

	cMoto* aux_moto = dynamic_cast<cMoto*>(vehiculo);
	if (aux_moto != NULL)
	{
		setAdicionales(eTipoAdicional::Casco, costo_primer_adicional);
		return;
	}

	cAuto* aux_auto = dynamic_cast<cAuto*>(vehiculo);
	if (aux_auto != NULL)
	{
		setAdicionales(eTipoAdicional::Silla_Ninos, costo_primer_adicional);
		return;
	}

	cCamioneta* aux_cam = dynamic_cast<cCamioneta*>(vehiculo);
	if (aux_cam != NULL)
	{
		setAdicionales(eTipoAdicional::Silla_Ninos, costo_primer_adicional, eTipoAdicional::Portaequipaje, costo_segundo_adicional);
		return;
	}

	cTrafic* aux_t = dynamic_cast<cTrafic*>(vehiculo);
	if (aux_t != NULL)
	{
		setAdicionales(eTipoAdicional::Silla_Ninos, costo_primer_adicional, eTipoAdicional::Asientos_rebatibles, costo_segundo_adicional);
		return;

	}
	ActualizarTarifaDiaria();
}


void cListaAdicional::setAdicionales(eTipoAdicional primer_adicional, float primer_costo, eTipoAdicional segundo_adicional, float segundo_costo)
{
	if (primer_costo == 0) 
		primer_costo = getCostoAdicionalDefault(primer_adicional);
	adicional1 = new cAdicional(primer_adicional, primer_costo, 0);
	CA = 1;

	if (segundo_adicional != eTipoAdicional::NONE)
	{
		if (segundo_costo == 0) 
			segundo_costo = getCostoAdicionalDefault(segundo_adicional);
		adicional2 = new cAdicional(segundo_adicional, segundo_costo, 0);
		CA = 2;
	}
	
}


cListaAdicional::~cListaAdicional()
{
	if (adicional1 != NULL) 
		delete adicional1;
	if (adicional2 != NULL) 
		delete adicional2;
}

void cListaAdicional::ActualizarTarifaDiaria()
{
	tarifa_diaria_adicionales = 0;
	
	if (adicional1 != NULL)
		tarifa_diaria_adicionales =+ adicional1->CalcularCostoDiarioTotal();
	
	if(adicional2!=NULL)
		tarifa_diaria_adicionales =+ adicional2->CalcularCostoDiarioTotal();
}

void cListaAdicional::AgregarAdicional(eTipoAdicional tipoadicional, int cant)
{
	if (adicional1->elemento == tipoadicional) {
		try {
			adicional1->ModificarElementos(cant);
			ActualizarTarifaDiaria();
			return;
		}
		catch (exception* ex)
		{
			string err = ex->what();
			delete ex;
			ex = new exception(("Error al agregar elementos: " + err).c_str());
			throw ex;
		}
	}
	if (adicional2->elemento == tipoadicional) {
		try {
			adicional2->ModificarElementos(cant);
			ActualizarTarifaDiaria();
			return;
		}
		catch (exception* ex)
		{
			string err = ex->what();
			delete ex;
			ex = new exception(("Error al agregar elementos: " + err).c_str());
			throw ex;
		}
	}
	throw new exception("No es posible agregar elementos de ese tipo en este alquiler");
}

void cListaAdicional::QuitarAdicional(eTipoAdicional tipoadicional, int cantidad)
{
	if (adicional1->elemento == tipoadicional) {
		try {
			adicional1->ModificarElementos(-cantidad);
			ActualizarTarifaDiaria();
			return;
		}
		catch (exception* ex)
		{
			string err = ex->what();
			delete ex;
			ex = new exception(("Error al quitar elementos: " + err).c_str());
			throw ex;
		}
	}
	if (adicional2->elemento == tipoadicional) 
	{
		try {
			adicional2->ModificarElementos(cantidad);
			ActualizarTarifaDiaria();
			return;
		}
		catch (exception* ex)
		{
			string err = ex->what();
			delete ex;
			ex = new exception(("Error al quitar elementos: " + err).c_str());
			throw ex;
		}
	}
	throw new exception("No es posible quitar elementos de ese tipo en este alquiler");
}
