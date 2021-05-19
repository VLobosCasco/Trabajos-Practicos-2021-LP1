#include "cListaAdicional.h"


cListaAdicional::cListaAdicional(cVehiculo* v, float costo1, float costo2)
{
	tarifa_diaria_adicionales = 0;
	cMoto* aux_moto = dynamic_cast<cMoto*>(v);
	if (aux_moto != NULL)
	{
		if (costo1 == 0) costo1 = DEFAULT_CASCO;
		adicional1 = new cAdicional(eTipoAdicional::Casco, costo1, 0);
		adicional2 = NULL;
		CA = 1;
		return;
	}
	cAuto* aux_auto = dynamic_cast<cAuto*>(v);
	if (aux_auto != NULL)
	{
		if (costo1 == 0) costo1 = DEFAULT_SILLA;
		adicional1 = new cAdicional(eTipoAdicional::Silla_Ninos, costo1, 0);
		adicional2 = NULL;
		CA = 1;
		return;
	}
	cCamioneta* aux_cam = dynamic_cast<cCamioneta*>(v);
	if (aux_cam != NULL)
	{
		if (costo1 == 0) costo1 = DEFAULT_SILLA;
		adicional1 = new cAdicional(eTipoAdicional::Silla_Ninos, costo1, 0);
		if (costo2 == 0) costo2 = DEFAULT_PORTAEQUIPAJE;
		adicional2 = new cAdicional(eTipoAdicional::Portaequipaje, costo2, 0);
		CA = 2;
		return;

	}
	cTrafic* aux_t = dynamic_cast<cTrafic*>(v);
	if (aux_t != NULL)
	{
		if (costo1 == 0) costo1 = DEFAULT_SILLA;
		adicional1 = new cAdicional(eTipoAdicional::Silla_Ninos, costo1, 0);
		if (costo2 == 0) costo2 = DEFAULT_ASIENTO;
		adicional2 = new cAdicional(eTipoAdicional::Asientos_rebatibles, costo2, 0);
		CA = 2;
		return;

	}

}

cListaAdicional::~cListaAdicional()
{
	if (adicional1 != NULL) delete adicional1;
	if (adicional2 != NULL) delete adicional2;
}

void cListaAdicional::ActualizarTarifaDiaria()
{
	tarifa_diaria_adicionales = adicional1->CalcularCostoDiarioTotal() + adicional2->CalcularCostoDiarioTotal();
}

void cListaAdicional::AgregarAdicional(eTipoAdicional e, int cant)
{
	if (adicional1->elemento == e) {
		try {
			adicional1->AgregarElementos(cant);
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
	if (adicional2->elemento == e) {
		try {
			adicional2->AgregarElementos(cant);
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
