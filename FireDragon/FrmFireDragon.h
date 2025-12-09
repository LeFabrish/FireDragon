#pragma once

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

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(FrmFireDragon::typeid));
			this->pnlMenu = (gcnew System::Windows::Forms::Panel());
			this->pbxJugar = (gcnew System::Windows::Forms::PictureBox());
			this->pbxPuntajes = (gcnew System::Windows::Forms::PictureBox());
			this->pbxCreditos = (gcnew System::Windows::Forms::PictureBox());
			this->txtNombre = (gcnew System::Windows::Forms::TextBox());
			this->pnlMenu->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pbxJugar))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pbxPuntajes))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pbxCreditos))->BeginInit();
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
			this->pnlMenu->Location = System::Drawing::Point(2, 2);
			this->pnlMenu->Name = L"pnlMenu";
			this->pnlMenu->Size = System::Drawing::Size(744, 614);
			this->pnlMenu->TabIndex = 0;
			// 
			// pbxJugar
			// 
			this->pbxJugar->BackColor = System::Drawing::Color::Transparent;
			this->pbxJugar->Location = System::Drawing::Point(241, 418);
			this->pbxJugar->Name = L"pbxJugar";
			this->pbxJugar->Size = System::Drawing::Size(266, 82);
			this->pbxJugar->TabIndex = 0;
			this->pbxJugar->TabStop = false;
			// 
			// pbxPuntajes
			// 
			this->pbxPuntajes->BackColor = System::Drawing::Color::Transparent;
			this->pbxPuntajes->Location = System::Drawing::Point(241, 546);
			this->pbxPuntajes->Name = L"pbxPuntajes";
			this->pbxPuntajes->Size = System::Drawing::Size(265, 58);
			this->pbxPuntajes->TabIndex = 1;
			this->pbxPuntajes->TabStop = false;
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
			// txtNombre
			// 
			this->txtNombre->Location = System::Drawing::Point(315, 520);
			this->txtNombre->Name = L"txtNombre";
			this->txtNombre->Size = System::Drawing::Size(191, 20);
			this->txtNombre->TabIndex = 3;
			// 
			// FrmFireDragon
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(747, 617);
			this->Controls->Add(this->pnlMenu);
			this->Icon = (cli::safe_cast<System::Drawing::Icon^>(resources->GetObject(L"$this.Icon")));
			this->Name = L"FrmFireDragon";
			this->Text = L"Fire Dragon";
			this->pnlMenu->ResumeLayout(false);
			this->pnlMenu->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pbxJugar))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pbxPuntajes))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pbxCreditos))->EndInit();
			this->ResumeLayout(false);

		}
#pragma endregion
	};
}
