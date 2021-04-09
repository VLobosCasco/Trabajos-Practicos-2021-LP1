
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include "Consultorio.h"
#include "Medico.h"
#include "Paciente.h"
#include "Horario.h"
#include "Enums.h"
#include "Funciones.h"


using namespace std;

int main() {
	//Creo mis variables a utilizar, siempre DINAMICAS
	Paciente* miPaciente = new Paciente("Julieta", "Di Marco", "06/11/1998", "49032541");
	Paciente* miPaciente2 = new Paciente("Taylor", "Swift", "13/12/1989", "111111111");
	//Todo viene por defecto, le doy un ID diferente a 0 (Por ahora lo vamos a hacer así, el 
	Consultorio* Consultorio_1 = new Consultorio(1);
	Medico* Medico1 = new Medico("Fernanda", "Gomez", "82001", "20/11/1969", eEspecialidad::Cardiologo);
	Medico* Medico2 = new Medico("Meredith", "Grey", "15425", "15/11/1975", eEspecialidad::Gastroenterologo);
	
	Consultorio_1->ImprimirPantalla();

	miPaciente->GenerarProblema();
	
	cout << ConvertEspecialidadString(miPaciente->GetProblema()) << endl;
	

	if (Consultorio_1->ArribarMedico(Medico1)) {
		cout << "Medico: " << Medico1->GetNombre() << " Entro al consultorio" << endl;
	}
	else
		cout << "Medico: " << Medico1->GetNombre() << " No pertenece al consultorio" << endl;

	Medico1->AsociarConsultorio(Consultorio_1);
	if (Consultorio_1->ArribarMedico(Medico1)) {
		cout << "Medico: " << Medico1->GetNombre() << " Entro al consultorio" << endl;
	}
	else
		cout << "Medico: " << Medico1->GetNombre() << " No pertenece al consultorio" << endl;

	Medico2->AsociarConsultorio(Consultorio_1);
	if (Consultorio_1->ArribarMedico(Medico2)) {
		cout << "Medico: " << Medico2->GetNombre() << " Entro al consultorio" << endl;
	}
	else
		cout << "Medico: " << Medico2->GetNombre() << " No pertenece al consultorio" << endl;

	Consultorio_1->EntrarPaciente(miPaciente);
	Consultorio_1->EntrarPaciente(miPaciente2);
	cout << (Consultorio_1->GetHorarioAtencion()) << endl;
	Consultorio_1->ImprimirPantalla();
	Medico1->ImprimirPantalla();
	cout << endl;
	cout << "---------Retiro medico---------";
	cout << endl;

	//Si no tuviera la referencia del médico, acá lo perderia en memoria y genera un Memory Leak! Por eso lo debo agarrar con un aux
	//En el caso que el primero puntero no lo tenga más, tendría que eliminar a aux
	Medico* aux = Consultorio_1->RetirarMedico("Fernanda");
	Consultorio_1->ImprimirPantalla();


	delete miPaciente;
	delete miPaciente2;
	delete Consultorio_1;
	delete Medico1;

}