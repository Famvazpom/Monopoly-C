#include "pch.h"
#include "tablero.h"
#include "casilla.h"


tablero::tablero()
{
	this->CreaTablero();
}


tablero::~tablero()
{
}

void tablero::CreaTablero()
{
	char name[40][50] = { 
		"SALIDA",
		"AVENIDA MEDITERRANEO",
		"ARCA COMUNAL",
		"AVENIDA BALTICA",
		"IMPUESTO SOBRE INGRESOS",
		"FERROCARRIL READING",
		"AVENIDA ORIENTAL",
		"FORTUNA",
		"AVENIDA VERMONT",
		"AVENIDA CONNECTICUT",
		"CARCEL",
		"PLAZA SAN CARLOS",
		"COMPANIA DE ELECTRICIDAD",
		"AVENIDA STATUS",
		"AVENIDA VIRGINIA",
		"FERROCARRIL DE PENSILVANIA",
		"PLAZA ST JAMES",
		"ARCA COMUNAL",
		"AVENIDA TENNESSEE",
		"AVENIDA NEW YORK",
		"PARADA LIBRE",
		"AVENIDA KENTUCKY",
		"FORTUNA",
		"AVENIDA INDIANA",
		"AVENIDA ILLINOIS",
		"FERROCARRIL B. & O.",
		"AVENIDA ATLANTICO",
		"AVENIDA VENTNOR",
		"COMPANIA DE AGUA",
		"JARDINES MARVIN",
		"VAYA A LA CARCEL",
		"AVENIDA PACIFICO",
		"AVENIDA CAROLINA DEL NORTE",
		"ARCA COMUNAL",
		"AVENIDA PENSILVANIA",
		"FERROCARRIL VIA RAPIDA",
		"FORTUNA",
		"PLAZA PARK",
		"IMPUESTO SOBRE POSESIONES DE LUJO",
		"EL MUELLE" };
	int types[40] =
	{
		0,2,4,2,5,2,2,3,2,2,
		1,2,2,2,2,2,2,4,2,2,
		6,2,3,2,2,2,2,2,2,2,
		7,2,2,4,2,2,3,2,5,2
	};
	
	int colores[40] = 
	{	-1,1,-1,1,-1,9,2,-1,2,2,
		-1,3,10,3,3,9,4,-1,4,4,
		-1,5,-1,5,5,9,6,6,10,6,
		-1,7,7,-1,7,9,-1,8,-1,8
	};

	int prices[40] =
	{
		-1,50,-1,50,-1,200,100,-1,100,120,
		-1,140,150,140,160,200,180,-1,180,200,
		-1,220,-1,220,240,200,250,250,150,280,
		-1,300,300,-1,320,200,-1,250,-1,400,
	};

	for (int i = 0; i < 40; i++)
	{
		this->mapa[i].CreaCasilla(types[i], name[i],colores[i], 0, 0, 0, prices[i], 0);
	}

}

void tablero::ImprimeTablero()
{
	for (int i = 0; i < 40; i++)
	{
		printf("NOMBRE:%s TIPO: %d PRECIO: %d \n", this->mapa[i].name,this->mapa[i].type,this->mapa[i].price);
	}
}