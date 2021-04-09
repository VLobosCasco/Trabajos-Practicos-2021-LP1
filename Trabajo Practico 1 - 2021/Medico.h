#pragma once
#include <iostream>
#include <string>
#include <ctime>
#include "Enums.h"
#include "Paciente.h"

using namespace std;

class Consultorio;

class Medico
{
	unsigned int ID_Consultorio;
	string Nombre;
	string Apellido;
	string Matricula;
	tm FechaNacimiento;

	//Se puede sacar siempre en cuando el getter verifique que el paciente sea null o no
	bool Ocupado; 
	eEspecialidad Especialidad;
	Paciente* PacienteAtendiendo;
public:
#pragma region Constructores y Destructores
	//Fecha nacimiento debe ser del formato "DD/MM/AAAA"
	//Esta es la propiedad de Abstracci�n!!
	Medico(string Nombre, string Apellido, string Matricula, string FechaNacimiento
		,eEspecialidad Especialidad);
	~Medico();
#pragma endregion


#pragma region Metodos
	unsigned int GetIDConsultorio();

	//Wrapper del struct de tm de C para C++
	//Convierte de tm a Dia/Mes/A�o
	string GetFechaNacimiento();

	//Recibe un paciente y cambia el estado del m�dico a ocupado.
	//Cambia el registro del paciente a la �ltima visita a hoy.Cambia el
	//puntero de Paciente al Paciente que entra de par�metro.
	//En el caso que el m�dico no sea de la especialidad, se registra la visita igual pero directamente no guarda al paciente ni se pone ocupado.
	void AtenderPaciente(Paciente* paciente);

	string ToString();
	void ImprimirPantalla();

	//Apunta el paciente en null y pone el estado ocupado en false
	void Desocupar();

	string GetNombre();

	bool IsOcupado();

	void AsociarConsultorio(Consultorio* consultorio);
	void DesasociarConsultorio();
#pragma endregion

};

