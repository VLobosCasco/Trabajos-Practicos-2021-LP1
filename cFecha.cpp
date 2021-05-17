#include "cFecha.h"

cFecha::cFecha() {
	fecha.tm_hour = 0;
	fecha.tm_min = 0;
	fecha.tm_sec = 0;
	fecha.tm_mday = 0;
	fecha.tm_mon = 0;
	fecha.tm_year = 0;
}
cFecha::cFecha(int d, int m, int a)
{
	fecha.tm_hour = 0;
	fecha.tm_min = 0;
	fecha.tm_sec = 0;
	fecha.tm_mday = d;
	fecha.tm_mon = m;
	fecha.tm_year = a-1900;
}

int cFecha::DiasEntreFechas(cFecha* inicio, cFecha* fin)
{
	int dif = 0;
	time_t aux_inicio = mktime(&(inicio->fecha));
	time_t aux_fin = mktime(&(fin->fecha));
	//verifico que las fechas que recibo no sean null ni estén incompletas
	if ((inicio != NULL && fin != NULL) && FechaCompleta(inicio) && FechaCompleta(fin)) {
		if (!VerificarFecha(inicio, fin)) //verifico que fecha fin > fecha inicio
			throw new exception("Las fechas no son válidas");
		else {
			dif = difftime(aux_fin, aux_inicio)/(86400); //calculo la diferencia de tiempo y la devuelvo
			return dif;
		}
	}
	else throw new exception("Fechas incompletas");
}

bool cFecha::VerificarFecha(cFecha* inicio, cFecha* fin)
{
	time_t aux_inicio = mktime(&(inicio->fecha));
	time_t aux_fin = mktime(&(fin->fecha));
	if (difftime(aux_fin, aux_inicio) < 0)//si la diferencia es negativa entonces la fecha de inicio es posterior a la fecha de fin
		return false;
	else return true;
}

void cFecha::SetHoy()
{
	time_t now = time(0);
	tm* aux = localtime(&now); //obtengo fecha actual
	fecha.tm_mday = aux->tm_mday;
	fecha.tm_mon = aux->tm_mon;
	fecha.tm_year = aux->tm_mon;
}

bool cFecha::FechaCompleta(cFecha* fecha)
{
	if (fecha->fecha.tm_year != 0 && fecha->fecha.tm_mon != 0 && fecha->fecha.tm_mday != 0) //verifico que los parámetros de día no esténe n sus valores nulos
		return true;
	return false;
}

string cFecha::to_string()
{
	string aux= std::to_string(fecha.tm_mday)
}
