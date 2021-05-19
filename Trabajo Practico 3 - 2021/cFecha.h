#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <ctime>
#include <string>


using namespace std;
class cFecha
{
public:
#pragma region Atributos
	tm fecha;
#pragma endregion

#pragma region Constructor y Destructor
//Constructor por default, inicia en la fecha de hoy
	cFecha();
//Constructor inicia en dia, mes, año
	cFecha(int d, int m, int a);
#pragma endregion
#pragma region Metodos
public:
//Calcula el numero de días entre dos fechas
	static int DiasEntreFechas(cFecha* inicio, cFecha* fin);
//Cambia la fecha a la fecha actual
	void SetHoy();
//Verifica que la fecha esté completa
	bool FechaCompleta();
//Devuelve la fecha actual en forma de string
	string to_string();
// Imprime fecha
	void ImprimirFecha();
#pragma endregion
#pragma region Sobrecarga de Operadores
	bool operator<(cFecha& otra) {
		time_t aux_this = mktime(&(this->fecha));
		time_t aux_otra = mktime(&(otra.fecha));
		return aux_this < aux_otra;
	}

	bool operator>(cFecha& otra) {
		time_t aux_this = mktime(&(this->fecha));
		time_t aux_otra = mktime(&(otra.fecha));
		return aux_this > aux_otra;
	}

	bool operator==(cFecha& otra) {
		time_t aux_this = mktime(&(this->fecha));
		time_t aux_otra = mktime(&(otra.fecha));
		return aux_this == aux_otra;
	}

	bool operator!=(cFecha& otra) {
		return !(*this == otra);
	}
#pragma endregion
};

