#pragma once
#include "FrmJuego.h"
#include "FrmResultados.h"

namespace FireDragon {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for FrmFireDragon
	/// </summary>
	public ref class FrmFireDragon : public System::Windows::Forms::Form
	{
	public:
		FrmFireDragon(void)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
			dificultad = 1; // facil por defecto
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~FrmFireDragon()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Panel^ pnlMenu;
	private: System::Windows::Forms::TextBox^ txtNombre;
	private: System::Windows::Forms::PictureBox^ pbxCreditos;
	private: System::Windows::Forms::PictureBox^ pbxPuntajes;
	private: System::Windows::Forms::PictureBox^ pbxJugar;
	protected:

	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>
		System::ComponentModel::Container ^components;
	private: System::Windows::Forms::Panel^ pnlDificultad;
	private: System::Windows::Forms::PictureBox^ pbxInfinito;
	private: System::Windows::Forms::PictureBox^ pbxDificil;
	private: System::Windows::Forms::PictureBox^ pbxNormal;
	private: System::Windows::Forms::PictureBox^ pbxFacil;
		   int dificultad;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(FrmFireDragon::typeid));
			this->pnlMenu = (gcnew System::Windows::Forms::Panel());
			this->pnlDificultad = (gcnew System::Windows::Forms::Panel());
			this->pbxInfinito = (gcnew System::Windows::Forms::PictureBox());
			this->pbxDificil = (gcnew System::Windows::Forms::PictureBox());
			this->pbxNormal = (gcnew System::Windows::Forms::PictureBox());
			this->pbxFacil = (gcnew System::Windows::Forms::PictureBox());
			this->txtNombre = (gcnew System::Windows::Forms::TextBox());
			this->pbxCreditos = (gcnew System::Windows::Forms::PictureBox());
			this->pbxPuntajes = (gcnew System::Windows::Forms::PictureBox());
			this->pbxJugar = (gcnew System::Windows::Forms::PictureBox());
			this->pnlMenu->SuspendLayout();
			this->pnlDificultad->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pbxInfinito))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pbxDificil))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pbxNormal))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pbxFacil))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pbxCreditos))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pbxPuntajes))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pbxJugar))->BeginInit();
			this->SuspendLayout();
			// 
			// pnlMenu
			// 
			this->pnlMenu->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pnlMenu.BackgroundImage")));
			this->pnlMenu->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->pnlMenu->Controls->Add(this->txtNombre);
			this->pnlMenu->Controls->Add(this->pbxCreditos);
			this->pnlMenu->Controls->Add(this->pbxPuntajes);
			this->pnlMenu->Controls->Add(this->pbxJugar);
			this->pnlMenu->Controls->Add(this->pnlDificultad);
			this->pnlMenu->Location = System::Drawing::Point(2, 2);
			this->pnlMenu->Name = L"pnlMenu";
			this->pnlMenu->Size = System::Drawing::Size(744, 614);
			this->pnlMenu->TabIndex = 0;
			// 
			// pnlDificultad
			// 
			this->pnlDificultad->BackColor = System::Drawing::SystemColors::ControlDark;
			this->pnlDificultad->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pnlDificultad.BackgroundImage")));
			this->pnlDificultad->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->pnlDificultad->Controls->Add(this->pbxInfinito);
			this->pnlDificultad->Controls->Add(this->pbxDificil);
			this->pnlDificultad->Controls->Add(this->pbxNormal);
			this->pnlDificultad->Controls->Add(this->pbxFacil);
			this->pnlDificultad->Location = System::Drawing::Point(0, 0);
			this->pnlDificultad->Name = L"pnlDificultad";
			this->pnlDificultad->Size = System::Drawing::Size(744, 614);
			this->pnlDificultad->TabIndex = 4;
			// 
			// pbxInfinito
			// 
			this->pbxInfinito->BackColor = System::Drawing::Color::Transparent;
			this->pbxInfinito->Location = System::Drawing::Point(386, 382);
			this->pbxInfinito->Name = L"pbxInfinito";
			this->pbxInfinito->Size = System::Drawing::Size(224, 174);
			this->pbxInfinito->TabIndex = 4;
			this->pbxInfinito->TabStop = false;
			this->pbxInfinito->Click += gcnew System::EventHandler(this, &FrmFireDragon::pbxInfinito_Click);
			// 
			// pbxDificil
			// 
			this->pbxDificil->BackColor = System::Drawing::Color::Transparent;
			this->pbxDificil->Location = System::Drawing::Point(139, 382);
			this->pbxDificil->Name = L"pbxDificil";
			this->pbxDificil->Size = System::Drawing::Size(224, 174);
			this->pbxDificil->TabIndex = 3;
			this->pbxDificil->TabStop = false;
			this->pbxDificil->Click += gcnew System::EventHandler(this, &FrmFireDragon::pbxDificil_Click);
			// 
			// pbxNormal
			// 
			this->pbxNormal->BackColor = System::Drawing::Color::Transparent;
			this->pbxNormal->Location = System::Drawing::Point(386, 173);
			this->pbxNormal->Name = L"pbxNormal";
			this->pbxNormal->Size = System::Drawing::Size(224, 174);
			this->pbxNormal->TabIndex = 2;
			this->pbxNormal->TabStop = false;
			this->pbxNormal->Click += gcnew System::EventHandler(this, &FrmFireDragon::pbxNormal_Click);
			// 
			// pbxFacil
			// 
			this->pbxFacil->BackColor = System::Drawing::Color::Transparent;
			this->pbxFacil->Location = System::Drawing::Point(139, 173);
			this->pbxFacil->Name = L"pbxFacil";
			this->pbxFacil->Size = System::Drawing::Size(224, 174);
			this->pbxFacil->TabIndex = 1;
			this->pbxFacil->TabStop = false;
			this->pbxFacil->Click += gcnew System::EventHandler(this, &FrmFireDragon::pbxFacil_Click);
			// 
			// txtNombre
			// 
			this->txtNombre->Location = System::Drawing::Point(315, 511);
			this->txtNombre->Name = L"txtNombre";
			this->txtNombre->Size = System::Drawing::Size(191, 20);
			this->txtNombre->TabIndex = 3;
			// 
			// pbxCreditos
			// 
			this->pbxCreditos->BackColor = System::Drawing::Color::Transparent;
			this->pbxCreditos->Location = System::Drawing::Point(524, 546);
			this->pbxCreditos->Name = L"pbxCreditos";
			this->pbxCreditos->Size = System::Drawing::Size(202, 57);
			this->pbxCreditos->TabIndex = 2;
			this->pbxCreditos->TabStop = false;
			// 
			// pbxPuntajes
			// 
			this->pbxPuntajes->BackColor = System::Drawing::Color::Transparent;
			this->pbxPuntajes->Location = System::Drawing::Point(241, 546);
			this->pbxPuntajes->Name = L"pbxPuntajes";
			this->pbxPuntajes->Size = System::Drawing::Size(265, 58);
			this->pbxPuntajes->TabIndex = 1;
			this->pbxPuntajes->TabStop = false;
			this->pbxPuntajes->Click += gcnew System::EventHandler(this, &FrmFireDragon::pbxPuntajes_Click);
			// 
			// pbxJugar
			// 
			this->pbxJugar->BackColor = System::Drawing::Color::Transparent;
			this->pbxJugar->Location = System::Drawing::Point(240, 423);
			this->pbxJugar->Name = L"pbxJugar";
			this->pbxJugar->Size = System::Drawing::Size(266, 82);
			this->pbxJugar->TabIndex = 0;
			this->pbxJugar->TabStop = false;
			this->pbxJugar->Click += gcnew System::EventHandler(this, &FrmFireDragon::pbxJugar_Click);
			// 
			// FrmFireDragon
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(748, 617);
			this->Controls->Add(this->pnlMenu);
			this->Icon = (cli::safe_cast<System::Drawing::Icon^>(resources->GetObject(L"$this.Icon")));
			this->Name = L"FrmFireDragon";
			this->Text = L"Fire Dragon";
			this->Load += gcnew System::EventHandler(this, &FrmFireDragon::FrmFireDragon_Load);
			this->pnlMenu->ResumeLayout(false);
			this->pnlMenu->PerformLayout();
			this->pnlDificultad->ResumeLayout(false);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pbxInfinito))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pbxDificil))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pbxNormal))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pbxFacil))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pbxCreditos))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pbxPuntajes))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pbxJugar))->EndInit();
			this->ResumeLayout(false);

		}
#pragma endregion
	private: System::Void pbxJugar_Click(System::Object^ sender, System::EventArgs^ e) {
		if (txtNombre->Text == "") {
			MessageBox::Show("Por favor ingrese su nombre antes de jugar.", "Nombre requerido", MessageBoxButtons::OK, MessageBoxIcon::Warning);
			return;
		}
		pnlDificultad->Visible = true;
		pbxFacil->Enabled = true;
		pbxNormal->Enabled = true;
		pbxDificil->Enabled = true;
		pbxInfinito->Enabled = true;
		pbxCreditos->Visible = false;
		pbxCreditos->Enabled = false;
		pbxJugar->Visible = false;
		pbxJugar->Enabled = false;
		pbxPuntajes->Visible = false;
		pbxPuntajes->Enabled = false;
		txtNombre->Visible = false;

	}
private: System::Void pbxPuntajes_Click(System::Object^ sender, System::EventArgs^ e) {

	FrmResultados^ frmResultados = gcnew FrmResultados();
	frmResultados->ShowDialog();
}
private: System::Void FrmFireDragon_Load(System::Object^ sender, System::EventArgs^ e) {
	pnlDificultad->Visible = false;
	pbxFacil->Enabled = false;
	pbxNormal->Enabled = false;
	pbxDificil->Enabled = false;
	pbxInfinito->Enabled = false;

}
private: System::Void pbxFacil_Click(System::Object^ sender, System::EventArgs^ e) {
	dificultad = 1; // Fácil
	ejecutarJuego();
}
private: System::Void pbxNormal_Click(System::Object^ sender, System::EventArgs^ e) {
	dificultad = 2; // Normal
	ejecutarJuego();
}
private: System::Void pbxInfinito_Click(System::Object^ sender, System::EventArgs^ e) {
	dificultad = 4; // Infinito
	ejecutarJuego();
}
private: System::Void pbxDificil_Click(System::Object^ sender, System::EventArgs^ e) {
	dificultad = 3; // Difícil
	ejecutarJuego();
}
	private: void ejecutarJuego() {

		this->Hide();
		FrmJuego^ fmrJuego = gcnew FrmJuego(txtNombre->Text, dificultad);
		fmrJuego->ShowDialog();

		delete fmrJuego;
		// Al hacer delete, se activa ~FrmJuego -> delete servicio -> ~JuegoService -> guardarResultado()

		pnlDificultad->Visible = false;
		pbxFacil->Enabled = false;
		pbxNormal->Enabled = false;
		pbxDificil->Enabled = false;
		pbxInfinito->Enabled = false;
		pbxCreditos->Visible = true;
		pbxCreditos->Enabled = true;
		pbxJugar->Visible = true;
		pbxJugar->Enabled = true;
		pbxPuntajes->Visible = true;
		pbxPuntajes->Enabled = true;
		txtNombre->Visible = true;

		this->Show(); 

	}
};
}
