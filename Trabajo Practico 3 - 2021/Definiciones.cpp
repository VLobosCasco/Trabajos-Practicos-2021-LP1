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

string CovertEstadoString(eEstado tipo)
{
	switch (tipo)
	{
	case eEstado::Libre:
		return "Libre";
		break;
	case eEstado::En_Mantenimiento:
		return "En Mantenimiento";
		break;
	case eEstado::Fuera_de_servicio:
		return "Fuera de Servicio";
		break;
	default:
		return "";
		break;
	}

	return "";

}

float getCostoAdicionalDefault(eTipoAdicional adicional)
{
	switch (adicional)
	{
	case eTipoAdicional::Casco:
		return DEFAULT_CASCO;
		break;
	case eTipoAdicional::Silla_Ninos:
		return DEFAULT_SILLA;
		break;
	case eTipoAdicional::Portaequipaje:
		return DEFAULT_PORTAEQUIPAJE;
		break;
	case eTipoAdicional::Asientos_rebatibles:
		return DEFAULT_ASIENTO;
		break;
	default:
		break;
	}
	return 0;
}
