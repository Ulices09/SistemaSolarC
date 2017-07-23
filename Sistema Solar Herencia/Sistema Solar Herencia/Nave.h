#pragma once
#include "galaxia.h"
#include "Bala.h"
#include "Asteroide.h"

class Nave :
	public Galaxia
{
private:
	Bala** arreglo_balas;
	int N;

public:
	Nave(void);
	Nave(int p_X, int p_Y, Bitmap ^bmp);
	~Nave(void);

	void Mostrar(Graphics ^gr, Bitmap ^bmp);
	void Mover(Graphics ^gr, Bitmap ^bmp);

	void DispararBalas(Bitmap ^bmp);
	void MoverBalas(Graphics ^gr, Bitmap ^bmp);
	void Eliminar_balas();
	void Cambiar_X_Y(int nuevoX, int nuevoY);
};

Nave::Nave(void)
{
}


Nave::~Nave(void)
{
}

Nave::Nave(int p_X, int p_Y, Bitmap ^bmp)
{
	X=p_X;
	Y=p_Y;

	W=bmp->Width/5;
	H=bmp->Height/3;

	indiceH=0;
	indiceW=0;

	arreglo_balas=NULL;
	N=0;


}

void Nave::Mostrar(Graphics ^gr, Bitmap ^bmp)
{
	Rectangle porcion_imagen = Rectangle(indiceW*W, indiceH*H, W, H);
	Rectangle zoom = Rectangle(X, Y, W/1.5, H/1.5);

	gr->DrawImage(bmp, zoom, porcion_imagen, GraphicsUnit::Pixel);
}

void Nave::Mover(Graphics ^gr, Bitmap ^bmp)
{

	Mostrar(gr, bmp);
}

void Nave::DispararBalas(Bitmap ^bmp)
{
	Bala** auxiliar = new Bala*[N+1];

	if(auxiliar!=NULL)
	{
		for(int i=0; i<N; i++)
			auxiliar[i] = arreglo_balas[i];

		auxiliar[N] = new Bala(X+(W/2)-22, Y-15, bmp);

		N=N+1;

		if(arreglo_balas!=NULL)
			delete arreglo_balas;

		arreglo_balas=auxiliar;
	}
}

void Nave::MoverBalas(Graphics ^gr, Bitmap ^bmp)
{
	for(int i=0; i<N; i++)
		arreglo_balas[i]->Mover(gr, bmp);

	Eliminar_balas();
}

void Nave::Eliminar_balas()
{
	int cantidad=0;

	for(int i=0; i<N; i++)
		cantidad+=arreglo_balas[i]->Retornar_eliminar_bala()? 1:0;

	Bala** auxiliar = new Bala*[N - cantidad];

	int j=0;

	if(auxiliar!=NULL)
	{
		for(int i=0; i<N; i++)
		{
			if(!arreglo_balas[i]->Retornar_eliminar_bala())
			{
				auxiliar[j]=arreglo_balas[i];
				j++;
			}
		}

		N=N-cantidad;

		if(arreglo_balas!=NULL)
			delete arreglo_balas;

		arreglo_balas=auxiliar;
	}
}

void Nave::Cambiar_X_Y(int nuevoX, int nuevoY)
{
	X=nuevoX;
	Y=nuevoY;
}