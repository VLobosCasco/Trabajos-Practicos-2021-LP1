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
#include <string>

using namespace std;


void main(){
	/*cFecha* inicio = new cFecha(5, 5, 2021);
	cFecha* fin = new cFecha(10, 5, 2021);
	int aux = cFecha::DiasEntreFechas(inicio, fin);
	cout << aux;*/

	//Creo fechas
	cFecha* Nov6 = new cFecha(6, 11, 2021);
	cFecha* Nov20 = new cFecha(20, 11, 2021);
	cFecha* May5 = new cFecha(5, 5, 2021);
	cFecha* May18 = new cFecha(18, 5, 2021);
	cFecha* Mar3 = new cFecha(3, 3, 2021);
	cFecha* Jun17 = new cFecha(17, 6, 2021);
	cFecha* Ene5 = new cFecha(5, 1, 2021);
	cFecha* Feb20 = new cFecha(20, 2, 2021);
	cFecha* Mar7 = new cFecha(7, 3, 2021);

	//Creo clientes y Lista clientes
	cCliente** clientes = new cCliente * [N_CLIENTES];

	InicializarClientes(clientes);

	cListaT<cCliente>* ListaClientes = new cListaT<cCliente>(3,true); //pongo un TAM < que el que necesito para probar la excepción
	
	AgregaraLista(ListaClientes, clientes, N_CLIENTES);
	
	delete[] clientes;
	
	cout << "Lista de clientes" << endl;
	ListaClientes->Listar(); //este lo dejé hasta que la sobrecarga esté terminada, después hay que borrarlo Florr
	cout << *ListaClientes;

	//Creo Vehiculos
	cVehiculo** vehiculos = new cVehiculo * [N_VEHICULOS];

	vehiculos[0] = new cMoto("ABC123", "123123123", "12", eColores::VIOLETA, Ene5);
	vehiculos[1] = new cMoto("ABC124", "145123", "18", eColores::GRIS, Feb20);

	vehiculos[2] = new cAuto("321ABD", "456546", "222", eColores::BLANCO, 4, Mar3);
	vehiculos[3] = new cAuto("3245BD", "4567896", "22", eColores::NEGRO, 5, Ene5);

	vehiculos[4] = new cCamioneta("3ABD", "44756546", "2225", eColores::AZUL, 5, Mar3);
	vehiculos[5] = new cCamioneta("3A45BD", "40006546", "205", eColores::NEGRO, 5, Ene5);

	vehiculos[6] = new cTrafic("3AB36D", "44756546", "2725", eColores::AZUL, 5, Mar3);
	vehiculos[7] = new cTrafic("3AB55D", "98756546", "855", eColores::ROJO, 5, Feb20);

	//Creo lista vehiculos y los agrego

	cListaT<cVehiculo>* ListaVehiculos = new cListaT<cVehiculo>(N_VEHICULOS, true);

	AgregaraLista(ListaVehiculos, vehiculos, N_VEHICULOS);

	delete[] vehiculos;

	ListaVehiculos->Listar();//Imprimir! Florrr

	//Creo Alquileres y lista alquileres

	cAlquiler** alquileres = new cAlquiler * [N_ALQUILERES];

	alquileres[0] = new cAlquiler((*ListaClientes)[0], (*ListaVehiculos)[0], Mar3, Mar7);
	alquileres[1] = new cAlquiler((*ListaClientes)[1], (*ListaVehiculos)[5], May5, Jun17);
	alquileres[2] = new cAlquiler((*ListaClientes)[2], (*ListaVehiculos)[2], Nov6, Nov20);
	alquileres[3] = new cAlquiler((*ListaClientes)[3], (*ListaVehiculos)[1], May18, Jun17);
	alquileres[4] = new cAlquiler((*ListaClientes)[3], (*ListaVehiculos)[0], Feb20, Mar7); // este se superpone


	cListaAlquiler* ListaAlquileres = new cListaAlquiler(N_ALQUILERES, true);
	
	AgregaraLista(ListaAlquileres, alquileres, N_ALQUILERES);

	delete[] alquileres;

	ListaAlquileres->Listar(); //Florrr

	//creo Empresa
	cEmpresa* empresa = new cEmpresa("Di Marco y Asociados", ListaVehiculos, ListaClientes, ListaAlquileres);

	empresa->Imprimir();//FLORRR

	delete empresa;
	delete ListaVehiculos;
	delete ListaAlquileres;
	delete ListaClientes;
	

};
