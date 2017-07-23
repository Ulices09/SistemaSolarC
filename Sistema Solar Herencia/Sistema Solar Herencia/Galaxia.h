#pragma once
using namespace System::Drawing;

#include <stdio.h>

class Galaxia
{
protected:
	int X;
	int Y;
	int dx;
	int dy;

	int W;
	int H;
	int indiceW;
	int indiceH;

public:
	Galaxia(void);
	~Galaxia(void);

	int Retornar_X();
	int Retornar_Y();
	int Retornar_W();
	int Retornar_H();
};

Galaxia::Galaxia(void)
{
	X=0;
	Y=0;
	dx=0;
	dy=0;
	W=0;
	H=0;
	indiceW=0;
	indiceH=0;
}


Galaxia::~Galaxia(void)
{

}

int Galaxia::Retornar_X()
{
	return X;
}

int Galaxia::Retornar_Y()
{
	return Y;
}

int Galaxia::Retornar_W()
{
	return W;
}

int Galaxia::Retornar_H()
{
	return H;
}
