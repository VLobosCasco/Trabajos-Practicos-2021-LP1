#include "cAdicional.h"

cAdicional::cAdicional(eTipoAdicional e, float costo, int cant):elemento(e)
{
	costo_diario=costo;
	cantidad = cant;
}

float cAdicional::CalcularCostoDiarioTotal()
{
	return costo_diario * cantidad;
}

void cAdicional::AgregarElementos(int c)
{
	if (elemento != eTipoAdicional::Casco)
		cantidad = +c;
	else if (cantidad + c > 2)
		throw new exception("Se ha alcanzado el número máximo de cascos: 2");
	
}
