#include "cEmpresa.h"

cEmpresa::cEmpresa(string n, cListaT<cVehiculo>* v, cListaT<cCliente>* c, cListaAlquiler* a):nombre(n)
{
	vehiculos = v;
	alquileres = a;
	clientes = c;
}

void cEmpresa::AdquirirVehiculo(cVehiculo* v)
{
	if (v != NULL)
	{
		try {
			vehiculos->AgregarItem(v);
		}
		catch (exception* ex) {
			string err = ex->what();
			delete ex;
			throw new exception(("Error al agregar: " + err).c_str());
		}
	}
	else
		throw new exception("Error al retirar de circulación: No hay datos del vehículo");
}

void cEmpresa::RetirardeCirculacion(cVehiculo* v)
{
	if (v != NULL)
	{
		v->estado = eEstado::Fuera_de_servicio;
	}
	else
		throw new exception("Error al retirar de circulación: No hay datos del vehículo");
}


void cEmpresa::RetirardeCirculacion(string patente)
{
	cVehiculo* aux = NULL;
	try {
		aux = vehiculos->BuscarItem(patente);
	}
	catch (exception* e) {
		string err = e->what();
		delete e;
		e = new exception(("Error al buscar el vehiculo:" + err).c_str());
		throw e;
	}
	aux->estado = eEstado::Fuera_de_servicio;

}

void cEmpresa::Mantenimiento(cVehiculo* v)
{
	v->estado = eEstado::En_Mantenimiento;
	v->PasosMantenimiento();
}

void cEmpresa::Mantenimiento(string patente)
{
	cVehiculo* aux = NULL;
	try {
		aux = vehiculos->BuscarItem(patente);
	}
	catch (exception* e) {
		string err = e->what();
		delete e;
		e = new exception(("Error al buscar el vehiculo:" + err).c_str());
		throw e;
	}
	Mantenimiento(aux);
}

void cEmpresa::TerminarMantenimiento(cVehiculo* v) {
	v->ActualizarMantenimiento();
	v->estado = eEstado::Libre;
}
void cEmpresa::TerminarMantenimiento(string p) {
	cVehiculo* aux = NULL;
	try {
		aux = vehiculos->BuscarItem(p);
	}
	catch (exception* e) {
		string err = e->what();
		delete e;
		e = new exception(("Error al buscar el vehiculo:" + err).c_str());
		throw e;
	}
	aux->ActualizarMantenimiento();
	aux->estado = eEstado::Libre;
}

string cEmpresa::To_string()
{
	return string();
}

void cEmpresa::Imprimir()
{
	cout << To_string() << endl;
}
