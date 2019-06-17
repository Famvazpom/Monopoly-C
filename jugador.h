#pragma once
#include "pch.h"
#include "tablero.h"
class jugador
{
public:
	jugador();
	~jugador();
	int money; //Dinero que posee el jugador
	int posicion; // Posicion actual del jugador
	bool free;
	int turnos_restantes;
	/*
		Metodos:
		Mover_Jugador()
		Comprar_Propiedad()
	*/
	void Mover_Jugador(int mov,tablero *mapa);
	void Comprar_Propiedad();
};

