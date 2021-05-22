#include "cMoto.h"
#include "Definiciones.h"

float cMoto::precio_base = 750;
float cMoto::precio_diario = 200;

cMoto::cMoto(string patente_c, string chasis_c, string poliza_c, eColores color_c, cFecha* ult_mantenimiento) : cVehiculo(patente_c, chasis_c, poliza_c, color_c, 2, ult_mantenimiento)
{

}

float cMoto::CalcularTarifa(int dias) {
	return precio_base + dias * precio_diario;
}

float cMoto::CalcularTarifa(cFecha& fecha_inicio, cFecha& fecha_fin)
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

void cMoto::PasosMantenimiento()
{
	cout << "Pasos mantenimiento moto" << endl;
	ActualizarMantenimiento();
}

void cMoto::Imprimir()
{
	cout << To_string() << endl;
}

string cMoto::To_string() {

	return string();
}

