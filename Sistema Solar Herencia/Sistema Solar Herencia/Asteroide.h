#pragma once
#include "galaxia.h"
class Asteroide :
	public Galaxia
{
private:

	bool Asteroide_sale_de_ventana;
public:
	Asteroide(void);
	Asteroide(int p_X, int p_Y, int p_dx, int p_dy, Bitmap ^bmp);
	~Asteroide(void);

	void Mover(Graphics ^gr, Bitmap ^bmp);
	void Mostrar(Graphics ^gr, Bitmap ^bmp);

	void Cambiar_Asteroide_sale_de_ventana(bool sale_ventana);
	bool Retornar_Asteroide_sale_de_ventana();
};

Asteroide::Asteroide(void)
{
}


Asteroide::~Asteroide(void)
{
}

Asteroide::Asteroide(int p_X, int p_Y, int p_dx, int p_dy, Bitmap ^bmp)
{
	X=p_X;
	Y=p_Y;
	dx=p_dx;
	dy=p_dy;
	
	
	W = bmp->Width/4;
	H = bmp->Height/4;

	indiceH=indiceW=0;

	Asteroide_sale_de_ventana=false;

}

void Asteroide::Mover(Graphics ^gr, Bitmap ^bmp)
{

	X=X+dx;
	Y=Y+dy;

	indiceW++;
	if(indiceW>3)
	{
		indiceW=0;
		indiceH++;

		if(indiceH>3)
			indiceH=0;
	}
	
	Mostrar(gr, bmp);

	if(X+H<0 || Y+H<0 || X > gr->VisibleClipBounds.Width || Y > gr->VisibleClipBounds.Height)//X+W+dx>gr->visibleclipbounds.width(probar)
		Asteroide_sale_de_ventana=true;
}

void Asteroide::Mostrar(Graphics ^gr, Bitmap ^bmp)
{
	Rectangle porcion_imagen = Rectangle(indiceW*W, indiceH*H, W, H);
	Rectangle zoom = Rectangle(X, Y, W/2, H/2);

	gr->DrawImage(bmp, zoom, porcion_imagen, GraphicsUnit::Pixel);

}

void Asteroide::Cambiar_Asteroide_sale_de_ventana(bool sale_ventana)
{
	Asteroide_sale_de_ventana = sale_ventana;
}

bool Asteroide::Retornar_Asteroide_sale_de_ventana()
{
	return Asteroide_sale_de_ventana;
}