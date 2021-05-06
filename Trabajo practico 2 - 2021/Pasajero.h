#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <stdio.h> //sprintf
#include <algorithm> //Me traigo la funcion clamp (ATENCION, COMPILO CON C++17!)
#include "Enums.h"

using namespace std;
class Pasajero
{
	string DNI;
	string Nombre;	
	float Peso;

	//Formato HH:MM
	string HorarioSubida;

	//Formato HH:MM
	string HorarioBajada;

	//Las estaciones pueden ser un gran enum o 
	//con template podrian hacer pasajeros dependiente de la linea con sus propias estaciones
	eEstacion EstacionOrigen;
	eEstacion EstacionDestino;
public:
	Pasajero(string DNI, string Nombre, float Peso, int HoraSubida, int MinutoSubida, eEstacion Origen, eEstacion Destino);
	void ArribarEstacion(int HoraBajada, int MinutoBajada);
	string to_string();
	void Imprimir();
	string getclave();
};

