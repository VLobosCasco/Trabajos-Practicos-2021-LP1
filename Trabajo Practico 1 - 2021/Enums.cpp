#include "Enums.h"

string ConvertEspecialidadString(eEspecialidad especialidad)
{
	switch (especialidad)
	{
	case eEspecialidad::Cardiologo:
		return "Cardiologo";
		break;
	case eEspecialidad::Gastroenterologo:
		return "Gastroenterologo";
		break;
	default:
		return "";
		break;
	}
}
