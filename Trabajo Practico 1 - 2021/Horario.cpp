#define _CRT_SECURE_NO_WARNINGS
#include "Horario.h"


Horario::Horario(short Hora, short Minutos)
{
	this->Hora = Hora;
	this->Minutos = Minutos;
	VerificarHorario();
}

Horario::Horario(string Horario, char Separador)
{
	string Hora_str = Horario.substr(0, Horario.find(Separador));
	string Minutos_str = Horario.substr(Horario.find(Separador) + 1, Horario.length()-1);

	//Variable Dummy para descartar el valor del sscanf
	int _  = sscanf(Hora_str.c_str(), "%hi", &this->Hora);
	_ = sscanf(Minutos_str.c_str(), "%hi", &this->Minutos);
	
	VerificarHorario();
	//Forma compacta
	//sscanf(Horario.c_str(), "%hi:%hi", &this->Hora, &this->Minutos);
}

string Horario::ToString(char Separador)
{
	string Hora_str = "";
	if (Hora < 10) {
		Hora_str += "0" + to_string(Hora);
	}
	else {
		Hora_str += to_string(Hora);
	}
	Hora_str += ":";

	if (Minutos < 10) {
		Hora_str += "0" + to_string(Minutos);
	}
	else {
		Hora_str += to_string(Minutos);
	}
	return Hora_str;
}

void Horario::VerificarHorario()
{
	if (Hora >= 24)
		Hora = 23;
	if (Minutos >= 60)
		Minutos = 59;
}
