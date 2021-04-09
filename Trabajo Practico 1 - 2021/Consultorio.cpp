#include "Consultorio.h"

Consultorio::Consultorio(unsigned int ID, string Nombre, string Direccion, string Telefono, string HorarioApertura, string HorarioCierre, char Delimitador)
{
    this->ID = ID;
    this->Nombre = Nombre;
    this->Direccion = Direccion;
    this->HorarioApertura = new Horario(HorarioApertura, Delimitador);
    this->HorarioCierre = new Horario(HorarioCierre, Delimitador);
    this->Telefono = Telefono;
    MedicoPrincipal = NULL;
    MedicoSecundario = NULL;
}

Consultorio::~Consultorio()
{
    //Solo elimino si son diferente a null, sino tira error
    if (HorarioApertura != NULL)
        delete HorarioApertura;
    if (HorarioCierre != NULL)
        delete HorarioCierre;
}

bool Consultorio::ArribarMedico(Medico* medico)
{
    if (medico != NULL) {
        //Verifico si pertenece primero
        if (medico->GetIDConsultorio() == ID) {
            //Si el medico principal existe...
            if (MedicoPrincipal != NULL) {
                //... Me fijo el segundo
                if (MedicoSecundario != NULL) {
                    //Si están los 2 ocupados no puede entrar el medico
                    return false;
                }
                MedicoSecundario = medico;
                return true;
            }
            MedicoPrincipal = medico;
            return true;
        }
    }
    return false;
}

Medico* Consultorio::RetirarMedico(string NombreMedico)
{
    if (MedicoPrincipal != NULL) {
        if (MedicoPrincipal->GetNombre() == NombreMedico) {
            Medico* aux = MedicoPrincipal;
            MedicoPrincipal = MedicoSecundario;
            MedicoSecundario = NULL;
            aux->DesasociarConsultorio();
            return aux;
        }
    }

    if (MedicoSecundario != NULL) {
        if (MedicoSecundario->GetNombre() == NombreMedico) {
            Medico* aux = MedicoSecundario;
            aux->DesasociarConsultorio();
            MedicoSecundario = NULL;
            return aux;
        }
    }
}

void Consultorio::EntrarPaciente(Paciente* paciente)
{
    //Idealmente buscaría el medico que tenga la especialidad que necesita el paciente, pero para simpliciar
    //Solamente voy a buscar el primero y el segundo en orden de ocupados
    //Caso: NO tengo medicos
    if (MedicoPrincipal == NULL) {
        cout << "No hay medicos para atender" << endl;
        return;
    }
    //Caso: Tengo medico principal pero NO Secundario
    if (MedicoSecundario == NULL) {
        //Pregunto nomás si el principal no está ocupado
        if (!MedicoPrincipal->IsOcupado()) {
            MedicoPrincipal->AtenderPaciente(paciente);
            return;
        }
        else {
            cout << "El medico está ocupado" << endl;
            return;
        }
    }

    //Caso: Están los 2 medicos, verifico el primero que esté desocupado
	if (!MedicoSecundario->IsOcupado()) {
		MedicoSecundario->AtenderPaciente(paciente);
		return;
	}
    if (!MedicoPrincipal->IsOcupado()) {
        MedicoPrincipal->AtenderPaciente(paciente);
        return;
    }
	cout << "Los medicos están ocupados" << endl;
}

string Consultorio::GetHorarioAtencion()
{
    return HorarioApertura->ToString() + " - " + HorarioCierre->ToString();
}

string Consultorio::ToString()
{
    string output = "ID: " + to_string(ID) + "\n"
        "Nombre: " + Nombre + "\n"
        "Direccion: " + Direccion + "\n"
        "Telefono: " + Telefono + "\n"
        "Horario de atencion: " + GetHorarioAtencion() + "\n";
    if (MedicoPrincipal != NULL) {
        output += "\n";
        output += "-----Datos Medico Principal-----";
        output += "\n";
        output += "Medico Principal: " + MedicoPrincipal->ToString() + "\n";
    }
    if (MedicoSecundario != NULL) {
        output += "\n";
        output += "-----Datos Medico Secundario-----";
        output += "\n";
        output += "Medico Secundario: " + MedicoSecundario->ToString();

    }

    return output;
}

void Consultorio::ImprimirPantalla()
{
    cout << this->ToString() << endl;
}

unsigned int Consultorio::GetID(){
    return ID;
}