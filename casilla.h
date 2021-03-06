#pragma once

class Casilla
{
public:

	char name[50]; 		// Nombre de la casilla 
	int type; 			// Tipo de casilla
	/*
		Existen 8 tipos de casillas:
			0.-	Salida
			1.-	Prision
			2.-	Propiedad
			3.-	Fortuna
			4.-	Arca Comunal
			5.-	Impuesto
			6.-	Parking
			7.-	Vaya a Prision
	*/

	int price;  		//Precio de la casilla 
	int status;			//Estado de la casilla
	/*
		Existen 3 estados:
		1.- Disponible para compra
		2.- Comprada
		3.- Hipotecada
	*/
	int owner;			//Jugador que posee la casilla
	/*
		Caso especial:
			owner == -1 <---- No se a comprado ( Propiedad del banco )
	*/
	int linea;			//Color al que pertenecen
	int base_loan;		//Alquiler base
	int actual_loan;	//Alquiler actual

	int houses;			//Cantidad de casas en la casilla	
	int house_price;	//Precio por construccion de casa

	int hotels;			//Cantidad de hoteles en la casilla
	int hotel_price;	//Precio por construccion de hotel

	int valor_hipoteca;	//Valor de hipoteca
	int effect;			//El indicador del efecto que realiza
	/*
		Solo los tipos 0,1,3,4 y 7 tienen lugar
	*/

	//Metodos
	/*
		CreaCasilla <- Este crea la casilla correspondiente
		ActualizaRenta <- Actualiza la renta
	*/
	void CreaCasilla(int type, char name[50], int color, int base_loan, int house_price, int hotel_price, int price, int effect);
	void Actualiza_Renta(Casilla *mapa);
};

