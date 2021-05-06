#include "Pasajero.h"

Pasajero::Pasajero(string DNI, string Nombre, float Peso, int HoraSubida, int MinutoSubida, eEstacion Origen, eEstacion Destino)
{
	this->DNI = DNI;
	this->Nombre = Nombre;
	this->Peso = Peso;
	char s[6];
	sprintf(s, "%02d:%02d", clamp(HoraSubida, 0, 23), clamp(MinutoSubida, 0, 59));
	this->HorarioSubida = string(s);
	this->HorarioBajada = "";
	this->EstacionOrigen = Origen;
	this->EstacionDestino = Destino;
}

void Pasajero::ArribarEstacion(int HoraBajada, int MinutoBajada)
{
	//Verifico si está bien
	int HoraSubida;
	int MinSubida;
	sscanf(this->HorarioSubida.c_str(), "%d:%d", &HoraSubida, &MinSubida);

	//Mejor irse antes
	if (HoraSubida > HoraBajada)
		throw new exception("Horario de bajada incorrecto");
	if (HoraSubida == HoraBajada) {
		if (MinSubida > MinutoBajada) {
			throw new exception("Horario de bajada incorrecto");
		}
	}
	//Si todo va bien, pongo la hora
	char s[6];
	sprintf(s, "%02d:%02d", clamp(HoraBajada, 0, 23), clamp(MinutoBajada, 0, 59));
	this->HorarioBajada = string(s);


}

string Pasajero::to_string()
{
	return DNI + Nombre + std::to_string(Peso) + HorarioBajada + HorarioSubida;
}

void Pasajero::Imprimir() 
{
	cout << to_string() << endl;
}
