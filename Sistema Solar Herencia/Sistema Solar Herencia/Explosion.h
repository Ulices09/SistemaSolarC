#pragma once
#include "galaxia.h"
#include "string.h""

class Explosion :
	public Galaxia
{
private:
	char* Imagen;

	bool Eliminar_explosion;
public:
	Explosion(void);
	Explosion(int p_X, int p_Y, char* p_Imagen);
	~Explosion(void);

	void Mostrar(Graphics ^gr);
	void Mover(Graphics ^gr);

	int Retornar_indiceH_Explosion();

	bool Retornar_Eliminar_Explosion();
};

Explosion::Explosion(void)
{
}

Explosion::~Explosion(void)
{
	delete Imagen;
}

Explosion::Explosion(int p_X, int p_Y, char* p_Imagen)
{
	X = p_X;
	Y = p_Y;
	Imagen=new char[50];
	strcpy(Imagen, p_Imagen);

	Bitmap ^bmp = gcnew Bitmap(gcnew System::String(Imagen));
	W = bmp->Width/5;
	H = bmp->Height/4;
	indiceH=indiceW=0;

	Eliminar_explosion=false;

	delete bmp;
}

void Explosion::Mostrar(Graphics ^gr)
{
	Bitmap ^bmp = gcnew Bitmap(gcnew System::String(Imagen));
	Rectangle porcion_imagen = Rectangle(indiceW*W, indiceH*H, W, H);
	Rectangle zoom = Rectangle(X, Y, W/1.5, H/1.5);

	gr->DrawImage(bmp, zoom, porcion_imagen, GraphicsUnit::Pixel);
}

void Explosion::Mover(Graphics ^gr)
{
	indiceW++;
	if(indiceW>4)
	{
		indiceW=0;
		indiceH++;
	}

	if(indiceH<3)
	{
		Mostrar(gr);
	}
	else
	{
		Eliminar_explosion=true;
	}
	
}

int Explosion::Retornar_indiceH_Explosion()
{
	return indiceH;
}

bool Explosion::Retornar_Eliminar_Explosion()
{
	return Eliminar_explosion;
}

