#pragma once

#include <stdio.h>
#include "Tierra.h"
#include "Sol.h"
#include "ArrAsteroides.h"
#include "EspacioExterior.h"
#include "Luna.h"
#include "Nave.h"

class SistemaSolar
{
private:
	Tierra* objTierra;
	Sol* objSol;
	ArrAsteroides* objArrAsteroide;
	EspacioExterior* objEspacioExterior;
	Luna* objLuna;
	Nave* objNave;

public:
	SistemaSolar(void);
	~SistemaSolar(void);

	void Mover(Graphics ^gr, Bitmap ^bmp_EspacioExterior, Bitmap ^bmpAsteriodes, Bitmap ^bmpTierra, Bitmap ^bmpSol, Bitmap ^bmpLuna, Bitmap ^bmpNave, Bitmap ^bmpBala);

	void CrearPlanetaTierra(int P_r, int P_r2, int P_angulo, int P_Xcentral, int P_Ycentral, Bitmap ^bmp);
	int Retornar_X_Tierra();
	int retornar_Y_Tierra();
	
	void CrearSol(int p_X, int p_Y, Bitmap ^bmp);
	int Retornar_W_Sol();

	void CrearAsteroide();
	void CrearAsteroides(int p_X, int p_Y, int p_dx, int p_dy, Bitmap ^bmp);

	void CrearEspacioExterior(int p_X, int p_Y, int p_W, int p_H, Bitmap ^bmp);

	void CrearLuna(int p_angulo, int p_r1, int p_r2, int p_x_central, int p_y_central, Bitmap ^bmp);

	void CrearNave(int p_X, int p_Y, Bitmap ^bmp);
	void CrearBalas(Bitmap ^bmp);
	void Cambiar_X_Y_Nave(int nuevoX, int nuevoY);
};

SistemaSolar::SistemaSolar(void)
{
	objTierra=NULL;
	objSol=NULL;
	objArrAsteroide=NULL;
	objEspacioExterior=NULL;
	objLuna=NULL;
	objNave=NULL;
}


SistemaSolar::~SistemaSolar(void)
{
	if(objTierra!=NULL)
		delete objTierra;

	if(objSol!=NULL)
		delete objSol;

	if(objArrAsteroide!=NULL)
		delete objArrAsteroide;

	if(objEspacioExterior!=NULL)
		delete objEspacioExterior;

	if(objLuna!=NULL)
		delete objLuna;

	if(objNave!=NULL)
		delete objNave;
}

void SistemaSolar::Mover(Graphics ^gr, Bitmap ^bmp_EspacioExterior, Bitmap ^bmpAsteriodes, Bitmap ^bmpTierra, Bitmap ^bmpSol, Bitmap ^bmpLuna,  Bitmap ^bmpNave, Bitmap ^bmpBala)
{
	if(objEspacioExterior!=NULL)
		objEspacioExterior->Mostrar(gr,bmp_EspacioExterior);

	if(objArrAsteroide!=NULL)
		objArrAsteroide->Mover_ArrAsteroides(gr, bmpAsteriodes);

	if(objTierra!=NULL)
		objTierra->Mover(gr, bmpTierra);

	if(objSol!=NULL)
		objSol->Mostrar(gr, bmpSol);

	if(objLuna!=NULL)
	{
		objLuna->ActualizarXYCentroTraslacion(objTierra->Retornar_X() + objTierra->Retornar_W()/2, objTierra->Retornar_Y() + objTierra->Retornar_H()/2);
		objLuna->Mover(gr, bmpLuna);
	}

	if(objNave!=NULL)
	{
		objNave->Mover(gr, bmpNave);
		objNave->MoverBalas(gr, bmpBala);
	}

	
}

void SistemaSolar::CrearPlanetaTierra(int P_r, int P_r2, int P_angulo, int P_Xcentral, int P_Ycentral, Bitmap ^bmp)
{
	if(objTierra==NULL)
		objTierra=new Tierra(P_r, P_r2, P_angulo, P_Xcentral, P_Ycentral, bmp);
}

int SistemaSolar::Retornar_X_Tierra()
{
	return objTierra->Retornar_X();
}

int SistemaSolar::retornar_Y_Tierra()
{
	return objTierra->Retornar_Y();
}
	
void SistemaSolar::CrearSol(int p_X, int p_Y, Bitmap ^bmp)
{
	if(objSol==NULL)
		objSol=new Sol(p_X, p_Y, bmp);
}

int SistemaSolar::Retornar_W_Sol()
{
	if(objSol!=NULL)
		return objSol->Retornar_W();
}

//void SistemaSolar::CrearAsteroide()
//{
//	if(objArrAsteroide==NULL)
//		objArrAsteroide = new ArrAsteroides();
//}

void SistemaSolar::CrearAsteroides(int p_X, int p_Y, int p_dx, int p_dy, Bitmap ^bmp)
{
	if(objArrAsteroide==NULL)
		objArrAsteroide = new ArrAsteroides();

	if(objArrAsteroide!=NULL)
		objArrAsteroide->CrearAsteroides(p_X, p_Y, p_dx, p_dy, bmp);
}

void SistemaSolar::CrearEspacioExterior(int p_X, int p_Y, int p_W, int p_H, Bitmap ^bmp)
{
	if(objEspacioExterior==NULL)
		objEspacioExterior = new EspacioExterior(p_X, p_Y, p_W, p_H, bmp);
}

void SistemaSolar::CrearLuna(int p_angulo, int p_r1, int p_r2, int p_x_central, int p_y_central, Bitmap ^bmp)
{
	if(objLuna==NULL)
		objLuna = new Luna(p_angulo, p_r1, p_r2, p_x_central, p_y_central, bmp);
}

void SistemaSolar::CrearNave(int p_X, int p_Y, Bitmap ^bmp)
{
	if(objNave==NULL)
		objNave = new Nave(p_X, p_Y, bmp);
}

void SistemaSolar::CrearBalas(Bitmap ^bmp)
{
	if(objNave!=NULL)
		objNave->DispararBalas(bmp);
}

void SistemaSolar::Cambiar_X_Y_Nave(int nuevoX, int nuevoY)
{
	if(objNave!=NULL)
		objNave->Cambiar_X_Y(nuevoX, nuevoY);
	
}