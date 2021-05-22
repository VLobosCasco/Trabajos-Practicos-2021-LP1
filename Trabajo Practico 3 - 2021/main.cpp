#pragma once
#include "Definiciones.h"
#include "cAlquiler.h"
#include "cEmpresa.h"
#include "funciones.h"
#include "cListaT.h"
#include"cVehiculo.h"
#include "cMoto.h"
#include "cAuto.h"
#include "cTrafic.h"
#include "cCamioneta.h"

using namespace std;


void main(){
	/*cFecha* inicio = new cFecha(5, 5, 2021);
	cFecha* fin = new cFecha(10, 5, 2021);
	int aux = cFecha::DiasEntreFechas(inicio, fin);
	cout << aux;*/

	//Creo clientes y Lista clientes
	cCliente* cliente1 = new cCliente("42024680", "Florencia Radzik", 21, 06 ,1999, "1235489");
	cCliente* cliente2 = new cCliente("44555680", "Camila Gonzalez", 2, 12, 1999, "8512335489");
	cCliente* cliente3 = new cCliente("41475680", "Damian Deza", 2, 5, 1997, "8535489");
	cCliente* cliente4 = new cCliente("44697680", "Lucas Rack", 7, 11, 1997, "80005489");

	cListaT<cCliente>* ListaClientes = new cListaT<cCliente>();

	cout << "Lista de clientes"<<endl;
	ListaClientes->AgregarItem(cliente1);
	ListaClientes->AgregarItem(cliente2);
	ListaClientes->AgregarItem(cliente3);
	ListaClientes->AgregarItem(cliente4);
	ListaClientes->Listar();
	cout << *ListaClientes;

	//Creo fechas
	cFecha* Nov6 = new cFecha(6, 11, 2021);
	cFecha* Nov20 = new cFecha(20, 11, 2021);
	cFecha* May5 = new cFecha(5, 5, 2021);
	cFecha* Mar3 = new cFecha(3, 3, 2021);
	cFecha* Jun17 = new cFecha(17, 6, 2021);
	cFecha* Ene5 = new cFecha(5, 1, 2021);
	cFecha* Feb20 = new cFecha(20, 2, 2021);

	//Creo Vehiculos
	cVehiculo* moto1 = new cMoto("ABC123", "123123123", "12", eColores::VIOLETA, Ene5);
	cVehiculo* moto2 = new cMoto("ABC124", "145123", "18", eColores::GRIS, Feb20);

	cVehiculo* auto1 = new cAuto("321ABD", "456546", "222", eColores::BLANCO, 4, Mar3);
	cVehiculo* auto2 = new cAuto("3245BD", "4567896", "22", eColores::NEGRO, 5, Ene5);

	cVehiculo* camioneta1 = new cCamioneta("3ABD", "44756546", "2225", eColores::AZUL, 5, Mar3);
	cVehiculo* camioneta2 = new cCamioneta("3A45BD", "40006546", "205", eColores::NEGRO, 5, Ene5);

	cVehiculo* trafic1= new cTrafic("3ABD", "44756546", "2225", eColores::AZUL, 5, Mar3)
};
