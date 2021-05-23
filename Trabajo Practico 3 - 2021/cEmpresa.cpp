#include "cEmpresa.h"

cEmpresa::cEmpresa(string nombre, cListaT<cVehiculo>* lista_vehiculos, cListaT<cCliente>* lista_clientes, cListaAlquiler* lista_alquileres) :nombre(nombre)
{
	if (lista_vehiculos != NULL)
		vehiculos = lista_vehiculos;
	else
		vehiculos = new cListaT<cVehiculo>();

	if (lista_clientes != NULL)
		clientes = lista_clientes;
	else
		clientes = new cListaT<cCliente>();

	if (lista_alquileres != NULL)
		alquileres = lista_alquileres;
	else
		alquileres = new cListaAlquiler();
}

void cEmpresa::AdquirirVehiculo(cVehiculo* vehiculo)
{
	if (vehiculo != NULL)
	{
		try {
			vehiculos->AgregarItem(vehiculo);
		}
		catch (exception* ex) {
			string err = ex->what();
			delete ex;
			throw new exception(("Error al agregar: " + err).c_str());
		}
	}
	else
		throw new exception("Error al adquirir vehiculo: No hay datos del vehículo");
}

void cEmpresa::RetirardeCirculacion(cVehiculo* vehiculo)
{
	if (vehiculo != NULL)
	{
		vehiculo->setEstado(eEstado::Fuera_de_servicio);
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

	aux->setEstado(eEstado::Fuera_de_servicio);

}

void cEmpresa::Mantenimiento(cVehiculo* v)
{
	v->setEstado(eEstado::En_Mantenimiento);
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
	v->setEstado(eEstado::Libre);

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
	aux->setEstado(eEstado::Libre);

}

string cEmpresa::To_string()
{
	return "Nombre: " + nombre + "\n" +
		"Lista de vehiculos: " + vehiculos->To_String() + "\n" +
		"Lista de alquileres: " + alquileres->To_String() + "\n" +
		"Lista de clientes: " + clientes->To_String();
}

void cEmpresa::Imprimir()
{
	cout << To_string() << endl;
}

cListaT<cVehiculo>* cEmpresa::getListaVehiculos()
{
	return vehiculos;
}

cListaAlquiler* cEmpresa::getListaAlquileres()
{
	return alquileres;
}
