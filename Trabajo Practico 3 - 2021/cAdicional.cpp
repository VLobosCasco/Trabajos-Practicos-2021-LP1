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

void cAdicional::ModificarElementos(int cant)
{
	if (cantidad + cant < 0)
		throw new exception((("No se puede quitar esa cantidad de elementos. Cantidad de elementos disponibles")
			+ std::to_string(cantidad)).c_str());
	
	if (elemento != eTipoAdicional::Casco)
		cantidad = +cant;
	else if (cantidad + cant > 2)
		throw new exception("Se ha alcanzado el número máximo de cascos: 2");

	cantidad = +cant;
	
}

