#include "game.h"
#include <cstdlib>
#include <time.h>
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
		printf("%d,%d\n",d1,d2 );
		//Mover Jugador

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


	}while(game);
}

void Game::CambiaTurno()
{
	this->actual_player = (this->actual_player + 1) % 4;

}