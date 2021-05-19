#include "cEmpresa.h"

cEmpresa::cEmpresa(string n, cListaVehiculo* v, cListaCliente* c, cListaAlquiler* a):nombre(n)
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
		throw new exception("Error al agregar: No hay datos del veh�culo");
}

void cEmpresa::RetirardeCirculacion(cVehiculo* v)
{
	if (v != NULL)
	{
		try {
			vehiculos->Eliminar(v);
		}
		catch (exception* ex) {
			string err = ex->what();
			delete ex;
			throw new exception(("Error al eliminar: " + err).c_str());
		}
	}
	else
		throw new exception("Error al agregar: No hay datos del veh�culo");
}


void cEmpresa::RetirardeCirculacion(string patente)
{
		try {
			vehiculos->Eliminar(patente);
		}
		catch (exception* ex) {
			string err = ex->what();
			delete ex;
			throw new exception(("Error al eliminar: " + err).c_str());
		}

}

void cEmpresa::Mantenimiento(cVehiculo* v)
{
	v->PasosMantenimiento();
}

string cEmpresa::to_string()
{
	return string();
}

void cEmpresa::Imprimir()
{
	cout << to_string() << endl;
}
