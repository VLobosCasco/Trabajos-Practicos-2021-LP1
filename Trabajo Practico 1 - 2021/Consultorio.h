#pragma once
#include <iostream>
#include <string>
#include "Medico.h"
#include "Horario.h"

#include "Paciente.h"
using namespace std;

class Consultorio
{
private:
	unsigned int ID;
	string Nombre;
	string Direccion;
	string Telefono;
	Horario* HorarioApertura;
	Horario* HorarioCierre;
	Medico* MedicoPrincipal;
	Medico* MedicoSecundario;
public:
	//Pragma region me permite estructurar mejor el codigo, totalmente opcional!
	#pragma region Constructores y Destructores
	//Constructor por defecto (Por que no lo declaro? Tira error sino)
	//Si tengo un constructor por parametros por defecto con todos los 
	//parametros por defecto entonces a fin de cabo es un constructor por defecto
	//Prueben descomentar la linea a ver que pasa
	//Consultorio();

	//Constructor por parametros (se puede eliminar porque el de defectos hace lo mismo
	//Consultorio(unsigned int ID, string Nombre, string Direccion, string Telefono,
	//	string HorarioApertura, string HorarioCierre, char Delimitador=':');
	//Constructor por parametros por defecto
	Consultorio(unsigned int ID = 0, string Nombre = "Test", string Direccion = "Av. Test 123", string Telefono = "12345689",
		string HorarioApertura = "10:30", string HorarioCierre = "20:00", char Delimitador = ':');
	//Destructor
	~Consultorio();
	#pragma endregion

	#pragma region Metodos
	//Recibe un Médico y verifica que trabaje en el consultorio, si
	//trabaja en el consultorio se lo asigna a uno de los 2 punteros, caso contrario
	//imprime en pantalla “Médico{ apellido } {matrícula} no corresponde al consultorio”
	bool ArribarMedico(Medico* medico);

	//Recibe el nombre de un Médico y se fija si está entre los
	//punteros, en caso de que esté, lo quita del consultorio(NO LO ELIMINA) y lo
	//devuelve por izquierda
	Medico* RetirarMedico(string NombreMedico);

	//Entra un paciente y lo asigna a un médico para ser atendido.
	//Si están los 2 ocupados Imprimir en pantalla “Los médicos están ocupados”.
	void EntrarPaciente(Paciente* paciente);

	//Devuelve un string que contiene el horario de atención en el formato:
	//XX:XX - YY:YY
	string GetHorarioAtencion();

	unsigned int GetID();

	string ToString();
	void ImprimirPantalla();
	#pragma endregion

	

};

