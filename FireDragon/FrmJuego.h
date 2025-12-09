#pragma once

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
		FrmJuego(void)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
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
		}
	private: System::Windows::Forms::Panel^ panel1;
	protected:
	private: System::Windows::Forms::Label^ lblPuntos;
	private: System::Windows::Forms::Label^ lblVidas;
	private: System::Windows::Forms::Label^ lblOvnis;

	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(FrmJuego::typeid));
			this->panel1 = (gcnew System::Windows::Forms::Panel());
			this->lblVidas = (gcnew System::Windows::Forms::Label());
			this->lblPuntos = (gcnew System::Windows::Forms::Label());
			this->lblOvnis = (gcnew System::Windows::Forms::Label());
			this->panel1->SuspendLayout();
			this->SuspendLayout();
			// 
			// panel1
			// 
			this->panel1->BackColor = System::Drawing::SystemColors::ActiveCaptionText;
			this->panel1->Controls->Add(this->lblOvnis);
			this->panel1->Controls->Add(this->lblPuntos);
			this->panel1->Controls->Add(this->lblVidas);
			this->panel1->Location = System::Drawing::Point(-1, 1);
			this->panel1->Name = L"panel1";
			this->panel1->Size = System::Drawing::Size(729, 572);
			this->panel1->TabIndex = 0;
			// 
			// lblVidas
			// 
			this->lblVidas->AutoSize = true;
			this->lblVidas->ForeColor = System::Drawing::Color::OrangeRed;
			this->lblVidas->Location = System::Drawing::Point(35, 11);
			this->lblVidas->Name = L"lblVidas";
			this->lblVidas->Size = System::Drawing::Size(39, 13);
			this->lblVidas->TabIndex = 0;
			this->lblVidas->Text = L"Vidas: ";
			// 
			// lblPuntos
			// 
			this->lblPuntos->AutoSize = true;
			this->lblPuntos->ForeColor = System::Drawing::Color::Orange;
			this->lblPuntos->Location = System::Drawing::Point(163, 11);
			this->lblPuntos->Name = L"lblPuntos";
			this->lblPuntos->Size = System::Drawing::Size(46, 13);
			this->lblPuntos->TabIndex = 1;
			this->lblPuntos->Text = L"Puntos: ";
			// 
			// lblOvnis
			// 
			this->lblOvnis->AutoSize = true;
			this->lblOvnis->ForeColor = System::Drawing::Color::Lime;
			this->lblOvnis->Location = System::Drawing::Point(657, 11);
			this->lblOvnis->Name = L"lblOvnis";
			this->lblOvnis->Size = System::Drawing::Size(40, 13);
			this->lblOvnis->TabIndex = 2;
			this->lblOvnis->Text = L"Ovnis: ";
			// 
			// FrmJuego
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(728, 575);
			this->Controls->Add(this->panel1);
			this->Icon = (cli::safe_cast<System::Drawing::Icon^>(resources->GetObject(L"$this.Icon")));
			this->Name = L"FrmJuego";
			this->Text = L"Fire Dragon";
			this->panel1->ResumeLayout(false);
			this->panel1->PerformLayout();
			this->ResumeLayout(false);

		}
#pragma endregion
	};
}
