#include "game.h"
#include <cstdlib>
#include <time.h>
#include <stdlib.h>

Game::Game()
{
	bool band = 0;

	do
	{
		printf("Ingrese el numero de jugadores ( Minimo 2, Maximo 4)\n");
		scanf("%d",&this->cant_jugadores);		/* code */

		if(this->cant_jugadores < 2 || this->cant_jugadores >4)
		{
			band = 1;
			printf("Cantidad invalida, Ingrese un numero entre 2 y 4 jugadores \n");
		}

	} while (band);

	this -> jugadores = new jugador[this->cant_jugadores];
	this-> tab = new tablero;
	this->actual_player = 0;
}

Game::~Game()
{

	delete this->jugadores,this->tab;

}

void Game:: MuestraJugadores()
{
	for (int i = 0; i < this->cant_jugadores; ++i)
	{
		printf("Jugador: %d ,Dinero: %d, Posicion: %d, Libre: %d\n",i+1,this->jugadores[i].money,this->jugadores[i].posicion,this->jugadores[i].free );
	}
}

bool Game::TiraDados(int *d1,int *d2)
{
	srand (time(NULL));
	*d1 = (rand() % 6) +1;
	*d2 = (rand() % 6) +1;

	if (*d1 == *d2)	return 1;
	return 0;

}

void Game::Realiza_Turno()
{
	int d1,d2,count;
	bool band,game = false;

	count = 0;
	do
	{
		printf("Turno del jugador: %d\n",this->actual_player+1);
		d1 = d2 = 0;
		//Tirar Dados
		band = this->TiraDados(&d1,&d2);
		//Mover Jugador
		this->MueveJugador(d1,d2);
		//Comprar/Pagar

		//Cambiar turno
		if(!band)
		{
			this->CambiaTurno();
			count = 0;
		}
		else
		{
			count++;
			if (count >= 3)
			{
				// Enviar a la carcel al jugador
				printf("Carcel\n");
			}
		}
		system("pause");
		system("cls");
		this->MuestraJugadores();


	}while(game);
}

void Game::CambiaTurno()
{
	this->actual_player = (this->actual_player + 1) % 4;

}


void Game::MueveJugador(int d1,int d2)
{
	
	int mov,prev;
	jugador player = this->jugadores[this->actual_player];
	mov = d1 +d2 ;
	prev = player.posicion;
	player.posicion = (player.posicion + mov) %40;

	if (player.posicion == 30)
	{
		printf("Vaya a la carcel\n");
		player.posicion = 10;
		player.free = 0;
	}

	if (player.posicion == 0  || prev >= 28 && player.posicion > 0 && player.free == true) 
		//Si cae en la salida o si pasa por ella se le otorgan los 200 
	{
		printf("Salida\n");
		player.money += 200;
	}
	
	if (this->tab->mapa[player.posicion].type == 4)
	{
		printf("\nArca Comunal\n");
	}
	
	if (this->tab->mapa[player.posicion].type == 3)
	{
		printf("\nFortuna\n");
	}

	this->jugadores[this->actual_player] = player;
	/*
	tablero *mapa = this->tab;
	jugador player = this->jugadores[this->actual_player];

	int mov,prev = player.posicion;
	mov = d1+d2;
	player.posicion = (player.posicion + mov) % 40;

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
	

	if (player.posicion == 30) // Si cae en la casilla: "Vaya a la carcel"
	{
		printf("Vaya a la carcel\n");
		player.posicion = 10; // Se ira a la carcel y quedara preso por 3 turnos;
		player.free = false;
	}

	if (player.posicion == 0 || prev >= 0 && player.posicion > 0 && player.free == true ) 
		//Si cae en la salida o si pasa por ella se le otorgan los 200 
	{
		printf("Salida\n");
		player.money += 200;
	}
	
	if (mapa->mapa[player.posicion].type == 4)
	{
		printf("\nArca Comunal\n");
	}
	
	if (mapa->mapa[player.posicion].type == 3)
	{
		printf("\nFortuna\n");
	}
	*/
}