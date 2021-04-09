#define _CRT_SECURE_NO_WARNINGS
#include "Funciones.h"


void VerificarFecha(tm& Fecha)
{
	if (Fecha.tm_mday > 31)
		Fecha.tm_mday = 31;
	if (Fecha.tm_mday < 1)
		Fecha.tm_mday = 1;

	if (Fecha.tm_mon > 12)
		Fecha.tm_mon = 12;
	if (Fecha.tm_mon < 1)
		Fecha.tm_mon = 1;

	time_t now = time(0);

	tm* ltm = localtime(&now);

	//1900 + ltm->tm_year deberia dar 2021
	if (Fecha.tm_year > 1900 + ltm->tm_year)
		Fecha.tm_year = 2021;
	if (Fecha.tm_year < 1900)
		Fecha.tm_year = 1900;
}

tm ConvertStringtm(string Fecha_str)
{

	//DD/MM/YYYY
	char Separador = '/';
	tm Fecha = tm();
	//Quedo con DD
	string Dia_str = Fecha_str.substr(0, Fecha_str.find(Separador));
	//Corto la parte derecha, me quedo con MM/YYYY
	string aux = Fecha_str.substr(Fecha_str.find(Separador) + 1 , Fecha_str.length() - 1);
	//Separo MM
	string Mes_str = aux.substr(0, aux.find(Separador));
	//Separo YYYY
	string Anio_str = aux.substr(aux.find(Separador) + 1, aux.length() - 1);

	//el _ Lo pongo para descartar el output del sscanf
	int _ = sscanf(Dia_str.c_str(), "%d", &(Fecha.tm_mday));
	_ = sscanf(Mes_str.c_str(), "%d", &(Fecha.tm_mon));
	_ = sscanf(Anio_str.c_str(), "%d", &(Fecha.tm_year));

	VerificarFecha(Fecha);

	//Forma compacta
	//sscanf(Horario.c_str(), "%d/%d/%d", &this->FechaNac, &this->Minutos);
	return Fecha;

}

string ConverttmString(tm Fecha) {
	string Fecha_str = "";
	//Acá utilizo operador ternario "?" Es un if de una linea
	//x = <condicion> ? <Verdadero> : <Falso>
	//Si condicion es verdadero, X vale lo que pongo en verdadero, caso contrario lo de falso
	Fecha_str += Fecha.tm_mday > 10 ? to_string(Fecha.tm_mday) : "0" + to_string(Fecha.tm_mday);
	Fecha_str += "/";
	Fecha_str += Fecha.tm_mon > 10 ? to_string(Fecha.tm_mon) : "0" + to_string(Fecha.tm_mon);
	Fecha_str += "/";
	Fecha_str += to_string(Fecha.tm_year);
	return Fecha_str;
}
