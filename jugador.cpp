#include "pch.h"
#include "jugador.h"


jugador::jugador()
{
	this->money = 2000;
	this->posicion = 0;
	this->free = true;
	this->turnos_restantes = 0;
}


jugador::~jugador()
{
	printf("\nJugador eliminado\n");
}

void jugador::Mover_Jugador(int mov, tablero *mapa)
{
	int prev = this->posicion;
	this->posicion = (this->posicion + mov) % 40;

	/*
		Considerar una funcion para verificar los efectos de la casilla
		Tomar en cuenta:
			-La casilla es una propiedad y ha sido comprada
				** En este caso descontar la renta del dinero del jugador
			-Es "Arca Comunal"
			-Es "Fortuna"
			-Es "Salida"
			-Es "Vaya a la carcel"
			-Es casilla de Impuestos
	*/

	if (this->posicion == 30) // Si cae en la casilla: "Vaya a la carcel"
	{
		printf("Vaya a la carcel\n");
		this->posicion = 10; // Se ira a la carcel y quedara preso por 3 turnos;
		this->free = false;
	}

	if (this->posicion == 0 || prev >= 0 && this->posicion > 0 && this->free == true ) 
		//Si cae en la salida o si pasa por ella se le otorgan los 200 
	{
		printf("Salida\n");
		this->money += 200;
	}
	
	if (mapa->mapa[this->posicion].type == 4)
	{
		printf("\nArca Comunal\n");
	}
	if (mapa->mapa[this->posicion].type == 3)
	{
		printf("\nFortuna\n");
	}
}
