#include "pch.h"
#include "jugador.h"


jugador::jugador()
{
	this->money = 2000;
	this->posicion = 0;
	this->free = true;
	this->turnos_restantes = 0;
	printf("Jugador Creado\n");
}


