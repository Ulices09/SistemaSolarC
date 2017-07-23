#pragma once

#include "Explosion.h"
#include <stdio.h>

class ArrExplosiones
{
private:
	Explosion** arreglo_explosiones;
	int *N;

public:
	ArrExplosiones(void);
	~ArrExplosiones(void);

	void MostrarExplosiones(int p_X, int p_Y, char* p_Imagen);
	void MoverExplosiones(Graphics ^gr);
	void EliminarExplosion();
};


ArrExplosiones::ArrExplosiones(void)
{
	arreglo_explosiones=NULL;

	N= new int();
	*N=0;
}


ArrExplosiones::~ArrExplosiones(void)
{
	for(int i=0; i<*N; i++)
		delete[] arreglo_explosiones;

	delete N;
}

void ArrExplosiones::MostrarExplosiones(int p_X, int p_Y, char* p_Imagen)
{
	Explosion** auxiliar = new Explosion*[*N+1];

	if(auxiliar!=NULL)
	{
		for(int i=0; i<*N; i++)
			auxiliar[i]=arreglo_explosiones[i];

		auxiliar[*N]=new Explosion(p_X, p_Y, p_Imagen);

		*N=*N+1;

		if(arreglo_explosiones!=NULL)
			delete arreglo_explosiones;

		arreglo_explosiones=auxiliar;
	}
}

void ArrExplosiones::MoverExplosiones(Graphics ^gr)
{
	for(int i=0; i<*N; i++)
		arreglo_explosiones[i]->Mover(gr);
}

void ArrExplosiones::EliminarExplosion()
{
	int cantidad = 0;

	for(int i=0; i<*N; i++)
	{
		if(arreglo_explosiones[i]->Retornar_Eliminar_Explosion())
			cantidad++;
	}

	if(cantidad>0)
	{
		Explosion** auxiliar = new Explosion*[*N-cantidad];
		
		int j=0;

		for(int i=0; i<*N; i++)
		{
			if(!arreglo_explosiones[i]->Retornar_Eliminar_Explosion())
			{
				auxiliar[j] = arreglo_explosiones[i];
				j++;
			}
		}

		*N=*N-cantidad;

		if(arreglo_explosiones!=NULL)
			delete[] arreglo_explosiones;

		arreglo_explosiones=auxiliar;
	}
}

