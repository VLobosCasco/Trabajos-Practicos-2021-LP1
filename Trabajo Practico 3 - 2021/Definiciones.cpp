#include "Definiciones.h"

string ConvertColorString(eColores color)
{
	switch (color)
	{
	case eColores::ROJO:
		return "Rojo";
		break;
	case eColores::AZUL:
		return "Azul";
		break;
	case eColores::VIOLETA:
		return "Violeta";
		break;
	case eColores::GRIS:
		return "Gris";
		break;
	case eColores::NEGRO:
		return "Negro";
		break;
	case eColores::BLANCO:
		return "Blanco";
			break;
	default:
		return "";
		break;
	}
}

string CovertTipoAdicionalString(eTipoAdicional tipo)
{
	switch (tipo)
	{
	case eTipoAdicional::Casco:
		return "Casco";
		break;
	case eTipoAdicional::Silla_Ninos:
		return "Silla Ninos";
		break;
	case eTipoAdicional::Portaequipaje:
		return "Porta equipaje";
		break;
	case eTipoAdicional::Asientos_rebatibles:
		return "Asientos Rebatibles";
		break;
	default:
		return "";
		break;
	}
}

string CovertEstadoString(eTipoAdicional tipo)
{
	switch (tipo)
	{
	case eTipoAdicional::Casco:
		return "Casco";
		break;
	case eTipoAdicional::Silla_Ninos:
		return "Silla de ninos";
		break;
	case eTipoAdicional::Portaequipaje:
		return "Portaequipaje";
		break;
	case eTipoAdicional::Asientos_rebatibles:
		return "Asientos rebatibles";
		break;
	default:
		break;
	}

	return "";

}
