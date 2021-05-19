#include "cTrafic.h"

float cTrafic::precio_base = 2250;
float cTrafic::precio_diario = 1200;

cTrafic::cTrafic(string patente_c, string chasis_c, string poliza_c, eColores color_c, int cant_pasaj_c) :cVehiculo(patente_c, chasis_c, poliza_c, color_c, cant_pasaj_c)
{
}
cTrafic::cTrafic(string patente_c, string chasis_c, string poliza_c, eColores color_c, int cant_pasaj_c, cFecha* ult_mantenimiento) : cVehiculo(patente_c, chasis_c, poliza_c, color_c, cant_pasaj_c, ult_mantenimiento)
{
}
float cTrafic::CalcularTarifa(int dias) {
	return precio_base + dias * precio_diario;
}

float cTrafic::CalcularTarifa(cFecha& fecha_inicio, cFecha& fecha_fin)
{
	int dias = 0;
	try {
		dias = cFecha::DiasEntreFechas(&fecha_inicio, &fecha_fin);
	}
	catch (exception* ex) {
		string error = ex->what();
		delete ex;
		ex = new exception(("Error en las fechas de alquiler: " + error).c_str());
		throw ex;

	}
	return CalcularTarifa(dias);
}

void cTrafic::PasosMantenimiento()
{
	cout << " Pasos mantenimiento camioneta";
	ActualizarMantenimiento();
}

void cTrafic::Imprimir()
{
	cout << to_string() << endl;
}

string cTrafic::to_string() {

	return string();
}

