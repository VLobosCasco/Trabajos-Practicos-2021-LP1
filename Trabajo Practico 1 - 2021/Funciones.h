#pragma once

#include <ctime>
#include <string>

using namespace std;

void VerificarFecha(tm& Fecha);

tm ConvertStringtm(string FechaNac_str);

string ConverttmString(tm Fecha);