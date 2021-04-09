#pragma once
#include <string>

using namespace std;
//Me permite hacer que el enum sea siempre necesario llamar al tipo de enum
//Con el enum class evita que pueda hacer simplemente Cardiologo, con el class tengo que si o si usar
//eEspecialidad::Cardiologo con el operador de ámbito
//Enum max es un util indicador de cuantos elementos existen en el enum
//NO ES UTIL cuando uno cambia algun valor del enum en numero y no es creciente
enum class eEspecialidad {Ninguna, Cardiologo, Gastroenterologo, ENUM_MAX};

string ConvertEspecialidadString(eEspecialidad especialidad);
