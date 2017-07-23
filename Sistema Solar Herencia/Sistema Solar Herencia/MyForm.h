#pragma once

namespace SistemaSolarHerencia {

	#include "SistemaSolar.h"
	#include "Tierra.h"
	#include <stdlib.h>
	#include <time.h>
	#include "Asteroide.h"
	#include "ArrAsteroides.h"
	#include "EspacioExterior.h"
	#include "Nave.h"

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for MyForm
	/// </summary>
	public ref class MyForm : public System::Windows::Forms::Form
	{
	public:
		MyForm(void)
		{
			bmp_EspacioExterior = gcnew Bitmap("EspacioExterior.jpg");
			bmp_Asteriodes = gcnew Bitmap("asteroids.png");
			bmp_Tierra = gcnew Bitmap("sprite_tierra2.png");
			bmp_Sol = gcnew Bitmap("Sol2.png");
			bmp_Luna = gcnew Bitmap("luna.png");
			bmp_Nave = gcnew Bitmap("nave.png");
			bmp_Bala = gcnew Bitmap("nokia.png");

			InitializeComponent();

			 Cursor->Hide();

			Objeto_SistemaSolar=new SistemaSolar();
	
			srand(time(NULL));
			hora_inicial=time(NULL);
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~MyForm()
		{
			if (components)
			{
				delete components;
			}

			delete Objeto_SistemaSolar;
			delete bmp_EspacioExterior;
			delete bmp_Asteriodes;
			delete bmp_Tierra;
			delete bmp_Sol;
			delete bmp_Luna;
			delete bmp_Nave;
			delete bmp_Bala;

		}
	private: System::Windows::Forms::Timer^  timer1;
	protected: 
	private: System::ComponentModel::IContainer^  components;

	private:
		SistemaSolar* Objeto_SistemaSolar;

		Bitmap ^bmp_EspacioExterior;

		Bitmap ^bmp_Asteriodes;

		Bitmap ^bmp_Tierra;

		Bitmap ^bmp_Sol;

		Bitmap ^bmp_Luna;

		Bitmap ^bmp_Nave;

		Bitmap ^bmp_Bala;


		time_t hora_inicial;


#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			this->components = (gcnew System::ComponentModel::Container());
			this->timer1 = (gcnew System::Windows::Forms::Timer(this->components));
			this->SuspendLayout();
			// 
			// timer1
			// 
			this->timer1->Enabled = true;
			this->timer1->Tick += gcnew System::EventHandler(this, &MyForm::timer1_Tick);
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(284, 262);
			this->Name = L"MyForm";
			this->Text = L"MyForm";
			this->WindowState = System::Windows::Forms::FormWindowState::Maximized;
			this->SizeChanged += gcnew System::EventHandler(this, &MyForm::MyForm_SizeChanged);
			this->MouseClick += gcnew System::Windows::Forms::MouseEventHandler(this, &MyForm::MyForm_MouseClick);
			this->MouseMove += gcnew System::Windows::Forms::MouseEventHandler(this, &MyForm::MyForm_MouseMove);
			this->ResumeLayout(false);

		}
#pragma endregion
	private: System::Void timer1_Tick(System::Object^  sender, System::EventArgs^  e) {

				 time_t hora_crear_asteroides=time(NULL);

				 if (difftime(hora_crear_asteroides,hora_inicial) > 0.5)
				 {  
					 Objeto_SistemaSolar->CrearAsteroides(rand()%this->Width, 0, rand()%10 - rand()%5, rand()%10, bmp_Asteriodes);
					 Objeto_SistemaSolar->CrearAsteroides(0, rand()%this->Height, rand()%10 +1, rand()%10-rand()%5, bmp_Asteriodes);
					 Objeto_SistemaSolar->CrearAsteroides(this->Width-15,rand()%this->Height-15, 0 - rand()%10 +1, rand()%10-rand()%7, bmp_Asteriodes);

					 hora_inicial=time(NULL);
				 }

				 Graphics ^gr = this->CreateGraphics();
				 BufferedGraphicsContext ^bgc = BufferedGraphicsManager::Current;
				 BufferedGraphics ^bg = bgc->Allocate(gr, this->ClientRectangle);
				 
				 bg->Graphics->Clear(Color::Black);
				 
				 Objeto_SistemaSolar->Mover(bg->Graphics, bmp_EspacioExterior, bmp_Asteriodes, bmp_Tierra, bmp_Sol, bmp_Luna, bmp_Nave, bmp_Bala);
				 
				 bg->Render(gr);
				 
				 delete bgc;
				 delete bg;
				 delete gr;
			 }
	private: System::Void MyForm_SizeChanged(System::Object^  sender, System::EventArgs^  e) {

				 timer1->Enabled=false;


				 Objeto_SistemaSolar->CrearEspacioExterior(0, 0, this->Width, this->Height, bmp_EspacioExterior);
				 Objeto_SistemaSolar->CrearSol(this->Width/2 - 90, this->Height/2 - 85, bmp_Sol);
				 Objeto_SistemaSolar->CrearPlanetaTierra(300, 200, 0, this->Width/2 - 50, this->Height/2 - 30, bmp_Tierra);
				 Objeto_SistemaSolar->CrearLuna(0, 50, 30 , Objeto_SistemaSolar->Retornar_X_Tierra(), Objeto_SistemaSolar->retornar_Y_Tierra(), bmp_Luna);
				 Objeto_SistemaSolar->CrearNave(this->Width/2 -50 , this->Height/2 + 200, bmp_Nave);
				
				 
				 timer1->Enabled=true;
			 }
private: System::Void MyForm_MouseMove(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e) {

			 Objeto_SistemaSolar->Cambiar_X_Y_Nave(e->X, e->Y);

		 }
private: System::Void MyForm_MouseClick(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e) {

			  Objeto_SistemaSolar->CrearBalas(bmp_Bala);
		 }
};
}
