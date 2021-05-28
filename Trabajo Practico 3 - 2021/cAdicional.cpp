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
	if (cantidad + cant < 0) //me fijo que si voy a eliminar (cant<0) no elimine más elementos de los que tengo
		throw new runtime_error((("No se puede quitar esa cantidad de elementos. Cantidad de elementos disponibles: ")
			+ std::to_string(cantidad)).c_str());
	
	if (elemento != eTipoAdicional::Casco)
		cantidad = +cant;
	else if (cantidad + cant > 2) //puedo alquilar solo 1 o 2 cascos
		throw new runtime_error("Se ha alcanzado el número máximo de cascos: 2");

	cantidad = +cant;
	
}

string cAdicional::To_string()
{
	return "Elemento: " + CovertTipoAdicionalString(elemento) + "\n" 
		"Cantidad: " + to_string(cantidad)+ "\n"
		"Costo Diario: " + to_string(costo_diario) + "\n\n";
}

