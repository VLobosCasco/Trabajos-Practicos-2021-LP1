#pragma once
#include"Definiciones.h"
#include "cAlquiler.h"
#include "cEmpresa.h"
#include "funciones.h"

using namespace std;

void main(){
	cFecha* inicio = new cFecha(5, 5, 2021);
	cFecha* fin = new cFecha(10, 5, 2021);
	int aux = cFecha::DiasEntreFechas(inicio, fin);
	cout << aux;
};