#pragma once
#include "casilla.h"
class tablero
{
public:
	tablero();
	~tablero();
	Casilla mapa[40];	
	void CreaTablero();
	void ImprimeTablero();
};

