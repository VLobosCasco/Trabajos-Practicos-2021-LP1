#pragma once
#include <iostream>
#include "cFecha.h"
#include "cMoto.h"
#include "cAuto.h"
#include "cCamioneta.h"
#include "cTrafic.h"
#include "cCliente.h"
#include "cListaAdicional.h"
#include "cListaT.h"

class cEmpresa;
using namespace std;
class cListaAlquiler;
class cAlquiler
{
public:
	const string IDAlquiler;
	cCliente* cliente;
	cVehiculo* vehiculo;
	cListaAdicional* adicionales;
	cFecha* fecha_inicio;
	cFecha* fecha_fin;
	float monto_total;
private:
	static int Cont_alquiler;
public:
#pragma region Constructor y Destructor
	cAlquiler(cCliente * c, cVehiculo * v, cFecha * fi, cFecha* ff, float costo1=0, float costo2=0);
	~cAlquiler();
#pragma endregion
#pragma region To_string e Imprimir
	string To_string();
	void Imprimir();
#pragma endregion
#pragma region Getters y Setters
//devuelve IDAlquiler (clave)
	string getclave(); //lo necesito para la lista
//devuelve IDAlquiler
	string getID();
#pragma endregion
#pragma region Métodos
//Calcula el monto total y lo actualiza
	void ActualizarMontoTotal();
//Agregar Adicional. Recibe el tipo de adicional y la cantidad, por default agrega 1
	void AgregarAdicional(eTipoAdicional e, int cant =1);
//Verifica que el vehículo se encuentre disponible entre las dos fechas
	bool VerificarDisponibilidad(cFecha* inicio, cFecha* fin);
#pragma endregion
};

