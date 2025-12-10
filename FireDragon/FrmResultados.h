#pragma once
#include "JuegoService.h"
#include "GestorArchivo.h" // Necesitamos incluir esto para leer el archivo directamente
#include <vector>
#include <string>

namespace FireDragon {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace std;

	public ref class FrmResultados : public System::Windows::Forms::Form
	{
	public:
		FrmResultados(void)
		{
			InitializeComponent();
			ConfigurarLista(); // Configuramos las columnas
			CargarPuntajes();  // Leemos y mostramos los datos
		}

	protected:
		~FrmResultados()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::ListView^ listView1;
	private: System::ComponentModel::Container^ components;

#pragma region Windows Form Designer generated code
		   void InitializeComponent(void)
		   {
			   this->listView1 = (gcnew System::Windows::Forms::ListView());
			   this->SuspendLayout();
			   // 
			   // listView1
			   // 
			   this->listView1->HideSelection = false;
			   this->listView1->Location = System::Drawing::Point(50, 50); // Ajusté un poco la posición
			   this->listView1->Name = L"listView1";
			   this->listView1->Size = System::Drawing::Size(600, 250);
			   this->listView1->TabIndex = 0;
			   this->listView1->UseCompatibleStateImageBehavior = false;
			   this->listView1->View = System::Windows::Forms::View::Details; // IMPORTANTE: Modo detalle
			   this->listView1->GridLines = true; // Lineas para que se vea como tabla
			   this->listView1->FullRowSelect = true;
			   // 
			   // FrmResultados
			   // 
			   this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			   this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			   this->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			   this->ClientSize = System::Drawing::Size(724, 346);
			   this->Controls->Add(this->listView1);
			   this->Name = L"FrmResultados";
			   this->Text = L"Tabla de Posiciones";
			   this->Load += gcnew System::EventHandler(this, &FrmResultados::FrmResultados_Load);
			   this->ResumeLayout(false);

		   }
#pragma endregion

		   // Método para configurar las columnas
	private: void ConfigurarLista() {
		this->listView1->Columns->Clear();
		this->listView1->Columns->Add("Jugador", 150);
		this->listView1->Columns->Add("Puntaje", 100);
		this->listView1->Columns->Add("Ovnis Destruidos", 120);
		this->listView1->Columns->Add("Vidas Restantes", 100);
		this->listView1->Columns->Add("Estado", 100);
	}

		   // Método para leer el archivo y llenar la tabla
	private: void CargarPuntajes() {
		GestorArchivo archivo;
		string nombreArchivo = "progresoDragonFire.txt";

		if (archivo.archivoExiste(nombreArchivo)) {
			// Leemos usando punto y coma (;) que es lo que usas en JuegoService
			vector<vector<string>> datos = archivo.leerLineasString(nombreArchivo, ';');

			listView1->Items->Clear();

			for (int i = 0; i < datos.size(); i++) {
				if (datos[i].size() >= 5) { // Aseguramos que la linea tenga datos validos
					// Convertimos std::string a System::String^
					String^ nombre = gcnew String(datos[i][0].c_str());
					String^ puntos = gcnew String(datos[i][1].c_str());
					String^ ovnis = gcnew String(datos[i][2].c_str());
					String^ vidas = gcnew String(datos[i][3].c_str());
					String^ estado = gcnew String(datos[i][4].c_str());

					// Creamos el item para la lista
					ListViewItem^ item = gcnew ListViewItem(nombre);
					item->SubItems->Add(puntos);
					item->SubItems->Add(ovnis);
					item->SubItems->Add(vidas);
					item->SubItems->Add(estado);

					listView1->Items->Add(item);
				}
			}
		}
		else {
			MessageBox::Show("Aún no hay registros de partidas.", "Información", MessageBoxButtons::OK, MessageBoxIcon::Information);
		}
	}

	private: System::Void FrmResultados_Load(System::Object^ sender, System::EventArgs^ e) {
		// Ya cargamos todo en el constructor, pero puedes recargar aqui si quieres
	}
	};
}