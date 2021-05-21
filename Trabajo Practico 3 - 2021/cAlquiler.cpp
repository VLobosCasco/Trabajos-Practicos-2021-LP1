#include "cAlquiler.h"

int cAlquiler::Cont_alquiler = 0;

cAlquiler::cAlquiler(cCliente* c, cVehiculo* v, cFecha* fi, cFecha* ff, float costo1,float costo2):IDAlquiler(std::to_string(Cont_alquiler))
{
	cliente = c;
	if (v->estado == eEstado::Libre)
		vehiculo = v;
	else
		throw new exception("El veh�culo no se encuentra disponible");
	fecha_inicio = fi;
	fecha_fin = ff;
	adicionales = new cListaAdicional(v,costo1,costo2);
	ActualizarMontoTotal();
	Cont_alquiler++;

}

cAlquiler::~cAlquiler()
{
	if (adicionales != NULL) delete adicionales;
}

string cAlquiler::to_string()
{
	return string();
}

void cAlquiler::Imprimir()
{
	cout << to_string ()<< endl;
}

string cAlquiler::getclave()
{
	return IDAlquiler;
}

string cAlquiler::getID()
{
	return IDAlquiler;
}

void cAlquiler::ActualizarMontoTotal()
{
	adicionales->ActualizarTarifaDiaria();
	monto_total = vehiculo->CalcularTarifa(*fecha_inicio, *fecha_fin) + adicionales->tarifa_diaria_adicionales*cFecha::DiasEntreFechas(fecha_inicio,fecha_fin);
}

void cAlquiler::AgregarAdicional(eTipoAdicional e, int cant)
{
	try {
		adicionales->AgregarAdicional(e, cant);
		ActualizarMontoTotal();
	}
	catch (exception* ex) {
		throw ex;
	}
}

