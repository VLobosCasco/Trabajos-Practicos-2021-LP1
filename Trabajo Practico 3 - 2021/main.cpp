#pragma once
#include "Definiciones.h"
#include "cAlquiler.h"
#include "cEmpresa.h"
#include "funciones.h"

using namespace std;


void main(){
	/*cFecha* inicio = new cFecha(5, 5, 2021);
	cFecha* fin = new cFecha(10, 5, 2021);
	int aux = cFecha::DiasEntreFechas(inicio, fin);
	cout << aux;*/
	cCliente* yo = new cCliente("42024680", "FlorRadzik", 21, 06 ,1999, "1235489");
	cListaT<cCliente>* Probando = new cListaT<cCliente>();
	Probando->AgregarItem(yo);
	Probando->Listar();
	cout << Probando;

};
