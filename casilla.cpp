#pragma once
#include "pch.h"
#include "casilla.h"


void CreaCasilla(Casilla **item,int type, char name[50], int base_loan, int house_price, int hotel_price, int price,int effect)
{
	/*
		Esta funcion creara las casillas del tablero.
		Les asignara los valores proporcionados
	
		Valores de entrada:
			Casilla **item <- La casilla a crear
			int type <- El tipo de casilla
			char *name <- El nombre de la casilla
			int base_loan <- El alquiler base
			int house_price <- El precio de construccion de una casa
			int hotel_price <- El precio de construccion de un hotel
			int price <- El precio de compra de la casilla
	*/

	Casilla *actual = new Casilla;
	

	actual->type = type;
	actual->actual_loan= actual->base_loan = base_loan;
	actual->hotel_price = hotel_price;
	actual->house_price = house_price;
	actual->price = price;
	actual->owner = -1;
	actual->effect = effect;
	
	strcpy_s(actual->name, strlen(actual->name), name);
	*item = actual;
	return;
}