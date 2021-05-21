#pragma once
#define DEFAULT_CASCO  20.5
#define DEFAULT_SILLA 20
#define DEFAULT_PORTAEQUIPAJE 50
#define DEFAULT_ASIENTO 25

enum class eColores{ ROJO=0, AZUL, VIOLETA, GRIS, NEGRO, BLANCO};
enum class eTipoAdicional{ Casco=1, Silla_Ninos,Portaequipaje,Asientos_rebatibles};
enum class eEstado{Libre=0,En_Mantenimiento, Fuera_de_servicio};