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
	catch(runtime_error& ex) {
		string error = ex.what();
		ex = runtime_error(("Error en las fechas de alquiler: " + error).c_str());
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

