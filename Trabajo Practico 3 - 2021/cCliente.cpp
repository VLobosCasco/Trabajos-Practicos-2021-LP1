#include "cCliente.h"



cCliente::cCliente() : DNI(to_string(0)) //ojo que esto me va a dar claves repetidas entonces voy a poder agregar uno solo a la lista
{
	NombreCompleto = "Sin datos";
	Fecha_de_Nacimiento = new cFecha();
	TarjetadeCredito = "Sin datos";
}

cCliente::cCliente(string dni, string nombreapellido, cFecha* fecha_nacimiento, string tarjeta_credito) : DNI(dni)
{
	
	NombreCompleto = nombreapellido;
	Fecha_de_Nacimiento = new cFecha(*fecha_nacimiento); //hago una nueva fecha por copia!! Si no cuando elimine el cliente se me va a borrar la fecha y si lo usé en otro lado voy a tener problemas
	TarjetadeCredito = tarjeta_credito;
}

cCliente::cCliente(string dni, string nombreapellido, int dia, int mes, int anio, string tarjeta_credito) : DNI(dni)
{
	
	NombreCompleto = nombreapellido;
	Fecha_de_Nacimiento = new cFecha(dia, mes, anio);
	TarjetadeCredito = tarjeta_credito;
}

cCliente::~cCliente()
{
	if (Fecha_de_Nacimiento != NULL)
		delete Fecha_de_Nacimiento;
}

string cCliente::getclave() const
{
	return DNI;
}


string cCliente::To_string()
{
	return "DNI: " + DNI + "\n" +
		"Nombre Completo: " + NombreCompleto + "\n" +
		"Fecha de Nacimiento: " + Fecha_de_Nacimiento->To_string()+"\n";


}

void cCliente::Imprimir()
{
	cout << To_string() << endl;
}


