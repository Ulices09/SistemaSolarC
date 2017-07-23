#pragma once

#include <stdio.h>
#include "Asteroide.h"
#include "Explosion.h"
#include "ArrExplosiones.h"

class ArrAsteroides
{
private:
	Asteroide** arreglo_asteroides;
	int* N;

	Explosion* objExplosion;
	ArrExplosiones* objArrExplosiones;
public:
	ArrAsteroides(void);
	~ArrAsteroides(void);

	void CrearAsteroides(int p_X, int p_Y, int p_dx, int p_dy, Bitmap ^bmp);
	void Mover_ArrAsteroides(Graphics ^gr, Bitmap ^bmp);

	void Eliminar_Asteroide();

	void Colision_Asteroides();
};

ArrAsteroides::ArrAsteroides(void)
{
	arreglo_asteroides=NULL;
	objArrExplosiones=NULL;
	objExplosion=NULL;

	N= new int();
	*N=0;
}


ArrAsteroides::~ArrAsteroides(void)
{
	for(int i=0; i<*N; i++)
		delete arreglo_asteroides[i];

	delete N;
	delete objArrExplosiones;
}


void ArrAsteroides::CrearAsteroides(int p_X, int p_Y, int p_dx, int p_dy, Bitmap ^bmp)
{
	Asteroide** auxiliar = new Asteroide*[*N+1];

	if(auxiliar!=NULL)
	{
		for(int i=0; i<*N; i++)
			auxiliar[i]=arreglo_asteroides[i];

		auxiliar[*N]= new Asteroide( p_X, p_Y, p_dx, p_dy, bmp);

		*N=*N+1;

		if(arreglo_asteroides!=NULL)
			delete[] arreglo_asteroides;

		arreglo_asteroides = auxiliar;
	}
}

void ArrAsteroides::Mover_ArrAsteroides(Graphics ^gr, Bitmap ^bmp)
{
	for(int i = 0; i < *N; i++)
	{
		arreglo_asteroides[i]->Mover(gr, bmp);

		Colision_Asteroides();
		Eliminar_Asteroide();		
	}

	if(objArrExplosiones!=NULL)
	{
		objArrExplosiones->MoverExplosiones(gr);
		objArrExplosiones->EliminarExplosion();
	}


}

void ArrAsteroides::Eliminar_Asteroide()
{
	int cantidad = 0;

	for(int i=0; i<*N; i++)
	{
		if(arreglo_asteroides[i]->Retornar_Asteroide_sale_de_ventana())
			cantidad++;
	}

	if(cantidad>0)
	{
		Asteroide** auxiliar = new Asteroide*[*N-cantidad];
		
		int j=0;

		for(int i=0; i<*N; i++)
		{
			if(!arreglo_asteroides[i]->Retornar_Asteroide_sale_de_ventana())
			{
				auxiliar[j] = arreglo_asteroides[i];
				j++;
			}
		}

		*N=*N-cantidad;

		if(arreglo_asteroides!=NULL)
			delete[] arreglo_asteroides;

		arreglo_asteroides=auxiliar;
	}
}

void ArrAsteroides::Colision_Asteroides()
{
	if(*N>1)
	{
		
		for (int i=0; i<*N-1; i++)
		{
			for (int j=i+1; j<*N; j++)
			{
				if(!(arreglo_asteroides[i]->Retornar_X() +45> arreglo_asteroides[j]->Retornar_X() + arreglo_asteroides[j]->Retornar_W() ||
					arreglo_asteroides[i]->Retornar_Y() +45 > arreglo_asteroides[j]->Retornar_Y() + arreglo_asteroides[j]->Retornar_H() ||
					arreglo_asteroides[j]->Retornar_X() +45> arreglo_asteroides[i]->Retornar_X() + arreglo_asteroides[i]->Retornar_W() ||
					arreglo_asteroides[j]->Retornar_Y() +45 > arreglo_asteroides[i]->Retornar_Y() + arreglo_asteroides[i]->Retornar_H() ))
				{
					arreglo_asteroides[i]->Cambiar_Asteroide_sale_de_ventana(true);
					arreglo_asteroides[j]->Cambiar_Asteroide_sale_de_ventana(true);

					if(objArrExplosiones==NULL)
						objArrExplosiones = new ArrExplosiones();

					if(objArrExplosiones!=NULL)
						objArrExplosiones->MostrarExplosiones(arreglo_asteroides[i]->Retornar_X(), arreglo_asteroides[i]->Retornar_Y(), "explosion.png");
				}
			}
		}
	}
}