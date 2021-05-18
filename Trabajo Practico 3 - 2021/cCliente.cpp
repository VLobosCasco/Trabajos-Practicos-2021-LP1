#include "cCliente.h"

int cCliente::Cant_clientes = 0;

cCliente::cCliente():IdCliente(to_string(Cant_clientes)), DNI(to_string(0))
{
	Cant_clientes++;
	NombreCompleto = "Sin datos";
	Fecha_de_Nacimiento = new cFecha();
	TarjetadeCredito = "Sin datos";
}

cCliente::cCliente(string dni, string nombreapellido, cFecha* fdn, string tarj_cred) :IdCliente(to_string(Cant_clientes)), DNI(to_string(0))
{
	Cant_clientes++;
	NombreCompleto = nombreapellido;
	Fecha_de_Nacimiento = fdn;
	TarjetadeCredito = tarj_cred;
}

cCliente::~cCliente()
{
	if (Fecha_de_Nacimiento != NULL)
		delete Fecha_de_Nacimiento;
}


