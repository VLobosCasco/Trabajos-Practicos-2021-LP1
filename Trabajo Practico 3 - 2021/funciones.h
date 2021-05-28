#pragma once
#include"Definiciones.h"
#include "cAlquiler.h"
#include "cEmpresa.h"

template <class L, class T>
//Agrega a la lista pasada por parámetros los items pasados por parámetro. Tiene manejo de excepciones
void AgregaraLista(L* lista, T** items, int cantidaditems) {
	for (unsigned int i = 0; i < cantidaditems; i++) {
		try {

			*lista+(items[i]);
		}
		catch(exception& ex) {
			string err = ex.what();
			
			if (err == "No hay tamaño suficiente para agregar el item") //Me quedé sin lugar
			{
				lista->Redimensionalizar(); //aumento el tamaño
				*lista+(items[i]); //agrego
			}
			else
			{
				cout << "Error al añadir: " + items[i]->To_string() + "\n" + err + "\n" << endl;

			}
		}
	}
}

//Inicializa 5 clientes con uno repetido para probar excepciones
void InicializarClientes(cCliente** clientes) {

	clientes[0] = new cCliente("42024680", "Florencia Radzik", 21, 06, 1999, "1235489");
	clientes[1] = new cCliente("44555680", "Camila Gonzalez", 2, 12, 1999, "8512335489");
	clientes[2] = new cCliente("41475680", "Damian Deza", 2, 5, 1997, "8535489");
	clientes[3] = new cCliente("44697680", "Lucas Rack", 7, 11, 1997, "80005489");
	clientes[4] = new cCliente("44697680", "Lucas Rack", 7, 11, 1997, "80005489"); //repito para probar la excepción

}


