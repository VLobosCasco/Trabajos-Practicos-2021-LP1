#pragma once
#include "cVehiculo.h"
class cCamioneta :
    protected cVehiculo
{
public:
    static float precio_base;
    static float precio_diario;

#pragma region Constructor
    cCamioneta(string patente_c, string chasis_c, string poliza_c, eColores color_c, int cant_pasaj_c);
    cCamioneta(string patente_c, string chasis_c, string poliza_c, eColores color_c, int cant_pasaj_c, cFecha* ult_mantenimiento);

#pragma endregion
#pragma region Metodos
    //calcula el precio del alquiler del vehículo (tarifa base + precio por día) sin tener en cuenta los adicionales
    float CalcularTarifa(int dias);
    /*calcula el precio del alquiler del vehículo (tarifa base + precio por día) sin tener en cuenta los adicionales
    Recibe la fecha de inicio */
    float CalcularTarifa(cFecha& fecha_inicio, cFecha& fecha_fin);
    //Imprime los pasos de mantenimiento para el vehículo
    void PasosMantenimiento();
#pragma endregion
#pragma region To_string e Imprimir
    string to_string();
    void Imprimir();
};

