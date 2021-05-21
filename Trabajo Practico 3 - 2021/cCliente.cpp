#include "cCliente.h"

int cCliente::Cant_clientes = 0;

cCliente::cCliente():IDCliente(to_string(Cant_clientes)), DNI(to_string(0))
{
	Cant_clientes++;
	NombreCompleto = "Sin datos";
	Fecha_de_Nacimiento = new cFecha();
	TarjetadeCredito = "Sin datos";
}

cCliente::cCliente(string dni, string nombreapellido, cFecha* fdn, string tarj_cred) :IDCliente(to_string(Cant_clientes)), DNI(dni)
{
	Cant_clientes++;
	NombreCompleto = nombreapellido;
	Fecha_de_Nacimiento = fdn;
	TarjetadeCredito = tarj_cred;
}

cCliente::cCliente(string dni, string nombreapellido, int dia, int mes, int anio, string tarj_cred) :IDCliente(to_string(Cant_clientes)), DNI(dni)
{
	Cant_clientes++;
	NombreCompleto = nombreapellido;
	Fecha_de_Nacimiento = new cFecha(dia,mes,anio);
	TarjetadeCredito = tarj_cred;
}

cCliente::~cCliente()
{
	if (Fecha_de_Nacimiento != NULL)
		delete Fecha_de_Nacimiento;
}

string cCliente::getclave()
{
	return IDCliente;
}

string cCliente::getID()
{
	return IDCliente;
}

string cCliente::To_string()
{
	return string();
}

void cCliente::Imprimir()
{
	cout << To_string() << endl;
}


