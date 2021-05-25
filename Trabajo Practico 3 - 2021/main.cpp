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

	cListaT<cCliente>* ListaClientes = new cListaT<cCliente>(3,true); //pongo un TAM < que el que necesito, para probar la excepción
	
	AgregaraLista(ListaClientes, clientes, N_CLIENTES);
	
	delete clientes[4]; //este no se agregó a la lista por repetido así que lo borre porque no se va a borrar con la lista
	delete[] clientes;
	
	cout << "---------- LISTA DE CLIENTES ----------" << endl;
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

	vehiculos[6] = new cTrafic("3AB36D", "44756546", "2725", eColores::AZUL, 8, Mar3);
	vehiculos[7] = new cTrafic("3AB55D", "98756546", "855", eColores::ROJO, 8, Feb20);

	//Creo lista vehiculos y los agrego

	cListaT<cVehiculo>* ListaVehiculos = new cListaT<cVehiculo>(N_VEHICULOS, true);

	AgregaraLista(ListaVehiculos, vehiculos, N_VEHICULOS);

	delete[] vehiculos;

	cout << "---------- LISTA DE VEHICULOS ----------" << endl;
	ListaVehiculos->Listar();//Imprimir! Florrr

	//Creo Alquileres y lista alquileres

	cAlquiler** alquileres = new cAlquiler * [N_ALQUILERES];

	alquileres[0] = new cAlquiler((*ListaClientes)[0], (*ListaVehiculos)[0], Mar3, Mar7);
	alquileres[1] = new cAlquiler((*ListaClientes)[1], (*ListaVehiculos)[7], May5, Jun17);
	alquileres[2] = new cAlquiler((*ListaClientes)[2], (*ListaVehiculos)[2], Nov6, Nov20);
	alquileres[3] = new cAlquiler((*ListaClientes)[3], (*ListaVehiculos)[1], May18, Jun17);
	alquileres[4] = new cAlquiler((*ListaClientes)[3], (*ListaVehiculos)[0], Feb20, Mar7); // este se superponen las fechass


	cListaAlquiler* ListaAlquileres = new cListaAlquiler(N_ALQUILERES, true);
	
	AgregaraLista(ListaAlquileres, alquileres, N_ALQUILERES);

	delete alquileres[4]; // este no se va a agregar a la lista entonces lo borro ahora para no olvidarmelo
	delete[] alquileres;

	cout << "---------- LISTA DE ALQUILERES ----------" << endl;
	ListaAlquileres->Listar(); //Florrr

	//creo Empresa
	cEmpresa* empresa = new cEmpresa("Di Marco y Asociados", ListaVehiculos, ListaClientes, ListaAlquileres);

	cout << "---------- EMPRESA ----------" << endl;
	empresa->Imprimir();//FLORRR

	//La empresa agrega un nuevo alquiler

	try {

		empresa->AgregarAlquiler(new cAlquiler((*ListaClientes)[0], (*ListaVehiculos)[4], Feb20, Mar7));
	}
	catch (exception* ex) {
		string error = ex->what();
		delete ex;
		cout << "Error al agregar nuevo alquiler: " + error << endl;

	}

	//La empresa va a adquirir un vehículo, poner en mantenimiento otro, y dar de baja otro
	cVehiculo* vehiculo_nuevo = new cAuto("987654", "789456123", "951", eColores::VIOLETA,5, Feb20);
	try {
		empresa->AdquirirVehiculo(vehiculo_nuevo);
	}
	catch (exception* ex) {

		string error = ex->what(); //esto debería tirar error por tamaño de la lista
		delete ex;

		if (error == "Error al agregar: No hay tamaño suficiente para agregar el item")
		{
			empresa->getListaVehiculos()->Redimensionalizar();
			empresa->AdquirirVehiculo(vehiculo_nuevo);
		}
		else
			cout << error << endl;
	}
	cout << "---------- VEHICULO EN MANTENIMIENTO ----------" << endl;
	empresa->Mantenimiento("ABC123");
	empresa->RetirardeCirculacion((*ListaVehiculos)[3]);

	//Ahora intento agregar un alquiler para el auto en mantenimiento y uno para el auto fuera de circulación
	try {
		cAlquiler* alquiler_mantenimiento = new cAlquiler((*ListaClientes)[2], ListaVehiculos->BuscarItem("ABC123"), Nov6, Nov20);
		*(empresa->getListaAlquileres()) + alquiler_mantenimiento;
	}
	catch (exception* ex) {
		string error = ex->what();
		delete ex;
		cout << error << endl;
	}

	try {
		cAlquiler* alquiler_vencido = new cAlquiler((*ListaClientes)[2], (*ListaVehiculos)[3], Nov6, Nov20);
		*(empresa->getListaAlquileres()) + alquiler_vencido;
	}
	catch (exception* ex) {
		string error = ex->what();
		delete ex;
		cout << error << endl;
	}

	//IMPRIMO AL VEHICULO EN MANTENIMIENTO
	
	ListaVehiculos->BuscarItem("ABC123")->Imprimir();

	//Saco al vehículo de mantenimiento
	empresa->TerminarMantenimiento("ABC123");

	cout << "---------- VEHICULO FUERA DE MANTENIMIENTO ----------" << endl;
	ListaVehiculos->BuscarItem("ABC123")->Imprimir();
	
	//Agrego adicionales
	try {

		(*ListaAlquileres)[0]->AgregarAdicional(eTipoAdicional::Casco, 2);
		
	}
	catch(exception* ex) {

		string err = ex->what();
		delete ex;
		cout << "Error al agregar elemento: " + err << endl;
	}

	//Ahora intento agregar otro casco y tiene que activarse la excepción
	try {

		(*ListaAlquileres)[0]->AgregarAdicional(eTipoAdicional::Casco, 2);
	}
	catch (exception* ex) {

		string err = ex->what();
		delete ex;
		cout <<  err << endl;
	}

	//Ahora intento agregarle un casco a un auto (no le agrega nada)
	try {

		(*ListaAlquileres)[2]->AgregarAdicional(eTipoAdicional::Casco, 2);

	}
	catch (exception* ex) {

		string err = ex->what();
		delete ex;
		cout << err << endl;
	}

	cout << "---------- ALQUILERES CON ADICIONALES ----------" << endl;

	//este tiene que tener 2 cascos
	(*ListaAlquileres)[0]->Imprimir();//FLORRR

	//este no tiene que tener adicionales
	(*ListaAlquileres)[2]->Imprimir();///FLORR

	//este no tiene adicionales todavía
	(*ListaAlquileres)[1]->Imprimir();///FLORR

	//Agrego 2 asientos rebatibles entonces tiene que aumentar en 2 la capacidad de pasajeros
	try {

		(*ListaAlquileres)[1]->AgregarAdicional(eTipoAdicional::Asientos_rebatibles, 2);

	}
	catch (exception* ex) {

		string err = ex->what();
		delete ex;
		cout << err << endl;
	}
	
	cout << "---------- ALQUILER CON ASIENTOS REBATIBLES ADICIONALES ----------" << endl;
	(*ListaAlquileres)[1]->Imprimir();///FLORR


	//Listo por cada vehículo y calculo ganancias

	cout << "---------- LISTO POR MOTO ----------" << endl;
	float ganancia_moto=ListaAlquileres->ListarGananciaAlquiler<cMoto>();
	cout << "Ganancia en alquileres de moto: " << ganancia_moto << endl;

	cout << "---------- LISTO POR AUTO ----------" << endl;
	float ganancia_auto = ListaAlquileres->ListarGananciaAlquiler<cAuto>();
	cout << "Ganancia en alquileres de auto: " << ganancia_auto << endl;

	cout << "---------- LISTO POR CAMIONETA ----------" << endl;
	float ganancia_camioneta = ListaAlquileres->ListarGananciaAlquiler<cCamioneta>();
	cout << "Ganancia en alquileres de camioneta: " << ganancia_camioneta << endl;

	cout << "---------- LISTO POR TRAFIC ----------" << endl;
	float ganancia_trafic = ListaAlquileres->ListarGananciaAlquiler<cTrafic>();
	cout << "Ganancia en alquileres de trafics: " << ganancia_trafic << endl;

	cout << "---------- GANANCIA TOTAL ----------" << endl;
	float ganancia_total = ganancia_moto + ganancia_auto + ganancia_camioneta + ganancia_trafic;
	cout << "Ganancia total alquileres: " << ganancia_total << endl;



	//Libero TODA la memoria
	delete empresa;
	delete ListaVehiculos;
	delete ListaAlquileres;
	delete ListaClientes;
	delete Nov6;
	delete Nov20;
	delete May5 ;
	delete May18;
	delete Mar3 ;
	delete Jun17;
	delete Ene5 ;
	delete Feb20 ;
	delete Mar7 ;


};
