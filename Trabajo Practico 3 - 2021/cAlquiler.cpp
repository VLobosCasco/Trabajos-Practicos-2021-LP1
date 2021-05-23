#include "cAlquiler.h"

#include "cAuto.h"
#include "cMoto.h"
#include "cCamioneta.h"
#include "cTrafic.h"

int cAlquiler::Cont_alquiler = 0;

cAlquiler::cAlquiler(cCliente* _cliente, cVehiculo* _vehiculo, cFecha* _fecha_inicio, cFecha* _fecha_final, float costo1, float costo2) :IDAlquiler(std::to_string(Cont_alquiler))
{
	cliente = _cliente;
	if (_vehiculo->getEstado() == eEstado::Libre)
		vehiculo = _vehiculo;
	else
		throw new exception("El veh�culo no se encuentra disponible");
	fecha_inicio = _fecha_inicio;
	fecha_fin = _fecha_final;
	adicionales = new cListaAdicional(_vehiculo, costo1, costo2);
	ActualizarMontoTotal();
	Cont_alquiler++;

}

cAlquiler::~cAlquiler()
{
	if (adicionales != NULL) 
		delete adicionales;
}

string cAlquiler::To_string()
{
	return string();
}

void cAlquiler::Imprimir()
{
	cout << To_string() << endl;
}

string cAlquiler::getclave() const
{
	return IDAlquiler;
}

string cAlquiler::getID() const
{
	return IDAlquiler;
}

cVehiculo* cAlquiler::getvehiculo() const
{
	return vehiculo;
}

cFecha* cAlquiler::getfechainicio() const
{
	return fecha_inicio;
}

cFecha* cAlquiler::getfechafin() const
{
	return fecha_fin;
}

void cAlquiler::ActualizarMontoTotal()
{
	monto_total = 0;
	adicionales->ActualizarTarifaDiaria();
	monto_total = getvehiculo()->CalcularTarifa(*getfechainicio(), *getfechafin()) + adicionales->tarifa_diaria_adicionales * cFecha::DiasEntreFechas(getfechainicio(), getfechafin());
}

void cAlquiler::AgregarAdicional(eTipoAdicional tipoAdicional, int cant)
{
	try {
		adicionales->AgregarAdicional(tipoAdicional, cant);
		ActualizarMontoTotal();
		if (tipoAdicional == eTipoAdicional::Asientos_rebatibles) //si agregu� asientos, aumento la cantidad de plazas
			vehiculo->ModificarAsientos(cant);
	}
	catch (exception* ex) {
		throw ex;
	}
}

bool cAlquiler::VerificarDisponibilidad(cFecha* inicio, cFecha* fin)
{
	bool aux = cFecha::FechasSuperpuestas(fecha_inicio, fecha_fin, inicio, fin); 
	return !aux; //si las fechas se superponen, entonces no est� disponible
}

void cAlquiler::QuitarAdicional(eTipoAdicional tipoAdicional, int cant)
{
	try {
		adicionales->QuitarAdicional(tipoAdicional, cant);
		ActualizarMontoTotal();
		if (tipoAdicional == eTipoAdicional::Asientos_rebatibles) //si agregu� asientos, aumento la cantidad de plazas
			vehiculo->ModificarAsientos(-cant);
	}
	catch (exception* ex) {
		throw ex;
	}
}

