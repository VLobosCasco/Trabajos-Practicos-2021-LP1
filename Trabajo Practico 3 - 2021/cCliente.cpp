#include "cCliente.h"



cCliente::cCliente() : DNI(to_string(0))
{
	NombreCompleto = "Sin datos";
	Fecha_de_Nacimiento = new cFecha();
	TarjetadeCredito = "Sin datos";
}

cCliente::cCliente(string dni, string nombreapellido, cFecha* fdn, string tarj_cred) : DNI(dni)
{
	
	NombreCompleto = nombreapellido;
	Fecha_de_Nacimiento = fdn;
	TarjetadeCredito = tarj_cred;
}

cCliente::cCliente(string dni, string nombreapellido, int dia, int mes, int anio, string tarj_cred) : DNI(dni)
{
	
	NombreCompleto = nombreapellido;
	Fecha_de_Nacimiento = new cFecha(dia, mes, anio);
	TarjetadeCredito = tarj_cred;
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


