#pragma once
#include "pch.h"
#include "casilla.h"



void Casilla::CreaCasilla(int type, char name[50],int color, int base_loan, int house_price, int hotel_price, int price,int effect)
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
	this->type = type;
	this->actual_loan = this->base_loan = base_loan;
	this->hotel_price = hotel_price;
	this->house_price = house_price;
	this->price = price;
	this->owner = -1;
	this->effect = effect;
	this->status = 1;
	strcpy_s(this->name, 50, name);

	return;
}