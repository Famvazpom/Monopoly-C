#include "pch.h"
#include "jugador.cpp"
#include "tablero.cpp"

class Game
{
public:
	int actual_player; // Jugador en turno
	bool TiraDados(int *d1,int *d2);
	Game();
	~Game();
	void MuestraJugadores();
	void Realiza_Turno();

private:
	jugador *jugadores;
	tablero *tab;
	int cant_jugadores;
	void CambiaTurno();
	void MueveJugador(int d1,int d2);
};