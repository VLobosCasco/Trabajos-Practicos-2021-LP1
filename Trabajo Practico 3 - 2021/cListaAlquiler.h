#pragma once
#include "cListaT.h"
#include "cAlquiler.h"
class cListaAlquiler :
    protected cListaT<cAlquiler>
{
public:
#pragma region Metodos
 //Lista todos los alquileres de Motos
    void ListarAlquilerMotos();
//Lista todos los alquileres de Autos
    void ListarAlquilerAutos();
//Lista todos los alquileres de Camionetas
    void ListarAlquilerCamionetas();
//Lista todos los alquileres de Trafics
    void ListarAlquilerTrafics();
//Lista todos los alquileres de Motos y devuelve la ganacia total
    float ListaryGananciaAlquilerMotos();
//Lista todos los alquileres de Autos y devuelve la ganacia total
    float ListaryGananciaAlquilerAutos();
//Lista todos los alquileres de Camionetas y devuelve la ganacia total
    float ListaryGananciaAlquilerCamionetas();
//Lista todos los alquileres de Trafics y devuelve la ganacia total
    float ListaryGananciaAlquilerTrafics();
//Lista todos los alquileres y devuelve la ganancia total
    float ListaryGanancia();
#pragma endregion
};

