#include "cVehiculo.h"

cVehiculo::cVehiculo(string patente_c, string chasis_c, string poliza_c, eColores color_c, int cant_pasajeros_c, cFecha* ult_mantenimiento):patente(patente_c), chasis(chasis_c), poliza(poliza_c)
{
	color = color_c;
	cant_pasajeros = cant_pasajeros_c;
	Ultimo_Mantenimiento = new cFecha(*ult_mantenimiento);
	estado = eEstado::Libre;
}

cVehiculo::~cVehiculo()
{
	if (Ultimo_Mantenimiento != NULL)
		delete Ultimo_Mantenimiento;
}

void cVehiculo::ActualizarMantenimiento() {
	Ultimo_Mantenimiento->SetHoy();
}

void cVehiculo::ModificarAsientos(int cantidad)
{
	cant_pasajeros =+ cantidad;
}

string cVehiculo::To_string()
{
	return
		"Chasis: " + chasis + "\n" +
		"Poliza: " + poliza + "\n" +
		"Patente: " + patente + "\n" +
		"Ultimo Mantenimiento: " + Ultimo_Mantenimiento->To_string() + "\n" +
		"Color: " + ConvertColorString(color) + "\n" +
		"Cantidad de Pasajeros: " + to_string(cant_pasajeros)+"\n\n";
}

void cVehiculo::Imprimir()
{
	cout << To_string();
}
/*
string cVehiculo::getclave()
{
	return patente;
}

string cVehiculo::getpatente()
{
	return patente;
}*/
