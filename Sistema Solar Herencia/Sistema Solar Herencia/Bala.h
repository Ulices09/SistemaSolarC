#pragma once
#include "galaxia.h"
class Bala :
	public Galaxia
{
private:
	bool eliminar_bala;

public:
	Bala(void);
	Bala(int p_X, int p_Y, Bitmap ^bmp);
	~Bala(void);

	void Mostrar(Graphics ^gr, Bitmap ^bmp);
	void Mover(Graphics ^gr, Bitmap ^bmp);

	bool Retornar_eliminar_bala();
};

Bala::Bala(void)
{
}


Bala::~Bala(void)
{
}

Bala::Bala(int p_X, int p_Y,  Bitmap ^bmp)
{
	X=p_X;
	Y=p_Y;
	dy=-10;

	W=bmp->Width;
	H=bmp->Height;

	eliminar_bala = false;

}

void Bala::Mostrar(Graphics ^gr, Bitmap ^bmp)
{
	gr->DrawImage(bmp, X, Y, W/1.5, H/1.5);
}

void Bala::Mover(Graphics ^gr, Bitmap ^bmp)
{
	if(Y+dy<1)
		eliminar_bala=true;

	Y = Y + dy;

	Mostrar(gr, bmp);
}

bool Bala::Retornar_eliminar_bala()
{
	return eliminar_bala;
}
