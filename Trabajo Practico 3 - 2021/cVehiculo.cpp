#include "cVehiculo.h"

cVehiculo::cVehiculo(string patente_c, string chasis_c, string poliza_c, eColores color_c, int cant_pasajeros_c):patente(patente_c), chasis(chasis_c), poliza(poliza_c)
{
	color = color_c;
	cant_pasajeros = cant_pasajeros_c;
	Ultimo_Mantenimiento = new cFecha();
}

cVehiculo::cVehiculo(string patente_c, string chasis_c, string poliza_c, eColores color_c, int cant_pasajeros_c, cFecha* ult_mantenimiento):patente(patente_c), chasis(chasis_c), poliza(poliza_c)
{
	color = color_c;
	cant_pasajeros = cant_pasajeros_c;
	Ultimo_Mantenimiento = ult_mantenimiento;
}

cVehiculo::~cVehiculo()
{
	if (Ultimo_Mantenimiento != NULL)
		delete Ultimo_Mantenimiento;
}

void cVehiculo::ActualizarMantenimiento() {
	Ultimo_Mantenimiento->SetHoy();
}

string cVehiculo::to_string()
{
	return string();
}

void cVehiculo::Imprimir()
{
	cout << to_string();
}

string cVehiculo::getclave()
{
	return clave;
}

string cVehiculo::getpatente()
{
	return clave;
}
