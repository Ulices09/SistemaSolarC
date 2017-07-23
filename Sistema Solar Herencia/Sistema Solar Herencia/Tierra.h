#pragma once
#include "galaxia.h"
class Tierra :
	public Galaxia
{
private:
	int r;
	int r2;
	int angulo;
	int Xcentral;
	int Ycentral;

public:
	Tierra(void);
	Tierra(int P_r1, int P_r2, int P_angulo, int P_Xcentral, int P_Ycentral, Bitmap ^bmp);
	~Tierra(void);

	void Transformar();
	void Mover(Graphics ^gr, Bitmap ^bmp);
	void Mostrar(Graphics ^gr, Bitmap ^bmp);
};

Tierra::Tierra(void)
{
}


Tierra::~Tierra(void)
{
}

Tierra::Tierra(int P_r1, int P_r2, int P_angulo, int P_Xcentral, int P_Ycentral, Bitmap ^bmp)
{
	r=P_r1;
	r2=P_r2;
	angulo=P_angulo;
	Xcentral=P_Xcentral;
	Ycentral=P_Ycentral;

	Transformar();

	W = bmp->Width/6;
	H = bmp->Height/8;
	indiceW=indiceH=0;
}

//Tierra::Tierra(int P_r1, int P_r2, int P_angulo, int P_Xcentral, int P_Ycentral, Bitmap ^bmp)/*:Galaxia()*/
//{
//	r=P_r1;
//	r2=P_r2;
//	angulo=P_angulo;
//	Xcentral=P_Xcentral;
//	Ycentral=P_Ycentral;
//
//	Transformar();
//
//	
//	W = bmp->Width/6;
//	H = bmp->Height/8;
//	indiceW=indiceH=0;
//
//}

void Tierra::Transformar()
{
	float angulo_radianes=(angulo*3.141516)/180;

	X=Xcentral + r*1.2*System::Math::Cos(angulo_radianes);
	Y=Ycentral + r2*0.6*System::Math::Sin(angulo_radianes);
}

void Tierra::Mover(Graphics ^gr, Bitmap ^bmp)
{
	angulo-=5;
	if(System::Math::Abs(angulo>360))
		angulo=0;

	indiceW++;
	if(indiceW>5)
	{
		indiceW=0;
		indiceH++;

		if(indiceH>6)
			indiceH=0;
	}

	Transformar();
	Mostrar(gr, bmp);
}

void Tierra::Mostrar(Graphics ^gr, Bitmap ^bmp)
{
	/*bmp->MakeTransparent(bmp->GetPixel(1,1));*/
	Rectangle porcion_de_imagen = Rectangle(indiceW*W, indiceH*H, W, H);
	Rectangle zoom = Rectangle(X,Y,W*1.2,H*1.2);

	/*gr->DrawImage(bmp, X, Y, porcion_de_imagen, GraphicsUnit::Pixel);*/
	gr->DrawImage(bmp, zoom, porcion_de_imagen, GraphicsUnit::Pixel);

}