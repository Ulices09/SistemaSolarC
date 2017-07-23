#pragma once
#include "galaxia.h"
class Sol :
	public Galaxia
{
public:
	Sol(void);
	Sol(int p_X, int p_Y, Bitmap ^bmp);
	~Sol(void);

	void Mostrar(Graphics ^gr, Bitmap ^bmp);
};

Sol::Sol(void)
{
}


Sol::~Sol(void)
{
}

Sol::Sol(int p_X, int p_Y, Bitmap ^bmp)
{
	X=p_X;
	Y=p_Y;
	
	W = bmp->Width;
	H = bmp->Height;
}

void Sol::Mostrar(Graphics ^gr, Bitmap ^bmp)
{

	gr->DrawImage(bmp, X, Y, W/2, H/2);

}