#pragma once
#include "galaxia.h"
class EspacioExterior :
	public Galaxia
{
public:
	EspacioExterior(void);
	EspacioExterior(int p_X, int p_Y, int p_W, int p_H, Bitmap ^bmp);
	~EspacioExterior(void);

	void Mostrar(Graphics ^gr, Bitmap ^bmp);
	void calcular_W_H(Bitmap ^bmp);
};

EspacioExterior::EspacioExterior(void)
{
}


EspacioExterior::~EspacioExterior(void)
{
}

EspacioExterior::EspacioExterior(int p_X, int p_Y, int p_W, int p_H, Bitmap ^bmp)
{
	X=p_X;
	Y=p_Y;
	W=p_W;
	H=p_H;
	
}


void EspacioExterior::Mostrar(Graphics ^gr, Bitmap ^bmp)
{	
	gr->DrawImage(bmp, X, Y, W, H);
}
