#pragma once
#include "JuegoService.h"
namespace FireDragon {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for FrmJuego
	/// </summary>
	public ref class FrmJuego : public System::Windows::Forms::Form
	{
	public:
		FrmJuego(String^ nombreJugador, int dificultad)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
			servicio = new JuegoService(pnlJuego->Width, pnlJuego->Height, toStdString(nombreJugador), dificultad);
			servicio->inicializar();
			tecla = Direccion::Ninguno;
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~FrmJuego()
		{
			if (components)
			{
				delete components;
			}
			if (servicio) {
				delete servicio;
			}
		}
	private: System::Windows::Forms::Panel^ pnlJuego;
	protected:

	protected:
	private: System::Windows::Forms::Label^ lblPuntos;
	private: System::Windows::Forms::Label^ lblVidas;
	private: System::Windows::Forms::Label^ lblOvnis;
	private: System::ComponentModel::IContainer^ components;
	private: System::Windows::Forms::Timer^ timerJuego;


	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>

		BufferedGraphics^ buffer;
		JuegoService* servicio;
	private: System::Windows::Forms::Label^ lblGameOver;
		   Direccion tecla;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			this->components = (gcnew System::ComponentModel::Container());
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(FrmJuego::typeid));
			this->pnlJuego = (gcnew System::Windows::Forms::Panel());
			this->lblGameOver = (gcnew System::Windows::Forms::Label());
			this->lblOvnis = (gcnew System::Windows::Forms::Label());
			this->lblPuntos = (gcnew System::Windows::Forms::Label());
			this->lblVidas = (gcnew System::Windows::Forms::Label());
			this->timerJuego = (gcnew System::Windows::Forms::Timer(this->components));
			this->pnlJuego->SuspendLayout();
			this->SuspendLayout();
			// 
			// pnlJuego
			// 
			this->pnlJuego->BackColor = System::Drawing::SystemColors::ActiveCaptionText;
			this->pnlJuego->Controls->Add(this->lblGameOver);
			this->pnlJuego->Controls->Add(this->lblOvnis);
			this->pnlJuego->Controls->Add(this->lblPuntos);
			this->pnlJuego->Controls->Add(this->lblVidas);
			this->pnlJuego->Location = System::Drawing::Point(-1, 1);
			this->pnlJuego->Name = L"pnlJuego";
			this->pnlJuego->Size = System::Drawing::Size(751, 572);
			this->pnlJuego->TabIndex = 0;
			// 
			// lblGameOver
			// 
			this->lblGameOver->AutoSize = true;
			this->lblGameOver->BackColor = System::Drawing::Color::MintCream;
			this->lblGameOver->Font = (gcnew System::Drawing::Font(L"Ebrima", 27.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lblGameOver->Location = System::Drawing::Point(242, 336);
			this->lblGameOver->Name = L"lblGameOver";
			this->lblGameOver->Size = System::Drawing::Size(285, 50);
			this->lblGameOver->TabIndex = 3;
			this->lblGameOver->Text = L"FIN DEL JUEGO";
			// 
			// lblOvnis
			// 
			this->lblOvnis->AutoSize = true;
			this->lblOvnis->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(192)), static_cast<System::Int32>(static_cast<System::Byte>(255)),
				static_cast<System::Int32>(static_cast<System::Byte>(255)));
			this->lblOvnis->Font = (gcnew System::Drawing::Font(L"Ebrima", 15.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lblOvnis->ForeColor = System::Drawing::SystemColors::ActiveCaptionText;
			this->lblOvnis->Location = System::Drawing::Point(3, 0);
			this->lblOvnis->Name = L"lblOvnis";
			this->lblOvnis->Size = System::Drawing::Size(80, 30);
			this->lblOvnis->TabIndex = 2;
			this->lblOvnis->Text = L"Ovnis: ";
			// 
			// lblPuntos
			// 
			this->lblPuntos->AutoSize = true;
			this->lblPuntos->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(192)), static_cast<System::Int32>(static_cast<System::Byte>(255)),
				static_cast<System::Int32>(static_cast<System::Byte>(255)));
			this->lblPuntos->Font = (gcnew System::Drawing::Font(L"Ebrima", 15.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lblPuntos->ForeColor = System::Drawing::SystemColors::ActiveCaptionText;
			this->lblPuntos->Location = System::Drawing::Point(3, 30);
			this->lblPuntos->Name = L"lblPuntos";
			this->lblPuntos->Size = System::Drawing::Size(94, 30);
			this->lblPuntos->TabIndex = 1;
			this->lblPuntos->Text = L"Puntos: ";
			// 
			// lblVidas
			// 
			this->lblVidas->AutoSize = true;
			this->lblVidas->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(192)), static_cast<System::Int32>(static_cast<System::Byte>(255)),
				static_cast<System::Int32>(static_cast<System::Byte>(255)));
			this->lblVidas->Font = (gcnew System::Drawing::Font(L"Ebrima", 15.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lblVidas->ForeColor = System::Drawing::SystemColors::ActiveCaptionText;
			this->lblVidas->Location = System::Drawing::Point(3, 60);
			this->lblVidas->Name = L"lblVidas";
			this->lblVidas->Size = System::Drawing::Size(78, 30);
			this->lblVidas->TabIndex = 0;
			this->lblVidas->Text = L"Vidas: ";
			// 
			// timerJuego
			// 
			this->timerJuego->Tick += gcnew System::EventHandler(this, &FrmJuego::timerJuego_Tick);
			// 
			// FrmJuego
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(754, 575);
			this->Controls->Add(this->pnlJuego);
			this->Icon = (cli::safe_cast<System::Drawing::Icon^>(resources->GetObject(L"$this.Icon")));
			this->Name = L"FrmJuego";
			this->Text = L"Fire Dragon";
			this->Load += gcnew System::EventHandler(this, &FrmJuego::FrmJuego_Load);
			this->KeyDown += gcnew System::Windows::Forms::KeyEventHandler(this, &FrmJuego::FrmJuego_KeyDown);
			this->KeyUp += gcnew System::Windows::Forms::KeyEventHandler(this, &FrmJuego::FrmJuego_KeyUp);
			this->pnlJuego->ResumeLayout(false);
			this->pnlJuego->PerformLayout();
			this->ResumeLayout(false);

		}
#pragma endregion



	private: System::Void timerJuego_Tick(System::Object^ sender, System::EventArgs^ e) {
		servicio->actualizarEstadoJuego();
		servicio->moverDragon(tecla);
		servicio->generarOvnis();

		lblOvnis->Text = "Ovnis: " + servicio->getOvnisDestruidos();
		lblPuntos->Text = "Puntos: " + servicio->getPuntos();
		lblVidas->Text = "Vidas: " + servicio->getVidasRestantes();
		
		if (servicio->JuegoTerminado()) {
			if(servicio->gano()){
				lblGameOver->Text = "YOU WIN";
			}
			else{
				lblGameOver->Text = "GAME OVER";
			}
			lblGameOver->Visible = true;
			// colocar labels en el centro
			lblOvnis->Location = System::Drawing::Point((pnlJuego->Width - lblOvnis->Width) / 2, lblOvnis->Location.Y);
			lblPuntos->Location = System::Drawing::Point((pnlJuego->Width - lblPuntos->Width) / 2, lblPuntos->Location.Y);
			lblVidas->Location = System::Drawing::Point((pnlJuego->Width - lblVidas->Width) / 2, lblVidas->Location.Y);


			timerJuego->Stop();
		}

		Graphics^ g = buffer->Graphics;
		g->Clear(Color::Black);
		servicio->dibujarTodo(g);
		buffer->Render(pnlJuego->CreateGraphics());
	}
private: System::Void FrmJuego_Load(System::Object^ sender, System::EventArgs^ e) {
	timerJuego->Interval = 50; // 50 ms
	lblGameOver->Visible = false;
	lblOvnis->Text = "Ovnis: 0";
	lblPuntos->Text = "Puntos: 0";
	lblVidas->Text = "Vidas: 5";

	timerJuego->Start();
	BufferedGraphicsContext^ context = BufferedGraphicsManager::Current;
	buffer = context->Allocate(pnlJuego->CreateGraphics(), pnlJuego->DisplayRectangle);
}
private: System::Void FrmJuego_KeyDown(System::Object^ sender, System::Windows::Forms::KeyEventArgs^ e) {
	if (e->KeyCode == Keys::Up || e->KeyCode == Keys::W) {
		tecla = Direccion::Arriba;
	}
	else if (e->KeyCode == Keys::Down || e->KeyCode == Keys::S) {
		tecla = Direccion::Abajo;
	}
	else if (e->KeyCode == Keys::Right || e->KeyCode == Keys::D) {
		tecla = Direccion::Derecha;
	}
	else if (e->KeyCode == Keys::Left || e->KeyCode == Keys::A) {
		tecla = Direccion::Izquierda;
	}
	if (e->KeyCode == Keys::Z) {
		servicio->generarBolas();
	}
}
private: System::Void FrmJuego_KeyUp(System::Object^ sender, System::Windows::Forms::KeyEventArgs^ e) {
	tecla = Direccion::Ninguno;
}
	   private: string toStdString(String^ texto) {
		   using namespace Runtime::InteropServices;
		   IntPtr ptr = Marshal::StringToHGlobalAnsi(texto);
		   std::string result = static_cast<const char*>(ptr.ToPointer());
		   Marshal::FreeHGlobal(ptr);
		   return result;
	   }
};
}
