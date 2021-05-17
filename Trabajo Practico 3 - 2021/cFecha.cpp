#include "cFecha.h"

cFecha::cFecha() { 
	fecha.tm_hour = 0;
	fecha.tm_min = 0;
	fecha.tm_sec = 0;
	fecha.tm_mday = 0;
	fecha.tm_mon = 0;
	fecha.tm_year = 0;
	SetHoy();
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
	if ((inicio != NULL && fin != NULL) && inicio->FechaCompleta() && fin->FechaCompleta()) {
		//verifico que fecha fin > fecha inicio con operador sobrecargado
		if (inicio<fin) 
			throw new exception("Las fechas no son válidas");
		else {
			dif = difftime(aux_fin, aux_inicio)/(86400); //calculo la diferencia de tiempo y la devuelvo
			return dif;
		}
	}
	else throw new exception("Fechas incompletas");
}


void cFecha::SetHoy()
{
	time_t now = time(0);
	tm* aux = localtime(&now); //obtengo fecha actual
	fecha.tm_mday = aux->tm_mday;
	fecha.tm_mon = aux->tm_mon;
	fecha.tm_year = aux->tm_mon;
}

bool cFecha::FechaCompleta()
{
	if (fecha.tm_year != 0 && fecha.tm_mon != 0 && fecha.tm_mday != 0) //verifico que los parámetros de día no estén en sus valores nulos
		return true;
	return false;
}

string cFecha::to_string()
{
	
}

void cFecha::ImprimirFecha() {
	cout << to_string();
}