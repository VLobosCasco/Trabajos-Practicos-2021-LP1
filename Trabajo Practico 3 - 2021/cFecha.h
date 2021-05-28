#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <ctime>
#include <string>


using namespace std;
class cFecha
{
private:
#pragma region Atributos

	tm fecha;

#pragma endregion


#pragma region Constructor y Destructor
public:
	//Constructor por default, inicia en la fecha de hoy
	cFecha();

	//Constructor inicia en dia, mes, a�o
	cFecha(int d, int m, int a);

#pragma endregion

#pragma region Metodos


	//Calcula el numero de d�as entre dos fechas
	static int DiasEntreFechas(cFecha* inicio, cFecha* fin);

	//Devuelve si las fechas se superponen
	static bool IsOverlapped(cFecha* inicio1, cFecha* fin1, cFecha* inicio2, cFecha* fin2);

	//Cambia la fecha a la fecha actual
	void SetHoy();

	//Verifica que la fecha est� completa
	bool FechaCompleta();

	//Devuelve la fecha actual en forma de string
	string To_string();

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

