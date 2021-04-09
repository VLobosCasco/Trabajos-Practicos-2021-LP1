#pragma once
#include <iostream>
#include <string>

using namespace std;

class Horario
{
private:
	short Hora;
	short Minutos;
public:
	//Pragma region me permite estructurar mejor el codigo, totalmente opcional!
#pragma region Constructores y Destructores
	Horario(short Hora, short Minutos);

	//En este caso me permite poner un string del estilo "20:30"
	//Separador es el char que separa los 2 numeros, puedo ponerlo como 20,30 tambien
	Horario(string Horario, char Separador);
#pragma endregion

#pragma region Metodos
	string ToString(char Separador = ':');

private:
	void VerificarHorario();
#pragma endregion
};

