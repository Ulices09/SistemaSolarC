#pragma once
#include "galaxia.h"
class Luna :
	public Galaxia
{
private:
	int angulo;
	int r1;
	int r2;
	int x_central;
	int y_central;

public:
	Luna(void);
	Luna(int p_angulo, int p_r1, int p_r2, int p_x_central, int p_y_central, Bitmap ^bmp);
	~Luna(void);

	void transformar();
	void Mostrar(Graphics ^gr, Bitmap ^bmp);
	void Mover(Graphics ^gr, Bitmap ^bmp);
	void ActualizarXYCentroTraslacion(int _xcentro,int _ycentro);
};

Luna::Luna(void)
{
}


Luna::~Luna(void)
{
}

Luna::Luna(int p_angulo, int p_r1, int p_r2, int p_x_central, int p_y_central, Bitmap ^bmp)
{
	angulo=p_angulo;
	r1=p_r1;
	r2=p_r2;
	x_central=p_x_central;
	y_central=p_y_central;

	transformar();

	W=bmp->Width;
	H=bmp->Height;
}

void Luna::transformar()
{
	float angulo_radianes = (angulo*3.141516)/180;

	X=x_central + r1*1.2*System::Math::Cos(angulo_radianes);
	Y=y_central + r2*1.2*System::Math::Sin(angulo_radianes);
}
	
void Luna::Mostrar(Graphics ^gr, Bitmap ^bmp)
{
	gr->DrawImage(bmp, X, Y, W/6, H/6);
}
	
void Luna::Mover(Graphics ^gr, Bitmap ^bmp)
{
	angulo-=30;
	if(System::Math::Abs(angulo>360))
		angulo=0;

	transformar();

	Mostrar(gr, bmp);
}

void Luna::ActualizarXYCentroTraslacion(int _xcentro,int _ycentro)
{
	x_central=_xcentro;    y_central=_ycentro;
}