#include "cAuto.h"
float cAuto::precio_base = 1000;
float cAuto::precio_diario = 500;

cAuto::cAuto(string patente_c, string chasis_c, string poliza_c, eColores color_c, int cant_pasaj_c, cFecha* ult_mantenimiento) : cVehiculo(patente_c, chasis_c, poliza_c, color_c, cant_pasaj_c, ult_mantenimiento)
{
}
float cAuto::CalcularTarifa(int dias) {
	return precio_base + dias * precio_diario;
}

float cAuto::CalcularTarifa(cFecha& fecha_inicio, cFecha& fecha_fin)
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

void cAuto::PasosMantenimiento()
{
	cout << "Pasos mantenimiento auto" << endl;
	ActualizarMantenimiento();
}

void cAuto::Imprimir()
{
	cout << To_string() << endl;
}

string cAuto::To_string() {

	return
		"Chasis: " + chasis + "\n" +
		"Poliza: " + poliza + "\n" +
		"Patente: " + patente + "\n" +
		"Ultimo Mantenimiento: " + Ultimo_Mantenimiento->To_string() + "\n" +
		"Color: " + ConvertColorString(color) + "\n" +
		"Cantidad de Pasajeros: " + to_string(cant_pasajeros) + "\n"
		"Precio Base: " + to_string(precio_base) + "\n"
		"Precio Diario: " + to_string(precio_diario);
}
