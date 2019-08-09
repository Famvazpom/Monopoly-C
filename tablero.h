#pragma once
#include "casilla.cpp"
class tablero
{
public:
	tablero();
	~tablero();
	Casilla mapa[40];	
	void CreaTablero();
	void ImprimeTablero();
};

