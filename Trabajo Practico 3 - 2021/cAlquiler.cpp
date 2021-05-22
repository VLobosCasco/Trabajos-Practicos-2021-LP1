#include "cAlquiler.h"

#include "cAuto.h"
#include "cMoto.h"
#include "cCamioneta.h"
#include "cTrafic.h"

int cAlquiler::Cont_alquiler = 0;

cAlquiler::cAlquiler(cCliente* cliente, cVehiculo* vehiculo, cFecha* fecha_inicio, cFecha* fecha_final, float costo1, float costo2) :IDAlquiler(std::to_string(Cont_alquiler))
{
	cliente = cliente;
	if (vehiculo->getEstado() == eEstado::Libre)
		vehiculo = vehiculo;
	else
		throw new exception("El vehículo no se encuentra disponible");
	fecha_inicio = fecha_inicio;
	fecha_fin = fecha_final;
	adicionales = new cListaAdicional(vehiculo, costo1, costo2);
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
	adicionales->ActualizarTarifaDiaria();
	monto_total = vehiculo->CalcularTarifa(*fecha_inicio, *fecha_fin) + adicionales->tarifa_diaria_adicionales * cFecha::DiasEntreFechas(fecha_inicio, fecha_fin);
}

void cAlquiler::AgregarAdicional(eTipoAdicional tipoAdicional, int cant)
{
	try {
		adicionales->AgregarAdicional(tipoAdicional, cant);
		ActualizarMontoTotal();
	}
	catch (exception* ex) {
		throw ex;
	}
}

bool cAlquiler::VerificarDisponibilidad(cFecha* inicio, cFecha* fin)
{
	bool aux = cFecha::FechasSuperpuestas(fecha_inicio, fecha_fin, inicio, fin);
	return aux;
}

