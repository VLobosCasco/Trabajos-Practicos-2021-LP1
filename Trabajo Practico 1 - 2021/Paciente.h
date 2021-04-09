#pragma once
#include <iostream>
#include <string>
#include "Enums.h"

using namespace std;

class Paciente
{
private:
	string Nombre;
	string Apellido;
	tm FechaNacimiento;
	tm UltimaVisita;
	string Telefono;
	eEspecialidad EspecialidadNecesaria;
public:
#pragma region Constructores y Destructores
	Paciente(string Nombre, string Apellido, string FechaNacimiento,string Telefono);
	~Paciente();
#pragma endregion

#pragma region Metodos
	//Cambia el especialidadNecesaria entre alguno de los problemas que pueden haber
	void GenerarProblema();
	void ActualizarFechaUltimaVisita(tm FechaUltimaVisita);
	eEspecialidad GetProblema();
#pragma endregion


};

