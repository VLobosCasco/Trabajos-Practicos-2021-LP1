#define _CRT_SECURE_NO_WARNINGS
#include "Medico.h"
#include <iostream>
#include "Funciones.h"
#include "Consultorio.h"

Medico::Medico(string Nombre, string Apellido, string Matricula, string FechaNacimiento, eEspecialidad Especialidad)
{
    this->Nombre = Nombre;
    this->Apellido = Apellido;
    this->Matricula = Matricula;
    this->FechaNacimiento = ConvertStringtm(FechaNacimiento);
    this->Especialidad = Especialidad;
    Ocupado = false;
    PacienteAtendiendo = NULL;
}

Medico::~Medico()
{
    //Nada que borrar
}

unsigned int Medico::GetIDConsultorio()
{
    return ID_Consultorio;
}

string Medico::GetFechaNacimiento()
{
    return ConverttmString(FechaNacimiento);
}

void Medico::AtenderPaciente(Paciente* paciente)
{
    if (paciente == NULL) return;
    time_t now = time(0);
    tm* ltm = localtime(&now);
    paciente->ActualizarFechaUltimaVisita(*ltm);

    //Si el problema que tiene es la especialidad, atiendo
    if (paciente->GetProblema() == this->Especialidad) {
        Ocupado = true;
        PacienteAtendiendo = paciente;
    }
}

string Medico::ToString()
{
    return
        "Nombre: " + Nombre + "\n" +
        "Apellido: " + Apellido + "\n" +
        "Matricula: " + Matricula + "\n" +
        "Fecha Nacimiento: " + GetFechaNacimiento() + "\n" +
        "Especialidad: " + ConvertEspecialidadString(Especialidad) + "\n" +
        "Ocupado: " + (Ocupado ? "Si" : "No");

}

void Medico::ImprimirPantalla()
{
    cout << this->ToString() << endl;
}

void Medico::Desocupar()
{
    Ocupado = false;
    PacienteAtendiendo = NULL;
}

string Medico::GetNombre() {
    return Nombre;
}

bool Medico::IsOcupado()
{
    return Ocupado;
}

void Medico::AsociarConsultorio(Consultorio* consultorio){
    if(consultorio!=NULL){
        this->ID_Consultorio = consultorio->GetID();
    }
}

void Medico::DesasociarConsultorio(){
    this->ID_Consultorio = 0;
}
