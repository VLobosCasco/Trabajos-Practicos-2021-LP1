#pragma once
#include <iostream>
#include <ctime>

using namespace std;
class cFecha
{
public:
#pragma region Atributos
	tm fecha;
#pragma endregion

#pragma region Constructor y Destructor
	cFecha();
	cFecha(int d, int m, int a);
	~cFecha() {};
#pragma endregion
#pragma region Metodos
//Calcula el numero de días entre dos fechas
	int DiasEntreFechas(cFecha* inicio, cFecha* fin);
// Verifica que la fecha de incio sea anterior a la fecha de fin
	bool VerificarFecha(cFecha* inicio, cFecha* fin);
//Cambia la fecha a la fecha actual
	void SetHoy();
//Verifica que la fecha esté completa
	bool FechaCompleta(cFecha* fecha);
//Devuelve la fecha actual en forma de string
	string to_string();
// Imprime fecha
	void ImprimirFecha();
#pragma endregion
};

