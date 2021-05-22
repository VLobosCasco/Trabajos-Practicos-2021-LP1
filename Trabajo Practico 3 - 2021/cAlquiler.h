#pragma once
#include <iostream>
#include "cFecha.h"
#include "cVehiculo.h"
#include "cCliente.h"
#include "cListaAdicional.h"
#include "cListaT.h"

class cEmpresa;
using namespace std;

class cAlquiler
{
private:
	const string IDAlquiler;
	cCliente* cliente;
	cVehiculo* vehiculo;
	cListaAdicional* adicionales;
	cFecha* fecha_inicio;
	cFecha* fecha_fin;
	float monto_total;

	static int Cont_alquiler;

public:

#pragma region Constructor y Destructor

	cAlquiler(cCliente* cliente, cVehiculo* vehiculo, cFecha* fecha_inicio, cFecha* fecha_final, float costo1 = 0, float costo2 = 0);
	~cAlquiler();

#pragma endregion

#pragma region To_string e Imprimir

	string To_string();
	void Imprimir();

#pragma endregion

#pragma region Getters y Setters

	//devuelve IDAlquiler (clave)
	string getclave()const; //lo necesito para la lista

	//devuelve IDAlquiler
	string getID() const ;

	//devuelve Vehiculo
	cVehiculo* getvehiculo() const;

	//devuelve la fecha de inicio
	cFecha* getfechainicio() const;

	//devuelve la fecha de fin
	cFecha* getfechafin() const;

#pragma endregion

#pragma region Métodos

	//Calcula el monto total y lo actualiza
	void ActualizarMontoTotal();

	//Agregar Adicional. Recibe el tipo de adicional y la cantidad, por default agrega 1
	void AgregarAdicional(eTipoAdicional tipoAdicional, int cant = 1);

	//Verifica que el vehículo se encuentre disponible entre las dos fechas (compara las fechas parámetro con las fechas del alquiler)
	bool VerificarDisponibilidad(cFecha* inicio, cFecha* fin);


#pragma endregion

#pragma region Sobrecarga
	bool operator ==(string otra_clave) {
		return this->getclave() == otra_clave;
	}
	bool operator !=(string otra_clave) {
		return this->getclave() != otra_clave;
	}
#pragma endregion
};

