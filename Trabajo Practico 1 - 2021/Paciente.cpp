#include "Paciente.h"
#include "Funciones.h"

Paciente::Paciente(string Nombre, string Apellido, string FechaNacimiento, string Telefono)
{
	this->Nombre = Nombre;
	this->Apellido = Apellido;
	this->FechaNacimiento = ConvertStringtm(FechaNacimiento);
	this->UltimaVisita = tm();
	this->Telefono = Telefono;
	this->EspecialidadNecesaria = eEspecialidad::Ninguna;
}

Paciente::~Paciente()
{
}

void Paciente::GenerarProblema()
{
	this->EspecialidadNecesaria = (eEspecialidad)((rand() % (int)eEspecialidad::ENUM_MAX - 1) + 1);
}

void Paciente::ActualizarFechaUltimaVisita(tm FechaUltimaVisita)
{
	this->UltimaVisita = FechaUltimaVisita;
}

eEspecialidad Paciente::GetProblema()
{
	return this->EspecialidadNecesaria;
}
